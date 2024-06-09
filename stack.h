#ifndef STACK_H
#define STACK_H

/*
 * Primero se necesita definir una estructura que corresponde al nodo en la lista enlazada
 * Hay que almacenar los datos en la variable data
 * Y luego hacer un puntero hacia el siguiente nodo en la lista
 */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/*
 * La siguiente estructura es para el propio stack
 * Se hace un puntero hacia el nodo en el top del stack
 */
typedef struct Stack {
    Node* top;
} Stack;

/*
 * Se hace una funcion para que se cree una nueva pila
 * La siguiente funcion se usa para adicionar un elemento al top del stack
 * La tercera funcion elimina y devuelve el elemento al top del stack
 * La cuarta funcion hace que se devuelva el elemento al top del stack, pero sin que se elimine
 * La penultima funcion es para hacer una verificacion de si la lista esta vacia
 * La ultima sirve para liberar toda la memoria que tiene que ver con el stack 
 */
Stack* createStack();
void push(Stack* stack, int data);
int pop(Stack* stack);
int peek(Stack* stack);
int isEmpty(Stack* stack);
void freeStack(Stack* stack);

#endif
