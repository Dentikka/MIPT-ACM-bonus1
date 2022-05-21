#include <Solver.h>

Solver::Solver (const vector<string>& strings_): strings(strings_),
                                         n_strings(strings_.size()),
                                         graph(Graph(strings_.size())) {
    for (int i = 0; i < n_strings; ++i) {
        for (int j = 0; j < n_strings; ++j) {
            graph.AddEdge(i, j,
                          Overlap(strings_[i], strings_[j]));
        }
    }
}

vector<vector<int>> Solver::GetCycles(const vector<int>& assignment) {
    vector<vector<int>> cycles;
    vector<int> cycle;
    vector<bool> mark(assignment.size());
    for (int i = 0; i < assignment.size(); ++i) {
        if (mark[i]) {
            continue;
        }
        cycle.push_back(i);
        mark[i] = true;
        if (assignment[i] == cycle[0]) {
            cycles.push_back(cycle);
            cycle.clear();
            i = 0;
        }
        else {
            i = assignment[i] - 1;
        }
    }
    return cycles;
}

vector<string> Solver::RotateCyclesGetSuperstrings
        (const vector<vector<int>>& cycles) const {
    vector<string> superstrings;
    for (vector<int> cycle: cycles) {
        string superstring;
        vector<int> overlaps;
        for (int i = 0; i < cycle.size() - 1; ++i) {
            overlaps.push_back(graph.GetEdge(cycle[i], cycle[i+1]));
        }
        int min = graph.GetEdge(cycle[cycle.size()-1], cycle[0]);
        int shift = 0;
        for (int i = 0; i < overlaps.size(); ++i) {
            if (overlaps[i] < min) {
                min = overlaps[i];
                shift = i + 1;
            }
            rotate(overlaps.begin(), overlaps.begin() + shift, overlaps.end());
            for (int i =0; i < cycle.size() - 1; ++i) {
                superstring += Prefix(strings[cycle[i]],
                                      graph.GetEdge(cycle[i], cycle[i+1]));
            }
            superstring += strings[cycle[cycle.size()-1]];
        }
        superstrings.push_back(superstring);
    }
    return superstrings;
}

string Solver::MakeSuperstring(const vector<string>& superstrings) {
    string superstring;
    for (const auto& partial_superstring: superstrings) {
        superstring += partial_superstring;
    }
    return superstring;
}

string Solver::Solve() {
    auto assignment = graph.Assignment();
    auto cycles = GetCycles(assignment);
    auto superstrings = RotateCyclesGetSuperstrings(cycles);
    auto superstring = MakeSuperstring(superstrings);
    return superstring;
}
