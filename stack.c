#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
 * Se procede a crear e inicializar un nuevo stack
 * Hay que asignar memoria para el stack
 * Se necesita inicializar top como NULL
 * Finalmente se retorna el stack creado
 */
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

/*
 * Se agrega un elemento al top del stack
 * Se necesita asignar memoria para el nuevo nodo y establecer los datos del mismo
 * Luego se procede a establer el siguiente puntero al nodo que se encuentra en el top
 * Seguidamente se necesita actualizar el top al nodo que es nuevo
 */
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

/*
 * Se necesita eliminar y devolver el elemento al top del stack
 * Primero se verifica si el stack esta vacio
 * Se cubre la situacion de desbordamiento de la pila enviando un mensaje de error al usuario
 * Se sale del programa
 */
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Hay desbordamiento del stack\n");
        exit(EXIT_FAILURE);
    }
/*
 * Aqui se procede a almacenar de manera temporal el nodo
 * Y luego se obtienen los datos del nodo que esta en top
 * Se necesita hacer una actualizacion del top al siguiente nodo
 * Se libera la memoria del nodo que se elimino
 * Se devuelven los datos del nodo borrado
 */
    Node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

/*
 * Lo siguiente va devolver el elemento del top del stack sin que se elimine
 * Se verifica si el stack esta vacio
 * Se imprime un mensaje en caso de que el stack este vacio
 * Se sale del programa y se devuelven los datos del nodo superior
 */
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "El stack esta vacio\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

/*
 * Se revisa si el stack esta vacio
 * Se retorna un 1 el top es equivalente a NULL, sino, se retorna un 0
 */
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

/*
 * Finalmente se libera la memoria que se usa con el stack
 * Se hace un bucle que continua hasta que la pila este vacia
 * Se hace la eliminacion del elemento en top y se libera la memoria del stack
 */
void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}
