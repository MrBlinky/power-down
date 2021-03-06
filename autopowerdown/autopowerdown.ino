#include <Arduboy2.h>
#include <Sprites.h>
#include "bitmap.h"
#include "src/autopowerdown.h"

Arduboy2 arduboy;

int16_t vortex_x = (WIDTH - vortex_width) / 2;
int16_t vortex_y = (HEIGHT - vortex_height) /2;
uint8_t vortex_frame;         
               
void setup() 
{
  arduboy.begin();
  //arduboy.setFrameRate(60); //Not needed default framerate is 60
}

void loop() 
{
  autoPowerDown(); //test and handle autopower down
  if (!arduboy.nextFrame()) return;
  
  Sprites::draw(vortex_x, vortex_y, vortex_sprite, vortex_frame ++, NULL, 0, SPRITE_IS_MASK);
  vortex_frame %= 15;
  
  arduboy.display(CLEAR_BUFFER);
}
