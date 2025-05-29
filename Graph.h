#include"Node.h"
#include<iostream>

using namespace std;

class Graph
{
 public:
  Node** nodes;
  int currentIndex;
  int amountOfNodes;
  Graph();
  void addNode(char a);
  void connectNodes(char a, char b, int length);
  void disconnectNodes(char a, char b);
  void deleteNode(char a);
  void printNodeMap(char a);
  int shortestPath(char a, char b);
};
