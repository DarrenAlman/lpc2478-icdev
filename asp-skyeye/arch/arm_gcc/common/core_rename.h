/* This file is generated from core_rename.def by genrename. */

#ifndef TOPPERS_CORE_RENAME_H
#define TOPPERS_CORE_RENAME_H

#define start_r						_kernel_start_r
#define ret_int						_kernel_ret_int
#define ret_exc						_kernel_ret_exc
#define excpt_nest_count			_kernel_excpt_nest_count
#define exch_tbl					_kernel_exch_tbl

#ifdef TOPPERS_LABEL_ASM

#define _start_r					__kernel_start_r
#define _ret_int					__kernel_ret_int
#define _ret_exc					__kernel_ret_exc
#define _excpt_nest_count			__kernel_excpt_nest_count
#define _exch_tbl					__kernel_exch_tbl

#endif /* TOPPERS_LABEL_ASM */


#endif /* TOPPERS_CORE_RENAME_H */
