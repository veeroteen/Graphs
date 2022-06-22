#pragma once
#include <vector>
#include <unordered_set>

class IGraph
{
public:
    IGraph() = default;
    virtual  ~IGraph() = default;
    virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро
    virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин
    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void ToUnif(std::vector<std::unordered_set<int>>& list) const = 0;
    virtual void ToDefine(const std::vector<std::unordered_set<int>>& list) = 0;
};

class MatrixGraph : public IGraph {
private:
    std::vector<std::vector<bool>> matrix;
public:
    MatrixGraph(const IGraph* oth);
    MatrixGraph();
    MatrixGraph(const MatrixGraph& graph);
    ~MatrixGraph() = default;
    int VerticesCount() const override;
    void AddEdge(int from, int to)  override;
    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void ToUnif(std::vector<std::unordered_set<int>>& list) const  override;
    void ToDefine(const std::vector<std::unordered_set<int>>& list) override;
};

class ListGraph : public IGraph {
private:
    std::vector<std::unordered_set<int>> list;
public:
    ListGraph();
    ListGraph(const ListGraph& graph);
    ListGraph(const IGraph* oth);
    ~ListGraph() = default;
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void ToUnif(std::vector<std::unordered_set<int>>& list) const override;
    void ToDefine(const std::vector<std::unordered_set<int>>& list) override;

};