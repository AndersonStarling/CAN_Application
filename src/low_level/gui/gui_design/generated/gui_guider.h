/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *speed;
	bool speed_del;
	lv_obj_t *speed_btn_next;
	lv_obj_t *speed_btn_next_label;
	lv_obj_t *speed_cont_box;
	lv_obj_t *speed_meter_board;
	lv_meter_scale_t *speed_meter_board_scale_0;
	lv_meter_indicator_t *speed_meter_board_scale_0_ndline_0;
	lv_meter_indicator_t *speed_meter_board_scale_0_arc_0;
	lv_meter_indicator_t *speed_meter_board_scale_0_arc_1;
	lv_meter_indicator_t *speed_meter_board_scale_0_arc_2;
	lv_obj_t *speed_img_logo;
	lv_obj_t *speed_label_title;
	lv_obj_t *speed_label_speed_unit;
	lv_obj_t *speed_label_digit;
	lv_obj_t *record;
	bool record_del;
	lv_obj_t *record_chart_board;
	lv_chart_series_t *record_chart_board_0;
	lv_obj_t *record_label_title;
	lv_obj_t *record_btn_before;
	lv_obj_t *record_btn_before_label;
	lv_obj_t *record_img_logo;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_speed(lv_ui *ui);
void setup_scr_record(lv_ui *ui);
LV_IMG_DECLARE(_NXP_Logo_60x29);
LV_IMG_DECLARE(_NXP_Logo_60x29);

LV_FONT_DECLARE(lv_font_arial_22)
LV_FONT_DECLARE(lv_font_arial_18)
LV_FONT_DECLARE(lv_font_arial_13)
LV_FONT_DECLARE(lv_font_arial_15)
LV_FONT_DECLARE(lv_font_arial_11)
LV_FONT_DECLARE(lv_font_arial_14)
LV_FONT_DECLARE(lv_font_arial_12)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_11)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_12)
LV_FONT_DECLARE(lv_font_arial_30)
LV_FONT_DECLARE(lv_font_ArchitectsDaughter_13)


#ifdef __cplusplus
}
#endif
#endif
