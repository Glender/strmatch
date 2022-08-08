#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
std::vector< std::string > cpp_str_sort( std::vector< std::string > strings ) {

  int len = strings.size();

  for( int i=0; i < len; i++ ) {
    std::sort( strings[i].begin(), strings[i].end() );
  }

  return strings;
}
