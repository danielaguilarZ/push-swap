#include <stdio.h>
#include <stdlib.h> // Para usar atoi()

// Estructura del nodo para la lista enlazada
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL; // Puntero al tope del stack

// Función para verificar si el stack está vacío
int isEmpty() {
    return top == NULL;
}

// Función para verificar si un número ya está en el stack
int isDuplicate(int value) {
    Node *current = top;
    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Función para agregar un elemento al stack
void pushAtFirst(int value) {
    if (isDuplicate(value)) {
        printf("El número %d ya está en el stack. No se permiten duplicados.\n", value);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo elemento.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        int i = argc - 1;
        while (i > 0) {
            int num = atoi(argv[i]); // Convertir el argumento a número
            pushAtFirst(num); // Agregar el número al stack
            i--;
        }
    }

    printf("Stack actual: ");
    Node *current = top;
    while (current != NULL) {
        printf("%d ", current->data); // Imprimir elementos del stack
        current = current->next;
    }
    printf("\n");

    return 0;
}