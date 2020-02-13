void lines_readLines() {

  #define sogliaLines 850 // Il valore potrebbe cambiare. L'ho creato a caso

  uint16_t analogReadLines[6];  // L'array che contiene i valori letti dai sensori
  uint16_t pinLines[6] = { A0, A1, A2, A3, A4, A5 };  // i 6 pin analogici dei sensori

  analogReadLines[0] = analogRead(pinLines[0]);
  analogReadLines[1] = analogRead(pinLines[1]);

  /*
   * Se questo, come anche gli altri valori, supera una certa soglia
   * bisogna correggere la direzione del robot.
   */

  if(( analogReadLines[0] || analogReadLines[1] ) >= sogliaLines) {

    /*
    I sensori anteriori del robot
     */

  } else {

  }

  analogReadLines[2] = analogRead(pinLines[2]);

  if(analogReadLines[2] >= sogliaLines) {

    /*
    I sensori di destra del robot
     */

  } else {

  }

  analogReadLines[3] = analogRead(pinLines[3]);
  analogReadLines[4] = analogRead(pinLines[4]);

  if(( analogReadLines[3] || analogReadLines[4] ) >= sogliaLines) {

    /*
    I sensori posteriori del robot
     */

  } else {

  }

  analogReadLines[5] = analogRead(pinLines[5]);

  if(analogReadLines[5] >= sogliaLines) {

    /*
    I sensori di sinistra del robot
     */

  } else {

  }

}
