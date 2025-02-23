#include <stdint.h>
#include <zephyr/kernel.h>
#include "receive_process.h"
#include "recv_data.h"
#include "event_handler.h"
#include <zephyr/drivers/can.h>

#define TEST_CAN_THREAD_STACK    2048
#define TEST_CAN_THREAD_PRIORITY 7

static const struct device *device;

static struct can_frame can_message = 
{
    .id    = 0x123,
    .dlc   = 2,
    .data[0]  = 1,
    .data[1]  = 2,
    .flags = CAN_FRAME_IDE
};

extern void test_can_thread(void *, void *, void *);

K_THREAD_STACK_DEFINE(test_can_thread_stack_size, TEST_CAN_THREAD_STACK);
struct k_thread test_can_thread_data;
static k_tid_t thread_id;

void test_can_process_init(void)
{
    /* init receive thread */
    thread_id = k_thread_create(&test_can_thread_data, test_can_thread_stack_size,
                                K_THREAD_STACK_SIZEOF(test_can_thread_stack_size),
                                test_can_thread,
                                NULL, NULL, NULL,
                                TEST_CAN_THREAD_PRIORITY, 0, K_FOREVER);
}

void test_can_process_start(void)
{
    k_thread_start(thread_id);
}

void test_can_thread(void * param1, void * param2, void * param3)
{
    int ret = 0;

    device = DEVICE_DT_GET_ONE(st_stm32_bxcan);

    for(;;)
    {
        ret = can_send(device, &can_message, K_FOREVER, NULL, NULL);
        if(0 != ret)
        {
            printf("can_send failed = %d\n", ret);
        }

        can_message.data[0] ++;
        can_message.data[0] = can_message.data[0] % 100;

        k_msleep(100);
    }

}























