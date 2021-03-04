#pragma once 
#include <iostream>
#include <cstring>
using namespace std;struct 
OneWayList//struktura wskazujaca na początek listy
{
struct node *head=nullptr;
};
struct node//pojedyńczy element listy
{
string data="";//dane zawarte w pojedynczym node
struct node *next=nullptr;//wskaznik na nastepny node
};
bool empty(const OneWayList *list);//sprawdzamy czy lista(*list to wskaźnik na liste) jest pusta;
void prepare(struct OneWayList *list);//tworzymy naszą liste przyporządkowywując do OneWayList pierwszą strukture node(*list jest wskaźnikiem na tworzoną liste)
void add(struct OneWayList *list,string data);//dodajemy data do struktury node(list-wskaźnik na liste, - data zapisywany string)
void dump(const OneWayList *list);//wypisujemy listę (-list jest wskaźnikiem na wypisywaną listę)
void clear(OneWayList *list);//usuwamy wszystkie elementy listy(list-wskaźnik na usuwaną liste)
void rclear(node *current);//rekurencyjna funkcja pomocnicza do czyszczenia listy(current-aktualny usuwany node z listy)