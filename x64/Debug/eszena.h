#ifndef ESZENA_H
#define ESZENA_H

EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int eszena);
int denda1(JOKO_ELEMENTUA jokalaria, int eszena, int motxila, char motxilanivel[], char zenbatplaka[], char zenbaterrota[], char zenbaturerrota[], char energia[], char Kofre[]);
POSIZIOA eszenaaldatu(char zenbatplaka[], char zenbaterrota[], char zenbaturerrota[], JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA npc, JOKO_ELEMENTUA giltzaid, JOKO_ELEMENTUA fondo1, JOKO_ELEMENTUA fondo2, JOKO_ELEMENTUA fondo3, JOKO_ELEMENTUA fondo4, JOKO_ELEMENTUA fondo4B, JOKO_ELEMENTUA fondo5, JOKO_ELEMENTUA fondo6, JOKO_ELEMENTUA fondo6B, JOKO_ELEMENTUA fondo7, JOKO_ELEMENTUA fondo8, JOKO_ELEMENTUA fondo8B, JOKO_ELEMENTUA fondo9, JOKO_ELEMENTUA fondo9B, JOKO_ELEMENTUA fondo10, JOKO_ELEMENTUA egurra1, JOKO_ELEMENTUA egurra2, JOKO_ELEMENTUA egurra3, JOKO_ELEMENTUA egurra4, JOKO_ELEMENTUA egurra5, JOKO_ELEMENTUA egurra6, JOKO_ELEMENTUA plastiko1, JOKO_ELEMENTUA plastiko2, JOKO_ELEMENTUA plastiko3, JOKO_ELEMENTUA plastiko4, JOKO_ELEMENTUA plastiko5, JOKO_ELEMENTUA kablea1, JOKO_ELEMENTUA kablea2, JOKO_ELEMENTUA kablea3, JOKO_ELEMENTUA plaka1, JOKO_ELEMENTUA plaka2, JOKO_ELEMENTUA errota1, JOKO_ELEMENTUA errota2, JOKO_ELEMENTUA urerrota, int eszena, char non[], int ireki, int zubia, char plastikoa[], char egurra[], char kablea[], int giltza);
int eszenazenbaki(EGOERA egoera, int eszena); //berria

#endif