#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdbool>

using namespace std;

/* g++ -std=c++2a */
void input(auto& energy)
{
    while (true) {
        string      s;

        getline(cin, s);

        if (cin.eof())
            break;

        energy.emplace_back();

        for (const auto c : s)
            energy.back().emplace_back(c - '0');
    }
}

/* g++ -std=c++2a */
int flash(auto& energy)
{
    int     sx = energy.size();
    int     sy = energy[0].size();

    vector < vector < bool > >      ed(sx, vector < bool >(sy, false));

    bool    again;

    do {
        again = false;

        for (int x = 0; x < sx; x++) {
            for (int y = 0; y < sy; y++) {
                if ((energy[x][y] > 9) && !ed[x][y]) {
                    again = true;
                    ed[x][y] = true;

                    int     xm = ( 0     == x) ? 0      : x - 1;
                    int     xM = (sx - 1 == x) ? sx - 1 : x + 1;
                    int     ym = ( 0     == y) ? 0      : y - 1;
                    int     yM = (sy - 1 == y) ? sy - 1 : y + 1;

                    for (auto tx = xm; tx <= xM; tx++)
                        for (auto ty = ym; ty <= yM; ty++)
                            energy[tx][ty]++;
                }
            }
        }
    } while (again);

    int     res = 0;

    for (auto& x : energy) {
        for (auto& y : x) {
            if (y > 9) {
                res++;
                y = 0;
            }
        }
    }

    return res;
}

/* g++ -std=c++2a */
auto round(auto& energy)
{
    for (auto& x : energy)
        for (auto& y : x)
            y++;

    return flash(energy);
}

int main(void)
{
    vector < vector < int > >       energy;

    input(energy);

    int         sum = 0;

    for (auto i = 1; i <= 100; i++)
        sum += round(energy);

    cout << sum << endl;

    return 0;
}
