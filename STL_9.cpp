#include<iostream>
#include<vector>
#include<iomanip>
#include<Windows.h>

using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    int k, p, s = 0, h = 0;
    bool flag = true;
    cout << "Введіть k(k = p): ";
    cin >> k;
    p = k;
    vector <vector<int> > matrix(k, vector<int>(p, 0));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < p; j++)
        {
            cout << "Input matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    cout << "Condition: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Home diagonal: ";
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << matrix[i][i] << " ";
    }
    cout << endl << "Side diagonal: ";
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << matrix[i][matrix.size() - 1 - i] << " ";
    }
   cout << endl;
   for (int i = 0; i < matrix.size() / 2; i++)
   {
       for (int j = i; j < matrix.size() - i ; j++)
       {
           matrix[i][j] = 0;
       }
   }
   for (int i = matrix.size() / 2; i < matrix.size(); i++)
   {
       for (int j = matrix.size() - i - 1; j <= i; j++)
       {
           matrix[i][j] = 0;
       }
   }
   cout << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
