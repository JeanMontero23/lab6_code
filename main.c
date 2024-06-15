//Se incluye stack.h ya que contiene las declaraciones de las estructuras y funciones para manejar el stack
#include <stdio.h>
#include "stack.h"

/*
 * Se define la funcion principal
 * Se crea una nueva pila al utilizar la funcion createStack()
 */
int main() {
    Stack* stack = createStack();

    /* 
     * Se imprime un mensaje de indicacion y se agrega el valor 10 al stack
     * Luego se devuelve el elemento del top al stack, pero sin sacarlo
    */
    printf("Poniendo 10 en el stack\n");
    push(stack, 10);
    printf("El elemento en top es %d\n", peek(stack));

    /*
     * Se agrega el valor 20 a la pila
     * Luego se devuelve el elemento del top de la pila (ahora es 20) y se imprime
     */
    printf("Poniendo 20 en el stack\n");
    push(stack, 20);
    printf("El elemento en top es %d\n", peek(stack));
    
    /*
     * Primero se saca y devuelve el elemento que esta en el top (ahora es 20)
     * Seguidamente se devuelve el nuevo elemento del top (10)
     */	
    printf("Sacando %d del stack\n", pop(stack));
    printf("El elemento en top es %d\n", peek(stack));

    /*
     * Se agrega el valor de 30 al stack
     * Se vuelve el nuevo el elemento top (30)
     */
    printf("Poniendo 30 en el stack\n");
    push(stack, 30);
    printf("El elemento en top es %d\n", peek(stack));
    
    /*
     * Se saca y devuelve el elemento superior del stack (30)
     * Luego se saca y devuelve el siguiente elemento del top del stack (10)
     */
    printf("Sacando %d del stack\n", pop(stack));
    printf("Sacando %d del stack\n", pop(stack));
    
    /*
     * Se verifica si la lista esta vacia, en caso de estar vacia se imprime un mensaje indicativo
     */
    if (isEmpty(stack)) {
        printf("El stack esta vacio\n");
    }

    /*
     * Se libera la memoria del stack para evitar memory leaks
     * Se sale del programa
     */
    freeStack(stack);
    return 0;
}
