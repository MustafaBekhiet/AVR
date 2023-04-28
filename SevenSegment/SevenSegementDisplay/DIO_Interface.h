

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}enuPins_t;

typedef enum{
	portA=0,
	portB,
	portC,
	portD
}enuPorts_t;

void DioSetPinDirection(u8 Copy_u8port,u8 Copy_u8pin,u8 Copy_u8direction);
void DioSetPinValue(u8 Copy_u8port,u8 Copy_u8pin, u8 Copy_u8value);
u8   DioGetPinValue(u8 Copy_u8port, u8 Copy_u8pin);

void DioSetPortDirection(u8 Copy_u8port, u8 Copy_u8direction);
void DioSetPortValue(u8 Copy_u8port, u8 Copy_u8value);
u8 DioGetPortValue(u8 Copy_u8port);

#endif /* DIO_INTERFACE_H_ */

