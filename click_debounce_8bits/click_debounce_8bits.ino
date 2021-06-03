
unsigned  int c=0;



void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
 
  

}

void loop() {
   if(check_click_debouce() == true)
  {
    c +=1;
    Serial.print(c);
    Serial.print("\n");
  } 
}
bool check_click_debouce(){
static unsigned char bn;
static unsigned char N;

  delay(5);
  bn <<= 1;
  if (digitalRead(2) == 1) bn |= 1;     
  switch(N) {
    case 0 :                    // kiem tra nhan phim
        if ((bn&0x07) == 0x00) {
          N = 1;
         /* Serial.print(millis());
          Serial.print("\n");*/
          
        }
        break;
    case 1 :                      // kiem tra nha phim
        if ((bn&0x07) == 0x07) {
           N = 0;
          /* Serial.print(millis());
           Serial.print("\n \n");*/
           return true;
        }
        break;
    default :
        N = 0;
        break;
  } // switch
  return(false);
}


  
  
  
  
  
