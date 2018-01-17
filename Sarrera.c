#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include "OurTypes.h"
#include "Instrukzioak.h"
#include "Jokoa.h"
#include "Sarrera.h"


#define PORTADA ".\\img\\portada.bmp"
#define INTRO_SOUND ".\\sound\\Lift.wav" 

GURE_GAUZAK gureGauzak;

void sarrera(void)
{
  int ebentu = 0, irten = 0;
  POSIZIOA pos;
  audioTerminate();
  audioInit();
  loadTheMusic(INTRO_SOUND);
  playMusic();
  sarreraPantailaBistaratu();
  while (!irten)
  {
    ebentu = ebentuaJasoGertatuBada();
    if (ebentu == SAGU_BOTOIA_EZKERRA)
    {
      pos = saguarenPosizioa();
      if ((pos.x > 465) && (pos.x < 615) && (pos.y > 270) && (pos.y < 270 + 50)) irten = 1;
      else if ((pos.x > 25) && (pos.x < 175) && (pos.y > 270) && (pos.y < 270 + 50)) { pantailaGarbitu(); irten = jokoa(); }
      else if ((pos.x > 230) && (pos.x < 410) && (pos.y > 270) && (pos.y < 270 + 50)) { pantailaGarbitu(); irten = instrukzioa(); }
    }
    else if (ebentu == TECLA_RETURN) toggleMusic();
  }

  sgItxi();
}

void sarreraPantailaBistaratu(void)
{
  audioInit();
  textuaGaitu();
  pantailaGarbitu();
  gureGauzak.fondo = irudiaKargatu(PORTADA);
  irudiaMugitu(gureGauzak.fondo, 0, 0);
  irudiakMarraztu();
  arkatzKoloreaEzarri(0, 0, 0);
  errektangeluaMarraztu(25, 270, 150, 50);
  textuaIdatzi(70, 280, "HASI");
  errektangeluaMarraztu(230, 270, 180, 50);
  textuaIdatzi(250, 280, "INSTRUKZIOAK");
  errektangeluaMarraztu(465, 270, 150, 50);
  textuaIdatzi(505, 280, "AMAITU");
  pantailaBerriztu();
}
