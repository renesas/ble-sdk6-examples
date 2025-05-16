/**
 ****************************************************************************************
 *
 * @file user_multi_peripheral.c
 *
 * @brief Empty peripheral template project source code.
 *
 * Copyright (C) 2012-2021 Renesas Electronics Corporation and/or its affiliates
 * The MIT License (MIT)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 * OR OTHER DEALINGS IN THE SOFTWARE.
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @addtogroup APP
 * @{
 ****************************************************************************************
 */
#include "rwip_config.h"             // SW configuration


/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "app_api.h"
#include "user_multi_peripheral.h"
#include "user_callback_config.h"
#include "app.h"
#include "app_prf_perm_types.h"
#include "user_custs1_def.h"
#include "user_custs1_impl.h"
#include "arch_console.h"

/*
 * FUNCTION DEFINITIONS
 ****************************************************************************************
*/

/*
 * GLOBAL VARIABLE DEFINITIONS
 ****************************************************************************************
 */
struct app_env_tag user_app_env[APP_EASY_MAX_ACTIVE_CONNECTION]     __SECTION_ZERO("retention_mem_area0"); //@RETENTION MEMORY

extern uint16_t non_db_val_read[CFG_MAX_CONNECTIONS];
extern uint16_t non_db_val_write[CFG_MAX_CONNECTIONS];

static uint8_t print_out_connected_dev(void)
{
    uint8_t connected_dev = 0;
    arch_printf("Connected Devices: \n\r");
    for (uint8_t i=0; i < APP_IDX_MAX; i++)
    {
        if (app_env[i].connection_active == true)
        {
            connected_dev++;
            arch_printf("[%d] ", i);
            arch_printf("%02x:%02x:%02x:%02x:%02x:%02x", 
            app_env[i].peer_addr.addr[5],
            app_env[i].peer_addr.addr[4],
            app_env[i].peer_addr.addr[3],
            app_env[i].peer_addr.addr[2],
            app_env[i].peer_addr.addr[1],
            app_env[i].peer_addr.addr[0]);
            arch_printf("\n\r"); 
        }            
    }
    if (!connected_dev)
        arch_printf("No currently connected devices \n\r");
    else if (connected_dev == APP_IDX_MAX)
        arch_printf("Peripheral is connected with the maximum number of centrals \n\r");
    arch_printf("**************************************** \n\r");
    return connected_dev;
}

void printout_db_status(void)
{
    arch_printf("bd_address         Read_Char         Write_Char \n\r");
    for (uint8_t i=0; i < APP_IDX_MAX; i++)
    {
        if (app_env[i].connection_active == true)
        {
            arch_printf("%02x:%02x:%02x:%02x:%02x:%02x", 
            app_env[i].peer_addr.addr[5],
            app_env[i].peer_addr.addr[4],
            app_env[i].peer_addr.addr[3],
            app_env[i].peer_addr.addr[2],
            app_env[i].peer_addr.addr[1],
            app_env[i].peer_addr.addr[0]);
            arch_printf("    ");
            arch_printf("%02x", non_db_val_read[sdkconidx_to_appconidx(i)]);
            arch_printf("              ");
            arch_printf("%02x", non_db_val_write[sdkconidx_to_appconidx(i)]);
            arch_printf("\n\r");
        }            
    }
}

uint8_t sdkconidx_to_appconidx(uint8_t sdk_conidx)
{
    for(uint8_t app_conidx = 0; app_conidx < APP_IDX_MAX; app_conidx++)
    {
        if (!memcmp(app_env[sdk_conidx].peer_addr.addr, user_app_env[app_conidx].peer_addr.addr, sizeof(struct bd_addr)))
            return user_app_env[app_conidx].conidx;
    }
    return 0;
}

uint8_t appconidx_to_sdkconidx(uint8_t app_conidx)
{
    for(uint8_t sdk_conidx = 0; sdk_conidx < APP_IDX_MAX; sdk_conidx++)
    {
        if (!memcmp(user_app_env[sdk_conidx].peer_addr.addr, app_env[app_conidx].peer_addr.addr, sizeof(struct bd_addr)))
            return app_env[sdk_conidx].conidx;
    }
    return 0;
}

uint8_t add_to_user_peer_log(uint8_t connection_idx)
{
    /* Check if the connected device exists in the application registered devices if yes return app_conidx  */
    for(uint8_t idx = 0; idx < APP_IDX_MAX; idx++)
        if (!memcmp(app_env[connection_idx].peer_addr.addr, user_app_env[idx].peer_addr.addr, sizeof(struct bd_addr)))
        {
            //memcpy(&user_app_env[idx], &app_env[connection_idx], sizeof(struct app_env_tag) );
            user_app_env[idx].connection_active = true;
            user_app_env[idx].conidx = idx;
            return idx;
        }
    /* If the bd address is not one of the stored devices and there is room for the device register the new device */
    for(uint8_t idx = 0; idx < APP_IDX_MAX; idx++)
    {
        if(user_app_env[idx].conidx == GAP_INVALID_CONIDX)
        {
            memcpy(&user_app_env[idx], &app_env[connection_idx], sizeof(struct app_env_tag));
            return idx;
        }
    }
    return 0xFF; // No room for an extra connection
}

void user_on_connection(uint8_t connection_idx, struct gapc_connection_req_ind const *param)
{
    add_to_user_peer_log(connection_idx);
    user_app_adv_start();
    default_app_on_connection(connection_idx, param);
}

void user_on_disconnect( struct gapc_disconnect_ind const *param)
{
    user_app_env[sdkconidx_to_appconidx(param->conhdl)].connection_active = false;
    user_app_env[sdkconidx_to_appconidx(param->conhdl)].conidx = GAP_INVALID_CONIDX;
    
    arch_printf("Device %02x:%02x:%02x:%02x:%02x:%02x has disconnected due to reason %02x\n\r",
                app_env[param->conhdl].peer_addr.addr[5],
                app_env[param->conhdl].peer_addr.addr[4],
                app_env[param->conhdl].peer_addr.addr[3],
                app_env[param->conhdl].peer_addr.addr[2],
                app_env[param->conhdl].peer_addr.addr[1],
                app_env[param->conhdl].peer_addr.addr[0],
                param->reason);
}

void user_app_adv_start(void)
{
    app_easy_gap_undirected_advertise_start();
    arch_printf("Device is Advertising \n\r");
    print_out_connected_dev();
}

void user_app_on_init(void)
{
    default_app_on_init();
    
    for(uint8_t idx = 0; idx < APP_IDX_MAX; idx++)  
    {
        user_app_env[idx].conidx = GAP_INVALID_CONIDX;
    }
}

void user_catch_rest_hndl(ke_msg_id_t const msgid,
                          void const *param,
                          ke_task_id_t const dest_id,
                          ke_task_id_t const src_id)
{
    switch(msgid)
    {
        case CUSTS1_VAL_WRITE_IND:
        {
            struct custs1_val_write_ind const *msg_param = (struct custs1_val_write_ind const *)(param);

            switch (msg_param->handle)
            {
                case SVC1_IDX_CONTROL_POINT_VAL:
                    user_svc1_ctrl_wr_ind_handler(msgid, msg_param, dest_id, src_id);
                    break;

                case SVC1_IDX_LED_STATE_VAL:
                    user_svc1_led_wr_ind_handler(msgid, msg_param, dest_id, src_id);
                    break;

                case SVC1_IDX_ADC_VAL_1_NTF_CFG:
                    user_svc1_adc_val_1_cfg_ind_handler(msgid, msg_param, dest_id, src_id);
                    break;

                case SVC1_IDX_INDICATEABLE_IND_CFG:
                    user_svc1_long_val_cfg_ind_handler(msgid, msg_param, dest_id, src_id);
                    break;

                case SVC1_IDX_LONG_VALUE_NTF_CFG:
                    user_svc1_long_val_cfg_ind_handler(msgid, msg_param, dest_id, src_id);
                    break;

                case SVC1_IDX_LONG_VALUE_VAL:
                    user_svc1_long_val_wr_ind_handler(msgid, msg_param, dest_id, src_id);
                    break;
                
                case SVC2_WRITE_1_VAL:
                    user_svc2_write_1_val_wr_ind_handler(msgid, msg_param, dest_id, src_id);
                    break;

                default:
                    break;
            }
        } break;

        case CUSTS1_VAL_NTF_CFM:
        {
            struct custs1_val_ntf_cfm const *msg_param = (struct custs1_val_ntf_cfm const *)(param);

            switch (msg_param->handle)
            {
                case SVC1_IDX_ADC_VAL_1_VAL:
                    break;

                case SVC1_IDX_LONG_VALUE_VAL:
                    break;

                default:
                    break;
            }
        } break;

        case CUSTS1_VAL_IND_CFM:
        {
            struct custs1_val_ind_cfm const *msg_param = (struct custs1_val_ind_cfm const *)(param);

            switch (msg_param->handle)
            {
                case SVC1_IDX_INDICATEABLE_VAL:
                    break;

                default:
                    break;
             }
        } break;

        case CUSTS1_ATT_INFO_REQ:
        {
            struct custs1_att_info_req const *msg_param = (struct custs1_att_info_req const *)param;

            switch (msg_param->att_idx)
            {
                case SVC1_IDX_LONG_VALUE_VAL:
                    user_svc1_long_val_att_info_req_handler(msgid, msg_param, dest_id, src_id);
                    break;

                default:
                    user_svc1_rest_att_info_req_handler(msgid, msg_param, dest_id, src_id);
                    break;
             }
        } break;

        case GAPC_PARAM_UPDATED_IND:
        {
            // Cast the "param" pointer to the appropriate message structure
            struct gapc_param_updated_ind const *msg_param = (struct gapc_param_updated_ind const *)(param);

            // Check if updated Conn Params filled to preferred ones
            if ((msg_param->con_interval >= user_connection_param_conf.intv_min) &&
                (msg_param->con_interval <= user_connection_param_conf.intv_max) &&
                (msg_param->con_latency == user_connection_param_conf.latency) &&
                (msg_param->sup_to == user_connection_param_conf.time_out))
            {
            }
        } break;

        case CUSTS1_VALUE_REQ_IND:
        {
            struct custs1_value_req_ind const *msg_param = (struct custs1_value_req_ind const *) param;

            switch (msg_param->att_idx)
            {
                case SVC3_IDX_READ_1_VAL:
                {
                    user_svc3_read_non_db_val_handler(msgid, msg_param, dest_id, src_id);
                } break;
                
                case SVC2_WRITE_1_VAL:
                {
                    user_svc2_write_non_db_val_handler(msgid, msg_param, dest_id, src_id);
                }break;

                default:
                {
                    // Send Error message
                    struct custs1_value_req_rsp *rsp = KE_MSG_ALLOC(CUSTS1_VALUE_REQ_RSP,
                                                                    src_id,
                                                                    dest_id,
                                                                    custs1_value_req_rsp);

                    // Provide the connection index.
                    rsp->conidx  = app_env[msg_param->conidx].conidx;
                    // Provide the attribute index.
                    rsp->att_idx = msg_param->att_idx;
                    // Force current length to zero.
                    rsp->length = 0;
                    // Set Error status
                    rsp->status  = ATT_ERR_APP_ERROR;
                    // Send message
                    ke_msg_send(rsp);
                } break;
             }
        } break;

        default:
            break;
    }
}


/// @} APP
