/* This file is generated from target_rename.def by genrename. */

#ifndef TOPPERS_TARGET_RENAME_H
#define TOPPERS_TARGET_RENAME_H

/*
 *  target_config.c, target_support.S
 */
#define idf							_kernel_idf
#define ipm							_kernel_ipm
#define inh_tbl						_kernel_inh_tbl
#define ipm_mask_tbl				_kernel_ipm_mask_tbl
#define inh_ipm_tbl					_kernel_inh_ipm_tbl
#define bitpat_cfgint				_kernel_bitpat_cfgint
#define x_config_int				_kernel_x_config_int

#define undef_handler				_kernel_undef_handler
#define swi_handler					_kernel_swi_handler
#define prefetch_handler			_kernel_prefetch_handler
#define data_abort_handler			_kernel_data_abort_handler
#define interrupt_handler			_kernel_interrupt_handler
#define fiq_handler					_kernel_fiq_handler

/*
 *  core_config.c, core_support.S
 */
#define core_initialize				_kernel_core_initialize
#define core_terminate				_kernel_core_terminate


#ifdef TOPPERS_LABEL_ASM

/*
 *  target_config.c, target_support.S
 */
#define _idf						__kernel_idf
#define _ipm						__kernel_ipm
#define _inh_tbl					__kernel_inh_tbl
#define _ipm_mask_tbl				__kernel_ipm_mask_tbl
#define _inh_ipm_tbl				__kernel_inh_ipm_tbl
#define _bitpat_cfgint				__kernel_bitpat_cfgint
#define _x_config_int				__kernel_x_config_int

#define _undef_handler				__kernel_undef_handler
#define _swi_handler				__kernel_swi_handler
#define _prefetch_handler			__kernel_prefetch_handler
#define _data_abort_handler			__kernel_data_abort_handler
#define _interrupt_handler			__kernel_interrupt_handler
#define _fiq_handler				__kernel_fiq_handler

/*
 *  core_config.c, core_support.S
 */
#define _core_initialize			__kernel_core_initialize
#define _core_terminate				__kernel_core_terminate


#endif /* TOPPERS_LABEL_ASM */

#include "arm_gcc/common/core_rename.h"

#endif /* TOPPERS_TARGET_RENAME_H */
