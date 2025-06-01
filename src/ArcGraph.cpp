#include "../include/ArcGraph.h"
#include <cassert>


ArcGraph::ArcGraph(int vertices) : numVertices_(vertices)
{
}

ArcGraph::ArcGraph(const IGraph& other) : ArcGraph(other.VerticesCount())
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

void ArcGraph::AddEdge(int from, int to)
{
    assert(0 <= from && from < numVertices_);
    assert(0 <= to && to < numVertices_);
    edges_.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const
{
    return numVertices_;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const
{
    std::vector<int> result;
    for (auto [f, t] : edges_)
    {
        if (f == vertex)
            result.push_back(t);
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> result;
    for (auto [f, t] : edges_)
    {
        if (t == vertex)
            result.push_back(f);
    }
    return result;
}