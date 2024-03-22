#include "Primes.h"

int isPrime(int num){

  int count = 0;

  for(int i = 1; i <= num; i++){

    if((num % i) == 0){

      count++;
    }
  }

  if(count > 2){
    return 0;
  }
  else{
    return 1;
  }
return 0;
}



void findPrimes(int num1, int num2, string something){
  ofstream file;
  file.open(something.c_str());
  file << "Below are the prime numbers between 1 and 20";
  for(int i = (num1 + 1); i < num2; i++){
    int x = isPrime(i);

    if(x == 1){
      file << i << endl;
    }
  }
  file.close();
}
