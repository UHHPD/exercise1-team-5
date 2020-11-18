// Sheet 2, Exercise 1
#include <fstream>
#include <iostream>
#include <cmath>

int main() {
  int n = 0, a = 0;
  double a_sum = 0.0, a2_sum = 0.0, mean, variance, sigma;
 
  // 1. a)
  std::ifstream fin("datensumme.txt");
  while (fin >> a) {
    n += 1;
    a_sum += a;
    a2_sum += a * a;
  };
  fin.close();
  std::cout << "Sum over " << n << " values = " << a_sum << std::endl;
  mean = a_sum / n;
  std::cout << "Mean value <a> = " << mean << std::endl;

  // 1. b)
  // more simple approach using:
  //   sum (ai - <a>)^2 = sum (ai)^2 - ( sum (ai) )^2 / n
  variance = (a2_sum - a_sum * a_sum / n) / n;
  std::cout << "Variance = " << variance << std::endl;

  // 1. c) 
  sigma = sqrt(variance);
  std::cout << "Std. deviation sigma = " << sigma << std::endl;

  return 0;
}
