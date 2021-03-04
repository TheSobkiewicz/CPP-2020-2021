#include "lab05.h"
#include "lab05.h"
#include <cstring>
#include <iostream>

const int kBufferSize = 500;

int main() {
    std::cout << "\t\t\tList #1" << std::endl;
    OneWayList testList;
    prepare(&testList);
    
    //////////////////////////////////////////////
    char buffer[kBufferSize];
    strcpy(buffer, "This");
    add(&testList, buffer);
    strcpy(buffer, "is");
    add(&testList, buffer);
    add(&testList, "test");
    add(&testList, "message");

     const OneWayList* ptr2list = &testList;

     std::cout << ptr2list->head->data << std::endl;
     std::cout << ptr2list->head->next->data << std::endl;
  
    ////////////////////////////////////////////////
    std::cout << ">> Is the list empty? " << std::boolalpha << empty(ptr2list) << std::endl;
     std::cout << ">> Let's print it:" << std::endl;
     dump(ptr2list);

    // ////////////////////////////////////////////////
    std::cout << "\n\n\t\t\tList #2" << std::endl;
    OneWayList drugaLista;
    prepare(&drugaLista);
    strcpy(buffer, "Today's task");
    add(&drugaLista, buffer);
    strcpy(buffer, "was incredibly easy xD");
    add(&drugaLista, buffer);
    dump(&drugaLista);

    // ////////////////////////////////////////////////
    std::cout << "\n\n\t\t\tCleaning" << std::endl;
    clear(&testList);
    std::cout << ">> Is the list empty? " 
              << std::boolalpha << empty(&testList) << std::endl;
              
    std::cout << ">> What happens if an empty list is dumped?" << std::endl;
    dump(ptr2list);
    
    ////////////////////////////////////////////////
    dump(&drugaLista);
    clear(&drugaLista);
    clear(&drugaLista);

    std::cout << std::endl;
}

/* // Output:
            List #1
This
is
>> Is the list empty? false
>> Let's print it:
This is test message 

            List #2
Today's task was incredibly easy xD 

            Cleaning
>> Is the list empty? true
>> What happens if an empty list is dumped?
Today's task was incredibly easy xD
*/
