#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int num;
    int num2;
    struct Nodo *link;
} Nodo;

Nodo *crearLista(Nodo *cabeza, int n);
Nodo *insertarNodo(Nodo *cabeza);
Nodo *insertarNodoEnPosicion(Nodo *cabeza, int posicion);
void imprimirLista(Nodo *cabeza);
Nodo *eliminar(Nodo *cabeza, int X);
int sumaLista(Nodo *cabeza);
int productoLista(Nodo *cabeza);
int buscar(Nodo *cabeza, int X);
void mayorValor(Nodo *cabeza, int *valor, int *posicion);
void menorValor(Nodo *cabeza, int *valor, int *repeticiones);
float divisionMayorMenor(Nodo *cabeza);
Nodo *ordenarListaAscendente(Nodo *lista);
Nodo *ordenarListaDescendente(Nodo *lista);
void menu();
int mcd(int a, int b);
int mcm(int a, int b);
void funcionmayor_menor_sumatoria(Nodo *cabeza, int opcion);

// Función para encontrar el máximo común divisor (MCD) de dos números
int mcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return mcd(b, a % b);
    }
}

// Función para encontrar el mínimo común múltiplo (MCM) de dos números
int mcm(int a, int b)
{
    return (a * b) / mcd(a, b);
}

Nodo *crearLista(Nodo *cabeza, int n)
{
    Nodo *nuevo = NULL;
    int i;
    if (cabeza == NULL)
    {
        Nodo *temp = NULL;
        for (i = 0; i < n; i++)
        {

            nuevo = (Nodo *)malloc(sizeof(Nodo));
            printf("Ingrese el valor del numerador: \n");
            scanf("%d", &nuevo->num);
            fflush(stdin);
            do
            {
                printf("Ingrese el valor del denominador: \n");
                scanf("%d", &nuevo->num2);
                fflush(stdin);
                if (nuevo->num2 == 0)
                {
                    printf("Valor invalido, reingrese denominador diferente de 0 \n");
                }

            } while (nuevo->num2 == 0);
            system("cls");
            nuevo->link = NULL;
            if (cabeza == NULL)
            {
                cabeza = nuevo;
                temp = nuevo;
            }
            else
            {
                temp->link = nuevo;
                temp = nuevo;
            }
        }
        printf("\n");
        return cabeza;
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
            printf("Ingrese el valor del numerador a agregar: ");
            scanf("%d", &nuevo->num);
            fflush(stdin);
            do
            {
                printf("Ingrese el valor del denominador: \n");
                scanf("%d", &nuevo->num2);
                fflush(stdin);
                if (nuevo->num2 == 0)
                {
                    printf("Valor invalido, reingrese denominador diferente de 0\n");
                }

            } while (nuevo->num2 == 0);
            nuevo->link = NULL;
            Nodo *temp = cabeza;
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = nuevo;
        }
    }
    printf("\n");
    return cabeza;
}

Nodo *insertarNodo(Nodo *cabeza)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    printf("Ingrese el valor del numerador a agregar: ");
    scanf("%d", &nuevo->num);
    fflush(stdin);
    do
    {
        printf("Ingrese el valor del denominador: \n");
        scanf("%d", &nuevo->num2);
        fflush(stdin);
        if (nuevo->num2 == 0)
        {
            printf("Valor invalido, reingrese denominador diferente de 0\n");
        }

    } while (nuevo->num2 == 0);
    system("cls");
    nuevo->link = NULL;
    if (cabeza == NULL)
    {
        cabeza = nuevo;
    }
    else
    {
        Nodo *temp = cabeza;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = nuevo;
    }
    printf("\n");
    return cabeza;
}

Nodo *insertarNodoEnPosicion(Nodo *cabeza, int posicion)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    printf("Ingrese el valor del nodo: ");
    scanf("%d", &nuevo->num);
    fflush(stdin);
    nuevo->link = NULL;
    if (cabeza == NULL)
    {
        cabeza = nuevo;
    }
    else if (posicion == 0)
    {
        nuevo->link = cabeza;
        cabeza = nuevo;
    }
    else
    {
        Nodo *temp = cabeza;
        int i = 1;
        while (temp->link != NULL && i < posicion)
        {
            temp = temp->link;
            i++;
        }
        nuevo->link = temp->link;
        temp->link = nuevo;
    }
    return cabeza;
}

void imprimirLista(Nodo *cabeza)
{
    system("cls");
    printf("Lista: \n");
    while (cabeza != NULL)
    {
        if (cabeza->link != NULL)
        {
            printf("%d/%d ->> ", cabeza->num, cabeza->num2);
        }
        else
        {
            printf("%d/%d ", cabeza->num, cabeza->num2);
        }
        cabeza = cabeza->link;
    }
    printf("\n\n");
}

Nodo *eliminar(Nodo *cabeza, int X)
{
    Nodo *anterior = NULL, *actual = cabeza;
    while (actual != NULL)
    {
        if (actual->num == X)
        {
            if (anterior == NULL)
            {
                cabeza = actual->link;
            }
            else
            {
                anterior->link = actual->link;
            }
            free(actual);
            break;
        }
        anterior = actual;
        actual = actual->link;
    }
    return cabeza;
}

int sumaLista(Nodo *cabeza)
{
    int suma = 0;
    while (cabeza != NULL)
    {
        suma += cabeza->num;
        cabeza = cabeza->link;
    }
    return suma;
}

int productoLista(Nodo *cabeza)
{
    system("cls");
    int producto1 = 1, producto2 = 1;
    if (cabeza == NULL)
    {
        printf("No hay elementos en la lista\n");
        return 0;
    }
    else
    {
        while (cabeza != NULL)
        {
            producto1 *= cabeza->num;
            producto2 *= cabeza->num2;
            cabeza = cabeza->link;
        }
        printf("El producto de los elementos de la lista es: %d/%d \n", producto1, producto2);
        return 0;
    }
}

int buscar(Nodo *cabeza, int x)
{
    system("cls");
    int x2;
    printf("Ingrese el numerador del conjunto a/b a buscar\n");
    scanf("%d", &x);

    printf("Ingrese el numerador del conjunto a/b a buscar\n");
    scanf("%d", &x2);

    if (x2 == 0)
    {
        printf("Su numero no se encuentra en la lista\n\n");
        return 0;
    }

    int contador = 0;
    while (cabeza != NULL)
    {
        if (cabeza->num == x && cabeza->num2 == x2)
        {
            contador = contador + 1;
        }
        cabeza = cabeza->link;
    }
    if (contador == 0)
    {
        printf("Su numero no se encuentra en la lista\n\n");
        return 0;
    }
    else
    {
        printf("Su numero se encuentra %d veces en la lista\n\n", contador);
        return 0;
    }
}

void mayorValor(Nodo *cabeza, int *valor, int *posicion)
{
    int mayor = cabeza->num;
    *valor = mayor;
    *posicion = 1;
    cabeza = cabeza->link;
    int i = 2;
    while (cabeza != NULL)
    {
        if (cabeza->num > mayor)
        {
            mayor = cabeza->num;
            *valor = mayor;
            *posicion = i;
        }
        cabeza = cabeza->link;
        i++;
    }
}

void menorValor(Nodo *cabeza, int *valor, int *repeticiones)
{
    int menor = cabeza->num;
    *valor = menor;
    *repeticiones = 1;
    cabeza = cabeza->link;
    while (cabeza != NULL)
    {
        if (cabeza->num < menor)
        {
            menor = cabeza->num;
            *valor = menor;
            *repeticiones = 1;
        }
        else if (cabeza->num == menor)
        {
            (*repeticiones)++;
        }
        cabeza = cabeza->link;
    }
}

float divisionMayorMenor(Nodo *cabeza)
{
    int mayor, menor, repeticiones;
    menorValor(cabeza, &menor, &repeticiones);
    mayorValor(cabeza, &mayor, &repeticiones);
    return (float)mayor / menor;
}

Nodo *ordenarListaAscendente(Nodo *lista)
{
    Nodo *actual = lista, *siguiente = NULL, *nuevo = NULL, *temp = NULL;
    int tempValor;
    while (actual != NULL)
    {
        siguiente = actual->link;
        while (siguiente != NULL)
        {
            if (actual->num > siguiente->num)
            {
                tempValor = actual->num;
                actual->num = siguiente->num;
                siguiente->num = tempValor;
            }
            siguiente = siguiente->link;
        }
        nuevo = (Nodo *)malloc(sizeof(Nodo));
        nuevo->num = actual->num;
        nuevo->link = NULL;
        if (temp == NULL)
        {
            temp = nuevo;
            lista = nuevo;
        }
        else
        {
            if (temp->num != actual->num)
            {
                temp->link = nuevo;
                temp = nuevo;
            }
        }
        actual = actual->link;
    }
    return lista;
}

Nodo *ordenarListaDescendente(Nodo *lista)
{
    Nodo *actual = lista, *siguiente = NULL, *nuevo = NULL, *temp = NULL;
    int tempValor;
    while (actual != NULL)
    {
        siguiente = actual->link;
        while (siguiente != NULL)
        {
            if (actual->num < siguiente->num)
            {
                tempValor = actual->num;
                actual->num = siguiente->num;
                siguiente->num = tempValor;
            }
            siguiente = siguiente->link;
        }
        nuevo = (Nodo *)malloc(sizeof(Nodo));
        nuevo->num = actual->num;
        nuevo->link = NULL;
        if (temp == NULL)
        {
            temp = nuevo;
            lista = nuevo;
        }
        else
        {
            if (temp->num != actual->num)
            {
                temp->link = nuevo;
                temp = nuevo;
            }
        }
        actual = actual->link;
    }
    return lista;
}

void funcionmayor_menor_sumatoria(Nodo *cabeza, int opcion)
{
    system("cls");
    if (cabeza == NULL)
    {
        switch (opcion)
        {
        case 1:
            printf("La lista esta vacia por lo que no existe la sumatoria de los datos\n\n");
            return;
            break;
        
        case 2:
            printf("La lista esta vacia por lo que no existe el mayor dato\n\n");
            return;
            break;
        case 3:
            printf("La lista esta vacia por lo que no existe el menor dato\n\n");
            return;
            break;

        case 4:
            printf("La lista esta vacia por lo que no existe division del mayor y el menor\n\n");
            return;
            break;
        default:
            printf("No deberias ver esto");

            break;
        }
    }
    int numeradorSum = 0;
    int denominadorSum = 1; // Inicializar con un denominador de 1
    int mayorNumerador = cabeza->num;
    int mayorDenominador = cabeza->num2;
    int menorNumerador = cabeza->num;
    int menorDenominador = cabeza->num2;

    // Encontrar el mínimo común múltiplo (MCM) de los denominadores
    Nodo *actual = NULL;
    actual = cabeza;
    while (actual != NULL)
    {
        denominadorSum = mcm(denominadorSum, actual->num2);
        actual = actual->link;
    }

    // Calcular la sumatoria de las fracciones y encontrar la mayor y menor fracción
    actual = cabeza;
    while (actual != NULL)
    {
        numeradorSum += actual->num * (denominadorSum / actual->num2);

        if (actual->num * denominadorSum > mayorNumerador * actual->num2)
        {
            mayorNumerador = actual->num;
            mayorDenominador = actual->num2;
        }

        if (actual->num * denominadorSum < menorNumerador * actual->num2)
        {
            menorNumerador = actual->num;
            menorDenominador = actual->num2;
        }

        actual = actual->link;
    }
    int posicion=1;
    int bandera =1;
    printf("La menor fraccion es %d/%d\n",mayorNumerador,mayorDenominador);
    system("pause");
    switch (opcion)
    {
    case 1:
        printf("La sumatoria de las fracciones es: %d/%d\n", numeradorSum, denominadorSum);
        return;
        break;
    
    case 2:
        
        actual=cabeza;
        while (actual!=NULL&& bandera == 1)
        {
            if (menorNumerador==actual->num && menorDenominador==actual->num2)
            {
                bandera=0;
            }
            posicion=posicion+1;
        }
        printf("la mayor fraccion es %d/%d y se encuentra en la posicion %d\n\n",menorNumerador,menorDenominador,posicion);
        
        break;
    default:
        break;
    }

    return;
    
}
void menu()
{
    Nodo *lista = NULL;
    int opcion = 0, n = 0, X = 0, valor = 0, posicion = 0, repeticiones = 0;
    float division = 0.0;
    do
    {
        printf("1. Insertar N elementos a la lista\n");
        printf("2. Insertar un unico elemento elemento\n");
        printf("3. Eliminar elemento especifico de la lista\n");
        printf("4. Sumar elementos de la lista\n");
        printf("5. Multiplicar elementos de la lista\n");
        printf("6. Buscar elemento en la lista\n");
        printf("7. Encontrar el mayor valor y su posición\n");
        printf("8. Encontrar el menor valor y sus repeticiones\n");
        printf("9. Calcular la división del mayor y el menor\n");
        printf("10. Ordenar la lista de forma ascendente\n");
        printf("11. Ordenar la lista de forma descendente\n");
        printf("12. Imprimir Lista\n");
        printf("13. Insertar nodo en posicion especifica\n");
        printf("14. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
        fflush(stdin);
        system("cls");
        switch (opcion)
        {
        case 1: // listo
            do
            {
                printf("Ingrese la cantidad de elementos de la lista \n");
                scanf("%d", &n);
                fflush(stdin);
                if (n < 1)
                {
                    printf("Valor invalido, reingrese dato mayor o igual a 1\n");
                }

            } while (n < 1);
            system("cls");
            lista = crearLista(lista, n);
            system("cls");
            break;
        case 2: // listo
            system("cls");
            lista = insertarNodo(lista);
            system("cls");
            break;
        case 3: //! no listo
            printf("Ingrese el valor del nodo que desea eliminar: ");
            scanf("%d", &X);
            fflush(stdin);
            lista = eliminar(lista, X);
            break;
        case 4: // listo
            system("cls");
            funcionmayor_menor_sumatoria(lista , 1);
            break;
        case 5: // lsito
            productoLista(lista);
            break;
        case 6: // listo pero solo funciona en interno no devuelve ojito si lo quieres usar para otras funciones
            buscar(lista, X);
            break;
        case 7: //! se crashea por alguna razon divina
            funcionmayor_menor_sumatoria(lista , 2);
            break;
        case 8: //! no listo
            menorValor(lista, &valor, &repeticiones);
            printf("El menor valor de la lista es %d y se repite %d veces\n", valor, repeticiones);
            break;
        case 9: //! no listo
            division = divisionMayorMenor(lista);
            printf("La división del mayor y el menor valor de la lista es: %.2f\n", division);
            break;
        case 10: //! no listo
            imprimirLista(lista);
            lista = ordenarListaAscendente(lista);
            imprimirLista(lista);
            break;
        case 11: //! no listo
            imprimirLista(lista);
            lista = ordenarListaDescendente(lista);
            imprimirLista(lista);
            break;
        case 12: // listo
            imprimirLista(lista);
            break;
        case 13: //! no listo
            printf("Ingrese la posicion del nodo que desea insertar: ");
            scanf("%d", &X);
            fflush(stdin);
            lista = insertarNodoEnPosicion(lista, X);
            break;
        case 14: // listo
            printf("Saliendo...\n");
            break;
        default: // listo xd
            printf("Opción inválida\n");
        }
    } while (opcion != 14);
}
int main()
{
    menu();
    return 0;
}
