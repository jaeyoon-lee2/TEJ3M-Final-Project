/*
  Created by: Jaeyoon Lee
  Created on: Jan 2022
  
  3-bit Adder/Subtractor

  Turn on the LEDs by converting from 0 to 2^(number of inputs)
  	into binary every 1/2 second.
*/

const int len = 3; // number of input A & B
int A[len] = {5,6,7}; // input A pins
int B[len] = {2,3,4}; // input B pins
int M = 8; // +/- pin number
int N_INPUTS = 2*len + 1;

void setup()
{
  for (int i = 0; i < len; i++)
  {
    pinMode(A[i], OUTPUT);
    pinMode(B[i], OUTPUT);
  }
  pinMode(M, OUTPUT);
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
    
    digitalWrite(M, bool_inputs[N_INPUTS-1]);
    
    for (int idx = 0; idx < len; idx++)
    {
      digitalWrite(B[idx], bool_inputs[idx]);
      digitalWrite(A[idx], bool_inputs[idx+len]);
    }
    delay(500);
  }
}
