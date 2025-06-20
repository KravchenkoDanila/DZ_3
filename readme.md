# Задача 1. «Представление графа».
### Обязательная задача
Дан базовый интерфейс для представления ориентированного графа:
```
struct IGraph {
virtual ~IGraph() {}

	// Добавление ребра от from к to.
virtual void AddEdge(int from, int to) = 0;

	virtual int VerticesCount() const  = 0;

virtual std::vector<int> GetNextVertices(int vertex) const = 0;
virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};
```

Необходимо написать несколько реализаций интерфейса:
ListGraph, хранящий граф в виде массива списков смежности,
MatrixGraph, хранящий граф в виде матрицы смежности,
SetGraph, хранящий граф в виде массива хэш-таблиц/сбалансированных деревьев поиска,
ArcGraph, хранящий граф в виде одного массива пар {from, to}.
Также необходимо реализовать конструктор, принимающий const IGraph&. Такой конструктор должен скопировать переданный граф в создаваемый объект.
Для каждого класса создавайте отдельные h и cpp файлы.
Число вершин графа задается в конструкторе каждой реализации.

# Результат работы программы

```
ListGraph
Vertices count: 7
BFS: 0 1 5 2 3 6 4
DFS: 0 1 2 3 4 6 5

MatrixGraph
Vertices count: 7
BFS: 0 1 5 2 3 6 4
DFS: 0 1 2 3 4 6 5

ArcGraph
Vertices count: 7
BFS: 0 1 5 2 3 6 4
DFS: 0 1 2 3 4 6 5

SetGraph
Vertices count: 7
BFS: 0 1 5 2 3 6 4
DFS: 0 1 2 3 4 6 5
```

