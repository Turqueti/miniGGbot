#ifndef TRAB_H
#define TRAB_H

#include "site.h"


typedef struct _no NO;

typedef struct _lista LISTA;


int ListaVazia(LISTA* l);

LISTA* ListaCriar();

void ListaApagar(LISTA* l);

int ListaInsereSite(LISTA* l, SITE* s);

int ListaRemoveSite(LISTA* l, int cod);

SITE* ListaBuscaCodigo(LISTA* l, int cod);

void ListaPrinta(LISTA* l);

#endif
