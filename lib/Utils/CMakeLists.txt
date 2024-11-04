aux_source_directory(. DIR_UTILS_SRCS)

# include_directories(../Config)
# include_directories(../LCD)

add_library(Utils ${DIR_UTILS_SRCS})
target_link_libraries(Utils PUBLIC)