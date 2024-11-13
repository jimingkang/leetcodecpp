#pragma once
#ifndef _MyMAIN_
#define _MyMAIN_
#define _CRT_SECURE_NO_WARNINGS
#include "MyAdjlistGraph.h"
#include "MyTree.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int NODE_RADIUS = 20;
const int DFS_DELAY_MS = 100; // 每次绘制路径之间的延迟时间（毫秒）

int test(MyAdjlistGraph* g);

//int testMyTree(MyTree* root);





#endif