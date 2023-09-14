#include "images.h"
#include "image_data.h"
#include "hardware/flash.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int num_labels = 1923;

image_t* load_image_t(int num_images)
{   
    // Allocate a single block of memory for all images
    image_t* images = malloc(sizeof(image_t) * num_images);
    if (!images)    {
        printf("Error, could not allocate memory for images!\n");
        return NULL;
    }

    const unsigned char* currentPtr = rawData;
    for (int image_counter = 0; image_counter < num_images; image_counter++)
    {
        int label_index = get_label_index(currentPtr - rawData);
        if (!convert_raw_to_image_t(&images[image_counter], currentPtr, label_index)) {
            free(images);
            return NULL;
        }

        currentPtr += (COMPRESSED_IMAGE_SIZE + COLOUR_TABLE_SIZE);
    }

    return images;
}

static int convert_raw_to_image_t(image_t* image, const uint8_t *raw_buffer, int label_index)
{
    if (!raw_buffer) 
    {
        printf("Error in converting to image type, invalid pointer to raw data buffer.\n");
        return 0;
    }

    if (label_index > num_labels || label_index < 0) 
    {
        printf("Error in converting to image type, invalid label index\n");
        return 0; 
    }

    image->colour_table = raw_buffer;
    image->pixel_buffer = raw_buffer + COLOUR_TABLE_SIZE;
    image->label = labels[label_index];

    return 1; 
}

static inline int get_label_index(int image_byte_offset)
{   
    return image_byte_offset / (COMPRESSED_IMAGE_SIZE + COLOUR_TABLE_SIZE);
}
