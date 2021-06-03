
 
unsigned int count = 0;
boolean pre_state = HIGH;




void setup() {
  Serial.begin(115200);
  pinMode(2, INPUT);
  
 
}

void loop() {

  if(check_click() == true)
  {
    count +=1;
    Serial.print(count);
    Serial.print("\n");
  }
  
  
}

bool check_click()
{
  if(check_state() == LOW && pre_state == HIGH)
  {
    pre_state = LOW;
    return true;
  }
  else if(check_state() == HIGH && (pre_state == LOW))
  {
    pre_state = HIGH;
    
  }
  return false;
}

bool check_state()
{
  if(digitalRead(2) == 0)
  {
    delay(5);
    if(digitalRead(2) == 0)
    {
      delay(5);
      if(digitalRead(2) == 0)
      return LOW;
    }
  }
  return HIGH;
}
