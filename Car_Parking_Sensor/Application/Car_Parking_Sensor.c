/*
 * Car_Parking_Sensor.c
 * Author: Muhammed Ayman
 * Module: Car Parking Sensor
 */

#include "Car_Parking_Sensor.h"

/*******************************************************************************
 *                      			Variables                                  *
 *******************************************************************************/
uint16 g_distance = 0;

/*
 * Function to initialize all modules.
 */
void Inits(void)
{
	Ultrasonic_init();
	LCD_init();
	LEDS_init();
	Buzzer_init();
}

/*
 * Function to make an alert.
 */
void Alert(void)
{
	LED_on(red);
	LED_on(green);
	LED_on(blue);
	Buzzer_on();
	_delay_ms(200);
	LED_off(red);
	LED_off(green);
	LED_off(blue);
	Buzzer_off();
	_delay_ms(200);
}

/*
 * Function to read the distance and display it on LCD.
 * Distance <= 5 cm: All LEDs are flashing (Red, Green, Blue), Buzzer sounds, LCD shows "Stop."
 * 6 cm <= Distance <= 10 cm: All LEDs ON (Red, Green, Blue), No buzzer.
 * 11 cm <= Distance <= 15 cm: Red and Green LEDs ON, Blue LED OFF.
 * 16 cm <= Distance <= 20 cm: Only Red LED ON, others OFF.
 * Distance > 20 cm: All LEDs OFF, Buzzer OFF.
 */
void Read_Distance_and_Display_on_LCD(void)
{
	g_distance = Ultrasonic_readDistance();

	LCD_displayStringRowColumn(0, 0, "Distance = ");
	LCD_intgerToString(g_distance);
	/*
	 * If distance is < 10, clear the next pixel in LCD.
	 */
	if(g_distance < 10)
	{
		LCD_displayCharacter(' ');
	}
	LCD_displayStringRowColumn(0, 13, " cm");

	if(g_distance <= 5)
	{
		Alert();
		LCD_displayStringRowColumn(1, 6, "-STOP-");
	}
	else if(g_distance >= 6 && g_distance <= 10)
	{
		Buzzer_off();
		LED_on(red);
		LED_on(green);
		LED_on(blue);
		LCD_displayStringRowColumn(1, 6, "      ");		/* To delete 'STOP' word from LCD. */
	}
	else if(g_distance >= 11 && g_distance <= 15)
	{
		LED_on(red);
		LED_on(green);
		LED_off(blue);
		LCD_displayStringRowColumn(1, 6, "      ");		/* To delete 'STOP' word from LCD. */
	}
	else if(g_distance >= 16 && g_distance <= 20)
	{
		LED_on(red);
		LED_off(green);
		LED_off(blue);
		LCD_displayStringRowColumn(1, 6, "      ");		/* To delete 'STOP' word from LCD. */
	}
	else
	{
		LED_off(red);
		LED_off(green);
		LED_off(blue);
		LCD_displayStringRowColumn(1, 6, "      ");		/* To delete 'STOP' word from LCD. */
	}
}

/*
 * The main function.
 */
int main(void)
{
	Inits();			/* Initialize all modules. */

	while(1)
	{
		Read_Distance_and_Display_on_LCD();		/* Read the distance and display it on LCD. */
	}
	return 0;
}
