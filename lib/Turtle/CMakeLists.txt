aux_source_directory(. DIR_TURTLE_SRCS)

include_directories(../LCD)
include_directories(../Config)

add_library(Turtle ${DIR_TURTLE_SRCS})
target_link_libraries(Turtle PUBLIC LCD Config)