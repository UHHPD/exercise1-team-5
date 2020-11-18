// Sheet 2, Exercise 2
#include <fstream>
#include <iostream>
#include <cmath>

int main() {
  int n = 0, a = 0;
  double a_sum = 0.0, a2_sum = 0.0, mean, variance, sigma;
   
  std::ofstream fmean("mittelwerte.txt");
  std::ofstream fvar("varianzen.txt");
  std::ifstream fin("datensumme.txt");

  while (fin >> a) {
    n += 1;
    a_sum += a;
    a2_sum += a * a;

    if (n%9 == 0) { 
      mean = a_sum/n;
      variance = (a2_sum - a_sum * a_sum / n) / n;
      fmean << mean <<std::endl;
      fvar << variance <<std::endl;
      //write into the files after every 9 elements
      
      a_sum = 0;
      a2_sum = 0;
      //reset the sums to 0
    }
  };
  
  fin.close();
  fmean.close();
  fvar.close();
  
  return 0;
}
