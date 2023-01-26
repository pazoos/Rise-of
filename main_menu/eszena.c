#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game02/game02.h"
#include "irudiak.h"
#include "graphics.h"
#include "ebentoak.h"
#include "textua.h"
#include "audio.h"
#include "kolisioak.h"
#include "marrazkiak.h"
#include "game02/game02.h"
#include "OurTypes.h"
#include "interaktuatu.h"



EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, int eszena) {
    EGOERA  ret = JOLASTEN;
    if (eszena == 1) {
        if (jokalaria.pos.x > 320 && jokalaria.pos.x < 361 && jokalaria.pos.y > 180 && jokalaria.pos.y < 270) {
            ret = 11;
        }
        if (jokalaria.pos.x < 10) {
            ret = 13;
        }
    }
    if (eszena == 2) {
        if (jokalaria.pos.x > -11 && jokalaria.pos.x < 11 && jokalaria.pos.y > -20 && jokalaria.pos.y < 130) {
            ret = 12;
        }
        if (jokalaria.pos.x > 11 && jokalaria.pos.x < 100 && jokalaria.pos.y > 0 && jokalaria.pos.y < 20) {
            ret = 12;
        }
    }
    if (eszena == 3) {
        if (jokalaria.pos.x > 600) {
            ret = 12;
        }
        if (jokalaria.pos.x < 10) {
            ret = 14;
        }
        if (jokalaria.pos.y < 10) {
            ret = 16;
        }
    }
    if (eszena == 4) {
        if (jokalaria.pos.x > 600) {
            ret = 13;
        }
        if (jokalaria.pos.x < 0) {
            ret = 15;
        }
        if (jokalaria.pos.y < 0) {
            ret = 17;
        }
    }
    if (eszena == 5) {
        if (jokalaria.pos.x > 600) {
            ret = 14;
        }
    }
    if (eszena == 6) {
        if (jokalaria.pos.y > 440) {
            ret = 13;
        }
        if (jokalaria.pos.x < 10) {
            ret = 17;
        }
        if (jokalaria.pos.y < 0) {
            ret = 18;
        }
    }
    if (eszena == 7) {
        if (jokalaria.pos.y > 450) {
            ret = 14;
        }
        if (jokalaria.pos.y < 0) {
            ret = 19;
        }
        if (jokalaria.pos.x > 600) {
            ret = 16;
        }
    }
    if (eszena == 8) {
        if (jokalaria.pos.x < 10) {
            ret = 19;
        }
        if (jokalaria.pos.y > 440) {
            ret = 16;
        }
    }
    if (eszena == 9) {
        if (jokalaria.pos.y > 450) {
            ret = 17;
        }
        if (jokalaria.pos.x > 600) {
            ret = 18;
        }
        if (jokalaria.pos.x > 70 && jokalaria.pos.x < 90 && jokalaria.pos.y > 0 && jokalaria.pos.y < 100) {
            ret = 20;
        }
    }
    if (eszena == 10) {
        if (jokalaria.pos.x > 390 && jokalaria.pos.x < 410 && jokalaria.pos.y > 180 && jokalaria.pos.y < 290) {
            ret = 19;
        }
    }
    return ret;
}

int denda1(JOKO_ELEMENTUA jokalaria, int eszena, int motxila, char motxilanivel[], char zenbatplaka[], char zenbaterrota[], char zenbaturerrota[], char energia[], char Kofre[], SDL_Renderer* gRenderer, SDL_Window* window) {

    if (eszena == 2) {
        if (jokalaria.pos.x < 250 && jokalaria.pos.x > 130 && jokalaria.pos.y < 310 && jokalaria.pos.y > 250) {
            motxila = denda(motxila, motxilanivel, zenbatplaka, zenbaterrota, zenbaturerrota, energia, Kofre,gRenderer,window);
            if (motxila == 8) {
                if (motxilanivel[0] == 1) {
                    motxilanivel[0] = 2;
                }
            }
            if (motxila == 11) {
                if (motxilanivel[0] == 2) {
                    motxilanivel[0] = 3;
                }
            }
        }
    }
    return motxila;
}

POSIZIOA eszenaaldatu(char zenbatplaka[], char zenbaterrota[], char zenbaturerrota[], JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA npc, JOKO_ELEMENTUA giltzaid, JOKO_ELEMENTUA fondo1, JOKO_ELEMENTUA fondo2, JOKO_ELEMENTUA fondo3, JOKO_ELEMENTUA fondo4, JOKO_ELEMENTUA fondo4B, JOKO_ELEMENTUA fondo5, JOKO_ELEMENTUA fondo6, JOKO_ELEMENTUA fondo6B, JOKO_ELEMENTUA fondo7, JOKO_ELEMENTUA fondo8, JOKO_ELEMENTUA fondo8B, JOKO_ELEMENTUA fondo9, JOKO_ELEMENTUA fondo9B, JOKO_ELEMENTUA fondo10, JOKO_ELEMENTUA egurra1, JOKO_ELEMENTUA egurra2, JOKO_ELEMENTUA egurra3, JOKO_ELEMENTUA egurra4, JOKO_ELEMENTUA egurra5, JOKO_ELEMENTUA egurra6, JOKO_ELEMENTUA plastiko1, JOKO_ELEMENTUA plastiko2, JOKO_ELEMENTUA plastiko3, JOKO_ELEMENTUA plastiko4, JOKO_ELEMENTUA plastiko5, JOKO_ELEMENTUA kablea1, JOKO_ELEMENTUA kablea2, JOKO_ELEMENTUA kablea3, JOKO_ELEMENTUA plaka1, JOKO_ELEMENTUA plaka2, JOKO_ELEMENTUA errota1, JOKO_ELEMENTUA errota2, JOKO_ELEMENTUA urerrota, int eszena, char non[], int ireki, int zubia, char plastikoa[], char egurra[], char kablea[], int giltza) {


    if (eszena == 1) {
        if (non[0] == 2) {
            irudiaMugitu(fondo1.id, 0, 0);
            irudiaMugitu(fondo2.id, 1000, 1000);
            if (zenbatplaka[0] == 1) {
                irudiaMugitu(plaka1.id, 430, 140);
            }
            if (zenbatplaka[0] == 2) {
                irudiaMugitu(plaka1.id, 430, 140);
                irudiaMugitu(plaka2.id, 530, 140);
            }
            if (zenbaterrota[0] == 1) {
                irudiaMugitu(errota1.id, 50, 15);
            }
            if (zenbaterrota[0] == 2) {
                irudiaMugitu(errota1.id, 50, 15);
                irudiaMugitu(errota2.id, 150, 15);
            }
            non[0] = 1;
            jokalaria.pos.x = 290;
            jokalaria.pos.y = 210;
        }
        if (non[0] == 3) {
            irudiaMugitu(fondo3.id, 1000, 1000);
            irudiaMugitu(fondo1.id, 0, 0);
            if (zenbatplaka[0] == 1) {
                irudiaMugitu(plaka1.id, 430, 140);
            }
            if (zenbatplaka[0] == 2) {
                irudiaMugitu(plaka1.id, 430, 140);
                irudiaMugitu(plaka2.id, 530, 140);
            }
            if (zenbaterrota[0] == 1) {
                irudiaMugitu(errota1.id, 50, 15);
            }
            if (zenbaterrota[0] == 2) {
                irudiaMugitu(errota1.id, 50, 15);
                irudiaMugitu(errota2.id, 150, 15);
            }
            non[0] = 1;
            jokalaria.pos.x = 10;
        }
    }
    if (eszena == 3) {
        if (non[0] == 1) {
            irudiaMugitu(fondo1.id, 1000, 1000);
            irudiaMugitu(fondo3.id, 0, 0);
            if (zenbatplaka[0] == 1) {
                irudiaMugitu(plaka1.id, 1000, 1000);
            }
            if (zenbatplaka[0] == 2) {
                irudiaMugitu(plaka1.id, 1000, 1000);
                irudiaMugitu(plaka2.id, 1000, 1000);
            }
            if (zenbaterrota[0] == 1) {
                irudiaMugitu(errota1.id, 1000, 1000);
            }
            if (zenbaterrota[0] == 2) {
                irudiaMugitu(errota1.id, 1000, 1000);
                irudiaMugitu(errota2.id, 1000, 1000);
            }
            jokalaria.pos.x = 589;
            non[0] = 3;
        }
        if (non[0] == 4) {
            irudiaMugitu(fondo4.id, 1000, 1000);
            irudiaMugitu(fondo4B.id, 1000, 1000);
            irudiaMugitu(plastiko1.id, 1000, 1000);
            irudiaMugitu(fondo3.id, 0, 0);
            jokalaria.pos.x = 10;
            non[0] = 3;
        }
        if (non[0] == 6) {
            irudiaMugitu(fondo6.id, 1000, 1000);
            irudiaMugitu(fondo6B.id, 1000, 1000);
            irudiaMugitu(egurra1.id, 1000, 1000);
            irudiaMugitu(egurra2.id, 1000, 1000);
            irudiaMugitu(egurra3.id, 1000, 1000);
            irudiaMugitu(fondo3.id, 0, 0);
            jokalaria.pos.y = 20;
            non[0] = 3;
        }
    }
    if (eszena == 2) {
        irudiaMugitu(fondo1.id, 1000, 1000);
        irudiaMugitu(fondo2.id, 0, 0);
        if (zenbatplaka[0] == 1) {
            irudiaMugitu(plaka1.id, 1000, 1000);
        }
        if (zenbatplaka[0] == 2) {
            irudiaMugitu(plaka1.id, 1000, 1000);
            irudiaMugitu(plaka2.id, 1000, 1000);
        }
        if (zenbaterrota[0] == 1) {
            irudiaMugitu(errota1.id, 1000, 1000);
        }
        if (zenbaterrota[0] == 2) {
            irudiaMugitu(errota1.id, 1000, 1000);
            irudiaMugitu(errota2.id, 1000, 1000);
        }
        jokalaria.pos.x = 30;
        jokalaria.pos.y = 40;
        non[0] = 2;
    }
    if (eszena == 4) {
        if (non[0] == 3) {
            irudiaMugitu(fondo3.id, 1000, 1000);
            if (ireki == 0) {
                irudiaMugitu(fondo4.id, 0, 0);
                irudiaMugitu(fondo4B.id, 1000, 1000);
            }
            else {
                irudiaMugitu(fondo4B.id, 0, 0);
            }
            if (plastikoa[3] == 0) {
                irudiaMugitu(plastiko1.id, 430, 90);
            }
            jokalaria.pos.x = 589;
            non[0] = 4;
        }
        if (non[0] == 5) {
            irudiaMugitu(fondo5.id, 1000, 1000);
            irudiaMugitu(kablea1.id, 1000, 1000);
            irudiaMugitu(kablea2.id, 1000, 1000);
            irudiaMugitu(plastiko3.id, 1000, 1000);
            if (ireki == 0) {
                irudiaMugitu(fondo4.id, 0, 0);
                irudiaMugitu(fondo4B.id, 1000, 1000);
            }
            else {
                irudiaMugitu(fondo4B.id, 0, 0);
            }
            if (plastikoa[3] == 0) {
                irudiaMugitu(plastiko1.id, 430, 90);
            }
            jokalaria.pos.x = 10;
            non[0] = 4;
        }
        if (non[0] == 7) {
            irudiaMugitu(fondo7.id, 1000, 1000);
            irudiaMugitu(plastiko2.id, 1000, 1000);
            irudiaMugitu(plastiko4.id, 1000, 1000);
            if (ireki == 0) {
                irudiaMugitu(fondo4.id, 0, 0);
                irudiaMugitu(fondo4B.id, 1000, 1000);
            }
            else {
                irudiaMugitu(fondo4B.id, 0, 0);
            }
            if (plastikoa[3] == 0) {
                irudiaMugitu(plastiko1.id, 430, 90);
            }
            jokalaria.pos.y = 10;
            non[0] = 4;
        }
    }
    if (eszena == 5) {
        if (non[0] == 4) {
            irudiaMugitu(fondo5.id, 0, 0);
            irudiaMugitu(fondo4.id, 1000, 1000);
            irudiaMugitu(fondo4B.id, 1000, 1000);
            irudiaMugitu(plastiko1.id, 1000, 1000);
            if (plastikoa[4] == 0) {
                irudiaMugitu(plastiko3.id, 420, 100);
            }
            if (kablea[1] == 0) {
                irudiaMugitu(kablea1.id, 40, 250);
            }
            if (kablea[2] == 0) {
                irudiaMugitu(kablea2.id, 40, 190);
            }
            jokalaria.pos.x = 589;
            non[0] = 5;
        }
    }
    if (eszena == 6) {
        if (non[0] == 3) {
            irudiaMugitu(fondo6.id, 0, 0);
            irudiaMugitu(fondo6B.id, 0, 0);
            irudiaMugitu(fondo3.id, 1000, 1000);
            if (egurra[1] == 0) {
                irudiaMugitu(egurra1.id, 190, 160);
            }
            if (egurra[2] == 0) {
                irudiaMugitu(egurra2.id, 400, 230);
            }
            if (egurra[3] == 0) {
                irudiaMugitu(egurra3.id, 400, 90);
            }
            jokalaria.pos.y = 430;
            non[0] = 6;
        }
        if (non[0] == 7) {
            irudiaMugitu(fondo6.id, 0, 0);
            irudiaMugitu(fondo6B.id, 0, 0);
            irudiaMugitu(fondo7.id, 1000, 1000);
            irudiaMugitu(plastiko4.id, 1000, 1000);
            irudiaMugitu(plastiko2.id, 1000, 1000);
            if (egurra[1] == 0) {
                irudiaMugitu(egurra1.id, 190, 160);
            }
            if (egurra[2] == 0) {
                irudiaMugitu(egurra2.id, 400, 230);
            }
            if (egurra[3] == 0) {
                irudiaMugitu(egurra3.id, 400, 90);
            }
            jokalaria.pos.x = 20;
            non[0] = 6;
        }
        if (non[0] == 8) {
            irudiaMugitu(fondo6.id, 0, 0);
            irudiaMugitu(fondo6B.id, 0, 0);
            irudiaMugitu(fondo8B.id, 1000, 1000);
            irudiaMugitu(fondo8.id, 1000, 1000);
            irudiaMugitu(egurra4.id, 1000, 1000);
            irudiaMugitu(egurra5.id, 1000, 1000);
            if (egurra[1] == 0) {
                irudiaMugitu(egurra1.id, 190, 160);
            }
            if (egurra[2] == 0) {
                irudiaMugitu(egurra2.id, 400, 230);
            }
            if (egurra[3] == 0) {
                irudiaMugitu(egurra3.id, 400, 90);
            }
            jokalaria.pos.y = 10;
            non[0] = 6;
        }
    }
    if (eszena == 7) {
        if (non[0] == 4) {
            irudiaMugitu(fondo7.id, 0, 0);
            irudiaMugitu(fondo4.id, 1000, 1000);
            irudiaMugitu(fondo4B.id, 1000, 1000);
            irudiaMugitu(plastiko1.id, 1000, 1000);
            if (plastikoa[1] == 0) {
                irudiaMugitu(plastiko4.id, 400, 120);
            }
            if (plastikoa[2] == 0) {
                irudiaMugitu(plastiko2.id, 200, 220);
            }
            jokalaria.pos.y = 430;
            non[0] = 7;
        }
        if (non[0] == 6) {
            irudiaMugitu(fondo7.id, 0, 0);
            irudiaMugitu(fondo6B.id, 1000, 1000);
            irudiaMugitu(fondo6.id, 1000, 1000);
            irudiaMugitu(egurra1.id, 1000, 1000);
            irudiaMugitu(egurra2.id, 1000, 1000);
            irudiaMugitu(egurra3.id, 1000, 1000);
            if (plastikoa[1] == 0) {
                irudiaMugitu(plastiko4.id, 400, 120);
            }
            if (plastikoa[2] == 0) {
                irudiaMugitu(plastiko2.id, 200, 220);
            }
            jokalaria.pos.x = 589;
            non[0] = 7;
        }
        if (non[0] == 9) {
            irudiaMugitu(fondo7.id, 0, 0);
            irudiaMugitu(fondo9.id, 1000, 1000);
            irudiaMugitu(fondo9B.id, 1000, 1000);
            irudiaMugitu(npc.id, 1000, 1000);
            if (plastikoa[1] == 0) {
                irudiaMugitu(plastiko4.id, 400, 120);
            }
            if (plastikoa[2] == 0) {
                irudiaMugitu(plastiko2.id, 200, 220);
            }
            if (zenbaturerrota[0] == 1) {
                irudiaMugitu(urerrota.id, 1000, 1000);
            }
            jokalaria.pos.y = 10;
            non[0] = 7;
        }
    }
    if (eszena == 8) {
        if (non[0] == 6) {
            irudiaMugitu(fondo8.id, 0, 0);
            irudiaMugitu(fondo8B.id, 0, 0);
            irudiaMugitu(fondo6B.id, 1000, 1000);
            irudiaMugitu(fondo6.id, 1000, 1000);
            irudiaMugitu(egurra1.id, 1000, 1000);
            irudiaMugitu(egurra2.id, 1000, 1000);
            irudiaMugitu(egurra3.id, 1000, 1000);
            if (egurra[4] == 0) {
                irudiaMugitu(egurra4.id, 190, 160);
            }
            if (egurra[6] == 0) {
                irudiaMugitu(egurra5.id, 400, 90);
            }
            jokalaria.pos.y = 430;
            non[0] = 8;
        }
        if (non[0] == 9) {
            irudiaMugitu(fondo8.id, 0, 0);
            irudiaMugitu(fondo8B.id, 0, 0);
            irudiaMugitu(fondo9.id, 1000, 1000);
            irudiaMugitu(fondo9B.id, 1000, 1000);
            irudiaMugitu(npc.id, 1000, 1000);
            if (zenbaturerrota[0] == 1) {
                irudiaMugitu(urerrota.id, 1000, 1000);
            }
            if (egurra[4] == 0) {
                irudiaMugitu(egurra4.id, 190, 160);
            }
            if (egurra[6] == 0) {
                irudiaMugitu(egurra5.id, 400, 90);
            }
            jokalaria.pos.x = 20;
            non[0] = 8;
        }
    }
    if (eszena == 9) {
        if (non[0] == 7) {
            irudiaMugitu(plastiko4.id, 1000, 1000);
            irudiaMugitu(plastiko2.id, 1000, 1000);
            if (zenbaturerrota[0] == 1) {
                irudiaMugitu(urerrota.id, 110, 140);
            }
            if (zubia == 0) {
                irudiaMugitu(fondo9.id, 0, 0);
                irudiaMugitu(fondo7.id, 1000, 1000);
            }
            else {
                irudiaMugitu(fondo9B.id, 0, 0);
                irudiaMugitu(fondo7.id, 1000, 1000);
            }
            irudiaMugitu(npc.id, 450, 130);
            jokalaria.pos.y = 430;
            non[0] = 9;
        }
        if (non[0] == 8) {
            irudiaMugitu(egurra4.id, 1000, 1000);
            irudiaMugitu(fondo8B.id, 1000, 1000);
            irudiaMugitu(egurra5.id, 1000, 1000);
            if (zenbaturerrota[0] == 1) {
                irudiaMugitu(urerrota.id, 110, 140);
            }
            if (zubia == 0) {
                irudiaMugitu(fondo9.id, 0, 0);
                irudiaMugitu(fondo8.id, 1000, 1000);
            }
            else {
                irudiaMugitu(fondo9B.id, 0, 0);
                irudiaMugitu(fondo8.id, 1000, 1000);
            }
            irudiaMugitu(npc.id, 450, 130);
            jokalaria.pos.x = 589;
            non[0] = 9;
        }
        if (non[0] == 10) {
            irudiaMugitu(giltzaid.id, 1000, 1000);
            irudiaMugitu(plastiko5.id, 1000, 1000);
            irudiaMugitu(kablea3.id, 1000, 1000);
            if (zenbaturerrota[0] == 1) {
                irudiaMugitu(urerrota.id, 110, 140);
            }
            if (zubia == 0) {
                irudiaMugitu(fondo9.id, 0, 0);
                irudiaMugitu(fondo10.id, 1000, 1000);
            }
            else {
                irudiaMugitu(fondo9B.id, 0, 0);
                irudiaMugitu(fondo10.id, 1000, 1000);
            }
            irudiaMugitu(npc.id, 450, 130);
            jokalaria.pos.x = 100;
            jokalaria.pos.y = 50;
            non[0] = 9;
        }
    }
    if (eszena == 10) {
        if (non[0] == 9) {
            irudiaMugitu(fondo10.id, 0, 0);
            irudiaMugitu(fondo9.id, 1000, 1000);
            irudiaMugitu(fondo9B.id, 1000, 1000);
            irudiaMugitu(npc.id, 1000, 1000);
            if (zenbaturerrota[0] == 1) {
                irudiaMugitu(urerrota.id, 1000, 1000);
            }
            if (giltza == 0) {
                irudiaMugitu(giltzaid.id, 50, 45);
            }
            if (plastikoa[5] == 0) {
                irudiaMugitu(plastiko5.id, 360, 300);
            }
            if (kablea[3] == 0) {
                irudiaMugitu(kablea3.id, 40, 250);
            }
            jokalaria.pos.x = 380;
            jokalaria.pos.y = 230;
            non[0] = 10;
        }
    }

    return jokalaria.pos;

}
int eszenazenbaki(EGOERA egoera, int eszena) {

    if (egoera == 11) {
        eszena = 2;
    }
    if (egoera == 12) {
        eszena = 1;
    }
    if (egoera == 13) {
        eszena = 3;
    }
    if (egoera == 14) {
        eszena = 4;
    }
    if (egoera == 15) {
        eszena = 5;
    }
    if (egoera == 16) {
        eszena = 6;
    }
    if (egoera == 17) {
        eszena = 7;
    }
    if (egoera == 18) {
        eszena = 8;
    }
    if (egoera == 19) {
        eszena = 9;
    }
    if (egoera == 20) {
        eszena = 10;
    }

    return eszena;
}
