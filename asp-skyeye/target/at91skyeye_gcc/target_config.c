/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2006 by GJ Business Division RICOH COMPANY,LTD. JAPAN
 *  Copyright (C) 2007-2010 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: target_config.c 951 2008-04-14 08:51:11Z ertl-honda $
 */

/*
 * チップ依存モジュール（AT91SKYEYE用）
 */

#include "kernel_impl.h"
#include <sil.h>
#include "target_serial.h"
#include <stdlib.h>

/*
 * 各割込みの割込み要求禁止フラグの状態
 */
uint32_t idf;

/*
 * 現在の割込み優先度マスクの値
 */
PRI ipm;
 
/*
 *  割込み属性が設定されているかを判別するための変数
 */
uint32_t bitpat_cfgint;

/*
 *  文字列の出力（バージョンチェック用）
 */
static void
target_fput_str(char *c) {
	while(*c != '\0') {
		at91skyeye_putc(*c++);
	}
	at91skyeye_putc('\n');
}

/*
 *  バージョンチェック
 */
void
version_check(void) {

	/* SkyEyeのバージョンを確認 */
	if (sil_rew_mem((void *)(SKYEYE_VER_REG)) != SUPPORT_SKYEYE_VER) {
		target_fput_str("SkyEye version is mismatch!!");
		target_fput_str("Kernel Exit...");
		ext_ker();
	}

	if ((sil_rew_mem((void *)(DEVM_VER_REG)) & 0xfff0)
		!= (SUPPORT_DEVM_VER & 0xfff0)) {
		target_fput_str("DeviceManager Extension version is mismatch!!");
		target_fput_str("Kernel Exit...");
		ext_ker();
	}
	
}

/*
 *  ターゲット依存の初期化
 */
void
target_initialize(void)
{
	/*
	 *  target_fput_logが使えるようにUARTを初期化
	 */
	at91skyeye_init_uart();

	/*
	 *  バージョンの確認
	 */
	//version_check();

	/*
	 *  ARM依存の初期化
	 */
	core_initialize();
    
	/*
	 * 各割込みの割込み要求禁止フラグ全禁止
	 */
	idf = ~0U;

	/*
	 * 割込み優先度マスクは0
	 */ 
	ipm = 0U;

	/*
	 * 全ての割込みをマスク
	 */ 
	at91skyeye_disable_int(~0U);

	/*
	 * すべての割込みを許可
	 */
	at91skyeye_clear_int(~0U);

	/*
	 *  割込み属性が設定されているかを判別するための変数を初期化する．
	 */
	bitpat_cfgint = 0U;
}

/*
 *  ターゲット依存の終了処理
 */
void
target_exit(void)
{
	extern void    software_term_hook(void);
	void (*volatile fp)(void) = software_term_hook;

	/*
	 *  software_term_hookへのポインタを，一旦volatile指定のあるfpに代
	 *  入してから使うのは，0との比較が最適化で削除されないようにするた
	 *  めである．
	 */
	if (fp != 0) {
		(*fp)();
	}

	/*
	 *  ARM依存の終了処理
	 */
	core_terminate();

	/*
	 *  すべての割込みをマスクする．
	 */
	at91skyeye_disable_int(~0U);

	/*
	 *  開発環境依存の終了処理
	 */
	at91skyeye_exit();

	exit(0);
}

/*
 *  システムログの低レベル出力のための文字出力
 */
void
target_fput_log(char_t c)
{
	if (c == '\n') {
		at91skyeye_putc('\r');
	}
	at91skyeye_putc(c);
}

/*
 *  割込み要求ラインの属性の設定
 *
 *  ASPカーネルでの利用を想定して，パラメータエラーはアサーションでチェッ
 *  クしている．FI4カーネルに利用する場合には，エラーを返すようにすべき
 *  であろう．
 *
 */
void
x_config_int(INTNO intno, ATR intatr, PRI intpri)
{
	assert(VALID_INTNO(intno));
	assert(TMIN_INTPRI <= intpri && intpri <= TMAX_INTPRI);

	/*
	 *  割込み属性が設定されているかを判別するための変数の設定
	 */
	bitpat_cfgint |= INTNO_BITPAT(intno);
    
	/* 
	 * いったん割込みを禁止する
	 */    
	x_disable_int(intno);

	if ((intatr & TA_ENAINT) != 0U){
		(void)x_enable_int(intno);
	}    
}

#ifndef OMIT_DEFAULT_INT_HANDLER
/*
 * 未定義の割込みが入った場合の処理
 */
void
default_int_handler(void){
	syslog_0(LOG_EMERG, "Unregistered Interrupt occurs.");
	target_exit();
}
#endif /* OMIT_DEFAULT_INT_HANDLER */

extern void software_init_hook(void);

/*
 *  コンパイラのスタートアップルーチンから呼び出される．
 *  sta_ker()を呼び出してカーネルをスタートさせる． 
 */
int
main(void)
{
	/*
	 *  software_init_hook を呼出し（0 でない場合）
	 *
	 *  ソフトウェア環境（特にライブラリ）に依存して必要な初期化処
	 *  理がある場合は，software_init_hook という関数を用意すれば
	 *  よい．
	 */
	if(software_init_hook != NULL) {
		software_init_hook();
	}
	sta_ker();
	return 1;
}
