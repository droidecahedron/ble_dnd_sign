#
# Copyright (c) 2018 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#
cmake_minimum_required(VERSION 3.20.0)

set(SHIELD adafruit_2_8_tft_touch_v2)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(ble_dnd_sign)

# NORDIC SDK APP START
target_sources(app PRIVATE
  src/main.c
  src/display/display.c
  src/display/logo.c
)

# NORDIC SDK APP END
zephyr_library_include_directories(.)
