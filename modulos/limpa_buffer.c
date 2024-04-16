#include "../headers/limpa_buffer.h"

void limparbuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}