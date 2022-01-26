
/*
  Created by: Jaeyoon Lee
  Created on: Jan 2022
  
  2-bit Full Adder

  Turn on the LEDs by converting from 0 to 2^(number of inputs)
  	into binary every second.
*/

const int len = 2; // number of input A & B
int A[len] = {4,5}; // input A pins
int B[len] = {2,3}; // input B pins
int N_INPUTS = 2*len;

void setup()
{
  for (int i = 0; i < len; i++)
  {
    pinMode(A[i], OUTPUT);
    pinMode(B[i], OUTPUT);
  }
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
    
    for (int idx = 0; idx < len; idx++)
    {
      digitalWrite(B[idx], bool_inputs[idx]);
      digitalWrite(A[idx], bool_inputs[idx+len]);
    }
    delay(1000);
  }
  delay(1000);
}
