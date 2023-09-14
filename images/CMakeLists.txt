add_library(images images.c images.h image_data.h)

target_include_directories(images PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(images pico_stdlib hardware_flash)
