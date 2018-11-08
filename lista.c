#include <stdio.h>
#include <stdlib.h>
#include "trab.h"

#define ERRO -4000

struct _no{
	NO *prox;
	SITE* site;
};

struct _lista{
	NO *cabeca;
	int tam;
};

int ListaVazia(LISTA* l){
	if(l->tam == 0 && (l->cabeca->prox == NULL)){
		return 1;
	}
	else{
		return 0;
	}
}

LISTA* ListaCriar(){
	LISTA* l = (LISTA*)malloc(sizeof(LISTA));
	if( l != NULL ){
		l->cabeca = (NO*)malloc(sizeof(NO));
		if(l->cabeca == NULL){
			return (NULL);
		}
		l->cabeca->prox = NULL;
		l-> tam = 0;
	}
	return l;
}

void ListaApagar(LISTA* l){
	NO* aux;
	NO* aux2;

	aux = l->cabeca->prox;
	while (aux != NULL) {
		aux2 = aux->prox;
		aux->prox = NULL;
		siteFree(aux->site);
		free(aux);
		aux = aux2;
	}
	free(l->cabeca);

	if(l != NULL){
		free(l);
	}
}


int ListaInsereSite(LISTA* l, SITE* s){
	NO* p = NULL;

	NO* n = NULL;

	if(l != NULL){
		p = l->cabeca;

		while((p->prox) != NULL && siteRetornaCod(p->prox->site) < siteRetornaCod(s) ){
			p = p->prox;
		}

		if((p->prox)!=NULL && siteRetornaCod(p->prox->site) == siteRetornaCod(s)){
			return ERRO;
		}

		n = (NO*)malloc(sizeof(NO));
		if(n == NULL) return ERRO;


		n->site = siteInicializa();
		siteCopia(s,n->site);
		siteFree(s);

		n->prox = p->prox;
		p->prox = n;

		l-> tam++;

		return 1;
	}
	return ERRO;
}

int ListaRemoveSite(LISTA* l, int cod){
	if(l != NULL && !(ListaVazia(l))){
		NO* p = l->cabeca;

		while(p->prox != NULL && (siteRetornaCod(p->prox->site) != cod)){
			p = p->prox;
		}

		if(p->prox != NULL){
			NO* aux = p->prox;
			p->prox = aux->prox;
			aux->prox = NULL;


			l-> tam--;
			siteFree(aux->site);
			free(aux);
			return 1;
		}
	}
	return ERRO;
}

SITE* ListaBuscaCodigo(LISTA* l, int cod){
	if(l != NULL){
		NO* p = l->cabeca;

		while(p->prox != NULL && (siteRetornaCod(p->prox->site) != cod)){
			p = p->prox;
		}

		if(p->prox != NULL){
			return p->prox->site;
		}

	}
	return NULL;
}

void ListaPrinta(LISTA *l){
		if(!(ListaVazia(l)) && l != NULL){
			NO* p = l->cabeca;
			while(p->prox != NULL){
				sitePrinta(p->prox->site);
				p = p ->prox;
			}
		return;
		}
	printf("Lista Vazia!\n");
}
