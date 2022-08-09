#' Extract data from text given a regular expression.
#'
#' @param string Character.
#' @param pattern A regular expression.
#' @param ... Args passed to gregexpr.
#'
#' @return
#' @export
str_extract <- function(string, pattern, ...) {
  regmatches(string, gregexpr(pattern, string, ...))
}
