#include <iostream>
#include <vector>

using std::cout, std::vector;

class Graph {
private:
    int n_vertex;
    vector<vector<int>> matrix;
public:
    Graph(int n_vertex_): n_vertex(n_vertex_);
    void AddEdge(int from, int to, int length);

    int GetEdge(int from, int to) const;

    vector<int> Assignment();
};