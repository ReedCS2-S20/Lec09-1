#include <iostream>
#include <cmath>
#include <string>

class Cmpx {

private:
  double re;
  double im;

  static const double kPi;       // class variables
  static const double kEpsilon;  // 

  static bool parse(std::string s, double& rp, double& ip); // class method

  Cmpx conjugate();
  double modulus2();
  Cmpx reciprocal();

public:
  // constructors
  Cmpx();
  Cmpx(std::string);
  Cmpx(double re);
  Cmpx(double re, double im);
  Cmpx(const Cmpx& that);     // copy constructor

  // getters
  double real();
  double imag();

  // methods
  Cmpx plus(Cmpx that);
  Cmpx times(Cmpx that);
  Cmpx times(double x);
  Cmpx over(Cmpx that);
  std::string to_string();

  friend Cmpx sum(Cmpx z1, Cmpx z2);
  friend Cmpx product(Cmpx z1, Cmpx z2);
};



