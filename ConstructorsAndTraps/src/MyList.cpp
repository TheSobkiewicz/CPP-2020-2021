#include "MyList.h"
#include <utility>
MyList::MyList():lsize( 0 ),head(nullptr),tail(nullptr){std::cout<<"KONST: Domyślny\n";}

MyList::MyList(std::initializer_list <int> list){
  lsize=0;
  std::cout<<"KONST: std::initializer_list\n";
  head=nullptr;
  tail=nullptr;
  for(auto i=list.begin(); i<list.end();i++){
    add(*i);
  }

}
MyList::MyList(int size):MyList(){
  lsize=0;
  for(int i=0;i<size;i++){
   add(i);
  }
  std::cout<<"KONST: Jednoargumentowy\n";
}

bool MyList::empty()const{
  if(head) return  false;
  else return true;
}

int MyList::size()const{
  return lsize;
}

MyList::~MyList(){
  std::cout<<"DESTRUKTOR (rozmiar = "<<lsize<<")\n";
  if(head)cleaner(head);
  head=nullptr;
  tail=head;
  lsize=0;
}

void MyList::cleaner(MyNode *toClean){
  if(toClean->next)cleaner(toClean->next);
  delete toClean;
}

void MyList::add(int data){
  lsize++;
  if(head){
    tail->next=new MyNode(data);
    tail=tail->next;
  }
  else{
    head=new MyNode(data);
    tail=head;
  }
}
void MyList::clear(){
    if(head)cleaner(head);
      head=nullptr;
      tail=head;
      lsize=0;
}

void MyList::print()const{
  std::cout<<"[";
  MyNode *cur=head;
  for(int i=0;i<lsize-1;i++){
    std::cout<<cur->data<<", ";
    cur=cur->next;
  }
  if(tail)std::cout<<tail->data;
std::cout<<"]\n";
}

MyList::MyList(const MyList &org):MyList(){
  MyNode *cur=org.head;
  for(int i=0;i<org.lsize;i++){
      add(cur->data);
      cur=cur->next;
  }
}

MyList::MyList( MyList &&org):MyList(){
    lsize=org.lsize;
    head=std::exchange(org.head,nullptr);
    tail=std::exchange(org.tail,nullptr);
    org.lsize=0;
}
MyList::MyList(int (*f)(MyNode*),int size){
std::cout<<"KONST: funkcja generujaca\n";
head=nullptr;
tail=nullptr;
for(int i=0;i<size;i++)add(f(tail));
}