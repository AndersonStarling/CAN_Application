#include <stdint.h>
#include <zephyr/kernel.h>
#include "receive_process.h"
#include "gui_process.h"
#include "test_can.h"
#include "event_handler.h"

int main(void)
{
    /* init receive thread */
    receive_process_init();

    /* init gui thread */
    gui_process_init();

    /* init test can */
    test_can_process_init();

    /* init event */
    event_init_global();

    /* start receive thread */
    receive_process_start();

    /* start gui thread */
    gui_process_start();

    /* start test can */
    test_can_process_start();

    return 0;

}






