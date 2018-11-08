#ifndef SITE_H
#define SITE_H

typedef struct SITE SITE;

/*relacionado a malloc*/
SITE* siteInicializa();
void siteFree(SITE* site);

void sitePrinta(SITE* site);

/*codigo*/
void siteAtualizaCod(SITE* site, int cod);
void sitePrintaCod(SITE* site);
int siteRetornaCod(SITE* site);

/*nome*/
void siteAtualizaNome(SITE* site, char nome[50]);
void sitePrintaNome(SITE* site);

/*relevancia*/
void siteAtualizaRelevancia(SITE* site, int relevancia);
void sitePrintaRelevancia(SITE* site);

/*link*/
void siteAtualizaLink(SITE* site, char link[100]);
void sitePrintaLink(SITE* site);

/*palavras Chave*/
void siteAtualizaPalavrasChave(SITE* site, char palavra[50]);
void sitePrintaPalavrasChave(SITE* site);

void siteCopia(SITE* src,SITE* dest);

#endif
