#pragma once
#ifndef _MyAdjlistGraph_
#define _MyAdjlistGraph_

#include "MyNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <SDL2/SDL.h>
#undef main
#include <SDL2/SDL_ttf.h>

#include <vector>
#include <cmath>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <cstdlib>

const int NODE_RADIUS = 20;

using namespace std;



class MyAdjlistGraph {
    int V; // 顶点数 v++
    //int V_MAX = 5;
    vector<vector<MyNode*>> adj; // 邻接表
    std::vector<Point> nodePositions; // 节点的位置
    std::vector<MyNode*> vertices; // 存储所有顶点
  
    int selectIndex = -1;
 
    char font_path[100];
    TTF_Font* font = nullptr;
    SDL_Rect rect;
    SDL_Texture* texture;
    SDL_Renderer* renderer;



public:
    MyAdjlistGraph( SDL_Renderer* renderer); // 构造函数
    void addEdge(int v, int w); // 添加边
    void addNode(int v); // 添加node
    void addNode(int x, int y);
    MyNode* getNode(int v); // 查找node
    vector<MyNode*> getNodeAdj(int v);
    void printGraph(); // 打印图
    void drawGraph();
    void DFS(MyNode* v);
    void DFS(int startNode);
    void DFSUtil(MyNode* v, std::vector<bool>& visited);
    int getNodeIndexAtPosition(int x, int y);
    void mousePress(SDL_MouseButtonEvent& b);
    void mouseMove(SDL_MouseButtonEvent& b);
    void mouseUp(SDL_MouseButtonEvent& b);

    // 使用SDL绘制圆圈
    void drawCircle( int x, int y, int radius);

    /*
    - x, y: upper left corner.
    - texture, rect: outputs.
    */
    void get_text_and_rect( int x, int y,int nodeNUm, TTF_Font* font, SDL_Texture** texture, SDL_Rect* rect);
    friend int test(MyAdjlistGraph *g);
};





#endif

