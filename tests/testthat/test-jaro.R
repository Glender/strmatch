test_that("Jaro functions work", {

  observed <- most_similar_jaro(c("some", "same"), c("same", "samex", "some"))
  expected <- list(
    c(0.833333333333333, 0.783333333333333, 1),
    c(1, 0.933333333333333, 0.833333333333333)
  )
  expect_equal(observed, expected)
})
