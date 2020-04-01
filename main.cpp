// uLCD-144-G2 basic text demo program for uLCD-4GL LCD driver library
//
#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
Serial pc( USBTX, USBRX );
float high = 0, low = 0.001;
int sample = 128;
float data[128];
int Out;
int n = 0;

int main()
{
    // basic printf demo = 16 by 18 characters on screen
    uLCD.printf("\n107000129\n"); //Default Green on black text
    uLCD.text_width(4); //4X size text
    uLCD.text_height(4);
    uLCD.triangle(20, 20, 30, 30, 20, 30, RED);
    uLCD.triangle(21, 20, 30, 20, 30, 29, RED);


    while(1){
        for(float i = 0; i < 1; i += 0.1){
            while(n < 10){
              Out = 1;
              wait(high);
              Out = 0;
              wait(low);
            }
            high += 0.0001;
            low -= 0.0001;
        }
        for(float j = 1; j >= 0; j -= 0.1){
            while(n < 10){
              Out = 1;
              wait(high);
              Out = 0;
              wait(low);
            }
            high -= 0.0001;
            low += 0.0001;
        }
    }
    for (int k = 0; k < sample; k++){
      data[k] = Out;
      wait(0.001/sample);
    }
    for (int m = 0; m < sample; m++){
      pc.printf("%1.3f\r\n", data[m]);
      wait(0.1);
    }
}
