#include "images/images.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    stdio_init_all();

    printf("Hello World!\n");

    while(1)
    {
        if(!load_image_t(1000)) return -1;

        sleep_ms(1000);
    }

    return 0;
}