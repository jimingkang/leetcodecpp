#pragma once
#include "MyNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern int NODE_RADIUS;
extern int DFS_DELAY_MS; // 每次绘制路径之间的延迟时间（毫秒）

using namespace std;


// 二叉树节点定义

class MyTree {
public:
    MyNode* root;
    std::vector<MyNode*> vertices; // 存储所有顶点
    vector<vector<MyNode*>> adj; // 邻接表
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
    void drawCircle(MyNode* node, int radius);
    // 绘制二叉树节点及其连接线
    void drawTree(MyNode* root);

    void drawGraph();
    void  levelOrderTraversal(MyNode* root);
    int  maxHeight(MyNode* root);
    void  invertTree(MyNode* root);
    MyNode* lowestCommonAncester(MyNode* root, int p, int q);
    void updateNodeXY(MyNode* root,int space);
    bool hasPathSum(int targetSum);
    bool pathSum(MyNode* root, int targetSum, int sum,vector<MyNode*>* v);
    void get_text_and_rect(int x, int y, int nodeNum, TTF_Font* font, SDL_Texture** texture, SDL_Rect* rect );

    // DFS前序遍历并动态显示遍历过程
    void dfsPreorder(MyNode* root);
  

    // 获取鼠标点击位置的节点索引
    int getNodeIndexAtPosition(int x, int y);
    void addNode(int x, int y);
 
    // 添加边
    MyNode* addEdge(int v, int w);
};
