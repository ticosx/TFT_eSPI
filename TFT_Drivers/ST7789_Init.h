
// This is the command sequence that initialises the ST7789 driver
//
// This setup information uses simple 8 bit SPI writecommand() and writedata() functions
//
// See ST7735_Setup.h file for an alternative format

{
#if 1
delay(120);                //delay 120ms
writecommand(0x11);     
delay(120);                //delay 120ms
writecommand(0x36);     
writedata( 0x00);   
writecommand(0x3A);     
writedata( 0x55);
writecommand(0xB0);
writedata(0x00);
writedata(0xE8);
writecommand(0xB2);     
writedata( 0x0C);   
writedata( 0x0C);   
writedata( 0x00);   
writedata( 0x33);   
writedata( 0x33);   
writecommand(0xB7);     
writedata( 0x75);   
writecommand(0xBB);     
writedata( 0x13);   
writecommand(0xC0);     
writedata( 0x2C);   
writecommand(0xC2);     
writedata( 0x01);   
writecommand(0xC3);     
writedata( 0x13);    
writecommand(0xC4);     
writedata( 0x20);   
writecommand(0xC6);     
writedata( 0x0F);   
writecommand(0xD0);     
writedata( 0xA4);   
writedata( 0xA1);   
writecommand(0xD6);     
writedata( 0xA1);
writecommand(0x21);     
writecommand(0xE0);
writedata( 0xD0);
writedata( 0x08);
writedata( 0x10);
writedata( 0x0D);
writedata( 0x0C);
writedata( 0x07);
writedata( 0x37);
writedata( 0x53);
writedata( 0x4C);
writedata( 0x39);
writedata( 0x15);
writedata( 0x15);
writedata( 0x2A);
writedata( 0x2D);
writecommand(0xE1);
writedata( 0xD0);
writedata( 0x0D);
writedata( 0x12);
writedata( 0x08);
writedata( 0x08);
writedata( 0x15);
writedata( 0x34);
writedata( 0x34);
writedata( 0x4A);
writedata( 0x36);
writedata( 0x12);
writedata( 0x13);
writedata( 0x2B);
writedata( 0x2F);   
writecommand(0x29);  

#else
  writecommand(ST7789_SLPOUT);   // Sleep out
  delay(120);

  writecommand(ST7789_NORON);    // Normal display mode on

  //------------------------------display and color format setting--------------------------------//
  writecommand(ST7789_MADCTL);
  //writedata(0x00);
  writedata(TFT_MAD_COLOR_ORDER);

  // JLX240 display datasheet
  writecommand(0xB6);
  writedata(0x0A);
  writedata(0x82);

  writecommand(ST7789_RAMCTRL);
  writedata(0x00);
  writedata(0xE0); // 5 to 6 bit conversion: r0 = r5, b0 = b5

  writecommand(ST7789_COLMOD);
  writedata(0x55);
  delay(10);

  //--------------------------------ST7789V Frame rate setting----------------------------------//
  writecommand(ST7789_PORCTRL);
  writedata(0x0c);
  writedata(0x0c);
  writedata(0x00);
  writedata(0x33);
  writedata(0x33);

  writecommand(ST7789_GCTRL);      // Voltages: VGH / VGL
  writedata(0x35);

  //---------------------------------ST7789V Power setting--------------------------------------//
  writecommand(ST7789_VCOMS);
  writedata(0x28);		// JLX240 display datasheet

  writecommand(ST7789_LCMCTRL);
  writedata(0x0C);

  writecommand(ST7789_VDVVRHEN);
  writedata(0x01);
  writedata(0xFF);

  writecommand(ST7789_VRHS);       // voltage VRHS
  writedata(0x10);

  writecommand(ST7789_VDVSET);
  writedata(0x20);

  writecommand(ST7789_FRCTR2);
  writedata(0x0f);

  writecommand(ST7789_PWCTRL1);
  writedata(0xa4);
  writedata(0xa1);

  //--------------------------------ST7789V gamma setting---------------------------------------//
  writecommand(ST7789_PVGAMCTRL);
  writedata(0xd0);
  writedata(0x00);
  writedata(0x02);
  writedata(0x07);
  writedata(0x0a);
  writedata(0x28);
  writedata(0x32);
  writedata(0x44);
  writedata(0x42);
  writedata(0x06);
  writedata(0x0e);
  writedata(0x12);
  writedata(0x14);
  writedata(0x17);

  writecommand(ST7789_NVGAMCTRL);
  writedata(0xd0);
  writedata(0x00);
  writedata(0x02);
  writedata(0x07);
  writedata(0x0a);
  writedata(0x28);
  writedata(0x31);
  writedata(0x54);
  writedata(0x47);
  writedata(0x0e);
  writedata(0x1c);
  writedata(0x17);
  writedata(0x1b);
  writedata(0x1e);

  writecommand(ST7789_INVON);

  writecommand(ST7789_CASET);    // Column address set
  writedata(0x00);
  writedata(0x00);
  writedata(0x00);
  writedata(0xE5);    // 239

  writecommand(ST7789_RASET);    // Row address set
  writedata(0x00);
  writedata(0x00);
  writedata(0x01);
  writedata(0x3F);    // 319

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  end_tft_write();
  delay(120);
  begin_tft_write();

  writecommand(ST7789_DISPON);    //Display on
  delay(120);
#endif
#ifdef TFT_BL
  // Turn on the back-light LED
  digitalWrite(TFT_BL, HIGH);
  pinMode(TFT_BL, OUTPUT);
#endif
}
