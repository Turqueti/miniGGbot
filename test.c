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

void ClienteInsereSite(LISTA* l);
int UsrInptLink(SITE* temp);


void ClienteRemoveSite(LISTA* lista);
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
                ClienteInsereSite(lista);
			break;

			case 2:
                ClienteRemoveSite(lista);
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


/*cliente insere site*/
int UsrInptNome(SITE* temp){

    printf("Insira o nome do site:(MAX 50chars)\n>");
    char nome[50];
    scanf("%s",nome);
    siteAtualizaNome(temp,nome);
    return 0;
}

int UsrInptRelev(SITE* temp){
    int relev;
    printf("Insira a relevancia do site:\n>");
    scanf("%d",&relev);
    if(relev <= 0 || relev >= 1000){
        printf("\nValor de relevancia invalido!!!\nValor deve ser entre [0 - 1000]\n\n");
        return 1;
    }else{
        siteAtualizaRelevancia(temp,relev);
        return 0;
    }
}

int UsrInptLink(SITE* temp){
    printf("Insira o link do site:\n>");
    char link[50];
    scanf("%s",link);
    siteAtualizaLink(temp,link);
    return 0;
}

void ClienteInsereSite(LISTA* l){

    SITE* find;

    do {
        int cod;
        printf("\nInsira um codigo pro site :\n>");
        scanf("%d",&cod);
        find = ListaBuscaCodigo(l,cod);
        if(find == NULL){

            SITE* temp;
            temp = siteInicializa();

            siteAtualizaCod(temp,cod);

            UsrInptNome(temp);

            int test;
            test = UsrInptRelev(temp);
            while (test == 1) {
                test = UsrInptRelev(temp);
            }

            UsrInptLink(temp);


            printf("\nInsira um n de palavras-chave do site:(n=<10)\n");
            int n;
            scanf("%d",&n);


            char* palavratemp;
            int i;
            for(i=0;i<n;i++){
                palavratemp = (char*)malloc(sizeof(char)*50);
                printf("\nInsira uma palavra chave(max 50 char)\n");
                scanf("%s",palavratemp);
                siteAtualizaPalavrasChave(temp,palavratemp);
                free(palavratemp);
            }

            ListaInsereSite(l,temp);
        }else{
        printf("\nCodigo ja existente!!!\nTente outro\n\n");
        }

    } while(find != NULL);

}
/*cliente insere site*/


void ClienteRemoveSite(LISTA* lista) {
    int cod;
    printf("\nDigite o codigo do item a ser deletado: \n");
    scanf("%d",&cod);
    int check = ListaRemoveSite(lista,cod);
    if(check == 1){
        printf("\nSite removido com sucesso\n");
    }else{
        printf("\nNao ha site com este codigo para ser removido\n");
    }
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
