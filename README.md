Project Title:
  Car Parking Sensor Using ATmega32, Ultrasonic Sensor, LCD Display, LEDs, and Buzzer.

Overview:
  This project uses an ATmega32 microcontroller to process distance data from an ultrasonic sensor and display the results on an LCD. The system includes three LEDs (Red, Green, and Blue) and a buzzer for indicating the proximity of an obstacle. The LEDs light up progressively and the buzzer activates as the obstacle gets closer, helping drivers park safely.

Features:
  • Ultrasonic Distance Measurement: The ultrasonic sensor measures the distance between the car and any nearby object.
  • LCD Display: Displays the distance measured by the ultrasonic sensor in centimeters. Also displays "Stop" if the distance is less than 5 cm.
  • LED Indicators: Three LEDs (Red, Green, and Blue) light up according to the proximity of the object.
  • Buzzer Alert: The buzzer sounds when the object is too close (<= 5 cm).
  • Dynamic LED Behavior: LEDs turn ON/OFF based on the following distance ranges.
