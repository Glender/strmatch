#' Extract data from text given a regular expression.
#'
#' @param string Character.
#' @param pattern A regular expression.
#'
#' @return
#' @export
str_extract <- function(string, pattern) {
  regmatches(string, gregexpr(pattern, string))
}


#' Extract sentences from text.
#'
#' @param text Character of length one.
#'
#' @return CharacterVector.
#' @export
#'
#' @examples
#' get_sentences("Hello world! My name is Mike. Why so serious?")
get_sentences <- function(text) {
  return(unlist(str_extract(text, "\\b[A-Z](?:[^\\.!?]|\\.\ d)*[\\.!?]")))
}


#' Count sentences
#'
#' @param text Character
#'
#' @return IntegerVector.
#' @export
#'
#' @examples
#' count_sentences("Hello world! My name is Mike. Why so serious?")
count_sentences <- function(text) {
  nr_of_sentences <- length(get_sentences(text))
  return(nr_of_sentences)
}
