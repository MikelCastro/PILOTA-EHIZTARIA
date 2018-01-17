#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include "OurTypes.h"
#include "Instrukzioak.h"
#include "Jokoa.h"
#include "Sarrera.h"

#define INSTRUK ".\\img\\foto.bmp"
#define GEZIA1 ".\\img\\gezia.bmp"
#define GEZIA2 ".\\img\\flecha.bmp"
#define GEZIAK ".\\img\\geziak.bmp"
#define SPACEBAR ".\\img\\spaceBar.bmp"

GURE_GAUZAK gureGauzak;

int instrukzioa(void)
{
  int ebentu = 0, gelditu = 0;
  POSIZIOA pos;

  jokoarenInstrukzioakBistaratu();
  while (!gelditu)
  {
    ebentu = ebentuaJasoGertatuBada();
    if (ebentu == SAGU_BOTOIA_EZKERRA)
    {
      pos = saguarenPosizioa();
      if ((pos.x > 10) && (pos.x < 220) && (pos.y > 400) && (pos.y < 455)) { gelditu = 1; pantailaGarbitu(); sarrera(); }
      else if ((pos.x > 420) && (pos.x < 630) && (pos.y > 400) && (pos.y < 455)) { gelditu = 1; pantailaGarbitu(); instrukzioa2(); }
    }
    else if (ebentu == TECLA_RETURN) toggleMusic();
  }
  return gelditu;
}

int instrukzioa2(void)
{
  int ebentu = 0, gelditu = 0;
  POSIZIOA pos;
  textuaGaitu();
  gureGauzak.idIrudi = irudiaKargatu(INSTRUK);
  irudiaMugitu(gureGauzak.idIrudi, 0, 0);
  gureGauzak.idIrudi = irudiaKargatu(GEZIA2);
  irudiaMugitu(gureGauzak.idIrudi, 30, 410);
  gureGauzak.idIrudi = irudiaKargatu(SPACEBAR);
  irudiaMugitu(gureGauzak.idIrudi, 50, 200);
  gureGauzak.idIrudi = irudiaKargatu(GEZIAK);
  irudiaMugitu(gureGauzak.idIrudi, 50, 260);
  irudiakMarraztu();
  textuaIdatzi(60, 80, "-  Jokalariak partida irabazi egingo du, pantailako pilota guztiak");
  textuaIdatzi(60, 105, "desagertu egin direnean.  ");
  textuaIdatzi(50, 140, "Beraz, joko honen helburua ahalik eta tiro gutxien eginez puntu");
  textuaIdatzi(50, 165, "gehien lortzean datza. Jokatzeko honako tekla hauek erabiliko dira:");
  textuaIdatzi(130, 200, "-  SPACE BAR: Pilotak jaurti ahal izateko.");
  textuaIdatzi(130, 260, " -  GEZIAK: Piloten norabideak aldatzeko.");
  textuaIdatzi(75, 425, "ATZERA JOAN");
  textuaIdatzi(480, 425, "JOLASTU");
  pantailaBerriztu();
  while (!gelditu)
  {
    ebentu = ebentuaJasoGertatuBada();
    if (ebentu == SAGU_BOTOIA_EZKERRA)
    {
      pos = saguarenPosizioa();
      if ((pos.x > 10) && (pos.x < 220) && (pos.y > 400) && (pos.y < 455)) { gelditu = 1; pantailaGarbitu(); instrukzioa(); }
      else if ((pos.x > 420) && (pos.x < 630) && (pos.y > 400) && (pos.y < 455)) { gelditu = 1; pantailaGarbitu(); jokoa(); }
    }
    else if (ebentu == TECLA_RETURN) toggleMusic();
  }
  return gelditu;
}

void jokoarenInstrukzioakBistaratu(void)
{
  textuaGaitu();
  gureGauzak.idIrudi = irudiaKargatu(INSTRUK);
  irudiaMugitu(gureGauzak.idIrudi, 0, 0);
  gureGauzak.idIrudi = irudiaKargatu(GEZIA1);
  irudiaMugitu(gureGauzak.idIrudi, 590, 410);
  gureGauzak.idIrudi = irudiaKargatu(GEZIA2);
  irudiaMugitu(gureGauzak.idIrudi, 30, 410);
  irudiakMarraztu();
  textuaIdatzi(50, 80, "Pilota ehiztariaren jokoa, kolore berdineko hiru pilota edo gehiago");
  textuaIdatzi(50, 105, "elkartzean datza. Arauak oso errazak dira eta seguruenik aspalditik");
  textuaIdatzi(50, 130, "ezagutuko dituzu, baina, hala ere gogorarazi egingo ditugu:");
  textuaIdatzi(60, 165, "-  Jolasa bukatu egingo da, pilota batek beheko marra ukitu egiten");
  textuaIdatzi(60, 190, "badu.");
  textuaIdatzi(60, 220, "-  Kolore berdineko gero eta pilota gehiago elkartu orduan eta ");
  textuaIdatzi(60, 245, " puntuazio hobeagoa lortzeko aukera izango duzu.");
  textuaIdatzi(75, 425, "ATZERA JOAN");
  textuaIdatzi(440, 425, "AURRERA JOAN");
  pantailaBerriztu();
}