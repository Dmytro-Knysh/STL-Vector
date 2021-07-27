#include<iostream>
#include<vector>
#include<Windows.h>

using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    int q;
    vector<int>a = { 1, 2, 8, 23, 156 };
    vector<int>b = { -23, -14, -12, 0, 45 };
    vector<int>c;

    int i=0, j=0;
    for (int k = 0; k < a.size() + b.size(); k++) {

        if (i > a.size() - 1) {
            int q = b[j];
            b.insert(b.begin() + k, q);
            j++;
        }
        else if (j > b.size() - 1) {
            int q = a[i];
            c.insert(c.begin() + k, q);
            i++;
        }
        else if (a[i] < b[j]) {
            int q = a[i];
            c.insert(c.begin() + k, q);
            i++;
        }
        else {
            int y = b[j];
            c.insert(c.begin() + k, y);
            j++;
        }
    }
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }
    return 0;
}


    