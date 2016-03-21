/*
 * SSD_config.h
 *
 *  Created on: Feb 3, 2016
 *      Author: Home
 */

#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_


#define SSD_u8DISPCOUNT
/**************************************************************************/
/********************* Types ********************************************/
/**************************************************************************/
#define SSD_u8DISP1TYPE SSD_u8COMCTH
#define SSD_u8DISP2TYPE SSD_u8COMCTH
#define SSD_u8DISP3TYPE SSD_u8COMCTH
#define SSD_u8DISP4TYPE SSD_u8COMCTH
#define SSD_u8DISP5TYPE SSD_u8COMCTH
#define SSD_u8DISP6TYPE SSD_u8COMCTH
/**************************************************************************/
/********************* Initial Values ********************************************/
/**************************************************************************/

#define SSD_u8DISP1INITVAL 0
#define SSD_u8DISP2INITVAL 0
#define SSD_u8DISP3INITVAL 0
#define SSD_u8DISP4INITVAL 0
#define SSD_u8DISP5INITVAL 0
#define SSD_u8DISP6INITVAL 0
/**************************************************************************/
/*********************** State ********************************************/
/**************************************************************************/

#define SSD_u8DISP1INITSTATE On
#define SSD_u8DISP2INITSTATE On
#define SSD_u8DISP3INITSTATE On
#define SSD_u8DISP4INITSTATE On
#define SSD_u8DISP5INITSTATE On
#define SSD_u8DISP6INITSTATE On
/**************************************************************************/
/*********************  Common pin ****************************************/
/**************************************************************************/

#define SSD_u8DISP1COM DIO_u8PIN0
#define SSD_u8DISP2COM DIO_u8PIN8
#define SSD_u8DISP3COM DIO_u8PIN16
#define SSD_u8DISP4COM DIO_u8PIN24
#define SSD_u8DISP5COM
#define SSD_u8DISP6COM
/**************************************************************************/
/*********************  Segments ******************************************/
/**************************************************************************/
#define SSD_u8DISP1SEGA DIO_u8PIN16
#define SSD_u8DISP1SEGB DIO_u8PIN17
#define SSD_u8DISP1SEGC DIO_u8PIN18
#define SSD_u8DISP1SEGD DIO_u8PIN19
#define SSD_u8DISP1SEGE DIO_u8PIN20
#define SSD_u8DISP1SEGF DIO_u8PIN21
#define SSD_u8DISP1SEGG DIO_u8PIN22

#define SSD_u8DISP2SEGA DIO_u8PIN9
#define SSD_u8DISP2SEGB DIO_u8PIN10
#define SSD_u8DISP2SEGC DIO_u8PIN11
#define SSD_u8DISP2SEGD DIO_u8PIN12
#define SSD_u8DISP2SEGE DIO_u8PIN13
#define SSD_u8DISP2SEGF DIO_u8PIN14
#define SSD_u8DISP2SEGG DIO_u8PIN15

#define SSD_u8DISP3SEGA DIO_u8PIN1
#define SSD_u8DISP3SEGB DIO_u8PIN1
#define SSD_u8DISP3SEGC DIO_u8PIN1
#define SSD_u8DISP3SEGD DIO_u8PIN1
#define SSD_u8DISP3SEGE DIO_u8PIN1
#define SSD_u8DISP3SEGF DIO_u8PIN1
#define SSD_u8DISP3SEGG DIO_u8PIN1

#define SSD_u8DISP4SEGA DIO_u8PIN1
#define SSD_u8DISP4SEGB DIO_u8PIN1
#define SSD_u8DISP4SEGC DIO_u8PIN1
#define SSD_u8DISP4SEGD DIO_u8PIN1
#define SSD_u8DISP4SEGE DIO_u8PIN1
#define SSD_u8DISP4SEGF DIO_u8PIN1
#define SSD_u8DISP4SEGG DIO_u8PIN1

#define SSD_u8DISP5SEGA DIO_u8PIN1
#define SSD_u8DISP5SEGB DIO_u8PIN1
#define SSD_u8DISP5SEGC DIO_u8PIN1
#define SSD_u8DISP5SEGD DIO_u8PIN1
#define SSD_u8DISP5SEGE DIO_u8PIN1
#define SSD_u8DISP5SEGF DIO_u8PIN1
#define SSD_u8DISP5SEGG DIO_u8PIN1

#define SSD_u8DISP6SEGA DIO_u8PIN1
#define SSD_u8DISP6SEGB DIO_u8PIN1
#define SSD_u8DISP6SEGC DIO_u8PIN1
#define SSD_u8DISP6SEGD DIO_u8PIN1
#define SSD_u8DISP6SEGE DIO_u8PIN1
#define SSD_u8DISP6SEGF DIO_u8PIN1
#define SSD_u8DISP6SEGG DIO_u8PIN1

/**************************************************************************/
/*********************  COUNT  ********************************************/
/**************************************************************************/

#define SSD_u8DISPCOUNT		2


#endif /* SSD_CONFIG_H_ */
