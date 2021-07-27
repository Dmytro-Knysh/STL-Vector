#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<Windows.h>

using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
    int z = 0;
	bool flag = false;
	vector<int>a = { 1, 1, 6, 8, 8, 8, 9, 11, 8 };
    int p = a[0];
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < a.size(); i++)
    {
        if (flag)
        {
            if (a[i] != p)
            {
                z++;
                flag = false;
            }
        }
        else
        {
            if (a[i] == p)
            {
                flag = true;
                if (i == a.size() - 1)
                    z++;
            }
        }
        p = a[i];
    }
    cout << "Кількість серій: " << z<<" Розмір масиву:"<<a.size();
	return 0;
}