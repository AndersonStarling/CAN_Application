"""
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
"""

is_increse = 1
is_up = 1
speedNum = 0
spd_chart = []
for i in range(100):
    spd_chart.append(0)

def screen_meter_timer_cb():
    global speedNum
    global is_increse
    if speedNum >= 110:
        is_increse = 0
    if speedNum <= 70:
        is_increse = 1
    speed_meter_board.set_indicator_value(speed_meter_board_scale_0_ndline_0, speedNum)
    speed_label_digit.set_text(str(speedNum))
    if is_increse == 1:
        speedNum += 1
    else:
        speedNum -= 1

def screen_1_chart_timer_cb():
    ser_y_array = lv.chart.get_y_array(record_chart_board, record_chart_board_series_0)
    global spd_chart
    global is_up
    for i in range(99):
        spd_chart[i] = spd_chart[i+1]
        ser_y_array[i] = spd_chart[i]
    
    if spd_chart[99] > 110:
        is_up = 0
    if spd_chart[99] < 70:
        is_up = 1
    
    if is_up == 1:
        spd_chart[99] += lv.rand(0, 5)
    else:
        spd_chart[99] -= lv.rand(0, 5)
        
    ser_y_array[99] = spd_chart[99]
    lv.chart.refresh(record_chart_board)
