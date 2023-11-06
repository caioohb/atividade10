#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

#define TABLE_SIZE 100

typedef struct Node {
    char* chave;
    char* dado;
    struct Node* proximo;
} Node;

Node* tabela[TABLE_SIZE];

int hash(char* chave) {
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % TABLE_SIZE;
}

void hash_table_init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela[i] = NULL;
    }
}

char* hash_table_get(char* chave) {
    int index = hash(chave);
    Node* atual = tabela[index];

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual->dado;
        }
        atual = atual->proximo;
    }

    return NULL;
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);
    Node* novo_node = (Node*)malloc(sizeof(Node));
    novo_node->chave = strdup(chave);
    novo_node->dado = strdup(dado);
    novo_node->proximo = tabela[index];
    tabela[index] = novo_node;
}

int hash_table_contains(char* chave) {
    int index = hash(chave);
    Node* atual = tabela[index];

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return 1;
        }
        atual = atual->proximo;
    }

    return 0;
}

void hash_table_remove(char* chave) {
    int index = hash(chave);
    Node* atual = tabela[index];
    Node* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior == NULL) {
                tabela[index] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual->chave);
            free(atual->dado);
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void hash_table_destroy() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* atual = tabela[i];
        while (atual != NULL) {
            Node* proximo = atual->proximo;
            free(atual->chave);
            free(atual->dado);
            free(atual);
            atual = proximo;
        }
        tabela[i] = NULL;
    }
}
