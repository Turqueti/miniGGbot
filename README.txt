*********************************************************************************
Projeto desenvolvido por:

 	-	Vitor Henrique Turqueti dos Santos		  NUSP: 10844313
 	
	-	Maurilio da Motta Meireles			  NUSP: 10734501
	-	Lucas Henrique Simoes Gaspar de Almeida Rodrigues NUSP: 10723691


********************************************************************************

*

Instruções de uso:
------------------------------------------------------------------------------------------------

É recomendado utilizar um ambiente Linux ao usar o programa, já que o mesmo foi
desenvolvido nesta plataforma e compilado utlizando o gcc versão 4.6.3.

Para compilar:
	Mova todos os arquivos para uma mesma pasta e digite o comando
		
		 make 

	no terminal. Um arquivo chamado main sera criado.
	
	Ou digite no terminal:
	
	gcc cliente.c site.c trab.c site.h trab.h -o main -Wall -std=c89



Para executar:

	Digite no terminal: ./main
**********
IMPORTANTE	 
**********
O arquivo que contem os sites a serem inseridos na lista, deve ter o nome de:
1.in


Ao executar o programa ira aparecer um menu com 6 opções, sendo elas:
	
	1	-	Inserir um site
	2	-	Remover um site
	3	-	Inserir palavra chave
	4	-	Atualizar relevancia
	5	-	Sair
	6	-	Imprimir lista

A primeira opção permite que dado o usuário, atráves de um codigo númerico (de 0 a 1000),
possa inserir um site na lista, porém, se o dado codigo já existir na lista, uma mensagem 
de erro é retornada.

A segunda opção também recebe um código fornecido pelo o usuário para que o site correspondente
a esse código seja removido, caso o codigo não seja encontrado na lista uma mensagem de erro
é retornada.

A terceira permite o usuário inserir palavras chaves no site, com um limite de 10 por site.

A quarta opção permite que por um código inserido pelo usuário, um site tenha a sua relevancia
atualizada (numero de 0 a 1000), contando que o código exista na lista, caso não exista será 
retornada uma mensagem de erro.

A quinta opção encerra o programa.

A sexta opção imprime na tela todos os elementos (sites) da lista.

-------------------------------------------------------------------------------------------------

Fizemos a escolha de utilizar dois TAD's, um para fazer todas as operações envolvendo o site
(sendo site toda a estrutura composta por: codigo, nome, link, relevância, palavras chave), e um
TAD para uma estrutura tipo Lista, que armazena todos os sites. A escolha de usar uma Lista, foi
feita pois a mesma é a estrutura de dado que mais facilitaria a inserção/removoção de elementos
independente da sua localização na mesma (inicio, meio, fim, etc).
A lista utilizada tem as seguintes características: linear, ordenada, dinâmica, simplesmente
encadeada e com nó cabeça.
Linear e ordenada, pois facilita a busca de sites. Dinâmica, pois assim o usuário não é limitado
a inserir uma quantidade fixa de sites, mas sim variada. Simplesmente linear, por que a
implementação é mais simples, utiliza menos memória e não foi encontrada nenhuma vantagem para
utilizar de uma duplamente encadeada. O nó cabeça foi simplesmente uma preferência do grupo, já
que facilita a remoção do primeiro item da lista.