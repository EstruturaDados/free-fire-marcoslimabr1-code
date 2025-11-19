#include <stdio.h>
#include <string.h>

// Define a estrutura do Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

int main() {
    Item mochila[10];
    int totalItens = 0;
    int opcao;
    
    // Variaveis auxiliares
    int i, j, encontrado;
    char nomeBusca[30];

    do {
        // Menu principal
        printf("\nEscolha uma opcao: \n");
        printf("1. Adicionar Novo Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        // Limpa o buffer do teclado
        while(getchar() != '\n'); 

        switch (opcao) {
            case 1: // --- ADICIONAR ---
                if (totalItens < 10) {
                    printf("\n--- Adicionar Novo Item ---\n");
                    
                    printf("Nome do item: ");
                    fgets(mochila[totalItens].nome, 30, stdin);
                    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = 0;

                    printf("Tipo do item (arma, municao, cura, etc.): ");
                    fgets(mochila[totalItens].tipo, 20, stdin);
                    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = 0;

                    printf("Quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);

                    totalItens++;
                    printf("\nItem '%s' adicionado com sucesso!\n", mochila[totalItens-1].nome);

                    // --- LISTAGEM AUTOMÁTICA (IGUAL DA PROFESSORA) ---
                    printf("\n--- ITENS NA MOCHILA (%d/10) ---\n", totalItens);
                    printf("--------------------------------------------------\n");
                    printf("%-15s | %-15s | %-10s\n", "NOME", "TIPO", "QUANTIDADE");
                    printf("--------------------------------------------------\n");
                    for (i = 0; i < totalItens; i++) {
                        printf("%-15s | %-15s | %-10d\n", 
                               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                    }
                    printf("--------------------------------------------------\n");

                } else {
                    printf("\n[ERRO] A mochila esta cheia!\n");
                }
                break;

            case 2: // --- REMOVER ---
                if (totalItens > 0) {
                    printf("\n--- Remover Item ---\n");
                    printf("Nome do item para remover: ");
                    fgets(nomeBusca, 30, stdin);
                    nomeBusca[strcspn(nomeBusca, "\n")] = 0;

                    encontrado = 0;
                    for (i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
                            encontrado = 1;
                            // Remove e reorganiza
                            for (j = i; j < totalItens - 1; j++) {
                                mochila[j] = mochila[j+1];
                            }
                            totalItens--;
                            printf("\nItem '%s' removido com sucesso!\n", nomeBusca);

                            // --- LISTAGEM AUTOMÁTICA APÓS REMOVER ---
                            printf("\n--- ITENS NA MOCHILA (%d/10) ---\n", totalItens);
                            printf("--------------------------------------------------\n");
                            printf("%-15s | %-15s | %-10s\n", "NOME", "TIPO", "QUANTIDADE");
                            printf("--------------------------------------------------\n");
                            for (j = 0; j < totalItens; j++) {
                                printf("%-15s | %-15s | %-10d\n", 
                                       mochila[j].nome, mochila[j].tipo, mochila[j].quantidade);
                            }
                            printf("--------------------------------------------------\n");
                            break; 
                        }
                    }
                    if (!encontrado) printf("\nItem nao encontrado.\n");
                } else {
                    printf("\nA mochila ja esta vazia.\n");
                }
                break;

            case 3: // --- LISTAR (Manual) ---
                printf("\n--- ITENS NA MOCHILA (%d/10) ---\n", totalItens);
                printf("--------------------------------------------------\n");
                printf("%-15s | %-15s | %-10s\n", "NOME", "TIPO", "QUANTIDADE");
                printf("--------------------------------------------------\n");
                for (i = 0; i < totalItens; i++) {
                    printf("%-15s | %-15s | %-10d\n", 
                           mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                }
                printf("--------------------------------------------------\n");
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}