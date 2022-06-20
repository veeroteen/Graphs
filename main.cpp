#include <iostream>
#include "IGraph.h"

using namespace std;
int main()
{
    IGraph* lgraph = new ListGraph();
    lgraph->AddEdge(1, 5);
    lgraph->AddEdge(1, 4);
    lgraph->AddEdge(2, 6);
    lgraph->AddEdge(1, 8);
    vector<int> larr;
    lgraph->GetNextVertices(1, larr);
    for (int i = 0; i < larr.size(); i++) {
        cout << larr[i] << endl;
    }
    cout << "hello" << endl;

    IGraph* mgraph = new MatrixGraph(lgraph);
    vector<int> marr;
    mgraph->GetNextVertices(1, marr);
    for (int i = 0; i < marr.size(); i++) {
        cout << marr[i] << endl;
    }








}
