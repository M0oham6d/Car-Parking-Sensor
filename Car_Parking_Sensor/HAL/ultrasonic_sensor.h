/*
 * ultrasonic_sensor.h
 * Author: Muhammed Ayman
 * Module: Ultrasonic Sensor
 */

#ifndef HAL_ULTRASONIC_SENSOR_H_
#define HAL_ULTRASONIC_SENSOR_H_

#include <util/delay.h>
#include "../MCAL/icu.h"
#include "../Standard_Types/standard_types.h"
#include "../MCAL/gpio.h"

/*******************************************************************************
 *                                Configurations                               *
 *******************************************************************************/
#define TRIGGER_PORT_CONNECTION					PORTD_ID
#define TRIGGER_PIN								PIN7_ID
#define ECHO_PORT_CONNECTION					PORTD_ID
#define ECHO_PIN								PIN6_ID

/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/

/*
 * Set up ICU Configuration.
 * Initialize ICU.
 * Set call back function.
 * */
void Ultrasonic_init(void);

/*
 * Send the trigger pulse by using the Ultrasonic_Trigger function.
 * Start the measurement process via the ICU driver.
 * The measured distance in centimeters.
 */
uint16 Ultrasonic_readDistance(void);

#endif /* HAL_ULTRASONIC_SENSOR_H_ */
