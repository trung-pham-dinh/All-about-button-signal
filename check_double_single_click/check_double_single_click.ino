
unsigned  int c=0;



void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
 
  

}

void loop() {
  unsigned short a=check_dou_sing();
   if(a != 0)
    {Serial.print(a);
    Serial.print("\n");}
  
}
bool check_click_debounce(){
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


unsigned short check_dou_sing(){
  unsigned long t;
  if(check_click_debounce() == true)
  {
    t =millis();
    while((millis()-t) <= 280)
    {
      if(check_click_debounce() == true)
      {
        return 2;
      }
    }
    return 1;
  }return 0;
  
}
