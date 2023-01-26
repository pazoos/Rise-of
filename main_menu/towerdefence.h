#ifndef TOWERDEFENCE_H
#define TOWERDEFENCE_H

#include <SDL.h>
static int torrekop = 0;
static int ronda = 0;
static int numronda = 1;
static int roundstart = 0;

void drawEnemies(SDL_Renderer* renderer, SDL_Surface* enemy, SDL_Surface* boss);
SDL_Surface* enemyimg(SDL_Renderer* renderer);
void updateenemies();
 int  checkRoundOver();
int AMUZON(int torreposx, int torreposy, SDL_Renderer* renderer);
int processEventsAmuzon(SDL_Window* amuzon, int torreposx, int  torreposy, SDL_Renderer* renderer);
static int processEventsTD(SDL_Window* window, SDL_Renderer* renderer);
void enemiespos(int dx, int dy);
void initTowers();
void drawTowers(SDL_Renderer* renderer, SDL_Surface* kainoia, SDL_Surface* metralleta, int j, int i, double angel);
void updateBullet(int towerIndex, int enemyIndex, SDL_Renderer* renderer);
void updateTowers(int currentTime, SDL_Renderer* renderer, SDL_Surface* kainoia, SDL_Surface* metralleta);
void renderBullets(SDL_Renderer* renderer);
int TD();

#endif