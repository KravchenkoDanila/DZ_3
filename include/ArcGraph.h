#pragma once
#include "IGraph.h"
#include <vector>


class ArcGraph : public IGraph
    {
    private:
        int numVertices_;
        std::vector<std::pair<int, int>> edges_;

    public:
        explicit ArcGraph(int vertices);
        ArcGraph(const IGraph& other);

        void AddEdge(int from, int to) override;
        int VerticesCount() const override;

        std::vector<int> GetNextVertices(int vertex) const override;
        std::vector<int> GetPrevVertices(int vertex) const override;
    };