aux_source_directory(. DIR_DEMO_SRCS)

include_directories(../Config)
include_directories(../LCD)

add_library(Demo ${DIR_DEMO_SRCS})
target_link_libraries(Demo PUBLIC LCD Config)