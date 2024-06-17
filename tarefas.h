#ifndef TAREFAS_H
#define TAREFAS_H

#include <stdio.h>

#define MAX_CATEGORIA 50
#define MAX_DESCRICAO 255
#define MAX_TAREFAS 100

typedef struct {
    char categoria[MAX_CATEGORIA];
    char descricao[MAX_DESCRICAO];
    int prioridade;
} Tarefa;

void trim_newline(char* str);
void adicionar_tarefa(Tarefa tarefas[], int* num_tarefas);
void listar_tarefas(Tarefa tarefas[], int num_tarefas);
void exportar_tarefas(Tarefa tarefas[], int num_tarefas);
void carregar_tarefas(Tarefa tarefas[], int* num_tarefas);
void salvar_tarefas(Tarefa tarefas[], int num_tarefas);
void deletar_tarefa(Tarefa tarefas[], int* num_tarefas);

#endif
