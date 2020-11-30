
// A Java program for Floyd Warshall All Pairs Shortest
// Path algorithm.
import java.util.*;

import javax.lang.model.util.ElementScanner6;

import java.lang.*;
import java.io.*;


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
                         "distances between every pair of vertices");
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
        for (int[] row : dist)
        {
            Arrays.fill(row, INF);
        }
        // Pick all vertices as source one by one
        for (int i = 0; i < V_; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (int j = 0; j < V_; j++)
            {
                for (int k = 0; k < V_; k++)
                {
                    // If vertex k is on the shortest path from
                    // i to j, then update the value of dist[i][j]
                    // System.out.print("dist[" +i+"][" + j + "] : " + dist[i][j]);
                    // System.out.print(" " );
                    // System.out.print("D[" +i+"][" + k + "]: " + D[i][k]);
                    // System.out.print(" " );
                    // System.out.print("W[" +k+"][" + j + "]: " + W[k][j]);
                    // System.out.println(" " );
                    if (dist[i][j] > D[i][k] + W[k][j] &&  D[i][k] != 0 &&  W[k][j] != 0 )
                    {
                        dist[i][j] = D[i][k] + W[k][j];
                        // System.out.println("Setting dist[" +i+"][" + j + "] : " + dist[i][j]);
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

        /* Initialize the solution matrix same as input graph matrix.
           Or we can say the initial values of shortest distances
           are based on shortest paths considering no intermediate
           vertex. */
        for (i = 0; i < V_; i++)
            for (j = 0; j < V_; j++)
                dist[i][j] = graph[i][j];

        int m = 0;
        int tempintVertices = intVertices;
        while (m < intVertices)
        {
            int temp = tempintVertices%2;
            System.out.println("temp" + temp);
            if ( temp > 0)
            {
                System.out.println("odd");
                dist = extendShortestPath(dist, graph);
                tempintVertices = 0;
                printSolution(dist);
                m = 1;
            }
            else
            {
                System.out.println("even");
                dist = extendShortestPath(dist, graph);
                printSolution(dist);
                if ( m==0)
                {
                    m = 1;
                }
                else
                {
                    m = m *2;
                }
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

        int k = 3; //intermediate vertices
        a.pathForIntVert(graph, k);
    }
}