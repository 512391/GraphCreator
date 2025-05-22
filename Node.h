#include<iostream>
#include <map>

using namespace std;

class Node
{  
 public:
  char name;
  map<Node*, int> nodeToEdge;
  Node(char Name);
  ~Node();
  void AddNode(Node* node, int length);
  void RemoveNode(Node* node);
  map<Node*, int> getAdjacencyInfo();
};
