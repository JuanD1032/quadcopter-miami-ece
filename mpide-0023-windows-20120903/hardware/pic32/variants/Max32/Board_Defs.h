/************************************************************************/
/*																		*/
/*	Board_Defs.h --	Board Customization for Digilent chipKIT Max32		*/
/*																		*/
/************************************************************************/
/*	Author: Gene Apperson												*/
/*	Copyright 2011, Digilent. All rights reserved						*/
/************************************************************************/
/*  File Description:													*/
/*																		*/
/* This file contains the board specific declartions and data structure	*/
/* to customize the chipKIT MPIDE for use with the Digilent chipKIT		*/
/* Max32 board.															*/
/*																		*/
/* This code is based on earlier work:									*/
/*		Copyright (c) 2010, 2011 by Mark Sproul							*/
/*		Copyright (c) 2005, 2006 by David A. Mellis						*/
/*																		*/
/************************************************************************/
/*  Revision History:													*/
/*																		*/
/*	10/06/2011(GeneA): Created											*/
/*	11/28/2011(GeneA): Moved data definitions and configuration			*/
/*		functions to Board_Data.c										*/
/*	11/29/2011(GeneA): Moved int priority definitions to System_Defs.h	*/
/*	03/31/2012(GeneA): added support for second LED on Rev D boards		*/
/*																		*/
/************************************************************************/
//*	This library is free software; you can redistribute it and/or
//*	modify it under the terms of the GNU Lesser General Public
//*	License as published by the Free Software Foundation; either
//*	version 2.1 of the License, or (at your option) any later version.
//*	
//*	This library is distributed in the hope that it will be useful,
//*	but WITHOUT ANY WARRANTY; without even the implied warranty of
//*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*	Lesser General Public License for more details.
//*	
//*	You should have received a copy of the GNU Lesser General
//*	Public License along with this library; if not, write to the
//*	Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*	Boston, MA  02111-1307  USA
/************************************************************************/

#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*				Public Board Declarations						*/
/* ------------------------------------------------------------ */
/* The following define symbols that can be used in a sketch to
** refer to periperhals on the board generically.
*/

#define	_BOARD_NAME_	"chipKIT Max32"

/* Define the Microcontroller peripherals available on the board.
*/
#define	NUM_DIGITAL_PINS	87
#define	NUM_ANALOG_PINS		16
#define	NUM_OC_PINS			5
#define	NUM_IC_PINS			5
#define	NUM_TCK_PINS		4
#define	NUM_INT_PINS		5

#define	NUM_SERIAL_PORTS	4
#define	NUM_SPI_PORTS		1
#define	NUM_I2C_PORTS		1

#define	NUM_DSPI_PORTS		4
#define NUM_DTWI_PORTS		5

/* Define I/O devices on the board.
*/
#define	NUM_LED				2
#define NUM_BTN				0
#define	NUM_SWT				0
#define NUM_SERVO			0

/* ------------------------------------------------------------ */
/*						LED Declarations						*/
/* ------------------------------------------------------------ */

/* Define the pin numbers for the LEDs
*/
#define	PIN_LED1	13
#define	PIN_LED2	86

/* ------------------------------------------------------------ */
/*					Button Declarations							*/
/* ------------------------------------------------------------ */

/* No buttons on this board.
*/

/* ------------------------------------------------------------ */
/*					Switch Declarations							*/
/* ------------------------------------------------------------ */

/* No switches on this board.
*/

/* ------------------------------------------------------------ */
/*					Servo Pin Declarations						*/
/* ------------------------------------------------------------ */

/* No servo connectors on this board.
*/

/* ------------------------------------------------------------ */
/*					Timer Pin Declarations						*/
/* ------------------------------------------------------------ */

#define PIN_OC1		3
#define	PIN_OC2		5
#define	PIN_OC3		6
#define	PIN_OC4		9
#define	PIN_OC5		10

#define PIN_IC1		48
#define PIN_IC2		74
#define PIN_IC3		38
#define PIN_IC4		49
#define	PIN_IC5		8

#define	PIN_TCK1	4
//#define	PIN_TCK2	not connected
#define	PIN_TCK3	22
#define	PIN_TCK4	23
#define	PIN_TCK5	11

/* ------------------------------------------------------------ */
/*					Interrupt Pin Declarations					*/
/* ------------------------------------------------------------ */

#define	PIN_INT0	3
#define	PIN_INT1	2
#define PIN_INT2	7
#define	PIN_INT3	21
#define	PIN_INT4	20

/* ------------------------------------------------------------ */
/*					SPI Pin Declarations						*/
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h
*/
const static uint8_t SS   = 53;		// PIC32 SS2A
const static uint8_t MOSI = 51;		// PIC32 SDO2A
const static uint8_t MISO = 50;		// PIC32 SDI2A
const static uint8_t SCK  = 52;		// PIC32 SCK2A

/* The Digilent DSPI library uses these ports.
*/
#define	PIN_DSPI0_SS	53
#define	PIN_DSPI1_SS	74
#define	PIN_DSPI2_SS	19
#define	PIN_DSPI3_SS	15

/* ------------------------------------------------------------ */
/*					Analog Pins									*/
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is
** used to map an analog pin number to the corresponding digital
** pin number.
*/
#define	A0		54
#define	A1		55
#define	A2		56
#define	A3		57
#define	A4		58
#define	A5		59
#define	A6		60
#define	A7		61
#define	A8		62
#define	A9		63
#define	A10		64
#define	A11		65
#define	A12		66
#define	A13		67
#define	A14		68
#define	A15		69

/* ------------------------------------------------------------ */
/*					Change Notice Pins							*/
/* ------------------------------------------------------------ */
/* These define the pin numbers for the various change notice
** pins.
*/
#define	PIN_CN0		4
#define	PIN_CN1		75
#define	PIN_CN2		54
#define	PIN_CN3		55
#define	PIN_CN4		56
#define	PIN_CN5		57
#define	PIN_CN6		58
#define	PIN_CN7		59
#define	PIN_CN8		52
#define	PIN_CN9		29
#define	PIN_CN10	43
#define	PIN_CN11	53
#define	PIN_CN12	69
#define	PIN_CN13	10
#define	PIN_CN14	39
#define	PIN_CN15	47
#define	PIN_CN16	77
#define	PIN_CN17	17
#define	PIN_CN18	16
#define	PIN_CN19	76
#define	PIN_CN20	19
#define	PIN_CN21	18

/* ------------------------------------------------------------ */
/*					Pin Mapping Macros							*/
/* ------------------------------------------------------------ */
/* Macros used to access the port and pin mapping tables.
** These are mostly generic, but some of them may be board specific.
** These perform slightly better as macros compared to inline functions
*/
#define digitalPinToPort(P) ( digital_pin_to_port_PGM[P]  )
#define digitalPinToBitMask(P) ( digital_pin_to_bit_mask_PGM[P]  )
#define digitalPinToTimerOC(P) ( (digital_pin_to_timer_PGM[P] & _MSK_TIMER_OC)  )
#define digitalPinToTimerIC(P) ( (digital_pin_to_timer_PGM[P] & _MSK_TIMER_IC)  )
#define digitalPinToTimerTCK(P) ( (digital_pin_to_timer_PGM[P] & _MSK_TIMER_TCK)  )
#define	digitalPinToTimer(P)	digitalPinToTimerOC(P)
#define portRegisters(P) ( port_to_tris_PGM[P])
#define portModeRegister(P) ( (volatile uint32_t *)port_to_tris_PGM[P] )
#define portInputRegister(P) ( (volatile uint32_t *)(port_to_tris_PGM[P] + 0x0010) )
#define portOutputRegister(P) ( (volatile uint32_t *)(port_to_tris_PGM[P] + 0x0020) )
#define	digitalPinToAnalog(P) ( (P) < 16 ? (P) : ((P) >= 54) && ((P) < 70) ? (P)-54 : NOT_ANALOG_PIN )
#define analogInPinToChannel(P) ( P  )

/* ------------------------------------------------------------ */
/*					Data Definitions							*/
/* ------------------------------------------------------------ */

/* The following declare externals to access the pin mapping
** tables. These tables are defined in Board_Data.c.
*/

#if !defined(OPT_BOARD_DATA)

extern const uint32_t	port_to_tris_PGM[];
extern const uint8_t	digital_pin_to_port_PGM[];
extern const uint16_t	digital_pin_to_bit_mask_PGM[];
extern const uint16_t	digital_pin_to_timer_PGM[];

#endif

/* ------------------------------------------------------------ */
/*				Internal Declarations							*/
/* ------------------------------------------------------------ */
/* The following declarations are used to map peripherals for	*/
/* the core and libraries and to provide configuration options	*/
/* for the core. They are not normally needed by a user sketch.	*/
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_INTERNAL)

/* ------------------------------------------------------------ */
/*				Core Configuration Declarations					*/
/* ------------------------------------------------------------ */
/*																*/
/* These are conditional compilation switches that control the	*/
/* board core configuration functions. These functions provide	*/
/* hooks that can call from some of the core functions into		*/
/* functions defined below that can be used to extend or		*/
/* replace the default behavior of the core function. To use	*/
/* this, enter the appropriate code into the appropriate		*/
/* function skeleton below and then set the appropriate switch	*/
/* value to 1. This will cause the configuration function to be	*/
/* compiled into the build and will cause the code to call the	*/
/* hook function to be compiled into the core function.			*/
/*																*/
/* This board requires some additional initialization, so it	*/
/* sets OPT_BOARD_INIT to 1 to cause the extra init function	*/
/* to be included.												*/
/*																*/
/* ------------------------------------------------------------ */

#define	OPT_BOARD_INIT			1	//board needs custom init code
#define	OPT_BOARD_DIGITAL_IO	0	//board does not extend digital i/o functions
#define	OPT_BOARD_ANALOG_READ	0	//board does not extend analogRead
#define	OPT_BOARD_ANALOG_WRITE	0	//board does not extend analogWrite

/* ------------------------------------------------------------ */
/*					Serial Port Declarations					*/
/* ------------------------------------------------------------ */

/* Serial port 0 uses UART1 (aka UART1A)
*/
#define	_SER0_BASE		_UART1_BASE_ADDRESS
#define	_SER0_IRQ		_UART1_ERR_IRQ
#define	_SER0_VECTOR	_UART_1_VECTOR
#define _SER0_IPL_ISR	_UART1_IPL_ISR
#define	_SER0_IPL		_UART1_IPL_IPC
#define	_SER0_SPL		_UART1_SPL_IPC

/* Serial port 1 uses UART4 (aka UART1B)
*/
#define	_SER1_BASE		_UART4_BASE_ADDRESS
#define	_SER1_IRQ		_UART4_ERR_IRQ
#define	_SER1_VECTOR	_UART_4_VECTOR
#define _SER1_IPL_ISR	_UART4_IPL_ISR
#define	_SER1_IPL		_UART4_IPL_IPC
#define	_SER1_SPL		_UART4_SPL_IPC

/* Serial port 2 uses UART2 (aka UART3A)
*/
#define	_SER2_BASE		_UART2_BASE_ADDRESS
#define	_SER2_IRQ		_UART2_ERR_IRQ
#define	_SER2_VECTOR	_UART_2_VECTOR
#define _SER2_IPL_ISR	_UART2_IPL_ISR
#define	_SER2_IPL		_UART2_IPL_IPC
#define	_SER2_SPL		_UART2_SPL_IPC

/* Serial port 3 uses UART5 (aka UART3B)
*/
#define	_SER3_BASE		_UART5_BASE_ADDRESS
#define	_SER3_IRQ		_UART5_ERR_IRQ
#define	_SER3_VECTOR	_UART_5_VECTOR
#define _SER3_IPL_ISR	_UART5_IPL_ISR
#define	_SER3_IPL		_UART5_IPL_IPC
#define	_SER3_SPL		_UART5_SPL_IPC

/* ------------------------------------------------------------ */
/*					SPI Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard SPI port uses SPI2.
*/
#define	_SPI_BASE		_SPI2_BASE_ADDRESS
#define _SPI_ERR_IRQ	_SPI2_ERR_IRQ
#define	_SPI_RX_IRQ		_SPI2_RX_IRQ
#define	_SPI_TX_IRQ		_SPI2_TX_IRQ
#define	_SPI_VECTOR		_SPI_2_VECTOR
#define	_SPI_IPL_ISR	_SPI2_IPL_ISR
#define	_SPI_IPL		_SPI2_IPL_IPC
#define	_SPI_SPL		_SPI2_SPL_IPC

/* The Digilent DSPI library uses these ports.
*/
#define	_DSPI0_BASE			_SPI2_BASE_ADDRESS
#define	_DSPI0_ERR_IRQ		_SPI2_ERR_IRQ
#define	_DSPI0_RX_IRQ		_SPI2_RX_IRQ
#define	_DSPI0_TX_IRQ		_SPI2_TX_IRQ
#define	_DSPI0_VECTOR		_SPI_2_VECTOR
#define	_DSPI0_IPL_ISR		_SPI2_IPL_ISR
#define	_DSPI0_IPL			_SPI2_IPL_IPC
#define	_DSPI0_SPL			_SPI2_SPL_IPC

#define	_DSPI1_BASE			_SPI1_BASE_ADDRESS
#define	_DSPI1_ERR_IRQ		_SPI1_ERR_IRQ
#define	_DSPI1_RX_IRQ		_SPI1_RX_IRQ
#define	_DSPI1_TX_IRQ		_SPI1_TX_IRQ
#define	_DSPI1_VECTOR		_SPI_1_VECTOR
#define	_DSPI1_IPL_ISR		_SPI1_IPL_ISR
#define	_DSPI1_IPL			_SPI1_IPL_IPC
#define	_DSPI1_SPL			_SPI1_SPL_IPC

#define	_SPI3_ERR_IRQ	_SPI1A_ERR_IRQ	//this declaration missing from the
										//Microchip header file
#define	_DSPI2_BASE			_SPI3_BASE_ADDRESS
#define	_DSPI2_ERR_IRQ		_SPI3_ERR_IRQ
#define	_DSPI2_RX_IRQ		_SPI3_RX_IRQ
#define	_DSPI2_TX_IRQ		_SPI3_TX_IRQ
#define	_DSPI2_VECTOR		_SPI_3_VECTOR
#define	_DSPI2_IPL_ISR		_SPI3_IPL_ISR
#define	_DSPI2_IPL			_SPI3_IPL_IPC
#define	_DSPI2_SPL			_SPI3_SPL_IPC

#define	_DSPI3_BASE			_SPI4_BASE_ADDRESS
#define	_DSPI3_ERR_IRQ		_SPI4_ERR_IRQ
#define	_DSPI3_RX_IRQ		_SPI4_RX_IRQ
#define	_DSPI3_TX_IRQ		_SPI4_TX_IRQ
#define	_DSPI3_VECTOR		_SPI_4_VECTOR
#define	_DSPI3_IPL_ISR		_SPI4_IPL_ISR
#define	_DSPI3_IPL			_SPI4_IPL_IPC
#define	_DSPI3_SPL			_SPI4_SPL_IPC

/* ------------------------------------------------------------ */
/*					I2C Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard I2C port uses I2C1 (SCL1/SDA1). These come to digital
** pins 20 & 21 on the communications connector (J4)
*/
#define	_TWI_BASE		_I2C1_BASE_ADDRESS
#define	_TWI_BUS_IRQ	_I2C1_BUS_IRQ
#define	_TWI_SLV_IRQ	_I2C1_SLAVE_IRQ
#define	_TWI_MST_IRQ	_I2C1_MASTER_IRQ
#define	_TWI_VECTOR		_I2C_1_VECTOR
#define	_TWI_IPL_ISR	_I2C1_IPL_ISR
#define _TWI_IPL		_I2C1_IPL_IPC
#define	_TWI_SPL		_I2C1_SPL_IPC

/* Declarations for Digilent DTWI library.
**		DTWI0:	SDA pin 20, SCL pin 21
**		DTWI1:	SDA pin 13, SCL pin 12
**		DTWI2:	SDA pin 0,  SCL pin 1
**		DTWI3:	SDA pin 29, SCL pin 43
**		DTWI4:	SDA pin 17, SCL pin 16
*/
#define	_DTWI0_BASE		_I2C1_BASE_ADDRESS
#define	_DTWI0_BUS_IRQ	_I2C1_BUS_IRQ
#define	_DTWI0_SLV_IRQ	_I2C1_SLAVE_IRQ
#define	_DTWI0_MST_IRQ	_I2C1_MASTER_IRQ
#define	_DTWI0_VECTOR	_I2C_1_VECTOR
#define	_DTWI0_IPL_ISR	_I2C1_IPL_ISR
#define	_DTWI0_IPL		_I2C1_IPL_IPC
#define	_DTWI0_SPL		_I2C1_SPL_IPC

#define	_DTWI1_BASE		_I2C2_BASE_ADDRESS
#define	_DTWI1_BUS_IRQ	_I2C2_BUS_IRQ
#define	_DTWI1_SLV_IRQ	_I2C2_SLAVE_IRQ
#define	_DTWI1_MST_IRQ	_I2C2_MASTER_IRQ
#define	_DTWI1_VECTOR	_I2C_2_VECTOR
#define	_DTWI1_IPL_ISR	_I2C2_IPL_ISR
#define	_DTWI1_IPL		_I2C2_IPL_IPC
#define	_DTWI1_SPL		_I2C2_SPL_IPC

#define	_DTWI2_BASE		_I2C3_BASE_ADDRESS
#define	_DTWI2_BUS_IRQ	_I2C3_BUS_IRQ
#define	_DTWI2_SLV_IRQ	_I2C3_SLAVE_IRQ
#define	_DTWI2_MST_IRQ	_I2C3_MASTER_IRQ
#define	_DTWI2_VECTOR	_I2C_3_VECTOR
#define	_DTWI2_IPL_ISR	_I2C3_IPL_ISR
#define	_DTWI2_IPL		_I2C3_IPL_IPC
#define	_DTWI2_SPL		_I2C3_SPL_IPC

#define	_DTWI3_BASE		_I2C4_BASE_ADDRESS
#define	_DTWI3_BUS_IRQ	_I2C4_BUS_IRQ
#define	_DTWI3_SLV_IRQ	_I2C4_SLAVE_IRQ
#define	_DTWI3_MST_IRQ	_I2C4_MASTER_IRQ
#define	_DTWI3_VECTOR	_I2C_4_VECTOR
#define	_DTWI3_IPL_ISR	_I2C4_IPL_ISR
#define	_DTWI3_IPL		_I2C4_IPL_IPC
#define	_DTWI3_SPL		_I2C4_SPL_IPC

#define	_DTWI4_BASE		_I2C5_BASE_ADDRESS
#define	_DTWI4_BUS_IRQ	_I2C5_BUS_IRQ
#define	_DTWI4_SLV_IRQ	_I2C5_SLAVE_IRQ
#define	_DTWI4_MST_IRQ	_I2C5_MASTER_IRQ
#define	_DTWI4_VECTOR	_I2C_5_VECTOR
#define	_DTWI4_IPL_ISR	_I2C5_IPL_ISR
#define	_DTWI4_IPL		_I2C5_IPL_IPC
#define	_DTWI4_SPL		_I2C5_SPL_IPC

/* ------------------------------------------------------------ */
/*					A/D Converter Declarations					*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */

#endif	//OPT_BOARD_INTERNAL

/* ------------------------------------------------------------ */

#endif	// BOARD_DEFS_H

/************************************************************************/
