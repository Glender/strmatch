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


#' Count the number of sentences in text.
#'
#' @param text CharacterVector.
#'
#' @return
#' @export
count_sentences <- function(text){
  return(length(get_sentences(text)))
}
