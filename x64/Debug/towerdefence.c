#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <Windows.h>
#include <SDL_ttf.h>
#include "towerdefence.h"


#define MAX_ENEMIES 10
#define MAX_TOWERS 10
#define MAX_BULLETS 100
#define BULLET_SPEED 10.0f



typedef struct {
    int x, y; // Posición de la bala
    int damage;// Daño de la bala
    int active;
} Bullet;




// Estructura para almacenar la información de cada enemigo
typedef struct {
    int x, y; // Posición
    int health; // Vida
    int speed; // Velocidad
    int daño;
    int active; // Indica si el enemigo está activo
} Enemy;


typedef struct {
    int x, y; // Posición
    int health; // Vida
    int speed; // Velocidad
    int daño;
    int active; // Indica si el enemigo está activo
} Enemyboss;

typedef struct  {
    int x, y; // Posición de la torre
    int range; // Alcance de la torre
    int damage; // Daño del disparo
    int fireRate; // Velocidad de disparo
    int lastShotTime; // Tiempo del último disparo
    Bullet bullet; // nueva variable para almacenar información de la bala
    int color;
    int active;
    int mota;
}Tower;

Bullet bullets[MAX_BULLETS];
Tower towers[MAX_TOWERS];
Enemy enemies[MAX_ENEMIES];
Enemyboss enemyboss[1];


int torreak[6];
int aktibatutakoTorreak[6];
int dirua = 0;
int vida = 0;
int vidaboss = 0;
char dirua_text[128];
double angle;

int text_x = 10;
int text_y = 10;
static int w = 100;
static int h = 100;


// Función para dibujar un enemigo en pantalla
void drawEnemies(SDL_Renderer* renderer, SDL_Surface* enemy, SDL_Surface* boss) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].active == 1) {
            // Calcula el ancho de la barra de vida en función de la vida del enemigo
            int healthBarWidth = enemies[i].health;
            // Dibuja la barra de vida

            SDL_Rect healthBar2 = { enemies[i].x, enemies[i].y - 10, vida, 5 };
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &healthBar2);

            SDL_Rect healthBar = { enemies[i].x, enemies[i].y - 10, healthBarWidth, 5 };
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderFillRect(renderer, &healthBar);
            // Dibuja el enemigo

            SDL_Rect enemyRect = { enemies[i].x, enemies[i].y, 30, 20 };

            

            SDL_RenderCopy(renderer, enemy,NULL,&enemyRect);

            

          
        }
    }

    if (enemyboss[1].active == 1) {
        // Calcula el ancho de la barra de vida en función de la vida del enemigo
        int healthBarWidth = enemyboss[1].health;
        // Dibuja la barra de vida

        SDL_Rect healthBarboss2 = { enemyboss[1].x, enemyboss[1].y - 10, vidaboss, 5 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &healthBarboss2);

        SDL_Rect healthBarboss = { enemyboss[1].x, enemyboss[1].y - 10, healthBarWidth, 5 };
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &healthBarboss);
        // Dibuja el enemigo

        SDL_Rect enemybossRect = { enemyboss[1].x, enemyboss[1].y, 40, 50 };



        SDL_RenderCopy(renderer, boss, NULL, &enemybossRect);




    }
    SDL_DestroyTexture(enemy);
    SDL_DestroyTexture(boss);
}
SDL_Surface* enemyimg(SDL_Renderer* renderer) {
    SDL_Surface* surface = 0;
    SDL_Texture* enemy;
        if (numronda == 1) {
            
            
            surface = IMG_Load("irudiak/fisika.png");

        }

        if (numronda == 2) {
          
            
            surface= IMG_Load("irudiak/redes.png");
   
        }
        if (numronda == 3) {
           
          
            surface = IMG_Load("irudiak/mate.png");

            
        }
        if (numronda == 4) {
            
        
            surface = IMG_Load("irudiak/oinarri.png");

           
        }

        if (numronda == 5) {
            
          
            surface = IMG_Load("irudiak/program.png");
        }

        enemy = SDL_CreateTextureFromSurface(renderer,surface);
        SDL_FreeSurface(surface);
        
        return enemy;
       
      
    }
SDL_Surface* bossimg(SDL_Renderer* renderer) {

    SDL_Surface* surfaceboss = 0;
    SDL_Texture* enemyboss;
    if (numronda == 1) {

        surfaceboss = IMG_Load("irudiak/badiola.png");
      

    }

    if (numronda == 2) {


        surfaceboss = IMG_Load("irudiak/carlos.png");

    }
    if (numronda == 3) {


        surfaceboss = IMG_Load("irudiak/aritz.png");


    }
    if (numronda == 4) {


        surfaceboss = IMG_Load("irudiak/joseba.png");


    }

    if (numronda == 5) {


        surfaceboss = IMG_Load("irudiak/valencia.png");
    }

    enemyboss = SDL_CreateTextureFromSurface(renderer, surfaceboss);
    SDL_FreeSurface(surfaceboss);
    return enemyboss;


}
void initEnemies() {
    int pos = 0;
    if (numronda == 1){
        for (int i = 0; i < MAX_ENEMIES; i++) {
            enemies[i].x = 280;
            enemies[i].y = 600 + pos;
            enemies[i].health = 50; // Asigna una vida inicial de 100
            enemies[i].speed = 1; // Asigna una velocidad inicial de 2
            enemies[i].daño = 30;
            enemies[i].active = 0; // Asigna como activo
            pos += 50;
            vida = enemies[i].health;

        }

        enemyboss[1].x = 280;
        enemyboss[1].y = 600 + pos;
        enemyboss[1].health = 100; // Asigna una vida inicial de 100
        enemyboss[1].speed = 1; // Asigna una velocidad inicial de 2
        enemyboss[1].daño = 60;
        enemyboss[1].active = 1; // Asigna como activo

        vidaboss = enemyboss[1].health;
    }

    if (numronda == 2) {
        for (int i = 0; i < MAX_ENEMIES; i++) {
            enemies[i].x = 280 ;
            enemies[i].y = 600 + pos;
            enemies[i].health = 70; // Asigna una vida inicial de 100
            enemies[i].speed = 1; // Asigna una velocidad inicial de 2
            enemies[i].daño = 20;
            enemies[i].active = 1; // Asigna como activo
            pos += 50;
            vida = enemies[i].health;
        }
        enemyboss[1].x = 280 ;
        enemyboss[1].y = 600  + pos;
        enemyboss[1].health = 130; // Asigna una vida inicial de 100
        enemyboss[1].speed = 1; // Asigna una velocidad inicial de 2
        enemyboss[1].daño = 60;
        enemyboss[1].active = 1; // Asigna como activo

        vidaboss = enemyboss[1].health;
    }
 
    if (numronda == 3) {
        for (int i = 0; i < MAX_ENEMIES; i++) {
            enemies[i].x = 280;
            enemies[i].y = 600 + pos;
            enemies[i].health = 100; // Asigna una vida inicial de 100
            enemies[i].speed = 2; // Asigna una velocidad inicial de 2
            enemies[i].daño = 30;
            enemies[i].active = 1; // Asigna como activo
            pos += 50;
            vida = enemies[i].health;
        }
        enemyboss[1].x = 280;
        enemyboss[1].y = 600 + pos;
        enemyboss[1].health = 140; // Asigna una vida inicial de 100
        enemyboss[1].speed = 1; // Asigna una velocidad inicial de 2
        enemyboss[1].daño = 60;
        enemyboss[1].active = 1; // Asigna como activo

        vidaboss = enemyboss[1].health;
    }

    if (numronda == 4) {
        for (int i = 0; i < MAX_ENEMIES; i++) {
            enemies[i].x = 280;
            enemies[i].y = 600 + pos;
            enemies[i].health = 60; // Asigna una vida inicial de 100
            enemies[i].speed = 2; // Asigna una velocidad inicial de 2
            enemies[i].daño = 40;
            enemies[i].active = 1; // Asigna como activo
            pos += 50;
            vida = enemies[i].health;
        }
        enemyboss[1].x = 280;
        enemyboss[1].y = 600 + pos;
        enemyboss[1].health = 160; // Asigna una vida inicial de 100
        enemyboss[1].speed = 1; // Asigna una velocidad inicial de 2
        enemyboss[1].daño = 60;
        enemyboss[1].active = 1; // Asigna como activo

        vidaboss = enemyboss[1].health;
    }

    if (numronda == 5) {
        for (int i = 0; i < MAX_ENEMIES; i++) {
            enemies[i].x = 280;
            enemies[i].y = 600 + pos;
            enemies[i].health = 100; // Asigna una vida inicial de 100
            enemies[i].speed = 2; // Asigna una velocidad inicial de 2
            enemies[i].daño = 40;
            enemies[i].active = 1; // Asigna como activo
            pos += 50;
            vida = enemies[i].health;
        }
        enemyboss[1].x = 280;
        enemyboss[1].y = 600 + pos;
        enemyboss[1].health = 160; // Asigna una vida inicial de 100
        enemyboss[1].speed = 2; // Asigna una velocidad inicial de 2
        enemyboss[1].daño = 70;
        enemyboss[1].active = 1; // Asigna como activo

        vidaboss = enemyboss[1].health;
    }
  
}
void updateenemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].health <= 0) {
            enemies[i].active = 0;
        }
    }
    if (enemyboss[1].health <= 0) {
        enemyboss[1].active = 0;
    }
}
int checkRoundOver() {
    int activeEnemies = 0;
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].active) {
            activeEnemies++;
        }
    }

    if (activeEnemies == 0 && enemyboss[1].active == 0) {
        return true;
    }
    else {
        return false;
    }
}
int AMUZON(int torreposx, int torreposy, SDL_Renderer* renderer) {

    SDL_Init(SDL_INIT_VIDEO);

    // Crear una ventana
    SDL_Window* amuzon = SDL_CreateWindow("AMUZON",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        0);
    
    // Obtener un puntero al contexto de renderizado de la ventana
    SDL_Renderer* rendereramuzon = SDL_CreateRenderer(amuzon, -1, 0);
    int done = 0;
    SDL_Texture* kainoiatexture;
    SDL_Surface* kainoia;
    SDL_Texture* texturemetralleta;
    SDL_Surface* metralleta;
    metralleta = IMG_Load("irudiak/metralleta.png");
    kainoia = IMG_Load("irudiak/kainoia.png");
    SDL_Surface* background;
    background = IMG_Load("irudiak/dendaTowerDefence.bmp");
   

    while (!done) {

        SDL_Texture* background_texture;

        background_texture = SDL_CreateTextureFromSurface(rendereramuzon, background, -1, SDL_RENDERER_ACCELERATED);

        SDL_RenderCopy(rendereramuzon, background_texture, NULL, NULL);

        

        SDL_Rect rect1;
        rect1.x = 20;
        rect1.y = 100;
        rect1.w = 300;
        rect1.h = 300;

        SDL_Rect rect2;
        rect2.x = 400;
        rect2.y = 100;
        rect2.w = 100;
        rect2.h = 100;


        done = processEventsAmuzon(amuzon, torreposx, torreposy,renderer);


        // Mostrar el resultado en la pantalla
        SDL_RenderSetLogicalSize(rendereramuzon, 640, 480);
        
        
        SDL_RenderPresent(rendereramuzon);

        // Hacer una pausa para limitar la tasa de fotogramas
        SDL_Delay(10);
  

        SDL_DestroyTexture(background_texture);
        SDL_RenderClear(rendereramuzon);

    }

    // Limpiar recursos y salir
    SDL_DestroyRenderer(rendereramuzon);
    SDL_DestroyWindow(amuzon);

}
int processEventsAmuzon(SDL_Window* amuzon, int torreposx, int  torreposy)
{


    SDL_Event event;
    int doneTD = 0;

    int mousex;
    int mousey;
    SDL_PumpEvents();
    SDL_GetMouseState(&mousex, &mousey);

    int mousepos = 0;

    //check events
    while (SDL_PollEvent(&event))

    {



        if (dirua < 5 && mousex > 20  && mousex < 320  && mousey  > 100  && mousey < 400  && event.type == SDL_MOUSEBUTTONDOWN ) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "W", "Ez duzu Energiarik.", NULL);


        }
            if (dirua >= 5 && mousex > 20 && mousex < 320 && mousey  > 100 && mousey < 400 && event.type == SDL_MOUSEBUTTONDOWN) {
                /*metralleta*/
                torrekop++;
                initTowers();
                towers[torrekop].x = torreposx;
                towers[torrekop].y = torreposy;
                towers[torrekop].damage = 10;
                towers[torrekop].fireRate = 400;
                towers[torrekop].color = 255;
                towers[torrekop].active = 1;
                towers[torrekop].mota = 1;
                dirua = dirua - 5;
                
                

               

                doneTD = 1;
              
            }


        
        if (dirua < 12 && mousex > 400 && mousex < 500 && mousey > 100 && mousey < 200 && event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Energia", "Ez duzu Energiarik.", NULL);
            
            
        }
        if (dirua >= 12 && mousex > 400 && mousex < 500 && mousey > 100 && mousey < 200 && event.type == SDL_MOUSEBUTTONDOWN) {
            /*kanoia*/
            torrekop++;
            initTowers();
            towers[torrekop].x = torreposx;
            towers[torrekop].y = torreposy;
            towers[torrekop].damage = 20;
            towers[torrekop].fireRate = 700;
            towers[torrekop].active = 1;
            towers[torrekop].mota = 2;

            

            dirua = dirua - 12;

            doneTD = 1;
        }
            

        switch (event.type)
        {
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {

            case SDLK_ESCAPE:


                doneTD = 1;

                break;

            case SDLK_p:

                break;

            }

        }
        return doneTD;
    }
}
int processEventsTD(SDL_Window* window, SDL_Renderer* renderer)
{


    SDL_Event event;
    int done = 0;
    int mousex;
    int mousey;
    SDL_PumpEvents();
    SDL_GetMouseState(&mousex, &mousey);


    //check events
    while (SDL_PollEvent(&event))
    {



        switch (event.type)
        {

            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {               

            case SDLK_ESCAPE:
                
                done = 1;

                break;

            case SDLK_s:

                roundstart++;

                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
        {
            if (mousex > 333   && mousex  < 387  && mousey  > 221  && mousey  < 278  && torreak[1] == 0) {
                int torreposx = 345;
                int torreposy = 235;

                torreak[1] = 1;
                
                AMUZON(torreposx,torreposy,renderer);

            }

            if (mousex > 208  && mousex < 264   && mousey > 283  && mousey < 337  && torreak[2] == 0 ) {
                int torreposx = 220;
                int torreposy = 295;
                
                AMUZON(torreposx, torreposy,renderer);
                torreak[2] = 1;
            }

            if (mousex > 99  && mousex < 155 && mousey > 316  && mousey < 360  && torreak[3] == 0) {
                int torreposx = 115;
                int torreposy = 340;
               
                AMUZON(torreposx, torreposy,renderer);
                torreak[3] = 1;
            }

            if (mousex > 97  && mousex < 153  && mousey > 102  && mousey < 140  && torreak[4] == 0) {
                int torreposx = 110;
                int torreposy = 100;
                
                AMUZON(torreposx, torreposy,renderer);;
                torreak[4] = 1;
            }

            if (mousex > 465  && mousex < 520  && mousey > 104  && mousey < 158  && torreak[5] == 0) {
                int torreposx = 477;
                int torreposy = 117;
                
                AMUZON(torreposx, torreposy,renderer);
                torreak[5] = 1;
            }


            break;
        }


        }
        return done;
    }
}
void enemiespos(int dx,int dy) {
    
        for (int i = 0; i < MAX_ENEMIES; i++) {
            // Actualizar la posición del square
            if(enemies[i].active == 1) {
                if (enemies[i].y >= 250  && enemies[i].x == 280 ) {

                    enemies[i].x += 0;
                    enemies[i].y -= dy;
                }

           
                if (enemies[i].y == 250  && enemies[i].x > 180 ) {
                    enemies[i].x -= dx;
                    enemies[i].y += 0;
                }

         
                if (enemies[i].x == 180  && enemies[i].y <= 400 && enemies[i].y >= 200 ) {
                    enemies[i].x += 0;
                    enemies[i].y += dy;
                }

            
                if (enemies[i].x <= 180 && enemies[i].y == 390 ) {
                    enemies[i].x -= dx;
                    enemies[i].y += 0;
                }

                if (enemies[i].x == 60 ) {
                    enemies[i].x -= 0;
                    enemies[i].y -= dy;
                }
                if (enemies[i].y == 40  && enemies[i].x < 300 ) {
                    enemies[i].x += dx;
                    enemies[i].y -= 0;
                }

                if (enemies[i].x == 300  && enemies[i].y < 300 ) {
                    enemies[i].x += 0;
                    enemies[i].y += dy;
                }

                if (enemies[i].y == 180  && enemies[i].x > 280 ) {
                    enemies[i].x += dx;
                    enemies[i].y += 0;
                }
                if (enemies[i].x == 540 ) {
                    enemies[i].x += 0;
                    enemies[i].y -= dy;
                }
            }
        }
        if (enemyboss[1].active == 1) {

            if (enemyboss[1].y >= 220  && enemyboss[1].x == 280 ) {

                enemyboss[1].x += 0;
                enemyboss[1].y -= dy;
            }


            if (enemyboss[1].y == 220  && enemyboss[1].x > 180) {
                enemyboss[1].x -= dx;
                enemyboss[1].y += 0;
            }


            if (enemyboss[1].x == 180  && enemyboss[1].y <= 400  && enemyboss[1].y >= 200) {
                enemyboss[1].x += 0;
                enemyboss[1].y += dy;
            }


            if (enemyboss[1].x <= 180  && enemyboss[1].y == 370 ) {
                enemyboss[1].x -= dx;
                enemyboss[1].y += 0;
            }

            if (enemyboss[1].x == 60 ) {
                enemyboss[1].x -= 0;
                enemyboss[1].y -= dy;
            }
            if (enemyboss[1].y == 20  && enemyboss[1].x < 300 ) {
                enemyboss[1].x += dx;
                enemyboss[1].y -= 0;
            }

            if (enemyboss[1].x == 300  && enemyboss[1].y < 300 ) {
                enemyboss[1].x += 0;
                enemyboss[1].y += dy;
            }

            if (enemyboss[1].y == 150  && enemyboss[1].x > 280 ) {
                enemyboss[1].x += dx;
                enemyboss[1].y += 0;
            }
            if (enemyboss[1].x == 540 ) {
                enemyboss[1].x += 0;
                enemyboss[1].y -= dy;
            }
        }
    
}
void initTowers() {
    
    

        towers[torrekop].x = 900;
        towers[torrekop].y = 900;
        towers[torrekop].range = 100;
        towers[torrekop].damage = 10;
        towers[torrekop].fireRate = 1000;
        towers[torrekop].lastShotTime = 0;
        
    
}
void drawTowers(SDL_Renderer* renderer, SDL_Surface* kainoia, SDL_Surface* metralleta,int j,int i,double angel) {

    

        SDL_Rect towerRect = { towers[i].x - 10, towers[i].y - 10, 64, 64 };
        SDL_Rect towerRect2 = { towers[i].x, towers[i].y, 32, 32 };

        if (towers[i].active == 1 ) {

            if (towers[i].mota == 1) {


               
                // Calcular el ángulo de giro
                angle = atan2(enemies[j].y - towers[i].y, enemies[j].x - towers[i].x);
                angle = angle * (180 / M_PI);

                // Crea un rectángulo para dibujar la torre

                SDL_Texture* texturemetralleta = SDL_CreateTextureFromSurface(renderer, metralleta);

                SDL_RenderCopyEx(renderer, texturemetralleta, NULL, &towerRect, angle - 90, NULL, SDL_FLIP_VERTICAL);
                SDL_DestroyTexture(texturemetralleta);
                
                
            }


            if (towers[i].mota == 2) {


                // Calcular el ángulo de giro
                angle = atan2(enemies[j].y - towers[i].y, enemies[j].x - towers[i].x);
                angle = angle * (180 / M_PI);

                SDL_Texture* texturekainoia = SDL_CreateTextureFromSurface(renderer, kainoia);

                SDL_RenderCopyEx(renderer, texturekainoia, NULL, &towerRect2, angle + 90, NULL, SDL_FLIP_NONE);
                SDL_DestroyTexture(texturekainoia);
                
            }

            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            SDL_RenderFillRect(renderer, &towerRect);
            SDL_RenderFillRect(renderer, &towerRect2);

        }

        
    

}
void updateTowers(int currentTime, SDL_Renderer* renderer, SDL_Surface* kainoia, SDL_Surface* metralleta) {
    int i = 0;
    int j = 0;
    int e = 0;
    for (i = 0; i < MAX_TOWERS; i++) {
       
        // Recorre el arreglo de enemigos
        for (int j = 0; j < MAX_ENEMIES; j++) {

           
            if (enemies[j].active ) {
                


                // Calcula la distancia entre la torre y el enemigo
                int distance = sqrt(pow(towers[i].x - enemies[j].x, 2) + pow(towers[i].y - enemies[j].y, 2));


                        // Verifica si el enemigo está dentro del alcance de la torre
                        if (distance <= towers[i].range) {
                            // Verifica si ha pasado suficiente tiempo desde el último disparo
                            if (currentTime - towers[i].lastShotTime > towers[i].fireRate) {
                                // Dispara al enemigo
                                enemies[j].health -= towers[i].damage;
                                towers[i].lastShotTime = currentTime;
                            }
                            
                            
                        }

                       
         
             }
                
            

            if (enemyboss[1].active) {
                int distanceboss = sqrt(pow(towers[i].x - enemyboss[1].x, 2) + pow(towers[i].y - enemyboss[1].y, 2));
                // Verifica si el boss está dentro del alcance de la torre
                if (distanceboss <= towers[i].range) {
                    // Verifica si ha pasado suficiente tiempo desde el último disparo
                    if (currentTime - towers[i].lastShotTime > towers[i].fireRate) {
                        // Dispara al enemigo
                        enemyboss[1].health -= towers[i].damage;
                        towers[i].lastShotTime = currentTime;
                    }
                  
                    
                
                }

            
            }
            
            
        }
        e++;
        drawTowers(renderer, kainoia, metralleta, e, i, angle);
        
        }

   
    
        
    }
void Textuaidatzi(TTF_Font* font, SDL_Renderer* renderer) {
    
    SDL_Texture* text_texture = 0;
    SDL_Color color = { 255, 255, 255 }; // color blanco

   

    sprintf(dirua_text, " Energia:%iW", dirua);
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, dirua_text, color);
    text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    

    // dibujar dinero

    SDL_Rect recttext = { text_x, text_y, text_surface->w, text_surface->h };
    SDL_RenderCopy(renderer, text_texture, NULL, &recttext);

    SDL_DestroyTexture(text_texture);
    
}



int TD(char energia[])
{
    // Inicializar SDL
    SDL_Init(SDL_INIT_VIDEO);
    
    // Crear una ventana
    SDL_Window* window = SDL_CreateWindow("RISE OF THE MUTANTS",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
       620, 480,
        NULL);
    
    
   
    // Obtener un puntero al contexto de renderizado de la ventana
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, NULL);
    




    //barra de vida game
    SDL_Rect rectvida1;
    rectvida1.x = 310;
    rectvida1.y = 30;
    rectvida1.w = 300;
    rectvida1.h = 20;

    SDL_Rect rectvida2;
    rectvida2.x = 310;
    rectvida2.y = 30;
    rectvida2.w = 300;
    rectvida2.h = 20;

        
    int done = 0;


    // Inicializar SDL_ttf
    if (TTF_Init() < 0) {
        printf("error ttf");
        // Error al inicializar SDL_ttf
    }
    TTF_Font* font = TTF_OpenFont("C:\\WINDOWS\\Fonts\\ARIAL.TTF", 16, 0);
    SDL_Color color = { 255, 255, 255 }; // color blanco

    
    SDL_Surface* metralleta;
    metralleta = IMG_Load("irudiak/metralleta.png");
    
    SDL_Surface* kainoia;
    kainoia = IMG_Load("irudiak/kainoia.png");

    SDL_Surface* background;
    background = IMG_Load("irudiak/fondo11.bmp");


    initEnemies();
    dirua = dirua + energia[0];
    energia[0] = 0;

    while (!done) {


        done = processEventsTD(window,renderer);


        if(roundstart == 1){
            for (int i = 0; i < MAX_ENEMIES; i++) {

                enemies[i].active = 1;
            }
        roundstart++;
        }

        SDL_Texture* background_texture;

        background_texture = SDL_CreateTextureFromSurface(renderer, background, - 1, SDL_RENDERER_ACCELERATED);

        SDL_RenderCopy(renderer, background_texture, NULL, NULL);

        SDL_DestroyTexture(background_texture);

        Uint32 currentTime = SDL_GetTicks(); // Obtiene el tiempo actual en milisegundos

        Textuaidatzi (font, renderer);

        
        
        updateenemies();

        drawEnemies(renderer,enemyimg(renderer),bossimg(renderer));
        
        // Variables para la velocidad y la dirección del movimiento

        int dx = 1 * enemies[1].speed;
        int dy = 1 * enemies[1].speed;
        int dxb = 1 * enemyboss[1].speed;
        int dyb = 1 * enemyboss[1].speed;

        enemiespos(dx, dy);
        
        

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rectvida1);

        SDL_SetRenderDrawColor(renderer, 0, 180, 0, 255);
        SDL_RenderFillRect(renderer, &rectvida2);


        updateTowers(currentTime, renderer, kainoia, metralleta);
        

        //quitar vida si llega al final
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (enemies[i].y < 0 && enemies[i].active == 1) {
                rectvida2.w = rectvida2.w - enemies[i].daño;
                //enemies[i].y = 1000;
                //enemies[i].x = 1000;
                enemies[i].active = 0;
            }
        }

        if (enemyboss[1].y <= 0) {
            rectvida2.w = rectvida2.w - enemyboss[1].daño;
            enemyboss[1].active = 0;
        }

        // bida 0 eltzen bada game over
        if (rectvida2.w <= 0) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Título de la alerta", "GAME OVER", NULL);
            done = 1;

        }


        
        // Mostrar el resultado en la pantalla
        
        
        SDL_RenderSetScale(renderer, 1, 1);
        SDL_RenderPresent(renderer);

        
        ronda = checkRoundOver();



       if (ronda && rectvida2.w > 0 && roundstart != 0) {
           SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Oso Ondo", "Oso Ondo Defendatuta", NULL);
           done = 1;
       }

        // Hacer una pausa para limitar la tasa de fotogramas
        SDL_Delay(10);
        
        SDL_RenderClear(renderer);
        
        
        
      
        
        
    }


    // Limpiar recursos y salir
    roundstart = 0;
    numronda++;
    TTF_Quit(); 
    SDL_RenderClear(renderer);
    if (numronda == 6) {
        SDL_Quit();
    }
   
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;
    return 0;
}
