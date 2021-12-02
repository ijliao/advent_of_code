#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main(void)
{
    int         hor = 0;
    int         dep = 0;
    string      cmd;
    int         num;

    while (cin >> cmd >> num) {
        if ("forward" == cmd) {
            hor += num;
        }
        else if ("up" == cmd) {
            dep -= num;

            assert(dep >= 0);
        }
        else if ("down" == cmd) {
            dep += num;
        }
    }

    cout << hor << ' ' << dep << ' ' << hor * dep << endl;

    return 0;
}
