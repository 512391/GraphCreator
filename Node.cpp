#include"Node.h"

Node::Node(char Name)
{
  Node::name = Name;
}

Node::~Node()
{
  for (map<Node*, int>::iterator it = nodeToEdge.begin(); it != nodeToEdge.end(); ++it) {
    it->first->RemoveNode(this);
    cout << it->first->name << endl;
  }
}

void Node::AddNode(Node* node, int length)
{
  nodeToEdge[node] = length;
}

void Node::RemoveNode(Node* node)
{
  nodeToEdge.erase(node);
}

map<Node*, int> Node::getAdjacencyInfo()
{
  for (map<Node*, int>::iterator it = nodeToEdge.begin(); it != nodeToEdge.end(); ++it) {
    cout << it->first->name << ", Length: " << it->second << endl;
  }
  return nodeToEdge;
}
