/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2006-2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  @(#) $Id: core_config.c 956 2008-04-14 09:16:00Z ertl-honda $
 */

/*
 *        コア依存モジュール（ARM用）
 */
#include "kernel_impl.h"
#include "check.h"
#include "task.h"

/*
 *  コンテキスト参照のための変数
 */
uint32_t excpt_nest_count;

#ifndef VECTOR_KERNEL
/*
 *  例外ベクタに書き込まれたジャンプ命令が参照するアドレス
 * 
 */
uint32_t *arm_vector_ref_tbl_add[8];

/*
 * 例外に応じたハンドラの起動番地
 */
uint32_t arm_saved_exch_add[8];
#endif /* VECTOR_KERNEL */

/*
 *  プロセッサ依存の初期化
 */
void
core_initialize()
{
    /*
     *  カーネル起動時は非タスクコンテキストとして動作させるため1に
     */ 
    excpt_nest_count = 1;
    
#ifndef VECTOR_KERNEL    
    {
        uint32_t i, vector_value;

        /*
         * 例外ベクタに登録されている命令から参照されるアドレスと，
         * そのアドレスの内容(ハンドラの番地)を保存する．
         */
        for(i = 0; i < TNUM_EXCH; i++){
            vector_value = *(volatile uint32_t *)(VECTOR_START + (i*4));
            vector_value &= 0x00000fff;
            arm_vector_ref_tbl_add[i]  =  (uint32_t *)(vector_value + 8) + i;
            arm_saved_exch_add[i] = *(arm_vector_ref_tbl_add[i]);
        }
    }
#endif /* VECTOR_KERNEL */    
}

/*
 *  プロセッサ依存の終了処理
 */
void
core_terminate(void)
{
#ifndef VECTOR_KERNEL
    uint32_t i;
    
    /*
     * 例外ベクタを元に戻す
     */
    for(i = 0; i < TNUM_EXCH; i++){
        *arm_vector_ref_tbl_add[i]  = arm_saved_exch_add[i];
    }    
#endif /* VECTOR_KERNEL */   
}

/*
 *  CPU例外の発生状況のログ出力
 *
 *  CPU例外ハンドラの中から，CPU例外情報ポインタ（p_excinf）を引数とし
 *  て呼び出すことで，CPU例外の発生状況をシステムログに出力する．
 */
#ifdef SUPPORT_XLOG_SYS

void
xlog_sys(void *p_excinf)
{    
}

#endif /* SUPPORT_XLOG_SYS */

/*
 *  例外ベクタから直接実行するハンドラを登録
 */ 
void
x_install_exc(EXCNO excno, FP exchdr)
{
#ifdef VECTOR_KERNEL
    *(((FP*)vector_ref_tbl) + excno) = exchdr;
#else
    *arm_vector_ref_tbl_add[excno] = (uint32_t)exchdr;
#endif /* VECTOR_KERNEL */    
}

#ifndef OMIT_DEFAULT_EXC_HANDLER
/*
 * 未定義の例外が入った場合の処理
 */
void
default_exc_handler(void){
    syslog_0(LOG_EMERG, "Unregistered Exception occurs.");
    ext_ker();
}
#endif /* OMIT_DEFAULT_EXC_HANDLER */
