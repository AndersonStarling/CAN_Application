# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(can_project)

# include header file
include_directories(
        "${CMAKE_CURRENT_LIST_DIR}/include"
        "${CMAKE_CURRENT_LIST_DIR}/src"
        "${CMAKE_CURRENT_LIST_DIR}/src/application_process/receive_process"
        "${CMAKE_CURRENT_LIST_DIR}/src/application_process/gui_process"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/CAN_device"
        "${CMAKE_CURRENT_LIST_DIR}/src/received_data"
)

# src file
file(GLOB SRC_FILE
        "${CMAKE_CURRENT_LIST_DIR}/src/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/application_process/receive_process/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/application_process/gui_process/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/low_level/CAN_device/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/received_data/*.c"
        )

target_sources(app PRIVATE ${SRC_FILE})




