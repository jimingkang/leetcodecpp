﻿
#include "MyNode.h"
#include "MyTree.h"
#include "MyLinkedList.h"



MyTree::MyTree( SDL_Renderer* renderer) {
 //   this->root = root;
    this->renderer = renderer;
    this->V = 0;
}
// 绘制节点的圆
void MyTree::drawCircle(MyNode * node, int radius) {
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, node->p->x + dx, node->p->y + dy);
            }
        }
    }
    const char* font_path = "C:/Users/ET/source/repos/leetcodecpp/x64/Debug/FreeSans.ttf";
    TTF_Font* font = TTF_OpenFont(font_path, 24);
    SDL_Rect rect;
    get_text_and_rect(node->p->x - 5, node->p->y - 10, node->data, font, &this->texture, &rect);
    SDL_RenderCopy(renderer, this->texture, NULL, &rect);
}
// 绘制图
void MyTree::drawGraph() {
//   SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // 黑色用于background
 //   SDL_RenderClear(renderer);
  //  SDL_RenderPresent(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); //red+ green色用于边

    // 绘制边
    for (int i = 0; i < this->V; ++i) {
       for (MyNode* neighbor : this->adj[i]) {
           SDL_RenderDrawLine(renderer, this->vertices[i]->p->x, vertices[i]->p->y, neighbor->p->x, neighbor->p->y);
       }
    }

 

    // 绘制节点
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // 蓝色节点
    for (const auto& vertex : vertices) {
        drawCircle(vertex, NODE_RADIUS);
       
    }

    SDL_RenderPresent(renderer);
}

// 绘制二叉树节点及其连接线
void MyTree::drawTree(MyNode* root) {
    if (root == nullptr) return;
   

    // 绘制左右子节点的连接线
    if (root->left) {
        SDL_RenderDrawLine(renderer, root->p->x, root->p->y, root->left->p->x, root->left->p->y);
        drawTree(root->left);
    }
    if (root->right) {
        SDL_RenderDrawLine(renderer, root->p->x, root->p->y, root->right->p->x, root->right->p->y);
        drawTree(root->right);
    }

    // 绘制当前节点的圆圈
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // 蓝色表示未访问节点
    drawCircle(root, NODE_RADIUS);
    SDL_RenderPresent(renderer);
    const char* font_path = "C:/Users/ET/source/repos/leetcodecpp/x64/Debug/FreeSans.ttf";
    TTF_Font* font = TTF_OpenFont(font_path, 24);
    SDL_Rect rect;
    get_text_and_rect(root->p->x - 5, root->p->y - 10, root->data, font, &this->texture, &rect);
    SDL_RenderCopy(renderer, this->texture, NULL, &rect);
    SDL_RenderPresent(renderer);
}
void  MyTree::levelOrderTraversal(MyNode* root) {
    if (root == nullptr)
        return;
    // queue<MyNode*> q; 
   //  queue<MyNode*> *qq = ;
    MyLinkedList* q = new MyLinkedList(renderer);


    q->offer(root);
    q->drawLinkedList();
    while (!q->isEmpty())
    {


        MyNode* tmp = q->peek();
        // q->drawLinkedList();
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); //red色用于Node
        drawCircle(tmp, NODE_RADIUS);
        SDL_RenderPresent(renderer);

        cout << tmp->data << " "; // 打印当前节点的值
        if (tmp->left != nullptr)
        {
            q->offer(tmp->left);
        }
        if (tmp->right != nullptr)
        {
            q->offer(tmp->right);
        }
        q->poll();
        q->drawLinkedList();
        // SDL_RenderPresent(renderer);

        _sleep(500);

    }
}




/*
- x, y: upper left corner.
- texture, rect: outputs.
*/
void MyTree::get_text_and_rect(int x, int y, int nodeNum, TTF_Font* font, SDL_Texture** texture, SDL_Rect* rect) {
    int text_width;
    int text_height;
    SDL_Surface* surface;
    SDL_Color textColor = { 255, 255, 255, 0 };

    char str[12];
    sprintf(str, "%d", nodeNum);
    surface = TTF_RenderText_Solid(font, str, textColor);
    *texture = SDL_CreateTextureFromSurface(this->renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
}

// 获取鼠标点击位置的节点索引
int MyTree::getNodeIndexAtPosition(int x, int y) {
    for (int i = 0; i < V; ++i) {

        int dx = x - (this->vertices)[i]->p->x;
        int dy = y - (this->vertices)[i]->p->y;
        if (std::sqrt(dx * dx + dy * dy) <= NODE_RADIUS) {
            return i;
        }
    }
    return -1; // 未找到节点
}
void MyTree::addNode(int x, int y) {
    MyNode* tmp = new MyNode(rand()%100,V, x, y);
   // if (root == nullptr)
   //     root = tmp;



    vertices.push_back(tmp);
    adj.push_back({});
    this->V++;

}

MyNode* insert(MyNode* root, int value) {
    if (root == nullptr) {
        return new MyNode(value); // 如果当前节点为空，则创建新节点
    }

    if (value < root->data) {
        root->left = insert(root->left, value); // 递归插入到左子树
    }
    else if (value > root->data) {
        root->right = insert(root->right, value); // 递归插入到右子树
    }

    return root; // 返回根节点
}
// 添加边
MyNode* MyTree::addEdge(int v, int w) {
    MyNode* tmp = vertices[v];
    if (root == nullptr)
        root = tmp;
    MyNode* pretmp = nullptr;
    while (tmp != nullptr) {
        pretmp = tmp;
        if (tmp->data > vertices[w]->data) {
            tmp = tmp->left;
        }
        else if (tmp->data < vertices[w]->data)
            tmp = tmp->right;
        else
            return vertices[v];


    }
    if ((vertices[w]->data) < (pretmp->data))
    {
        pretmp->left = vertices[w];
        vertices[w]->p->x = pretmp->p->x - 50;
        vertices[w]->p->y = pretmp->p->y + 50;
        adj[pretmp->left->idx].push_back(this->vertices[w]); // 添加 v -> w 的边
        adj[w].push_back(this->vertices[pretmp->left->idx]); // 如果是无向图，添加 w -> v 的边
    }
    else
    {
        pretmp->right = vertices[w];
        vertices[w]->p->x = pretmp->p->x + 50;
        vertices[w]->p->y = pretmp->p->y + 50;
        adj[pretmp->right->idx].push_back(this->vertices[w]); // 添加 v -> w 的边
        adj[w].push_back(this->vertices[pretmp->right->idx]); // 如果是无向图，添加 w -> v 的边
    }

}
  
void  MyTree::invertTree(MyNode* root) {
    if (root == nullptr)
        return;
    MyNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    if (root->left != nullptr)
        root->left->p->x = root->p->x - 50;
    if (root->right != nullptr)
        root->right->p->x = root->p->x + 50;

    invertTree(root->left);
    invertTree(root->right);
    
 
  
   
}

   
void MyTree::updateNodeXY(MyNode* root,int space) {
    if (root == nullptr) return;

    root->p->x = root->p->x + space;
    // 递归遍历左子树和右子树
    updateNodeXY(root->left, space);
    updateNodeXY(root->right, space);
}

// DFS前序遍历并动态显示遍历过程
void MyTree::dfsPreorder(MyNode* root) {
    if (root == nullptr) return;

    // 将当前节点标记为已访问，显示红色
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // 红色表示已访问节点
    drawCircle(root, NODE_RADIUS);
    SDL_RenderPresent(renderer);
    const char* font_path = "C:/Users/ET/source/repos/leetcodecpp/x64/Debug/FreeSans.ttf";
    TTF_Font* font = TTF_OpenFont(font_path, 24);
    SDL_Rect rect;
    get_text_and_rect(root->p->x - 5, root->p->y - 10, root->data, font, &this->texture, &rect);
    SDL_RenderCopy(renderer, this->texture, NULL, &rect);
    std::this_thread::sleep_for(std::chrono::milliseconds(200)); // 延迟显示

    // 递归遍历左子树和右子树
    dfsPreorder(root->left );
    dfsPreorder(root->right);
}

MyNode* MyTree::lowestCommonAncester(MyNode* root, int p, int q) {
    if (root == nullptr || root->data == p || root->data == q)
        return root;
    MyNode* l = lowestCommonAncester(root->left, p, q);
    MyNode* r = lowestCommonAncester(root->right, p, q);
    if (l != nullptr && r != nullptr)
        return root;
    return l == nullptr ? r : l;
}





int  MyTree::maxHeight(MyNode* root) {
    int lh = 0;
    int rh = 0;

    if (root == nullptr)
        return 0;

    //   SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); //red色用于Node
    //   drawCircle(tmp, NODE_RADIUS);
    //   SDL_RenderPresent(renderer);


    if (root->left != nullptr)
    {
        lh = maxHeight(root->left) + 1;
        const char* font_path = "C:/Users/ET/source/repos/leetcodecpp/x64/Debug/FreeSans.ttf";
        TTF_Font* font = TTF_OpenFont(font_path, 24);
        //  SDL_Rect rect;
        //  get_text_and_rect(root->left->p->x - 20, root->left->p->y - 20, lh, font, &this->texture, &rect);
        //    SDL_RenderCopy(renderer, this->texture, NULL, &rect);
        //  SDL_RenderPresent(renderer);
    }
    else if (root->right != nullptr)
    {
        rh = maxHeight(root->right) + 1;
        const char* font_path = "C:/Users/ET/source/repos/leetcodecpp/x64/Debug/FreeSans.ttf";
        TTF_Font* font = TTF_OpenFont(font_path, 24);
        SDL_Rect rect;
        get_text_and_rect(root->right->p->x + 50, root->right->p->y - 20, rh, font, &this->texture, &rect);
        SDL_RenderCopy(renderer, this->texture, NULL, &rect);
        SDL_RenderPresent(renderer);
    }



    _sleep(500);
    return max(lh, rh);



}


static int sum;
bool MyTree::hasPathSum(int targetSum) {
    vector<MyNode*> v;
    bool flag= pathSum(this->root, targetSum, sum,&v);
    for (MyNode* i : v)
        std::cout << i->data << ' ';
    return flag;

}
bool  MyTree::pathSum(MyNode * root,int targetSum,int sum,vector<MyNode*>* v) {
    bool tmp=false;
  //  bool rsum;
    if (root == nullptr && sum != targetSum)
    {
       //
            return false;
    }
    else if (root == nullptr && sum == targetSum)
        return true;
        
    sum += root->data;
    v->push_back(root);

    tmp= pathSum(root->left, targetSum,sum,v);
    if (tmp)
        return tmp;
    else
    { 
       
        tmp = pathSum(root->right, targetSum, sum, v);
        if (tmp)
            return tmp;
        else
            v->pop_back();
    }
  
   
}
