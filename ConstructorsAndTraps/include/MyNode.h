class MyNode{
  public: 
    MyNode(int a);
    MyNode();
    int val();
    
  private:
    friend class MyList;
    MyNode *next;
    int data;
    
};