#include "MyAdjmatrixGraph.h"
// 构造函数
MyAdjmatrixGraph::MyAdjmatrixGraph(int V) {
    this->V = V;
    adjMatrix = new int* [V];
    for (int i = 0; i < V; i++) {
        adjMatrix[i] = new int[V];
        for (int j = 0; j < V; j++)
            adjMatrix[i][j] = 0;
    }
}

// 添加边
void MyAdjmatrixGraph::addEdge(int v, int w) {
    adjMatrix[v][w] = 1;
    adjMatrix[w][v] = 1; // 无向图
}

// 打印图
void MyAdjmatrixGraph::printGraph() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}

// 析构函数
MyAdjmatrixGraph::~MyAdjmatrixGraph() {
    for (int i = 0; i < V; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

