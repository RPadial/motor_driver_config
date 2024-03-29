/**********************************************************
 * - File: motdrv.hpp
 * - Author: Rubén Padial Allué
 * - Contact: padialruben@gmail.com
 * - Date: 
 * - Revision: 
 **********************************************************/

#ifndef motdrv_hpp
#define motdrv_hpp

/**********************************************************/
/*                        INCLUDES                        */
/**********************************************************/
#if ARDUINO < 100
  #include <WProgram.h>
#else
  #include <Arduino.h>
#endif

#include "motdrv_defs.hpp"
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
 * - Function: motdrv_init
 * - Description: Init motdrv.
 * - Inputs: void
 * - Return: void
 **********************************************************/
void motdrv_init(void);

/**********************************************************
 * - Function: motdrv_task
 * - Description: motdrv task.
 * - Inputs: void
 * - Return: void
 **********************************************************/
void motdrv_task(void);
/**********************************************************/

#endif /* motdrv_hpp */
/* END OF FILE */
