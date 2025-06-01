#pragma once
#include "IGraph.h"
#include <vector>


class ListGraph : public IGraph
    {
    private:
        std::vector<std::vector<int>> adjacencyLists;

    public:
        explicit ListGraph(int size);
        ListGraph(const IGraph& other);

        void AddEdge(int from, int to) override;
        int VerticesCount() const override;

        std::vector<int> GetNextVertices(int vertex) const override;
        std::vector<int> GetPrevVertices(int vertex) const override;
    };