#include "IGraph.h"
IGraph::IGraph(IGraph* oth) {
    
};

MatrixGraph::MatrixGraph(const IGraph* oth) {
    std::vector<std::unordered_set<int>> tmp;
    oth->ToUnif(tmp);
    ToDefine(tmp);
}
MatrixGraph::MatrixGraph() {
    std::vector<bool> tmp = { false };
    matrix.push_back(tmp);
}

MatrixGraph::MatrixGraph(const MatrixGraph& graph) {
    matrix = graph.matrix;
}

void MatrixGraph::AddEdge(int from, int to) {
    if (from > to) {
        int tmp = to;
        to = from;
        from = to;
    }
    if (to > matrix.size()) {
        for (int i = 0; i < to - 1; i++) {
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

int MatrixGraph::VerticesCount() const {
    return matrix.size();
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    if (vertex <= matrix.size()) {
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[vertex - 1][i]) {
                vertices.push_back(i + 1);
            }
        }
    }
}

void MatrixGraph::ToUnif(std::vector<std::unordered_set<int>>& list) const {
    for (int i = 0; i < matrix.size(); i++) {
        list.emplace_back();
    }
    for (int y = 0; y < matrix.size(); y++) {
        for (int x = 0; x < matrix.size(); x++) {
            if (matrix[y][x]) {
                list[y].insert(x + 1);
            }
        }
    }
};

void MatrixGraph::ToDefine(const std::vector<std::unordered_set<int>>& list) {
    matrix.clear();
    for (int y = 0; y < list.size(); y++) {
        matrix.emplace_back();
        for (int x = 0; x < list.size(); x++) {
            matrix[y].push_back(false);
            if (list[y].contains(x + 1)) {
                matrix[y][x] = true;
            }
        }
    }
}




ListGraph::ListGraph() {
    list.emplace_back();
}

ListGraph::ListGraph(const ListGraph& graph) {
    list = graph.list;
}

ListGraph::ListGraph(const IGraph* oth) {
    std::vector<std::unordered_set<int>> tmp;
    oth->ToUnif(tmp);
    ToDefine(tmp);
};
void ListGraph::AddEdge(int from, int to) {
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
    list[from - 1].insert(to);
    list[to - 1].insert(from);

}

int ListGraph::VerticesCount() const {
    return list.size();
}

void ListGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    if (vertex <= list.size()) {
        for (int i = 1; i <= list.size(); i++) {
            if (list[vertex - 1].contains(i)) {
                vertices.push_back(i);
            }
        }
    }
}

void ListGraph::ToUnif(std::vector<std::unordered_set<int>>& list) const {
    list = this->list;
}


void ListGraph::ToDefine(const std::vector<std::unordered_set<int>>& list) {
    this->list = list;
}