#ifndef eSPIPortConfig_h
#define eSPIPortConfig_h

#include <Arduino.h>

/*!
 * @brief 供 TFT_eSPI 获得 SPI 端口配置信息
 */
int8_t getSpiCs();
int8_t getSpiSclk();
int8_t getSpiMiso();
int8_t getSpiMosi();
int8_t getTftDc();
int8_t getTftRst();


#endif // eSPIPortConfig_h