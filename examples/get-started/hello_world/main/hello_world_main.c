/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#include "st7789.h"
#include "lcd_init.h"

void app_main()
{
    printf("Hello world!\n");

    LCD_Init();
    LCD_Fill(0, 0, LCD_W, LCD_H, WHITE);
    LCD_DrawRectangle(60, 60, 180, 180, BLUE);

    while (1)
    {
        /* code */
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        printf("Hello world!\n");
    }
}