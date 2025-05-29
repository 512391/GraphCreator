#include<iostream>
#include <map>

using namespace std;

class Node
{  
 public:
  //Name
  char name;
  //a map of all the connections
  map<Node*, int> nodeToEdge;
  //initialize stuff
  Node(char Name);
  //when deleted it disconnects itself
  ~Node();
  //adds a node to is conncetions
  void AddNode(Node* node, int length);
  //removes a node from its connections
  void RemoveNode(Node* node);
  //gets the node to edge
  map<Node*, int> getAdjacencyInfo();
};
