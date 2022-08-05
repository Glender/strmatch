#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
List bigram_cpp( std::vector< std::string > strings) {

  // create list of bigrams
  int num_strings = strings.size();

  List out(num_strings);
  for( int i=0; i < num_strings; i++ ) {

    int num_substr = strings[i].length();
    std::vector< std::string > tmp;

    for( int j=0; j < num_substr - 1; j++ ) {
      tmp.push_back( strings[i].substr( j, 2) );
    }
    out[i] = tmp;
  }
  return out;
}
