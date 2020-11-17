// Sheet 2, Exercise 1
#include <fstream>
#include <iostream>
#include <cmath>

int main() {
  int n = 0, a = 0;
  double a_sum = 0.0, mean = 0.0, a_square = 0.0, sigma = 0.0;
 
  // 1. a)
  std::ifstream fin1("datensumme.txt");
  while (fin1 >> a) {
	a_sum += a;
    n += 1;
  };
  fin1.close();
  std::cout << "Sum over " << n << " values = " << a_sum << std::endl;
  mean = a_sum / n;
  std::cout << "Mean value <a> = " << mean << std::endl;

  // 1. b) 
  std::ifstream fin2("datensumme.txt");
  while (fin2 >> a) {
	a_square += (a - mean) * (a - mean);
  }
  fin2.close();
  std::cout << "Variance = " << a_square << std::endl;

  // 1. c) 
  sigma = sqrt(a_square);
  std::cout << "Std. deviation sigma = " << sigma << std::endl;

  return 0;
}
