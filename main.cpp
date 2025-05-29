#include"Graph.h"


int main()
{
  int input = 0;
  Graph* g = new Graph();
 
  while(true)
    {
      //gets input to do stuff
      cout << "1 to add, 2 to delete, 3 to disconnect, 4 to add path, 5 find shortest distance, 6 print node map" << endl;
      cin >> input;

      //adds
      if(input == 1)
	{
	  char name;
	  cout << "enter a name(one character): ";
	  cin >> name;
	  g->addNode(name);
	}
      else if(input == 2)//removes
        {
	  char name;
          cout << "enter a name(one character): ";
          cin >> name;
          g->deleteNode(name);
        }
      else if(input == 3)//disconnects
        {
	  char name1, name2;
          cout << "enter a name(one character): ";
          cin >> name1;
	  cout << "enter a name(one character): ";
          cin >> name2;
          g->disconnectNodes(name1, name2);
        }
      else if(input == 4)//connects
        {
	  char name1, name2;
	  int length;
          cout << "enter a name(one character): ";
          cin >> name1;
          cout << "enter a name(one character): ";
          cin >> name2;
	  cout << "enter a length: ";
	  cin >> length;
          g->connectNodes(name1, name2, length);
        }
      else if(input == 5)//finds shortest path
        {
	  char name1, name2;
          cout << "enter a name(one character): ";
          cin >> name1;
          cout << "enter a name(one character): ";
          cin >> name2;
          cout << "shotest path: " << g->shortestPath(name1, name2) << endl;
        }
      else
	{
	  cout << "try again" << endl;
	}
    }
}
