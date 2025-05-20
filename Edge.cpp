#include"Edge.h"

Edge::Edge(int l, Node** nodes)
{
  Edge::length = l;
  Edge::nodes = nodes;
}

int Edge::getLength()
{
  return Edge::length;
}

void Edge::changeLength(int l)
{
  Edge::length = l;
}

void Edge::changeNode(Node* node, Node* oldNode, Node* newNode)
{
  node->RemoveNode(oldNode);
  node->AddNode(newNode, this);
}
