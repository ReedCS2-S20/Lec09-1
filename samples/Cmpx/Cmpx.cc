#include <iostream>
#include <cmath>
#include <string>
#include <regex>
#include "Cmpx.hh"

const double Cmpx::kPi = std::atan(1.0)*4.0;
const double Cmpx::kEpsilon = 0.000001;

bool Cmpx::parse(std::string s, double& rp, double& ip) {

  rp = 0.0;
  ip = 0.0;

  // Search through the string using regular expressions, seeking 
  // the pattern expected for a complex number constant.
  //
  std::regex real_part("((\\s+)?(\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");
  std::regex pure_imag("((\\s+)?(\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?(\\s+)?i(\\s+)?");
  std::regex whitespace("(\\s+)?");
  // Attempts to match as, essentially, " rp + ip i " where rp and ip
  // look like double values. If, at any point, the string doesn't have
  // that format, returns the complex representation of zero.

  std::smatch mtch;
  bool has_real = std::regex_search(s, mtch, real_part);
  bool starts_w_real = mtch.position() == 0;
  if (starts_w_real) {

    // Grab the real part at the front.
    rp = std::stod(mtch.str());
    // Remove that part from the string.
    s = mtch.suffix();

    bool is_empty = s.length() == 0;
    bool has_whitespace = std::regex_search(s, mtch, whitespace);
    bool all_parsed = is_empty || (has_whitespace && (mtch.length() == s.length()));
    if (all_parsed) {
      return true;
    } else {
      bool has_imag = std::regex_search(s, mtch, pure_imag);
      bool is_pure_imag = has_imag && (mtch.length() == s.length());
      if (is_pure_imag) {
	std::regex_search(s, mtch, real_part);
	ip = std::stod(mtch.str());
	return true;
      }
    }
  }

  // Saw problem in the string.
  rp = 0.0;
  ip = 0.0;

  return false;
} 

Cmpx::Cmpx() :
  re {0.0},
  im {0.0}
{ }

Cmpx::Cmpx(double r) :
  re {r},
  im {0.0}
{ }

Cmpx::Cmpx(double r, double i) :  
  re {r},
  im {i}
{ }

Cmpx::Cmpx(std::string s) {
  parse(s,re,im);
  // Should maybe check the parse flag, raise an error?
}

// This is a "copy constructor" which we'll discuss soon.                                                                                 
Cmpx::Cmpx(const Cmpx& that) :
  re {that.re},
  im {that.im}
{ }

double Cmpx::real() {
  return re;
}

double Cmpx::imag() {
  return im;
}

Cmpx Cmpx::conjugate() {
  return Cmpx {re,-im};
}
  
double Cmpx::modulus2() {
  return times(conjugate()).re;
}

Cmpx Cmpx::reciprocal() {
  return conjugate().times(1.0 / modulus2());
}

Cmpx Cmpx::plus(Cmpx that) {
  return Cmpx {re + that.re, im + that.im};
}
  
Cmpx Cmpx::times(Cmpx that) {
  double rp = re*that.re - im*that.im;
  double ip = im*that.re + that.im*re;
  return Cmpx {rp,ip};
}

Cmpx Cmpx::times(double x) {
  return Cmpx {x*re,x*im};
}

Cmpx Cmpx::over(Cmpx that) {
  return times(that.reciprocal());
}

std::string Cmpx::to_string() {
  if (std::abs(im) < kEpsilon) {
    // Just the real part.
    return std::to_string(re);
  } else if (std::abs(re) < kEpsilon) {
    // Just the imaginary part.
    return std::to_string(im) + "i";
  } else {
    // Maybe don't include the "+".
    if (im < 0.0) {
      return std::to_string(re) + std::to_string(im) + "i";
    } else {
      return std::to_string(re) + "+" + std::to_string(im) + "i";
    }
  }    
}  

Cmpx sum(Cmpx z1, Cmpx z2) {
  return z1.plus(z2);
}

Cmpx product(Cmpx z1, Cmpx z2) {
  return z1.times(z2);
}
