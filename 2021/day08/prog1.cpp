#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
    int                 count = 0;

    while (true) {
        string          line;

        getline(cin, line);

        if (cin.eof())
            break;

        stringstream    ss(line);
        string          t;

        while (getline(ss, t, ' ')) {
            if ('|' == t[0])
                break;
        }

        while (getline(ss, t, ' ')) {
            size_t      len = t.length();

            if ((2 == len) || (4 == len) || (3 == len) || (7 == len))
                count++;
        }
    }

    cout << count << endl;

    return 0;
}
