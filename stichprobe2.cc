// Sheet 2, Exercise 2
// Modified 2020-11-22 by Michael

#include <fstream>
#include <iostream>
#include <cmath>

int main() {
  const int sample_size = 9;
  int n = 0, sample_count = 0, a = 0;
  double a_sum = 0.0, a2_sum = 0.0, mean, variance;
  double mean_sum, var_sum, samples_mean, samples_var;
 
  std::ofstream fmean("mittelwerte.txt");
  std::ofstream fvar("varianzen.txt");
  std::ifstream fin("datensumme.txt");

// Sheet 2, Exercise 2a
  while (fin >> a) {
    n += 1;
    a_sum += a;
    a2_sum += a * a;

    if (n % sample_size == 0) { 
      mean = a_sum / sample_size;
      variance = (a2_sum - a_sum * a_sum / sample_size) / sample_size;
      //write into the files after every 9 elements
      fmean << mean <<std::endl;
      fvar << variance <<std::endl;
      sample_count += 1;
      mean_sum += mean;
      var_sum += variance;

      //reset the sums to 0
      a_sum = 0;
      a2_sum = 0;
    }
  };

// Sheet 2, Exercise 2b
//   samples_var = var_sum / (sample_count - 1);
  samples_mean = mean_sum / sample_count;
  samples_var = var_sum / sample_count;

  std::cout << "Mean of " << sample_count << " means = "
	<< samples_mean << std::endl;
  std::cout << "Mean of the variances = " << samples_var << std::endl;

  fin.close();
  fmean.close();
  fvar.close();
  
  return 0;
}
