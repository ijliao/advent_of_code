#include <iostream>
#include <sstream>
#include <cstdbool>
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
bool cango(auto& seen, auto& to)
{
    if ("start" == to)
        return false;

    if ("end" == to)
        return true;

    if (isupper(to[0]))
        return true;

    if (0 == seen[to])
        return true;

    if (1 == seen[to]) {
        for (auto& s : seen) {
            if ("start" == s.first)
                continue;

            if ("end" == s.first)
                continue;

            if (isupper((s.first)[0]))
                continue;

            if (s.first == to)
                continue;

            if (s.second == 2)
                return false;
        }

        return true;
    }

    return false;
}

/* g++ -std=c++2a */
void visit(auto& graph, auto& seen, auto& from, auto& count)
{
    if ("end" == from) {
        count++;
        return;
    }

    seen[from]++;

    auto        r = graph.equal_range(from);

    while (r.first != r.second) {
        if (cango(seen, r.first->second))
            visit(graph, seen, r.first->second, count);

        r.first++;
    }

    seen[from]--;
}

int main(void)
{
    unordered_multimap < string, string >       graph;

    input(graph);

    unordered_map < string, int >               seen;

    for (auto& g : graph)
        seen[g.first] = 0;

    unsigned long long int                      count = 0;

    visit(graph, seen, "start", count);

    cout << count << endl;

    return 0;
}
