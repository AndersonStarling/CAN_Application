# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(can_project)

set(LVGL_DIR ${ZEPHYR_LVGL_MODULE_DIR})


target_sources_ifdef(CONFIG_LV_USE_DEMO_MUSIC app PRIVATE
    ${LVGL_DIR}/demos/music/lv_demo_music_list.c
    ${LVGL_DIR}/demos/music/lv_demo_music.c
    ${LVGL_DIR}/demos/music/lv_demo_music_main.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_next.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_wave_top_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_icon_4_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_icon_4.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_corner_right.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_cover_1.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_slider_knob_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_icon_3.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_pause.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_pause_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_wave_bottom_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_icon_2_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_list_play_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_wave_top.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_play_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_cover_1_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_wave_bottom.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_corner_left_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_play.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_list_border.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_icon_2.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_next_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_list_play.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_list_border_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_rnd.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_cover_3.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_prev_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_loop.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_icon_1.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_slider_knob.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_corner_right_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_corner_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_corner_left.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_cover_2_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_icon_3_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_icon_1_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_cover_2.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_prev.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_rnd_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_list_pause_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_cover_3_large.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_list_pause.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_logo.c
    ${LVGL_DIR}/demos/music/assets/img_lv_demo_music_btn_loop_large.c
)

target_sources_ifdef(CONFIG_LV_USE_DEMO_BENCHMARK app PRIVATE
    ${LVGL_DIR}/demos/benchmark/lv_demo_benchmark.c
    ${LVGL_DIR}/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.c
    ${LVGL_DIR}/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.c
    ${LVGL_DIR}/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.c
    ${LVGL_DIR}/demos/benchmark/assets/img_benchmark_cogwheel_argb.c
    ${LVGL_DIR}/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.c
    ${LVGL_DIR}/demos/benchmark/assets/img_benchmark_cogwheel_rgb.c
    ${LVGL_DIR}/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.c
    ${LVGL_DIR}/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.c
    ${LVGL_DIR}/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.c
)

target_sources_ifdef(CONFIG_LV_USE_DEMO_STRESS app PRIVATE
    ${LVGL_DIR}/demos/stress/lv_demo_stress.c
)

target_sources_ifdef(CONFIG_LV_USE_DEMO_WIDGETS app PRIVATE
    ${LVGL_DIR}/demos/widgets/assets/img_clothes.c
    ${LVGL_DIR}/demos/widgets/assets/img_demo_widgets_avatar.c
    ${LVGL_DIR}/demos/widgets/assets/img_lvgl_logo.c
    ${LVGL_DIR}/demos/widgets/lv_demo_widgets.c
)

# include header file
include_directories(
        "${CMAKE_CURRENT_LIST_DIR}/include"
        "${CMAKE_CURRENT_LIST_DIR}/src"
        "${CMAKE_CURRENT_LIST_DIR}/src/application_process/receive_process"
        "${CMAKE_CURRENT_LIST_DIR}/src/application_process/gui_process"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/CAN_device"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/gui"
        "${CMAKE_CURRENT_LIST_DIR}/src/received_data"
        "${LVGL_DIR}/demos/"
        "${LVGL_DIR}/demos/music"
        "${LVGL_DIR}"
        "${LVGL_DIR}/src"
)

# src file
file(GLOB SRC_FILE
        "${CMAKE_CURRENT_LIST_DIR}/src/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/application_process/receive_process/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/application_process/gui_process/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/CAN_device/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/gui/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/received_data/*.c"
        )

target_sources(app PRIVATE ${SRC_FILE})




