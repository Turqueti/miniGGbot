/*arquivo com teste do TAD site: até agora tudo OK*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

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

void recebeLista(LISTA* lista) {

    int numlin;
    numlin = numLinhas();

    FILE* arquivo;
    arquivo = fopen(nomearquivo, "r");
    SITE* siteTemp;


    int i;
    for (i = 0; i < numlin; i++) {
        siteTemp = recebeSite(arquivo);
        ListaInsereSite(lista,siteTemp);
    }


    fclose(arquivo);
}

void menu(LISTA* lista){
	int opt;
	do{
		printf("\n-[Escolha uma operacao]-\n");
		printf("\n1.Inserir um site\n2.Remover um site\n3.Inserir palavra-chave\n4.Atualizar relevancia\n5.Sair\n6.Imprimir Lista\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
                /*ClienteInsereSite(lista);*/
                printf("1\n");
			break;

			case 2:
                printf("2\n");
                /*ClienteRemoveSite(lista);*/
			break;

			case 3:
                printf("3\n");
                /*ClienteInserePalavraChave(lista);*/
			break;

			case 4:
                printf("4\n");
                /*ClienteAtualizaRelevancia(lista);*/
			break;

            case 6:
                printf("6\n");
                ListaPrinta(lista);
            break;

			default:
                opt = 5;
		}
	}while(opt != 5);
	return;
}


int main(int argc, char const *argv[]) {
    /*recebe entrada*/
    LISTA* l;
    l = ListaCriar();
    recebeLista(l);
    /*recebe entrada*/

    menu(l);
    /*ListaPrinta(l);*/

    /*apaga a lista*/
    ListaApagar(l);
    /*apaga a lista*/
    return 0;
}
