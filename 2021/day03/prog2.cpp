#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/* g++ -std=c++2a */
auto find_common(auto& data, auto pos, auto most)
{
    auto    n = 0;

    for (auto& i : data)
        if ('1' == i[pos])
            n++;

    if (true == most) {
        return ((n * 2) >= data.size()) ? '1' : '0';
    }
    else {
        return ((n * 2) < data.size()) ? '1' : '0';
    }
}

/* g++ -std=c++2a */
auto filter_criteria(auto raw, auto most)
{
    auto            len = raw[0].length();
    decltype(raw)   data_src, data_dst;

    data_src = raw;

    for (auto pos = 0; pos < len; pos++) {
        auto    ch = find_common(data_src, pos, most);

        copy_if(
                data_src.begin(), data_src.end(), back_inserter(data_dst),
                [p = pos, c = ch](auto& i) { return (i[p] == c); }
            );

        if (1 == data_dst.size())
            break;

        data_src.clear();
        data_src = data_dst;
        data_dst.clear();
    }

    return stoi(data_dst[0], 0, 2);
}

int main(void)
{
    vector < string >   raw;

    while (true) {
        string      s;

        getline(cin, s);

        if (cin.eof())
            break;

        raw.push_back(s);
    }

    auto        O2 = filter_criteria(raw, true);
    auto        CO2 = filter_criteria(raw, false);

    cout << O2 << ' ' << CO2 << ' ' << O2 * CO2 << endl;

    return 0;
}
