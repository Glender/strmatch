#' Finds words in a sentence.
#'
#' @param text Character
#'
#' @return Character Vector.
#' @export
get_words <- function(text) {
  words <- unlist(str_extract(text, pattern = "\\b[a-zA-Z\\\\'\\\\-]+\\b"))
  return(tolower(words))
}


#' Counts the number of words in text.
#'
#' @param text Character.
#'
#' @return
#' @export
count_words <- function(text) {
  return(length(get_words(text)))
}
