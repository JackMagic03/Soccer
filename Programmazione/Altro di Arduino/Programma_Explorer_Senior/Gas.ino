//Massimo Giordano
//Funzioni Sensore di Gas

boolean gas()
{
  #define SogliaGas 400
  int readGas = analogRead(Gas);
  
  if(readGas >= SogliaGas)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
