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



void setup_scr_speed(lv_ui *ui)
{
    //Write codes speed
    ui->speed = lv_obj_create(NULL);
    lv_obj_set_size(ui->speed, 480, 272);
    lv_obj_set_scrollbar_mode(ui->speed, LV_SCROLLBAR_MODE_OFF);

    //Write style for speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->speed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->speed, lv_color_hex(0x364498), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->speed, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->speed, lv_color_hex(0x0d2c73), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->speed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes speed_btn_next
    ui->speed_btn_next = lv_btn_create(ui->speed);
    ui->speed_btn_next_label = lv_label_create(ui->speed_btn_next);
    lv_label_set_text(ui->speed_btn_next_label, ">");
    lv_label_set_long_mode(ui->speed_btn_next_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->speed_btn_next_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->speed_btn_next, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->speed_btn_next_label, LV_PCT(100));
    lv_obj_set_pos(ui->speed_btn_next, 374, 110);
    lv_obj_set_size(ui->speed_btn_next, 52, 52);

    //Write style for speed_btn_next, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->speed_btn_next, 239, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->speed_btn_next, lv_color_hex(0x0043a1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->speed_btn_next, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->speed_btn_next, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->speed_btn_next, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->speed_btn_next, lv_color_hex(0x002b70), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->speed_btn_next, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->speed_btn_next, 26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->speed_btn_next, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->speed_btn_next, lv_color_hex(0xa3ddff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->speed_btn_next, &lv_font_arial_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->speed_btn_next, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->speed_btn_next, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes speed_cont_box
    ui->speed_cont_box = lv_obj_create(ui->speed);
    lv_obj_set_pos(ui->speed_cont_box, 0, 0);
    lv_obj_set_size(ui->speed_cont_box, 356, 271);
    lv_obj_set_scrollbar_mode(ui->speed_cont_box, LV_SCROLLBAR_MODE_OFF);

    //Write style for speed_cont_box, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->speed_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->speed_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->speed_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->speed_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->speed_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->speed_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->speed_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->speed_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes speed_meter_board
    ui->speed_meter_board = lv_meter_create(ui->speed_cont_box);
    // add scale ui->speed_meter_board_scale_0
    ui->speed_meter_board_scale_0 = lv_meter_add_scale(ui->speed_meter_board);
    lv_meter_set_scale_ticks(ui->speed_meter_board, ui->speed_meter_board_scale_0, 61, 2, 10, lv_color_hex(0x4a69ff));
    lv_meter_set_scale_major_ticks(ui->speed_meter_board, ui->speed_meter_board_scale_0, 5, 4, 16, lv_color_hex(0xffffff), 15);
    lv_meter_set_scale_range(ui->speed_meter_board, ui->speed_meter_board_scale_0, 0, 120, 300, 120);

    // add arc for ui->speed_meter_board_scale_0
    ui->speed_meter_board_scale_0_arc_0 = lv_meter_add_arc(ui->speed_meter_board, ui->speed_meter_board_scale_0, 10, lv_color_hex(0x00d6c2), 0);
    lv_meter_set_indicator_start_value(ui->speed_meter_board, ui->speed_meter_board_scale_0_arc_0, 0);
    lv_meter_set_indicator_end_value(ui->speed_meter_board, ui->speed_meter_board_scale_0_arc_0, 50);

    // add arc for ui->speed_meter_board_scale_0
    ui->speed_meter_board_scale_0_arc_1 = lv_meter_add_arc(ui->speed_meter_board, ui->speed_meter_board_scale_0, 10, lv_color_hex(0x950080), 0);
    lv_meter_set_indicator_start_value(ui->speed_meter_board, ui->speed_meter_board_scale_0_arc_1, 80);
    lv_meter_set_indicator_end_value(ui->speed_meter_board, ui->speed_meter_board_scale_0_arc_1, 120);

    // add arc for ui->speed_meter_board_scale_0
    ui->speed_meter_board_scale_0_arc_2 = lv_meter_add_arc(ui->speed_meter_board, ui->speed_meter_board_scale_0, 10, lv_color_hex(0xb3dc00), 0);
    lv_meter_set_indicator_start_value(ui->speed_meter_board, ui->speed_meter_board_scale_0_arc_2, 50);
    lv_meter_set_indicator_end_value(ui->speed_meter_board, ui->speed_meter_board_scale_0_arc_2, 80);

    // add needle line for ui->speed_meter_board_scale_0.
    ui->speed_meter_board_scale_0_ndline_0 = lv_meter_add_needle_line(ui->speed_meter_board, ui->speed_meter_board_scale_0, 4, lv_color_hex(0xf7f8ff), -12);
    lv_meter_set_indicator_value(ui->speed_meter_board, ui->speed_meter_board_scale_0_ndline_0, 5);
    lv_obj_set_pos(ui->speed_meter_board, 29, 11);
    lv_obj_set_size(ui->speed_meter_board, 250, 250);

    //Write style for speed_meter_board, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->speed_meter_board, 251, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->speed_meter_board, lv_color_hex(0x142c58), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->speed_meter_board, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->speed_meter_board, 125, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->speed_meter_board, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->speed_meter_board, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->speed_meter_board, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->speed_meter_board, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->speed_meter_board, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->speed_meter_board, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for speed_meter_board, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->speed_meter_board, lv_color_hex(0xffffff), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->speed_meter_board, &lv_font_arial_15, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->speed_meter_board, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write style for speed_meter_board, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->speed_meter_board, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->speed_meter_board, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->speed_meter_board, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes speed_img_logo
    ui->speed_img_logo = lv_img_create(ui->speed_cont_box);
    lv_obj_add_flag(ui->speed_img_logo, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->speed_img_logo, &_NXP_Logo_60x29);
    lv_img_set_pivot(ui->speed_img_logo, 50,50);
    lv_img_set_angle(ui->speed_img_logo, 0);
    lv_obj_set_pos(ui->speed_img_logo, 126, 88);
    lv_obj_set_size(ui->speed_img_logo, 60, 29);

    //Write style for speed_img_logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->speed_img_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->speed_img_logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->speed_img_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->speed_img_logo, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes speed_label_title
    ui->speed_label_title = lv_label_create(ui->speed_cont_box);
    lv_label_set_text(ui->speed_label_title, "Speed");
    lv_label_set_long_mode(ui->speed_label_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->speed_label_title, 113, 163);
    lv_obj_set_size(ui->speed_label_title, 82, 21);

    //Write style for speed_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->speed_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->speed_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->speed_label_title, lv_color_hex(0xe4eeff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->speed_label_title, &lv_font_arial_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->speed_label_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->speed_label_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->speed_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->speed_label_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->speed_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->speed_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->speed_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->speed_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->speed_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->speed_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes speed_label_speed_unit
    ui->speed_label_speed_unit = lv_label_create(ui->speed_cont_box);
    lv_label_set_text(ui->speed_label_speed_unit, "Km/h");
    lv_label_set_long_mode(ui->speed_label_speed_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->speed_label_speed_unit, 124, 218);
    lv_obj_set_size(ui->speed_label_speed_unit, 54, 29);

    //Write style for speed_label_speed_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->speed_label_speed_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->speed_label_speed_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->speed_label_speed_unit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->speed_label_speed_unit, &lv_font_arial_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->speed_label_speed_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->speed_label_speed_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->speed_label_speed_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->speed_label_speed_unit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->speed_label_speed_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->speed_label_speed_unit, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->speed_label_speed_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->speed_label_speed_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->speed_label_speed_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->speed_label_speed_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes speed_label_digit
    ui->speed_label_digit = lv_label_create(ui->speed_cont_box);
    lv_label_set_text(ui->speed_label_digit, "0");
    lv_label_set_long_mode(ui->speed_label_digit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->speed_label_digit, 122, 197);
    lv_obj_set_size(ui->speed_label_digit, 54, 29);

    //Write style for speed_label_digit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->speed_label_digit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->speed_label_digit, &lv_font_arial_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->speed_label_digit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->speed_label_digit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->speed_label_digit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->speed_label_digit, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of speed.


    //Update current screen layout.
    lv_obj_update_layout(ui->speed);

    //Init events for screen.
    events_init_speed(ui);
}
