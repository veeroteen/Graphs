#pragma once
#include <vector>
#include <unordered_set>

class IGraph
{
public:
    virtual ~IGraph() {}
    IGraph() { };
    IGraph(IGraph* oth) {
        std::vector<std::unordered_set<int>> tmp;
        ToUnif(tmp);
        ToDefine(tmp);
    };
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
    MatrixGraph() {
        std::vector<bool> tmp = { false };
        matrix.push_back(tmp);
    }
    MatrixGraph(MatrixGraph &graph) {
        matrix = graph.matrix;
    }
    void AddEdge(int from, int to) {
        if (from > to) {
            int tmp = to;
            to = from;
            from = to;
        }
        if (to > matrix.size()) {
            for (int i = 0; i < to-1; i++) {
                std::vector<bool> tmp = { false };
                matrix.push_back(tmp);
            }
            for (int i = 0; i < matrix.size(); i++) {
                while (matrix[i].size() != matrix.size()) {
                    matrix[i].push_back(false);
                }
            }
        }
        matrix[to - 1][from - 1] = true;
        matrix[from - 1][to - 1] = true;
    }
    int VerticesCount() const {
        return matrix.size();
    }
    void GetNextVertices(int vertex, std::vector<int>& vertices) const {
        if (vertex <= matrix.size()) {
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[vertex - 1][i]) {
                    vertices.push_back(i + 1);
                }
            }
        }
    }

    void ToUnif(std::vector<std::unordered_set<int>> &list) const {
        for (int i = 0; i < matrix.size(); i++) {
            list.emplace_back();
        }
        for (int y = 0; y < matrix.size();y++) {
            for (int x = 0; x < matrix.size(); x++) {
                if (matrix[y][x]) {
                    list[y].insert(x + 1);
                }
            }
        }
    };
    void ToDefine(std::vector<std::unordered_set<int>>& list) {
        matrix.clear();
        for (int y = 0; y < list.size(); y++) {
            matrix.emplace_back();
            for (int x = 0; x < list.size(); x++) {
                matrix[y].push_back(false);
                if (list[y].contains(x + 1));
                matrix[y][x] = true;
            }
        }
    }







};

class ListGraph : public IGraph {
    std::vector<std::unordered_set<int>> list;
public:
    ListGraph() {
        list.emplace_back();
    }
    ListGraph(ListGraph &graph) {
        list = graph.list;
    }
    ListGraph(IGraph* _oth) : IGraph(_oth) {};
    void AddEdge(int from, int to) {
        if (from > to) {
            int tmp = to;
            to = from;
            from = to;
        }

        if (to > list.size()) {
            while (list.size() != to) {
                list.emplace_back();
            }
        }
        list[from-1].insert(to);
        list[to - 1].insert(from);

    }
    int VerticesCount() const {
        return list.size();
    }
    void GetNextVertices(int vertex, std::vector<int>& vertices) const {
        if (vertex <= list.size()) {
            for (int i = 1; i <= list.size(); i++) {
                if (list[vertex - 1].contains(i)) {
                    vertices.push_back(i);
                }
            }
        }



    }
    void ToUnif(std::vector<std::unordered_set<int>>& list) const {
        list = this->list;
    }


    void ToDefine(std::vector<std::unordered_set<int>>& list) {
        this->list = list;
    }

};