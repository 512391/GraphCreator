#include"Node.h"
#include<iostream>

using namespace std;

class Graph
{
 public:
  //array of all the nodes
  Node** nodes;
  //current index in the nodes array
  int currentIndex;
  //amount of nodes
  int amountOfNodes;
  //initialize vars
  Graph();
  //add a node
  void addNode(char a);
  //connects 2 nodes
  void connectNodes(char a, char b, int length);
  //disconnects 2 nodes
  void disconnectNodes(char a, char b);
  //deletes a node
  void deleteNode(char a);
  //returns the shortest path between 2 nodes
  int shortestPath(char a, char b);
};
