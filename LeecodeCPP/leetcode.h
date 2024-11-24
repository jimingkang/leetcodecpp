#pragma once
#include <algorithm>
#include <vector>
#include <iostream>

#include <SDL2/SDL.h>

#include "MyNode.h"

extern  int GRID_ROWS;  // 网格行数
extern int GRID_COLS ;  // 网格列数
extern int CELL_SIZE ;  // 每个单元格的大小（像素）;

extern SDL_Window* window;
extern SDL_Renderer* renderer ;

using namespace std;
int maxWater(vector<int> & v);



void drawGrid();
void dfs(int row, int col);
int countIslands();

int removeElement(vector<int>& nums, int val);

int getMinimumDifference(MyNode* root);
void minimumDifference(MyNode* root, int& min);

bool isSameTree(MyNode* p, MyNode* q);

int kthSmallest(MyNode* root, int k);
void find(MyNode* root, int k);

//leetcode124 bintree(not BST) max path sum
int maxPathSum(MyNode* root);
void inOrder(MyNode* root, vector<int> & v);

//leetcode 129
int sumNumbers(MyNode* root);
int sumNumber(MyNode* root, int& sum);