/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief ZLG118 PCNT �û������ļ�
 * \sa am_hwconf_zlg118_pcnt.c
 *
 * \internal
 * \par Modification history
 * - 1.00 19-10-12
 * \endinternal
 */

#include "ametal.h"
#include "am_gpio.h"
#include "am_zlg118.h"
#include "zlg118_clk.h"
#include "zlg118_inum.h"
#include "zlg118_regbase.h"
#include "am_zlg118_clk.h"
#include "am_zlg118_pcnt.h"

/**
 * \addtogroup am_if_src_hwconf_zlg118_pcnt
 * \copydoc am_hwconf_zlg118_pcnt.c
 * @{
 */

/**
 * \brief PCNT ƽ̨��ʼ������
 */
am_local void __zlg118_pcnt_plfm_init (void)
{
    am_gpio_pin_cfg(PIOB_5, PIOB_5_INPUT_FLOAT | PIOB_5_PCNT_S0);
    am_gpio_pin_cfg(PIOB_7, PIOB_7_INPUT_FLOAT | PIOB_7_PCNT_S1);

    am_clk_enable(CLK_PCNT);
    am_zlg118_clk_reset(CLK_PCNT);
}

/**
 * \brief PCNT ƽ̨���ʼ������
 */
am_local void __zlg118_pcnt_plfm_deinit (void)
{
    am_zlg118_clk_reset(CLK_PCNT);
    am_clk_disable(CLK_PCNT);
}

/** \brief PCNT �豸��Ϣ */
am_local am_const am_zlg118_pcnt_devinfo_t __g_zlg118_pcnt_devinfo = {
        ZLG118_PCNT_BASE,
        CLK_PCNT,
        INUM_PCNT,
        __zlg118_pcnt_plfm_init,
        __zlg118_pcnt_plfm_deinit
};

/** \brief PCNT �豸ʵ�� */
am_local am_zlg118_pcnt_dev_t __g_zlg118_pcnt_dev;

/**
 * \brief PCNT ʵ����ʼ��
 */
am_zlg118_pcnt_handle_t am_zlg118_pcnt_inst_init (void)
{
    return am_zlg118_pcnt_init(&__g_zlg118_pcnt_dev, &__g_zlg118_pcnt_devinfo);
}

/**
 * \brief PCNT ʵ�����ʼ��
 */
void am_zlg118_pcnt_inst_deinit (am_zlg118_pcnt_handle_t handle)
{
    am_zlg118_pcnt_deinit(handle);
}

/**
 * @}
 */

/* end of file */