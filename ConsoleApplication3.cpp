#include<iostream>
#include<vector>
#include<iomanip>
#include<Windows.h>

using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    int k, p, s = 0, h = 0;
    bool flag_1 = true, flag = true, flag_0 = false;
    cout << "Введіть k, p: ";
    cin >> k >> p;
    vector <vector<int> > matrix(k, vector<int>(p, 0));
    vector<int>task_1;
    int t_1, t_2;
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
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    //Поміняти місцями перший та останній рядки, елементи яких утворюють арифметичну прогресію.
    int q;
    for (int i = 0; i < matrix.size(); i++)
    {
        q = matrix[i][1] - matrix[i][0];
        for (int j = 0; j < matrix[i].size() - 1; j++)
        {
            if (matrix[i][j + 1] - matrix[i][j] == q)
            {
                s++;
            }
        }
        if (s == matrix[i].size() - 1)
        {
            task_1.push_back(i);
            flag_0 = true;
        }
        s = 0;
        
    }
    if (flag_0)
    {
        int y = task_1[0];
        int x = task_1[task_1.size() - 1];
        matrix[y].swap(matrix[x]);
        cout << "Перше завдання: " << endl;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cout << setw(3) << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    //Поміняти місцями перший стовпець, що містить більше парних значень, ніж непарних, з першим стовпцем, що містить менше парних значень ніж непарних.
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < matrix.size() && flag; j++)
        {
            if (matrix[j][i] % 2 == 0)
            {
                s++;
            }
            else
            {
                h++;
            }
        }
        if (s > h)
        {
            t_1 = i;
            flag = false;
        }
        s = 0;
        h = 0;
    }
    for (int i = 0; i < p && flag_1; i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[j][i] % 2 != 0)
            {
                s++;
            }
            else
            {
                h++;
            }
    }
        if (s > h)
        {
            t_2 = i;
            flag_1 = false;
        }
        s = 0;
        h = 0;
    }
    if(flag == false && flag_1 == false)
    {
        for (int i = 0; i < matrix.size(); i++)
            swap(matrix[i][t_1], matrix[i][t_2]);
        cout << "Друге завдання: " << endl;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < p; j++)
            {
                cout << setw(3) << matrix[i][j] << " ";
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
