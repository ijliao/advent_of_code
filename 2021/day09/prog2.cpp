#include <iostream>
#include <vector>

using namespace std;

/* g++ -std=c++2a */
int expand(auto& hmap, auto x, auto y)
{
    hmap[x][y] = '9';

    int         h = hmap.size() - 1;
    int         w = hmap[0].size() - 1;

    int         up    = (0 == x) ? 0 : (('9' != hmap[x - 1][y    ]) ? expand(hmap, x - 1, y    ) : 0);
    int         down  = (h == x) ? 0 : (('9' != hmap[x + 1][y    ]) ? expand(hmap, x + 1, y    ) : 0);
    int         left  = (0 == y) ? 0 : (('9' != hmap[x    ][y - 1]) ? expand(hmap, x    , y - 1) : 0);
    int         right = (w == y) ? 0 : (('9' != hmap[x    ][y + 1]) ? expand(hmap, x    , y + 1) : 0);

    return 1 + up + down + left + right;
}

/* g++ -std=c++2a */
auto basin(auto& hmap)
{
    vector < int >      res;

    for (auto x = 0; x < hmap.size(); x++)
        for (auto y = 0; y < hmap[0].size(); y++)
            if ('9' != hmap[x][y])
                res.push_back(expand(hmap, x, y));

    sort(res.begin(), res.end(), greater< int >());

    cout << res[0] * res[1] * res[2] << endl;
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

    basin(hmap);

    return 0;
}
