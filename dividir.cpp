#include <vector>
#include <algorithm>
#include "Util.h"
#include "dividir.h"

using namespace std;

int maxx(vector<int>& vec, int begin, int end) {
	int idx, idx2;

	if (end - begin == 1)
		return begin;
	else {
		idx = maxx(vec, begin, (end + begin) / 2);
		idx2 = maxx(vec, (end + begin) / 2, end);

		return vec[idx] > vec[idx2] ? idx : idx2;
	}

}

void maxx(vector<int>& vec)
{
	int tam = vec.size();
	cout << maxx(vec, 0, tam) << endl;
}