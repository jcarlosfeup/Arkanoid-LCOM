#include <stdio.h>
#include "Score.h"


//l� um ficheiro txt
void HighScore(FILE *file)
{
	 int caracter = 0;
	 file = fopen("Scores.txt", "r");
	 int c = 0;
	 //enquanto n�o chega ao final do ficheiro
	 do{
	 c = fgetc(file);
	 if(c != ' ')
	 putchar(caracter);
	
	 } while (c != EOF);

/* Close file */
	  fclose(file);
}



//guarda no ficheiro de txt   
void update_hsc(FILE *file,char nome[],unsigned int score)
{
	if(file != NULL){
	        file = fopen("Scores.txt", "w");
			fprintf(file, "Nome: %s -> Pontuacao: %d\n", nome, score);
	        fclose(file);
	    }
	    else
		printf("� necess�rio especificar um nome de ficheiro.\n");
	   
	}


