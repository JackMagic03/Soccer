void lines_readLines() {
  /**
   * Bisogna creare una variabile agganciata ad un pin analogico
   * che gestirà il ricevitore ad infrarossi.
   * Organizzare un ritorno di dati utilizzabile per tutti e 5 i sensori:
   * nella croce di sensori i sensori posteriori devono
   * essere programmati in parallelo come unico sensore.
   */

  #define sogliaLines 850 // Il valore potrebbe cambiare. L'ho creato a caso

  uint16_t analogReadLines[6];  // L'array che contiene i valori letti dai sensori

  analogReadLines[0] = analogRead(pinLines[0]);
  analogReadLines[1] = analogRead(pinLines[1]);

  /**
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
