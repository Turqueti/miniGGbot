#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"

typedef struct SITE{
    int codigo;
    char *nome;//50
    int relevancia;
    char *link;//100
    char **palavrasChave;//[10][50];

}SITE;

SITE* siteInicializa(){
    SITE *site;
    char *nome;//50
    char *link;//100
    char **palavrasChave;//[10][50];


    site = (SITE*)malloc(sizeof(SITE));
    nome = (char*)malloc(sizeof(char)*50);
    link = (char*)malloc(sizeof(char)*100);

    palavrasChave =  (char**)malloc(sizeof(char*)*10);
    int i = 0;
    for (i = 0; i < 10; i++) {
        palavrasChave[i] = (char*)malloc(sizeof(char)*50);
        palavrasChave[i][0] = '\0';//inicializa as strings com -1 no primeiro char
    }

    nome[0] = '\0';
    link[0] = '\0';
    site->codigo = -1;
    site->nome = nome;
    site->relevancia = -1;
    site->link = link;
    site->palavrasChave = palavrasChave;


    return site;
}
void siteFree(SITE* site) {
    free(site->nome);
    free(site->link);
    int i;
    for (i = 0; i < 10; i++) {
        free(site->palavrasChave[i]);
    }
    free(site->palavrasChave);
    free(site);
}



void siteInsere(SITE* site,int cod,char* nome,int relevancia,char* link,char** palavrasChave,int numPalavras) {

    siteAtualizaCod(site,cod);
    siteAtualizaNome(site,nome);
    siteAtualizaRelevancia(site,relevancia);
    siteAtualizaLink(site,link);
    int i;
    for (i = 0; palavrasChave[i][0] != -1; i++) {
        siteAtualizaPalavrasChave(site,palavrasChave[i]);
    }
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

void siteAtualizaNome(SITE* site, char* nome){
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


void siteAtualizaLink(SITE* site, char* link){
    strcpy(site->link,link);
    //printf("link atualizado com sucesso\n");
}
void sitePrintaLink(SITE* site){
    printf("link: %s\n",site->link);
}

void siteAtualizaPalavrasChave(SITE* site, char* palavra){

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
