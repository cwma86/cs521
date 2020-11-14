#ifndef MSTUtils_h
#define MSTUtils_h
#include "../subset/Subset.h"
#include "../edge/Edge.h"
namespace MSTUtils{
    // A utility function to find set of an element i
    // (uses path compression technique)
    int find(Subset subsets[], int element)
    {
        // find root and make root as parent of element
        // (path compression)
        if (subsets[element].parent != element)
            subsets[element].parent
                = find(subsets, subsets[element].parent);

        return subsets[element].parent;
    }

    void Union(Subset subsets[], int element1, int element2)
    {
        int element1root = find(subsets, element1);
        int element2root = find(subsets, element2);

        // Attach smaller rank tree under root of high
        // rank tree (Union by Rank)
        if (subsets[element1root].rank < subsets[element2root].rank)
            subsets[element1root].parent = element2root;
        else if (subsets[element1root].rank > subsets[element2root].rank)
            subsets[element2root].parent = element1root;

        // If ranks are same, then make one as root and
        // increment its rank by one
        else {
            subsets[element2root].parent = element1root;
            subsets[element1root].rank++;
        }
    }
    // Compare two edges according to their weights.
    // Used in qsort() for sorting an array of edges
    int myComp(const void* edge1, const void* edge2)
    {
        Edge* a1 = (Edge*)edge1;
        Edge* b1 = (Edge*)edge2;
        return a1->getWeight() > b1->getWeight();
    }
}
#endif