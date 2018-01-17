#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "OurTypes.h"
#include "Jokoa.h"
#include "Sarrera.h"

#define HOME ".\\img\\SarreraB.bmp"
#define BERRIRO ".\\img\\BerriroB.bmp"
#define ITXI ".\\img\\itxiB.bmp"

#define JOKOA_SOUND ".\\sound\\Candyland.wav" 

#define L1_FONDO ".\\img\\L1pantaila2.bmp"
#define L1_NOVENTA ".\\img\\L1canon90.bmp"
#define L1_SETENTA ".\\img\\L1canon75.bmp"
#define L1_CUARENTA ".\\img\\L1canon45.bmp"
#define L1_VEINTE ".\\img\\L1canon25.bmp"
#define L1_SETENTAM ".\\img\\L1canon-75.bmp"
#define L1_CUARENTAM ".\\img\\L1canon-45.bmp"
#define L1_VEINTEM ".\\img\\L1canon-25.bmp"

#define L2_FONDO ".\\img\\L2pantaila2.bmp"
#define L2_NOVENTA ".\\img\\L2canon90.bmp"
#define L2_SETENTA ".\\img\\L2canon75.bmp"
#define L2_CUARENTA ".\\img\\L2canon45.bmp"
#define L2_VEINTE ".\\img\\L2canon25.bmp"
#define L2_SETENTAM ".\\img\\L2canon-75.bmp"
#define L2_CUARENTAM ".\\img\\L2canon-45.bmp"
#define L2_VEINTEM ".\\img\\L2canon-25.bmp"

#define L3_FONDO ".\\img\\L3pantaila2.bmp"
#define L3_NOVENTA ".\\img\\L3canon90.bmp"
#define L3_SETENTA ".\\img\\L3canon75.bmp"
#define L3_CUARENTA ".\\img\\L3canon45.bmp"
#define L3_VEINTE ".\\img\\L3canon25.bmp"
#define L3_SETENTAM ".\\img\\L3canon-75.bmp"
#define L3_CUARENTAM ".\\img\\L3canon-45.bmp"
#define L3_VEINTEM ".\\img\\L3canon-25.bmp"

#define PI 3.14
#define RADIO 15
#define SOINU_KOP 5

PELOTA PM[9][11], jaurtigaia[4];
GURE_GAUZAK gureGauzak;

int jokoa(void)
{
  double angle = 90;
  int gertatu = 0;
  int ebentu = 0;
  int kont = 0;
  POSIZIOA pos;
  audioTerminate();
  audioInit();
  loadTheMusic(JOKOA_SOUND);
  playMusic();
  jokoPantailaBistaratu();
  jaurtigaiaSortu();
  jaurtigaiaMarraztu();
  pantailaBerriztu();
  pilotaMultzoaSortu();
  while (!gertatu)
  {
    ebentu = ebentuaJasoGertatuBada();
    if (ebentu == SAGU_BOTOIA_EZKERRA)
    {
      pos = saguarenPosizioa();
      if ((pos.x > 90) && (pos.x < 90 + 60) && (pos.y > 400) && (pos.y < 400 + 60)) { jokoa(); gertatu = 1; }
      else if ((pos.x > 90 + 60 + 10) && (pos.x < 220) && (pos.y > 400) && (pos.y < 400 + 60)) { gertatu = 1; }
      else if ((pos.x > 20) && (pos.x < 20 + 60) && (pos.y > 400) && (pos.y < 400 + 60)) { gertatu = 1; pantailaGarbitu(); sarrera(); }
    }

    else if (ebentu == TECLA_RETURN) toggleMusic();

    if (ebentu == TECLA_SPACE)
    {
      tiroaEgin(angle);
    }
    if (ebentu == TECLA_LEFT)
    {
      angle = kainoiakLeft(angle, kont);
      kont--;
    }
    if (ebentu == TECLA_RIGHT)
    {
      angle = kainoiakRight(angle, kont);
      kont++;
    }
    if (ebentu == TECLA_BACKSPACE)
    {
      hurrengoPilotakSortu();
      jaurtigaiaMarraztu();
      pantailaBerriztu();
    }
  }

  return gertatu;
}

double radianetara(double angelua)
{
  double radianak;
  radianak = (angelua*PI) / 180;
  return radianak;
}

void pilotaMultzoaSortu(void) /*+35*/
{
  srand(time(NULL));
  int i = 8;
  int j = 10, k = 125, m = 605; /*k=125*/

  do {
    if (i % 2 != 0 && j == 10)
    {
      PM[i][j].visible = 0;
      m = 620;
    }
    else
    {
      PM[i][j].visible = 1;
      PM[i][j].color = koloreak();
      zirkuluaMarraztu(PM[i][j].x = m, PM[i][j].y = k, RADIO);
    }
    m -= 35;
    j--;
    if (j < 0)
    {
      i--;
      j = 10;
      k -= 35;
      m = 605;
    }

  } while (i >= 0);

  pantailaBerriztu();
}

//Hemendik aurrera beste funtzio batean. Nola pasatu matrizea?
//Sleep(30000);
// pantailaGarbitu();
/*i=8;
do {
t = denbora();
if (t)
{
PM[i][j].y += 35;
if (j < 0)
{
j = 10;
i--;
}
}
if (!PM[i][j].visible)
{
arkatzKoloreaEzarri(50, 182, 175);
zirkuluaMarraztu(PM[i][j].x, PM[i][j].y, RADIO);
}
else
{
arkatzKoloreaEzarri(255, 255, 255);
zirkuluaMarraztu(PM[i][j].x, PM[i][j].y, RADIO);
}
pantailaBerriztu();
j--;
} while (i>=0);*/

void jokoPantailaBistaratu(void)
{
  gureGauzak.idIrudi = irudiaKargatu(L1_FONDO);
  gureGauzak.idIrudi2 = irudiaKargatu(BERRIRO);
  gureGauzak.idIrudi3 = irudiaKargatu(HOME);
  gureGauzak.idIrudi4 = irudiaKargatu(ITXI);
  gureGauzak.id = irudiaKargatu(L1_NOVENTA);
  jokoarenElementuakMugitu();
  pantailaBerriztu();
}

void jokoarenElementuakMugitu(void)
{
  irudiaMugitu(gureGauzak.idIrudi, 0, 0);
  irudiaMugitu(gureGauzak.idIrudi2, 90, 400);
  irudiaMugitu(gureGauzak.idIrudi3, 20, 400);
  irudiaMugitu(gureGauzak.idIrudi4, 160, 400);
  irudiaMugitu(gureGauzak.id, 382, 375);
  irudiakMarraztu();
  arkatzKoloreaEzarri(0XFF, 0xFF, 0xFF);
  zuzenaMarraztu(228, SCREEN_HEIGHT * 4 / 6, 635, SCREEN_HEIGHT * 4 / 6);
  arkatzKoloreaEzarri(0XFF, 0xFF, 0xFF);
  errektangeluaMarraztu(227, 5, 409, 470);
  textuaGaitu();
  textuaIdatzi(10, 10, "Return: musika ON/OFF");
  textuaIdatzi(10, 60, "PUNTUAK: ");
  textuaIdatzi(10, 90, "LEVEL 1");
}

int koloreak(void)
{
  int r;
  r = rand() % 5;
  koloreaEzarri(r);
  return r;
}

void koloreaEzarri(int aldagaia)
{
  if (aldagaia == 0)
  {
    arkatzKoloreaEzarri(255, 255, 51);
  }
  else if (aldagaia == 1)
  {
    arkatzKoloreaEzarri(0, 51, 255);
  }
  else if (aldagaia == 2)
  {
    arkatzKoloreaEzarri(0, 255, 102);
  }
  else if (aldagaia == 3)
  {
    arkatzKoloreaEzarri(171, 71, 188);
  }
  else
  {
    arkatzKoloreaEzarri(255, 87, 51);
  }

}

void tiroaEgin(double angle)
{
  double t = 0, x0 = 432, y0 = 430;
  int v = 2;
  double r = 0;
  angle = radianetara(angle);
  do {
    jaurtigaia[0].x = x0 - v * cos(angle)*t;
    jaurtigaia[0].y = y0 - v * sin(angle)*t;
    t++;
    pantailaGarbitu();
    jokoarenElementuakMugitu();
    matrizeaMarraztu();
    jaurtigaiaMarraztu();
    pantailaBerriztu();
    if (jaurtigaia[0].x <= 227 || jaurtigaia[0].x >= 640)
    {
      errebotea(jaurtigaia[0].x, jaurtigaia[0].y, v, angle);
      r = 1;
    }
  } while (!r && jaurtigaia[0].y>0);
  jaurtigaia[0].color = jaurtigaia[3].color;
  jaurtigaia[3].color = jaurtigaia[2].color;
  jaurtigaia[2].color = jaurtigaia[1].color;
  jaurtigaia[1].color = koloreak();
  koloreaEzarri(jaurtigaia[0].color);
  jaurtigaia[0].x = 432;
  jaurtigaia[0].y = 430;
  jaurtigaiaMarraztu();
  pantailaBerriztu();
}

void errebotea(double x0, double y0, int v, double angle)
{
  int t = 1, r = 0;
  angle = angle * (180 / PI);
  if (angle >= 0 && angle <= 90)
    angle = 180 - angle;
  else if (angle >= 90 && angle <= 180)
    angle -= 90;
  angle = radianetara(angle);
  do {

    jaurtigaia[0].x = x0 - v * cos(angle)*t;
    jaurtigaia[0].y = y0 - v * sin(angle)*t;
    t++;
    pantailaGarbitu();
    jokoarenElementuakMugitu();
    matrizeaMarraztu();
    jaurtigaiaMarraztu();
    pantailaBerriztu();
    if (jaurtigaia[0].x <= 227 || jaurtigaia[0].x >= 640)
    {
      errebotea(jaurtigaia[0].x, jaurtigaia[0].y, v, angle);
      r = 1;
    }
  } while (!r && jaurtigaia[0].y>0);
  jaurtigaia[0].color = jaurtigaia[3].color;
  jaurtigaia[3].color = jaurtigaia[2].color;
  jaurtigaia[2].color = jaurtigaia[1].color;
  jaurtigaia[1].color = koloreak();
  koloreaEzarri(jaurtigaia[0].color);
  jaurtigaia[0].x = 432;
  jaurtigaia[0].y = 430;
  zirkuluaMarraztu(jaurtigaia[0].x, jaurtigaia[0].y, RADIO);
  pantailaBerriztu();
}

void matrizeaMarraztu(void)
{
  int i = 8, j = 10;
  do {
    koloreaEzarri(PM[i][j].color);
    if (PM[i][j].visible != 0)
    {
      zirkuluaMarraztu(PM[i][j].x, PM[i][j].y, RADIO);
    }
    j--;
    if (j < 0)
    {
      i--;
      j = 10;
    }
  } while (i >= 0);
}

int pilotaAlDago(void)
{
  int i = 0, j = 0;
  if (((PM[i][j].x == jaurtigaia[0].x) || (PM[i][j].x > (jaurtigaia[0].x + RADIO)) || (PM[i][j].x <= (jaurtigaia[0].x + RADIO))))
  {
    return 1;
  }
  return 0;
}

void jaurtigaiaSortu(void)
{
  srand(time(NULL));
  hurrengoPilotakSortu();
  jaurtigaia[0].color = koloreak();
  jaurtigaia[0].x = 432;
  jaurtigaia[0].y = 430;
}

void jaurtigaiaMarraztu(void)
{
  int i = 0;
  do {
    koloreaEzarri(jaurtigaia[i].color);
    zirkuluaMarraztu(jaurtigaia[i].x, jaurtigaia[i].y, RADIO);
    i++;
  } while (i <= 3);
}

void hurrengoPilotakSortu(void)
{
  int i = 1, x = 50, y = 250;
  do
  {
    jaurtigaia[i].x = x;
    jaurtigaia[i].y = y;
    jaurtigaia[i].color = koloreak();
    i++;
    x += 35;
  } while (i <= 3);
}

int kainoiakLeft(double angle, int kont)
{
  pantailaGarbitu();
  if (kont == 3)
  {
    irudiaKendu(gureGauzak.id);
    angle = 135;
    gureGauzak.id = irudiaKargatu(L1_CUARENTA);
  }
  if (kont == 2)
  {
    irudiaKendu(gureGauzak.id);
    angle = 105;
    gureGauzak.id = irudiaKargatu(L1_SETENTA);
  }
  if (kont == 1)
  {
    irudiaKendu(gureGauzak.id);
    angle = 90;
    gureGauzak.id = irudiaKargatu(L1_NOVENTA);
  }
  if (kont == 0)
  {
    irudiaKendu(gureGauzak.id);
    angle = 75;
    gureGauzak.id = irudiaKargatu(L1_SETENTAM);
  }
  if (kont == -1)
  {
    irudiaKendu(gureGauzak.id);
    angle = 45;
    gureGauzak.id = irudiaKargatu(L1_CUARENTAM);
  }
  if (kont == -2)
  {
    angle = 25;
    gureGauzak.id = irudiaKargatu(L1_VEINTEM);
  }
  irudiaMugitu(gureGauzak.id, 382, 375);
  irudiakMarraztu();
  jokoarenElementuakMugitu();
  matrizeaMarraztu();
  jaurtigaiaMarraztu();
  pantailaBerriztu();
  return angle;
}

int kainoiakRight(double angle, int kont)
{
  pantailaGarbitu();
  if (kont == -2)
  {
    irudiaKendu(gureGauzak.id);
    angle = 45;
    gureGauzak.id = irudiaKargatu(L1_CUARENTAM);
  }
  if (kont == -1)
  {
    irudiaKendu(gureGauzak.id);
    angle = 75;
    gureGauzak.id = irudiaKargatu(L1_SETENTAM);
  }
  if (kont == 0)
  {
    irudiaKendu(gureGauzak.id);
    angle = 90;
    gureGauzak.id = irudiaKargatu(L1_NOVENTA);
  }
  if (kont == 1)
  {
    irudiaKendu(gureGauzak.id);
    angle = 105;
    gureGauzak.id = irudiaKargatu(L1_SETENTA);
  }
  if (kont == 2)
  {
    angle = 135;
    gureGauzak.id = irudiaKargatu(L1_CUARENTA);
  }
  if (kont == 3)
  {
    irudiaKendu(gureGauzak.id);
    angle = 155;
    gureGauzak.id = irudiaKargatu(L1_VEINTE);
  }
  irudiaMugitu(gureGauzak.id, 382, 375);
  irudiakMarraztu();
  jokoarenElementuakMugitu();
  matrizeaMarraztu();
  jaurtigaiaMarraztu();
  pantailaBerriztu();
  return angle;
}
