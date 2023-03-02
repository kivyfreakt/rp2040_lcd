#include "lcd.h"
#include "framebuf.h"
#include "DEV_Config.h"

#include <stdlib.h>
#include <stdio.h>

LCD::LCD(uint16_t* canvas): Framebuf(canvas, LCD_HEIGHT, LCD_WIDTH)
{
    this->reset();
    sleep_ms(100);
    this->set_direction(HORIZONTAL);
    this->init_reg();
    this->clear(WHITE);
    this->display();
}

LCD::LCD(uint16_t* canvas, uint8_t direction): Framebuf(canvas, LCD_HEIGHT, LCD_WIDTH)
{
    this->reset();
    sleep_ms(100);
    this->set_direction(direction);
    this->init_reg();
    this->clear(WHITE);
    this->display();
}

void LCD::reset()
{
    DEV_Digital_Write(LCD_RST_PIN, 1);
    DEV_Delay_ms(100);
    DEV_Digital_Write(LCD_RST_PIN, 0);
    DEV_Delay_ms(100);
    DEV_Digital_Write(LCD_RST_PIN, 1);
    DEV_Digital_Write(LCD_CS_PIN, 0);
    DEV_Delay_ms(100);
}

void LCD::command(uint8_t _command)
{
    DEV_Digital_Write(LCD_DC_PIN, 0);
    DEV_SPI_WriteByte(_command);
}

void LCD::data(uint8_t _data)
{
    DEV_Digital_Write(LCD_DC_PIN, 1);
    DEV_SPI_WriteByte(_data);
}

void LCD::set_windows(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
    this->command(0x2A);
    this->data(0x00);
    this->data(x0);
    this->data((x1-1)>>8);
    this->data(x1-1);

    this->command(0x2B);
    this->data(0x00);
    this->data(y0);
    this->data((x1-1)>>8);
    this->data(y1-1);

    this->command(0X2C);
}


void LCD::init_reg()
{
  this->command(0xEF);
    this->command(0xEB);
    this->data(0x14);

  this->command(0xFE);
    this->command(0xEF);

    this->command(0xEB);
    this->data(0x14);

    this->command(0x84);
    this->data(0x40);

    this->command(0x85);
    this->data(0xFF);

    this->command(0x86);
    this->data(0xFF);

    this->command(0x87);
    this->data(0xFF);

    this->command(0x88);
    this->data(0x0A);

    this->command(0x89);
    this->data(0x21);

    this->command(0x8A);
    this->data(0x00);

    this->command(0x8B);
    this->data(0x80);

    this->command(0x8C);
    this->data(0x01);

    this->command(0x8D);
    this->data(0x01);

    this->command(0x8E);
    this->data(0xFF);

    this->command(0x8F);
    this->data(0xFF);


    this->command(0xB6);
    this->data(0x00);
    this->data(0x20);

    this->command(0x36);
    // this->data(0x00); // RGB???
    this->data(0x08);

    this->command(0x3A);
    this->data(0x55);//16bits/pixel
    // this->data(0x05);

    this->command(0x90);
    this->data(0x08);
    this->data(0x08);
    this->data(0x08);
    this->data(0x08);

    this->command(0xBD);
    this->data(0x06);

    this->command(0xBC);
    this->data(0x00);

    this->command(0xFF);
    this->data(0x60);
    this->data(0x01);
    this->data(0x04);

    this->command(0xC3);
    this->data(0x13);
    this->command(0xC4);
    this->data(0x13);

    this->command(0xC9);
    this->data(0x22);

    this->command(0xBE);
    this->data(0x11);

    this->command(0xE1);
    this->data(0x10);
    this->data(0x0E);

    this->command(0xDF);
    this->data(0x21);
    this->data(0x0c);
    this->data(0x02);

    this->command(0xF0);
    this->data(0x45);
    this->data(0x09);
    this->data(0x08);
    this->data(0x08);
    this->data(0x26);
     this->data(0x2A);

     this->command(0xF1);
     this->data(0x43);
     this->data(0x70);
     this->data(0x72);
     this->data(0x36);
     this->data(0x37);
     this->data(0x6F);


     this->command(0xF2);
     this->data(0x45);
     this->data(0x09);
     this->data(0x08);
     this->data(0x08);
     this->data(0x26);
     this->data(0x2A);

     this->command(0xF3);
     this->data(0x43);
     this->data(0x70);
     this->data(0x72);
     this->data(0x36);
     this->data(0x37);
     this->data(0x6F);

    this->command(0xED);
    this->data(0x1B);
    this->data(0x0B);

    this->command(0xAE);
    this->data(0x77);

    this->command(0xCD);
    this->data(0x63);


    this->command(0x70);
    this->data(0x07);
    this->data(0x07);
    this->data(0x04);
    this->data(0x0E);
    this->data(0x0F);
    this->data(0x09);
    this->data(0x07);
    this->data(0x08);
    this->data(0x03);

    this->command(0xE8);
    this->data(0x34);

    this->command(0x62);
    this->data(0x18);
    this->data(0x0D);
    this->data(0x71);
    this->data(0xED);
    this->data(0x70);
    this->data(0x70);
    this->data(0x18);
    this->data(0x0F);
    this->data(0x71);
    this->data(0xEF);
    this->data(0x70);
    this->data(0x70);

    this->command(0x63);
    this->data(0x18);
    this->data(0x11);
    this->data(0x71);
    this->data(0xF1);
    this->data(0x70);
    this->data(0x70);
    this->data(0x18);
    this->data(0x13);
    this->data(0x71);
    this->data(0xF3);
    this->data(0x70);
    this->data(0x70);

    this->command(0x64);
    this->data(0x28);
    this->data(0x29);
    this->data(0xF1);
    this->data(0x01);
    this->data(0xF1);
    this->data(0x00);
    this->data(0x07);

    this->command(0x66);
    this->data(0x3C);
    this->data(0x00);
    this->data(0xCD);
    this->data(0x67);
    this->data(0x45);
    this->data(0x45);
    this->data(0x10);
    this->data(0x00);
    this->data(0x00);
    this->data(0x00);

    this->command(0x67);
    this->data(0x00);
    this->data(0x3C);
    this->data(0x00);
    this->data(0x00);
    this->data(0x00);
    this->data(0x01);
    this->data(0x54);
    this->data(0x10);
    this->data(0x32);
    this->data(0x98);

    this->command(0x74);
    this->data(0x10);
    this->data(0x85);
    this->data(0x80);
    this->data(0x00);
    this->data(0x00);
    this->data(0x4E);
    this->data(0x00);

    this->command(0x98);
    this->data(0x3e);
    this->data(0x07);

    this->command(0x35);
    this->command(0x21);

    this->command(0x11);
    sleep_ms(120);
    this->command(0x29);
    sleep_ms(20);
}


void LCD::set_direction(uint8_t _direction){

    this->direction = _direction;

    uint8_t MemoryAccessReg=0x08;

    switch(_direction){
        case 0: MemoryAccessReg=0x08;break;
        case 1: MemoryAccessReg=0x68;break;
        case 2: MemoryAccessReg=0xc8;break;
        case 3: MemoryAccessReg=0xa8;break;
    }

    this->command(0x36); //MX, MY, RGB mode
    this->data(MemoryAccessReg);	//0x08 set RGB
}


uint8_t LCD::get_direction(){
    return this->direction;
}

void LCD::display()
{    
    this->set_windows(0, 0, LCD_WIDTH, LCD_HEIGHT);

    DEV_Digital_Write(LCD_DC_PIN, 1);

    for (uint16_t j = 0; j < LCD_HEIGHT; j++)
        DEV_SPI_Write_nByte((uint8_t *)&(this->canvas[j*LCD_WIDTH]), LCD_WIDTH*2);
}