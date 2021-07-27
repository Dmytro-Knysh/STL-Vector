#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<Windows.h>

using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    int first_value, last_value, n, k, m, p = 0, q = 0, random_number;
    vector<int>a;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << endl << "Enter the range (a, b): ";
    cin >> first_value >> last_value;
    cout << endl << "Введіть k: ";
    cin >> k;
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        random_number = first_value + rand() % (last_value);
        a.push_back(random_number);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    //shift to the left gradually moving the elements
    for (int j = 0; j < k; j++)
    {
        for (int i = 0; i < a.size() / 2 - 1; i++)
        {
            a[i] = a[i + 1];
            a[i + 1] = 0;

        }
    }
    //shift to the left using vector class methods
    for (int i = 0; i < k; i++)
    {
      a.insert(a.begin() + a.size() / 2, 0);
      a.erase(a.begin());
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 0)
        {
            m = i;
        }
    }
    //shift to the right using vector class methods
    for (int i = 0; i < k; i++)
    {
      a.insert(a.begin()+m, 0);
      a.erase(a.begin() + a.size() - 1);
    }
    //shift to the right gradually moving the elements
    for (int j = 0; j < k; j++)
    {
        for (int i = a.size() - 1; i > m; i--)
        {
            a[i] = a[i - 1];
            a[i - 1] = 0;
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
