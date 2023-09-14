/**********************************************************
 * - File: com.hpp
 * - Author: Rubén Padial Allué
 * - Contact: padialruben@gmail.com
 * - Date: 
 * - Revision: 
 **********************************************************/

#ifndef com_hpp
#define com_hpp

/**********************************************************/
/*                        INCLUDES                        */
/**********************************************************/
#if ARDUINO < 100
  #include <WProgram.h>
#else
  #include <Arduino.h>
#endif

#include<SPI.h>
/**********************************************************/

/**********************************************************/
/*                        DEFINES                         */
/**********************************************************/

/**********************************************************/

/**********************************************************/
/*                    TYPE DEFINITONS                     */
/**********************************************************/

/**********************************************************/

/**********************************************************/
/*                    GLOBAL FUNCTIONS                    */
/**********************************************************/

/**********************************************************
 * - Function: com_init
 * - Description: Init com.
 * - Inputs: void
 * - Return: void
 **********************************************************/
void com_init(void);

/**********************************************************
 * - Function: com_task
 * - Description: com task.
 * - Inputs: void
 * - Return: void
 **********************************************************/
void com_task(void);

/**********************************************************
 * - Function: com_write
 * - Description: com write.
 * - Inputs: 
 * -- uint8_t address: Register address.
 * -- uint32_t data: Data to be written 
 * -- uint8_t CS: Chips Select
 * - Return: uint8 status
 **********************************************************/
uint8_t com_write(uint8_t address, uint32_t data, uint8_t CS);

/**********************************************************
 * - Function: com_read
 * - Description: com read.
 * - Inputs: void
 * -- uint8_t address: Register address.
 * -- uint8_t CS: Chips Select
 * - Return: uint32 data
 **********************************************************/
uint32_t com_read(uint8_t address,  uint8_t CS);
/**********************************************************/

#endif /* com_hpp */
/* END OF FILE */
