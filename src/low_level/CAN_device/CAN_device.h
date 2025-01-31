#ifndef CAN_DEVICE_H
#define CAN_DEVICE_H

typedef struct
{
    uint8_t * data;
    uint32_t data_size;
} CAN_data_struct_t;

int CAN_device_init(void);

int CAN_device_add_recv_data_cb(CAN_data_struct_t * recv_data_cb);

#endif /* CAN_DEVICE_H */




