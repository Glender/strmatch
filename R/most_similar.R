#' Find the most similar string in a target set of strings.
#'
#' @param strings String Vector. Strings that you want to compare with a target.
#' @param targets String Vector. Set of target strings.
#' @param method Edit distance method. Either "dl", "lv", "jw", or "jaro".
#'
#' @return List
#' @export
#'
#' @examples
#' most_similar(c("some", "same"), c("same", "samex", "some"), method = "lv")
most_similar <- function(strings, targets, method = c("dl", "lv", "jw", "jaro")) {

  # this fun is a wrapper around the most_sim functions
  edit_dist <- switch (method,
    "lv" = most_similar_levenstein(strings, targets),
    "jw" = most_similar_jw(strings, targets),
    "jaro" = most_similar_jaro(strings, targets),
    "dl" = most_similar_DL(strings, targets)
  )
  return(edit_dist)
}

