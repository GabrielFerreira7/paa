#include <vector>
#include <algorithm>
#include "Util.h"
#include "diminuir.h"

using namespace std;

void busca_binaria(int inicio, int fim, vector<int> vec, int valor)
{
	int n;
	int media = fim + inicio;
	cout << media << endl;
	if (fim - inicio == 1)
	{
		cout << "Nao encontrado" << endl;
		return;
	}
	if ((media % 2) == 1) //impar 
	{

		n = (media + 1) / 2;
	}
	else
		n = media / 2;

	if (vec[n] == valor)
	{
		cout << "valor encontrado, indice  " << n << endl;
		return;
	}


	else if (vec[n] > valor)
		fim = n;
	else
		inicio = n;

	busca_binaria(inicio, fim, vec, valor);

}

void busca_binaria(vector<int> vec, int valor)
{
	int n = (vec.size() - 1);

	busca_binaria(0, n, vec, valor);
}

int soma(vector<int> vec, int inicio, int fim)
{
	int acc = 0;
	for (int i = inicio; i <= fim; i++)
	{
		acc += vec[i];
	}
	return acc;
}

void fake_coins(int inicio, int fim, vector<int> vec)
{
	int n;
	int s = 0;
	int l1, l2;
	int media = fim + inicio;


	if ((media % 2) == 1) //impar 
		n = (media + 1) / 2;
	else
	{
		n = (media) / 2;
		s = 1;

	}




	l1 = soma(vec, inicio, n);
	l2 = soma(vec, n + s, fim);

	if (l1 > l2)
	{
		inicio = n + 1;
	}
	else if (l1 < l2)
		fim = n;
	else
	{
		cout << "nao existe valor menor" << endl;
		return;
	}

	if (fim - inicio == 1)
	{
		cout << "encontrou, indice " << n << endl;
	}

	fake_coins(inicio, fim, vec);




}

void fake_coins(vector<int> vec)
{
	int n = (vec.size() - 1);
	//cout << soma(vec, 0, 4) << endl;

	fake_coins(0, n, vec);



}