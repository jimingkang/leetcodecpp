#pragma once
#include <iostream>
using namespace std;

class MyAdjmatrixGraph {
    int V; // 顶点数
    int** adjMatrix; // 邻接矩阵

public:
    MyAdjmatrixGraph(int V); // 构造函数
    void addEdge(int v, int w); // 添加边
    void printGraph(); // 打印图
    ~MyAdjmatrixGraph(); // 析构函数
};

