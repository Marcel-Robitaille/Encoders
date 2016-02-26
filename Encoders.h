class Encoders{
    long RightCount, R_A_SIG=0, R_B_SIG=1;
    long LeftCount,  L_A_SIG=0, L_B_SIG=1;

    int PIN_R_A, PIN_R_B, PIN_L_A, PIN_L_B;

    static Encoders * instance;

    static void R_A_RISE(){
        if(Encoders::instances [0] != NULL){
            Encoders::instances [0]->switchPressed(Encoders::instances[0]->getPinRA(), 1);
        }
    }

    static void R_A_FALL(){
    	if(Encoders::instances[0] != NULL){
    		Encoders::instances[0]->switchPressed(Encoders::instances[0]->getPinRA(), 0);
    	}
    }
    
    static void R_B_RISE(){
        if(Encoders::instances [0] != NULL){
            Encoders::instances [0]->switchPressed(Encoders::instances[0]->getPinRB(), 1);
        }
    }

    static void R_B_FALL(){
    	if(Encoders::instances[0] != NULL){
    		Encoders::instances[0]->switchPressed(Encoders::instances[0]->getPinRB(), 0);
    	}
    }

	static void L_A_RISE(){
		if(Encoders::instances [1] != NULL){
			Encoders::instances [1]->switchPressed(Encoders::instances[1]->getPinLA(), 1);
		}
	}

	static void L_A_FALL(){
		if(Encoders::instances[1] != NULL){
			Encoders::instances[1]->switchPressed(Encoders::instances[1]->getPinLA(), 0);
		}
	}
	
	static void L_B_RISE(){
		if(Encoders::instances [1] != NULL){
			Encoders::instances [1]->switchPressed(Encoders::instances[1]->getPinLB(), 1);
		}
	}

	static void L_B_FALL(){
		if(Encoders::instances[1] != NULL){
			Encoders::instances[1]->switchPressed(Encoders::instances[1]->getPinLB(), 0);
		}
	}


    public:
        void begin (const int side, const int pinA, const int pinB){
//            pinMode (pin, INPUT_PULLUP);
            switch (side){
                case 0: //Right
                	PIN_R_A = pinA;
                	PIN_R_B = pinB;
                    attachInterrupt(pinA, R_A_RISE, RISING);
                    attachInterrupt(pinB, R_B_RISE, RISING);
                    instances [0] = this;
                    break;

                case 1: //Left
                    attachInterrupt(pinA, L_A_RISE, RISING);
                    attachInterrupt(pinB, L_B_RISE, RISING);
                    instances [1] = this;
                    break;

            }
        }

        int getRightCount(){
			return RightCount;
        }
        int getLeftCount(){
        	return LeftCount;
        }

		int getPinRA(){
			return PIN_R_A;
		}

		int getPinRB(){
			return PIN_R_B;
		}

		int getPinLA(){
			return PIN_L_A;
		}

		int getPinLB(){
			return PIN_L_B;
		}
		

        void switchPressed(int pin, int rise){
            detachInterrupt(pin);
            if(pin == PIN_R_A){
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
            }else if(pin == PIN_R_B){
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
            }else if(pin == PIN_L_A){
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
            }else if(pin == PIN_L_B){
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
