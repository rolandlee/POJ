#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double vector[12];
	double total = 0.0f;

	for(int idx = 0; idx < 12; idx++){
		cin >> vector[idx];
	}

	for(int idx = 0; idx < 12; idx++){
		total += vector[idx];
	}

	cout << setprecision(2) << fixed;
	cout << '$' << total / 12 << endl;
	
	return 0;
}