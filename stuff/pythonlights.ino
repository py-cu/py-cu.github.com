//DEFINE PINS
int RED      = 3;
int YELLOW   = 5;
int GREEN    = 9;
int INFRARED = 10;




//SETUP PINS and UART
void setup() 

{ 
  //Begin Serial Communication
  Serial.begin(9600);
  
  
  //Set the pins on board to output
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(INFRARED, OUTPUT);
  delay(100); 
} 

//INIT LIGHTS TO BE OFF 
int SW_RED          = 0;
int SW_YELLOW       = 0;
int SW_GREEN        = 0;
int SW_INFRARED     = 0;
int CONTROL         = 0;
int BRIGHTNESS      = 255;
int RESET           = 1;

void loop() 
{ 

//Lets do a fun startup routine

if(RESET == 1)
{
  Serial.println("INITIALIZING................");
  Serial.print("\n");
  Serial.print("\r");
  Serial.println("BOARD WAS RESET");
  Serial.print("\n");
  Serial.print("\r");
	for(int x=0; x<=255; x++)
	{
		analogWrite(RED,x);
		analogWrite(GREEN,x);
		analogWrite(YELLOW,x);
		analogWrite(INFRARED,x);
                delay(10);	
	}

      
        for(int x=255; x>=0; x--)
	{
		analogWrite(RED,x);
		analogWrite(GREEN,x);
		analogWrite(YELLOW,x);
		analogWrite(INFRARED,x);
                delay(10);	
	}

                analogWrite(RED,255);
                delay(1000);
                analogWrite(RED,0);
		analogWrite(YELLOW,255);
                delay(1000);
                analogWrite(YELLOW,0);
		analogWrite(GREEN,255);
                delay(1000);
                analogWrite(GREEN,0);
		analogWrite(INFRARED,255);
                delay(1000);
                analogWrite(INFRARED,0);
                
                 analogWrite(RED,255);
                 analogWrite(YELLOW,255);
                 analogWrite(GREEN,255);
                 analogWrite(INFRARED,255);
                 delay(1000);
                 
                analogWrite(RED,0);
                analogWrite(YELLOW,0);
                analogWrite(GREEN,0);
                analogWrite(INFRARED,255);

          RESET = 0 ;
          
         Serial.println("BOARD READY");
         Serial.print("\n");
         Serial.print("\r");
         Serial.println("HELLO PY-CU");
         Serial.print("\n");
         Serial.print("\r");
          
}

//START SEQUENCE IS DONE TIME TO START READING FROM SERIAL
if(Serial.available() > 0)
{
  CONTROL = Serial.read();
  

  
 
  switch(CONTROL)
  {
    
      case 'b':
         Serial.println("TO SET BRIGHTNESS PLEASE ENTER A VALUE BETWEEN 1-3");
         Serial.print("\n");
         Serial.print("\r");
        break;
    
       case '1':
        BRIGHTNESS = 85;
        Serial.println("BRIGHTNESS SET");
        Serial.print("\n");
        Serial.print("\r");
        break;
        
        case '2':
        BRIGHTNESS = 170;
        Serial.println("BRIGHTNESS SET");
        Serial.print("\n");
        Serial.print("\r");
        break;
        
        case '3':
        BRIGHTNESS = 255;
        Serial.println("BRIGHTNESS SET");
        Serial.print("\n");
        Serial.print("\r");
        break;
    
    
    case 'R':
    SW_RED = BRIGHTNESS;
    Serial.print("RED:");
    Serial.println(SW_RED, DEC);
    break;
    
    
    case 'r':
    SW_RED = 0;
    Serial.print("RED:");
    Serial.println(SW_RED, DEC);
    break;
    
    case 'Y':
    SW_YELLOW = BRIGHTNESS;
    Serial.print("YELLOW:");
    Serial.println(SW_YELLOW, DEC);
    break;
    
    
    case 'y':
    SW_YELLOW = 0;
    Serial.print("YELLOW:");
    Serial.println(SW_YELLOW, DEC);
    break;
    
    case 'G':
    SW_GREEN = BRIGHTNESS;
    Serial.print("GREEN:");
    Serial.println(SW_GREEN, DEC);
    break;
    
    
    case 'g':
    SW_GREEN = 0;
    Serial.print("GREEN:");
    Serial.println(SW_GREEN, DEC);
    break;
    
     case 'I':
    SW_INFRARED = BRIGHTNESS;
    Serial.print("INFRARED:");
    Serial.println(SW_INFRARED, DEC);
    break;
    
    
    case 'i':
    SW_INFRARED = 0;
    Serial.print("INFRARED:");
    Serial.println(SW_INFRARED, DEC);
    break;
  }
  
    
    
    
    
    


	











//WRITE OUT THE PIN VALUES


	   analogWrite(RED, SW_RED);
	   analogWrite(YELLOW, SW_YELLOW);
	   analogWrite(GREEN, SW_GREEN);
	   analogWrite(INFRARED, SW_INFRARED);

}


// say what you got:
	//Serial.println(control, BYTE);
  

}




