#pragma once
#include <vector>
using namespace std;

class IntGraph
{
	int vertex;
	vector<IntGraph*> link;
public:

	IntGraph(int vertex, IntGraph& from) {
		this->vertex = vertex;
		addEdge(from);
	}
	IntGraph(int vertex) {
		this->vertex = vertex;
	}
	void addEdge(IntGraph&to) {
		link.push_back(&to);
	}



};

class HumanGraph {
	vector<IntGraph> vertices;
public:
	HumanGraph() {
		vertices.push_back(IntGraph(1));
	}
	int addVertex() {
		vertices.push_back(IntGraph(vertices.size() + 1));
		return vertices.size();
	}
	int getSize() const {
		return vertices.size();
	}
	bool addEdge(int from, int to) {
		while (true) {
			if (to > vertices.size()) {
				addVertex();
			}
			else {
				break;
			}
		}
		if ((from > 0 && to > 0) && (from <= vertices.size() && to <= vertices.size()) && (to != from)) {
			vertices[from - 1].addEdge(vertices[to - 1]);
			vertices[to - 1].addEdge(vertices[from - 1]);
			return true;
		}
		return false;
	}


};