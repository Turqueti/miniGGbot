#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"

void recebePalavrasChave(SITE *site);

void recebeSite(SITE* site) {
    int codigo;
    char nome[50];
    int relevancia;
    char link[100];
    char palavrasChave[10][50];

    scanf("%d,%[^,],%d,%[^,],",&codigo,nome,&relevancia,link);
    siteAtualizaCod(site,codigo);
    siteAtualizaNome(site,nome);
    siteAtualizaRelevancia(site,relevancia);
    siteAtualizaLink(site,link);

    recebePalavrasChave(site);
}

void recebePalavrasChave(SITE *site) {
    char bufferPalavra[50];
    bufferPalavra[0] = '\0';

    int i,j;
    j = 0;
    i = 0;
    char bufferLetra;
    bufferLetra = '1';

    while (bufferLetra != ',' ||bufferLetra != '\n') {
        bufferLetra = getchar();
        bufferPalavra[i] = bufferLetra;
        i++;
        if(bufferLetra == ','){

            bufferPalavra[i-1] = '\0';
            siteAtualizaPalavrasChave(site,bufferPalavra);
            j++;
            i = 0;


        }else if (bufferLetra == '\n') {

            bufferPalavra[i-1] = '\0';
            siteAtualizaPalavrasChave(site,bufferPalavra);
            j++;
            i = 0;
            break;
        }
    }
}

int main(int argc, char const *argv[]) {
    SITE* site;
    site = siteInicializa();

    recebeSite(site);

    sitePrinta(site);
    siteFree(site);

    return 0;
}
