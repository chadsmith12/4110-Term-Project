#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <fstream>

int main(int argc, char** argv)
{

	if(argc < 5)
	{
		std::cerr << "Error: Usage: [verticies] [costMin] [costMax] [fileName]." << std::endl;

		return -1;
	}

	int numberVerticies;
	int costMin;
	int costMax;
	std::string fileName;
	std::ofstream outputFile;

	numberVerticies = std::stoi(argv[1]);
	costMin = std::stoi(argv[2]);
	costMax = std::stoi(argv[3]);
	fileName = argv[4];

	if(costMin <= 0)
	{
		std::cerr << "Error: Minimum must be > 0" << std::endl;
		return -1;
	}
	if(costMin >= costMax)
	{
		std::cerr << "Eror: Maximum must be > the minimum" << std::endl;
		return -1;
	}

	// seed value to generate the random distribution
	std::mt19937 generator(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<> costDistribution(costMin, costMax);

	std::cout << "Generating cost matrix..." << std::endl;

	// allocate enough memory for this matrix
	// this numberVerticies*numberVerticies array is the same as a [numberVerticies][numberVerticies] array
	int* costMatrix = new int[numberVerticies * numberVerticies];

	// loop through every row in this matrix
	for (int row = 0; row < numberVerticies; row++)
	{
		// loop through every column in this matrix
		for (int col = 0; col < numberVerticies; col++)
		{
			// row major form to use this psuedo 2D Array
			// same as doing [row][col] in 2d array
			int index = row * numberVerticies + col;
			// if row and col are equal, then we know we are on the diagnols and these should be 0 (no cycles)
			if(row == col)
			{
				costMatrix[index] = 0;
			}
			else
			{
				costMatrix[index] = costDistribution(generator);
			}
		}
	}

	outputFile.open(fileName);
	if(!outputFile.is_open())
	{
		std::cerr << "Could not open " << fileName << " for writing." << std::endl;
		return -1;
	}

	for (int row = 0; row < numberVerticies; row++)
	{
		for (int col = 0; col < numberVerticies; col++)
		{
			int index = row * numberVerticies + col;
			outputFile << costMatrix[index];
			if((index < numberVerticies*numberVerticies) && (col < numberVerticies -1))
			{
				outputFile << " ";
			}
			
		}
		outputFile << std::endl;
	}

	outputFile.close();
	delete[] costMatrix;

	return 0;
}