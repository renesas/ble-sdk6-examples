/**
 ****************************************************************************************
 *
 * @file user_fsp.c
 *
 * @brief FSP external processor user application source code.
 *
 * Copyright (C) 2012-2025 Renesas Electronics Corporation and/or its affiliates.
 * All rights reserved. Confidential Information.
 *
 * This software ("Software") is supplied by Renesas Electronics Corporation and/or its
 * affiliates ("Renesas"). Renesas grants you a personal, non-exclusive, non-transferable,
 * revocable, non-sub-licensable right and license to use the Software, solely if used in
 * or together with Renesas products. You may make copies of this Software, provided this
 * copyright notice and disclaimer ("Notice") is included in all such copies. Renesas
 * reserves the right to change or discontinue the Software at any time without notice.
 *
 * THE SOFTWARE IS PROVIDED "AS IS". RENESAS DISCLAIMS ALL WARRANTIES OF ANY KIND,
 * WHETHER EXPRESS, IMPLIED, OR STATUTORY, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. TO THE
 * MAXIMUM EXTENT PERMITTED UNDER LAW, IN NO EVENT SHALL RENESAS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE, EVEN IF RENESAS HAS BEEN ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGES. USE OF THIS SOFTWARE MAY BE SUBJECT TO TERMS AND CONDITIONS CONTAINED IN
 * AN ADDITIONAL AGREEMENT BETWEEN YOU AND RENESAS. IN CASE OF CONFLICT BETWEEN THE TERMS
 * OF THIS NOTICE AND ANY SUCH ADDITIONAL LICENSE AGREEMENT, THE TERMS OF THE AGREEMENT
 * SHALL TAKE PRECEDENCE. BY CONTINUING TO USE THIS SOFTWARE, YOU AGREE TO THE TERMS OF
 * THIS NOTICE.IF YOU DO NOT AGREE TO THESE TERMS, YOU ARE NOT PERMITTED TO USE THIS
 * SOFTWARE.
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup APP
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "rwip_config.h"             // SW configuration
#include "user_periph_setup.h"       // SW configuration
#include "user_fsp.h"
#include "arch_api.h"
#include "user_config.h"
#include "user_fsp.h"

#ifdef CFG_FSP_EXT_TASK
#include "fsp_ext_task.h"
#endif

#if ((UART_FLOW_CTRL_WAKEUP) && (!BLE_APP_PRESENT))
#include "ext_wakeup_uart.h"
#endif 

extern const gtl_pads_config_t * pad_cfg;

/*
 * FUNCTION DEFINITIONS
 ****************************************************************************************
*/

/**
 ****************************************************************************************
 * @brief The handler of the FSP user commands
 ****************************************************************************************
 */
static void custom_user_commands_handler (ke_msg_id_t const msgid,
                                         void const *param,
                                         ke_task_id_t const dest_id,
                                         ke_task_id_t const src_id)
{
    switch (msgid)
    {
        case USER_CUST_CMD_1:
            break;
        case USER_CUST_CMD_2:
            break;
        default:
            break;
    }
}

/**
 ****************************************************************************************
 * @brief User code initialization function.
 ****************************************************************************************
*/
void user_on_init(void)
{
#ifdef CFG_FSP_EXT_TASK
    fsp_ext_task_init(custom_user_commands_handler);
#endif
    
#if ((UART_FLOW_CTRL_WAKEUP) && (!BLE_APP_PRESENT))

    ext_wkup_uart_pins_t wkup_pins = {
        .cts_uart_port = pad_cfg->cts_pad_port,
        .cts_uart_pin = pad_cfg->cts_pad_pin,
        .rts_uart_port = pad_cfg->rts_pad_port,
        .rts_uart_pin = pad_cfg->rts_pad_pin,
    };
    
    ext_wakeup_uart_init(wkup_pins);
    ext_wakeup_uart_enable();
#endif
    
    arch_set_sleep_mode(app_default_sleep_mode);
}

/// @} APP
