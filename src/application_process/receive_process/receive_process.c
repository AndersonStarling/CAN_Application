#include <stdint.h>
#include <zephyr/kernel.h>
#include "receive_process.h"
#include "recv_data.h"

#define RECEIVE_THREAD_STACK    2048
#define RECEIVE_THREAD_PRIORITY 8

#define RECEIVE_PROCESS_EVENT_LOADING 0x01u

static uint8_t received_data[100] = {0};

extern void receive_thread(void *, void *, void *);

static void receive_process_handle_data(void);

K_THREAD_STACK_DEFINE(receive_thread_stack_size, RECEIVE_THREAD_STACK);
struct k_thread receive_thread_data;
static k_tid_t thread_id;
struct k_event receive_process_event;

k_event receive_process_get_event_handler(void)
{
    return receive_process_event;
}


void receive_process_init(void)
{
    /* init receive buffer */ 
    recv_data_init(&received_data[0], sizeof(received_data));

    k_event_init(&receive_process_event);

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
        /* sleep in ms */
        k_msleep(100);
    }
}

static void receive_process_handle_data(void)
{
    /* handle received data */
    switch(received_data[0])
    {
        case 0:
            /* send event to gui_process to display loading screen */
            k_event_set(&receive_process_event, RECEIVE_PROCESS_EVENT_LOADING);
            break;
        default:
            /* send event to gui_process to display received_data[0] km/h */
            k_event_set(&receive_process_event, received_data[0]);
            break;
    }
}







