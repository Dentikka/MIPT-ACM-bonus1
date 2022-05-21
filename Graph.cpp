#include <Graph.h>


Graph::Graph(int n_vertex_): n_vertex(n_vertex_) {
    matrix.resize(n_vertex_, vector<int> (n_vertex_));
}
void Graph::AddEdge(int from, int to, int length) {
    matrix[from][to] = length;
}

int Graph::GetEdge(int from, int to) const {
    return matrix[from][to];
}

vector<int> Graph::Assignment() {
    vector<vector<bool>> not_allow(n_vertex, vector<bool> (n_vertex));
    vector<int> assignment(n_vertex);
    while (true) {
        int max = -1, maxi = -1, maxj = -1;
        for (int i = 0; i < n_vertex; ++i) {
            for (int j = 0; j < n_vertex; ++j) {
                if (not_allow[i][j]) {
                    continue;
                }
                if (matrix[i][j] > max) {
                    max = matrix[i][j];
                    maxi = i;
                    maxj = j;
                }
            }
        }
        if (max == -1) {
            break;
        }
        assignment[maxi] = maxj;
        for (int i = 0; i < n_vertex; ++i) {
            not_allow[maxi][i] = true;
            not_allow[i][maxj] = true;
        }
    }
    return assignment;