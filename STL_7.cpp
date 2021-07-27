#include<iostream>
#include<vector>
#include<iomanip>
#include<Windows.h>

using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    int k, p, n, s = 0;
    bool flag = false;
    cout << "Input k, p: ";
    cin >> k >> p;
    vector <vector<int> > matrix(k, vector<int>(p, 0));
    vector<int> task_1; 
    vector<int>vstavka(p, 2);
    vector<int>vstavka_1(k, 0);
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
            cout << setw(3) <<matrix[i][j] << " ";
        }
        cout << endl;
    }
    //1)In front of the line, the elements of which are even, insert a line with twos.
    for (int i = 0; i < matrix.size() && flag == false; i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] % 2 == 0)
            {
                s++;
                n = i;
            }
        }
        if (s == matrix[i].size())
        {
            flag = true;
        }
        else
        {
            s = 0;
        }
    }
    if (flag == true)
    {
        matrix.insert(matrix.begin() + n, vstavka);

        cout << endl << "Task 1:" << endl;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cout << setw(3) << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Unable to perform first interference" << endl;
    }
    //After the column containing the minimum element of the matrix, insert the column with zeros.
    int min = matrix[0][0] +1;
    int min_index = -1;
    for (int i = 0; i < p; i++)
        for (int j = 0; j < matrix.size(); j++)
            if (min > matrix[j][i])
            {
                min = matrix[j][i];
                min_index = i;
            }
    if (min_index >= 0)
    {
        for (int i = 0; i < matrix.size(); i++)
            matrix[i].insert(matrix[i].begin() + min_index + 1, 0);
        cout << endl << "Task 2:" << endl;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cout << setw(3) << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Unable to complete second task";
    }
    return 0;
}
