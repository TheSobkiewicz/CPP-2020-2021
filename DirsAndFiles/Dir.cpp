#include "Dir.h"
void Dir::operator += (File *f) {
  f->space(spaces);
   vec.push_back(f);
}  

ostream &Dir::print(std::ostream &out)const {
   for(int i=0;i<spaces;i++) {
    out<<" ";
  }
  out<<name<<"\n";
  for(auto i:vec ) {
    i->print(out);
  }
  return out;
}
void Dir::add( File *f) {
  *this += f;
}

Dir * Dir::findDir(string n)const{
  for (auto el: vec){
    if  (n==el->getName()){
      return dynamic_cast<Dir*> (el);
    }
    if(dynamic_cast<Dir*>(el) != nullptr){
      return dynamic_cast<Dir*>(el)->findDir(n);
    }
  }
  return nullptr;
}
File* Dir::get(std::string n) {
 for (auto el: vec){
    if(el->getName()==n) return el;
    else if (el->get(n))
      return el->get(n);
}
return nullptr;
}

Dir::~Dir(){
  cout<<"Deleting Dir: " << name << endl;
  for (auto el: vec){
    cout<<"About to delete "<< el->getName() << endl;
      delete el;
  }
}
