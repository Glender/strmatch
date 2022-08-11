#include <Rcpp.h>
#include <string.h>

using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
unsigned int LCSubStr(std::string X, std::string Y)
{
  // Create a table to store
  // lengths of longest
  // common suffixes of substrings.
  // Note that LCSuff[i][j] contains
  // length of longest common suffix
  // of X[0..i-1] and Y[0..j-1].
  int m = X.length();
  int n = Y.length();

  int LCSuff[m + 1][n + 1];
  int result = 0; // To store length of the
  // longest common substring

  /* Following steps build LCSuff[m+1][n+1] in
   bottom up fashion. */
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      // The first row and first column
      // entries have no logical meaning,
      // they are used only for simplicity
      // of program
      if (i == 0 || j == 0)
        LCSuff[i][j] = 0;

      else if (X[i - 1] == Y[j - 1]) {
        LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
        result = max(result, LCSuff[i][j]);
      }
      else
        LCSuff[i][j] = 0;
    }
  }
  return result;
}


// [[Rcpp::export]]
double LCS_ratio(std::string s1, std::string s2){

  // convert Least Common Substr to a ratio score
  unsigned int edit_distance = LCSubStr(s1, s2);
  unsigned int size_s1 = s1.size(), size_s2 = s2.size();

  // if both s1 and s2 are empty strings, they are identical
  double longest_str = max(size_s1, size_s2);
  if (longest_str == 0){
    return 0.0;
  }
  double ratio = edit_distance / longest_str;

  return ratio;
}


//' Calculate for each string the Longest Common Substring given a set of target strings.
//'
//' @param strings String Vector.
//' @param targets String Vector.
//' @export
// [[Rcpp::export]]
List most_similar_LCS(std::vector< std::string > strings, std::vector< std::string > targets) {

  // create list to store results
  unsigned int num_strings = strings.size();
  List out(num_strings);

  unsigned int num_targets = targets.size();
  for( int i=0; i < num_strings; i++ ) {

    NumericVector v(num_targets);
    for( int j=0; j < num_targets; j++ ) {

      // calculate LCS ratio for each target and store them in v
      v[j] = LCS_ratio(strings[i], targets[j]);
    }
    out[i] = v;
  }
  return out;
}
