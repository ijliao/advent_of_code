#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef unsigned long long int fish_amount_t;

int main(int argc, char *argv[])
{
    if (argc == 1) {
        cout << argv[0] << " <days>" << endl;
        return 0;
    }

    int                 days = stoi(argv[1]);

    string              line;

    getline(cin, line);

    fish_amount_t       fish[9] = { 0 };
    stringstream        ss(line);
    string              t;

    while (getline(ss, t, ','))
        fish[ stoi(t) ]++;

    for (auto d = 1; d <= days; d++) {
        fish_amount_t   day0 = fish[0];

        move(begin(fish) + 1, end(fish), begin(fish));
        fish[6] += day0;
        fish[8] = day0;
    }

    fish_amount_t       sum = 0;

    for (auto& f : fish)
        sum += f;

    cout << sum << endl;

    return 0;
}
