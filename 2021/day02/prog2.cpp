#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main(void)
{
    int         hor = 0;
    int         dep = 0;
    int         aim = 0;
    string      cmd;
    int         num;

    while (cin >> cmd >> num) {
        if ("forward" == cmd) {
            hor += num;
            dep += num * aim;
        }
        else if ("up" == cmd) {
            aim -= num;
        }
        else if ("down" == cmd) {
            aim += num;
        }

        assert(aim >= 0);
        assert(dep >= 0);
    }

    cout << hor << ' ' << dep << ' ' << hor * dep << endl;

    return 0;
}
