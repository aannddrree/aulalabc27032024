#include <stdio.h>

// Função para calcular a média dos elementos de um vetor
float calcularMedia(int vetor[], int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return soma / tamanho;
}

int main() {
    int numeros[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    // Chama a função para calcular a média e imprime o resultado
    float media = calcularMedia(numeros, tamanho);
    printf("A media dos elementos do vetor e: %.2f\n", media);

    return 0;
}