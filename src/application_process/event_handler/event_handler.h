#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

void event_init_global(void);
void event_set_global(uint32_t events);
uint32_t event_wait_global(uint32_t events, k_timeout_t timeout);
void event_clear_global(uint32_t events);

#endif /* EVENT_HANDLER_H */