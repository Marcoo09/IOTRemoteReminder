
int led1 = 1; // declaramos el led en el pin 12 del arduino

void setup()
{
pinMode(13, OUTPUT); //El pin 1 del arduino lo asignamos como salida para el led
pinMode(12,OUTPUT);
}
void loop()
{ 
  digitalWrite(13, HIGH);   
  //delay(1000);              
  //digitalWrite(13, LOW);   
  //delay(1000);  
}
