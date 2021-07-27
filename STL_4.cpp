#include<iostream>
#include<vector>
#include<Windows.h>

using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    int k, t;
    bool flag = false;
    vector<int>a = { 45, 45, 38, 37, 22, 22, 22, 11, 10, 1 };
    cout << "Input k: ";
    cin >> k;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "size " << a.size() << " max " << a.max_size() << " capacity " << a.capacity() << endl;
    for (int i = a.size()-1; i > -1; i--)
    {
        for (int j = a.size()-1; j > -1; j--)
        {
            if (i != j)
            {
                if (a[i] == a[j])
                {
                     a.erase(a.begin() + j);
                }
            }
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << "size " << a.size() << " max " << a.max_size() << " capacity " << a.capacity() << endl;
    t = a.size();
    for (int i = 0; i < t; i++)
    {
        if (a[i] % 2 != 0)
        {
            a.insert(a.begin() + i, k);
            i++;
            t++;
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << "size " << a.size() << " max " << a.max_size() << " capacity " << a.capacity() << endl;
    return 0; 
}
