#include "pontos.h"


float distance(vector<float> v1, vector<float> v2)
{

	float s = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		s += pow((v1[i] - v2[i]), 2);
	}
	return pow(s, (1.0 / 2.0));
}

float BruteForceClosestPair(vector<vector<float> > vec)
{
	int qp = vec.size(); //quantidade de pontos
	float dmin = 1000000.0;
	float dpontos = 0;
	for (int i = 0; i < qp - 1; i++)
	{
		for (int j = i + 1; j < qp; j++)
		{
			dpontos = distance(vec[i], vec[j]);
			if (dmin > dpontos)
			{
				dmin = dpontos;
			}


		}
	}
	return dmin;
}

