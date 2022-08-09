#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

using std::cout; using std::cerr;
using std::endl; using std::string;

using namespace std;

// [[Rcpp::export]]
std::string read_text(const std::string& path) {

  struct stat sb{};
  std::string res;

  FILE* input_file = fopen(path.c_str(), "r");
  if (input_file == nullptr) {
    perror("fopen");
  }

  stat(path.c_str(), &sb);
  res.resize(sb.st_size);

  fread(const_cast<char*>(res.data()), sb.st_size, 1, input_file);
  fclose(input_file);

  return res;
}
