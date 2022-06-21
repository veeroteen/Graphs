#pragma once
#include <vector>
#include <unordered_set>

class IGraph
{
public:
    virtual ~IGraph() {}
    IGraph() { };
    IGraph(IGraph* oth);
    virtual void AddEdge(int from, int to) = 0; // ����� ��������� ������� ������ � ����� ����� � ��������� �����
    virtual int VerticesCount() const = 0; // ����� ������ ������� ������� ���������� ������
    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const = 0; // ��� ���������� ������� ����� ������� � ������ ��������� ��� �������, � ������� ����� ����� �� ����� �� ������
    virtual void ToUnif(std::vector<std::unordered_set<int>>& list) const = 0;
    virtual void ToDefine(const std::vector<std::unordered_set<int>>& list) = 0;
};

class MatrixGraph : public IGraph {
    std::vector<std::vector<bool>> matrix;
public:
    MatrixGraph(const IGraph* oth);
    MatrixGraph();
    MatrixGraph(const MatrixGraph& graph);
    int VerticesCount() const override;
    void AddEdge(int from, int to)  override;
    void GetNextVertices(int vertex, std::vector<int>& vertices) const;
    void ToUnif(std::vector<std::unordered_set<int>>& list) const  override;
    void ToDefine(const std::vector<std::unordered_set<int>>& list) override;
};

class ListGraph : public IGraph {
    std::vector<std::unordered_set<int>> list;
public:
    ListGraph();
    ListGraph(const ListGraph& graph);
    ListGraph(const IGraph* oth);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void ToUnif(std::vector<std::unordered_set<int>>& list) const override;
    void ToDefine(const std::vector<std::unordered_set<int>>& list) override;

};