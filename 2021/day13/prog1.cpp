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
void dedup(auto& paper)
{
    sort(paper.begin(), paper.end(), coord_cmp);

    paper.erase(
            unique(paper.begin(), paper.end(), [](auto& x, auto& y) { return ((x.first == y.first) && (x.second == y.second)); } ),
            paper.end()
        );
}

/* g++ -std=c++2a */
int calcdot(auto& paper)
{
    return paper.size();
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

        dedup(paper);

        cout << "dot = " << calcdot(paper) << endl;

        break;
    }

    return 0;
}
