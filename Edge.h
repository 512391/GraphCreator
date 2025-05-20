#include<iostream>
#include"Node.h"

class Edge
{
 private:
  int length;
  Node** nodes;
  
 public:
  Edge(int l);
  int getLength();
  void changeLength(int l);
  void changeNode(Node* oldNode, Node* newNode);
}
