#include <Rcpp.h>
#include <string.h>

using namespace Rcpp;
using namespace std;


// [[Rcpp::export]]
int damerau_levenshtein(const std::string A, const std::string B)
{

  int m = A.length();
  int n = B.length();

  int table[m+1][n+1];

  int cost;
  int counter=0;

  for(int i=0; i<=m; i++)
  {
    for(int j=0; j<=n; j++)
    {
      table[i][j]=0;
    }
  }
  for(int i=0; i<=m; i++)
  {
    table[i][0]= i;
  }
  for(int j=0; j<=n; j++)
  {
    table[0][j]= j;
  }

  for(int j=1; j<=n; j++)
  {
    for(int i=1; i<=m; i++)
    {
      counter++;
      if(A[i-1]==B[j-1])
      {
        cost=0;
      }
      else
      {
        cost=1;
      }

      int minimum, deletion, substitution, insertion;

      deletion = table[i-1][j]+1;
      insertion = table[i][j-1]+1;
      substitution = table[i-1][j-1]+cost;

      minimum = deletion;
      if(insertion<minimum)
      {
        minimum= insertion;
      }
      else if(substitution<minimum)
      {
        minimum= substitution;
      }

      table[i][j]= minimum;
      if((i>1 and j>1))
      {
        if((A[i-1]==B[j-2]) and (A[i-2]==B[j-1]))
        {
          int transposition= table[i-2][j-2]+cost;
          if(table[i][j]>transposition)
          {
            table[i][j]= transposition;
          }
        }
      }
    }
  }
  return table[m][n];
}


// [[Rcpp::export]]
double damerau_levenshtein_ratio(const std::string s1, const std::string s2){

  // convert DL Distance to a ratio score
  unsigned int edit_distance = damerau_levenshtein(s1, s2);
  unsigned int size_s1 = s1.size(), size_s2 = s2.size();

  // if both s1 and s2 are empty strings, they are identical
  double longest_str = max(size_s1, size_s2);
  if (longest_str == 0){
    return 0.0;
  }
  double ratio = 1 - (edit_distance / longest_str);

  return ratio;
}

//' Calculate for each string the normalized Damerau-Levenshtein Distance given a set of target strings.
//'
//' @param strings String Vector.
//' @param targets String Vector.
//' @export
// [[Rcpp::export]]
List most_similar_DL(const std::vector< std::string > strings, const std::vector< std::string > targets) {

  // create list to store results
  unsigned int num_strings = strings.size();
  List out(num_strings);

  unsigned int num_targets = targets.size();
  for( int i=0; i < num_strings; i++ ) {

    NumericVector v(num_targets);
    for( int j=0; j < num_targets; j++ ) {

      // calculate LD ratio for each target and store them in v
      v[j] = damerau_levenshtein_ratio(strings[i], targets[j]);
    }
    out[i] = v;
  }
  return out;
}


