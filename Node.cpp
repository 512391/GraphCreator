#include"Node.h"

Node::Node(char Name)
{
  Node::info = new adjacencyInfo();
  Node::name = Name;
}

void Node::AddNode(Node* node, int length)
{
  info->connectedNodes.push_back(node);
  Node** nodes = {this, node};
  info->nodeToEdge[node] = new Edge(length, nodes);
}

void Node::AddNode(Node* node, Edge* edge)
{
  info->connectedNodes.push_back(node);
  info->nodeToEdge[node] = edge;
}

void Node::RemoveNode(Node* node)
{
  int i = 0;

  info->nodeToEdge.erase(node);
  
  for(Node* val : info->connectedNodes)
    {
      if(val == node)
	{
	  info->connectedNodes.erase(info->connectedNodes.begin()+i);
	  return;
	}
      i++;
    }
}

adjacencyInfo Node::getAdjacencyInfo()
{
  return info;
}
