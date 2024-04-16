#include "../headers/criar_palavra.h"



void criarpalavra(char* texto, char* tipo, int tamanho_maximo){

    int i = 0;
    char c;
    bool tamanho = true; //tamanho verifica se o tamanho da frase é menor que o definido por tamanho_maximo

    do{
        printf("digite a %s\n", tipo);
        while((c = getchar()) != '\n' && tamanho_maximo){
            if(i < tamanho_maximo){
                texto[i] = c;
            i++;
            }else{
                tamanho = false;
                puts("frase muito comprida, insira uma frase menor");
                limparbuffer();
                i=0;
                break;
            }
        }
    }while(!tamanho);
    texto[i]='\0';
}
