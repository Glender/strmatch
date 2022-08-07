.onUnload <- function (libpath) {
  library.dynam.unload("strmatch", libpath)
}
