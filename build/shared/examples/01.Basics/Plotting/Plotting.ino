/*
Plotting example

In this example we generate a continous sine wave 
on the arduino and send it out via the serial port.
This signal can be observed via the serial plotter
of the Arduino IDE.

This example code is in the public domain.
*/

float frequency = 1.0f;
float amplitude = 100.0f;

void setup() {
  // Initialize serial
  Serial.begin(115200);
}

void loop() {
  unsigned long time = millis();
  
  // Compute basic sine wave signal
  float x = time * 0.001f * 2 * PI * frequency;
  float signal = amplitude * sin(x);
  
  // Adding some random noise to the signal
  signal += random(-100, 101) * 0.0006f * amplitude;

  // Send the signal over the serial
  Serial.println(signal);

  // Wait for 10ms to limit the update rate
  delay(10);
}
