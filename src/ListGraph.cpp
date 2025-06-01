#include "../include/ListGraph.h"
#include <cassert>


ListGraph::ListGraph(int size)
        : adjacencyLists(size)
        {
        }

ListGraph::ListGraph(const IGraph& other)
{
    adjacencyLists.resize(other.VerticesCount());
    for (int i = 0; i < other.VerticesCount(); ++i)
    {
        adjacencyLists[i] = other.GetNextVertices(i);
    }
}

void ListGraph::AddEdge(int from, int to)
{
    assert(0 <= from && from < adjacencyLists.size());
    assert(0 <= to && to < adjacencyLists.size());
    adjacencyLists[from].push_back(to);
}

int ListGraph::VerticesCount() const
{
    return static_cast<int>(adjacencyLists.size());
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const
{
    if (vertex >= 0 && vertex < adjacencyLists.size())
        return adjacencyLists[vertex];
    return {};
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> result;
    for (int from = 0; from < adjacencyLists.size(); ++from)
    {
        for (int to : adjacencyLists[from])
        {
            if (to == vertex)
                result.push_back(from);
        }
    }
    return result;
}
