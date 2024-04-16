#include "../headers/main_game.h"

#ifdef _WIN32 // descobrir se o processador é windows para definir o comando para limpar a tela

    #define CLEAR_SCREEN "cls"
#else

    #define CLEAR_SCREEN "clear"
#endif

void game(char* resposta, char* word, char* tip){
    
    char letras_usadas[26] ={0};
    char vidas = 5;
    char turnos = 0;
    char chute;
    bool nova_letra = true;
    int i;
    bool vitoria = false;
    bool acerto = false;
    int letras_restantes = strlen(word);

    while(vidas && !vitoria){//main loop
        turnos++;
        INICIO:// voltar ao inicio caso opção de entrada seja invalida ou usuario usou letra repitida
        acerto = false;
        nova_letra = true;

        system(CLEAR_SCREEN);
        i=0;
        printf("vidas : %d\n", vidas);
        printf("turno : %d\n", turnos);
        printf("letras usadas: %s\n", letras_usadas);
        printf("palavra: %s\n", word);
        printf("dica: %s\n", tip);



        do{// verificar se a letra escolhida existe
            puts("digite uma letra");
            chute = getchar();
            limparbuffer();//limpar buffer para remover \n do getchar()
            if(chute< 'a' || chute > 'z'){//verificando se a entrada é uma letra
                puts("opção invalida");
                goto INICIO;//voltar ao inicio se a opção de entrada for invalida
            }
            if(chute == letras_usadas[i]){
                puts("letra ja escolhida");
                system("PAUSE");
                goto INICIO; //voltar ao inicio caso letra ja foi escolhida
                nova_letra = false;
                i=0;
            } 
            i++;
        }while(!letras_usadas[i]  && !nova_letra);
        if(nova_letra){//inserindo a letra usada ao vetor de letras usadas
            letras_usadas[i-1] = chute;
            //letras_usadas[i] = '\0'; vetor iniciado como 0, então todas as posições são 0, não necessitando essa atualização
        }
        
        i = 0;

    for(i=0; word[i];i++){ //verificando se a palavra contem a letra e alterando o vetor de resposta
        if(resposta[i] == chute){
            word[i] = chute;
            acerto = true;
            letras_restantes--;
        }
    }
    if(!acerto){
        vidas--;
        printf("que pena, a palavra não contem a letra %c\n", chute);
        system("PAUSE");
    }else if(!letras_restantes){
        vitoria = true;
    }

  }
  if(!vitoria){
    puts("que pena você perdeu...");
    printf("a palavra era: %s\n", resposta);
  }else
    puts("parabens, você ganhou!!!");
}

