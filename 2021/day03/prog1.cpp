#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define BIT(n)      (1UL << (n))
#define MASK(n)     (BIT(n) - 1)

int main(void)
{
    int         n = 0;
    string      s;
    int         cal[32] = { 0 };
    int         len;
    unsigned int    gamma = 0, epsilon;

    while (cin >> s) {
        n++;
        len = s.length();
        for (auto i = 0; i < len; i++)
            if ('1' == s[i])
                cal[i]++;
    }

    for (auto i = 0; i < len; i++) {
        gamma <<= 1;
        gamma |= (cal[i] > (n / 2)) ? 1 : 0;
    }

    epsilon = ~gamma & MASK(len);

    cout << gamma << ' ' << epsilon << ' ' << gamma * epsilon << endl;

    return 0;
}
