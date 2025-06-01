#include "../include/SetGraph.h"
#include <cassert>


SetGraph::SetGraph(int vertices)
        : numVertices_(vertices), adjSets_(vertices)
        {
        }

SetGraph::SetGraph(const IGraph& other) : SetGraph(other.VerticesCount())
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

void SetGraph::AddEdge(int from, int to)
{
    assert(0 <= from && from < numVertices_);
    assert(0 <= to && to < numVertices_);
    adjSets_[from].insert(to);
}

int SetGraph::VerticesCount() const
{
    return numVertices_;
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const
{
    std::vector<int> result;
    for (int v : adjSets_[vertex])
    {
        result.push_back(v);
    }
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> result;
    for (int i = 0; i < numVertices_; ++i)
    {
        if (adjSets_[i].count(vertex))
            result.push_back(i);
    }
    return result;
}