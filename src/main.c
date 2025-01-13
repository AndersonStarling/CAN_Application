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
    printf("call back called\n");
    return;
}

int main(void)
{
    int ret = 0;
    can_mode_t can_mode_support;
    can_mode_t can_current_mode;
    struct can_frame can_message;

    printf("Hello\n");

    device = DEVICE_DT_GET_ONE(st_stm32_bxcan);

    ret = can_get_capabilities(device, &can_mode_support);
    if(0 == ret)
    {
        printf("can_mode_support = %d\n", can_mode_support);
    }

    ret = can_set_mode(device, CAN_MODE_LOOPBACK);
    if(0 == ret)
    {
        printf("can_set_mode successfully\n");
    }

    can_current_mode = can_get_mode(device);
    printf("can_current_mode = %d\n", can_current_mode);

    ret = can_start(device);
    if(0 == ret)
    {
        printf("can_start = %d\n", ret);
    }

    ret = can_add_rx_filter(device, can_recv_call_back, NULL, &can_filter_user);
    if(0 == ret)
    {
        printf("can_add_rx_filter = %d\n", ret);
    }

    ret = can_send(device, &can_message, K_FOREVER, NULL, NULL);
    printf("can_send = %d\n", ret);
    if(0 == ret)
    {
        printf("can_send = %d\n", ret);
    }

    return 0;
}























