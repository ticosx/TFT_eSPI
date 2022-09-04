#ifndef LvgleSPIDisplayAdapter_h
#define LvgleSPIDisplayAdapter_h

#include <Arduino.h>
#include "TFT_eSPI.h"
#include "LvglDisplayAdapter.h"
#include "LvglDefs.h"
#include "eSPIPortConfig.h"

/*!
 * @brief 基于 TFT_eSPI 的 LVGL 显示驱动适配器
 */

class LvgleSPIDisplayAdapter : public LvglDisplayAdapter {
  public:
    LvgleSPIDisplayAdapter(int16_t screenWidth, int16_t screenHeight, int8_t bpp, int8_t rotation=1);
    virtual ~LvgleSPIDisplayAdapter() override;
    using LvglDisplayAdapter::getScreenWidth;
    using LvglDisplayAdapter::getScreenHeight;
    using LvglDisplayAdapter::getColorBit;
    using DisplayAdapter::getRotation;
    //通过以下函数对宏的替换，实现对 TFT_eSPI 中对应 pin 的配置
    static void configSpiPort(int8_t spi_cs, int8_t spi_sclk, int8_t spi_miso, int8_t spi_mosi, int8_t tft_dc, int8_t tft_rst);
    static int8_t getSpiCs(){return spi_cs;}
    static int8_t getSpiSclk(){return spi_sclk;}
    static int8_t getSpiMiso(){return spi_miso;}
    static int8_t getSpiMosi(){return spi_mosi;}
    static int8_t getTftDc(){return tft_dc;}
    static int8_t getTftRst(){return tft_rst;}

  private:
    static TFT_eSPI* tft;
    static int8_t spi_cs;
    static int8_t spi_sclk;
    static int8_t spi_miso;
    static int8_t spi_mosi;
    static int8_t tft_dc;
    static int8_t tft_rst;
    static void display( lv_disp_drv_t *, const lv_area_t *, lv_color_t * );
};

#endif // LvgleSPIDisplayAdapter_h
