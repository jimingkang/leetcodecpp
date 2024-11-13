﻿#pragma once
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

#include "main.h"

using namespace std;


// 二叉树节点定义

class MyTree {
public:
    MyNode* root;
    std::vector<MyNode*> vertices; // 存储所有顶点
    int V;
    int selectIndex = -1;

    char font_path[100];
    TTF_Font* font = nullptr;
    SDL_Rect rect;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
public:
    MyTree( SDL_Renderer* renderer);
    // 绘制节点的圆
    void drawCircle(int x, int y, int radius);
    // 绘制二叉树节点及其连接线
    void drawTree(MyNode* root);

    void drawGraph();

    // DFS前序遍历并动态显示遍历过程
    void dfsPreorder(MyNode* root);
    /*
    - x, y: upper left corner.
    - texture, rect: outputs.
    */
    void get_text_and_rect(int x, int y, int nodeNum, TTF_Font* font, SDL_Texture** texture, SDL_Rect* rect
    );

    // 获取鼠标点击位置的节点索引
    int getNodeIndexAtPosition(int x, int y);
    void addNode(int x, int y);
 
    // 添加边
    MyNode* addEdge(int v, int w);
};
