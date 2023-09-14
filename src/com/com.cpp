/**********************************************************
 * - File: com.cpp
 * - Author: Rubén Padial Allué
 * - Contact: padialruben@gmail.com
 * - Date: 
 * - Revision: 
 **********************************************************/

/**********************************************************/
/*                        INCLUDES                        */
/**********************************************************/
#include "com.hpp"

/**********************************************************/

/**********************************************************/
/*                    GLOBAL VARIABLES                    */
/**********************************************************/

/**********************************************************/

/**********************************************************/
/*                     LOCAL FUNCTIONS                    */
/**********************************************************/

/**********************************************************/

/**********************************************************/
/*                    GLOBAL FUNCTIONS                    */
/**********************************************************/
void com_init(void)
{
  SPI.begin();
  DEBUG_PRINTLN("SPI initialized.");
  
}

void com_task(void)
{ 

}

uint8_t com_write(uint8_t address, uint32_t data, uint8_t CS)
{
  address += 0x80; // Write mode

  SPI.beginTransaction(SPISettings(400, MSBFIRST,SPI_MODE3));
  digitalWrite(CS,LOW);

  
  uint8_t stat = SPI.transfer(address);
  SPI.transfer(data>>24&0xff);
  SPI.transfer(data>>16&0xff);
  SPI.transfer(data>>8&0xff);
  SPI.transfer(data&0xff);

  digitalWrite(CS,HIGH);
  SPI.endTransaction();
  DEBUG_PRINTLN("Register " + String(address) + ": " + String(data));
  return stat;
}

uint32_t com_read(uint8_t address,  uint8_t CS)
{
  uint32_t data = 0;
  SPI.beginTransaction(SPISettings(400, MSBFIRST,SPI_MODE3));
  digitalWrite(CS,LOW);

  uint8_t stat = SPI.transfer(address);
  data |= SPI.transfer(0x00 & 0xff);
  data <<= 8;
  data |= SPI.transfer(0x00 & 0xff);
  data <<= 8;
  data |= SPI.transfer(0x00 & 0xff);
  data <<= 8;
  data |= SPI.transfer(0x00 & 0xff);

  digitalWrite(CS,HIGH);
  SPI.endTransaction();
  return data;
}
/**********************************************************/

/* END OF FILE */
