#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#include <locale.h>
#include "headers/criar_palavra.h"
#include "headers/main_game.h"

#define max_size 50

int main(void){

    char palavra[max_size];
    char dica [max_size];
    char palavra_secreta[max_size];
    int i = 0;

    setlocale(LC_ALL, "en_US.UTF-8"); // garantindo que os caracteres especiais serão imprimidos
    //criação das palavras a serem usadas
    criarpalavra(palavra, "palavra",max_size);
    criarpalavra(dica, "dica",max_size);
    //strcpy(palavra, "teste numero 1");
    //strcpy(dica, "teste2");

    //criar o array que será mostrado ao usuário

    while(palavra[i]){
        if (palavra[i] == ' ')
            palavra_secreta[i] = ' ';
        else 
            palavra_secreta[i] = '_';
        i++;
    }

    
    game(palavra,palavra_secreta,dica);

    return 0;
}

