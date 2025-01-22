#include <stdint.h>
#include "receive_process.h"
#include "recv_data.h"

uint8_t received_data[100] = {0};


void receive_process_init(void)
{
    recv_data_init(&received_data[0], sizeof(received_data));
}



