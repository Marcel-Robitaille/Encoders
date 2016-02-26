class Encoders{
	long RightCount, LeftCount;
	int pinRA, pinRB, pinLA, pinLB;
	int R_A_SIG=0, R_B_SIG=1, L_A_SIG=0, L_B_SIG=1;

	static Encoders * instance;

	static void R_A_RISE(){
		if(Encoders::instance != NULL){
			Encoders::instance->switchPressed(Encoders::instance->getPinRA(), 1);
		}
	}

	static void R_A_FALL(){
		if(Encoders::instance != NULL){
			Encoders::instance->switchPressed(Encoders::instance->getPinRA(), 0);
		}
	}
	
	static void R_B_RISE(){
		if(Encoders::instance != NULL){
			Encoders::instance->switchPressed(Encoders::instance->getPinRB(), 1);
		}
	}

	static void R_B_FALL(){
		if(Encoders::instance != NULL){
			Encoders::instance->switchPressed(Encoders::instance->getPinRB(), 0);
		}
	}

	static void L_A_RISE(){
		if(Encoders::instance != NULL){
			Encoders::instance->switchPressed(Encoders::instance->getPinLA(), 1);
		}
	}

	static void L_A_FALL(){
		if(Encoders::instance != NULL){
			Encoders::instance->switchPressed(Encoders::instance->getPinLA(), 0);
		}
	}
	
	static void L_B_RISE(){
		if(Encoders::instance != NULL){
			Encoders::instance->switchPressed(Encoders::instance->getPinLB(), 1);
		}
	}

	static void L_B_FALL(){
		if(Encoders::instance != NULL){
			Encoders::instance->switchPressed(Encoders::instance->getPinLB(), 0);
		}
	}
	
	public:
		void begin (const int _pinRA, const int _pinRB, const int _pinLA, const int _pinLB){
			pinRA = _pinRA;
			pinRB = _pinRB;

			pinLA = _pinLA;
			pinLB = _pinLB;

			attachInterrupt(pinRA, R_A_RISE, RISING);
			attachInterrupt(pinRB, R_B_RISE, RISING);

			attachInterrupt(pinLA, L_A_RISE, RISING);
			attachInterrupt(pinLB, L_B_RISE, RISING);
			instance = this;
		}

		long getRightCount(){
			return RightCount;
		}
		long getLeftCount(){
			return LeftCount;
		}

		int getPinRA(){
			return pinRA;
		}

		int getPinRB(){
			return pinRB;
		}

		int getPinLA(){
			return pinLA;
		}

		int getPinLB(){
			return pinLB;
		}
		

		void switchPressed(int pin, int rise){
			detachInterrupt(pin);
			if(pin == pinRA){
				R_A_SIG = rise;
				if(R_B_SIG == rise){
					RightCount--;
				}else{
					RightCount++;
				}
				if(rise){
					attachInterrupt(pin, R_A_FALL, FALLING);
				}else{
					attachInterrupt(pin, R_A_RISE, RISING);
				}
			}else if(pin == pinRB){
				R_B_SIG = rise;
				if(R_A_SIG == rise){
					RightCount++;
				}else{
					RightCount--;
				}
				if(rise){
					attachInterrupt(pin, R_B_FALL, FALLING);
				}else{
					attachInterrupt(pin, R_B_RISE, RISING);
				}
			}else if(pin == pinLA){
				L_A_SIG = rise;
				if(L_B_SIG == rise){
					LeftCount--;
				}else{
					LeftCount++;
				}
				if(rise){
					attachInterrupt(pin, L_A_FALL, FALLING);
				}else{
					attachInterrupt(pin, L_A_RISE, RISING);
				}
			}else if(pin == pinLB){
				L_B_SIG = rise;
				if(L_A_SIG == rise){
					LeftCount++;
				}else{
					LeftCount--;
				}
				if(rise){
					attachInterrupt(pin, L_B_FALL, FALLING);
				}else{
					attachInterrupt(pin, L_B_RISE, RISING);
				}
			}
		}

};
