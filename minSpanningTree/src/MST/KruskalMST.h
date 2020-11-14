#ifndef KruskalMST_h
#define KruskalMST_h
#include "../graph/Graph.h"
class KruskalMST
{
    public:
    KruskalMST(Graph* graph);
    void printResult();
    Edge* result_;
    int vertexSize_;
};
#endif