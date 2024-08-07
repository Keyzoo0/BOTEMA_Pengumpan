#include "variabel.h"

void setup() {
  setup_motor();


}

void loop() {
    int x = 100,
        y = 0,
        teta =0;
    
    kinMotor(x , y , teta);
}

