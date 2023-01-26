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


#define JOKOA_PLAYER "irudiak\\prota.bmp"
#define JOKOA_NPC "irudiak\\mendizalea.bmp"
#define JOKOA_GILTZA "irudiak\\giltza.bmp"
#define JOKOA_FONDO1 "irudiak\\fondo1.bmp"
#define JOKOA_FONDO2 "irudiak\\fondo2.bmp"
#define JOKOA_FONDO3 "irudiak\\fondo3.bmp"
#define JOKOA_FONDO4 "irudiak\\fondo4.bmp"
#define JOKOA_FONDO4B "irudiak\\fondo4Irekita.bmp"
#define JOKOA_FONDO5 "irudiak\\fondo5.bmp"
#define JOKOA_FONDO6 "irudiak\\fondo6.bmp"
#define JOKOA_FONDO6B "irudiak\\fondo6Zuhaitzak.bmp"
#define JOKOA_FONDO7 "irudiak\\fondo7.bmp"
#define JOKOA_FONDO8 "irudiak\\fondo8.bmp"
#define JOKOA_FONDO8B "irudiak\\fondo8Zuhaitzak.bmp"
#define JOKOA_FONDO9 "irudiak\\fondo9.bmp"
#define JOKOA_FONDO9B "irudiak\\fondo9Konponduta.bmp"
#define JOKOA_FONDO10 "irudiak\\fondo10.bmp"
#define JOKOA_EGURRA "irudiak\\egurra.bmp"
#define JOKOA_PLASTIKOA "irudiak\\plastikoa.bmp"
#define JOKOA_KABLEA "irudiak\\kablea.bmp"
#define JOKOA_INBENTARIOA "irudiak\\inventario.bmp"
#define JOKOA_PLAKA "irudiak\\plaka.bmp"
#define JOKOA_ERROTA "irudiak\\errota.bmp"
#define JOKOA_URERROTA "irudiak\\urerrota.bmp"

//fonduak
int JOKOA_fondo1()
{
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO1);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();

    return martzianoId;

}
int JOKOA_fondo3()
{
    int fondoid = -1;
    fondoid = irudiaKargatu(JOKOA_FONDO3);
    irudiaMugitu(fondoid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();

    return fondoid;

}
int JOKOA_fondo2()
{
    int fondoid = -1;
    fondoid = irudiaKargatu(JOKOA_FONDO2);
    irudiaMugitu(fondoid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();

    return fondoid;

}
int JOKOA_objetua()
{
    int fondoid = -1;
    fondoid = irudiaKargatu(JOKOA_GILTZA);
    irudiaMugitu(fondoid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return fondoid;

}
int JOKOA_fondo4() {
    int fondoid = -1;
    fondoid = irudiaKargatu(JOKOA_FONDO4);
    irudiaMugitu(fondoid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return fondoid;
}
int JOKOA_fondo4B() {
    int fondoid = -1;
    fondoid = irudiaKargatu(JOKOA_FONDO4B);
    irudiaMugitu(fondoid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return fondoid;
}
int JOKOA_fondo5() {
    int fondoid = -1;
    fondoid = irudiaKargatu(JOKOA_FONDO5);
    irudiaMugitu(fondoid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return fondoid;
}
int JOKOA_fondo6() {
    int fondoid = -1;
    fondoid = irudiaKargatu(JOKOA_FONDO6);
    irudiaMugitu(fondoid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return fondoid;
}
int JOKOA_fondo6B() {
    int fondoid = -1;
    fondoid = irudiaKargatu(JOKOA_FONDO6B);
    irudiaMugitu(fondoid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return fondoid;
}
int JOKOA_fondo7() {
    int fondoid = -1;
    fondoid = irudiaKargatu(JOKOA_FONDO7);
    irudiaMugitu(fondoid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return fondoid;
}
int JOKOA_fondo8() {
    int fondoid = -1;
    fondoid = irudiaKargatu(JOKOA_FONDO8);
    irudiaMugitu(fondoid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return fondoid;
}
int JOKOA_fondo8B() {
    int fondoid = -1;
    fondoid = irudiaKargatu(JOKOA_FONDO8B);
    irudiaMugitu(fondoid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return fondoid;
}
int JOKOA_fondo9() {
    int fondoid = -1;
    fondoid = irudiaKargatu(JOKOA_FONDO9);
    irudiaMugitu(fondoid, 1000, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return fondoid;
}
int JOKOA_fondo9B() {
    int fondoid = -1;
    fondoid = irudiaKargatu(JOKOA_FONDO9B);
    irudiaMugitu(fondoid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return fondoid;
}
int JOKOA_fondo10() {
    int fondoid = -1;
    fondoid = irudiaKargatu(JOKOA_FONDO10);
    irudiaMugitu(fondoid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return fondoid;
}
//materialak
int JOKOA_egurra1() {
    int egurraid = -1;
    egurraid = irudiaKargatu(JOKOA_EGURRA);
    irudiaMugitu(egurraid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return egurraid;
}
int JOKOA_egurra2() {
    int egurraid = -1;
    egurraid = irudiaKargatu(JOKOA_EGURRA);
    irudiaMugitu(egurraid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return egurraid;
}
int JOKOA_egurra3() {
    int egurraid = -1;
    egurraid = irudiaKargatu(JOKOA_EGURRA);
    irudiaMugitu(egurraid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return egurraid;
}
int JOKOA_egurra4() {
    int egurraid = -1;
    egurraid = irudiaKargatu(JOKOA_EGURRA);
    irudiaMugitu(egurraid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return egurraid;
}
int JOKOA_egurra5() {
    int egurraid = -1;
    egurraid = irudiaKargatu(JOKOA_EGURRA);
    irudiaMugitu(egurraid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return egurraid;
}
int JOKOA_egurra6() {
    int egurraid = -1;
    egurraid = irudiaKargatu(JOKOA_EGURRA);
    irudiaMugitu(egurraid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return egurraid;
}
int JOKOA_plastikoa1() {
    int plastikoaid = -1;
    plastikoaid = irudiaKargatu(JOKOA_PLASTIKOA);
    irudiaMugitu(plastikoaid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return plastikoaid;
}
int JOKOA_plastikoa2() {
    int plastikoaid = -1;
    plastikoaid = irudiaKargatu(JOKOA_PLASTIKOA);
    irudiaMugitu(plastikoaid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return plastikoaid;
}
int JOKOA_plastikoa3() {
    int plastikoaid = -1;
    plastikoaid = irudiaKargatu(JOKOA_PLASTIKOA);
    irudiaMugitu(plastikoaid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return plastikoaid;
}
int JOKOA_plastikoa4() {
    int plastikoaid = -1;
    plastikoaid = irudiaKargatu(JOKOA_PLASTIKOA);
    irudiaMugitu(plastikoaid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return plastikoaid;
}
int JOKOA_plastikoa5() {
    int plastikoaid = -1;
    plastikoaid = irudiaKargatu(JOKOA_PLASTIKOA);
    irudiaMugitu(plastikoaid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return plastikoaid;
}
int JOKOA_kablea1() {
    int kableid = -1;
    kableid = irudiaKargatu(JOKOA_KABLEA);
    irudiaMugitu(kableid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return kableid;
}
int JOKOA_kablea2() {
    int kableid = -1;
    kableid = irudiaKargatu(JOKOA_KABLEA);
    irudiaMugitu(kableid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return kableid;
}
int JOKOA_kablea3() {
    int kableid = -1;
    kableid = irudiaKargatu(JOKOA_KABLEA);
    irudiaMugitu(kableid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return kableid;
}

//pertsonaiak
int JOKOA_jokalariaIrudiaSortu(int x, int y)
{
    int protaid = -1;
    pantailaGarbitu();
    protaid = irudiaKargatu(JOKOA_PLAYER);
    irudiaMugitu(protaid, x, y);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return protaid;

}
int JOKOA_npc()
{
    int npcid = -1;
    pantailaGarbitu();
    npcid = irudiaKargatu(JOKOA_NPC);
    irudiaMugitu(npcid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return npcid;
}
//inbentario
int JOKOA_motxila()
{
    int motxilaid = -1;
    pantailaGarbitu();
    motxilaid = irudiaKargatu(JOKOA_INBENTARIOA);
    irudiaMugitu(motxilaid, 525, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return motxilaid;
}
// BERRIAK energia sortzaileak
int JOKOA_plaka1()
{
    int plakaid = -1;
    pantailaGarbitu();
    plakaid = irudiaKargatu(JOKOA_PLAKA);
    irudiaMugitu(plakaid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return plakaid;
}
int JOKOA_plaka2()
{
    int plakaid = -1;
    pantailaGarbitu();
    plakaid = irudiaKargatu(JOKOA_PLAKA);
    irudiaMugitu(plakaid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return plakaid;
}
int JOKOA_errota1()
{
    int errotaid = -1;
    pantailaGarbitu();
    errotaid = irudiaKargatu(JOKOA_ERROTA);
    irudiaMugitu(errotaid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return errotaid;
}
int JOKOA_errota2()
{
    int errotaid = -1;
    pantailaGarbitu();
    errotaid = irudiaKargatu(JOKOA_ERROTA);
    irudiaMugitu(errotaid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return errotaid;
}
int JOKOA_urerrota()
{
    int urerrotaid = -1;
    pantailaGarbitu();
    urerrotaid = irudiaKargatu(JOKOA_URERROTA);
    irudiaMugitu(urerrotaid, 1000, 1000);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return urerrotaid;
}


