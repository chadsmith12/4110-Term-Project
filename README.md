# 4110-Term-Project
Comparing solving the All Pairs Shortest Path Problem between dijkstra's and Floyd-Warshall

This project implements 2 different algorithms for solving
all pairs shortest path problem in DIRECTED Graphs and compare the performance of these
algorithms in practice. Both algorithms have the time complexity of O(n^3). 

The first algorithm is the O(n^2) version of Dijkstra’s algorithm that runs n
times, (once from each node of the graph), resulting in O(n^3) time. The second algorithm is
the Floyd-Warshall dynamic programming algorithm that runs in O(n^3) time. The input to
each algorithm is the cost matrix. The output is a matrix that stores the cost of shortest path
between every pair of the vertices.

