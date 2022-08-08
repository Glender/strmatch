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


#' Count the number of sentences.
#'
#' @param sentences CharacterVector
#'
#' @return
#' @export
count_sentences <- function(sentences){
  return(length(sentences))
}
