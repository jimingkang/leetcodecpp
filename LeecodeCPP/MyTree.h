#pragma once
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


// 二叉树节点定义

class MyTree {
private:
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
    MyTree(MyNode* root, SDL_Renderer* renderer) {
        this->root = root;
        this->renderer = renderer;
        this->V = 0;
    }
    // 绘制节点的圆
    void drawCircle( int x, int y, int radius) {
        for (int w = 0; w < radius * 2; w++) {
            for (int h = 0; h < radius * 2; h++) {
                int dx = radius - w;
                int dy = radius - h;
                if ((dx * dx + dy * dy) <= (radius * radius)) {
                    SDL_RenderDrawPoint(renderer, x + dx, y + dy);
                }
            }
        }
    }

    // 绘制二叉树节点及其连接线
    void drawTree( MyNode* root) {
        if (root == nullptr) return;

        // 绘制左右子节点的连接线
        if (root->left) {
            SDL_RenderDrawLine(renderer, root->p->x, root->p->y, root->left->p->x, root->left->p->y);
            drawTree( root->left);
        }
        if (root->right) {
            SDL_RenderDrawLine(renderer, root->p->x, root->p->y, root->right->p->x, root->right->p->y);
            drawTree( root->right);
        }

        // 绘制当前节点的圆圈
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // 蓝色表示未访问节点
        drawCircle( root->p->x, root->p->y, NODE_RADIUS);
        SDL_RenderPresent(renderer);
    }

    // DFS前序遍历并动态显示遍历过程
    void dfsPreorder(MyNode* root, SDL_Renderer* renderer) {
        if (root == nullptr) return;

        // 将当前节点标记为已访问，显示红色
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // 红色表示已访问节点
        drawCircle( root->p->x, root->p->y, NODE_RADIUS);
        SDL_RenderPresent(renderer);
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); // 延迟显示

        // 递归遍历左子树和右子树
        dfsPreorder(root->left, renderer);
        dfsPreorder(root->right, renderer);
    }


    /*
    - x, y: upper left corner.
    - texture, rect: outputs.
    */
    void get_text_and_rect(int x, int y, int nodeNum, TTF_Font* font, SDL_Texture** texture, SDL_Rect* rect
    ) {
        int text_width;
        int text_height;
        SDL_Surface* surface;
        SDL_Color textColor = { 255, 255, 255, 0 };

        char str[12];
        sprintf(str, "%d", nodeNum);
        surface = TTF_RenderText_Solid(font, str, textColor);
        *texture = SDL_CreateTextureFromSurface(renderer, surface);
        text_width = surface->w;
        text_height = surface->h;
        SDL_FreeSurface(surface);
        rect->x = x;
        rect->y = y;
        rect->w = text_width;
        rect->h = text_height;
    }

    // 获取鼠标点击位置的节点索引
    int getNodeIndexAtPosition(int x, int y) {
        for (int i = 0; i < V; ++i) {

            int dx = x - (this->vertices)[i]->p->x;
            int dy = y - (this->vertices)[i]->p->y;
            if (std::sqrt(dx * dx + dy * dy) <= NODE_RADIUS) {
                return i;
            }
        }
        return -1; // 未找到节点
    }
    void addNode(int x, int y) {


        vertices.push_back(new MyNode(V, x, y));
      //  adj.push_back({});
        this->V++;

    }
 
    // 添加边
    void addEdge(int v, int w) {
        MyNode* tmp = vertices[v];
        MyNode* pretmp = tmp;
        while (tmp != nullptr) {
            if (v < w) {
                tmp = tmp->left;
            }
            else
                tmp = tmp->right;

        }
       
        //adj[v].push_back(this->vertices[w]); // 添加 v -> w 的边
        //adj[w].push_back(this->vertices[v]); // 如果是无向图，添加 w -> v 的边
    }

};
