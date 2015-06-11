#include <SPI.h>
#include <Gamebuino.h>
extern const byte font3x5[];
extern const byte font5x7[];
Gamebuino gb;

// sprites
const byte title[] PROGMEM = {64,30,0x84,0xE0,0x0,0x10,0xA0,0x0,0x42,0x80,0x97,0x1F,0x0,0x10,0x20,0x0,0x40,0x80,0x91,0x50,0x80,0xC,0xC0,0x0,0x33,0x0,0x8C,0x2,0x40,0x8,0x4E,0x7,0x21,0x0,0x40,0x1,0x20,0x9,0x71,0xF8,0xE5,0x0,0x21,0x10,0xA0,0x9,0x15,0xA,0x85,0x0,0x1F,0x1C,0x20,0x8,0xC0,0x60,0x9,0x0,0x0,0xE4,0x20,0x4,0x0,0x0,0x2,0x0,0x0,0x6,0x60,0x2,0x11,0x8,0x84,0x0,0x0,0x8,0x10,0x1,0xF1,0xF8,0xF8,0x0,0x0,0x8,0x50,0x0,0xE,0x7,0x0,0x0,0x0,0x8,0x10,0x0,0x0,0x0,0x0,0x0,0x0,0x6,0x60,0x0,0x0,0x0,0x0,0x0,0xC0,0xE4,0x20,0x0,0x0,0x0,0x0,0x0,0x3F,0x1C,0xA0,0x0,0x0,0x0,0x0,0x0,0xA1,0x50,0xA0,0x0,0x0,0x0,0x0,0x0,0xC,0x1,0x20,0x0,0x7,0x0,0x7,0x0,0x0,0x0,0x40,0x0,0x5,0x0,0x5,0x0,0x21,0x10,0x80,0x0,0x5,0x0,0x7,0xC,0x3F,0x1F,0x0,0x0,0x5,0x0,0x0,0x14,0xC0,0xE0,0x0,0x0,0x7,0x0,0x0,0x14,0x3E,0x1F,0x8E,0xF0,0x77,0x38,0xE7,0x37,0x7E,0x3F,0x4B,0xE8,0xBF,0x28,0xA5,0x3F,0xF0,0x79,0xAE,0x29,0xE7,0x38,0xA5,0x1C,0xE0,0x70,0xAE,0x29,0xC7,0x38,0xA5,0x1C,0xE0,0x70,0xEE,0x39,0xC7,0x38,0xE7,0x1C,0xE0,0x70,0xEE,0x39,0xC7,0x38,0xE7,0x1C,0xF0,0x79,0xEE,0x39,0xC7,0x38,0xE7,0x1C,0x7E,0x3F,0xCE,0x38,0xFF,0x3F,0xE7,0x1F,0x3E,0x1F,0x8E,0x38,0x77,0x1E,0xE7,0xF,};
const byte tile[][10] PROGMEM = {
{8,8,0xE7,0x81,0x81,0x0,0x0,0x81,0x81,0xE7,},
{8,8,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,},   
{8,8,0x0,0x0,0x0,0xFF,0xFF,0x0,0x0,0x0,},          
{8,8,0x0,0x0,0x0,0x1F,0x1F,0x18,0x18,0x18,},      
{8,8,0x0,0x0,0x0,0xF8,0xF8,0x18,0x18,0x18,},      
{8,8,0x18,0x18,0x18,0xF8,0xF8,0x0,0x0,0x0,},      
{8,8,0x18,0x18,0x18,0x1F,0x1F,0x0,0x0,0x0,},     
{8,8,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,},
{8,8,0x0,0x0,0xFF,0x0,0x0,0xFF,0x0,0x0,},
{8,8,0x0,0x0,0x1F,0x30,0x20,0x27,0x24,0x24,},
{8,8,0x0,0x0,0xF8,0xC,0x4,0xE4,0x24,0x24,},
{8,8,0x24,0x24,0xE4,0x4,0xC,0xF8,0x0,0x0,},
{8,8,0x24,0x24,0x27,0x20,0x30,0x1F,0x0,0x0,},
{8,8,0x18,0x18,0x1F,0xF8,0xF8,0x27,0x24,0x24,},
{8,8,0x18,0x18,0xF8,0x1F,0x1F,0xE4,0x24,0x24,},
{8,8,0x24,0x24,0xE4,0x1F,0x1F,0xF8,0x18,0x18,},
{8,8,0x24,0x24,0x27,0xF8,0xF8,0x1F,0x18,0x18,},
{8,8,0x24,0x24,0x24,0xFF,0xFF,0x24,0x24,0x24,},
{8,8,0x18,0x18,0xFF,0x18,0x18,0xFF,0x18,0x18,},
{8,8,0x0,0x18,0xE4,0x2,0x2,0xE4,0x18,0x0,},
{8,8,0x0,0x18,0x27,0x40,0x40,0x27,0x18,0x0,},
{8,8,0x0,0x0,0x18,0x3F,0x3F,0x18,0x0,0x0,},
{8,8,0x0,0x0,0x18,0xFC,0xFC,0x18,0x0,0x0,},
};
//menu
#define MENULENGTH 3
const char strplay[] PROGMEM = "play game";
const char stredit[] PROGMEM = "edit level";
const char strreset[] PROGMEM = "reset stats";
const char* const menu[MENULENGTH] PROGMEM = {
  strplay,
  stredit,
  strreset,
};

const byte u = 1;
const byte d = 2;
const byte l = 3;
const byte r = 4;
// 
/*
  black
  1 vertical
  2 horizontal
  3 down right
  4 down left
  5 up left
  6 up right
  white
  7 vertical
  8 horizontal
  9 down right
  10 down left
  11 up left
  12 up right 
  
  combined white
  13 down right
  14 down left
  15 up left
  16 up right
  17 vertical
  18 horizontal
  
   white ends
   19 left
   20 right
   black ends
   21 left 
   22 right
*/
//map
byte mapdata[][8] ={
  {20,0,0,8,0,3,4,22},
  {0,0,7,0,0,6,2,0},
  {0,7,2,10,0,3,5,0},
  {0,0,3,17,0,0,5,0},
  {21,0,2,7,8,8,0,0},
  {0,5,0,0,8,8,12,19},
};

byte gamestate = 1;
byte selectX = 4;
byte selectY = 3;
unsigned int points = 10000;
int pointgain = 1000;
int pointlose = 5;
int count = 0;
unsigned int moves = 0;
byte grid = 0;
byte brush = 0;
boolean scroll = false;
boolean winstate = false;
void GameDraw(){
  
  for(int x = 0; x < 8; x++){
    for(int y = 0; y < 6; y++){
      if(grid == 1){gb.display.drawPixel( x*8,y*8);}
      else if(grid == 2){gb.display.setColor(GRAY); gb.display.drawFastHLine((x*8)+1, y*8, 6);gb.display.drawFastVLine(x*8, (y*8)+1, 6); gb.display.setColor(BLACK);}
      else if(grid == 3){gb.display.setColor(GRAY); gb.display.drawFastVLine(x*8, y*8, 8);gb.display.drawFastHLine(x*8, y*8, 8); gb.display.setColor(BLACK);}
      else if(grid == 4){gb.display.setColor(GRAY); gb.display.drawPixel( x*8,y*8); gb.display.setColor(BLACK);}
      
      if(mapdata[y][x] > 0){
        gb.display.drawBitmap(x*8,y*8,tile[mapdata[y][x]],NOROT,NOFLIP);
      }
    }
  }
  gb.display.drawBitmap(selectX*8,selectY*8,tile[0],NOROT,NOFLIP);
  
      
}
void StatsDraw(){
  gb.display.cursorX = 64;
  gb.display.cursorY = 43;
  gb.display.setFont(font3x5);
  gb.display.print(points);
  if(winstate){
      gb.display.cursorX = 64;
      gb.display.cursorY = 10;
      gb.display.setFont(font5x7);
      gb.display.print("win");
  }
  if(points < 1){
      gb.display.cursorX = 30;
      gb.display.cursorY = 10;
      gb.display.setFont(font5x7);
      gb.display.print("game over");
  }
   gb.display.cursorX = 64;
      gb.display.cursorY = 20;
      gb.display.setFont(font5x7);
      gb.display.print(moves);
}
void setup(){
  gb.begin();
  gb.titleScreen(F(""),title);
  
  
}
// scaning for conections
boolean scanBlack(byte x, byte y, byte dir){
   count =  count +1;
  if( x > 7 || y > 5) return false;
  if( mapdata[y][x] == 0) return false;
  if( mapdata[y][x] == 21 && dir == l) return true;
  if( mapdata[y][x] == 22 && dir == r) return true;
  
  if( mapdata[y][x] == 1 || mapdata[y][x] == 18){if(dir == u)return scanBlack(x,y-1,u); if(dir == d) return scanBlack(x,y+1,d);}
  if( mapdata[y][x] == 2 || mapdata[y][x] == 17){if(dir == l)return scanBlack(x-1,y,l); if(dir == r) return scanBlack(x+1,y,r);}

  if( mapdata[y][x] == 3 || mapdata[y][x] == 15){if(dir == l)return scanBlack(x,y+1,d); if(dir == u) return scanBlack(x+1,y,r);}
  if( mapdata[y][x] == 4 || mapdata[y][x] == 16){if(dir == r)return scanBlack(x,y+1,d); if(dir == u) return scanBlack(x-1,y,l);}
  if( mapdata[y][x] == 5 || mapdata[y][x] == 13){if(dir == r)return scanBlack(x,y-1,u); if(dir == d) return scanBlack(x-1,y,l);}
  if( mapdata[y][x] == 6 || mapdata[y][x] == 14){if(dir == l)return scanBlack(x,y-1,u); if(dir == d) return scanBlack(x+1,y,r);}
  return false;
}
boolean scanWhite(byte x, byte y, byte dir){
  count =  count +1;
  if( x > 7 || y > 5) return false;
  if( mapdata[y][x] == 0) return false;
  if( mapdata[y][x] == 19 && dir == r) return true;
  if( mapdata[y][x] == 20 && dir == l) return true;
  
  if( mapdata[y][x] == 7 || mapdata[y][x] == 17){if(dir == u)return scanWhite(x,y-1,u); if(dir == d) return scanWhite(x,y+1,d);}
  if( mapdata[y][x] == 8 || mapdata[y][x] == 18){if(dir == l)return scanWhite(x-1,y,l); if(dir == r) return scanWhite(x+1,y,r);}

  if( mapdata[y][x] == 9 || mapdata[y][x] == 13){if(dir == l)return scanWhite(x,y+1,d); if(dir == u) return scanWhite(x+1,y,r);}
  if( mapdata[y][x] == 10 || mapdata[y][x] == 14){if(dir == r)return scanWhite(x,y+1,d); if(dir == u) return scanWhite(x-1,y,l);}
  if( mapdata[y][x] == 11 || mapdata[y][x] == 15){if(dir == r)return scanWhite(x,y-1,u); if(dir == d) return scanWhite(x-1,y,l);}
  if( mapdata[y][x] == 12 || mapdata[y][x] == 16){if(dir == l)return scanWhite(x,y-1,u); if(dir == d) return scanWhite(x+1,y,r);}
  return false;
}
void pathfind(){
  winstate = true;
  count = 0;
  for(int x = 0; x < 8; x++){
    for(int y = 0; y < 6; y++){
      if(mapdata[y][x] > 18){
         if(mapdata[y][x] == 22){if(scanBlack(x-1,y,l)== false){winstate = false;}}
         if(mapdata[y][x] == 21){if(scanBlack(x+1,y,r)== false){winstate = false;}}
         if(mapdata[y][x] == 19){if(scanWhite(x-1,y,l)== false){winstate = false;}}
         if(mapdata[y][x] == 20){if(scanWhite(x+1,y,r)== false){winstate = false;}}
      }
    }
  }
  if(winstate){
    points = points + pointgain + pointlose;
  }
}
//swaping the map data vertical and horizontal to scroll the tiles
void swapLeft(){
  byte hold = mapdata[selectY][1];
  for(int x = 1; x < 6; x++){
    mapdata[selectY][x] = mapdata[selectY][x+1];
  }
  mapdata[selectY][6] = hold;
}
void swapRight(){
  byte hold = mapdata[selectY][6];
  for(int x = 6; x > 1; x--){
    mapdata[selectY][x] = mapdata[selectY][x-1];
  }
  mapdata[selectY][1] = hold;
}
void swapUp(){
  byte hold = mapdata[0][selectX];
  for(int y = 0; y < 5; y++){
    mapdata[y][selectX] = mapdata[y+1][selectX];
  }
  mapdata[5][selectX] = hold;
}
void swapDown(){
  byte hold = mapdata[5][selectX];
  for(int y = 5; y > 0; y--){
    mapdata[y][selectX] = mapdata[y-1][selectX];
  }
  mapdata[0][selectX] = hold;
}
void GameTick(){
    if(gb.buttons.repeat(BTN_RIGHT,5)){
      if(scroll){
        gb.sound.playTick();
        swapRight();
        pathfind();
        points = points - pointlose;
        moves = moves +1;
      }
      else{
        if(selectX < 6){
          selectX = selectX + 1;
        }
      }
    }
    if(gb.buttons.repeat(BTN_LEFT,5)){
      if(scroll){
        gb.sound.playTick();
        swapLeft();
        pathfind();
        points = points - pointlose;
        moves = moves +1;
       }
      else{
        if(selectX > 1){
          selectX = selectX - 1;
        }
       }
    }
    if(gb.buttons.repeat(BTN_DOWN,5)){
      if(scroll){
       gb.sound.playTick();
       swapDown();
       pathfind();
       points = points - pointlose;
       moves = moves +1;
       }
      else{
       if(selectY < 5){
         selectY = selectY + 1;
       }
      }
    }
    if(gb.buttons.repeat(BTN_UP,5)){
      if(scroll){
      gb.sound.playTick();
      swapUp();
      pathfind();
      points = points - pointlose;
      moves = moves +1;
       }
      else{
        if(selectY > 0){
          selectY = selectY - 1;
        }
      }
    }
    
    if(gb.buttons.pressed(BTN_A)){
      //gb.sound.playOK();
      if(winstate){
      }
      else{
        scroll = true;
      }
    }
    if(gb.buttons.released(BTN_A)){
       scroll = false;
    }
    if(gb.buttons.pressed(BTN_B)){
      //gb.sound.playCancel();
      grid = grid +1;
      if(grid > 4)grid = 0;
    }
    if(gb.buttons.pressed(BTN_C)){
      //gb.titleScreen(F("Controls"));
      gamestate = 1;
    }

}
void EditTick(){
  if(gb.buttons.repeat(BTN_RIGHT,5)){
     
        if(selectX < 7){
          selectX = selectX + 1;
        }
      
    }
    if(gb.buttons.repeat(BTN_LEFT,5)){
    
        if(selectX > 0){
          selectX = selectX - 1;
        }
       
    }
    if(gb.buttons.repeat(BTN_DOWN,5)){
     
       if(selectY < 5){
         selectY = selectY + 1;
       }
      
    }
    if(gb.buttons.repeat(BTN_UP,5)){
        if(selectY > 0){
          selectY = selectY - 1;
        }
      
    }
    if(gb.buttons.repeat(BTN_A,10)){
       mapdata[selectY][selectX] = 0;
    }
    if(gb.buttons.pressed(BTN_A)){
       mapdata[selectY][selectX] = brush;
    }
    
    if(gb.buttons.pressed(BTN_B)){
      brush = brush + 1;
      if(brush == 23) brush = 0;
    }
    if(gb.buttons.pressed(BTN_C)){
      gamestate = 1;
    }
     gb.display.drawBitmap(63,10,tile[brush],NOROT,NOFLIP);
}
void loop(){
  if(gb.update()){
    if(gamestate == 1){
      switch(gb.menu(menu, MENULENGTH)){
    case -1: //nothing selected
      //gb.titleScreen(F("Menu example"));
      break;
    case 0: //game
      //displaySystemInfo();
      gamestate = 2;
      break;
    case 1: //level edit
      //gb.changeGame();
      gamestate = 3;
      break;
    case 2: //reset stats
      points = 10000;
      pointgain = 1000;
      pointlose = 5;
      moves = 0;
      //grid = 0;
      brush = 0;
      break;
    default:
      break;
  }
    }
    else if(gamestate == 2){
      GameTick();
      GameDraw();
      StatsDraw();
    }
    else if(gamestate == 3){
      EditTick();
      GameDraw();
    }
    
  }
}

