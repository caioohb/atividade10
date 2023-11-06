#include <stdio.h>
#include "tabela_hash.h"

int main() {
    hash_table_init();  

    hash_table_put("chave1", "valor1");
    hash_table_put("chave2", "valor2");
    hash_table_put("chave3", "valor3");

    printf("A chave 'chave1' %s na tabela.\n", hash_table_contains("chave1") ? "esta" : "nao esta");
    printf("A chave 'chave4' %s na tabela.\n", hash_table_contains("chave4") ? "esta" : "nao esta");

    char* valor2 = hash_table_get("chave2");
    if (valor2 != NULL) {
        printf("Valor 'chave2': %s\n", valor2);
    }

    hash_table_remove("chave3");

    hash_table_destroy();

    return 0;
}
