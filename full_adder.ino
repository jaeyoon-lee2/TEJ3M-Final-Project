/*
  Created by: Jaeyoon Lee
  Created on: Jan 2022
  
  1-bit Full Adder

  Turn on the LEDs by converting from 0 to 2^(number of inputs)
  	into binary every second.
*/

const int len = 1; // number of input A & B
int A[len] = {4}; // input A pins
int B[len] = {3}; // input B pins
int C = 2; // pin number of Carry in
int N_INPUTS = 2*len + 1;
int index = 0;

void setup()
{
  //Serial.begin(9600);
  for (int i = 0; i < len; i++)
  {
    pinMode(A[i], OUTPUT);
    pinMode(B[i], OUTPUT);
  }
  pinMode(C, OUTPUT);
}

void loop()
{
  for (int i = 0; i < pow(2, N_INPUTS); i++)
  {
    bool bool_inputs[N_INPUTS];
    for (int j = 0; j < N_INPUTS; j++)
    {
      bool_inputs[j] = ((i >> j) & 1) == 1;
    }
    
    digitalWrite(C, bool_inputs[0]);
    //Serial.print(bool_inputs[0]);
    
    for (int idx = 1; idx < len+1; idx++)
    {
      digitalWrite(B[idx-1], bool_inputs[idx]);
      digitalWrite(A[idx-1], bool_inputs[idx+len]);
      //Serial.print(bool_inputs[idx]);
      //Serial.print(bool_inputs[idx+len]);
    }
    //Serial.println();
    delay(1000);
  }
}
