#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"

typedef struct SITE{
    int codigo;
    char nome[50];
    int relevancia;
    char link[100];
    char palavrasChave[10][50];

}SITE;

/*retorna um ponteiro pra site alocado na heap*/
SITE* siteInicializa(){
	SITE* site;
	site = (SITE*)malloc(sizeof(SITE));

    /*colocam o primeiro char como '\0' pra poder usar a funcao strcpy*/
    site->nome[0] = '\0';
    site->link[0] = '\0';

    int i;
    for (i = 0; i < 10; i++) {
        site->palavrasChave[i][0] = '\0';
    }

	return site;
}


void siteCria(SITE* site, char nome[30],int relevancia,char link[100],char palavrasChave[10][50],int numPalavras){
    int i;
    /*copia os paremetros da função pra dentro da estrutura*/
    strcpy(site->nome,nome);
    strcpy(site->link,link);
    site->relevancia = relevancia;
    for (i = 0; i < numPalavras; i++) {
        strcpy(site->palavrasChave[i],palavrasChave[i]);
    }

    printf("site inserido\n");
}

void siteFree(SITE* site){
    free(site);
}

void sitePrinta(SITE* site){
    sitePrintaCod(site);
    sitePrintaNome(site);
    sitePrintaRelevancia(site);
    sitePrintaLink(site);
    sitePrintaPalavrasChave(site);
}

void siteAtualizaCod(SITE* site, int cod){
    site->codigo = cod;
    //printf("codigo atualizado com sucesso\n");
}

void sitePrintaCod(SITE* site){
    printf("codigo: %d\n",site->codigo);
}

int siteRetornaCod(SITE* site){
    int cod;
    cod = site->codigo;
    return cod;
}


void siteAtualizaNome(SITE* site, char nome[50]){
    strcpy(site->nome,nome);
    //printf("nome atualizado com sucesso\n");
}

void sitePrintaNome(SITE* site){
    printf("nome: %s\n",site->nome);
}

void siteAtualizaRelevancia(SITE* site, int relevancia){
    site->relevancia = relevancia;
    //printf("relevancia atualizada com sucesso\n");
}

void sitePrintaRelevancia(SITE* site){
    printf("relevancia: %d\n",site->relevancia);
}


void siteAtualizaLink(SITE* site, char link[100]){
    strcpy(site->link,link);
    //printf("link atualizado com sucesso\n");
}

void sitePrintaLink(SITE* site){
    printf("link: %s\n",site->link);
}

void siteAtualizaPalavrasChave(SITE* site, char palavra[50]){

    int i;
    for (i = 0; i < 10; i++) {
        if(site->palavrasChave[i][0] == '\0' )
        {
            strcpy(site->palavrasChave[i],palavra);
            //printf("palavra adicionada com sucesso\n");
            break;

        }else if (site->palavrasChave[i][0] != '\0' && i == 9) {
            printf("não é possivel colocar mais palavras chave(max = 10)\n");
        }
    }
}

void sitePrintaPalavrasChave(SITE* site) {
    int i;
    for (i = 0; i < 10; i++) {
        if(site->palavrasChave[i][0] != '\0'){
            printf("palavra%d %s\n",i,site->palavrasChave[i]);
        }else{
            break;
        }
    }
}

void siteCopia(SITE* src,SITE* dest) {
    siteAtualizaCod(dest,src->codigo);
    siteAtualizaNome(dest,src->nome);
    siteAtualizaRelevancia(dest,src->relevancia);
    siteAtualizaLink(dest,src->link);

    int i = 0;
    for (i = 0; i < 10; i++) {
        siteAtualizaPalavrasChave(dest,src->palavrasChave[i]);
    }
}
