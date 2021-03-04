#include "MyLine.h"
MyLine::MyLine(std::string lin){
  line=lin;
}
MyLine::MyLine(const char *lin){
  line=lin;
}
MyLine::MyLine():line(""){}

MyLine MyLine::operator=(const char *data ){
return MyLine(data);
}
void convertAndPrint(MyLine a){
  std::cout<<a.line<<"\n";
}
