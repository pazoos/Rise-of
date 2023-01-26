#ifndef INTERAKTUATU_H
#define INTERAKTUATU_H

int objetuakhartu(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA egurra1, JOKO_ELEMENTUA egurra2, JOKO_ELEMENTUA egurra3, JOKO_ELEMENTUA egurra4, JOKO_ELEMENTUA egurra5, JOKO_ELEMENTUA plastiko1, JOKO_ELEMENTUA plastiko2, JOKO_ELEMENTUA plastiko3, JOKO_ELEMENTUA plastiko4, JOKO_ELEMENTUA plastiko5, JOKO_ELEMENTUA kablea1, JOKO_ELEMENTUA kablea2, JOKO_ELEMENTUA kablea3, int eszena, int ireki, int zerdo, int giltza, int motxila, char egurra[], char plastikoa[], char kablea[], char motxilaa[]);
int zubiakonpondu(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA fondo9, JOKO_ELEMENTUA fondo9B, int zubia, int ebentu, char egurra[], char Kofre[], int eszena);
int ateaireki(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA fondo4, JOKO_ELEMENTUA fondo4B, int eszena, int giltza, int ireki, char plastikoa[]);
int giltzahartu(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA giltzaid, int eszena, int giltza, char kablea[], char plastikoa[]);
void kofree(char Kofre[]);
void inbentariomu(char kofre[]);
void inbentario(char materialak[], int motxila);
int denda(int motxila, char motxilanivel[], char zenbatplaka[], char zenbaterrota[], char zenbaturerrota[], char energia[], char Kofre[], SDL_Window* window, SDL_Renderer* gRenderer);
int erosi(char motxilanivel[], char zenbatplaka[], char zenbaterrota[], char zenbaturerrota[], char energia[], char Kofre[]);
void textua(char materialak[], int motxila);
void gauzakgorde(int eszena, char egurra[], char plastikoa[], char kablea[], char egurraKofre[]);



#endif