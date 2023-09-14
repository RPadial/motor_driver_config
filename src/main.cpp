/*
* @Author: Ruben
* @Date:   2023-09-09 10:39:35
* @Last Modified by:   Ruben
* @Last Modified time: 2023-09-13 21:01:02
*/

#include <Arduino.h>

#include "com.hpp"
#include "motdrv.hpp"

void setup(void)
{
  digitalWrite(13, 0);
  DEBUG_BEGIN(DEBUG_BAUDRATE);
  delay(5000);
  digitalWrite(13, 1);
  com_init();
  motdrv_init();
}

void loop(void)
{
  com_task();
  motdrv_task();
}