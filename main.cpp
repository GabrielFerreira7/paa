#include <vector>
#include <list>
#include <numeric>
#include <iostream>
#include "Util.h"
#include <stack>
#include <unordered_map>
#include <algorithm> // função find
#include <stack> // pilha para usar na DFS
#include <queue> // fila para usar na BFS
#include "diminuir.h"
#include "dividir.h"
#include "pontos.h"
#include "search.h"
#include "Sorting.h"

using namespace std;


void casamento(string texto, string padrao);
void generate(int n, vector<int>& solution, int cont1);
void doido(vector<int>& v, int n, bool flag, int cont);
bool viabilidade(vector<int>& v, int corrente);
void doidoTeste();
int testeIn(int a, int b);
int Ex7(std::vector<int>& v, int begin, int end);
void Ex2(std::vector<float>& v, int begin, int end, std::vector<float>& mm);
void Ex3(std::vector<float>& v, int begin, int end, std::vector<float>& mm);
int Ex6(std::vector<int>& v, int begin, int end);
int Ex8(std::vector<int>& v, int begin, int end, int key);
int searchM(std::vector<int>& v, int key, int begin, int end);

int fibo(int seq)
{
	if (seq == 0)
		return 0;
	if (seq == 1)
		return 1;

	return fibo(seq - 1) + fibo(seq - 2);

}

int main() {

	//cout << fibo(6) << endl;
	string t = "abbcccddcccacccafgccc";
	string t1 = "ccc";
	//casamento(t, t1);
	//vector<int> solution({});
	//generate(4, solution, 0);
	//doidoTeste();

	//cout<<testeIn(100, 20)<<endl;
	vector<int> vec = { 10, 40, 7, 8, 11, 15 };
	//cout << Ex7(vec, 0, vec.size()) << endl;
	vector<float> v = { 14.2, 16.7, 10.9, 5.05, 17.5 };
	vector<float> mm = { 100.1, -1.6 };
	Ex3(v, 0, v.size(), mm);
	//cout << mm[0]<<" "<<mm[1] << endl;
	//cout << Ex8(vec, 0, vec.size(), 10);
	cout<<searchM(vec, 10, 0, vec.size())<<endl; 
	


}

void casamento(string texto, string padrao)
{
	int tamTexto = texto.size();
	int tamP = padrao.size();
	

	for (int i = 0; i < tamTexto - tamP + 1; i++)
	{
		int j = 0;
		for (j; j < tamP; j++)
		{
			if (padrao[j] == texto[i + j]) {
				//cout << "casou " << i << endl;
				continue;

			}


			else
				j = tamP;

		}
		if (j == tamP)
			cout <<"inicio "<< i << endl;
		
	}
}


void generate(int n, vector<int>& solution, int cont1) 
{
	bool flag;

	if (solution.size() == n) 
		printSequence(solution);

	else {
		for (int i = 0; i < 2; i++)
		{
			flag = false;
			if (i == 1)
				cont1 = cont1 + 1;
			if (n % 2 == 1 && cont1 < n / 2 + 1)
				flag = true;
			else if (cont1 < n / 2)
				flag = true;

			if (flag) {
				solution.push_back(i);
				generate(n, solution, cont1);
				solution.pop_back();
			}
			

		}
	}
	
}

bool viabilidade(vector<int>& v, int corrente)
{
	bool flag = true;
	for (int i = 0; i < corrente; i++)
	{
		if (v[corrente] % v[i] == 0)
			continue;
		else {
			flag = false;
			break;
		}
	}
	return flag;
}

void doido(vector<int>& v, int n, bool flag, int cont)
{
	if (flag)
		cout << "solucao viavel " << cont - 1 << endl;

	if (cont < n)
	{
		flag = viabilidade(v, cont);
		doido(v, n, flag, cont + 1);
		
	}
}

void doidoTeste()
{
	vector<int> v = { 1, 2, 4, 8, 10, 40 };
	int n = v.size();
	doido(v, n, false, 0);
}

int testeIn(int a, int b)
{
	return a < b ? a : b;
}

int Ex7(std::vector<int>& v, int begin, int end) {
	if ((end - begin) == 1) {
		return v[begin];
	}
	else {
		int x = Ex7(v, begin + 1, end);
		return v[begin] < x ? v[begin] : x;
	}
}

void Ex2(std::vector<float>& v, int begin, int end, std::vector<float>& mm) {
	if ((end - begin) == 1) {
		mm[0] = v[begin];
		mm[1] = v[begin];
	}
	else {
		Ex2(v, begin + 1, end, mm);
		if (v[begin] < mm[0]) {
			mm[0] = v[begin];
		}
		else if (v[begin] > mm[1]) {
			mm[1] = v[begin];
		}
	}
}

void Ex3(std::vector<float>& v, int begin, int end, std::vector<float>& mm) {
	if ((end - begin) == 1) {
		if (v[begin] < mm[0]) {
			mm[0] = v[begin];
		}
		else if (v[begin] > mm[1]) {
			mm[1] = v[begin];
		}
	}
	else {
		Ex3(v, begin, (begin + end) / 2, mm);
		Ex3(v, (begin + end) / 2, end, mm);
	}
}

int Ex6(std::vector<int>& v, int begin, int end) {
	if ((end - begin) == 1) {
		return v[begin];
	}
	else {
		int x1 = Ex6(v, begin, (begin + end) / 2);
		int x2 = Ex6(v, (begin + end) / 2, end);
		return (x1 < x2) ? x1 : x2;
	}
}

int Ex8(std::vector<int>& v, int begin, int end, int key) {
	if ((end - begin) == 1) {
		if (v[begin] == key)
			return begin;
		else
			return -1;
	}
	else {
		int x1 = Ex8(v, begin, (begin + end) / 2, key);
		int x2 = Ex8(v, (begin + end) / 2, end, key);
		return (x1 > x2) ? x1 : x2;
	}
}

int searchM(std::vector<int>& v, int key, int begin, int end) {

	if (end - begin == 0) {
		return -1;
	}
	else {

		int midpoint = std::floor((float)(begin + end) / 2);

		if (key == v[midpoint]) {
			return midpoint;
		}
		else {
			int x1 = searchM(v, key, begin, midpoint);
			int x2 = searchM(v, key, midpoint + 1, end);
			return (x1 > x2) ? x1 : x2;
		}

	}

}