#include <iostream>
#include <sstream>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

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
void connect(auto& graph, auto& a, auto& b)
{
    graph.emplace(a, b);
    graph.emplace(b, a);
}

/* g++ -std=c++2a */
void input(auto& graph)
{
    string          s;

    while (true) {
        getline(cin, s);

        if (cin.eof())
            break;

        auto        v = split(s, '-');

        connect(graph, v[0], v[1]);
    }
}

/* g++ -std=c++2a */
void visit(auto& graph, auto& seen, auto& from, auto& count)
{
    if ("end" == from) {
        count++;
        return;
    }

    if (islower(from[0]))
        seen.emplace(from);

    auto        r = graph.equal_range(from);

    while (r.first != r.second) {
        if (seen.find(r.first->second) == seen.end())
            visit(graph, seen, r.first->second, count);

        r.first++;
    }

    seen.erase(from);
}

int main(void)
{
    unordered_multimap < string, string >       graph;

    input(graph);

    unordered_set < string >                    seen;
    unsigned long long int                      count = 0;

    visit(graph, seen, "start", count);

    cout << count << endl;

    return 0;
}
