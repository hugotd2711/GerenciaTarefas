#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAREFAS 100
#define MAX_DESCRICAO 256

typedef struct {
    int id;
    char descricao[MAX_DESCRICAO];
} Tarefa;

Tarefa listaDeTarefas[MAX_TAREFAS];
int contadorDeTarefas = 0;

void adicionarTarefa(const char* descricao) {
    if (contadorDeTarefas < MAX_TAREFAS) {
        listaDeTarefas[contadorDeTarefas].id = contadorDeTarefas + 1;
        strncpy(listaDeTarefas[contadorDeTarefas].descricao, descricao, MAX_DESCRICAO - 1);
        listaDeTarefas[contadorDeTarefas].descricao[MAX_DESCRICAO - 1] = '\0';  // Garantir terminação nula
        contadorDeTarefas++;
        printf("Tarefa adicionada com sucesso!\n");
    } else {
        printf("Lista de tarefas cheia!\n");
    }
}

void visualizarTarefas() {
    printf("Lista de Tarefas:\n");
    for (int i = 0; i < contadorDeTarefas; i++) {
        printf("ID: %d, Descrição: %s\n", listaDeTarefas[i].id, listaDeTarefas[i].descricao);
    }
}

void removerTarefa(int id) {
    int found = 0;
    for (int i = 0; i < contadorDeTarefas; i++) {
        if (listaDeTarefas[i].id == id) {
            found = 1;
            for (int j = i; j < contadorDeTarefas - 1; j++) {
                listaDeTarefas[j] = listaDeTarefas[j + 1];
            }
            contadorDeTarefas--;
            printf("Tarefa removida com sucesso!\n");
            break;
        }
    }
    if (!found) {
        printf("Tarefa com ID %d não encontrada.\n", id);
    }
}

void menu() {
    printf("\n=== Gerenciador de Tarefas ===\n");
    printf("1. Adicionar tarefa\n");
    printf("2. Visualizar tarefas\n");
    printf("3. Remover tarefa\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    int opcao;
    char descricao[MAX_DESCRICAO];
    int id;

    while (1) {
        menu();
        scanf("%d", &opcao);
        getchar();  // Limpar o caractere de nova linha do buffer

        switch (opcao) {
            case 1:
                printf("Digite a descrição da tarefa: ");
                fgets(descricao, MAX_DESCRICAO, stdin);
                descricao[strcspn(descricao, "\n")] = 0;  // Remover nova linha
                adicionarTarefa(descricao);
                break;
            case 2:
                visualizarTarefas();
                break;
            case 3:
                printf("Digite o ID da tarefa para remover: ");
                scanf("%d", &id);
                removerTarefa(id);
                break;
            case 4:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    return 0;
}
