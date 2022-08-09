#' @title Counts the number of syllables in a word
#'
#' @param word Character.
#'
#' @return Character.
#' @export
count_syllables <- function(word) {
  word <- tolower(word)
  syllables <- unlist(str_extract(word, pattern = "(^|[^aeuoiy])(?!e$)[aeouiy]", perl = TRUE))
  return(length(syllables))
}
