#ifndef LOAD_DATA_H
#define LOAD_DATA_H

#include "pico/stdlib.h"

#define IMAGE_PIXELS_COUNT 1600
#define COLOUR_TABLE_SIZE 64
#define COMPRESSED_IMAGE_SIZE IMAGE_PIXELS_COUNT/2
#define MAX_LABEL_SIZE 25
#define MAX_NUM_IMAGES 1923

extern const int num_labels;

typedef struct {
    const uint8_t *pixel_buffer;
    const uint8_t *colour_table;
    const char *label;
} image_t;

//Returns an array of image_t struct pointers of the first count images in flash memory
image_t* load_image_t(int count);

static int convert_raw_to_image_t(image_t* image, const uint8_t *raw_buffer, int label_index);
static inline int get_label_index(int image_byte_offset);

#endif