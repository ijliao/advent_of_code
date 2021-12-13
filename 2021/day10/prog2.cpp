#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/* g++ -std=c++2a */
string findincomplete(auto& cmd)
{
    vector < char >     chunk;
    string              res;

    for (auto c : cmd) {
        switch (c) {
            case '(' :
            case '[' :
            case '{' :
            case '<' :
                chunk.push_back(c);
                break;
            case ')' :
                if ('(' == chunk.back()) chunk.pop_back(); else return "I";
                break;
            case ']' :
                if ('[' == chunk.back()) chunk.pop_back(); else return "I";
                break;
            case '}' :
                if ('{' == chunk.back()) chunk.pop_back(); else return "I";
                break;
            case '>' :
                if ('<' == chunk.back()) chunk.pop_back(); else return "I";
                break;
            default :
                assert(true);
        }
    }

    copy(chunk.rbegin(), chunk.rend(), back_inserter(res));

    return res;
}

/* g++ -std=c++2a */
long long int calscore(auto& cmd)
{
    auto            str = findincomplete(cmd);

    if ("I" == str)
        return -1;

    long long int   score = 0;

    for (auto c : str) {
        score *= 5;
        switch (c) {
            case '(' : score += 1; break;
            case '[' : score += 2; break;
            case '{' : score += 3; break;
            case '<' : score += 4; break;
            default : assert(true);
        }
    }

    return score;
}

int main(void)
{
    string          cmd;
    vector < long long int >    score;

    while (true) {
        getline(cin, cmd);

        if (cin.eof())
            break;

        long long int   s = calscore(cmd);

        if (-1 != s)
            score.push_back(s);
    }

    sort(score.begin(), score.end());

    cout << score[score.size() / 2] << endl;

    return 0;
}
