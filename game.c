//
// Created by Tomi on 15/01/2019.
//

#include "game.h"
#include "global.h"
#include "textures.h"

int init() {

    bool success = true;

    // Initializing everything, setting up the playground
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    // creating the window
    SDL_Window *window = SDL_CreateWindow("HeadBall", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        SDL_ShowSimpleMessageBox(0, "Window init error", SDL_GetError(), window);
        success = false;
        return success;
    }
    // creating the renderer
    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == NULL) {
        SDL_ShowSimpleMessageBox(0, "Renderer init error", SDL_GetError(), window);
        success = false;
        return success;
    }

    // setting up drawing color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    return success;
}

void eventHandler(SDL_Event event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {

            if (event.button.x != -1 && event.button.y != -1) {
                mouseX = event.button.x;
                mouseY = event.button.y;
                ball.x = mouseX, ball.y = mouseY, ball.r = radius;                                                      //később kivenni, tesztre kell
                printf("%d %d\n", mouseX, mouseY);
            }
        }
    }
}

bool isInside(int x0, int y0){
    if(x0 >= 40+radius && x0 <= 660-radius && y0 >= radius && y0 <= 404-radius)                                         // 40 és 660 a gólvonal, 404 pedig a föld vonala
    {
        return true;
    }
    else{
        return false;
    }
}

void drawBall(int x0, int y0, int radius)
{
    if(isInside(x0, y0))                                         // 40 és 660 a gólvonal, 404 pedig a föld vonala
    {
        SDL_Rect ball = {x0-radius, y0-radius, 2*radius, 2*radius};
        SDL_RenderCopy(renderer, textures[1], NULL, &ball);
    }
}

void moveBall(Ball *ball) {
    ball->vx = speedX;
    ball->vy = speedY;
    if(ball->x <= 40)
        ball->vx = +speedX;
    if(ball->x >= 660)
        ball->vx = -speedX;
    if(ball->y >= 404-ball->r)
        ball->vy = -speedY;
    if(ball->y >= ball->r)
        ball->vy = speedY;

    if(ball->x > 40+radius && ball->x < 660-radius && ball->y >= radius && ball->y < 404-radius)
    {
        ball->x += ball->vx;
        ball->y += ball->vy;
        drawBall(ball->x, ball->y, ball->r);

    }
    drawBall(ball->x, ball->y, ball->r);
}

