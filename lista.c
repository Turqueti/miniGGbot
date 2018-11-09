#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define ERRO -4000

struct _no{
	NO *prox;
	SITE* site;
};

struct _lista{
	NO *cabeca;
	int tam;
};

/*
	~ Verifica se a lista esta vazia ~

	Parametros:
		l - Lista a ser verificada
	Retorno:
		1 - A lista esta vazia
		0 - Lista NAO vazia
*/
int ListaVazia(LISTA* l){
	if(l->tam == 0 && (l->cabeca->prox == NULL)){
		return 1;
	}
	else{
		return 0;
	}
}

/*
	~ Cria uma lista, alocando dinamicamente a propria lista e seu nó cabeca ~

	Parametros:
		VOID
	Retorno:
		LISTA* - Ponteiro para a lista criado
		NULL - Nao conseguiu alocar a lista ou seu cabeca
*/
LISTA* ListaCriar(){
	LISTA* l = (LISTA*)malloc(sizeof(LISTA)); /* Aloca o ponteiro pra lista */
	if( l != NULL ){
		l->cabeca = (NO*)malloc(sizeof(NO)); /* Aloca o ponteiro para nó */
		if(l->cabeca == NULL){
			return (NULL);
		}
		l->cabeca->prox = NULL;	/* Inicializacao do nó cabeca */
		l-> tam = 0;
	}
	return l;
}

/*
	~ Apaga uma lista e todos os seus nós ~

	Parametros:
		l - Lista a ser apagada
	Retorno:
		VOID
*/
void ListaApagar(LISTA* l){
	if(l != NULL){
		NO* aux;	/* Nó que percorre a lista */
		NO* aux2;	/* Nó que evita perder a referencia de ponteiros */

		aux = l->cabeca->prox;	/* Olha sempre pro proximo nó */
		while (aux != NULL) {
			aux2 = aux->prox;	/* Aponta no seguinte ao que vai ser apagado, assim, nao se perde a referencia dos nós posteriores */
			aux->prox = NULL;
			siteFree(aux->site);	/* Da free no site(item) */
			free(aux);				/* Da free no nó*/
			aux = aux2;
		}
		free(l->cabeca);	/* Apaga o cabeca */

		free(l);	/* Da free na lista */
	}
}

/*
	~ Insere um site na lista ~

	Parametros:
		l - Lista em que o site sera inserido
		s - Site que sera inserido na lista
	Retorno:
		1 - Inseriu com sucesso
		ERRO - Nao foi possivel inserir
*/
int ListaInsereSite(LISTA* l, SITE* s){
	NO* p = NULL;	/* Nó que percorre a lista */
	NO* n = NULL;	/* Nó que sera inserido */

	if(l != NULL){
		p = l->cabeca;

			/* Enquanto nao achar o fim da lista e a chave for maior que o codigo do nó atual...*/
		while((p->prox) != NULL && siteRetornaCod(p->prox->site) < siteRetornaCod(s) ){
			p = p->prox;
		}
			/* Se parou mas nao eh o fim da lista e o codigo do nó atual eh o mesmo da chave (Existe conflito de codigos!) */
		if((p->prox)!=NULL && siteRetornaCod(p->prox->site) == siteRetornaCod(s)){
			return ERRO;
		}

		n = (NO*)malloc(sizeof(NO)); /* Aloca o nó */
		if(n == NULL) return ERRO;


		n->site = siteInicializa(); /* Aloca o site */
		siteCopia(s,n->site);	/* Copia as informacoes do site no parametro */
		siteFree(s);	/* Da free no site do parametro */
		/* --- Um site ja alocado eh passado como parametro. Apartir do momento que copiamos as informacoes
			dele para um site ja alocado em um nó, o site do parametro se torna inutil(pois foi clonado), entao damos free --- */

		n->prox = p->prox;	/* O proximo nó do que acabou de ser alocado vira o proximo nó de p */
		p->prox = n;	/* O proximo no de p vira o no que acabou de ser alocado */
		/* --- Encaixa o nó na posicao certa --- */

		l-> tam++;

		return 1;
	}
	return ERRO;
}

/*
	~ Remove um site da lista e apaga seu nó ~

	Parametros:
		l - Lista em que sera removido o site
		cod - Codigo(chave) do site a ser removido
	Retorno:
		1 - Removeu com sucesso
		ERRO - Nao foi possivel remover ou nao existe site com este codigo na lista
*/
int ListaRemoveSite(LISTA* l, int cod){
	if(l != NULL && !(ListaVazia(l))){
		NO* p = l->cabeca;	/* Nó que percorrera a lista */

			/* Enquanto nao achar o fim da lista e nao encontrar um site com o mesmo codigo da chave... */
		while(p->prox != NULL && (siteRetornaCod(p->prox->site) != cod)){
			p = p->prox;
		}
			/* Se nao eh o fim da lista, entao encontrou um site com o mesmo codigo da chave */
		if(p->prox != NULL){
			NO* aux = p->prox;
			p->prox = aux->prox;
			aux->prox = NULL;


			l-> tam--;
			siteFree(aux->site);	/* Da free no site */
			free(aux);	/* Da free no nó */
			return 1;
		}
	}
	return ERRO;
}

/*
	~ Busca um site na lista, dado um codigo(chave) ~

	Parametros:
		l - Lista em que sera buscado o site
		cod - Codigo(chave) do site a ser buscado
	Retorno:
		SITE* - Site buscado
		NULL - Site nao encontrado ou lista inexistente
*/
SITE* ListaBuscaCodigo(LISTA* l, int cod){
	if(l != NULL){
		NO* p = l->cabeca;

			/* Enquanto nao achar  o fim da lista e nao encontrar um site com o mesmo codigo da chave */
		while(p->prox != NULL && (siteRetornaCod(p->prox->site) != cod)){
			p = p->prox;
		}
			/* Se nao eh o fim da lista, entao encontrou um site com o mesmo codigo da chave */
		if(p->prox != NULL){
			return p->prox->site;
		}

	}
	return NULL;
}

/*
	~ Imprime uma lista inteira na tela ~

	Parametros:
		l - Lista a ser impressa
	Retorno:
		VOID
*/
void ListaPrinta(LISTA *l){
		if(!(ListaVazia(l)) && l != NULL){
			NO* p = l->cabeca;
				/* Percorre a lista */
			while(p->prox != NULL){
				sitePrinta(p->prox->site);	/* Imprime o site do nó atual */
				printf("..........................................................\n");
				p = p ->prox;
			}
		return;
		}
	printf("Lista Vazia!\n");
}
