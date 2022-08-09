#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <Rcpp.h>

using namespace Rcpp;
using namespace std;

 /*
 All these function are useful in Reading file. erase_delime function is used to erase delimiter
 such space' ' ,new line ('\n'),tab ...


//[[Rcpp::export]]
std::string read_txt(std::string path){
  std::ifstream in(path.c_str());//connect with file into in(STDIN)
  std::stringstream ss;
  ss<<in.rdbuf();                // scan file or reading buffer
  return ss.str();
}


//[[Rcpp::export]]
std::string read_txts(std::string path){
  std::ifstream in(path.c_str());
  std::string contents;
  in.seekg(0,std::ios::end); // scan all file from the first to the end
  contents.resize(in.tellg());// adjust the size of the resulting string with the file size(tellg function)
  in.seekg(0,std::ios::beg);  //return to the beginning
  in.read(&contents[0],contents.size());// each value of the  in pointer will copied into contents
  in.close();                          // colsing the in
  return contents;
}


//[[Rcpp::export]]
std::string erase_delime(std::string A,char p){
  A.erase(std::remove(A.begin(),A.end(),p),A.end()-1);
  return(A);
}

*/

/*** R
###*******************choose file to read************************####
con<-utils::choose.files()
system.time(FR<-readLines(con))    # fast reading with R
system.time(Fcpp1<-read_txt(con))  #contents Line delimiter
system.time(Fcpp2<-read_txts(con)) #contents Line delimiter and faster then read_txt
#one string without \n and in lower case
system.time(Fcpp3<-erase_delime(Fcpp2,'\n')) # there also' ' and '\b'.

*/
