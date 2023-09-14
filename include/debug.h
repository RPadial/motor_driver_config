#ifndef debug_h
#define debug_h


#if _DEBUG_SERIAL_
  #define DEBUG_BAUDRATE 9600
  #define DEBUG_BEGIN(baudrate)           Serial.begin(baudrate)
  #define DEBUG_PRINT(str)                Serial.print(str)
  #define DEBUG_PRINTLN(str)              Serial.println(str)
  #define DEBUG_PRINTF2(d0,d1)            Serial.printf(d0,d1)
  #define DEBUG_PRINTF3(d0,d1,d2)         Serial.printf(d0,d1,d2)
  #define DEBUG_PRINT4D(str,d0,d1,d2,d3)  Serial.printf(str,d0,d1,d2,d3)
#else
  #define DEBUG_BEGIN(baudrate)
  #define DEBUG_PRINT(str)
  #define DEBUG_PRINTLN(str)
  #define DEBUG_PRINTF2(d0,d1)
  #define DEBUG_PRINTF3(d0,d1,d2) 
  #define DEBUG_PRINT4D(str,d0,d1,d2,d3) 
#endif /* DEBUG_SERIAL */

#endif /* debug_h */