
#include <zephyr/kernel.h>
#include <zephyr/drivers/display.h>
#include <lvgl.h>
#include <lvgl_mem.h>
#include <lv_demos.h>
#include <stdio.h>
#include <lv_demo_music.h>

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

#if defined(CONFIG_LV_USE_DEMO_MUSIC)
	lv_demo_music();
#elif defined(CONFIG_LV_USE_DEMO_BENCHMARK)
	lv_demo_benchmark();
#elif defined(CONFIG_LV_USE_DEMO_STRESS)
	lv_demo_stress();
#elif defined(CONFIG_LV_USE_DEMO_WIDGETS)
	lv_demo_widgets();
#else
#error Enable one of the demos CONFIG_LV_USE_DEMO_MUSIC, CONFIG_LV_USE_DEMO_BENCHMARK ,\
	CONFIG_LV_USE_DEMO_STRESS, or CONFIG_LV_USE_DEMO_WIDGETS
#endif

	lv_task_handler();
	display_blanking_off(display_dev);

}



