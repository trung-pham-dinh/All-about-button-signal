
unsigned  int c=0;
unsigned long T=0;

void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
 
  

}

void loop() {
  unsigned short a = check_dou_sing();
   if(a != 0)
    {Serial.print(a);
    Serial.print("\n");}
  
}


bool check_click_debouce(){
static unsigned char bn;
static unsigned char N;
    if((millis() - T) >= 5){
      T = millis();
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
  return false;
}


unsigned short check_dou_sing(){
  static unsigned char M;
  static unsigned int t;
  switch(M)
  {
    case 0:
      if(check_click_debouce() == true)
      {
        t =millis();
        M = 1;
      }
      else return 0;
      break;
    case 1:
      if(((unsigned int)millis()-t) <= 280)
      {
        if(check_click_debouce() == true)
        {
          M = 0;
          return 2;
        }
      }
      else
      {
        M = 0;
        return 1;
      }
      break;
    default: M =0;
  }
  return 0;
}
