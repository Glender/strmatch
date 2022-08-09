#' Quantify the complexity of text with the Gunning Fox Index.
#'
#' @param text Character.
#'
#' @return
#' @export
gunning_fog <- function(text) {

  sentences <- get_sentences(text)
  words <- get_words(text)
  complex_words <- filter_complex_words(words)
  len_words <- length(words)

  gunning_fox_index <-
    0.4 * ((len_words / length(sentences)) + (100 * (length(complex_words) / len_words)))

  return(gunning_fox_index)
}
