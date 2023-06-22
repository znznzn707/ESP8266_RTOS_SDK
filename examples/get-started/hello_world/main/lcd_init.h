#ifndef _LCD_INIT_H
#define _LCD_INIT_H

#include <string.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"

#define USE_HORIZONTAL 0  //���ú�������������ʾ 0��1Ϊ���� 2��3Ϊ����


#define LCD_W 240
#define LCD_H 240

//D5 GPIO14
#define LCD_DC              14
//D8 GPIO15
#define LCD_SPI_CLK			15
//D7 GPIO13
#define LCD_SPI_MOSI		13
//D6 GPIO12
#define LCD_RES             12
//D4 GPIO2
// #define LCD_BLK             2

//-----------------LCD�˿ڶ���---------------- 

#define LCD_SCLK_Clr() gpio_set_level(LCD_SPI_CLK, 0) //SCL=SCLK
#define LCD_SCLK_Set() gpio_set_level(LCD_SPI_CLK, 1) 
                       
#define LCD_MOSI_Clr() gpio_set_level(LCD_SPI_MOSI, 0)//SDA=MOSI
#define LCD_MOSI_Set() gpio_set_level(LCD_SPI_MOSI, 1)
                       
#define LCD_RES_Clr()  gpio_set_level(LCD_RES, 0)//RES
#define LCD_RES_Set()  gpio_set_level(LCD_RES, 1)
                       
#define LCD_DC_Clr()   gpio_set_level(LCD_DC, 0)//DC
#define LCD_DC_Set()   gpio_set_level(LCD_DC, 1)

// #define LCD_BLK_Clr()   gpio_set_level(LCD_BLK, 0)//BLK
// #define LCD_BLK_Set()   gpio_set_level(LCD_BLK, 1)
 		                    
// #define LCD_CS_Clr()   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6, GPIO_PIN_RESET)//CS
// #define LCD_CS_Set()   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6, GPIO_PIN_SET)
                       
// #define LCD_BLK_Clr()  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4, GPIO_PIN_RESET)//BLK
// #define LCD_BLK_Set()  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4, GPIO_PIN_SET)


void LCD_GPIO_Init(void);//��ʼ��GPIO
void LCD_Writ_Bus(uint8_t dat);//ģ��SPIʱ��
void LCD_WR_DATA8(uint8_t dat);//д��һ���ֽ�
void LCD_WR_DATA(uint16_t dat);//д�������ֽ�
void LCD_WR_REG(uint8_t dat);//д��һ��ָ��
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);//�������꺯��
void LCD_Init(void);//LCD��ʼ��
#endif




