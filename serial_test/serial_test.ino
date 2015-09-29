// test_serial.ino
//konashi == Arduino test program
//Arduino PWM 3,5,6,9,10,11

#define red 3
#define blue 5
#define green 6


void setup() {
	Serial.begin(9600);
	pinMode(red,OUTPUT);
        pinMode(blue,OUTPUT);
        pinMode(green,OUTPUT);
	Serial.println("stars-E");

}

void up(){
       Serial.println("up");
       for(int i = 0; i < 3; i++){
         analogWrite(red,255);
         delay(100);
         analogWrite(red,0);
         delay(100);
       }
       
       
}


void down(){
       Serial.println("down");
         for(int b = 0; b < 3; b++){
        analogWrite(blue,255);
         delay(100);
         analogWrite(blue,0);
         delay(100);
         }
         
}

void brake(){
       Serial.println("brake");
         for(int c = 0; c < 3; c++){
        analogWrite(green,255);
         delay(100);
         analogWrite(green,0);
         delay(100);
         }
         
  
}

void info(){
                        Serial.println("info");
                        
}



  
  

void loop() {      
         analogWrite(green,255);
         analogWrite(red,255);
         analogWrite(blue,255);
}

void serialEvent(){
	char ch;
	if(Serial.available()>0){
		ch=Serial.read();
		switch(ch){
			case 's':
                        up();
                        break;
                        

			case 'd':
			down();
                        break;

			case 'b':
			brake();
                        break;

			case 'i':
                         info();
                        break;

		}
	}
}
