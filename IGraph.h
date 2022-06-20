#pragma once
#include <vector>
#include <unordered_set>

class IGraph
{
public:
    virtual ~IGraph() {}
    IGraph() { };
    IGraph(IGraph* oth);
    virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро
    virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин
    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void ToUnif(std::vector<std::unordered_set<int>>& list) const = 0;
    virtual void ToDefine(std::vector<std::unordered_set<int>>& list) = 0;
};

class MatrixGraph : public IGraph {
    std::vector<std::vector<bool>> matrix;
public:
    MatrixGraph(IGraph* _oth) : IGraph(_oth) {};
    MatrixGraph();
    MatrixGraph(MatrixGraph& graph);
    int VerticesCount() const;
    void AddEdge(int from, int to);
    void GetNextVertices(int vertex, std::vector<int>& vertices) const;
    void ToUnif(std::vector<std::unordered_set<int>>& list) const;
    void ToDefine(std::vector<std::unordered_set<int>>& list);
};

class ListGraph : public IGraph {
    std::vector<std::unordered_set<int>> list;
public:
    ListGraph();
    ListGraph(ListGraph& graph);
    ListGraph(IGraph* _oth) : IGraph(_oth) {};
    void AddEdge(int from, int to);
    int VerticesCount() const;
    void GetNextVertices(int vertex, std::vector<int>& vertices) const;
    void ToUnif(std::vector<std::unordered_set<int>>& list) const;
    void ToDefine(std::vector<std::unordered_set<int>>& list);

};