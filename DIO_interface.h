/*
 * DIO_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

/*****************************************************************/
/***********************Public Definitions************************/
/*****************************************************************/


/*Comment!: Pin Index Values */
#define DIO_U8PIN0		0
#define DIO_U8PIN1		1
#define DIO_U8PIN2		2
#define DIO_U8PIN3		3
#define DIO_U8PIN4		4
#define DIO_U8PIN5		5
#define DIO_U8PIN6		6
#define DIO_U8PIN7		7
#define DIO_U8PIN8		8
#define DIO_U8PIN9		9
#define DIO_U8PIN10		10
#define DIO_U8PIN11		11
#define DIO_U8PIN12		12
#define DIO_U8PIN13		13
#define DIO_U8PIN14		14
#define DIO_U8PIN15		15
#define DIO_U8PIN16		16
#define DIO_U8PIN17		17
#define DIO_U8PIN18		18
#define DIO_U8PIN19		19
#define DIO_U8PIN20		20
#define DIO_U8PIN21		21
#define DIO_U8PIN22		22
#define DIO_U8PIN23		23
#define DIO_U8PIN24		24
#define DIO_U8PIN25		25
#define DIO_U8PIN26		26
#define DIO_U8PIN27		27
#define DIO_U8PIN28		28
#define DIO_U8PIN29		29
#define DIO_U8PIN30		30
#define DIO_U8PIN31		31


/*Comment!: Port Index Values */
#define DIO_U8PORT0		0
#define DIO_U8PORT1		1
#define DIO_U8PORT2		2
#define DIO_U8PORT3		3

/*Comment!: Digital I/O value */
#define DIO_U8HIGH		1
#define DIO_U8LOW		0

/*Comment!: Digital I/O Direction */
#define DIO_U8INPUT		0
#define DIO_U8OUTPUT	1


/*****************************************************************/
/***********************Public Functions**************************/
/*****************************************************************/

/*Comment!: Read Pin Value */
extern u8 DIO_U8ReadPinVal(u8 Copy_U8PinIdx, u8* Copy_U8PtrToVal);

/*Comment!: Write Pin Value */
extern u8 DIO_U8WritePinVal(u8 Copy_U8PinIdx, u8 Copy_U8PinVal);

/*Comment!: Read Port Value */
extern u8 DIO_U8ReadPortVal(u8 Copy_U8PortIdx, u8* Copy_U8PtrToVal);

/*Comment!: Write Port Value */
extern u8 DIO_U8WritePortVal(u8 Copy_U8PortIdx, u8 Copy_U8PortVal);

/*Comment!: Write Pin Direction */
extern u8 DIO_U8WritePinDir(u8 Copy_U8PinIdx, u8 Copy_U8PinDir);

/*Comment!: Write Port Direction */
extern u8 DIO_U8WritePortDir(u8 Copy_U8PortIdx, u8 Copy_U8PortDir);

/*Comment!: Read Pin Direction */
extern u8 DIO_U8ReadPinDir(u8 Copy_U8PinIdx, u8* Copy_U8PtrToDir);

/*Comment!: Read Port Direction */
extern u8 DIO_U8ReadPortDir(u8 Copy_U8PortIdx, u8* Copy_U8PtrToDir);

/*Comment!: Initialization Function */
extern void DIO_voidInit(void);



#endif /* DIO_INTERFACE_H_ */
