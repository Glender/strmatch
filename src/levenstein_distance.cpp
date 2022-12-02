#include <Rcpp.h>
#include <string>
#include <algorithm>
//#include "upper.h"

using namespace Rcpp;
using namespace std;


//' @export
// [[Rcpp::export]]
unsigned int levenstein_distance(const std::string& s1, const std::string& s2)
{

  const std::size_t len1 = s1.size(), len2 = s2.size();
  std::vector<std::vector<unsigned int>> d(len1 + 1, std::vector<unsigned int>(len2 + 1));

  d[0][0] = 0;
  for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
  for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

  for(unsigned int i = 1; i <= len1; ++i)
    for(unsigned int j = 1; j <= len2; ++j)
      // note that std::min({arg1, arg2, arg3}) works only in C++11,
      // for C++98 use std::min(std::min(arg1, arg2), arg3)
      d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });
  return d[len1][len2];
}


//' @export
// [[Rcpp::export]]
double levenstein_ratio(std::string s1, std::string s2){

  // convert Levenstein Distance to a ratio score
  unsigned int edit_distance = levenstein_distance(s1, s2);
  unsigned int size_s1 = s1.size(), size_s2 = s2.size();

  // if both s1 and s2 are empty strings, they are identical
  double longest_str = max(size_s1, size_s2);
  if (longest_str == 0){
    return 0.0;
  }
  double ratio = 1 - (edit_distance / longest_str);

  return ratio;
}


//' Calculate for each string the normalized Levenstein Distance given a set of target strings.
//'
//' @param strings String Vector.
//' @param targets String Vector.
//' @export
// [[Rcpp::export]]
List most_similar_levenstein(std::vector< std::string > strings, std::vector< std::string > targets) {

  // create list to store results
  unsigned int num_strings = strings.size();
  List out(num_strings);

  unsigned int num_targets = targets.size();
  for( int i=0; i < num_strings; i++ ) {

    NumericVector v(num_targets);
    for( int j=0; j < num_targets; j++ ) {

      // calculate LD ratio for each target and store them in v
      v[j] = levenstein_ratio(strings[i], targets[j]);
    }
    out[i] = v;
  }
  return out;
}
