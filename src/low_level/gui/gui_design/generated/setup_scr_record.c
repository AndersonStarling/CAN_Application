/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_record(lv_ui *ui)
{
    //Write codes record
    ui->record = lv_obj_create(NULL);
    lv_obj_set_size(ui->record, 480, 272);
    lv_obj_set_scrollbar_mode(ui->record, LV_SCROLLBAR_MODE_OFF);

    //Write style for record, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->record, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->record, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->record, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->record, lv_color_hex(0x05379c), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->record, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->record, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes record_chart_board
    ui->record_chart_board = lv_chart_create(ui->record);
    lv_chart_set_type(ui->record_chart_board, LV_CHART_TYPE_LINE);
    lv_chart_set_div_line_count(ui->record_chart_board, 5, 6);
    lv_chart_set_point_count(ui->record_chart_board, 100);
    lv_chart_set_range(ui->record_chart_board, LV_CHART_AXIS_PRIMARY_Y, 0, 120);
    lv_chart_set_range(ui->record_chart_board, LV_CHART_AXIS_SECONDARY_Y, 0, 100);
    lv_chart_set_zoom_x(ui->record_chart_board, 256);
    lv_chart_set_zoom_y(ui->record_chart_board, 256);
    ui->record_chart_board_0 = lv_chart_add_series(ui->record_chart_board, lv_color_hex(0xd0ff00), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
    lv_chart_set_next_value(ui->record_chart_board, ui->record_chart_board_0, 0);
#endif
    lv_obj_set_pos(ui->record_chart_board, 99, 47);
    lv_obj_set_size(ui->record_chart_board, 366, 197);
    lv_obj_set_scrollbar_mode(ui->record_chart_board, LV_SCROLLBAR_MODE_OFF);

    //Write style for record_chart_board, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->record_chart_board, 223, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->record_chart_board, lv_color_hex(0x00cbff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->record_chart_board, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->record_chart_board, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->record_chart_board, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->record_chart_board, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->record_chart_board, lv_color_hex(0x26cbf6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->record_chart_board, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->record_chart_board, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for record_chart_board, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->record_chart_board, lv_color_hex(0x151212), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->record_chart_board, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->record_chart_board, 255, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->record_chart_board, 2, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->record_chart_board, lv_color_hex(0xe8e8e8), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->record_chart_board, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write codes record_label_title
    ui->record_label_title = lv_label_create(ui->record);
    lv_label_set_text(ui->record_label_title, "Dynamic Chart");
    lv_label_set_long_mode(ui->record_label_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->record_label_title, 278, 27);
    lv_obj_set_size(ui->record_label_title, 200, 16);

    //Write style for record_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->record_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->record_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->record_label_title, lv_color_hex(0xfeffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->record_label_title, &lv_font_arial_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->record_label_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->record_label_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->record_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->record_label_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->record_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->record_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->record_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->record_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->record_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->record_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes record_btn_before
    ui->record_btn_before = lv_btn_create(ui->record);
    ui->record_btn_before_label = lv_label_create(ui->record_btn_before);
    lv_label_set_text(ui->record_btn_before_label, "<");
    lv_label_set_long_mode(ui->record_btn_before_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->record_btn_before_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->record_btn_before, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->record_btn_before_label, LV_PCT(100));
    lv_obj_set_pos(ui->record_btn_before, 19, 123);
    lv_obj_set_size(ui->record_btn_before, 52, 52);

    //Write style for record_btn_before, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->record_btn_before, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->record_btn_before, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->record_btn_before, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->record_btn_before, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->record_btn_before, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->record_btn_before, lv_color_hex(0x52adf8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->record_btn_before, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->record_btn_before, 26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->record_btn_before, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->record_btn_before, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->record_btn_before, &lv_font_arial_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->record_btn_before, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->record_btn_before, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes record_img_logo
    ui->record_img_logo = lv_img_create(ui->record);
    lv_obj_add_flag(ui->record_img_logo, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->record_img_logo, &_NXP_Logo_60x29);
    lv_img_set_pivot(ui->record_img_logo, 50,50);
    lv_img_set_angle(ui->record_img_logo, 0);
    lv_obj_set_pos(ui->record_img_logo, 11, 11);
    lv_obj_set_size(ui->record_img_logo, 60, 29);

    //Write style for record_img_logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->record_img_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->record_img_logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->record_img_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->record_img_logo, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of record.


    //Update current screen layout.
    lv_obj_update_layout(ui->record);

    //Init events for screen.
    events_init_record(ui);
}
