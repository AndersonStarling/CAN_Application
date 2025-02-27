#include <stdint.h>
#include <zephyr/kernel.h>
#include "gui_process.h"
#include "gui.h"
#include "event_handler.h"

#define GUI_THREAD_STACK    4096
#define GUI_THREAD_PRIORITY 10

extern void gui_thread(void *, void *, void *);

K_THREAD_STACK_DEFINE(gui_thread_stack_size, GUI_THREAD_STACK);
static struct k_thread gui_thread_data;

static k_tid_t thread_id;


void gui_process_init(void)
{
    /* init gui */
    gui_init();

    /* init gui thread */
    thread_id = k_thread_create(&gui_thread_data, gui_thread_stack_size,
                                K_THREAD_STACK_SIZEOF(gui_thread_stack_size),
                                gui_thread,
                                NULL, NULL, NULL,
                                GUI_THREAD_PRIORITY, 0, K_FOREVER);
}

void gui_process_start(void)
{
    k_thread_start(thread_id);
}

void gui_thread(void * param1, void * param2, void * param3)
{
    uint32_t event_recv = 0;

    for(;;)
    {
        /* receive all event then display to LCD */
        event_recv = event_wait_global(0xFFFFFFFF, K_FOREVER);

        gui_update_value(event_recv);

        gui_handler();
        k_msleep(100);
    }
}

