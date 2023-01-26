#include "game02.h"
#include "../irudiak.h"
#include "../graphics.h"
#include "../ebentoak.h"
#include "../textua.h"
#include "../audio.h"
#include "../kolisioak.h"
#include "../marrazkiak.h"
#include "../eszena.h"
#include "../interaktuatu.h"
#include <stdio.h>
#include <windows.h>
#include "SDL_TTF.h"
#include "../towerdefence.h"

#define ONGI_ETORRI_MEZUA "Sakatu return hasteko..."
#define PREZIOA "30 euro"
#define JOKOA_EGURRA "irudiak\egurra.bmp"



void sarreraMezuaIdatzi();
int JOKOA_jokalariaIrudiaSortu(int x, int y);
int fonduaSortu();
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, int eszena);
int BUKAERA_irudiaBistaratu();

void jokoaAurkeztu(void)
{
  int ebentu = 0;
  sarreraMezuaIdatzi();
  do
  {
    ebentu = ebentuaJasoGertatuBada();
  } while (ebentu != TECLA_RETURN);
  pantailaGarbitu();
  pantailaBerriztu();
}


void sarreraMezuaIdatzi()
{
  pantailaGarbitu();
  textuaGaitu();
  textuaIdatzi(225, 200, ONGI_ETORRI_MEZUA);
  pantailaBerriztu();
}

EGOERA jokatu(void) 
{
  int noa = 0, eszena = 1, giltza = 0, sortu = 0, motxila = 5, zerdo = 0, ireki = 0, erosia = 0;
  int aldatu = 0, zubia = 0;
  char egurra[50], Kofre[50], plastikoa[50], kablea[50], motxilaa[50], motxilanivel[50], posizio[50], non[50], zenbatplaka[50], zenbaterrota[50], zenbaturerrota[50], energia[50];

  motxilanivel[0] = 1;
  zenbatplaka[0] = 0;
  zenbaterrota[0] = 0;
  zenbaturerrota[0] = 0;
  energia[0] = 0;
  non[0] = 1;

  Kofre[1] = 0;//egurra
  Kofre[2] = 0;//plastikoa
  Kofre[3] = 0;//kablea

  egurra[0] = 0; //dakazun egurra
  plastikoa[0] = 0; //dakazun plastikoa
  kablea[0] = 0; //dakazun kableak
  //egur bakoitza kentzeko
  egurra[1] = 0;
  egurra[2] = 0;
  egurra[3] = 0;
  egurra[4] = 0;
  egurra[5] = 0;
  egurra[6] = 0;
  egurra[11] = 0;
  plastikoa[1] = 0;
  plastikoa[2] = 0;
  plastikoa[3] = 0;
  plastikoa[4] = 0;
  plastikoa[5] = 0;
  kablea[1] = 0;
  kablea[2] = 0;
  kablea[3] = 0;
  kablea[4] = 0;

  EGOERA  egoera = JOLASTEN;
  int ebentu = 0;
  JOKO_ELEMENTUA zirkulua, jokalaria, fondo, giltzaid, npc, motxilaid;
  JOKO_ELEMENTUA plaka1, plaka2, errota1, errota2, urerrota;
  JOKO_ELEMENTUA fondo1, fondo2, fondo3, fondo4, fondo4B, fondo5, fondo6, fondo6B, fondo7, fondo8, fondo8B, fondo9, fondo9B, fondo10;
  JOKO_ELEMENTUA egurra1, egurra2, egurra3, egurra4, egurra5, egurra6, plastiko1, plastiko2, plastiko3, plastiko4, plastiko5, kablea1, kablea2, kablea3;
  POSIZIOA aux;

  jokalaria.pos.x = 20;
  jokalaria.pos.y = 240;

  audioInit();
  playMusic();

  fondo10.id = JOKOA_fondo10();
  fondo9B.id = JOKOA_fondo9B();
  fondo9.id = JOKOA_fondo9();
  fondo8.id = JOKOA_fondo8();
  fondo7.id = JOKOA_fondo7();
  fondo6.id = JOKOA_fondo6();
  fondo5.id = JOKOA_fondo5();
  fondo4B.id = JOKOA_fondo4B();
  fondo4.id = JOKOA_fondo4();
  fondo3.id = JOKOA_fondo3();
  fondo2.id = JOKOA_fondo2();
  egurra1.id = JOKOA_egurra1();
  egurra2.id = JOKOA_egurra2();
  egurra3.id = JOKOA_egurra3();
  egurra4.id = JOKOA_egurra4();
  egurra5.id = JOKOA_egurra5();
  egurra6.id = JOKOA_egurra6();
  plastiko1.id = JOKOA_plastikoa1();
  plastiko2.id = JOKOA_plastikoa2();
  plastiko3.id = JOKOA_plastikoa3();
  plastiko4.id = JOKOA_plastikoa4();
  plastiko5.id = JOKOA_plastikoa5();
  kablea1.id = JOKOA_kablea1();
  kablea2.id = JOKOA_kablea2();
  kablea3.id = JOKOA_kablea3();
  npc.id = JOKOA_npc();
  giltzaid.id = JOKOA_objetua();

  fondo1.id = JOKOA_fondo1();
  errota1.id = JOKOA_errota1();
  errota2.id = JOKOA_errota2();
  jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
  urerrota.id = JOKOA_urerrota();
  fondo6B.id = JOKOA_fondo6B();
  fondo8B.id = JOKOA_fondo8B();
  plaka1.id = JOKOA_plaka1();
  plaka2.id = JOKOA_plaka2();
  motxilaid.id = JOKOA_motxila();



  do {
      do {
          //denda
          if (ebentu == TECLA_e) {
              erosia = denda1(jokalaria, eszena, motxila, motxilanivel, zenbatplaka, zenbaterrota, zenbaturerrota, energia, Kofre);
              if (erosia == 2) {
                  motxila += 3;
              }
          }
          //kofrea
          if (ebentu == TECLA_e) {
              if (eszena == 2) {
                  if (jokalaria.pos.x > 500 && jokalaria.pos.y < 70) {
                      gauzakgorde(eszena, egurra, plastikoa, kablea, Kofre);
                      inbentariomu(Kofre);
                      zerdo = 0;
                  }
              }
          }

          if (ebentu == TECLA_e) {
              if (eszena == 2) {
                  if (jokalaria.pos.x > 500 && jokalaria.pos.y > 320) {
                      TD(energia);
                      
                      zerdo = 0;
                  }
              }
          }

          //atea
          if (ebentu == TECLA_e) {
              if (ireki == 0) {
                  ireki = ateaireki(jokalaria, fondo4, fondo4B, eszena, giltza, ireki, plastikoa);
              }
          }
          // materialak hartu
          if (ebentu == TECLA_e) {
              zerdo = objetuakhartu(jokalaria, egurra1, egurra2, egurra3, egurra4, egurra5, plastiko1, plastiko2, plastiko3, plastiko4, plastiko5, kablea1, kablea2, kablea3, eszena, ireki, zerdo, giltza, motxila, egurra, plastikoa, kablea, motxilaa);
          }
          // zubia konpondu
          if (ebentu == TECLA_e) {
              if (zubia != 1) {
                  zubia = zubiakonpondu(jokalaria, fondo9, fondo9B, zubia, ebentu, egurra, Kofre, eszena);
                  if (egurra[10] == 1) {
                      zerdo -= 2;
                  }
              }
          }
          // giltza hartu
          if (ebentu == TECLA_e) {
              if (giltza == 0) {
                  giltza = giltzahartu(jokalaria, giltzaid, eszena, giltza, kablea, plastikoa);
              }
          }

          Sleep(2);
          irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
          irudiakMarraztu();
          pantailaBerriztu();
          ebentu = ebentuaJasoGertatuBada();
          //inbetario
          if (ebentu == TECLA_q) {
              motxilaa[0] = zerdo; //tokila
              motxilaa[1] = egurra[0]; // egurra
              motxilaa[2] = plastikoa[0]; //plastikoa
              motxilaa[3] = kablea[0]; //kablea
              inbentario(motxilaa, motxila);
          }
          //mugitu 1
          if (ebentu == TECLA_w)
          {
              noa = 4;
              aldatu = 1;
          }
          if (ebentu == TECLA_s)
          {
              noa = 3;
              aldatu = 1;
          }
          if (ebentu == TECLA_a)
          {
              noa = 2;
              aldatu = 1;
          }
          if (ebentu == TECLA_d)
          {
              noa = 1;
              aldatu = 1;
          }
          //MUGITU 2
          if (noa!=0) {
              aux = ERREALITATE_FISIKOA_mugimendua(zenbaterrota, zenbaturerrota, jokalaria.pos, noa, eszena, ireki, zubia);
              jokalaria.pos.y = aux.y;
              jokalaria.pos.x = aux.x;
              noa = 0;
          }
          //MAPA
          egoera = JOKOA_egoera(jokalaria, eszena);
          eszena = eszenazenbaki(egoera, eszena);
      } while (egoera == JOLASTEN);
      //eszena aldatu
      aux = eszenaaldatu(zenbatplaka, zenbaterrota, zenbaturerrota, jokalaria, npc, giltzaid, fondo1, fondo2, fondo3, fondo4, fondo4B, fondo5, fondo6, fondo6B, fondo7, fondo8, fondo8B, fondo9, fondo9B, fondo10, egurra1, egurra2, egurra3, egurra4, egurra5, egurra6, plastiko1, plastiko2, plastiko3, plastiko4, plastiko5, kablea1, kablea2, kablea3, plaka1, plaka2, errota1, errota2, urerrota, eszena, non, ireki, zubia, plastikoa, egurra, kablea, giltza, posizio);
      jokalaria.pos.y = aux.y;
      jokalaria.pos.x = aux.x;
      egoera = JOLASTEN;
  } while (egoera == JOLASTEN);
  irudiaKendu(jokalaria.id);
  toggleMusic();
  audioTerminate();
  pantailaGarbitu();
  pantailaBerriztu();
  return egoera;
}
