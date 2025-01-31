/* Handle CAN message that receive from CAN bus */

#include <stdint.h>
#include <zephyr/drivers/can.h>
#include <CAN_device.h>

#define CAN_NODE_ID        0x123u
#define CAN_MASK_ID        CAN_EXT_ID_MASK
#define CAN_FILTER_TYPE    CAN_FILTER_IDE
#define CAN_OPERATION_MODE CAN_MODE_LOOPBACK
#define CAN_MAX_DATA_LEN   100u


static const struct device *can_device;

struct can_filter can_filter_information =
{
    .id    = CAN_NODE_ID,
    .mask  = CAN_MASK_ID,
    .flags = CAN_FILTER_TYPE
};

CAN_data_struct_t * CAN_internal_recv_data = NULL;

static void CAN_device_recv_call_back(const struct device *dev, struct can_frame *frame, void *user_data)
{
    uint32_t index = 0;
    CAN_data_struct_t * recv_data = NULL;

    recv_data = (CAN_data_struct_t *)user_data;

    if(NULL != recv_data && recv_data->data_size <= CAN_MAX_DLEN)
    {
        for(index = 0; index < CAN_MAX_DLEN; index ++)
        {
            recv_data->data[index] = frame->data[index];
        }
    }

    return;
}

int CAN_device_init(void)
{
    int ret = 0;

    /* get CAN device from device tree */
    can_device = DEVICE_DT_GET_ONE(st_stm32_bxcan);

    /* Set CAN operation mode */
    ret = can_set_mode(can_device, CAN_OPERATION_MODE);
    if(ret != 0)
    {
        return ret;
    }

    /* Start CAN bus */
    ret = can_start(can_device);
    if(ret != 0)
    {
        return ret;
    }

    return ret;
}

int CAN_device_add_recv_data_cb(CAN_data_struct_t * recv_data_cb)
{
    int ret = 0;

    /* Add CAN received message filter */
    ret = can_add_rx_filter(can_device, CAN_device_recv_call_back, recv_data_cb, &can_filter_information);

    return ret;
}








