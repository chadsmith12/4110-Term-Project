#include "Graph.h"


unsigned int Graph::MAX_INT = std::numeric_limits<unsigned int>::max();

Graph::Graph(int numberVerticies): adjacencyMatrix(nullptr), numberVerticies(numberVerticies), totalSize(numberVerticies*numberVerticies)
{

}

Graph::~Graph()
{
	// free up the memory allocated for the matrix
	delete[] adjacencyMatrix;
}

void Graph::ReadGraph(std::istream& inputStream)
{
	// initialize the adjacency matrix to the numberVeritices*numberVerticies
	adjacencyMatrix = new int[numberVerticies * numberVerticies];

	for (int i = 0; i < numberVerticies * numberVerticies; ++i)
	{
		inputStream >> adjacencyMatrix[i];
	}
}

void Graph::PrintCostGraph() const
{
	for (int row = 0; row < numberVerticies; row++)
	{
		for (int col = 0; col < numberVerticies; col++)
		{
			std::cout << adjacencyMatrix[row * numberVerticies + col] << " ";
		}
		std::cout << std::endl;
	}
}

/// <summary>
/// Runs the dijkstra.
/// </summary>
/// <param name="source">The source.</param>
/// <returns></returns>
std::vector<unsigned int> Graph::RunDijkstra(int source) const
{
	// set all the distances to the max at the start
	std::vector<unsigned int> costs(numberVerticies, MAX_INT);
	// all the visited nodes, initialized to false at the start
	std::deque<bool> visitedNodes(numberVerticies, false);

	// source we enetered is more than the number of verticies in the graph
	// just return the max costs
	if(source >= numberVerticies)
	{
		return costs;
	}
	costs[source] = 0;

	for (int i = 0; i < numberVerticies; i++)
	{
		// get the minimum distance index for a node we haven't visted
		int minimumIndex = GetMinDistance(costs, visitedNodes);
		visitedNodes[minimumIndex] = true;

		for (int j = 0; j < numberVerticies; j++)
		{
			int index = minimumIndex * numberVerticies + j;
			// update the distance if we haven't set that vertex to visited
			// and edge exists, and the total weight is actually smaller
			if(!visitedNodes[j] && adjacencyMatrix[index] && costs[minimumIndex] != MAX_INT && costs[minimumIndex] + adjacencyMatrix[index] < costs[j])
			{
				costs[j] = costs[minimumIndex] + adjacencyMatrix[index];
			}
		}

	}

	return costs;
}

/// <summary>
/// Gets the minimum distance.
/// </summary>
/// <param name="distances">The distances.</param>
/// <param name="visited">The visited.</param>
/// <returns></returns>
int Graph::GetMinDistance(const std::vector<unsigned int>& distances, std::deque<bool> visited) const
{
	unsigned int currentMin = MAX_INT;
	int minIndex = 0;

	// go through all the verticies
	for (int i = 0; i < numberVerticies; i++)
	{
		// if the one we are on hasn't been visited and its distance is less than the current min
		if(!visited[i] && distances[i] <= currentMin)
		{
			currentMin = distances[i];
			minIndex = i;
		}
	}

	return minIndex;
}
