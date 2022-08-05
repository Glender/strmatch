#include <Rcpp.h>
#include <string>
#include <algorithm>

using namespace Rcpp;
using namespace std;


// [[Rcpp::export]]
std::string to_uppercase(std::string str) {

  // convert string to back to lower case
  std::for_each(str.begin(), str.end(), [](char & c) {
    c = ::toupper(c);
  });

  return str;
}


// [[Rcpp::export]]
std::string to_lowercase(std::string str) {

  // convert string to back to lower case
  std::for_each(str.begin(), str.end(), [](char & c) {
    c = ::tolower(c);
  });

  return str;
}

