#include <stdint.h>
#include "receive_process.h"
#include "gui_process.h"

int main(void)
{
    /* init receive thread */
    receive_process_init();

    /* init gui thread */
    gui_process_init();

    /* start receive thread */
    receive_process_start();

    /* start gui thread */
    gui_process_start();
    
}






