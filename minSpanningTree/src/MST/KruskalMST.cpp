#include <cstdlib>
#include <iostream>
#include "KruskalMST.h"
#include "../util/MSTUtils.h"
#include "../subset/Subset.h"

KruskalMST::KruskalMST(Graph* graph)
{
    int vertex = graph->numOfVertex_;
    Edge result[vertex]; // Tnis will store the resultant MST

    // Sort all edges by weight
    std::qsort(graph->edge_, graph->numOfEdges_, sizeof(graph->edge_[0]),
          MSTUtils::myComp);

    // Allocate memory for creating vertex ssubsets
    Subset* subsets = new Subset[(vertex * sizeof(Subset))];

    // Create vertex subsets with single elements
    for (int v = 0; v < vertex; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to vertex-1
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges
    while (e < vertex - 1 && i < graph->numOfEdges_)
    {
        // Step 2: Pick the smallest edge. And increment
        // the index for next iteration
        Edge next_edge = graph->edge_[i++];

        int x = MSTUtils::find(subsets, next_edge.getSrc());
        int y = MSTUtils::find(subsets, next_edge.getDest());

        // If including this edge does't cause cycle,
        // include it in result and increment the index
        // of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            MSTUtils::Union(subsets, x, y);
        }
        // Else discard the next_edge
    }

    // print the contents of result[] to display the
    // built MST
    std::cout << "Following are the edges in the constructed "
            "MST\n";
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        std::cout << result[i].getSrc() << " -- " << result[i].getDest()
             << " == " << result[i].getWeight() << std::endl;
        minimumCost = minimumCost + result[i].getWeight();
    }
    // return;
    std::cout << "Minimum Cost Spanning Tree: " << minimumCost
         << std::endl;
}
