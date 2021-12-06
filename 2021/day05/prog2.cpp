#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int   SIZE = 1000;
int         cloud[SIZE][SIZE];

/* g++ -std=c++2a */
void process(auto& cmd)
{
    for (auto i = 0; i < cmd.length(); i++)
        if (!isdigit(cmd[i]))
            cmd[i] = ' ';

    stringstream    ss(cmd);
    int             x1, y1, x2, y2;

    ss >> x1 >> y1 >> x2 >> y2;

    if (!((x1 == x2) || (y1 == y2) ||
          (abs(x1 - x2) == abs(y1 - y2))
         )
       )
    {
        return;
    }

    auto    xdir = (x1 == x2) ? 0 : ((x2 > x1) ? 1 : -1);
    auto    ydir = (y1 == y2) ? 0 : ((y2 > y1) ? 1 : -1);

    if (x1 == x2) {
        for (auto y = y1; y != y2 + ydir; y += ydir)
            cloud[x1][y]++;
    }
    else if (y1 == y2) {
        for (auto x = x1; x != x2 + xdir; x += xdir)
            cloud[x][y1]++;
    }
    else {
        for (auto x = x1, y = y1; (x != x2 + xdir) && (y != y2 + ydir); x += xdir, y += ydir)
            cloud[x][y]++;
    }
}

auto overlap(void)
{
    int     res = 0;

    for (auto x = 0; x < SIZE; x++)
        for (auto y = 0; y < SIZE; y++)
            if (cloud[x][y] >= 2)
                res++;

    return res;
}

int main(void)
{
    while (true) {
        string          cmd;

        getline(cin, cmd);
        if (cin.eof())
            break;

        process(cmd);
    }

    cout << overlap() << endl;

    return 0;
}
