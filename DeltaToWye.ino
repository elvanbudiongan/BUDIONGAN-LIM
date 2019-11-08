int Vin = 5;
int raw1 = 0,
    raw2 = 0,
    raw3 = 0;
float Vout1 = 0,
      Vout2 = 0,
      Vout3 = 0;
float R0 = 1000,
      R1 = 0,
      R2 = 0,
      R3 = 0;
float out12 = 0,
      out23 = 0,
      out13 = 0,
      Rsum = 0;
float buffer = 0;

void setup()
{
  Serial.begin( 9600 );
}

void loop()
{
  raw1 = analogRead( A0 );
  raw2 = analogRead( A1 );
  raw3 = analogRead( A2 );
  
  Vout1 = ( raw1 * Vin )/1024.0;
  Vout2 = ( raw2 * Vin )/1024.0;
  Vout3 = ( raw3 * Vin )/1024.0;

  R1 = R0 * ( ( Vout2/Vout1 ) - 1 );
  R2 = R0 * ( ( Vout3/Vout1 ) - 1 ) - R1;
  R3 = R0 * ( ( Vin/Vout1 ) - 1 ) - R1 - R2;

  Rsum = R1 + R2 + R3;
  out12 = ( R1 * R2 )/Rsum;
  out23 = ( R2 * R3 )/Rsum;
  out13 = ( R1 * R3 )/Rsum;

  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();

  Serial.print("-----DELTA ELEMENTS-----");
   Serial.println();
  Serial.print( "Rab: " );
  Serial.println( R1 );
  
  Serial.print( "Rbc: " );
  Serial.println( R2 );

  Serial.print( "Rac: " );
  Serial.println( R3 );
  
  Serial.println();
  Serial.print("-----WYE ELEMENTS-----");
   Serial.println(); 
  Serial.print( "Ra: " );
  Serial.println( out13 );
  
  Serial.print( "Rb: " );
  Serial.println( out12 );
  
  Serial.print( "Rc: " );
  Serial.println( out23 );
  

  
  delay( 1000 );

}
