/*
 * =====================================================================================
 *
 *       Filename:  target.c
 *
 *    Description:  目标初始化的C语言实现
 *
 *        Version:  1.0
 *        Created:  2011-1-22 21:51:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  renwei
 *        Company:  hust
 *
 * =====================================================================================
 */
#define DEFAULT_ISTKSZ  40960 /* 40KB 堆栈(SVC模式下)  */

static unsigned int intstack[DEFAULT_ISTKSZ];		/* interrupt stack */

unsigned int * const p_intstack = &intstack[DEFAULT_ISTKSZ];



