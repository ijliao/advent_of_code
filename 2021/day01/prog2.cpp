#include <iostream>

using namespace std;

int main(void)
{
    int     data1, data2, data3;
    int     sum, sum_p = 0;
    int     res = 0;

    cin >> data1 >> data2;

    while (cin >> data3) {
        sum = data1 + data2 + data3;

        if (sum > sum_p)
            res++;

        sum_p = sum;
        data1 = data2;
        data2 = data3;
    }

    cout << --res << endl;

    return 0;
}
