#include <PS4Controller.h>
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gap_bt_api.h"
#include "esp_err.h"


//motor1 
#define EN1  14
#define M1A  26
#define M1B  27
//motor2 
#define EN2  5
#define M2A  19
#define M2B  18
//motor3 
#define EN3  4
#define M3A  16
#define M3B  17
//motor4 
#define EN4  25
#define M4A  32
#define M4B  33
//motor lift
#define ENL  3
#define MLA  1
#define MLB  23
//motor capit 
#define ENC 15 
#define MCA 12
#define MCB 13


#define PWM_M1A 1 
#define PWM_M1B 2 
#define PWM_M2A 3 
#define PWM_M2B 4 
#define PWM_M3A 5 
#define PWM_M3B 6
#define PWM_M4A 7 
#define PWM_M4B 8
#define PWM_MLA 9
#define PWM_MLB 10
#define PWM_MCA 11
#define PWM_MCB 12

#define M1 1
#define M2 2
#define M3 3
#define M4 4
#define ML 5
#define MC 6


#define res 10
#define freq 20000


#define lambda 4
#define d2r(x) x*(PI/180)

#define LengthAlpha 0.1 // Ubah Disini untuk panjang dari sumbu roda ke tengah roda

int16_t x;
int16_t y;
int16_t th;

float atanVal;
int xL, yL;
int xR, yR;

int SpeedM = 255 ,
    SpeedM2 = 255 ;
int inv_yR ;

int m1, m2, m3 , m4;
