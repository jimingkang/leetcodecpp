/*#include <SDL2/SDL.h>
#undef main
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const int TILE_SIZE = 100;

struct Player {
    int x, y;        // 玩家位置
    int money;       // 资金
    int position;    // 在棋盘上的位置（0-15格）
    SDL_Color color; // 玩家颜色
};

// 掷骰子，返回1到6之间的数
int rollDice() {
    return rand() % 6 + 1;
}

// 更新玩家的位置
void movePlayer(Player& player, int steps) {
    player.position = (player.position + steps) % 16;

    // 更新 x 和 y 坐标
    if (player.position < 4) { // 上方
        player.x = player.position * TILE_SIZE;
        player.y = 0;
    }
    else if (player.position < 8) { // 右方
        player.x = 3 * TILE_SIZE;
        player.y = (player.position - 4) * TILE_SIZE;
    }
    else if (player.position < 12) { // 下方
        player.x = (11 - player.position) * TILE_SIZE;
        player.y = 3 * TILE_SIZE;
    }
    else { // 左方
        player.x = 0;
        player.y = (15 - player.position) * TILE_SIZE;
    }
}

// 绘制棋盘
void drawBoard(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // 黑色格子边框

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            SDL_Rect tileRect = { i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE };
            SDL_RenderDrawRect(renderer, &tileRect);
        }
    }
}

// 绘制玩家
void drawPlayer(SDL_Renderer* renderer, const Player& player) {
    SDL_SetRenderDrawColor(renderer, player.color.r, player.color.g, player.color.b, 255);
    SDL_Rect playerRect = { player.x + TILE_SIZE / 4, player.y + TILE_SIZE / 4, TILE_SIZE / 2, TILE_SIZE / 2 };
    SDL_RenderFillRect(renderer, &playerRect);
}

int main(int argc, char* argv[]) {
    srand(static_cast<unsigned int>(time(0)));

    // 初始化SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("Monopoly Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // 创建玩家
    Player player = { 0, 0, 1000, 0, {255, 0, 0, 255} };

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // 事件处理
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_SPACE) {
                    int steps = rollDice();
                    std::cout << "Rolled a " << steps << "!" << std::endl;
                    movePlayer(player, steps);
                    std::cout << "Player position: " << player.position << std::endl;
                }
            }
        }

        // 绘制棋盘和玩家
        drawBoard(renderer);
        drawPlayer(renderer, player);

        // 更新屏幕
        SDL_RenderPresent(renderer);

        SDL_Delay(100); // 控制帧率
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
*/