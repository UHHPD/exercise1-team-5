#include <fstream>
#include <iostream>
using namespace std;

int main() {
  int z1, z2;

  ifstream fin;
  fin.open("daten.txt");
  ofstream fout("datensumme.txt");   
  while(fin >> z1 >> z2) {
  //  cout << z1 << " " << z2 << endl; // print the numbers
  //  cout << z1 + z2 << endl; //print the sums of pairs
  fout << z1 + z2 << endl; //write the sums into the file
  }
  
  fin.close();
  fout.close();
  return 0;
}