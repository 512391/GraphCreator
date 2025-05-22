#include"Graph.h"

Graph::Graph()
{
  nodes = new Node*[100];
  currentIndex = 0;
}

void Graph::addNode(char a)
{
  nodes[currentIndex] = new Node(a);
  currentIndex++;
}

void Graph::connectNodes(char a, char b, int length)
{
  Node* aNode = nullptr;
  Node* bNode = nullptr;

  for(int i = 0; i < currentIndex; i++)
    {
      if(nodes[i] != nullptr)
	{
      if(nodes[i]->name == a)
	{
	  aNode = nodes[i];
	}
      else if(nodes[i]->name == b)
	{
	  bNode = nodes[i];
	}
	}
    }
  
  if(aNode == nullptr || bNode == nullptr)
    {
      cout << "Could not find nodes" << endl;
    }

  aNode->AddNode(bNode, length);
  bNode->AddNode(aNode, length);
}

void Graph::disconnectNodes(char a, char b)
{
   Node* aNode = nullptr;
  Node* bNode = nullptr;

  for(int i = 0; i < currentIndex; i++)
    {
      if(nodes[i] != nullptr)
	{
      if(nodes[i]->name == a)
        {
          aNode = nodes[i];
        }
      else if(nodes[i]->name == b)
        {
          bNode = nodes[i];
        }
	}
    }

  if(aNode == nullptr || bNode == nullptr)
    {
      cout << "Could not find nodes" << endl;
    }

  aNode->RemoveNode(bNode);
  bNode->RemoveNode(aNode);
}

void Graph::deleteNode(char a)
{
  for(int i = 0; i < currentIndex; i++)
    {
      if(nodes[i] != nullptr && nodes[i]->name == a)
	{
	  delete nodes[i];
	  nodes[i] = nullptr;
	  return;
	}
    }
}

void Graph::printNodeMap(char a)
{
  for(int i = 0; i < currentIndex; i++)
    {
      if(nodes[i] != nullptr && nodes[i]->name == a)
        {
          nodes[i]->getAdjacencyInfo();
          return;
        }
    }
}

int Graph::shortestPath(char a, char b)
{
   Node* aNode = nullptr;
  Node* bNode = nullptr;

  for(int i = 0; i < currentIndex; i++)
    {
      if(nodes[i] != nullptr)
	{
      if(nodes[i]->name == a)
        {
          aNode = nodes[i];
        }
      else if(nodes[i]->name == b)
        {
          bNode = nodes[i];
        }
	}
    }

  if(aNode == nullptr || bNode == nullptr)
    {
      cout << "Could not find nodes" << endl;
    }

  
  
  return 0;
}
