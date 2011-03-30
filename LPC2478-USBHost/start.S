/*
 * =====================================================================================
 *
 *       Filename:  start.S
 *
 *    Description:  arm gcc 通用初始化文件
 *
 *        Version:  1.1
 *        Created:  2011-1-22 21:31:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  renwei
 *				Modified：yecunkui
 *        Company:  HUST
 *
 * =====================================================================================
 */

/*
	.S格式意味着可以使用宏定义如#define
	#include "xxx.h", 但不能有函数声明和变量声明
*/

/* Stack Sizes */
.set  UND_STACK_SIZE, 0x00000040		/* stack for "undefined instruction" interrupts	*/
.set  ABT_STACK_SIZE, 0x00000040		/* stack for "abort" interrupts	*/
.set  FIQ_STACK_SIZE, 0x00000040		/* stack for "FIQ" interrupts	*/
.set  IRQ_STACK_SIZE, 0x00000100		/* stack for "IRQ" normal interrupts	*/
.set  SYS_STACK_SIZE, 0x00000400		/* stack for "SYS" system mode	*/

/* Standard definitions of Mode bits and Interrupt (I & F) flags in PSRs (program status registers) */
.set  MODE_USR, 0x10            		/* Normal User Mode	*/
.set  MODE_FIQ, 0x11            		/* FIQ Processing Fast Interrupts Mode	*/
.set  MODE_IRQ, 0x12            		/* IRQ Processing Standard Interrupts Mode	*/
.set  MODE_SVC, 0x13            		/* Supervisor Processing Software Interrupts Mode	*/
.set  MODE_ABT, 0x17            		/* Abort Processing memory Faults Mode	*/
.set  MODE_UND, 0x1B            		/* Undefined Processing Undefined Instructions Mode	*/
.set  MODE_SYS, 0x1F            		/* System Running Priviledged Operating System Tasks  Mode	*/

.set  I_BIT, 0x80               		/* when I bit is set, IRQ is disabled (program status registers) */
.set  F_BIT, 0x40               		/* when F bit is set, FIQ is disabled (program status registers) */

/* ARM 异常中断向量表开始 */
.section .vector,"a"
    .global vector_table
vector_table:
    ldr pc, reset_vector				/* rest */
    ldr pc, undef_vector				/* undefine */
    ldr pc, swi_vector					/* software interrupt */
    ldr pc, prefech_vector			/* prefetch */
    ldr pc, data_abort_vector		/* data abort */
    ldr pc, reset_vector				/* reserver */
    /* ldr pc, irq_vector	*/		/* IRQ */
    ldr pc, [pc, #-0x0120]			/* Vector from VICAddress */
    														/* 0x18+0x08-0x0120 == 0xFFFFFF00 */
    ldr pc, fiq_vector					/* FIQ */

	.global vector_ref_tbl
vector_ref_tbl:
reset_vector:
    .long   start
undef_vector:
    .long   undef_handler
swi_vector:
    .long   swi_handler
prefech_vector:
    .long   prefetch_handler
data_abort_vector:
    .long   data_abort_handler
irq_vector:
    .long   irq_handler
fiq_vector:
    .long   fiq_handler

/* ARM 异常中断向量表结束 */


	.text
	.code 32	//Sets the instruction width in bits.
						//Use 16 for Thumb and 32 for ARM assembly.
	.align	2
	.global	start
start:

   /* Added by yecunkui */
   /* Setup a stack for each mode - note that this only sets up a usable stack
			for User mode.   Also each mode is setup with interrupts initially disabled. */

   	ldr		r1, =p_intstack
   	ldr		r0,[r1]
	msr     CPSR_c, #MODE_UND|I_BIT|F_BIT 	/* Undefined Instruction Mode  */
 	mov     sp, r0
	sub     r0, r0, #UND_STACK_SIZE
	msr     CPSR_c, #MODE_ABT|I_BIT|F_BIT 	/* Abort Mode */
 	mov     sp, r0
	sub     r0, r0, #ABT_STACK_SIZE
	msr     CPSR_c, #MODE_FIQ|I_BIT|F_BIT 	/* FIQ Mode */
 	mov     sp, r0
	sub     r0, r0, #FIQ_STACK_SIZE
	msr     CPSR_c, #MODE_IRQ|I_BIT|F_BIT 	/* IRQ Mode */
	mov     sp, r0
 	sub     r0, r0, #IRQ_STACK_SIZE
 	msr		CPSR_c, #MODE_SYS|I_BIT|F_BIT		/* System Mode	*/
 	mov		sp, r0
 	sub		r0, r0, #SYS_STACK_SIZE
 	msr		CPSR_c, #MODE_SVC|F_BIT		/* Supervisor Mode */
 	mov		sp, r0

    /*
     * initilize ARM's mode
     * supervisor mode FIQ/IRQ disable
     */
     //如果要同时禁止IRQ中断和FIQ中断，cpsr应赋值为0xd3
    /* msr  cpsr, #0xd3 */

    /*
     * load stack pointer, frame pointer
     */

    /* ldr  r0, =p_intstack  load stack pointer, p_intstack is bottem of stack */
    /* ldr  sp, [r0]	*/
    mov  fp, #0        /* ARM mode frame pointer*/
    mov  r7, #0        /* Thumb mode frame pointer */

    /*
     *  call hardware_init_hook
     */
    ldr   r0, =hardware_init_hook /* necessary hardware initialize */
    cmp   r0, #0x00
    movne lr, pc
    movne pc, r0

/* 初始化BSS段 对应的内存区域必须清零 */
start_1:
    /*
     *  bss clear
     */
    ldr  r1, =__bss_start
    ldr  r2, =__bss_end
    cmp  r1,r2
    bhs  start_3
    mov  r0,#0
start_2:
    str  r0,[r1],#4
    cmp  r1, r2
    blo  start_2

/* 初始化.data段，从ROM拷贝数据到RAM，如数据本身已在RAM中则不用拷贝 */
start_3:

    /*
     *  copy data from rom
     *  ROM:  from__idata_start to  __idata_end
	 *  RAM: to __data_start
     */
    ldr  r1, =__idata_start
    ldr  r3, =__idata_end
    cmp  r1, r3
    bhs  start_5   /* start_5 */
    ldr  r2, =__data_start
start_4:
    ldr  r0, [r1],#4
    str  r0, [r2],#4
    cmp  r1, r3
    blo  start_4
     /*
     *   call software_init_hook
     */
start_5:
    ldr   r0, =software_init_hook
    cmp   r0, #0x00
    movne lr, pc
    movne pc, r0
    /*
     *  call main
     */
start_6:
    bl	main

/* exception handlers */
 	.text
    .align 2
    .global undef_handler  /* UNDEF handler */
undef_handler:
    b     undef_handler /* target_exc_handler(lr,spsr,exceptno) */

    .text
    .align 2
    .global swi_handler /* SWI handler */
swi_handler:
    b     swi_handler	/* target_exc_handler(lr,spsr,exceptno) */


    .text
    .align 2
    .global prefetch_handler
prefetch_handler:	/* PREFETCH handler */
    b     prefetch_handler

    .text
    .align 2
    .global data_abort_handler
data_abort_handler:		/* DATA ABORT handler */
    b     data_abort_handler


    .text
    .align 2
    .global fiq_handler
fiq_handler:	/* FIQ handler */
    b     fiq_handler


    .text
    .align 2
    .global irq_handler
irq_handler:	/* IRQ handler */
		b     irq_handler
