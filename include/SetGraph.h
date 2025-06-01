#pragma once
#include "IGraph.h"
#include <vector>
#include <set>


class SetGraph : public IGraph
    {
    private:
        int numVertices_;
        std::vector<std::set<int>> adjSets_;

    public:
        explicit SetGraph(int vertices);
        SetGraph(const IGraph& other);

        void AddEdge(int from, int to) override;
        int VerticesCount() const override;

        std::vector<int> GetNextVertices(int vertex) const override;
        std::vector<int> GetPrevVertices(int vertex) const override;
    };