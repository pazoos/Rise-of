#include "game02/game02.h"
#include "irudiak.h"
#include "graphics.h"
#include "ebentoak.h"
#include "textua.h"
#include "audio.h"
#include "kolisioak.h"
#include "marrazkiak.h"
#include "eszena.h"
#include "interaktuatu.h"
#include <stdio.h>
#include <windows.h>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "sdl.h"


#define ONGI_ETORRI_MEZUA2 "Sakatu return itzultzeko..."
#define JOKOA_DENDA "irudiak\\denda.bmp"




int objetuakhartu(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA egurra1, JOKO_ELEMENTUA egurra2, JOKO_ELEMENTUA egurra3, JOKO_ELEMENTUA egurra4, JOKO_ELEMENTUA egurra5, JOKO_ELEMENTUA plastiko1, JOKO_ELEMENTUA plastiko2, JOKO_ELEMENTUA plastiko3, JOKO_ELEMENTUA plastiko4, JOKO_ELEMENTUA plastiko5, JOKO_ELEMENTUA kablea1, JOKO_ELEMENTUA kablea2, JOKO_ELEMENTUA kablea3, int eszena, int ireki, int zerdo, int giltza, int motxila, char egurra[], char plastikoa[], char kablea[], char motxilaa[]) {


    if (eszena == 8) {
        if (jokalaria.pos.x > 170 && jokalaria.pos.x < 210 && jokalaria.pos.y > 130 && jokalaria.pos.y < 190) {
            if (egurra[4] == 0) {
                if (zerdo + 2 <= motxila) {
                    egurra[4] = 1;
                    irudiaKendu(egurra4.id);
                    zerdo += 2;
                    egurra[0] += 2;
                }
            }
        }
        if (jokalaria.pos.x > 380 && jokalaria.pos.x < 420 && jokalaria.pos.y > 60 && jokalaria.pos.y < 120) {
            if (egurra[6] == 0) {
                if (zerdo + 2 <= motxila) {
                    egurra[6] = 1;
                    irudiaKendu(egurra5.id);
                    zerdo += 2;
                    egurra[0] += 2;
                }
            }
        }
    }
    if (eszena == 4) {
        if (jokalaria.pos.x > 410 && jokalaria.pos.x < 450 && jokalaria.pos.y > 60 && jokalaria.pos.y < 120) {
            if (plastikoa[3] == 0) {
                if (zerdo + 5 <= motxila) {
                    plastikoa[3] = 1;
                    irudiaKendu(plastiko1.id);
                    zerdo += 5;
                    plastikoa[0] += 2;
                }
            }
        }
    }
    if (eszena == 5) {
        if (jokalaria.pos.x > 400 && jokalaria.pos.x < 440 && jokalaria.pos.y > 70 && jokalaria.pos.y < 130) {
            if (plastikoa[4] == 0) {
                if (zerdo + 5 <= motxila) {
                    plastikoa[4] = 1;
                    irudiaKendu(plastiko3.id);
                    zerdo += 5;
                    plastikoa[0] += 2;
                }
            }
        }
        if (jokalaria.pos.x > 20 && jokalaria.pos.x < 60 && jokalaria.pos.y > 220 && jokalaria.pos.y < 280) {
            if (kablea[1] == 0) {
                if (zerdo + 3 <= motxila) {
                    kablea[1] = 1;
                    irudiaKendu(kablea1.id);
                    zerdo += 3;
                    kablea[0] += 2;
                }
            }
        }
        if (jokalaria.pos.x > 20 && jokalaria.pos.x < 60 && jokalaria.pos.y > 160 && jokalaria.pos.y < 220) {
            if (kablea[2] == 0) {
                if (zerdo + 3 <= motxila) {
                    kablea[2] = 1;
                    irudiaKendu(kablea2.id);
                    zerdo += 3;
                    kablea[0] += 2;
                }
            }
        }
    }
    if (eszena == 6) {
        if (jokalaria.pos.x > 170 && jokalaria.pos.x < 210 && jokalaria.pos.y > 130 && jokalaria.pos.y < 190) {
            if (egurra[1] == 0) {
                if (zerdo + 2 <= motxila) {
                    egurra[1] = 1;
                    irudiaKendu(egurra1.id);
                    zerdo += 2;
                    egurra[0] += 2;
                }
            }
        }
        if (jokalaria.pos.x > 380 && jokalaria.pos.x < 420 && jokalaria.pos.y > 200 && jokalaria.pos.y < 260) {
            if (egurra[2] == 0) {
                if (zerdo + 2 <= motxila) {
                    egurra[2] = 1;
                    irudiaKendu(egurra2.id);
                    zerdo += 2;
                    egurra[0] += 2;
                }
            }
        }
        if (jokalaria.pos.x > 380 && jokalaria.pos.x < 420 && jokalaria.pos.y > 60 && jokalaria.pos.y < 120) {
            if (egurra[3] == 0) {
                if (zerdo + 2 <= motxila) {
                    egurra[3] = 1;
                    irudiaKendu(egurra3.id);
                    zerdo += 2;
                    egurra[0] += 2;
                }
            }
        }
    }
    if (eszena == 7) {
        if (jokalaria.pos.x > 380 && jokalaria.pos.x < 420 && jokalaria.pos.y > 110 && jokalaria.pos.y < 150) {
            if (plastikoa[1] == 0) {
                if (zerdo + 5 <= motxila) {
                    plastikoa[1] = 1;
                    irudiaKendu(plastiko4.id);
                    zerdo += 5;
                    plastikoa[0] += 2;
                }
            }
        }
        if (jokalaria.pos.x > 180 && jokalaria.pos.x < 220 && jokalaria.pos.y > 190 && jokalaria.pos.y < 250) {
            if (plastikoa[2] == 0) {
                if (zerdo + 3 <= motxila) {
                    plastikoa[2] = 1;
                    irudiaKendu(plastiko2.id);
                    zerdo += 5;
                    plastikoa[0] += 2;
                }
            }
        }
    }
    if (eszena == 10) {
        if (jokalaria.pos.x > 340 && jokalaria.pos.x < 380 && jokalaria.pos.y > 270 && jokalaria.pos.y < 330) {
            if (plastikoa[5] == 0) {
                if (zerdo + 5 <= motxila) {
                    plastikoa[5] = 1;
                    irudiaKendu(plastiko5.id);
                    zerdo += 5;
                    plastikoa[0] += 2;
                }
            }
        }
        if (jokalaria.pos.x > 20 && jokalaria.pos.x < 60 && jokalaria.pos.y > 220 && jokalaria.pos.y < 280) {
            if (kablea[3] == 0) {
                if (zerdo + 3 <= motxila) {
                    kablea[3] = 1;
                    irudiaKendu(kablea3.id);
                    zerdo += 3;
                    kablea[0] += 2;
                }
            }
        }
    }
    return zerdo;
}

int zubiakonpondu(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA fondo9, JOKO_ELEMENTUA fondo9B, int zubia, int ebentu, char egurra[], char Kofre[], int eszena) {

    if (eszena == 9) {
        if (Kofre[1] >= 2 || egurra[0] >= 2) {
            if (jokalaria.pos.y > 150 && jokalaria.pos.y < 220 && jokalaria.pos.x >380 && jokalaria.pos.x < 440) {
                zubia = 1;
                irudiaKendu(fondo9.id);
                irudiaMugitu(fondo9B.id, 0, 0);
                egurra[11] = 1;
                if (egurra[0] >= 2) {
                    egurra[0] -= 2;
                    egurra[10] = 1;
                }
                else if (Kofre[1] >= 2) {
                    Kofre[1] -= 2;
                }
            }
        }
    }

    return zubia;
}

int ateaireki(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA fondo4, JOKO_ELEMENTUA fondo4B, int eszena, int giltza, int ireki, char plastikoa[]) {

    if (giltza == 1) {
        if (eszena == 4) {
            if (jokalaria.pos.x < 110) {
                irudiaKendu(fondo4.id);
                irudiaMugitu(fondo4B.id, 0, 0);
                ireki = 1;
            }
        }
    }

    return ireki;
}
int giltzahartu(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA giltzaid, int eszena, int giltza, char kablea[], char plastikoa[]) {
    if (eszena == 10) {
        if (jokalaria.pos.x > 40 && jokalaria.pos.y > 10 && jokalaria.pos.x < 100 && jokalaria.pos.y < 80) {
            irudiaKendu(giltzaid.id);
            giltza = 1;
        }
    }


    return giltza;
}
void inbentario(char materialak[], int motxila)
{
    int ebentu = 0;
    textua(materialak, motxila);

    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);
    pantailaGarbitu();
    pantailaBerriztu();
}
void inbentariomu(char kofre[])
{
    int ebentu = 0;
    kofree(kofre);

    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);
    pantailaGarbitu();
    pantailaBerriztu();
}
void kofree(char Kofre[]) {
    char egurra[50], plastikoa[50], kablea[50];


    sprintf(egurra, "Egurra: %d", Kofre[1]);
    sprintf(plastikoa, "Plastikoa: %d", Kofre[2]);
    sprintf(kablea, "kablea: %d", Kofre[3]);
    pantailaGarbitu();
    textuaIdatzi(225, 200, egurra);
    textuaIdatzi(225, 240, plastikoa);
    textuaIdatzi(225, 280, kablea);
    textuaIdatzi(450, 400, ONGI_ETORRI_MEZUA2);
    pantailaBerriztu();
}
int denda(int motxila, char motxilanivel[], char zenbatplaka[], char zenbaterrota[], char zenbaturerrota[], char energia[], char Kofre[], SDL_Window* window, SDL_Renderer* gRenderer) {
    SDL_Init(SDL_INIT_VIDEO);

    int bat = 0;

    // Crear una ventana
    SDL_Window* amuzon = SDL_CreateWindow("denda",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        0);
    SDL_Texture* dendatextura;
    SDL_Surface* denda;
    denda = IMG_Load("irudiak\\denda.bmp");

    // Obtener un puntero al contexto de renderizado de la ventana
    SDL_Renderer* rendereramuzon = SDL_CreateRenderer(amuzon, -1, 0);

    int done = 0;

    while (done == 0) {

        SDL_Rect rect1;
        rect1.x = 0;
        rect1.y = 0;
        rect1.w = 640;
        rect1.h = 480;


        done = erosi(motxilanivel, zenbatplaka, zenbaterrota, zenbaturerrota, energia, Kofre);


        SDL_SetRenderDrawColor(rendereramuzon, 255, 255, 255, 0);
        SDL_RenderClear(rendereramuzon);


        SDL_SetRenderDrawColor(rendereramuzon, 255, 255, 0, 255);
        SDL_RenderFillRect(rendereramuzon, &rect1);

        if (bat == 0) {

            dendatextura = SDL_CreateTextureFromSurface(rendereramuzon, denda);

            SDL_RenderCopy(rendereramuzon, dendatextura, NULL, &rect1);

            // Mostrar el resultado en la pantalla
            SDL_RenderPresent(rendereramuzon);
            bat++;
        }


        // Hacer una pausa para limitar la tasa de fotogramas
        SDL_Delay(10);
    }

    // Limpiar recursos y salir
    SDL_DestroyRenderer(rendereramuzon);
    SDL_DestroyWindow(amuzon);

    return done;
}

int erosi(char motxilanivel[], char zenbatplaka[], char zenbaterrota[], char zenbaturerrota[], char energia[], char Kofre[]) {

    SDL_Event event;
    int done = 0;

    int mousex;
    int mousey;
    SDL_PumpEvents();
    SDL_GetMouseState(&mousex, &mousey);

    int mousepos = 0;

    while (SDL_PollEvent(&event)) {

        if (mousex > 540 && mousey < 70 && event.type == SDL_MOUSEBUTTONDOWN) {
            done = 1;
        }
        if (motxilanivel[0] == 3 && mousex > 400 && mousex < 510 && mousey > 340 && mousey < 440 && event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Maila", "Maila handienera iritsi zara.", NULL);
            done = 1;
        }
        else {
            if (Kofre[2] < 1 && mousex > 400 && mousex < 510 && mousey > 340 && mousey < 440 && event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Materialak", "Ez duzu nahiko material", NULL);
                done = 1;
            }
            if (Kofre[2] >= 1 && mousex > 370 && mousex < 510 && mousey > 340 && mousey < 440 && event.type == SDL_MOUSEBUTTONDOWN) {
                motxilanivel[0] += 1;
                Kofre[2]-=1;
                done = 2;
            }
        }
        if (zenbatplaka[0] == 2 && mousex > 90 && mousex < 230 && mousey > 310 && mousey < 420 && event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Maila", "Maila handienera iritsi zara.", NULL);
            done = 1;
        }
        else {
            if (Kofre[2] < 1 && Kofre[3] < 2 && mousex > 90 && mousex < 230 && mousey > 310 && mousey < 420 && event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Materialak", "Ez duzu nahiko material", NULL);
                done = 1;
            }
            if (Kofre[2] >= 1 && Kofre[3] >= 2 && mousex > 90 && mousex < 220 && mousey > 310 && mousey < 420 && event.type == SDL_MOUSEBUTTONDOWN) {
                zenbatplaka[0] += 1;
                Kofre[2] -= 1;
                Kofre[3] -= 2;
                energia[0] += 10;
                done = 3;
            }
        }
        if (zenbaterrota[0] == 2 && mousex > 90 && mousex < 200 && mousey > 80 && mousey < 240 && event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Maila", "Maila handienera iritsi zara.", NULL);
            done = 1;
        }
        else {
            if (Kofre[1] < 2 && Kofre[2] < 1 && mousex > 90 && mousex < 200 && mousey > 80 && mousey < 240 && event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Materialak", "Ez duzu nahiko material", NULL);
                done = 1;
            }
            if (Kofre[1] >= 2 && Kofre[2] >= 1 && mousex > 90 && mousex < 200 && mousey > 80 && mousey < 240 && event.type == SDL_MOUSEBUTTONDOWN) {
                zenbaterrota[0] += 1;
                Kofre[1] -= 2;
                Kofre[2] -= 1;
                energia[0] += 10;
                done = 3;
            }
        }
        if (zenbaturerrota[0] == 1 && mousex > 370 && mousex < 500 && mousey > 60 && mousey < 220 && event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Maila", "Maila handienera iritsi zara.", NULL);
            done = 1;
        }
        else {
            if (Kofre[2] < 2 && Kofre[1] < 1 && mousex > 370 && mousex < 500 && mousey > 60 && mousey < 220 && event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Materialak", "Ez duzu nahiko material", NULL);
                done = 1;
            }
            if (Kofre[2] >= 2 && Kofre[1] >= 1 && mousex > 370 && mousex < 500 && mousey > 60 && mousey < 220 && event.type == SDL_MOUSEBUTTONDOWN) {
                zenbaturerrota[0] += 1;
                Kofre[2] -= 2;
                Kofre[1] -= 1;
                energia[0] += 20;
                done = 3;
            }
        }
    }

    return done;
}
void textua(char materialak[], int motxila) {
    int tokila;
    char egurra[50], plastikoa[50], motxilaa[50], kablea[50];
    tokila = 5;


    sprintf(motxilaa, "Motxila: %d/%d", materialak[0], motxila);
    sprintf(egurra, "Egurra: %d", materialak[1]);
    sprintf(plastikoa, "Plastikoa: %d", materialak[2]);
    sprintf(kablea, "Kablea: %d", materialak[3]);
    pantailaGarbitu();
    textuaIdatzi(225, 200, egurra);
    textuaIdatzi(225, 240, plastikoa);
    textuaIdatzi(225, 280, kablea);
    textuaIdatzi(225, 160, motxilaa);
    textuaIdatzi(450, 400, ONGI_ETORRI_MEZUA2);
    pantailaBerriztu();
}
void gauzakgorde(int eszena, char egurra[], char plastikoa[], char kablea[], char Kofre[]) {
    Kofre[1] = Kofre[1] + egurra[0];
    Kofre[2] = Kofre[2] + plastikoa[0];
    Kofre[3] = Kofre[3] + kablea[0];
    egurra[0] = 0;
    plastikoa[0] = 0;
    kablea[0] = 0;
}
