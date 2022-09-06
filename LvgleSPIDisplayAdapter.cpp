#include "LvgleSPIDisplayAdapter.h"

int8_t LvgleSPIDisplayAdapter::spi_cs = -1;
int8_t LvgleSPIDisplayAdapter::spi_sclk = -1;
int8_t LvgleSPIDisplayAdapter::spi_miso = -1;
int8_t LvgleSPIDisplayAdapter::spi_mosi = -1;
int8_t LvgleSPIDisplayAdapter::tft_dc = -1;
int8_t LvgleSPIDisplayAdapter::tft_rst = -1;
TFT_eSPI* LvgleSPIDisplayAdapter::tft = NULL;
bool LvgleSPIDisplayAdapter::swapBytes = false;

LvgleSPIDisplayAdapter::LvgleSPIDisplayAdapter(int16_t screenWidth, int16_t screenHeight, int8_t bpp, int8_t rotation)
  :LvglDisplayAdapter(screenWidth, screenHeight, bpp, rotation)
{
  if(!tft){
    tft = new TFT_eSPI(screenWidth, screenHeight); /* TFT instance */
    tft->rotation = rotation;
    tft->begin();
  }
  disp_cb = LvgleSPIDisplayAdapter::display;
}

LvgleSPIDisplayAdapter::~LvgleSPIDisplayAdapter(){
  if(tft){
    delete(tft);
    tft = NULL;
  }
}

/**
 * @brief LVGL 显示回调接口，详见：https://docs.lvgl.io/master/porting/display.html#examples
 */
void LvgleSPIDisplayAdapter::display(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );
    
    tft->startWrite();
    tft->setAddrWindow( area->x1, area->y1, w, h );
    tft->pushColors( ( uint16_t * )&color_p->full, w * h, swapBytes );
    tft->endWrite();

    lv_disp_flush_ready( disp );
}

void LvgleSPIDisplayAdapter::configSpiPort(int8_t spi_cs, int8_t spi_sclk, int8_t spi_miso, int8_t spi_mosi,
  int8_t tft_dc, int8_t tft_rst){
  LvgleSPIDisplayAdapter::spi_cs = spi_cs;
  LvgleSPIDisplayAdapter::spi_sclk = spi_sclk;
  LvgleSPIDisplayAdapter::spi_miso = spi_miso;
  LvgleSPIDisplayAdapter::spi_mosi = spi_mosi;
  LvgleSPIDisplayAdapter::tft_dc = tft_dc;
  LvgleSPIDisplayAdapter::tft_rst = tft_rst;
}


/*!
 * @brief 供 TFT_eSPI 获得 SPI 端口配置信息
 */
int8_t getSpiCs() {
  return LvgleSPIDisplayAdapter::getSpiCs();
}

int8_t getSpiSclk() {
  return LvgleSPIDisplayAdapter::getSpiSclk();
}

int8_t getSpiMiso() {
  return LvgleSPIDisplayAdapter::getSpiMiso();
}

int8_t getSpiMosi() {
  return LvgleSPIDisplayAdapter::getSpiMosi();
}

int8_t getTftDc() {
  return LvgleSPIDisplayAdapter::getTftDc();
}

int8_t getTftRst() {
  return LvgleSPIDisplayAdapter::getTftRst();
}

void LvgleSPIDisplayAdapter::setSwapBytes(bool swap){
  swapBytes = swap;
}
