#ifndef Graph_h
#define Graph_h
#include "../edge/Edge.h"
class Graph {
public:
    Graph(size_t vertex, size_t edge):
        numOfVertex_(vertex),
        numOfEdges_(edge)
    {
        edge_ = new Edge[numOfEdges_];
    }
    size_t numOfVertex_;
    size_t numOfEdges_;
    Edge* edge_;
};
#endif
