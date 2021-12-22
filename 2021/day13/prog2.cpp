#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum {
    AXIS_X,
    AXIS_Y,
};

/* g++ -std=c++2a */
auto split(auto& s, auto delim = ' ')
{
    stringstream            ss(s);
    vector < string >       v;
    string                  t;

    while (getline(ss, t, delim))
        v.emplace_back(t);

    return v;
}

/* g++ -std=c++2a */
void fold(auto& paper, auto n, auto dir)
{
    for_each(paper.begin(), paper.end(),
            [n, dir](auto& dot) {
                if (AXIS_X == dir) {
                    if (dot.first > n)
                        dot.first = n - (dot.first - n);
                }
                else { /* AXIS_Y */
                    if (dot.second > n)
                        dot.second = n - (dot.second - n);
                }
            } );
}

auto coord_cmp = [](auto& x, auto& y) { return (x.second < y.second) || ((x.second == y.second) && (x.first < y.first)); };

/* g++ -std=c++2a */
void draw(auto& paper)
{
    vector < vector < char > >      matrix(10, vector < char > (40, '.'));

    for (auto& dot : paper)
        matrix[dot.second][dot.first] = '#';

    for (auto& y : matrix) {
        for (auto& x : y)
            cout << x;

        cout << endl;
    }

    cout << endl;
}

int main(void)
{
    vector < pair < int, int > >    paper;

    string          s;

    while (true) {
        getline(cin, s);

        if (cin.eof())
            break;

        if (s.empty())
            break;

        auto        v = split(s, ',');

        paper.emplace_back(stoi(v[0]), stoi(v[1]));
    }

    sort(paper.begin(), paper.end(), coord_cmp);

    while (true) {
        getline(cin, s);

        if (cin.eof())
            break;

        auto        x = s.find("x");
        if (string::npos != x)
            fold(paper, stoi(s.substr(x + 2)), AXIS_X);

        auto        y = s.find("y");
        if (string::npos != y)
            fold(paper, stoi(s.substr(y + 2)), AXIS_Y);
    }

    draw(paper);

    return 0;
}
