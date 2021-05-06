#pragma once
#include <vector>
#include <utility>
#include <functional>
template <typename T> struct Node { //szablon dla struktury Node, przechowuje stałą dowolnego typu i wskaźnik na następny element 
  Node(const T &val): value(val){}

  const T value;
  Node *next = nullptr;
};


template<typename T> class List { //szalbon dla Listy jednokierunkowej zawierającej wskaźniki na ostatni i pierwszy Node typu T
    public:
    List() = default;

    List(List<T> &&l) { //konstruktor przenoszacy
      head=std::exchange(l.head,nullptr);
      tail=std::exchange(l.tail,nullptr);
    }

    List(const List<T> &l) {//konstruktor kopiujacy 
        Node<T> *current = l.head;

      while(current) {
        this->add(current->value);
        current = current->next;
      }
      
    }

    List& add(const T &toAdd) { //dodawanie elementu typu T na koniec list, tworzony jest tam nowy Node, o zwolnienie pamięci zadba destruktor
    Node<T> *temp = new Node<T>(toAdd);
      if(!head) {
        head = temp;
        tail = head;
      }
      else {
        tail -> next = temp;
        tail = temp;
      }
      return *this;
    }

    bool contains(const T &val) const {//funckja sprawdzajaca czy element T zawiera sie w liscie
      Node<T> *current = head;

      while(current) {
        if(current->value == val) return true; 
        current = current->next;
      }

      return false;
    }

      bool contains (std::function<bool(T)>fun) const {//funckja sprawdzajaca czy dla jakiegos elementu funckja fun zwraca true
      Node<T> *current = head;

      while(current) {
        if(fun(current->value)) return true; 
        current = current->next;
      }

      return false;
    }

       List& collect (std::function<bool(T)>fun) const {//funkcja zwracajaca Liste wszystkich elementów dla których funckja fun zwraca true
      Node<T> *current = head;
      List<T> *list=new List<T>;
      while(current) {
        if(fun(current->value)) list->add(current->value);
        current = current->next;
      }

      return *list;
    }



    Node<T>* getHead() const {  //getter dla head
      return head;
    }

    Node<T>* pop() { //funckja usuwa i zwraca ostatni element listy
          Node<T> *current = head;
          Node<T> *temp = tail;

      while(current) {
        if(current->next == tail) {
          tail=current;
          tail->next=nullptr;
        } 
        current = current->next;
      }

      return temp;
    }

    ~List() { // destruktor
          Node<T> *current = head;
          while(current != tail) {
            current = current-> next;
            delete head;
            head = current;
          }
          delete tail;
    }


    private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
};

template <typename T> std::ostream &operator<<(std::ostream &stream,const List<T> &list) {//operator wypisujący dla listy, przyjmuje stała referencje
     Node<T> *current = list.getHead();

      while(current) {
        stream<<current->value<<" ";
        current = current->next;
      }
  return stream;
}



