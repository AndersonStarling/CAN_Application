# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(can_project)

set(LVGL_DIR ${ZEPHYR_LVGL_MODULE_DIR})

target_compile_definitions(app PRIVATE LV_LVGL_H_INCLUDE_SIMPLE=1)
# target_compile_definitions(app PRIVATE CONFIG_LV_USE_DEMO_MUSIC=1)
# target_compile_definitions(app PRIVATE LV_USE_DEMO_MUSIC=1)



# include header file
include_directories(
        "${CMAKE_CURRENT_LIST_DIR}/include"
        "${CMAKE_CURRENT_LIST_DIR}/src"
        "${CMAKE_CURRENT_LIST_DIR}/src/application_process/receive_process"
        "${CMAKE_CURRENT_LIST_DIR}/src/application_process/gui_process"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/CAN_device"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/gui"
        "${CMAKE_CURRENT_LIST_DIR}/src/received_data"
        "${CMAKE_CURRENT_LIST_DIR}/src/application_process/event_handler"
        "${CMAKE_CURRENT_LIST_DIR}/src/test"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/gui/gui_design/custom"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/gui/gui_design/generated"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/gui/gui_design/generated/guider_customer_fonts"
        "${ZEPHYR_LVGL_MODULE_DIR}/lvgl/src"
)

# src file
file(GLOB SRC_FILE
        "${CMAKE_CURRENT_LIST_DIR}/src/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/application_process/receive_process/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/application_process/gui_process/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/CAN_device/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/gui/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/received_data/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/application_process/event_handler/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/test/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/gui/gui_design/custom/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/gui/gui_design/generated/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/gui/gui_design/generated/guider_fonts/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/gui/gui_design/generated/images/*.c"
        )

target_sources(app PRIVATE ${SRC_FILE})

