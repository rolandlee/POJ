#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Decimal
{
	int v[256];
	int length;
	int posDecimal;
};

void print(const Decimal &d)
{
	int endPos = 0;
	while(endPos < d.posDecimal && d.v[endPos]==0)endPos++;

	for(int i = d.length-1; i >= d.posDecimal; i--)
		putchar(d.v[i] + '0');
	if(d.posDecimal != endPos) putchar('.');
	for(int i = d.posDecimal-1; i>= endPos; i--)
		putchar(d.v[i] + '0');
	putchar('\n');
}


void mul(const Decimal &n1, const Decimal &n2, Decimal &ret)
{
	int overflow;
	for(int i = 0; i < n2.length; i++){
		for(int j = 0; j < n1.length; j++){
			ret.v[i+j] += n1.v[j] * n2.v[i];
		}
	}
	for(int i = 0; i < n1.length + n2.length; i++){
		overflow = ret.v[i] / 10;
		ret.v[i+1]+=overflow;
		ret.v[i] %= 10;
	}
	ret.length = n1.length + n2.length;
	ret.posDecimal = n1.posDecimal + n2.posDecimal;
	while(ret.length > 1 && ret.v[ret.length-1]==0)ret.length--;
}

void init(Decimal &d)
{
	memset(&d, 0, sizeof(Decimal));
}

void set(Decimal &d, const char *x)
{
	int len = strlen(x);
	int pos = len;
	for(int i = 0; i < len; i++){
		d.v[i] = x[len - i - 1] - '0';
		if(x[len - i - 1] == '.'){
			pos = i;
		}
	}
	for(int i = pos; i < len; i++){
		d.v[i] = d.v[i + 1];
	}
	d.posDecimal = (pos == len ? 0 : pos);
	d.length = (pos == len ? len : len - 1);
	while(d.length > 1 && d.v[d.length-1]==0)d.length--;
}


void mpow(const Decimal &x, const int n, Decimal &ret)
{
	if(n == 0){
		set(ret,"1");
		return;
	}
	if(n == 1){
		ret = x;
		return;
	}
	Decimal temp,temp2;
	init(temp);
	init(temp2);
	mpow(x, n >> 1, temp);
	mul(temp,temp,temp2);
	if(n & 1){
		mul(temp2, x, ret);
	}else{
		ret = temp2;
	}
}

void print_debug(const Decimal &n)
{
	for(int i = 0; i < n.length; i++)
		putchar(n.v[i] + '0');
	printf("\n%d %d \n", n.posDecimal, n.length);
}

int main()
{
	char buf[8];
	int power;
	Decimal x,ret;

	while(cin >> buf >> power){
		while(buf[strlen(buf)-1]=='0') buf[strlen(buf)-1]=0;
		init(x);
		init(ret);
		set(x, buf);
		mpow(x, power, ret);
		print(ret);
	}
	return 0;
}