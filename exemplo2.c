#include <stdio.h>
#include <string.h>

// Definição da estrutura Produto
struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

// Função para adicionar um produto ao estoque
void adicionarProduto(struct Produto estoque[], int *numProdutos) {
    printf("Informe o nome do produto: ");
    scanf("%s", estoque[*numProdutos].nome);
    printf("Informe o preco do produto: ");
    scanf("%f", &estoque[*numProdutos].preco);
    printf("Informe a quantidade em estoque: ");
    scanf("%d", &estoque[*numProdutos].quantidade);
    (*numProdutos)++;
}

// Função para atualizar o preço de um produto
void atualizarPreco(struct Produto estoque[], int numProdutos) {
    char nome[50];
    printf("Informe o nome do produto para atualizar o preco: ");
    scanf("%s", nome);

    // Procura o produto pelo nome e atualiza o preço se encontrado
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(estoque[i].nome, nome) == 0) {
            printf("Informe o novo preco: ");
            scanf("%f", &estoque[i].preco);
            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

// Função para exibir informações sobre todos os produtos no estoque
void exibirEstoque(struct Produto estoque[], int numProdutos) {
    printf("Produtos em estoque:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Nome: %s, Preco: %.2f, Quantidade: %d\n", estoque[i].nome, estoque[i].preco, estoque[i].quantidade);
    }
}

int main() {
    struct Produto estoque[50]; // Vetor de produtos
    int numProdutos = 0; // Número de produtos atualmente no estoque
    int opcao;

    do {
        printf("\n1. Adicionar produto\n");
        printf("2. Atualizar preco do produto\n");
        printf("3. Exibir estoque\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(estoque, &numProdutos);
                break;
            case 2:
                atualizarPreco(estoque, numProdutos);
                break;
            case 3:
                exibirEstoque(estoque, numProdutos);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}