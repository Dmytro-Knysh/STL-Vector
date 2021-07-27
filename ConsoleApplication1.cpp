#include<iostream>
#include<vector>
#include<Windows.h>

using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    int k, p, sum = 0, n, s = 0;
    bool flag = false;
    cout << "Введіть k, p: ";
    cin >> k >> p;
    vector <vector<int> > matrix(k, vector<int>(p, 0));
    vector<int> task_1;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < p; j++)
        {
            cout << "Введіть matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    cout << "Умова: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    //1) рядок, в якому сума елементів максимальна;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            sum += matrix[i][j];
        }
        task_1.insert(task_1.begin() + i, sum);
        sum = 0;
    }
    n = task_1[0];
    int index = 0;
    for (int i = 1; i < task_1.size(); i++)
    {
        if (task_1[i] > n)
        {
            n = task_1[i];
            index = i;
        }
    }
    matrix.erase(matrix.begin() + index);
    cout << "Перше завдання: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    //2) останній стовбець, в якому всі елементи від’ємні.
    index = -1;
    for (int i = 0; i <matrix[i].size(); i++)
    {
        for (int j = 0; j <matrix.size(); j++)
        {
            if (matrix[j][i] < 0)
            {
                s++;
            }
        }
        if (s == matrix.size())
        {
            index = i;
        }
        s = 0;
    }
    if (index>=0)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i].erase(matrix[i].begin() + index);
        }

        cout << "Друге завдання: " << endl;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Неможливо виконати друге завдання";
    }
    return 0;
}

