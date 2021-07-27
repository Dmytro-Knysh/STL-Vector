#include<iostream>
#include<vector>
#include<iomanip>
#include<Windows.h>

using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    int k, p, h = 0, q = 0, v = 0, sum = 0, d = 0;
    bool flag = false;
    bool flag_1 = false;
    cout << "Введіть k, p ( p >= k ): ";
    cin >> k >> p;
    vector <vector<int> > matrix(k, vector<int>(p, 0));
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
    //Знайти кільькості додатних елементів для головної діагоналі та для всіх діагоналей, що їй паралельні.
    for (int i = 0; i < matrix.size(); i++)
    {
        h = i;
        v = 0;
        for (int j = 0; j < matrix.size() && v < matrix[j].size() && h < matrix.size(); j++)
        {
            if (matrix[h][v] == matrix[k - 1][0])
            {
                break;
            }
            if (matrix[h][v] > 0)
            {
                q++;
            }
            h++;
            v++;
        }
        d++;
       
    }
    h = 0; v = 1;
    for (int i = 1; i < matrix.size(); i++)
    {
        h = 0;
        v = i;
        for (int j = 0; j < matrix.size() && v < matrix[j].size() && h < matrix.size(); j++)
        {
            if (matrix[h][v] == matrix[0][p-1])
            {
                break;
            }
            if (matrix[h][v] > 0)
            {
                q++;
            }
            h++;
            v++;
        }
        d++;
    }
   cout << "Кількість додатних елементів для головної діагоналі та для всіх діагоналей, що їй паралельні: " << q << endl;
    //Знайти суми непарних значень для елементів побічної діагоналі та для кожної діагоналі, що їй паралельні
    int u = 0;
    int t = 0;
    for (int j = 2; j < d+1/2; j++)
    {
        u = p - j;
        for (int i = matrix.size() - 1; i >= 0 && u < p && u>=0; i--)
        {
            if (matrix[i][u] % 2 != 0)
            {
                sum += matrix[i][u];
            }
            u++;
        }
    }
    u = 0;
    t = 2;

    for (int j = (d/2)+1; j < d - 1;j++)
    {

        for (int i = matrix.size() - t; i >= 0 && u < p; i--)
        {
            if (matrix[i][u] % 2 != 0)
            {
                sum += matrix[i][u];
            }
            u++;
        }
        u = 0;
        t++;

    }
    cout << "Сума непарних значень для елементів побічної діагоналі та для кожної діагоналі, що їй паралельні: " << sum;
    return 0;
}

