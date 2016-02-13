#ifndef Encoders_h
#define Encoders_h

#include "Arduino.h"

class Encoders{
	public:
		Encoders();
		void EncodersSetup();
		long RightCount;
		long LeftCount;
		void R_A_RISE();
		void R_A_FALL();
		void R_B_RISE();
		void R_B_FALL();
		void L_A_RISE();
		void L_A_FALL();
		void L_B_RISE();
		void L_B_FALL();
	private:
		short R_A_SIG, R_B_SIG, L_A_SIG, L_B_SIG;
};

#endif