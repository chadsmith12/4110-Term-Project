#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
#include <deque>
#include <limits>

class Graph
{
public:
	Graph(int numberVerticies);
	~Graph();
	

	/// <summary>
	/// Reads the graph.
	/// </summary>
	/// <param name="inputStream">The input stream.</param>
	void ReadGraph(std::istream& inputStream);
	

	/// <summary>
	/// Prints the cost graph.
	/// </summary>
	void PrintCostGraph() const;
	

	/// <summary>
	/// Runs the dijkstra.
	/// </summary>
	/// <param name="source">The source.</param>
	/// <returns></returns>
	std::vector<unsigned int> RunDijkstra(int source) const;

private:
	// represent the graph as an adjacency matrix
	int* adjacencyMatrix;

	// number of verticies in the graph
	int numberVerticies;
	
	/// <summary>
	/// The total size 
	/// </summary>
	int totalSize;

	static unsigned int MAX_INT;

	// utility functions for shortest path algorithims
	int GetMinDistance(const std::vector<unsigned int>& distances, std::deque<bool> visited) const;




};

#endif
