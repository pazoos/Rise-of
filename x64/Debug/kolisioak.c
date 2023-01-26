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

POSIZIOA ERREALITATE_FISIKOA_mugimendua(char zenbaterrota[], char zenbaturerrota[], POSIZIOA posizioa, int noa, int eszena, int ireki, int zubia) {

    if (noa == 1) {
        posizioa.x = posizioa.x + 10;
        if (eszena == 1) {
            if (posizioa.x > 275 && posizioa.y > 250) {
                posizioa.x = posizioa.x - 10;
            }
            if (posizioa.x > 351 && posizioa.y > 100) {
                posizioa.x = posizioa.x - 10;
            }
            if (posizioa.x > 600) {
                posizioa.x = posizioa.x - 10;
            }
            if (zenbaterrota[0] == 1 || zenbaterrota[0] == 2) {
                if (posizioa.x > 20 && posizioa.x < 120 && posizioa.y < 120) {
                    posizioa.x = posizioa.x - 10;
                }
            }
        }
        if (eszena == 2) {
            if (posizioa.x > 600) {
                posizioa.x = posizioa.x - 10;
            }
        }
        if (eszena == 3) {
            if (posizioa.x > 40 && posizioa.x < 61 && posizioa.y < 111 && posizioa.y > 41) {
                posizioa.x = posizioa.x - 10;
            }
        }
        if (eszena == 4) {
            if (posizioa.x > 430 && posizioa.x < 469 && posizioa.y < 350 && posizioa.y > -20) {
                posizioa.x = posizioa.x - 10;
            }
            if (posizioa.x > 98 && posizioa.x < 129 && posizioa.y < 230 && posizioa.y > -20) {
                posizioa.x = posizioa.x - 10;
            }
        }
        if (eszena == 5) {
            if (posizioa.x > 449 && posizioa.x < 460 && posizioa.y > 310 && posizioa.y < 470) {
                posizioa.x = posizioa.x - 10;
            }
            if (posizioa.x > 449 && posizioa.x < 460 && posizioa.y > -20 && posizioa.y < 230) {
                posizioa.x = posizioa.x - 10;
            }
        }
        if (eszena == 6) {
            if (posizioa.x > 600) {
                posizioa.x = posizioa.x - 10;
            }
        }
        if (eszena == 7) {
            if (posizioa.x > 30 && posizioa.x < 50 && posizioa.y > 210 && posizioa.y < 410) {
                posizioa.x = posizioa.x - 10;
            }
            if (posizioa.x > 340 && posizioa.x < 360 && posizioa.y > 20 && posizioa.y < 120) {
                posizioa.x = posizioa.x - 10;
            }
        }
        if (eszena == 8) {
            if (posizioa.x > 600) {
                posizioa.x = posizioa.x - 10;
            }
        }
        if (eszena == 9) {
            if (posizioa.x > 270 && posizioa.x < 290 && posizioa.y > -30 && posizioa.y < 150) {
                posizioa.x = posizioa.x - 10;
            }
        }
        if (eszena == 10) {
            if (posizioa.x > 560) {
                posizioa.x = posizioa.x - 10;
            }
            if (posizioa.x > 380 && posizioa.x < 400 && posizioa.y > 270) {
                posizioa.x = posizioa.x - 10;
            }
            if (posizioa.x > 380 && posizioa.x < 400 && posizioa.y > 160 && posizioa.y < 190) {
                posizioa.x = posizioa.x - 10;
            }
        }
    }
    if (noa == 2) {
        posizioa.x = posizioa.x - 10;
        if (eszena == 1) {
            if (zenbaterrota[0] == 1) {
                if (posizioa.y < 120 && posizioa.x < 120) {
                    posizioa.x = posizioa.x + 10;
                }
            }
            if (zenbaterrota[0] == 2) {
                if (posizioa.y < 120 && posizioa.x < 220) {
                    posizioa.x = posizioa.x + 10;
                }
            }
        }
        if (eszena == 2) {
            if (posizioa.x < 10) {
                posizioa.x = posizioa.x + 10;
            }
            if (posizioa.x < 250 && posizioa.y > 290) {
                posizioa.x = posizioa.x + 10;
            }
        }
        if (eszena == 3) {
            if (posizioa.x > 249 && posizioa.x < 260 && posizioa.y < 101 && posizioa.y > 41) {
                posizioa.x = posizioa.x + 10;
            }
        }
        if (eszena == 4) {
            if (posizioa.x > 118 && posizioa.x < 129 && posizioa.y < 230 && posizioa.y > -20) {
                posizioa.x = posizioa.x + 10;
            }
            if (posizioa.x > 458 && posizioa.x < 469 && posizioa.y < 350 && posizioa.y > -20) {
                posizioa.x = posizioa.x + 10;
            }
            if (posizioa.x > 118 && posizioa.x < 129 && posizioa.y < 480 && posizioa.y > 310) {
                posizioa.x = posizioa.x + 10;
            }
            if (ireki != 1) {
                if (posizioa.x < 10) {
                    posizioa.x = posizioa.x + 10;
                }
            }
        }
        if (eszena == 5) {
            if (posizioa.x < 0) {
                posizioa.x = posizioa.x + 10;
            }
        }
        if (eszena == 7) {
            if (posizioa.x > 360 && posizioa.x < 380 && posizioa.y > 210 && posizioa.y < 390) {
                posizioa.x = posizioa.x + 10;
            }
            if (posizioa.x > 510 && posizioa.x < 530 && posizioa.y > 20 && posizioa.y < 120) {
                posizioa.x = posizioa.x + 10;
            }
            if (posizioa.x < 10) {
                posizioa.x = posizioa.x + 10;
            }
        }
        if (eszena == 9) {
            if (zubia == 0) {
                if (posizioa.x > 360 && posizioa.x < 380 && posizioa.y > -30 && posizioa.y < 390) {
                    posizioa.x = posizioa.x + 10;
                }
            }
            else {
                if (posizioa.x > 360 && posizioa.x < 380 && posizioa.y > -30 && posizioa.y < 150) {
                    posizioa.x = posizioa.x + 10;
                }
                if (posizioa.x > 360 && posizioa.x < 380 && posizioa.y > 220 && posizioa.y < 390) {
                    posizioa.x = posizioa.x + 10;
                }
            }
            if (zenbaturerrota[0] == 1) {
                if (posizioa.x < 180 && posizioa.x > 160 && posizioa.y > 130 && posizioa.y < 250) {
                    posizioa.x = posizioa.x + 10;
                }
            }
            if (posizioa.x > 60 && posizioa.x < 90 && posizioa.y > 90 && posizioa.y < 260) {
                posizioa.x = posizioa.x + 10;
            }
            if (posizioa.x < 10) {
                posizioa.x = posizioa.x + 10;
            }
        }
        if (eszena == 10) {
            if (posizioa.x < 40) {
                posizioa.x = posizioa.x + 10;
            }
        }
    }
    if (noa == 3) {
        posizioa.y = posizioa.y + 10;
        if (eszena == 1) {
            if (posizioa.x > 351 && posizioa.y > 100) {
                posizioa.y = posizioa.y - 10;
            }
            if (posizioa.x > 275 && posizioa.y > 250) {
                posizioa.y = posizioa.y - 10;
            }
            if (posizioa.y > 440) {
                posizioa.y = posizioa.y - 10;
            }
        }
        if (eszena == 2) {
            if (posizioa.y > 440) {
                posizioa.y = posizioa.y - 10;
            }
            if (posizioa.x < 250 && posizioa.y > 290) {
                posizioa.y = posizioa.y - 10;
            }
        }
        if (eszena == 3) {
            if (posizioa.x > 50 && posizioa.x < 260 && posizioa.y > 41 && posizioa.y < 52) {
                posizioa.y = posizioa.y - 10;
            }
            if (posizioa.y > 440) {
                posizioa.y = posizioa.y - 10;
            }
        }
        if (eszena == 4) {
            if (posizioa.y > 440) {
                posizioa.y = posizioa.y - 10;
            }
            if (posizioa.x > -30 && posizioa.x < 130 && posizioa.y > 310 && posizioa.y < 330) {
                posizioa.y = posizioa.y - 10;
            }
        }
        if (eszena == 5) {
            if (posizioa.y > 440) {
                posizioa.y = posizioa.y - 10;
            }
            if (posizioa.x > 440 && posizioa.x < 640 && posizioa.y > 310 && posizioa.y < 330) {
                posizioa.y = posizioa.y - 10;
            }
        }
        if (eszena == 7) {
            if (posizioa.x > 20 && posizioa.x < 370 && posizioa.y > 210 && posizioa.y < 230) {
                posizioa.y = posizioa.y - 10;
            }
            if (posizioa.x > 340 && posizioa.x < 530 && posizioa.y > 20 && posizioa.y < 40) {
                posizioa.y = posizioa.y - 10;
            }
            if (posizioa.x > -20 && posizioa.x < 460 && posizioa.y > 440) { // easter egg posizioa.x > 90
                posizioa.y = posizioa.y - 10;
            }
        }
        if (eszena == 9) {
            if (zenbaturerrota[0] == 1) {
                if (posizioa.y > 130 && posizioa.y < 150 && posizioa.x < 180) {
                    posizioa.y = posizioa.y - 10;
                }
            }
            if (posizioa.x > 80 && posizioa.x < 380 && posizioa.y > 230 && posizioa.y < 260) {
                posizioa.y = posizioa.y - 10;
            }
        }
        if (eszena == 10) {
            if (posizioa.y > 410) {
                posizioa.y = posizioa.y - 10;
            }
            if (posizioa.x > 380 && posizioa.y > 160 && posizioa.y < 190) {
                posizioa.y = posizioa.y - 10;
            }
        }
    }
    if (noa == 4) {
        posizioa.y = posizioa.y - 10;
        if (eszena == 1) {
            if (posizioa.y < 10) {
                posizioa.y = posizioa.y + 10;
            }
            if (zenbaterrota[0] == 1) {
                if (posizioa.y < 120 && posizioa.x < 120) {
                    posizioa.y = posizioa.y + 10;
                }
            }
            if (zenbaterrota[0] == 2) {
                if (posizioa.y < 120 && posizioa.x < 220) {
                    posizioa.y = posizioa.y + 10;
                }
            }
        }
        if (eszena == 2) {
            if (posizioa.y < 10) {
                posizioa.y = posizioa.y + 10;
            }
        }
        if (eszena == 3) {
            if (posizioa.x > 50 && posizioa.x < 260 && posizioa.y > 101 && posizioa.y < 112) {
                posizioa.y = posizioa.y + 10;
            }
        }
        if (eszena == 4) {
            if (posizioa.x > -30 && posizioa.x < 130 && posizioa.y > 210 && posizioa.y < 230) {
                posizioa.y = posizioa.y + 10;
            }
            if (posizioa.x > 50 && posizioa.x < 440 && posizioa.y > -20 && posizioa.y < 0) {
                posizioa.y = posizioa.y + 10;
            }
            if (posizioa.x > 440 && posizioa.x < 460 && posizioa.y > 330 && posizioa.y < 350) {
                posizioa.y = posizioa.y + 10;
            }
        }
        if (eszena == 5) {
            if (posizioa.y < 10) {
                posizioa.y = posizioa.y + 10;
            }
            if (posizioa.x > 440 && posizioa.x < 640 && posizioa.y > 210 && posizioa.y < 230) {
                posizioa.y = posizioa.y + 10;
            }
        }
        if (eszena == 7) {
            if (posizioa.x > 30 && posizioa.x < 380 && posizioa.y > 370 && posizioa.y < 390) {
                posizioa.y = posizioa.y + 10;
            }
            if (posizioa.x > 340 && posizioa.x < 530 && posizioa.y > 100 && posizioa.y < 120) {
                posizioa.y = posizioa.y + 10;
            }
        }
        if (eszena == 8) {
            if (posizioa.y < 10) {
                posizioa.y = posizioa.y + 10;
            }
        }
        if (eszena == 9) {
            if (posizioa.x > -30 && posizioa.x < 380 && posizioa.y > 370 && posizioa.y < 390) {
                posizioa.y = posizioa.y + 10;
            }
            if (posizioa.x > 80 && posizioa.x < 280 && posizioa.y > 0 && posizioa.y < 20) {
                posizioa.y = posizioa.y + 10;
            }
            if (posizioa.x > 280 && posizioa.x < 380 && posizioa.y > 130 && posizioa.y < 150) {
                posizioa.y = posizioa.y + 10;
            }
            if (posizioa.y < 10) {
                posizioa.y = posizioa.y + 10;
            }
        }
        if (eszena == 10) {
            if (posizioa.y < 30) {
                posizioa.y = posizioa.y + 10;
            }
        }
    }
    return posizioa;
}