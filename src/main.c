#include <stdint.h>
#include <zephyr/drivers/can/can_mcan.h>

const struct device *device;

// #if DT_NODE_HAS_STATUS(DT_NODELABEL(can1), okay)
// #error "Hello _11111"
// #else
// #error "Node is disabled"
// #endif

int main(void)
{
    device = DEVICE_DT_GET_ONE(st_stm32_bxcan);



    return 0;
}























