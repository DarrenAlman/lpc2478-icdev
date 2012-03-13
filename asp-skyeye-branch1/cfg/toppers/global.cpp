/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *  Copyright (C) 2007-2008 by TAKAGI Nobuhisa
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ��������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ��������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 */
#include <new>
#include <map>
#include "toppers/global.hpp"

namespace toppers
{

  /*!
   *  \brief  �������Х륪�֥������ȤؤΥ������å�
   *  \param[in]  key   ���֥�������̾
   *  \return     key �ǻ��ꤷ�����֥������Ȥؤλ���
   *
   *  �������Х륪�֥������ȤؤΥ���������층�������롣
   *  ���δؿ���𤷤ƥ������Х륢��������Ԥ����Ȥˤ�ꡢ�̾����Ū���֥������Ȥ�����ưŪ�������
   *  ����˴ؤ������꤬��ä���롣
   *  �ޤ�������Ū�˴������Ƥ��륪�֥������Ȥϡ��ץ�����ཪλ���˥ǥ��ȥ饯�����ƤФ�뤳�ȤϤʤ���
   *  �ʸ�̩�ˤ����Х���꡼���ˤ����뤬�������ϤȤ��ˤʤ���
   */
  boost::any& global( std::string const& key )
  {
    static std::map< std::string, boost::any >* gvm = 0;
    if ( gvm == 0 )
    {
      union max_aligner
      {
        long long ll;
        double d;
        long double ld;
        void* pv;
        void (*pfn)();
      };
      const std::size_t size = ( sizeof( std::map< std::string, boost::any > ) + sizeof( max_aligner ) - 1 ) / sizeof( max_aligner );
      static max_aligner gvm_storage[ size ];
      gvm = new ( gvm_storage ) std::map< std::string, boost::any >;  // �ǥ��ȥ饯���ϸƤФ�ʤ�
    }
    return ( *gvm )[key];
  }

}