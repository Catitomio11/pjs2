#include "tarefas.h"

void exibir_menu() {
    printf("1. Adicionar tarefa\n");
    printf("2. Listar tarefas\n");
    printf("3. Exportar tarefas\n");
    printf("4. Carregar tarefas\n");
    printf("5. Salvar tarefas\n");
    printf("6. Deletar tarefa\n");
    printf("0. Sair\n");
}

int main() {
    Tarefa tarefas[MAX_TAREFAS];
    int num_tarefas = 0;
    int opcao;

    do {
        exibir_menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                adicionar_tarefa(tarefas, &num_tarefas);
                break;
            case 2:
                listar_tarefas(tarefas, num_tarefas);
                break;
            case 3:
                exportar_tarefas(tarefas, num_tarefas);
                break;
            case 4:
                carregar_tarefas(tarefas, &num_tarefas);
                break;
            case 5:
                salvar_tarefas(tarefas, num_tarefas);
                break;
            case 6:
                deletar_tarefa(tarefas, &num_tarefas);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
