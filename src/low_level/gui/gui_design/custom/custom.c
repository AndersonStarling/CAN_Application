/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include "lvgl.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/
#define CHART1_POINTS 100
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static int32_t speed = 0;


static int16_t spd_chart[CHART1_POINTS] = {0};
static bool is_up = true;

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

void custom_update_speed(int32_t speed_value)
{
    speed = speed_value;
}

/**********************
 *  STATIC FUNCTIONS
 **********************/

void speed_meter_timer_cb(lv_timer_t * t)
{
    lv_ui * gui = t->user_data;

    

    lv_meter_set_indicator_value(gui->speed_meter_board, gui->speed_meter_board_scale_0_ndline_0, speed);
    lv_label_set_text_fmt(gui->speed_label_digit, "%"LV_PRId32, speed);

}

void record_chart_timer_cb(lv_timer_t * t)
{
    lv_obj_t * obj = t->user_data;

    lv_chart_series_t * ser = lv_chart_get_series_next(obj, NULL);
    lv_coord_t * ser_array = lv_chart_get_y_array(obj, ser);


    for(int i = 0; i < CHART1_POINTS - 1; i++)
    {
        spd_chart[i] = spd_chart[i+1];
        ser_array[i] = spd_chart[i];
    }

    if(spd_chart[CHART1_POINTS - 1] > 110) is_up = false;
    if(spd_chart[CHART1_POINTS - 1] < 70) is_up = true;

    if(is_up)
    {
        spd_chart[CHART1_POINTS - 1] += lv_rand(0, 5);
    }else
    {
        spd_chart[CHART1_POINTS - 1] -= lv_rand(0, 5);
    }
    ser_array[CHART1_POINTS - 1] = spd_chart[CHART1_POINTS - 1];
    lv_chart_refresh(obj);
}
