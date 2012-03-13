	.cpu arm7tdmi
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 2
	.eabi_attribute 18, 4
	.file	"makeoffset.c"
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.align	2
	.global	makeoffset
	.type	makeoffset, %function
makeoffset:
.LFB61:
	.file 1 "../../arch/arm_gcc/common/makeoffset.c"
	.loc 1 58 0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 1 59 0
@ 59 "../../arch/arm_gcc/common/makeoffset.c" 1
	OFFSET_DEF TCB_p_tinib = #8
@ 0 "" 2
	.loc 1 60 0
@ 60 "../../arch/arm_gcc/common/makeoffset.c" 1
	OFFSET_DEF TCB_texptn = #16
@ 0 "" 2
	.loc 1 61 0
@ 61 "../../arch/arm_gcc/common/makeoffset.c" 1
	OFFSET_DEF TCB_sp = #24
@ 0 "" 2
	.loc 1 62 0
@ 62 "../../arch/arm_gcc/common/makeoffset.c" 1
	OFFSET_DEF TCB_pc = #28
@ 0 "" 2
	.loc 1 64 0
@ 64 "../../arch/arm_gcc/common/makeoffset.c" 1
	OFFSET_DEF TINIB_exinf = #4
@ 0 "" 2
	.loc 1 65 0
@ 65 "../../arch/arm_gcc/common/makeoffset.c" 1
	OFFSET_DEF TINIB_task = #8
@ 0 "" 2
	.loc 1 66 0
	bx	lr
	.cfi_endproc
.LFE61:
	.size	makeoffset, .-makeoffset
	.global	BIT_REF_4
	.global	BIT_REF_2
	.global	BIT_REF_1
	.global	BIT_BB_TCB_enatex
	.data
	.align	2
	.type	BIT_REF_4, %object
	.size	BIT_REF_4, 4
BIT_REF_4:
	.word	305419896
	.type	BIT_REF_2, %object
	.size	BIT_REF_2, 2
BIT_REF_2:
	.short	4660
	.type	BIT_REF_1, %object
	.size	BIT_REF_1, 1
BIT_REF_1:
	.byte	18
	.space	1
	.type	BIT_BB_TCB_enatex, %object
	.size	BIT_BB_TCB_enatex, 32
BIT_BB_TCB_enatex:
	.word	0
	.word	0
	.word	0
	.byte	0
	.byte	0
	.byte	4
	.space	1
	.word	0
	.word	0
	.word	0
	.word	0
	.text
.Letext0:
	.file 2 "../../arch/gcc/tool_stddef.h"
	.file 3 "../../include/t_stddef.h"
	.file 4 "../../include/kernel.h"
	.file 5 "../../arch/arm_gcc/common/core_config.h"
	.file 6 "../../include/queue.h"
	.file 7 "../../kernel/time_event.h"
	.file 8 "../../kernel/task.h"
	.file 9 "../../target/at91skyeye_gcc/target_config.h"
	.section	.debug_info
	.4byte	0x49b
	.2byte	0x2
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF71
	.byte	0x1
	.4byte	.LASF72
	.4byte	.LASF73
	.4byte	.Ltext0
	.4byte	.Letext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.4byte	.LASF0
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.4byte	.LASF1
	.uleb128 0x4
	.4byte	.LASF4
	.byte	0x2
	.byte	0x66
	.4byte	0x45
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.4byte	.LASF2
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.4byte	.LASF3
	.uleb128 0x4
	.4byte	.LASF5
	.byte	0x2
	.byte	0x69
	.4byte	0x5e
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.4byte	.LASF6
	.uleb128 0x4
	.4byte	.LASF7
	.byte	0x2
	.byte	0x6c
	.4byte	0x2c
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.4byte	.LASF8
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.4byte	.LASF9
	.uleb128 0x4
	.4byte	.LASF10
	.byte	0x2
	.byte	0x74
	.4byte	0x89
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.4byte	.LASF11
	.uleb128 0x4
	.4byte	.LASF12
	.byte	0x2
	.byte	0x75
	.4byte	0x9b
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.4byte	.LASF13
	.uleb128 0x3
	.byte	0x4
	.byte	0x4
	.4byte	.LASF14
	.uleb128 0x3
	.byte	0x8
	.byte	0x4
	.4byte	.LASF15
	.uleb128 0x5
	.4byte	.LASF24
	.byte	0x4
	.byte	0x3
	.byte	0x5b
	.4byte	0xcb
	.uleb128 0x6
	.4byte	.LASF26
	.byte	0x3
	.byte	0x5b
	.4byte	0x25
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x4
	.4byte	.LASF16
	.byte	0x3
	.byte	0x5c
	.4byte	0xd6
	.uleb128 0x7
	.byte	0x4
	.4byte	0xdc
	.uleb128 0x8
	.byte	0x1
	.4byte	0xe8
	.uleb128 0x9
	.4byte	0xb0
	.byte	0x0
	.uleb128 0x4
	.4byte	.LASF17
	.byte	0x3
	.byte	0x66
	.4byte	0x25
	.uleb128 0x4
	.4byte	.LASF18
	.byte	0x3
	.byte	0x67
	.4byte	0x2c
	.uleb128 0x4
	.4byte	.LASF19
	.byte	0x3
	.byte	0x6a
	.4byte	0x9b
	.uleb128 0xa
	.ascii	"ER\000"
	.byte	0x3
	.byte	0x6d
	.4byte	0xe8
	.uleb128 0xa
	.ascii	"ATR\000"
	.byte	0x3
	.byte	0x6f
	.4byte	0xf3
	.uleb128 0xa
	.ascii	"PRI\000"
	.byte	0x3
	.byte	0x72
	.4byte	0xe8
	.uleb128 0x4
	.4byte	.LASF20
	.byte	0x3
	.byte	0x73
	.4byte	0x90
	.uleb128 0xa
	.ascii	"FP\000"
	.byte	0x3
	.byte	0x7a
	.4byte	0xcb
	.uleb128 0x4
	.4byte	.LASF21
	.byte	0x4
	.byte	0x53
	.4byte	0xf3
	.uleb128 0x4
	.4byte	.LASF22
	.byte	0x4
	.byte	0x5c
	.4byte	0x154
	.uleb128 0x7
	.byte	0x4
	.4byte	0x15a
	.uleb128 0x8
	.byte	0x1
	.4byte	0x166
	.uleb128 0x9
	.4byte	0x7e
	.byte	0x0
	.uleb128 0x4
	.4byte	.LASF23
	.byte	0x4
	.byte	0x5d
	.4byte	0x171
	.uleb128 0x7
	.byte	0x4
	.4byte	0x177
	.uleb128 0x8
	.byte	0x1
	.4byte	0x188
	.uleb128 0x9
	.4byte	0x13e
	.uleb128 0x9
	.4byte	0x7e
	.byte	0x0
	.uleb128 0x7
	.byte	0x4
	.4byte	0x18e
	.uleb128 0x8
	.byte	0x1
	.4byte	0x19a
	.uleb128 0x9
	.4byte	0x19a
	.byte	0x0
	.uleb128 0xb
	.byte	0x4
	.uleb128 0xc
	.byte	0x4
	.byte	0x7
	.uleb128 0x5
	.4byte	.LASF25
	.byte	0x8
	.byte	0x5
	.byte	0x6e
	.4byte	0x1c6
	.uleb128 0xd
	.ascii	"sp\000"
	.byte	0x5
	.byte	0x6f
	.4byte	0x19a
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.ascii	"pc\000"
	.byte	0x5
	.byte	0x70
	.4byte	0x134
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x4
	.4byte	.LASF27
	.byte	0x5
	.byte	0x71
	.4byte	0x19f
	.uleb128 0x5
	.4byte	.LASF28
	.byte	0x8
	.byte	0x6
	.byte	0x3f
	.4byte	0x1fa
	.uleb128 0x6
	.4byte	.LASF29
	.byte	0x6
	.byte	0x40
	.4byte	0x1fa
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x6
	.4byte	.LASF30
	.byte	0x6
	.byte	0x41
	.4byte	0x1fa
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x7
	.byte	0x4
	.4byte	0x1d1
	.uleb128 0x4
	.4byte	.LASF31
	.byte	0x6
	.byte	0x42
	.4byte	0x1d1
	.uleb128 0x4
	.4byte	.LASF32
	.byte	0x7
	.byte	0x3b
	.4byte	0xfe
	.uleb128 0x4
	.4byte	.LASF33
	.byte	0x7
	.byte	0x40
	.4byte	0x188
	.uleb128 0x5
	.4byte	.LASF34
	.byte	0xc
	.byte	0x7
	.byte	0x42
	.4byte	0x258
	.uleb128 0x6
	.4byte	.LASF35
	.byte	0x7
	.byte	0x43
	.4byte	0xf3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x6
	.4byte	.LASF36
	.byte	0x7
	.byte	0x44
	.4byte	0x216
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xd
	.ascii	"arg\000"
	.byte	0x7
	.byte	0x45
	.4byte	0x19a
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.byte	0x0
	.uleb128 0x4
	.4byte	.LASF37
	.byte	0x7
	.byte	0x46
	.4byte	0x221
	.uleb128 0x7
	.byte	0x4
	.4byte	0x258
	.uleb128 0xe
	.4byte	.LASF74
	.byte	0x4
	.byte	0x8
	.byte	0xa4
	.4byte	0x28c
	.uleb128 0xf
	.4byte	.LASF38
	.byte	0x8
	.byte	0xa5
	.4byte	0x109
	.uleb128 0xf
	.4byte	.LASF39
	.byte	0x8
	.byte	0xa6
	.4byte	0x263
	.byte	0x0
	.uleb128 0x4
	.4byte	.LASF40
	.byte	0x8
	.byte	0xa7
	.4byte	0x269
	.uleb128 0x5
	.4byte	.LASF41
	.byte	0x20
	.byte	0x8
	.byte	0xb7
	.4byte	0x314
	.uleb128 0x6
	.4byte	.LASF42
	.byte	0x8
	.byte	0xb8
	.4byte	0x113
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x6
	.4byte	.LASF43
	.byte	0x8
	.byte	0xb9
	.4byte	0x7e
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x6
	.4byte	.LASF44
	.byte	0x8
	.byte	0xba
	.4byte	0x149
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x6
	.4byte	.LASF45
	.byte	0x8
	.byte	0xbb
	.4byte	0xf3
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x6
	.4byte	.LASF46
	.byte	0x8
	.byte	0xbc
	.4byte	0x129
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0xd
	.ascii	"stk\000"
	.byte	0x8
	.byte	0xbd
	.4byte	0x19a
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x6
	.4byte	.LASF47
	.byte	0x8
	.byte	0xbf
	.4byte	0x113
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0x6
	.4byte	.LASF48
	.byte	0x8
	.byte	0xc0
	.4byte	0x166
	.byte	0x2
	.byte	0x23
	.uleb128 0x1c
	.byte	0x0
	.uleb128 0x4
	.4byte	.LASF49
	.byte	0x8
	.byte	0xc1
	.4byte	0x297
	.uleb128 0x5
	.4byte	.LASF50
	.byte	0x20
	.byte	0x8
	.byte	0xe6
	.4byte	0x3c4
	.uleb128 0x6
	.4byte	.LASF51
	.byte	0x8
	.byte	0xe7
	.4byte	0x200
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x6
	.4byte	.LASF52
	.byte	0x8
	.byte	0xe8
	.4byte	0x3c4
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x6
	.4byte	.LASF53
	.byte	0x8
	.byte	0xeb
	.4byte	0x3a
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x10
	.4byte	.LASF54
	.byte	0x8
	.byte	0xef
	.4byte	0x2c
	.byte	0x4
	.byte	0x8
	.byte	0x10
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x10
	.4byte	.LASF55
	.byte	0x8
	.byte	0xf1
	.4byte	0x2c
	.byte	0x4
	.byte	0x1
	.byte	0xf
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x10
	.4byte	.LASF56
	.byte	0x8
	.byte	0xf2
	.4byte	0x2c
	.byte	0x4
	.byte	0x1
	.byte	0xe
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x10
	.4byte	.LASF57
	.byte	0x8
	.byte	0xf3
	.4byte	0x2c
	.byte	0x4
	.byte	0x1
	.byte	0xd
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x6
	.4byte	.LASF58
	.byte	0x8
	.byte	0xf5
	.4byte	0x13e
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x6
	.4byte	.LASF59
	.byte	0x8
	.byte	0xf6
	.4byte	0x3cf
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x6
	.4byte	.LASF60
	.byte	0x8
	.byte	0xf7
	.4byte	0x1c6
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.byte	0x0
	.uleb128 0x7
	.byte	0x4
	.4byte	0x3ca
	.uleb128 0x11
	.4byte	0x314
	.uleb128 0x7
	.byte	0x4
	.4byte	0x28c
	.uleb128 0xa
	.ascii	"TCB\000"
	.byte	0x8
	.byte	0xf8
	.4byte	0x31f
	.uleb128 0x12
	.byte	0x1
	.4byte	.LASF75
	.byte	0x1
	.byte	0x39
	.byte	0x1
	.4byte	.LFB61
	.4byte	.LFE61
	.byte	0x1
	.byte	0x5d
	.uleb128 0x13
	.4byte	.LASF61
	.byte	0x9
	.byte	0x9b
	.4byte	0x65
	.byte	0x1
	.byte	0x1
	.uleb128 0x13
	.4byte	.LASF62
	.byte	0x9
	.byte	0xa8
	.4byte	0x11e
	.byte	0x1
	.byte	0x1
	.uleb128 0x14
	.4byte	0x65
	.4byte	0x41d
	.uleb128 0x15
	.4byte	0x19c
	.byte	0x7
	.byte	0x0
	.uleb128 0x13
	.4byte	.LASF63
	.byte	0x9
	.byte	0xae
	.4byte	0x42a
	.byte	0x1
	.byte	0x1
	.uleb128 0x11
	.4byte	0x40d
	.uleb128 0x13
	.4byte	.LASF64
	.byte	0x9
	.byte	0xe8
	.4byte	0x65
	.byte	0x1
	.byte	0x1
	.uleb128 0x13
	.4byte	.LASF65
	.byte	0x5
	.byte	0x81
	.4byte	0x65
	.byte	0x1
	.byte	0x1
	.uleb128 0x13
	.4byte	.LASF66
	.byte	0x7
	.byte	0x60
	.4byte	0x20b
	.byte	0x1
	.byte	0x1
	.uleb128 0x16
	.4byte	.LASF67
	.byte	0x1
	.byte	0x44
	.4byte	0x65
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.4byte	BIT_REF_4
	.uleb128 0x16
	.4byte	.LASF68
	.byte	0x1
	.byte	0x45
	.4byte	0x53
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.4byte	BIT_REF_2
	.uleb128 0x16
	.4byte	.LASF69
	.byte	0x1
	.byte	0x46
	.4byte	0x3a
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.4byte	BIT_REF_1
	.uleb128 0x16
	.4byte	.LASF70
	.byte	0x1
	.byte	0x48
	.4byte	0x3d5
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.4byte	BIT_BB_TCB_enatex
	.byte	0x0
	.section	.debug_abbrev
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0x0
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0x0
	.byte	0x0
	.uleb128 0x4
	.uleb128 0x16
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x5
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x7
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x8
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x9
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xa
	.uleb128 0x16
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0xc
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0xd
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0xe
	.uleb128 0x17
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xf
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x10
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0xd
	.uleb128 0xb
	.uleb128 0xc
	.uleb128 0xb
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x11
	.uleb128 0x26
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x12
	.uleb128 0x2e
	.byte	0x0
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x13
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0x14
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x15
	.uleb128 0x21
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x16
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.section	.debug_pubnames,"",%progbits
	.4byte	0x5d
	.2byte	0x2
	.4byte	.Ldebug_info0
	.4byte	0x49f
	.4byte	0x3e0
	.ascii	"makeoffset\000"
	.4byte	0x456
	.ascii	"BIT_REF_4\000"
	.4byte	0x468
	.ascii	"BIT_REF_2\000"
	.4byte	0x47a
	.ascii	"BIT_REF_1\000"
	.4byte	0x48c
	.ascii	"BIT_BB_TCB_enatex\000"
	.4byte	0x0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0x0
	.2byte	0x0
	.2byte	0x0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0x0
	.4byte	0x0
	.section	.debug_str,"MS",%progbits,1
.LASF33:
	.ascii	"CBACK\000"
.LASF53:
	.ascii	"tstat\000"
.LASF12:
	.ascii	"uintptr_t\000"
.LASF38:
	.ascii	"wercd\000"
.LASF58:
	.ascii	"texptn\000"
.LASF9:
	.ascii	"long long unsigned int\000"
.LASF17:
	.ascii	"int_t\000"
.LASF57:
	.ascii	"enatex\000"
.LASF71:
	.ascii	"GNU C 4.4.1\000"
.LASF20:
	.ascii	"SIZE\000"
.LASF72:
	.ascii	"../../arch/arm_gcc/common/makeoffset.c\000"
.LASF8:
	.ascii	"long long int\000"
.LASF1:
	.ascii	"signed char\000"
.LASF56:
	.ascii	"wupque\000"
.LASF18:
	.ascii	"uint_t\000"
.LASF11:
	.ascii	"long int\000"
.LASF70:
	.ascii	"BIT_BB_TCB_enatex\000"
.LASF59:
	.ascii	"p_winfo\000"
.LASF45:
	.ascii	"ipriority\000"
.LASF5:
	.ascii	"uint16_t\000"
.LASF62:
	.ascii	"_kernel_ipm\000"
.LASF15:
	.ascii	"double\000"
.LASF23:
	.ascii	"TEXRTN\000"
.LASF67:
	.ascii	"BIT_REF_4\000"
.LASF48:
	.ascii	"texrtn\000"
.LASF46:
	.ascii	"stksz\000"
.LASF0:
	.ascii	"unsigned int\000"
.LASF47:
	.ascii	"texatr\000"
.LASF13:
	.ascii	"long unsigned int\000"
.LASF66:
	.ascii	"_kernel_next_time\000"
.LASF19:
	.ascii	"ulong_t\000"
.LASF39:
	.ascii	"p_tmevtb\000"
.LASF28:
	.ascii	"queue\000"
.LASF6:
	.ascii	"short unsigned int\000"
.LASF43:
	.ascii	"exinf\000"
.LASF73:
	.ascii	"/home/fanghuaqi/workspace/works/eclipse_projects/as"
	.ascii	"p-skyeye/obj/myapp\000"
.LASF36:
	.ascii	"callback\000"
.LASF54:
	.ascii	"priority\000"
.LASF10:
	.ascii	"intptr_t\000"
.LASF65:
	.ascii	"_kernel_excpt_nest_count\000"
.LASF32:
	.ascii	"EVTTIM\000"
.LASF22:
	.ascii	"TASK\000"
.LASF26:
	.ascii	"TOPPERS_dummy_field\000"
.LASF42:
	.ascii	"tskatr\000"
.LASF14:
	.ascii	"float\000"
.LASF55:
	.ascii	"actque\000"
.LASF21:
	.ascii	"TEXPTN\000"
.LASF34:
	.ascii	"time_event_block\000"
.LASF27:
	.ascii	"CTXB\000"
.LASF30:
	.ascii	"p_prev\000"
.LASF37:
	.ascii	"TMEVTB\000"
.LASF61:
	.ascii	"_kernel_idf\000"
.LASF2:
	.ascii	"unsigned char\000"
.LASF24:
	.ascii	"TOPPERS_dummy_t\000"
.LASF69:
	.ascii	"BIT_REF_1\000"
.LASF68:
	.ascii	"BIT_REF_2\000"
.LASF3:
	.ascii	"short int\000"
.LASF29:
	.ascii	"p_next\000"
.LASF52:
	.ascii	"p_tinib\000"
.LASF7:
	.ascii	"uint32_t\000"
.LASF75:
	.ascii	"makeoffset\000"
.LASF16:
	.ascii	"TOPPERS_fp_t\000"
.LASF35:
	.ascii	"index\000"
.LASF44:
	.ascii	"task\000"
.LASF63:
	.ascii	"_kernel_ipm_mask_tbl\000"
.LASF49:
	.ascii	"TINIB\000"
.LASF31:
	.ascii	"QUEUE\000"
.LASF50:
	.ascii	"task_control_block\000"
.LASF51:
	.ascii	"task_queue\000"
.LASF64:
	.ascii	"_kernel_bitpat_cfgint\000"
.LASF74:
	.ascii	"waiting_information\000"
.LASF4:
	.ascii	"uint8_t\000"
.LASF25:
	.ascii	"task_context_block\000"
.LASF40:
	.ascii	"WINFO\000"
.LASF60:
	.ascii	"tskctxb\000"
.LASF41:
	.ascii	"task_initialization_block\000"
	.ident	"GCC: (Sourcery G++ Lite 2010q1-188) 4.4.1"
