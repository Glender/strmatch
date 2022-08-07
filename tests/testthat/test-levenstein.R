# check levenstein functions
test_that("Levenstein functions work", {

  observed <- most_similar_levenstein(c("some", "same"), c("same", "samex", "some"))
  expected <- list(c(0.75, 0.6, 1), c(1, 0.8, 0.75))

  expect_equal(observed, expected)

})
