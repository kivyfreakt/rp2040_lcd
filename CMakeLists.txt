cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)

project(pico_lcd)
pico_sdk_init()

add_subdirectory(./lib/Config)
add_subdirectory(./lib/Fonts)
add_subdirectory(./lib/LCD)
add_subdirectory(./lib/Watchfaces)
# add_subdirectory(./lib/Turtle)
# add_subdirectory(./lib/Demo)

include_directories(./lib/Config)
include_directories(./lib/Fonts)
include_directories(./lib/LCD)
include_directories(./lib/Watchfaces)

# include_directories(./lib/Turtle)
# include_directories(./lib/Demo)

add_executable(main 
main.cpp
)

# enable usb output, disable uart output
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 1)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(main)

target_link_libraries(
main
pico_stdlib 
hardware_spi 
hardware_i2c 
hardware_rtc 
hardware_dma
# Demo
Watchfaces
LCD 
Fonts
Config 
)
