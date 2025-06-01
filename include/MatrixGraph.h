#pragma once
#include "IGraph.h"
#include <vector>


class MatrixGraph : public IGraph
    {
    private:
        int numVertices_;
        std::vector<std::vector<bool>> matrix_;

    public:
        explicit MatrixGraph(int vertices);
        MatrixGraph(const IGraph& other);

        void AddEdge(int from, int to) override;
        int VerticesCount() const override;

        std::vector<int> GetNextVertices(int vertex) const override;
        std::vector<int> GetPrevVertices(int vertex) const override;
    };