#include "Encoders.h"
Encoders * Encoders::instances [2] = { NULL, NULL };


// instances of our class
Encoders right;
Encoders left;

void setup (){
	Serial.begin(9600);
    right.begin (0, 2, 3);
    left.begin (1, 0, 1);
}

void loop (){
	Serial.print("Right: ");
    Serial.print(right.getRightCount());
    Serial.print("		Left: ");
    Serial.println(left.getLeftCount());
    delay(10);
}
