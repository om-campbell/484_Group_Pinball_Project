#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"
#include "image.h"
int ballsInPlay = 0;
int score = 0;
long timer = 0;
int ballsLost = 0;

void setup()
{
  //Play field pins
  pinMode(6,INPUT);//detects ball entering play
  pinMode(5,INPUT);//detects ball exiting play
  pinMode(4,INPUT);//detects 10pt
  pinMode(3,INPUT);//detects 5pt
  pinMode(2,INPUT);//detects 5pt
  Serial.begin(9600);

  Config_Init();
  LCD_Init();
  LCD_Clear(0x0000);
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, BLACK);

  dispStart();

}

  void dispStart(){

    Paint_Clear(BLACK);
    Paint_DrawString_EN(100, 70, "WELCOME", &Font24, BLACK, GREEN);
    Paint_DrawString_EN(135, 100, "TO", &Font24, BLACK, GREEN);
    Paint_DrawString_EN(90, 130, "PINBALL!", &Font24, BLACK, GREEN);

    delay(1000);

    Paint_DrawString_EN(90, 70, "ACTIVATE", &Font24, BLACK, GREEN);
    Paint_DrawString_EN(100, 100, "PLUNGER", &Font24, BLACK, GREEN);
    Paint_DrawString_EN(70, 130, "WHEN READY!", &Font24, BLACK, GREEN);
  
    delay(1000);

  }

void updateNumBalls(){
    Paint_DrawNum(210, 30, ballsInPlay, &Font20, BLACK, GREEN);
}

void updateTimer(){
  if (ballsInPlay > 0 && (30 - timer/1000) > 9){
    Paint_DrawNum(100, 10, 30 - timer/1000, &Font20, BLACK, GREEN);
  } else if (ballsInPlay > 0 && (30 - timer/1000) < 10){
    Paint_DrawNum(100, 10, 30 - timer/1000, &Font20, BLACK, RED);
    Paint_DrawString_EN(110, 10, "  ", &Font20, BLACK, GREEN);
  }
}

void updateScore(){
    Paint_DrawNum(100, 50, score, &Font20, BLACK, GREEN);
}

void resetGame(){
  ballsInPlay = 0;
  timer = 0;
  ballsLost = 0;

  Paint_Clear(BLACK);
  Paint_DrawString_EN(60, 55, "GAME OVER!", &Font24, BLACK, GREEN);
  Paint_DrawString_EN(50, 75, "YOUR SCORE:", &Font24, BLACK, GREEN);
  Paint_DrawNum(235, 80, score, &Font20, BLACK, GREEN);
  delay(3000);
  score = 0;
  dispStart();
  
}

void loop()
{
  // Read gameboard Inputs
  int detectEnteringPlay = digitalRead(6);
  int detectLeavingPlay = digitalRead(5);
  int detectFiveOnLeft = digitalRead(4);
  int detectFiveOnRight = digitalRead(3);

  static unsigned long gameStartTime = 0;
  static unsigned long lastEnterTime = 0; // Last time a ball entered
  static unsigned long lastExitTime = 0; // Last time a ball exited
  unsigned long currentMillis = millis();

  // Check if a new ball enters the play
  if (detectEnteringPlay == HIGH && currentMillis - lastEnterTime > 250){
    lastEnterTime = currentMillis; // Update last enter time
    if (ballsInPlay == 0) { // Reset game if it's the first ball entering
      gameStartTime = currentMillis;
      Paint_Clear(BLACK);
      Paint_DrawRectangle(0, 0, 320, 240, GREEN, DOT_PIXEL_2X2, DRAW_FILL_EMPTY);
      Paint_DrawString_EN(10, 10, "TIMER:", &Font20, BLACK, GREEN);
      // Paint_DrawNum(100, 10, 30 - timer/1000, &Font20, BLACK, GREEN); takes too long to load in accurately
      Paint_DrawString_EN(10, 30, "BALLS IN PLAY:", &Font20, BLACK, GREEN);
      Paint_DrawString_EN(10, 50, "SCORE:", &Font20, BLACK, GREEN);
      Paint_DrawNum(100, 50, score, &Font20, BLACK, GREEN);
    }
    ballsInPlay++;
    updateNumBalls();
  }

  // Only update timer if there are balls in play
  if (ballsInPlay > 0){
    timer = millis() - gameStartTime; // Update timer to the elapsed time since the game started
    updateTimer();
  }

   if (detectLeavingPlay == HIGH && currentMillis - lastExitTime > 250){
    lastExitTime = currentMillis; // Update last exit time
    ballsInPlay--;
    ballsLost++;
    updateNumBalls();
   }

   if (detectFiveOnRight == HIGH || detectFiveOnLeft == HIGH){
    score += 5*ballsInPlay;
    updateScore();
   }

  //End game if 30 seconds have passed
  if (timer > 30000 || ballsLost == 3) {
    resetGame();
  }
}


/*********************************************************************************************************
  END FILE
    
*********************************************************************************************************/

