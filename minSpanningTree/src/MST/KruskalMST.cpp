#include <cstdlib>
#include <iostream>
#include "KruskalMST.h"
#include "../util/MSTUtils.h"
#include "../subset/Subset.h"

KruskalMST::KruskalMST(Graph* graph):
    result_(nullptr),
    vertexSize_(graph->numOfVertex_)
{
    result_ = new Edge[vertexSize_]; // Tnis will store the resultant MST

    // Sort all edges by weight
    std::qsort(graph->edge_, graph->numOfEdges_, sizeof(graph->edge_[0]),
          MSTUtils::myComp);

    // Allocate memory for creating vertex ssubsets
    Subset* subsets = new Subset[(vertexSize_ * sizeof(Subset))];

    // Create vertex subsets with single elements
    for (size_t v = 0; v < vertexSize_; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to vertex-1
    size_t e = 0; // An index variable, used for result[]
    size_t i = 0; // An index variable, used for sorted edges
    while (e < vertexSize_ - 1 && i < graph->numOfEdges_)
    {
        // Step 2: Pick the smallest edge. And increment
        // the index for next iteration
        Edge next_edge = graph->edge_[i++];

        size_t x = MSTUtils::find(subsets, next_edge.getSrc());
        size_t y = MSTUtils::find(subsets, next_edge.getDest());

        // If including this edge does't cause cycle,
        // include it in result and increment the index
        // of result for next edge
        if (x != y) {
            result_[e++] = next_edge;
            MSTUtils::Union(subsets, x, y);
        }
        // Else discard the next_edge
    }


}
void KruskalMST::printResult()
{
    // print the contents of result[] to display the
    // built MST
    std::cout << "Following are the edges in the constructed "
            "MST\n";
    int minimumCost = 0;
    for (size_t i = 0; i < vertexSize_; ++i)
    {
        std::cout << result_[i].getSrc() << " -- " << result_[i].getDest()
             << " == " << result_[i].getWeight() << std::endl;
        minimumCost = minimumCost + result_[i].getWeight();
    }
    // return;
    std::cout << "Minimum Cost Spanning Tree: " << minimumCost
         << std::endl;
}