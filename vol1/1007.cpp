#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;
int N;
int M;

struct Ret
{
	short value;
	short ptr;
};


string pool[100];
Ret records[100];

int sortness(const string &s)
{
	int ret = 0;
	for(int i = 0; i < s.length(); i++){
		for(int j = i+1; j < s.length(); j++){
			if( s[i] > s[j])
				ret++;
		}
	}
	return ret;
}

int cmp(const void *a, const void *b)
{
	return ((Ret*)a)->value - ((Ret*)b)->value;
}

int main()
{
	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		cin >> pool[i];
		records[i].ptr = i;
		records[i].value = sortness(pool[i]);
	}

	qsort(records, M, sizeof(Ret), cmp);

	for(int i = 0; i < M; i++){
		cout << pool[records[i].ptr] << endl;
	}
	return 0;
}
