
//loading led's and indicator
const int red_led = 6;
const int green_led = 5;
const int blue_led  = 7;
const int white_led = 8;
const int yellow_led = 10;	//indicates that there's a huge Light fluctuation
const int buzzer = 3;
const int pin_input = A0;


int stable_voltage;	//first voltage reading(with a laser through the ldr).
int spike_voltage = 70;
int voltage_read;	//voltage read inside the loop(it keeps updating).

void setup(){
	//for checking the voltage value;
	//Serial.begin(9600);

	pin_setup();
	loading();
	stable_voltage = analogRead(pin_input);

	//Serial.println(stable_voltage);
}

void loop(){

	voltage_read = analogRead(pin_input);
	int time = 500;
	int time_change = 2;
	int red_voltage = 0;
	int add_voltage = 51;

	if(voltage_read < stable_voltage + spike_voltage){
		
		for(int j = 0; j < 5; j++){
		
			red_voltage += add_voltage;
			digitalWrite(white_led, HIGH);
			delay(time_change);
			digitalWrite(white_led, LOW);
			digitalWrite(blue_led, HIGH);
			delay(time_change);
			digitalWrite(blue_led, LOW);
			delay(time_change);
			digitalWrite(green_led, HIGH);
			delay(time_change);
			digitalWrite(green_led, LOW);
			analogWrite(red_led, red_voltage);
			analogWrite(buzzer, red_voltage);

			time = time / time_change;

		}
		do{
			voltage_read = analogRead(pin_input);
			for(int k = 0; k < 3; k++){

				digitalWrite(red_led, HIGH);
				digitalWrite(buzzer, HIGH);
				delay(500);
				digitalWrite(red_led, LOW);
				digitalWrite(buzzer, LOW);
				delay(500);

			}
		}while(voltage_read < stable_voltage + spike_voltage);

	}else if(voltage_read <= stable_voltage + 20 || voltage_read >= stable_voltage + 20){

		digitalWrite(red_led, LOW);
		digitalWrite(green_led, HIGH);
		digitalWrite(blue_led, LOW);
		digitalWrite(white_led, LOW);


	}else{

		digitalWrite(yellow_led, HIGH);
		delay(500);
		digitaWrite(yellow_led,	LOW);
		delay(500);

	}


}





void pin_setup(){

	pinMode(red_led, OUTPUT);
	pinMode(green_led, OUTPUT);
	pinMode(blue_led, OUTPUT);
	pinMode(white_led, OUTPUT);
	pinMode(yellow_led, OUTPUT);
	pinMode(buzzer, OUTPUT);
	pinMode(pin_input, INPUT);

}
void loading(){
	float voltage_add = 51;	
	float voltage_container = 0;
	int i = 0;
	int time = 1000;
	int time_change = 2; 
	int result;

	for(i; i < 5; i++){
		voltage_container += voltage_add;	//voltage change per iteration
		result = time / time_change	// time change per iteration
		int option = i % 2;
		if(options == 0){

			digitalWrite(red_led, HIGH);
			delay(result);
			digitalWrite(red_led, LOW);
			digitalWrite(green_led, voltage_container);
			delay(result);
			digitalWrite(blue_led, HIGH);
			delay(result);
			digitalWrite(blue_led, LOW);
			digitalWrite(white_led, HIGH);
			delay(result);
			digitalWrite(white_led, LOW);
			digitalWrite(yellow_led, HIGH);
			delay(result);

		}else if(options == 1){

			digitalWrite(yellow_led, LOW);
			digitalWrite(white_led, HIGH);
			delay(result);
			digitalWrite(white_led, LOW);
			digitalWrite(blue_led, HIGH);
			delay(result);
			digitalWrite(blue_led, LOW);
			digitalWrite(green_led, voltage_container);
			delay(result);

		}else{
			for(int a = 0; a < 3; a++){

				digitalWrite(red_led, HIGH);
				digitalWrite(green_led, HIGH);
				digitalWrite(blue_led, HIGH);
				digitalWrite(white_led, HIGH);
				digitalWrite(yellow_led, HIGH);
				delay(500);
				digitalWrite(red_led, LOW);
				digitalWrite(green_led, LOW);
				digitalWrite(blue_led, LOW);
				digitalWrite(white_led, LOW);
				digitalWrite(yellow_led, LOW);
				delay(500);
			}
		}
	
	}
	digitalWrite(red_led, LOW);
	analogWrite(green_led, 255);
	digitaWrite(blue_led, LOW);
	digitalWrite(white_led, LOW);
	digitalWrite(yellow_led, LOW);

}
