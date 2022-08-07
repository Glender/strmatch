test_that("Jaro Winkler functions work", {

  observed <- most_similar_jw(c("some", "same"), c("same", "samex", "some"))
  expected <- list(
    c(0.883333333333333, 0.848333333333333, 1),
    c(1, 0.96, 0.883333333333333)
  )
  expect_equal(observed, expected)
})
