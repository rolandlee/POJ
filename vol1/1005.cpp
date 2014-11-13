#include <iostream>
#include <cmath>

using namespace std;

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502884
#endif

inline int calcul(double x, double y)
{
	return ceil((x*x + y*y) * M_PI / 100); 
}

int main()
{
	int N;
	double X, Y;
	cin >> N;
	for(int idx = 1; idx <= N; idx++){
		cin >> X >> Y;
		cout << "Property " << idx << ": This property will begin eroding in year " << calcul(X,Y) << ".\n";
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}