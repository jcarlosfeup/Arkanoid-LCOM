#include "Menu.h"
#include <stdlib.h>
#include <conio.h>
//falta por opcao de ver as pontuações








void guide();
void game();
void credits();
void menu();

void guide(){
	system("cls");
	printf("	Manual do Jogo do ARKANOID \n\n");
	printf(" Este e o jogo do Arkanoid que consiste em fazer movimentar \n");
	printf(" uma raquete, com o rato ou o teclado; escolhido previamente pelo \n");
	printf(" jogador. A raquete vai tomar o lugar do jogador que deve fazer com que\n");
	printf(" destrua um conjunto de blocos, dispostos dependendo de cada nivel.\n");
	printf(" O que vai destruir os blocos sera um bola que o jogador devera evitar deixar cair \n");
	printf(" para tal tera entao o raquete. \n");
	printf(" Press any key..... \n");
	getch();
}

void credits(){
		printf("+-----------------------------------------------------------+\n");
        printf("|Programa Desenvolvido Por:                                 |\n");
        printf("|                           Damien Rosa e Carlos Portela    |\n");
        printf("|\"Todo homem procura o sentido de sua existencia, mas nem  |\n");
        printf("|todos encontram o caminho.\" Jose Mario                    |\n");
        printf("|                           ei09093@fe.up.pt e		        |\n");
		printf("|                           ei09012@fe.up.pt  		        |\n");
        printf("+-----------------------------------------------------------+\n\n\n");
}

void guide();
void credits();
void menu();


void menu(){
	int opcao;
	 system("cls");
	 
	 do {
		printf("Escolha uma das seguintes opcoes.\n");
		printf("+-----------------------------------------------------------------------------+\n");
		printf("|                            Bem-Vindo ao ARKANOID                            |\n");
		printf("|1) Ler o Manual de Utilizador.                                               |\n");
		printf("|2) >>>>>>>>>>>>>>>>JOGAR<<<<<<<<<<<<<<<<<<<                                  |\n");
		printf("|3) Mostrar creditos e Encerrar o programa.                                   |\n");
		printf("|											 Por: Damien Rosa (090509093)     |\n");
		printf("|											 	e Carlos Portela (090509012)  |\n");
		printf("+-----------------------------------------------------------------------------+\n");
		scanf("Opcao: %d " ,&opcao);
	 }while(opcao < 1 || opcao > 3);
	 
	 switch(opcao){
	 case 1:{
		guide();
		menu();
		break; }
		
	case 2:{
		menu();
		break;	}
	case 3:{
		credits();
		break; }
	 }
}


