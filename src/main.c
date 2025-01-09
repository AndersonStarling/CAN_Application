#include <stdint.h>
#include <zephyr/drivers/can.h>

const struct device *device;
struct can_filter can_filter_user =
{
    .id = 0xff,
    .mask = 0xff,
    .flags = CAN_FILTER_IDE
};

static void can_recv_call_back(const struct device *dev, struct can_frame *frame, void *user_data)
{
    return;
}

int main(void)
{
    int ret = 0;
    can_mode_t can_mode_support;

    device = DEVICE_DT_GET_ONE(st_stm32_bxcan);

    ret = can_get_capabilities(device, &can_mode_support);
    if(0 == ret)
    {
        printf("can_mode_support = %d\n", can_mode_support);
    }

    ret = can_add_rx_filter(device, can_recv_call_back, NULL, &can_filter_user);

    return 0;
}























