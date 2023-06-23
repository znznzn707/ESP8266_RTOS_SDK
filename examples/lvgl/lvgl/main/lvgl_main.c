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

#include "lvgl.h"
#include "lv_conf.h"
#include "lv_port_disp.h"

#include "st7789.h"
#include "lcd_init.h"

void lv_demo_task(void *pvParameters)
{
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_obj_set_style_bg_opa(lv_scr_act(), LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0x000000), 0); //0x000000 = 黑色
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL);                //滚动模式
    lv_label_set_recolor(label, true);                                  //使能颜色修改
    lv_obj_set_pos(label, 10, 50);                                      //文本位置
    lv_obj_set_size(label, 240, 60);                                    //标签框大小
    LV_FONT_DECLARE(lv_font_montserrat_16)                              //设置字体
    lv_label_set_text(label, "#ff0080 abcde##00ff80 12345#");           //字体颜色
    lv_obj_set_style_text_font(label, &lv_font_montserrat_16, 0);
}


void app_main()
{
    printf("Hello world!\n");

    LCD_Init();
    lv_init();
    lv_port_disp_init();

    lv_demo_task(NULL);

    while (1)
    {
        lv_tick_inc(5);
        lv_task_handler(); /* LVGL 计时器 */
        vTaskDelay(5 / portTICK_PERIOD_MS);
    }
}
