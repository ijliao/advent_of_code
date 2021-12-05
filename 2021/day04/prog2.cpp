#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct {
    int     num[25];
} board_t;

const auto MAGIC = 12345;

/* g++ -std=c++2a */
void process(auto& b, auto num)
{
    for (auto& n : b.num) {
        if (num == n) {
            n += MAGIC;
            return;
        }
    }
}

/* g++ -std=c++2a */
auto check(auto& b)
{
    for (auto x = 0; x < 5; x++) {
        auto    sum = 0;

        for (auto y = 0; y < 5; y++)
            sum += b.num[x * 5 + y];

        if (sum > (MAGIC * 5))
            return true;
    }

    for (auto x = 0; x < 5; x++) {
        auto    sum = 0;

        for (auto y = 0; y < 5; y++)
            sum += b.num[x + y * 5];

        if (sum > (MAGIC * 5))
            return true;
    }

    return false;
}

/* g++ -std=c++2a */
auto bingo(auto& b)
{
    auto    sum = 0;

    for (auto& n : b.num)
        if (n < MAGIC)
            sum += n;

    return sum;
}

int main(void)
{
    string              cmd;
    vector < board_t >  boards;

    getline(cin, cmd);

    while (true) {
        board_t     b;

        for (auto& n : b.num)
            cin >> n;

        if (cin.eof())
            break;

        boards.push_back(b);
    }

    stringstream        ss(cmd);
    string              t;

    while (getline(ss, t, ',')) {
        auto        num = stoi(t);

        for (auto i = 0; i < boards.size(); i++) {
            auto&       b = boards[i];

            process(b, num);

            if (check(b)) {
                if (1 == boards.size()) {
                    auto        res = bingo(b);

                    cout << num << ' ' << res << ' ' << num * res << endl;
                    exit(0);
                }

                boards.erase(boards.begin() + i);
                i--;
            }
        }
    }

    return 0;
}
