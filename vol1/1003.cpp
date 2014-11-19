#include <iostream>
using namespace std;

int calcul(double x)
{
	int n = 2;
	double length = 1.0 / n;
	while(length < x){
		n++;
		length += 1.0 / n;
	}
	return n - 1;
}

int main()
{
	double c;
	cin >> c;
	while(c != 0){
		cout << calcul(c) << " card(s)\n";
		cin >> c;
	}
	return 0;
}