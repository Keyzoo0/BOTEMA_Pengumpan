void kontrol_motor(){
  // Serial.printf("rx:%4d,ry:%4d", inverse, ry_val);
  // Serial.println();

  xR = PS4.RStickX() ;
  yR = PS4.RStickY() ;

  if(abs(xR) < 50) xR = 0 ; 
  if(abs(yR) < 50) yR = 0 ;

  if (PS4.RStickX() != 0 || PS4.RStickY() != 0) {
    if (abs(yR) <= 127 ) inv_yR = 127;    
    atanVal = atan2(xR, inv_yR);
    atanVal = (atanVal* 3 * 180 / PI);
    // Serial.printf("rx:%4d,ry:%4d", inverse, ry_val);
    // Serial.println();
  }

  if (PS4.LStickX() != 0 || PS4.LStickY() != 0) {
    if (PS4.Right()) {
      // Serial.println("kanan");
      xL = 70 ;
      yL = 0;
    } else if (PS4.Down()) {
      // Serial.println("bawah");
      xL = 0;
      yL = -70 ;
    } else if (PS4.Up()) {
      // Serial.println("atas");
      xL = 0;
      yL = 70 ;
    } else if (PS4.Left()) {
      // Serial.println("kiri");
      xL = -70 ;
      yL = 0;
    } else {
      xL = PS4.LStickX() * 225 / 128;
      yL = PS4.LStickY() * 225 / 128;
      
      if(abs(xL) < 50){
        xL = 0 ;
      }if(abs(yL) < 50){
        yL = 0 ;
      }
      if (abs(yL) > abs(xL)) {
        if (abs(yL) > 60) xL = 0;
      } else {
        if (abs(xL) > 60) yL = 0;
      }
    }
  
  if(abs(xL) < 10) xL = 0;
  if(abs(yL) < 10) yL = 0;

  kinMotor(yL, -xL, (atanVal*-1) * 400);

    // Serial.println();
  }
}


void removePairedDevices() {
  uint8_t pairedDeviceBtAddr[20][6];
  int count = esp_bt_gap_get_bond_device_num();
  esp_bt_gap_get_bond_device_list(&count, pairedDeviceBtAddr);
  for (int i = 0; i < count; i++) {
    esp_bt_gap_remove_bond_device(pairedDeviceBtAddr[i]);
  }
}

