#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/* g++ -std=c++2a */
void input(auto& pos)
{
    string          line;

    getline(cin, line);

    stringstream    ss(line);
    string          t;

    while (getline(ss, t, ','))
        pos.push_back(stoi(t));

    sort(begin(pos), end(pos));
}

/* g++ -std=c++2a */
auto fuel(auto n)
{
    return (n * (n + 1)) / 2;
}

int main(void)
{
    vector < int >      pos;

    input(pos);

    decltype(pos)       trial;

    for (auto i = 0; i < pos.size(); i++) {
        int             sum = 0;

        for (auto p : pos)
            sum += fuel(abs(p - i));

        trial.push_back(sum);
    }

    cout << *min_element(begin(trial), end(trial)) << endl;

    return 0;
}
