#include<iostream>
#include <map>
#include <vector>
#include"Edge.h"
using namespace std;

class Node
{
  struct adjacencyInfo
  {
    vector<Node*> connectedNodes;
    map<Node*, Edge*> nodeToEdge;
  };
  
 private:
  adjacencyInfo* info;
  char name;

 public:
  Node(char Name);
  void AddNode(Node* node, int length);
  void AddNode(Node* node, Edge* edge);
  void RemoveNode(Node* node);
  adjacencyInfo getAdjacencyInfo();
};
