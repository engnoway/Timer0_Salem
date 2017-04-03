/*
 * DIO_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */
#include "Types.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "util.h"

/*****************************************************************/
/*************************Global Variables************************/
/*****************************************************************/

/*Comment!= 2D-Array that store the add. of each and every DIO_Registers */
volatile static u8* const DIO_U8RegSel[3][4]={{DIO_PINA, DIO_PINB, DIO_PINC, DIO_PIND},{DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD},{DIO_DDRA, DIO_DDRB, DIO_DDRC, DIO_DDRD}};


/*****************************************************************/
/*************************Functions's Body************************/
/*****************************************************************/

/*Comment!= Initialize DIO_Registers values and direction */
extern void DIO_voidInit(void)
{
	*DIO_DDRA=DIO_U8PORTADIR;
	*DIO_DDRB=DIO_U8PORTBDIR;
	*DIO_DDRC=DIO_U8PORTCDIR;
	*DIO_DDRD=DIO_U8PORTDDIR;

	*DIO_PORTA= ((~(DIO_U8PORTADIR)) & *DIO_PORTA);
	*DIO_PORTB= ((~(DIO_U8PORTBDIR)) & *DIO_PORTB);
	*DIO_PORTC= ((~(DIO_U8PORTCDIR)) & *DIO_PORTC);
	*DIO_PORTD= ((~(DIO_U8PORTDDIR)) & *DIO_PORTD);


	*DIO_PORTA= *DIO_PORTA | (DIO_U8PORTAVAL & DIO_U8PORTADIR);
	*DIO_PORTB= *DIO_PORTB | (DIO_U8PORTBVAL & DIO_U8PORTBDIR);
	*DIO_PORTC= *DIO_PORTC | (DIO_U8PORTCVAL & DIO_U8PORTCDIR);
	*DIO_PORTD= *DIO_PORTD | (DIO_U8PORTDVAL & DIO_U8PORTDDIR);
}

extern u8 DIO_U8ReadPinVal(u8 Copy_U8PinIdx, u8* Copy_U8PtrToVal)
{
	u8 Local_U8Flag= U8_NOERROR, Local_U8Port=0;
	if ( Copy_U8PinIdx > DIO_U8PINS_ALL )
	{
		Local_U8Flag= U8_ERROR;
	}
	else
	{

	Local_U8Port = Copy_U8PinIdx/8;
	Copy_U8PinIdx %= 8;
	* Copy_U8PtrToVal = GetBit(*DIO_U8RegSel[0][Local_U8Port], Copy_U8PinIdx);
	}
	return Local_U8Flag;
}

extern u8 DIO_U8WritePinVal(u8 Copy_U8PinIdx, u8 Copy_U8PinVal)
{

	u8 Local_U8Flag= U8_NOERROR, Local_U8Port=0;



	if ( Copy_U8PinIdx > DIO_U8PINS_ALL )
		{
			Local_U8Flag= U8_ERROR;
		}
		else
		{

			Local_U8Port = Copy_U8PinIdx/8;
			Copy_U8PinIdx %= 8;
			switch (Copy_U8PinVal)
			{
				case DIO_U8HIGH: *DIO_U8RegSel[1][Local_U8Port] = SetBit(*DIO_U8RegSel[1][Local_U8Port], Copy_U8PinIdx); break;
				case DIO_U8LOW:  *DIO_U8RegSel[1][Local_U8Port] = ClrBit(*DIO_U8RegSel[1][Local_U8Port], Copy_U8PinIdx); break;
			}
		}


	return Local_U8Flag;
}

extern u8 DIO_U8ReadPortVal(u8 Copy_U8PortIdx, u8* Copy_U8PtrToVal)
{
	u8 Local_U8Flag= U8_NOERROR;
	if ( Copy_U8PortIdx > DIO_U8PORTS_ALL )
		{
			Local_U8Flag= U8_ERROR;
		}
		else
		{
			* Copy_U8PtrToVal = *DIO_U8RegSel[0][Copy_U8PortIdx];
		}
	return Local_U8Flag;
}

u8 DIO_U8WritePortVal(u8 Copy_U8PortIdx, u8 Copy_U8PortVal)
{
	u8 Local_U8Flag= U8_NOERROR;
	if ( Copy_U8PortIdx > DIO_U8PORTS_ALL )
		{
			Local_U8Flag= U8_ERROR;
		}
		else
		{
			Assign(*DIO_U8RegSel[1][Copy_U8PortIdx], Copy_U8PortVal);
		}
	return Local_U8Flag;
}

//??????????//
u8 DIO_U8WritePinDir(u8 Copy_U8PinIdx, u8 Copy_U8PinDir)
{
	u8 Local_U8Flag= U8_NOERROR, Local_U8Port=0;
	if ( Copy_U8PinIdx > DIO_U8PINS_ALL )
		{
			Local_U8Flag= U8_ERROR;
		}
		else
		{

			Local_U8Port = Copy_U8PinIdx/8;
			Copy_U8PinIdx %= 8;
			switch (Copy_U8PinDir)
			{
				case DIO_U8OUTPUT: *DIO_U8RegSel[2][Local_U8Port] = SetBit(*DIO_U8RegSel[2][Local_U8Port], Copy_U8PinIdx); break;
				case DIO_U8INPUT:  *DIO_U8RegSel[2][Local_U8Port] = ClrBit(*DIO_U8RegSel[2][Local_U8Port], Copy_U8PinIdx); break;
			}

		}
	return Local_U8Flag;

}

u8 DIO_U8WritePortDir(u8 Copy_U8PortIdx, u8 Copy_U8PortDir)
{
	u8 Local_U8Flag= U8_NOERROR;
	if ( Copy_U8PortIdx > DIO_U8PORTS_ALL )
		{
			Local_U8Flag= U8_ERROR;
		}
		else
		{
			Assign(*DIO_U8RegSel[2][Copy_U8PortIdx], Copy_U8PortDir);
		}
	return Local_U8Flag;
}

u8 DIO_U8ReadPinDir(u8 Copy_U8PinIdx, u8* Copy_U8PtrToDir)
{
	u8 Local_U8Flag= U8_NOERROR, Local_U8Port=0;
	if ( Copy_U8PinIdx > DIO_U8PINS_ALL )
	{
		Local_U8Flag= U8_ERROR;
	}
	else
	{

	Local_U8Port = Copy_U8PinIdx/8;
	Copy_U8PinIdx %= 8;
	* Copy_U8PtrToDir = GetBit(*DIO_U8RegSel[2][Local_U8Port], Copy_U8PinIdx);
	}
	return Local_U8Flag;
}

u8 DIO_U8ReadPortDir(u8 Copy_U8PortIdx, u8* Copy_U8PtrToDir)
{
	u8 Local_U8Flag= U8_NOERROR;
	if ( Copy_U8PortIdx > DIO_U8PORTS_ALL )
	{
		Local_U8Flag= U8_ERROR;
	}
	else
	{
	* Copy_U8PtrToDir = *DIO_U8RegSel[2][Copy_U8PortIdx];
	}
	return Local_U8Flag;
}
