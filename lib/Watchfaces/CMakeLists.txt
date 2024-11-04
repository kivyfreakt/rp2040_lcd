aux_source_directory(. DIR_LCD_SRCS)

include_directories(../Config)
include_directories(../LCD)

add_library(Watchfaces ${DIR_LCD_SRCS})
target_link_libraries(Watchfaces PUBLIC LCD Config)