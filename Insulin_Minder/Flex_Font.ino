void flexDrawChar(Adafruit_GFX* gfx, int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, prog_uchar* font, prog_uchar* fontWidth, prog_uint16_t* fontOffset, byte fontHeight)
{
  byte width = pgm_read_byte(fontWidth + c);
  prog_uint16_t* offset = fontOffset + pgm_read_word(fontOffset + c);
  for (byte colIndex = 0; colIndex < width; colIndex ++)
  {
    byte colData = pgm_read_byte(offset + colIndex);
    for (byte rowIndex = 0; rowIndex < fontHeight; rowIndex ++)
    {
      if (colData & 0x01) {
        gfx->drawPixel(x + colIndex, y + rowIndex, color);
      }
      
      colData >>= 1;
    }
  }
}
