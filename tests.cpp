#include "Solver.h"
#include "StringFunctions.h"
#include "gtest/gtest.h"

TEST(Graph, Assignment) {
    Graph graph(5);
    graph.AddEdge(0, 1, 1);
    graph.AddEdge(1, 2, 2);
    graph.AddEdge(2, 3, 1);
    graph.AddEdge(3, 4, 2);
    graph.AddEdge(4, 5, 1);
    graph.AddEdge(5, 0, 2);
    ASSERT_EQ(graph.Assignment(), vector<int>(0, 1, 2, 3, 4, 5));
}

TEST(Graph, Assignment) {
Graph test_gr(6);
test_gr.AddEdge(0,2,1);
test_gr.AddEdge(1,0,1);
test_gr.AddEdge(2,1,2);
test_gr.AddEdge(3,4,2);
test_gr.AddEdge(3,5,1);
test_gr.AddEdge(4,3,1);
ASSERT_EQ(max_assignment(test_gr), std::vector<size_t>({2,0,1,4,3,5}));
}

TEST(Overlap, Simple) {
    string a = "aba";
    string b = "caba";
    ASSERT_EQ(Overlap(b, a), 3);
}
