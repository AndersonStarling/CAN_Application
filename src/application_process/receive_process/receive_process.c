#include <stdint.h>
#include <zephyr/kernel.h>
#include "receive_process.h"
#include "recv_data.h"
#include "event_handler.h"

#define RECEIVE_THREAD_STACK    2048
#define RECEIVE_THREAD_PRIORITY 8

#define RECEIVE_PROCESS_EVENT_LOADING 0x01u

/* 1 can frame have 8 byte data */
static uint8_t received_data[8] = {0};

extern void receive_thread(void *, void *, void *);

static void receive_process_handle_data(void);

K_THREAD_STACK_DEFINE(receive_thread_stack_size, RECEIVE_THREAD_STACK);
struct k_thread receive_thread_data;
static k_tid_t thread_id;

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
        receive_process_handle_data();
        /* sleep in ms */
        k_msleep(100);
    }
}

static void receive_process_handle_data(void)
{
    event_set_global(received_data[0]);
}







