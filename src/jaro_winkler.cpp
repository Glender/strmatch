#include <Rcpp.h>
#include <string>

using namespace Rcpp;

//' @export
// [[Rcpp::export]]
double jaro_winkler_distance(std::string str1, std::string str2) {

  size_t len1 = str1.size();
  size_t len2 = str2.size();
  if (len1 < len2) {
    std::swap(str1, str2);
    std::swap(len1, len2);
  }
  if (len2 == 0)
    return len1 == 0 ? 0.0 : 1.0;

  size_t delta = std::max(size_t(1), len1/2) - 1;
  std::vector<bool> flag(len2, false);
  std::vector<char> ch1_match;
  ch1_match.reserve(len1);

  for (size_t idx1 = 0; idx1 < len1; ++idx1) {
    char ch1 = str1[idx1];
    for (size_t idx2 = 0; idx2 < len2; ++idx2) {
      char ch2 = str2[idx2];
      if (idx2 <= idx1 + delta && idx2 + delta >= idx1
            && ch1 == ch2 && !flag[idx2]) {
        flag[idx2] = true;
        ch1_match.push_back(ch1);
        break;
      }
    }
  }
  size_t matches = ch1_match.size();
  if (matches == 0)
    return 0.0;

  size_t transpositions = 0;
  for (size_t idx1 = 0, idx2 = 0; idx2 < len2; ++idx2) {
    if (flag[idx2]) {
      if (str2[idx2] != ch1_match[idx1])
        ++transpositions;
      ++idx1;
    }
  }

  double m = matches;
  double jaro = (m/len1 + m/len2 + (m - transpositions/2.0)/m)/3.0;

  size_t common_prefix = 0;
  len2 = std::min(size_t(4), len2);

  for (size_t i = 0; i < len2; ++i) {
    if (str1[i] == str2[i])
      ++common_prefix;
  }
  return (jaro + common_prefix * 0.1 * (1.0 - jaro));
}


//' Calculate for each string the Jaro Winkler Distance given a set of target strings.
//'
//' @param strings String Vector.
//' @param targets String Vector.
//' @export
// [[Rcpp::export]]
List most_similar_jw(std::vector< std::string > strings, std::vector< std::string > targets) {

  // create list to store results
  unsigned int num_strings = strings.size();
  List out(num_strings);

  unsigned int num_targets = targets.size();
  for( int i=0; i < num_strings; i++ ) {

    NumericVector v(num_targets);
    for( int j=0; j < num_targets; j++ ) {

      // calculate  JWD for each target and store them in v
      v[j] = jaro_winkler_distance(strings[i], targets[j]);
    }
    out[i] = v;
  }
  return out;
}
