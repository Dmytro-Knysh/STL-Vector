#include<iostream>
#include<vector>
#include<Windows.h>

using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	int k, t;
	float x;
	vector<float>a; vector<float>b;
	cout << "Input k: ";
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cout << "Input a["<<i<<"]: ";
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < a.size(); i++)
	{
		t = round(a[i]);
		if (a[i] > t)
		{
			b.push_back(a[i]);
		}
	}
	cout << "Vector A: ";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << "Vector B: ";
	for (int i = 0; i < b.size(); i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
