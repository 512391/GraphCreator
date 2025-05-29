#include"Graph.h"

Graph::Graph()
{
  nodes = new Node*[100];
  currentIndex = 0;
  amountOfNodes = 0;
}

void Graph::addNode(char a)
{
  nodes[currentIndex] = new Node(a);
  currentIndex++;
  amountOfNodes++;
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
	  amountOfNodes--;
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

  int visInd = 0;
  Node** visited = new Node*[amountOfNodes];
  Node** unvisited = new Node*[amountOfNodes];

  map<Node*, int> shortestDist = {};
  map<Node*, Node*> previousNode = {};

  int j = 0;
  for(int i = 0; i <= currentIndex; i++)
    {
      if(nodes[i] != nullptr)
	{
	  if(nodes[i] != aNode)
	    {
	      unvisited[j] = nodes[i];
	      j++;
	    }
	  shortestDist[nodes[i]] = 1000000000;
	  previousNode[nodes[i]] = nullptr;
	}
    }
  shortestDist[aNode] = 0;
  
  Node* currentNode = aNode;
  
  while(true)
    {
      cout << "CurrentNode: " << currentNode->name << endl;
      int lowestUnvisitedNodeDist = 100000000;
      for(map<Node*, int>::iterator it = currentNode->getAdjacencyInfo().begin(); it != currentNode->getAdjacencyInfo().end(); ++it){
	bool isUnvisited = true;

	if(it->second < 0)
	  {
	    break;
	  }
	
	for(int i = 0; i < amountOfNodes; i++)
	  {
	    if(visited[i] == it->first)
	      {
		isUnvisited = false;
	      }
	  }

	cout << "IsUnvisited: " << isUnvisited << endl;
	
	int initialDist = shortestDist[currentNode];

	if((initialDist + it->second) < shortestDist[it->first] &&isUnvisited)
	  {
	    cout << "Short path to: " << it->first->name << "  is: " << initialDist +it->second << endl;
	    shortestDist[it->first] = (initialDist + it->second);
	    previousNode[it->first] = currentNode;
	  }
      }

      currentNode = nullptr;
      cout << "passed dist check" << endl;
      for(map<Node*, int>::iterator it = shortestDist.begin(); it != shortestDist.end(); ++it){
        for(int i = 0; i < amountOfNodes; i++)
	  {
	    if(unvisited[i] == it->first)
	      {
		cout << "trying to add: " << it->first->name << endl;
		if(it->second < lowestUnvisitedNodeDist)
		  {
		    cout << "became curr" << endl;
		    currentNode = it->first;
		    lowestUnvisitedNodeDist = it->second;
		  }
	      }
	  }
      }
      cout << "passed new assign" << endl;
       for(int i = 0; i < amountOfNodes; i++)
          {
            if(currentNode != nullptr && unvisited[i] == currentNode)
              {
		cout << "removing: " << currentNode->name << endl;
		unvisited[i] = nullptr;
	      }
	  }
       cout << "passed removal" << endl;
       if(currentNode == nullptr)
	 {
	   Node* backlog = bNode;
	   cout << "at while" << endl;
	   cout << bNode->name << ", ";
	   while(previousNode[backlog] != nullptr)
	     {
	       cout << previousNode[backlog]->name << ", ";
	       backlog = previousNode[backlog];
	     }
	     cout << endl;
	   return shortestDist[bNode];
	 }
       
    }
}
