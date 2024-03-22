#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H
using namespace std;

class GraphMatrix
{
	private:
		
		int** vertexMatrix;
		int numVertices;
		int numEdges;
		
	public:
		
		GraphMatrix(int);
		~GraphMatrix();
		void addEdge(int, int);
		void printGraph();
		bool isThereAnEdge(int, int);
};

GraphMatrix::GraphMatrix(int numV)
{
	numVertices = numV;
	
	vertexMatrix = new int*[numV];
	for (int i = 0; i < numV; i++)
	{
		vertexMatrix[i] = new int[numV];
	}
	
	for (int j = 0; j < numV; j++)
	{
		for (int k = 0; k < numV; k++)
		{
			vertexMatrix[j][k] = 0;
		}
	}
}

GraphMatrix::~GraphMatrix()
{
	for (int i = 0; i < numVertices; i++)
	{
		delete vertexMatrix[i];
	}
}

void GraphMatrix::addEdge(int v1, int v2)
{
	this->vertexMatrix[v1][v2] = 1;
}

void GraphMatrix::printGraph()
{
	for (int i = 0; i < numVertices; i++)
	{
		for (int j = 0; j < numVertices; j++)
		{
			cout << vertexMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

bool GraphMatrix::isThereAnEdge(int v1, int v2)
{
	if (vertexMatrix[v1][v2] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
	
	
	
	
	
#endif