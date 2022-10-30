#include <vector>
#include <algorithm>
#include "Util.h"
#include "search.h"

void generate_permutations(int n, std::vector<int> solution, int rep) {

	//if (solution.size() == n) {
	printSequence(solution);
	//}
	//else {
	for (int i = rep; i < n; i++)
	{

		if (std::find(solution.begin(), solution.end(), i) == solution.end()) {
			solution.push_back(i);
			generate_permutations(n, solution, i);
			solution.pop_back();
		}
	}
	//}
}
int custoS(std::vector<std::vector<int>> matriz, std::vector<int> solution)
{
	int custo = 0;
	std::vector<int> x;
	int n = solution.size();

	for (int i = 0; i < (n - 1); i++)
	{
		//x = matriz[i];
		//std::cout << x[i+1] << std::endl;


		custo = custo + matriz[solution[i]][solution[i + 1]];
		//std::cout << matriz[i][(i + 1)] << std::endl;
	}
	x = matriz[solution[solution.size() - 1]];
	//std::cout << x[solution[0]] << std::endl;

	return custo + x[solution[0]];
}


void generate_permutationsTSP(int n, std::vector<int> solution, std::vector<int> solutionM, int& custoM, std::vector<std::vector<int>>& matriz) {
	int custoS1;
	if (solution.size() == n) {

		custoS1 = custoS(matriz, solution);
		if (custoM > custoS1)
		{
			solutionM = solution;
			custoM = custoS1;
			solutionM.push_back(solution[0]);
			printSequence(solutionM);
			std::cout << custoM << std::endl;

		}



	}
	else {
		for (int i = 0; i < n; i++)
		{

			if (std::find(solution.begin(), solution.end(), i) == solution.end()) {
				solution.push_back(i);
				generate_permutationsTSP(n, solution, solutionM, custoM, matriz);
				solution.pop_back();
			}
		}
	}

	//std::cout << "custo da solucao: " << custoM << std::endl;
}

void generate_permutations(int n) {
	std::vector<int> solution({});

	generate_permutations(n, solution, 0);
}
void generate_permutationsTSP(int n, std::vector<std::vector<int>>& matriz)
{
	std::vector<int> solution({});
	std::vector<int> solution2({});
	int x = 10000;
	int& ref = x;
	generate_permutationsTSP(n, solution, solution2, ref, matriz);
	//std::vector<int> solution3= { 0, 1, 3, 2};
	//std::cout << custoS(matriz, solution3) << std::endl;
}

void generate_binary(int n, std::vector<int>& solution) {


	if (solution.size() == n) {
		printSequence(solution);
		return;
	}
	else {
		for (int i = 0; i < 2; i++)
		{
			solution.push_back(i);
			generate_binary(n, solution);
			solution.pop_back();
		}
	}
}

void generate_binary(int n) {

	std::vector<int> solution({});
	generate_binary(n, solution);
}