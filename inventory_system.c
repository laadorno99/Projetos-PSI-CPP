#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS 3

typedef struct {
    char nome[50];
    int idade;
    float salario;
} Pessoa;

// Função para procurar por nome
void procurarPorNome(Pessoa p[], int tam, char nomeBusca[]) {
    int encontrado = 0;
    for(int i = 0; i < tam; i++) {
        if(strcmp(p[i].nome, nomeBusca) == 0) {
            printf("\nEncontrado: %s, %d anos, Salário: %.2f€\n", p[i].nome, p[i].idade, p[i].salario);
            encontrado = 1;
        }
    }
    if(!encontrado) printf("\nPessoa não encontrada.\n");
}

// Função para procurar por faixa etária (18 a 30 anos)
void procurarFaixaEtaria(Pessoa p[], int tam) {
    printf("\n--- Pessoas entre 18 e 30 anos ---\n");
    for(int i = 0; i < tam; i++) {
        if(p[i].idade >= 18 && p[i].idade <= 30) {
            printf("Nome: %s | Idade: %d\n", p[i].nome, p[i].idade);
        }
    }
}

int main() {
    Pessoa grupo[MAX_PESSOAS];
    char busca[50];

    // Preencher o Vetor
    for(int i = 0; i < MAX_PESSOAS; i++) {
        printf("Introduza o nome da pessoa %d: ", i + 1);
        scanf("%s", grupo[i].nome);
        printf("Introduza a idade: ");
        scanf("%d", &grupo[i].idade);
        printf("Introduza o salário: ");
        scanf("%f", &grupo[i].salario);
    }

    // Imprimir o Vetor
    printf("\n--- Lista de Pessoas ---\n");
    for(int i = 0; i < MAX_PESSOAS; i++) {
        printf("%s - %d anos - %.2f€\n", grupo[i].nome, grupo[i].idade, grupo[i].salario);
    }

    // Localizar por nome
    printf("\nDigite um nome para procurar: ");
    scanf("%s", busca);
    procurarPorNome(grupo, MAX_PESSOAS, busca);

    // Procurar faixa de valores
    procurarFaixaEtaria(grupo, MAX_PESSOAS);

    return 0;
}