#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/

int findMax(int arr[], int size) 
{ 

  int max = arr[0];

  for (int i = 1; i < size; i++)
    
    if (arr[i] > max)
      
      max = arr[i];
  
  return max;
}
/* 
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {

  for (int i = 0; i < size / 2; i++) {
    
    int temp = arr[i];
    arr[i] = arr[size - 1 - i];
    arr[size - 1 - i] = temp;
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
newsize apunta a una dirección válida que no ha sido inicializada con nigún valor específico. 
*newsize debe almacenar el tamaño del nuevo arreglo que se retorna.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) { 

  *newSize = 0;
  
  for (int i = 0; i < size; i++)
    {
      if (arr[i] % 2 == 0)
        {
          (*newSize)++;
        }
    }
  
  int *nuevoArreglo = (int *)malloc((*newSize) * sizeof(int));
  
  if (nuevoArreglo == NULL) {
      return NULL;
  }
  int j = 0;
  for (int i = 0; i < size; i++) {
      if (arr[i] % 2 == 0) {
          nuevoArreglo[j++] = arr[i];
      }
  }

  return nuevoArreglo; 

}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados de menor a mayor y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado de menor a mayor.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int result[]) {
  
  int i = 0, j = 0, k = 0;

  while (i < size1 && j < size2) {
      if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
      } else {
            result[k++] = arr2[j++];
      }
  }
  while (i < size1) {
        result[k++] = arr1[i++];
  }
  while (j < size2) {
        result[k++] = arr2[j++];
  }

}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) { 

  int cont1 = 0;
  int cont2 = 0;
  int iguales = 0;
  
  for (int i = 0; i < size - 1; i++)
  {
      if (arr[i] < arr[i + 1])
          cont1++;
      else if (arr[i] > arr[i + 1])
          cont2++;
      else
          iguales++;
    
  }

  if (cont1 == size - 1 - iguales) return 1;
  else if (cont2 == size - 1 - iguales) return -1;
  else return 0;
 
}
/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;


void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor, int anioNacimiento, int anioPublicacion) {

  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
}
/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
Puedes guiarte con lo que vimos en las clases (diapos).
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) { 
  
  Nodo *cabeza = NULL;
  Nodo *actual = NULL;

  
  for (int i = 0; i < size; i++) {

      Nodo *nuevo_nodo = (Nodo *)malloc(sizeof(Nodo));
      if (nuevo_nodo == NULL) {
          exit(EXIT_FAILURE);
      }
      nuevo_nodo->numero = arr[i];
      nuevo_nodo->siguiente = NULL;
    
      if (cabeza == NULL) {
          cabeza = nuevo_nodo;
          actual = cabeza;
      } else {

          actual->siguiente = nuevo_nodo;
          actual = actual->siguiente;
      }
  }

  return cabeza;
}
