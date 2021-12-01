#include <iostream>

using namespace std;

int main(void)
{
    int     n = 0;
    int     x;
    int     res = 0;

    while (cin >> x) {
        if (x > n) {
            res++;
        }

        n = x;
    }

    cout << --res << endl;

    return 0;
}
