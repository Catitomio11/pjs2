    #include "tarefas.h"
    #include <string.h>

    void trim_newline(char* str) {
        size_t len = strlen(str);
        if (len > 0 && str[len-1] == '\n') {
            str[len-1] = '\0';
        }
    }

    void adicionar_tarefa(Tarefa tarefas[], int* num_tarefas) {
        if (*num_tarefas >= MAX_TAREFAS) {
            printf("Lista de tarefas cheia.\n");
            return;
        }

        Tarefa nova_tarefa;
        printf("Digite a categoria: ");
        fgets(nova_tarefa.categoria, MAX_CATEGORIA, stdin);
        trim_newline(nova_tarefa.categoria);

        printf("Digite a descrição: ");
        fgets(nova_tarefa.descricao, MAX_DESCRICAO, stdin);
        trim_newline(nova_tarefa.descricao);

        do {
            printf("Digite a prioridade (1-10): ");
            scanf("%d", &nova_tarefa.prioridade);
        } while (nova_tarefa.prioridade < 1 || nova_tarefa.prioridade > 10);

        tarefas[*num_tarefas] = nova_tarefa;
        (*num_tarefas)++;
        getchar();
    }

    void listar_tarefas(Tarefa tarefas[], int num_tarefas) {    
        char categoria[MAX_CATEGORIA];
        printf("Digite a categoria para listar (deixe vazio para listar todas): ");
        fgets(categoria, MAX_CATEGORIA, stdin);
        trim_newline(categoria);

        int encontrada = 0;
        for (int i = 0; i < num_tarefas; i++) {
            if (strlen(categoria) == 0 || strcmp(tarefas[i].categoria, categoria) == 0) {
                printf("Categoria: %s, Descrição: %s, Prioridade: %d\n", tarefas[i].categoria, tarefas[i].descricao, tarefas[i].prioridade);
                encontrada = 1;
            }
        }

        if (!encontrada) {
            printf("Nenhuma tarefa encontrada.\n");
        }
    }

    void exportar_tarefas(Tarefa tarefas[], int num_tarefas) {
        char categoria[MAX_CATEGORIA];
        char nome_arquivo[100];

        printf("Digite a categoria para exportar (deixe vazio para exportar todas): ");
        fgets(categoria, MAX_CATEGORIA, stdin);
        trim_newline(categoria);

        printf("Digite o nome do arquivo para exportar: ");
        fgets(nome_arquivo, 100, stdin);
        trim_newline(nome_arquivo);

        FILE* arquivo = fopen(nome_arquivo, "w");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        for (int i = 0; i < num_tarefas; i++) {
            if (strlen(categoria) == 0 || strcmp(tarefas[i].categoria, categoria) == 0) {
                fprintf(arquivo, "Categoria: %s, Descrição: %s, Prioridade: %d\n", tarefas[i].categoria, tarefas[i].descricao, tarefas[i].prioridade);
            }
        }

        fclose(arquivo);
        printf("Tarefas exportadas com sucesso.\n");
    }

    void carregar_tarefas(Tarefa tarefas[], int* num_tarefas) {
        char nome_arquivo[100];

        printf("Digite o nome do arquivo para carregar: ");
        fgets(nome_arquivo, 100, stdin);
        trim_newline(nome_arquivo);

        FILE* arquivo = fopen(nome_arquivo, "rb");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        fread(num_tarefas, sizeof(int), 1, arquivo);
        fread(tarefas, sizeof(Tarefa), *num_tarefas, arquivo);
        fclose(arquivo);

        printf("Tarefas carregadas com sucesso.\n");
    }

    void salvar_tarefas(Tarefa tarefas[], int num_tarefas) {
        char nome_arquivo[100];

        printf("Digite o nome do arquivo para salvar: ");
        fgets(nome_arquivo, 100, stdin);
        trim_newline(nome_arquivo);

        FILE* arquivo = fopen(nome_arquivo, "wb");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        fwrite(&num_tarefas, sizeof(int), 1, arquivo);
        fwrite(tarefas, sizeof(Tarefa), num_tarefas, arquivo);
        fclose(arquivo);

        printf("Tarefas salvas com sucesso.\n");
    }

    void deletar_tarefa(Tarefa tarefas[], int* num_tarefas) {
        char descricao[MAX_DESCRICAO];
        printf("Digite a descrição da tarefa a ser deletada: ");
        fgets(descricao, MAX_DESCRICAO, stdin);
        trim_newline(descricao);

        int encontrada = 0;
        for (int i = 0; i < *num_tarefas; i++) {
            if (strcmp(tarefas[i].descricao, descricao) == 0) {
                for (int j = i; j < *num_tarefas - 1; j++) {
                    tarefas[j] = tarefas[j + 1];
                }
                (*num_tarefas)--;
                encontrada = 1;
                printf("Tarefa deletada com sucesso.\n");
                break;
            }
        }

        if (!encontrada) {
          }
        if (!encontrada) {
            printf("Tarefa não encontrada.\n");
        }
    }
