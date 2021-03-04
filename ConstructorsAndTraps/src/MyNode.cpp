#include "MyNode.h"
MyNode::MyNode(int a):data(a),next(nullptr){}
MyNode::MyNode():data(0),next(nullptr){}
int MyNode::val(){
  return data;
}