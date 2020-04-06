#include <iostream>
#include "Cmpx.hh"

int main() {

  std::string s1, s2;
  std::cout << "Enter a complex number (e.g. -2.01 + 6.7i): ";
  getline(std::cin,s1);
  std::cout << "Now enter another complex number: ";
  getline(std::cin,s2);

  Cmpx z1 {s1};
  Cmpx z2 {s2};

  Cmpx sum = z1.plus(z2);
  std::cout << "The sum of " << z1.to_string() << " and " << z2.to_string() << " is " << sum.to_string() << ".\n";

  Cmpx product = z1.times(z2);
  std::cout << "Their product is " << product.to_string() << ".\n";
  std::cout << "Dividing out the second to obtain the first: " << product.over(z2).to_string() << "\n";
  std::cout << "Dividing out the first to obtain the second: " << product.over(z1).to_string() << "\n";
  
  Cmpx i {0.0,1.0};
  std::cout << "Rotating first by 90 degrees: " << z1.times(i).to_string() << "\n";
  std::cout << "Rotating second by 90 degrees: " << z2.times(i).to_string() << "\n";
  
  return 0;
}

