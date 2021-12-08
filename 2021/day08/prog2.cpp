#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

/* g++ -std=c++2a */
void store(auto& seg_map, auto n, auto& s)
{
    auto    it = seg_map.find(n);

    assert(it == seg_map.end());

    seg_map[n] = s;
}

/* g++ -std=c++2a */
void proc_signal(auto& ss, auto& seg_map)
{
    string          t;
    vector < string >   signals;

    while (getline(ss, t, ' ')) {
        if ('|' == t[0])
            break;

        sort(t.begin(), t.end());
        signals.push_back(t);
    }

    while (!signals.empty()) {
        auto        s = signals[0];     signals.erase(signals.begin());
        auto        len = s.length();

        if (2 == len) {
            store(seg_map, 1, s);
            continue;
        }
        else if (3 == len) {
            store(seg_map, 7, s);
            continue;
        }
        else if (4 == len) {
            store(seg_map, 4, s);
            continue;
        }
        else if (7 == len) {
            store(seg_map, 8, s);
            continue;
        }
        else if (5 == len) {
            auto    it = seg_map.find(1);

            if (it != seg_map.end()) {
                vector < char >     v;

                set_difference(it->second.begin(), it->second.end(), s.begin(), s.end(), back_inserter(v));

                if (v.empty()) {
                    store(seg_map, 3, s);
                    continue;
                }
            }
            else {
                signals.push_back(s);
                continue;
            }

            it = seg_map.find(4);

            if (it != seg_map.end()) {
                vector < char >     v;

                set_intersection(it->second.begin(), it->second.end(), s.begin(), s.end(), back_inserter(v));

                if (2 == v.size()) {
                    store(seg_map, 2, s);
                    continue;
                }
                else if (3 == v.size()) {
                    store(seg_map, 5, s);
                    continue;
                }
            }

            signals.push_back(s);
            continue;
        }
        else if (6 == len) {
            auto    it = seg_map.find(1);

            if (it != seg_map.end()) {
                vector < char >     v;

                set_difference(it->second.begin(), it->second.end(), s.begin(), s.end(), back_inserter(v));

                if (!v.empty()) {
                    store(seg_map, 6, s);
                    continue;
                }
            }

            it = seg_map.find(4);

            if (it != seg_map.end()) {
                vector < char >     v;

                set_difference(it->second.begin(), it->second.end(), s.begin(), s.end(), back_inserter(v));

                if (v.empty()) {
                    store(seg_map, 9, s);
                    continue;
                }
            }

            auto        it6 = seg_map.find(6);
            auto        it9 = seg_map.find(9);

            if ((it6 != seg_map.end()) && (it9 != seg_map.end())) {
                store(seg_map, 0, s);
                continue;
            }

            signals.push_back(s);
            continue;
        }
    }

    assert(10 == seg_map.size());
}

/* g++ -std=c++2a */
auto proc_guess(auto& ss, auto& seg_map)
{
    string          t;
    int             res = 0;

    while (getline(ss, t, ' ')) {
        sort(t.begin(), t.end());

        auto        it = find_if(seg_map.begin(), seg_map.end(),
                                    [&t](const auto& p) { return p.second == t; });

        assert(it != seg_map.end());

        res = res * 10 + it->first;
    }

    return res;
}

int main(void)
{
    int     sum = 0;

    while (true) {
        string          line;

        getline(cin, line);

        if (cin.eof())
            break;

        stringstream    ss(line);

        map < int, string >     seg_map;

        proc_signal(ss, seg_map);
        sum += proc_guess(ss, seg_map);
    }

    cout << sum << endl;

    return 0;
}
