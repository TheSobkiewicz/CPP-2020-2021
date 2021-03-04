#include "lab05.h"
void prepare(struct OneWayList *list)
{
  list->head=new struct node;
}
void add(struct OneWayList *list,string data)
{
struct node *cur=list->head;
while(cur->data!="")
{
  if(cur->next)cur=cur->next;//sprawdzamy czy istnieje następny element, a jeśli nie to go tworzymy
  else 
  {
    cur->next=new node;
    cur=cur->next;
    break;
  }
}
cur->data=data;//przypisujemy wartość data
}
bool empty(const OneWayList *list)
{
  if(list->head)return 0; else return 1;
}
void dump(const struct OneWayList *list)
{
 struct node *cur=list->head;
 if(empty(list))return;
 
 while(cur->next)
 {
   cout<<cur->data<<" ";
   cur=cur->next;
 }
 cout<<cur->data<<" ";
 cout<<endl;
}
void clear(OneWayList *list)
{
  if(empty(list))return;
  rclear(list->head);
  list->head=nullptr;
  list=nullptr;
}
void rclear(node *current)
{
 if(current->next)rclear(current->next);
 delete(current);
}