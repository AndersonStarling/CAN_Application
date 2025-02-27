
#include <zephyr/kernel.h>
#include <zephyr/drivers/display.h>
#include <lvgl.h>
#include <lvgl_mem.h>
#include <stdio.h>
#include "custom.h"

lv_ui guider_ui;

void gui_update_value(int32_t value)
{
	custom_update_speed(value);
}

void gui_handler(void)
{
    uint32_t sleep_ms = lv_task_handler();

	k_msleep(MIN(sleep_ms, INT32_MAX));
}

void gui_init(void)
{
    const struct device *display_dev;

	display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	if (!device_is_ready(display_dev)) {
		printf("Device not ready, aborting test");
	}

	setup_ui(&guider_ui);
	custom_init(&guider_ui);

	lv_task_handler();
	display_blanking_off(display_dev);

}



