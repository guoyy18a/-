#include <iostream>
#include<vector>
#include<string>
using namespace std;
void multiply(const vector<int> &numa, const vector<int> &numb, vector<int> &mul);
int main()
{
	unsigned int N;		//number of samples
	vector<int> numA;
	vector<int> numB;
	string a;
	string b;
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		cin >> a >> b;
		numA.reserve(a.size());
		numB.reserve(b.size());
		for (int i = 0; i < a.size(); i++)
		{
			numA.push_back(a[i] - '0');
		}
		for (int i = 0; i < b.size(); i++)
		{
			numB.push_back(b[i] - '0');
		}
		vector<int> multi(a.size() + b.size() - 1, 0);
		multiply(numA, numB, multi);
		for (int i = 0; i < multi.size(); i++)
		{
			cout << multi[i];
		}
		cout << endl;
		numA.clear();
		numB.clear();
		multi.clear();
	}
	return 0;
}
void multiply(const vector<int> &numa, const vector<int> &numb, vector<int> &mul)
{
	int k;
	for (int i = 0; i < numa.size(); i++)
	{
		k = i;
		for (int j = 0; j < numb.size(); j++)
		{
			mul[k++] += numa[i] * numb[j];
		}
	}
	for (k = mul.size() - 1; k >= 0; k--)
	{
		if (mul[k] > 9)
		{
			if (k != 0)
			{
				mul[k - 1] += mul[k] / 10;
				mul[k] %= 10;
			}
			else
			{
				int add = mul[k] / 10;
				mul[k] %= 10;
				mul.insert(mul.begin(), add);
			}
		}
	}
}
