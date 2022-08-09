#include <Rcpp.h>
#include "read_text.h"

using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
std::string read_dictionary() {

  std::string res = read_text("inst/extdata/dictionary.txt");

  return res;
}

