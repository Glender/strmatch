#' Examines if a word is complex, where complexity is
#' defined by the number of syllables in a word (n).
#'
#' @param word Character.
#' @param n int. Number of syllables in a word before a word counts as complex.
#'
#' @return Logical
is_complex_word <- function(word, n = 3) {
  return(count_syllables(word) >= n)
}


#' Examines if a word is complex, that is, when it
#' contains three or more syllables.
#'
#' @param words Character Vector.
#'
#' @return
#' @export
filter_complex_words <- function(words) {

  # filter complex words
  complex_words <- sapply(words, is_complex_word)
  return(words[complex_words])
}

