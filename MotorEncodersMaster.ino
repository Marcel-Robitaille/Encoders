#include "Encoders.h"
Encoders * Encoders::instance = NULL;

// instances of our class
Encoders encoders;

void setup (){
	Serial.begin(9600);
    encoders.begin (0, 1, 2, 3);
}

void loop (){
	Serial.print("Right: ");
    Serial.print(encoders.getRightCount());
    Serial.print("		Left: ");
    Serial.println(encoders.getLeftCount());
    delay(10);
}
