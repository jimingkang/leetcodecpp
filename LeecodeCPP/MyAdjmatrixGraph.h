#pragma once
#include <iostream>
using namespace std;
extern int SCREEN_WIDTH ;
extern int SCREEN_HEIGHT ;
extern int NODE_RADIUS ;
extern int DFS_DELAY_MS ; // 每次绘制路径之间的延迟时间（毫秒）

class MyAdjmatrixGraph {
    int V; // 顶点数
    int** adjMatrix; // 邻接矩阵

public:
    MyAdjmatrixGraph(int V); // 构造函数
    void addEdge(int v, int w); // 添加边
    void printGraph(); // 打印图
    ~MyAdjmatrixGraph(); // 析构函数
};

