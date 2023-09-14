cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(pico_ml C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_ML_PATH ${PROJECT_SOURCE_DIR})

pico_sdk_init()

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        )
if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wno-maybe-uninitialized)
endif()

add_subdirectory(images)

add_executable(pico_ml pico_ml.c)

target_link_libraries(pico_ml images)

pico_add_extra_outputs(pico_ml)