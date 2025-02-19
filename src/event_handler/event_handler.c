#include <stdint.h>
#include <zephyr/kernel.h>
#include "event_handler.h"

static struct k_event global_event;

void event_init_global(void) 
{
    k_event_init(&global_event);
}

void event_set_global(uint32_t events) 
{
    k_event_set(&global_event, events);
}

uint32_t event_wait_global(uint32_t events, k_timeout_t timeout) 
{
    return k_event_wait(&global_event, events, false, timeout);
}

void event_clear_global(uint32_t events) 
{
    k_event_clear(&global_event, events);
}


