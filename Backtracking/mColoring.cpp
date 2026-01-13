/*
PS : Given an integer M and an undirected graph with N vertices (zero indexed) and E edges. 
The goal is to determine whether the graph can be coloured with a maximum of M colors so that no two of its 
adjacent vertices have the same colour applied to them.

In this context, colouring a graph refers to giving each vertex a different colour. If the colouring of vertices 
is possible then return true, otherwise return false.

Example 1
Input : N = 4 , M = 3 , E = 5 , Edges = [ (0, 1) , (1, 2) , (2, 3) , (3, 0) , (0, 2) ]
Output : true

Analysis - 
TC = O(m^v)
SC = O(v)
*/

#include <bits/stdc++.h>
using namespace std;

// global declarations
int V = 4; // number of vertices
int m = 3; // number of colors

int graph[4][4] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int color[4]; // color for each vertex

// Check if assigning color c to vertex v is safe
bool isValid(int v, int c) {
    for(int i = 0; i < V; i++) {
        if(graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Backtracking function
bool mColor(int v) {
    // Base condition: all vertices colored
    if(v == V) {
        return true;
    }

    // Try all colors
    for(int c = 1; c <= m; c++) {
        if(isValid(v, c)) {
            color[v] = c;

            if(mColor(v + 1)) {
                return true;
            }

            // Backtrack
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    if(mColor(0)) {
        cout << "TRUE\n";
    } else {
        cout << "FALSE\n";
    }
}