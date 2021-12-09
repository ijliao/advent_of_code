#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/* g++ -std=c++2a */
auto is_low(auto& hmap, auto x, auto y)
{
    int         h = hmap.size() - 1;
    int         w = hmap[0].size() - 1;

    int         up    = (0 == x) ? INT_MAX : hmap[x - 1][y    ];
    int         down  = (h == x) ? INT_MAX : hmap[x + 1][y    ];
    int         left  = (0 == y) ? INT_MAX : hmap[x    ][y - 1];
    int         right = (w == y) ? INT_MAX : hmap[x    ][y + 1];

    int         v = hmap[x][y];

    if ((v < up) && (v < down) && (v < left) && (v < right))
       return v - '0';

    return -1;
}

int main(void)
{
    string              line;
    vector < string >   hmap;

    while (true) {
        getline(cin, line);

        if (cin.eof())
            break;

        hmap.push_back(line);
    }

    int                 sum = 0;

    for (auto x = 0; x < hmap.size(); x++) {
        for (auto y = 0; y < hmap[0].size(); y++) {
            int         res = is_low(hmap, x, y);

            if (res >= 0)
                sum += res + 1;
        }
    }

    cout << sum << endl;

    return 0;
}
