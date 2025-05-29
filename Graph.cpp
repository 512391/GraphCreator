#include"Graph.h"

//sets up all the graph stuff
Graph::Graph()
{
  nodes = new Node*[100];
  currentIndex = 0;
  amountOfNodes = 0;
}

//adds a node to the graph
void Graph::addNode(char a)
{
  nodes[currentIndex] = new Node(a);
  currentIndex++;
  amountOfNodes++;
}

//connects two nodes on the graph with a length
void Graph::connectNodes(char a, char b, int length)
{
  Node* aNode = nullptr;
  Node* bNode = nullptr;

  //finds both nodes
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
      return;
    }

  //if both are found connect them
  aNode->AddNode(bNode, length);
  bNode->AddNode(aNode, length);
}

//disconnect nodes removing their path
void Graph::disconnectNodes(char a, char b)
{
   Node* aNode = nullptr;
  Node* bNode = nullptr;

  //finds both nodes
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
      return;
    }

  //if both nodes are found remove their connection
  aNode->RemoveNode(bNode);
  bNode->RemoveNode(aNode);
}

//takes a node off the graph
void Graph::deleteNode(char a)
{
  //finds the node
  for(int i = 0; i < currentIndex; i++)
    {
      //wipes it off the face of the planet
      if(nodes[i] != nullptr && nodes[i]->name == a)
	{
	  delete nodes[i];
	  nodes[i] = nullptr;
	  amountOfNodes--;
	  return;
	}
    }
}

//finds the shortest path between two nodes
int Graph::shortestPath(char a, char b)
{
   Node* aNode = nullptr;
  Node* bNode = nullptr;

  //finds the nodes
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

  //makes sure it found the nodes
  if(aNode == nullptr || bNode == nullptr)
    {
      cout << "Could not find nodes" << endl;
    }

  //makes stuff
  Node** visited = new Node*[amountOfNodes];
  Node** unvisited = new Node*[amountOfNodes];

  map<Node*, int> shortestDist = {};
  map<Node*, Node*> previousNode = {};

  int j = 0;
  //initializes all the structures above
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
      //goes through each connection fr the current node
      for(map<Node*, int>::iterator it = currentNode->getAdjacencyInfo().begin(); it != currentNode->getAdjacencyInfo().end(); ++it){
	bool isUnvisited = true;

	//if it is a garbage value get out of the loop
	if(it->second < 0)
	  {
	    break;
	  }

	//makes sure the node is unvisited
	for(int i = 0; i < amountOfNodes; i++)
	  {
	    if(visited[i] == it->first)
	      {
		isUnvisited = false;
	      }
	  }

	cout << "IsUnvisited: " << isUnvisited << endl;
	
	int initialDist = shortestDist[currentNode];

	//sees if the path from this node to the node is the shortest path
	if((initialDist + it->second) < shortestDist[it->first] &&isUnvisited)
	  {
	    //if it is the shortest path this updates it as the shortest path
	    cout << "Short path to: " << it->first->name << "  is: " << initialDist +it->second << endl;
	    shortestDist[it->first] = (initialDist + it->second);
	    previousNode[it->first] = currentNode;
	  }
      }

      currentNode = nullptr;
      cout << "passed dist check" << endl;
      //goes through all of the nodes
      for(map<Node*, int>::iterator it = shortestDist.begin(); it != shortestDist.end(); ++it){
        for(int i = 0; i < amountOfNodes; i++)
	  {
	    //checks if it is unvisited
	    if(unvisited[i] == it->first)
	      {
		cout << "trying to add: " << it->first->name << endl;
		if(it->second < lowestUnvisitedNodeDist)
		  {
		    //if it is the lowest unvisited distance make it the new curr node
		    cout << "became curr" << endl;
		    currentNode = it->first;
		    lowestUnvisitedNodeDist = it->second;
		  }
	      }
	  }
      }
      cout << "passed new assign" << endl;
      //removes the new current node from unvisited
       for(int i = 0; i < amountOfNodes; i++)
          {
            if(currentNode != nullptr && unvisited[i] == currentNode)
              {
		cout << "removing: " << currentNode->name << endl;
		unvisited[i] = nullptr;
	      }
	  }
       cout << "passed removal" << endl;
       //if there are no more nodes to find then print out the result
       if(currentNode == nullptr)
	 {
	   //if it did not find the node print no path
	   if(shortestDist[bNode] == 1000000000)
	     {
	       cout << "No Path" << endl;
	       return -1;
	     }
	   Node* backlog = bNode;
	   cout << "at while" << endl;
	   cout << "path from second node: ";
	   cout << bNode->name << ", ";

	   //print the path to get there
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
