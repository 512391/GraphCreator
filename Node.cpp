#include"Node.h"

//constructor for name
Node::Node(char Name)
{
  Node::name = Name;
}
//when deleted it removes itself from all connected nodes connections
Node::~Node()
{
  for (map<Node*, int>::iterator it = nodeToEdge.begin(); it != nodeToEdge.end(); ++it) {
    it->first->RemoveNode(this);
  }
}

//adds a node to its connections
void Node::AddNode(Node* node, int length)
{
  nodeToEdge[node] = length;
}

//removes a node from its connections
void Node::RemoveNode(Node* node)
{
  nodeToEdge.erase(node);
}

//returns node to edge
map<Node*, int> Node::getAdjacencyInfo()
{
  return nodeToEdge;
}
