#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_

#include "stdio.h"
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "hardware/pwm.h"
#include "hardware/dma.h"

#define SPI_PORT spi1
#define I2C_PORT i2c1

#define LCD_DC_PIN 8
#define LCD_CS_PIN 9
#define LCD_CLK_PIN 10
#define LCD_MOSI_PIN 11
#define LCD_RST_PIN 12
#define LCD_BL_PIN 25

#define DEV_SDA_PIN     (6)
#define DEV_SCL_PIN     (7)

#define BAT_ADC_PIN     (29)
#define BAR_CHANNEL     (3)


void dev_gpio_mode(uint16_t Pin, uint16_t Mode);
uint8_t dev_module_init(void);

#endif
