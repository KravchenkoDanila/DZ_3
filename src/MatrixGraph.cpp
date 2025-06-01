#include "../include/MatrixGraph.h"
#include <cassert>


MatrixGraph::MatrixGraph(int vertices)
        : numVertices_(vertices), matrix_(vertices, std::vector<bool>(vertices, false))
        {
        }

MatrixGraph::MatrixGraph(const IGraph& other) : MatrixGraph(other.VerticesCount())
{
    for (int v = 0; v < numVertices_; ++v)
    {
        auto next = other.GetNextVertices(v);
        for (int u : next)
        {
            AddEdge(v, u);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to)
{
    assert(0 <= from && from < numVertices_);
    assert(0 <= to && to < numVertices_);
    matrix_[from][to] = true;
}

int MatrixGraph::VerticesCount() const
{
    return numVertices_;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const
{
    std::vector<int> result;
    for (int i = 0; i < numVertices_; ++i)
    {
        if (matrix_[vertex][i])
            result.push_back(i);
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> result;
    for (int i = 0; i < numVertices_; ++i)
    {
        if (matrix_[i][vertex])
            result.push_back(i);
    }
    return result;
}
