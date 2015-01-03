int16_t flexFontX;
int16_t flexFontY;
uint16_t flexFontColor;

void flexFontDrawChar(Adafruit_GFX* gfx, unsigned char c, prog_uchar* font, prog_uchar* fontWidth, prog_uint16_t* fontOffset, byte fontHeight, char fontStartChar)
{
  // Space is a special case
  if (c == ' ')
  {
    flexFontX += fontHeight / 2;
    return;
  }
  
  // The width of the character (support characters up to 255 wide)
  byte width = pgm_read_byte(fontWidth + c - fontStartChar);

  // Get the program memory offset for the character in the font data
  prog_uchar* offset = font + pgm_read_word(fontOffset + c - fontStartChar);
  
  // Output each column (characters are stored as one byte per column, so a maximum height of 8 pixels)
  for (byte colIndex = 0; colIndex < width; colIndex ++)
  {
    byte colData = pgm_read_byte(offset + colIndex);
    
    // Output a pixel for each row in the current column.
    for (byte rowIndex = 0; rowIndex < fontHeight; rowIndex ++)
    {
      if (colData & 0x01) {
        gfx->drawPixel(flexFontX + colIndex, flexFontY + rowIndex, flexFontColor);
      }
      
      colData >>= 1;
    }
  }
  flexFontX += width + 1;
}

void flexFontSetPos(int16_t x, int16_t y)
{
  flexFontX = x;
  flexFontY = y;
}

void flexFontColour(int16_t colour)
{
  flexFontColor = colour;
}

void flexFontDrawString(Adafruit_GFX* gfx, String s, prog_uchar* font, prog_uchar* fontWidth, prog_uint16_t* fontOffset, byte fontHeight, char fontStartChar)
{ 
  for (int i = 0; i < s.length(); i ++)
  {
    flexFontDrawChar(gfx, s.charAt(i), font, fontWidth, fontOffset, fontHeight, fontStartChar);
  }
}
