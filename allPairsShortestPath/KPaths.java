import java.util.*;

class AllPairShortestPath
{
    final static int INF = 99999;
    int V_;
    AllPairShortestPath(int V)
    {
        V_ =V;
    }

    void printSolution(int dist[][])
    {
        System.out.println("The following matrix shows the shortest "+
                         "distances between every pair of vertices for a give number of int vertices (k)");
        for (int i=0; i<V_; ++i)
        {
            for (int j=0; j<V_; ++j)
            {
                if (dist[i][j] >= INF)
                    System.out.print("INF ");
                else
                    System.out.print(dist[i][j]+"   ");
            }
            System.out.println();
        }
    }

    int[][] extendShortestPath(int D[][], int W[][])
    {
        int dist[][] = new int[D.length][D[0].length];
        // Init the return matrix
        for (int[] row : dist)
        {
            Arrays.fill(row, INF);
        }
        for (int i = 0; i < V_; i++)
        {
            for (int j = 0; j < V_; j++)
            {
                for (int k = 0; k < V_; k++)
                {
                    // If vertex k is on the shortest path from
                    // i to j, then update the value of dist[i][j]
                    if (dist[i][j] > D[i][k] + W[k][j] &&  D[i][k] != 0 &&  W[k][j] != 0 )
                    {
                        dist[i][j] = D[i][k] + W[k][j];
                    }
                }
            }
        }
       return dist;
    }

    void pathForIntVert(int graph[][],int intVertices)
    {
        int dist[][] = new int[graph[0].length][graph[0].length];
        int i, j;

        /* Init the return matrix*/
        for (i = 0; i < V_; i++)
            for (j = 0; j < V_; j++)
                dist[i][j] = graph[i][j];

        int m = 1;
        while (m <= intVertices)
        {
            if ( m == intVertices)// if odd number of calls
            {
                dist = extendShortestPath(dist, graph);
                printSolution(dist);
                m = m+1;
            }
            else
            {
                dist = extendShortestPath(dist, dist);
                printSolution(dist);
                    m = m *2;
            }
        }
        printSolution(dist);
    }

    // program to test above function
    public static void main (String[] args)
    {
        int graph[][] = { {  0,   2,   4,   5, INF},
                          {  2,   0,   1, INF, INF},
                          {  4,   1,   0,   5,   2},
                          {  5, INF,   5,   0,  10},
                          {INF, INF,   2,  10,   0}
                        };
        AllPairShortestPath a = new AllPairShortestPath(graph[0].length);

        int k =3; //intermediate vertices
        a.pathForIntVert(graph, k);
    }
}