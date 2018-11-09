/*arquivo com teste do TAD site: até agora tudo OK*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"

#define  nomearquivo  "googlebot.txt"

/*funcoes do cliente*/
void recebePalavrasChave(SITE *site,FILE* arquivo);
SITE* recebeSite(FILE* arquivo);
int numLinhas();
/*funcoes do cliente*/

int numLinhas(){

    FILE *arquivo;
    int contador;
    char aux;

    arquivo = fopen(nomearquivo, "r");


    contador = 0;
    aux = getc(arquivo);/*le o primeiro char*/

    while (aux != EOF) {
        if (aux == '\n')
            contador++;
        aux = getc(arquivo);
    }

    fclose(arquivo);
    return contador;
}

SITE* recebeSite(FILE* arquivo) {
    SITE* site;
    site = siteInicializa();
    int codigo;
    char nome[50];
    int relevancia;
    char link[100];
    char palavrasChave[10][50];

    fscanf(arquivo,"%d,%[^,],%d,%[^,],",&codigo,nome,&relevancia,link);
    siteAtualizaCod(site,codigo);
    siteAtualizaNome(site,nome);
    siteAtualizaRelevancia(site,relevancia);
    siteAtualizaLink(site,link);

    recebePalavrasChave(site,arquivo);
    return(site);
}

void recebePalavrasChave(SITE *site,FILE* arquivo) {
    char bufferPalavra[50];
    bufferPalavra[0] = '\0';

    int i,j;
    j = 0;
    i = 0;
    char bufferLetra;
    bufferLetra = '1';

    while (bufferLetra != ',' ||bufferLetra != '\n') {
        bufferLetra = fgetc(arquivo);
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

/*void recebeLista(LISTA* lista) {

    FILE* arquivo;
    arquivo = fopen(nomearquivo, "r");
    SITE* siteTemp;

    int numlin;
    numlin = numLinhas();

    for (int i = 0; i < numlin; i++) {
        siteTemp = recebeSite(arquivo);
        ListaInsereSite(lista,siteTemp);
    }


    fclose(arquivo);
}*/

int main(int argc, char const *argv[]) {
    SITE* site;
    FILE* arquivo;
    arquivo = fopen(nomearquivo, "r");
    site = recebeSite(arquivo);

    sitePrinta(site);
    siteFree(site);
    fclose(arquivo);
    return 0;
}
