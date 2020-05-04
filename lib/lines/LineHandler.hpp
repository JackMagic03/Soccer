/**
 * LineHandler.hpp
 * #author Massimo Giordano
 */

#pragma once
#include "LineDetector.hpp"

class LineHandler {
  LineDetector detector_vect[NUM_LINES];

  int16_t angle[NUM_LINES];
  uint8_t mask[NUM_LINES];
  /**
   * L'array mask serve per l'ulteriore controllo quando si parla delle letture dei sensori,
   * perché le sue variabili vengono messe da 1 solo quando il sensore non ha mai letto prima
   */
   uint8_t flg;
   int timer;

   int tot_angle;      //La somma degli angoli dei sensori che hanno rilevato qualcosa
   uint8_t num_angle;  //Il numero degli angoli che hanno trovato quancosa
   int escape_angle;   //La traiettoria calcolata dalla media dei vettori dagli angoli dei sensori

public:
  LineHandler();

  void reset();
  void moveData();
  void handle();
};
