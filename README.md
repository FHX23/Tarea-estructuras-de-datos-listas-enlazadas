# Tarea-estructuras-de-datos-listas-enlazadas
Tarea de la asignatura estructura de datos 

Este código en C incluye las siguientes funciones:

## Nodo *crearLista(Nodo *cabeza, int n)

Esta función se utiliza para crear una nueva lista y agregar un número específico de nodos a ella. Si se proporciona una cabeza no nula, se agregarán los nodos adicionales a la lista existente. La función solicita al usuario que ingrese un numerador y un denominador para cada nodo en la lista.

## Nodo *insertarNodo(Nodo *cabeza)

Esta función se utiliza para agregar un solo nodo al final de la lista. La función solicita al usuario que ingrese un numerador y un denominador para el nuevo nodo.

## Nodo *insertarNodoEnPosicion(Nodo *cabeza, int posicion)

Esta función se utiliza para agregar un solo nodo en una posición específica en la lista. La función solicita al usuario que ingrese un numerador y un denominador para el nuevo nodo.

## void imprimirLista(Nodo *cabeza)

Esta función se utiliza para mostrar todos los nodos en la lista. Imprime el valor de numerador y denominador de cada nodo en la lista.

## Nodo *eliminarNodo(Nodo *cabeza, int valor)

Esta función se utiliza para eliminar un nodo específico de la lista. Elimina el primer nodo que tenga el valor de numerador especificado.

## int sumaLista(Nodo *cabeza)

Esta función se utiliza para sumar todos los valores de numerador en la lista y devuelve la suma.

## int productoLista(Nodo *cabeza)

Esta función se utiliza para multiplicar todos los valores de numerador y denominador en la lista y devuelve el resultado como una fracción.

## int buscar(Nodo *cabeza, int x)

Esta función se utiliza para buscar un número específico en la lista y contar cuántas veces aparece. Solicita al usuario que ingrese un numerador y un denominador para el número a buscar.

## void mayorValor(Nodo *cabeza, int *valor, int *posicion)

Esta función se utiliza para encontrar el valor máximo en la lista y su posición en la lista. La función devuelve el valor máximo y la posición mediante los parámetros de la función.

## void menorValor(Nodo *cabeza, int *valor, int *repeticiones)

Esta función se utiliza para encontrar el valor mínimo en la lista y cuántas veces aparece. La función devuelve el valor mínimo y el número de repeticiones mediante los parámetros de la función.

## float divisionMayorMenor(Nodo *cabeza)

Esta función se utiliza para calcular la división del mayor valor entre el menor valor en la lista y devuelve el resultado como un flotante.

## Nodo *ordenarListaAscendente(Nodo *lista)

Esta función se utiliza para ordenar la lista en orden ascendente.

## Nodo *ordenarListaDescendente(Nodo *lista)

Esta función se utiliza para ordenar la lista en orden descendente.

## void menu()

Esta función se utiliza para mostrar un menú de opciones para el usuario.

Además, se pueden observar varias funciones auxiliares que se utilizan dentro de las funciones principales, como la función malloc para asignar memoria dinámica a los nodos de la lista, la función fflush para limpiar el búfer de entrada de la consola, y varias instrucciones de control de flujo como if, while y do-while.

En general, este código proporciona una implementación básica de una lista enlazada simple y varias funciones útiles para manipular y analizar los nodos en la lista. Es importante resaltar que esta implementación puede mejorarse y optimizarse en función de las necesidades específicas de cada proyecto, pero este código puede servir como un punto de partida útil para aquellos que buscan aprender sobre listas enlazadas en C.
