cmake_minimum_required(VERSION 3.5)

project(list)

# include_directories(Inc)

set(SOURCE_FILES
    # list_example.cpp
    vector_example.cpp
)

add_executable(list ${SOURCE_FILES})

install(TARGETS list RUNTIME DESTINATION bin)
