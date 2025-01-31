#include <stdint.h>
#include "recv_data.h"
#include "CAN_device.h"

static CAN_data_struct_t recv_data;

int recv_data_init(uint8_t * buffer, uint32_t buffer_size)
{
    int ret = 0;

    /* add user buffer */
    recv_data.data      = buffer;
    recv_data.data_size = buffer_size;

    /* init CAN device */
    ret = CAN_device_init();
    if(ret != 0)
    {
        return ret;
    }

    /* add recv data call back */
    ret = CAN_device_add_recv_data_cb(&recv_data);
    if(ret != 0)
    {
        return ret;
    }

    return ret;
}





