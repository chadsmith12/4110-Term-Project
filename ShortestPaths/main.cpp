#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <fstream>

#include "Graph.h"

int main(int argc, char** argv)
{
	if(argc < 4)
	{
		std::cerr << "ERROR: Usage: [numberVerticies] [inputFile] [outputFile]" << std::endl;
		return -1;
	}

	int numberVerticies = std::stoi(argv[1]);
	std::string inputFileName = argv[2];
	std::string outputFileName = argv[3];

	std::ifstream inputFile(inputFileName);

	if(!inputFile.is_open())
	{
		std::cerr << "ERROR: Can not open " << inputFileName << std::endl;
		return -1;
	}
	
	Graph myGraph = numberVerticies;
	myGraph.ReadGraph(inputFile);
	inputFile.close();

	std::ofstream outputFile(outputFileName);

	// run dijkstras for each node
	for (int i = 0; i < numberVerticies; i++)
	{
		std::vector<unsigned int> costs = myGraph.RunDijkstra(i);

		for (auto cost : costs)
		{
			outputFile << cost << " ";
		}
		outputFile << std::endl;
	}

	outputFile.close();

	return 0;
}