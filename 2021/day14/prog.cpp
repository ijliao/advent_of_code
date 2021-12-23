#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/* g++ -std=c++2a */
void getpolymer(auto& polymer)
{
    string              s;

    getline(cin, s);

    polymer["x" + s.substr(0, 1)] = 1;

    for (size_t i = 0; i < s.length() - 1; i++)
        polymer[s.substr(i, 2)]++;

    polymer[s.substr(s.length() - 1) + "x"] = 1;

    getline(cin, s);
}

/* g++ -std=c++2a */
void getformula(auto& formula)
{
    while (true) {
        string              s;

        getline(cin, s);

        if (cin.eof())
            break;

        formula[s.substr(0, 2)] = s.substr(6);
    }
}

/* g++ -std=c++2a */
void process(auto& polymer, auto& formula)
{
    unordered_map < string, unsigned long long int >        res;

    for (auto& p : polymer) {
        auto    itor = formula.find(p.first);

        if (itor == formula.end()) {
            res.emplace(p);
        }
        else {
            res[itor->first[0] + itor->second] += p.second;
            res[itor->second + itor->first[1]] += p.second;
        }
    }

    polymer.clear();
    polymer = res;
}

/* g++ -std=c++2a */
void classify(auto& polymer)
{
    unordered_map < char, unsigned long long int >      particles;

    for (auto& p : polymer) {
        particles[p.first[0]] += p.second;
        particles[p.first[1]] += p.second;
    }

    particles.erase(particles.find('x'));

    auto comp = [](auto& a, auto& b) { return a.second < b.second; };
    auto max = max_element(particles.begin(), particles.end(), comp)->second / 2;
    auto min = min_element(particles.begin(), particles.end(), comp)->second / 2;

    cout << max << ' ' << min << ' ' << max - min << endl;
}

int main(int argc, char *argv[])
{
    if (argc == 1) {
        cout << argv[0] << " <steps>" << endl;
        return 0;
    }

    auto        steps = stoi(argv[1]);

    unordered_map < string, unsigned long long int >        polymer;
    unordered_map < string, string >                        formula;

    getpolymer(polymer);
    getformula(formula);

    for (decltype(steps) i = 0; i < steps; i++) {
        process(polymer, formula);
    }

    classify(polymer);

    return 0;
}
