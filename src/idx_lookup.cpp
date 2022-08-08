#include <Rcpp.h>
using namespace Rcpp;

// https://stackoverflow.com/questions/59055902/find-index-of-all-max-min-values-in-vector-in-rcpp


//' Find the max indices given a list of edit distances.
//'
//' Function is designed to find the max indices in a list of numeric vectors.
//' The numeric vectors consist of edit distances, numeric values.
//'
//' @param list_of_edit_distances A list of numeric vectors.
//' @return Integer Vector
//' @export
//'
// [[Rcpp::export]]
IntegerVector idx_lookup(List list_of_edit_distances) {

  int len_list = list_of_edit_distances.length();
  IntegerVector max_idx(len_list);
  for(int i=0; i < len_list; i++){

    // convert to vector
    NumericVector v = list_of_edit_distances[i];

    // R starts counting from 1, not 0
    // thus + 1
    max_idx[i] = which_max(v) + 1;
  }
  return max_idx;
}
