aux_source_directory(. DIR_WATCHFACES_SRCS)

include_directories(../Config)
include_directories(../LCD)
include_directories(../Utils)

add_library(Watchfaces ${DIR_WATCHFACES_SRCS})
target_link_libraries(Watchfaces PUBLIC LCD Config Utils)