#include <stdint.h>
#include <zephyr/kernel.h>
#include "receive_process.h"
#include "recv_data.h"

#define RECEIVE_THREAD_STACK    1024
#define RECEIVE_THREAD_PRIORITY 10

uint8_t received_data[100] = {0};

extern void receive_thread(void *, void *, void *);

K_THREAD_STACK_DEFINE(receive_thread_stack_size, RECEIVE_THREAD_PRIORITY);
struct k_thread receive_thread_data;

k_tid_t thread_id;


void receive_process_init(void)
{
    /* init receive buffer */
    recv_data_init(&received_data[0], sizeof(received_data));

    /* init receive thread */
    thread_id = k_thread_create(&receive_thread_data, receive_thread_stack_size,
                                K_THREAD_STACK_SIZEOF(receive_thread_stack_size),
                                receive_thread,
                                NULL, NULL, NULL,
                                RECEIVE_THREAD_PRIORITY, 0, K_FOREVER);
}

void receive_process_start(void)
{
    k_thread_start(thread_id);
}

void receive_thread(void * param1, void * param2, void * param3)
{
    for(;;)
    {
        printf("receive process is running\n");

        /* sleep in ms */
        k_msleep(100);
    }
}







