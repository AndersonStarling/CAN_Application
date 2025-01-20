/* Handle CAN message that receive from CAN bus */

#include <stdint.h>
#include <zephyr/drivers/can.h>

#define CAN_NODE_ID        0x123u
#define CAN_MASK_ID        CAN_EXT_ID_MASK
#define CAN_FILTER_TYPE    CAN_FILTER_IDE
#define CAN_OPERATION_MODE CAN_MODE_LOOPBACK

static const struct device *can_device;

struct can_filter can_filter_information =
{
    .id    = CAN_NODE_ID,
    .mask  = CAN_MASK_ID,
    .flags = CAN_FILTER_TYPE
};

int CAN_device_init(void)
{
    int ret = 0;

    /* get CAN device from device tree */
    can_device = DEVICE_DT_GET_ONE(st_stm32_bxcan);

    /* Set CAN operation mode */
    ret = can_set_mode(device, CAN_OPERATION_MODE);
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

    /* Add CAN received message filter */
    ret = can_add_rx_filter(device, can_recv_call_back, NULL, &can_filter_information);
    if(ret != 0)
    {
        return ret;
    }

}









