	#include "Arduino.h"
	#include "Encoders.h"

	long RightCount;
	long LeftCount;
	long R_A_SIG, R_B_SIG, L_A_SIG, L_B_SIG;

	Encoders::Encoders(){
		attachInterrupt(0, &Encoders::R_A_RISE, this, RISING);
		attachInterrupt(1, R_B_RISE, RISING);
		attachInterrupt(2, L_A_RISE, RISING);
		attachInterrupt(3, L_B_RISE, RISING);
		R_A_RISE();
	}

	static void Encoders::R_A_RISE(){
		detachInterrupt(0);
		R_A_SIG = 1;
		if(R_B_SIG == 0){
			RightCount++;
		}
		if(R_B_SIG == 1){
			RightCount--;
		}
		attachInterrupt(0, R_A_FALL, FALLING);
	}
	void Encoders::R_A_FALL(){
		detachInterrupt(0);
		R_A_SIG = 0;
		if(R_B_SIG == 1){
			RightCount++;
		} 
		if(R_B_SIG == 0){
			RightCount--;
		}
		attachInterrupt(0, R_A_RISE, RISING);
	}
	void Encoders::R_B_RISE(){
		detachInterrupt(1);
		R_B_SIG = 1;
		if(R_A_SIG == 1){
			RightCount++;
		}
		if(R_A_SIG == 0){
			RightCount--;
		}
		attachInterrupt(1, R_B_FALL, FALLING);
	}
	void Encoders::R_B_FALL(){
		detachInterrupt(1);
		R_B_SIG = 0;
		if(R_A_SIG == 0){
			RightCount++;
		}
		if(R_A_SIG == 1){
			RightCount--;
		}	
		attachInterrupt(1, R_B_RISE, RISING);
	}
	void Encoders::L_A_RISE(){
		detachInterrupt(2);
		L_A_SIG = 1;
		if(L_B_SIG == 0){
			LeftCount++;
		}
		if(L_B_SIG == 1){
			LeftCount--;
		}
		attachInterrupt(2, L_A_FALL, FALLING);
	}
	void Encoders::L_A_FALL(){
		detachInterrupt(2);
		L_A_SIG = 0;
		if(L_B_SIG == 1){
			LeftCount++;
			} 
		if(L_B_SIG == 0){
			LeftCount--;
			}
		attachInterrupt(2, L_A_RISE, RISING);	
	}
	void Encoders::L_B_RISE(){
		detachInterrupt(3);
		L_B_SIG = 1;
		if(L_A_SIG == 1){
			LeftCount++;
		}
		if(L_A_SIG == 0){
			LeftCount--;
		}
		attachInterrupt(3, L_B_FALL, FALLING);
	}
	void Encoders::L_B_FALL(){
		detachInterrupt(3);
		L_B_SIG = 0;
		if(L_A_SIG == 0){
			LeftCount++;
		}
		if(L_A_SIG == 1){
			LeftCount--;
		}	
		attachInterrupt(3, L_B_RISE, RISING);
	}
