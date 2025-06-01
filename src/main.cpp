#include <iostream>
#include <vector>
#include <queue>

#include "../include/IGraph.h"
#include "../include/ListGraph.h"
#include "../include/MatrixGraph.h"
#include "../include/SetGraph.h"
#include "../include/ArcGraph.h"


void BFS(const IGraph& graph, int vertex, std::vector<bool>& visited, const std::function<void(int)>& func)
{
    std::queue<int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty())
    {
        int currentVertex = qu.front();
        qu.pop();

        func(currentVertex);

        for (int nextVertex : graph.GetNextVertices(currentVertex))
        {
            if (!visited[nextVertex])
            {
                visited[nextVertex] = true;
                qu.push(nextVertex);
            }
        }
    }
}


void mainBFS(const IGraph& graph, const std::function<void(int)>& func)
{
    std::vector<bool> visited(graph.VerticesCount(), false);
    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        if (!visited[i])
            BFS(graph, i, visited, func);
    }
}


void DFS(const IGraph& graph, int vertex, std::vector<bool>& visited, const std::function<void(int)>& func)
{
    visited[vertex] = true;
    func(vertex);

    for (int nextVertex : graph.GetNextVertices(vertex))
    {
        if (!visited[nextVertex])
            DFS(graph, nextVertex, visited, func);
    }
}


void mainDFS(const IGraph& graph, const std::function<void(int)>& func)
{
    std::vector<bool> visited(graph.VerticesCount(), false);
    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        if (!visited[i])
            DFS(graph, i, visited, func);
    }
}

int main()
{
    ListGraph listGraph(7);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);


    MatrixGraph matrixGraph(listGraph);
    ArcGraph arcGraph(matrixGraph);
    SetGraph setGraph(arcGraph);


    auto testGraph = [](const IGraph& graph, const std::string& name)
    {
        std::cout << name << "\n";
        std::cout << "Vertices count: " << graph.VerticesCount() << "\n";

        std::cout << "BFS: ";
        mainBFS(graph, [](int v){ std::cout << v << " "; });
        std::cout << "\n";

        std::cout << "DFS: ";
        mainDFS(graph, [](int v){ std::cout << v << " "; });
        std::cout << "\n\n";
    };

    testGraph(listGraph, "ListGraph");
    testGraph(matrixGraph, "MatrixGraph");
    testGraph(arcGraph, "ArcGraph");
    testGraph(setGraph, "SetGraph");

    return 0;
}