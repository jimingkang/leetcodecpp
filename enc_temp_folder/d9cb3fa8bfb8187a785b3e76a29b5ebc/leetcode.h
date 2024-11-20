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
int minimumDifference(MyNode* root, int& min);