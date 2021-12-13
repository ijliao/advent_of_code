#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/* g++ -std=c++2a */
char findcorrupt(auto& cmd)
{
    vector < char >     chunk;

    for (auto c : cmd) {
        switch (c) {
            case '(' :
            case '[' :
            case '{' :
            case '<' :
                chunk.push_back(c);
                break;
            case ')' :
                if ('(' == chunk.back()) chunk.pop_back(); else return c;
                break;
            case ']' :
                if ('[' == chunk.back()) chunk.pop_back(); else return c;
                break;
            case '}' :
                if ('{' == chunk.back()) chunk.pop_back(); else return c;
                break;
            case '>' :
                if ('<' == chunk.back()) chunk.pop_back(); else return c;
                break;
            default :
                assert(true);
        }
    }

    return ' ';
}

/* g++ -std=c++2a */
int calscore(auto& cmd)
{
    auto            c = findcorrupt(cmd);

    switch (c) {
        case ' ' : return     0; break;
        case ')' : return     3; break;
        case ']' : return    57; break;
        case '}' : return  1197; break;
        case '>' : return 25137; break;
        default : assert(true);
    }

    return -1;
}

int main(void)
{
    string          cmd;
    int             sum = 0;

    while (true) {
        getline(cin, cmd);

        if (cin.eof())
            break;

        auto        score = calscore(cmd);
        sum += score;
    }

    cout << sum << endl;

    return 0;
}
