#include <stdlib.h>     /* srand, rand */
#include <unistd.h>
#include <time.h>       /* time */
#include <chrono>
#include <iostream>
#include "graph/Graph.h"
#include "MST/KruskalMST.h"


void buildRandomGraph(int* randomArray, size_t size){
  srand (time(0));
  /* initialize random seed: */
  for (auto i = 0; i < size; i++)
  {

    /* generate number between 0 and 100: */
    *(randomArray+i) = rand() % 100;

  }
}

void createEdge(Graph* graph, int index, int src, int dest, int weight)
{
    // add edge_ 5-6
    graph->edge_[index].setSrc(src);
    graph->edge_[index].setDest(dest);
    graph->edge_[index].setWeight(weight);
}

Graph * constExample1()
{
    size_t numOfVertex = 4; // Number of vertices in graph
    size_t numberOfEdges = 5; // Number of edges in graph
    Graph* graph = new Graph(numOfVertex, numberOfEdges);
    int index = 0;

    // add edge_ 0-1
    createEdge(graph, index, 0, 1, 10);
    index++;
    // add edge_ 0-2
    createEdge(graph, index, 0, 2, 6);
    index++;
    // add edge_ 0-3
    createEdge(graph, index, 0, 3, 5);
    index++;

    // add edge_ 1-3
    createEdge(graph, index, 1, 3, 15);
    index++;
    // add edge_ 2-3
    graph->edge_[4].setSrc(2);
    graph->edge_[4].setDest(3);
    graph->edge_[4].setWeight(4);
    createEdge(graph, index, 2, 3, 4);
    index++;
    return graph;
}

Graph * constExample2()
{
    size_t numOfVertex = 9; // Number of vertices in graph
    size_t numberOfEdges = 14; // Number of edges in graph
    Graph* graph = new Graph(numOfVertex, numberOfEdges);
    int index = 0;

    // add edge_ 0-1
    createEdge(graph, index, 0, 1, 4);
    index++;

    // add edge_ 0-7
    createEdge(graph, index, 0, 7, 8);
    index++;

    // add edge_ 1-2
    createEdge(graph, index, 1, 2, 8);
    index++;

    // add edge_ 2-3
    createEdge(graph, index, 2, 3, 7);
    index++;

    // add edge_ 2-8
    createEdge(graph, index, 2, 8, 2);
    index++;

    // add edge_ 2-5
    createEdge(graph, index, 2, 5, 4);
    index++;

    // add edge_ 3-4
    createEdge(graph, index, 3, 4, 9);
    index++;

    // add edge_ 3-5
    createEdge(graph, index, 3, 5, 14);
    index++;

    // add edge_ 5-6
    createEdge(graph, index, 5, 6, 2);
    index++;

    // add edge_ 6-7
    createEdge(graph, index, 6, 7, 1);
    index++;

    // add edge_ 6-8
    createEdge(graph, index, 6, 8,6);
    index++;

    // add edge_ 7-8
    createEdge(graph, index, 7, 8, 7);
    index++;

    return graph;
}

int main (int argc, char *argv[])
{
  char opt;
  int arraySize = 100;
  int sortType = 0;
  bool verboseOutput = false;
  while((opt = getopt(argc, argv, "h")) != -1)
  {
    switch(opt)
    {
      case 'h':
        std::cout << "using Kruskal algorithm to find the min spanning tree" << std::endl;
        break;
      default:
        std::cout << "d" << std::endl;
        break;

    }
  }

    // Function call
    Graph * graph = constExample2();
    KruskalMST* tmp = new KruskalMST(graph);
    tmp->printResult();

  return 0;
}
