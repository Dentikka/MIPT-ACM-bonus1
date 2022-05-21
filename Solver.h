#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Graph.h"

using std::cin, std::rotate, std::vector, std::string;

class Solver {
private:
    vector <string> strings;
    int n_strings;
    Graph graph;
public:
    Solver(const vector <string> &strings_);

    vector <vector<int>> GetCycles(const vector<int> &assignment);

    vector <string> RotateCyclesGetSuperstrings (const vector <vector<int>> &cycles) const;

    string MakeSuperstring(const vector <string> &superstrings);

    string Solve();
};