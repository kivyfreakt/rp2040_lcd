#include "dev_config.h"

uint slice_num;
int dma_channel;
dma_channel_config cfg;

/**
 * GPIO Mode
 **/
void dev_gpio_mode(uint16_t Pin, uint16_t Mode)
{
    gpio_init(Pin);
    if (Mode == 0 || Mode == GPIO_IN)
    {
        gpio_set_dir(Pin, GPIO_IN);
    }
    else
    {
        gpio_set_dir(Pin, GPIO_OUT);
    }
}

void dev_gpio_init(void)
{
    dev_gpio_mode(LCD_RST_PIN, 1);
    dev_gpio_mode(LCD_DC_PIN, 1);
    dev_gpio_mode(LCD_CS_PIN, 1);
    dev_gpio_mode(LCD_BL_PIN, 1);

    gpio_put(LCD_CS_PIN, 1);
    gpio_put(LCD_DC_PIN, 0);
    gpio_put(LCD_BL_PIN, 1);
}


uint8_t dev_module_init(void)
{
    stdio_init_all();
    // GPIO Config
    dev_gpio_init();

    // ADC
    adc_init();
    adc_gpio_init(BAT_ADC_PIN);
    adc_select_input(BAR_CHANNEL);

    // PWM Config
    gpio_set_function(LCD_BL_PIN, GPIO_FUNC_PWM);
    slice_num = pwm_gpio_to_slice_num(LCD_BL_PIN);
    pwm_set_wrap(slice_num, 100);
    pwm_set_chan_level(slice_num, PWM_CHAN_B, 0);
    pwm_set_clkdiv(slice_num, 50);
    pwm_set_enabled(slice_num, true);

    // SPI Config
    spi_init(SPI_PORT, 40000 * 1000);
    gpio_set_function(LCD_CLK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(LCD_MOSI_PIN, GPIO_FUNC_SPI);

    // I2C Config
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(DEV_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(DEV_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(DEV_SDA_PIN);
    gpio_pull_up(DEV_SCL_PIN);

    // Set lcd backlight
    pwm_set_chan_level(slice_num, PWM_CHAN_B, 69);

    // init dma
    dma_channel = dma_claim_unused_channel(true);
    cfg = dma_channel_get_default_config(dma_channel);
    channel_config_set_transfer_data_size(&cfg, DMA_SIZE_8);
	channel_config_set_dreq(&cfg, spi_get_dreq(SPI_PORT, true));

    printf("DEV_Module_Init OK \r\n");
    return 0;
}
