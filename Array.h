#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

  @Author: Libardo J. Rengifo
  @NameLibrary: JS Functions

*/


#ifndef _JSLIBS_
#define _JSLIBS_

typedef struct{
    int * Array;
    int size;
}ArrayNodeIntiger;

// FUNCIONES EN RELACION A NUMEROS
int isIntiger(char *);
int isNatural(char *);
int Intiger(char *);
int isNatural(char *);
int isPrime(char *);
int isPar(char *);
int isFloat(char *);
int isIntigerChar(char);

//FUNCIONES EN RELACION A CADENAS
int stringIncludesChar(char *, char);

//FUNCIONES EN RELACION A ARREGLOS ENTEROS
int arrayIncludeElement(int *,int, int);
void arrayReplaceAll(int *, int, int, int);
void arrayPrint(int *, int);
void arrayReverse(int *, int);
void arraySort(int *, int);
void arrayPush(int *, int, int);
void arrayUnshift(int *, int, int);
void arrayReset(int *, int, int);
void arrayInsert(int *, int, int, int);
void arrayConcat(int *, int, int *, int);
void arrayRemove(int *, int, int);
int arraySlice(int *, int, int, int);
int arrayCount(int*, int, int);

//Con Nodos de arreglos
void arrayNodePrint(ArrayNodeIntiger *);
void arrayNodeRemove(ArrayNodeIntiger *, int);
void arrayNodeReplaceAll(ArrayNodeIntiger*, int, int);
void arrayNodeReverse(ArrayNodeIntiger *);
int arrayNodeCount(ArrayNodeIntiger *, int);
void arrayNodeConcat(ArrayNodeIntiger *, ArrayNodeIntiger *);
int arrayNodeIncludeElement(ArrayNodeIntiger *, int);
void arrayNodeInsert(ArrayNodeIntiger *, int, int);
void arrayNodeSort(ArrayNodeIntiger *);
void arrayNodeReset(ArrayNodeIntiger *, int);
void arrayNodePush(ArrayNodeIntiger *, int);
void arrayNodePop(ArrayNodeIntiger *);
void arrayNodeSlice(ArrayNodeIntiger *, int, int);
int arrayNodeSum(ArrayNodeIntiger *);

int isIntigerChar(char number){
  return (48 <= (int)number) && ((int)number <= 57);
}
int isIntiger(char * numero){
  // la variable 'es' indica con un 1 o un 0 si cada caracter es un digito en la tabla ASCII
  int i, es=0, l = strlen(numero), negative = 0;
  if(l > 0){//La longitud del parametro tiene que ser mayor a 0 para poder comprobar CARACTERES
    for(i = 0; i < l ; i++){
      if(!negative && numero[0] == '-'){//si la variable negative es falsa (0) entonces el numero no ha sido marcado como negativo
                                      //y se marcara como negativo si estrictamente el simbolo '-' aparece delante de todos los numeros (indicando negatividad)
        negative = 1;//si es así entonces marcamos el numero como negativo
        continue;//obviamos el codigo restante ya que cambiara el valor de 'es' ya que '-' no es un caracter ASCII numerico
        //despues de obviar el codigo restante, jamas se volvera a entrar en este condicional ya que negative no es falso, es true ahora,
        //por lo tanto cualquier caracter '-' despues del primero no sera un caracter ASCII numerico valido
      }
      if((48 <= (int)numero[i]  && (int)numero[i] <= 57)){
         //comprobamos un rango de codigos ASCII para saber si esta entre los codigos de los numeros
        es = 1;
      }else{
        es = 0;
        i = l;//rompemos el for
      }
    }
  }else es = 0; //si la longitud es igual a 0 entonces no hay nada que comprobar
  
  /* IMPORTANTE 
    el return se usa un operador ternario que indica que el string pasado por parametro sea un numero entero positivo o negativo
    si es alguno de los dos devuelve 1 (true) en caso contrario devuelve 0 (false)
  */
  return (es && negative) || (es && !negative );
}

int  Intiger(char * numero){
  return isIntiger(numero) ? atoi(numero) : -1;
}

int isNatural(char * numero){
  return isIntiger(numero) && numero[0] != '-';
}

int isPar(char * numero){
  return Intiger(numero) % 2 == 0;
}

int isPrime(char * numero){
  int primo = 1, divisor = 2;//suponemos que la cadena es un numero, y a la vez el numero es primo
  int parseN = Intiger(numero);
  if(parseN > -1){
      while( (divisor < parseN) && primo){
        if(parseN % divisor == 0) primo = 0; //si es divisble entre el rango de 2 y numero-1 no es un numero primo
        divisor++;
      }
  }else primo = 0;
  return primo;
}

int isFloat(char * numero){
  int es = 0,length = strlen(numero), puntos = 0, i, guiones=0;
  if(length > 0){
    if(numero[0] != '.' && numero[0] != ',' && numero[length-1] != '.' && numero[length-1] != ','){
      for(i=0; i < length; i++){
        if(numero[i] == '-')
          guiones++;
        else if(numero[i] == '.')
           puntos++;
        else if(isIntigerChar(numero[i])){
          es = 1;
        }else{
          es = 0;
          i = length;
        }
      }
    }
  }                                    
  return (es && puntos >= 1 && puntos <= 1 && guiones <= 1 && numero[0] == '-') || (es && puntos >= 1 && puntos <= 1 && guiones ==0 && numero[0] != '-');
}

int stringIncludesChar(char * string, char character){
  if(strlen(string) > 0){
    short i = 0;
    while(i < strlen(string))
      if(string[i++] == character) return 1;
  }
  return 0;
}

int arrayIncludeElement(int * array, int size, int value){
  if(size > 0){
    int i = 0;
    while(i < size){
      if(array[i++] == value) return i;
    }
  }
  return -1;
}

void arrayReplaceAll(int * array, int size, int value, int replace){
  if(size > 0){
    int i = 0;
    while(i < size){
      if(array[i] == value) array[i++] = replace;
    }
  }
}

void arrayPrint(int * array, int size){
  int i = 0;
  while(i < size){
    if(i+1 == size) printf("%d\n", array[i++]);
    else
      printf("%d, ", array[i++]);
  }
}

void arrayReverse(int * array, int size){
  int i=0, index =0;
  int copy[size];
  while(i < size) copy[i] = array[i++];
  for(i=size-1; i >=0;) array[i--] = copy[index++];
}

void arraySort(int * array, int size){
  int aux, i=0, k=0;
  for(; i < size; i++){
    for(; k < size; k++){
      if(array[i] < array[k]){
        aux = array[k];
        array[k] = array[i];
        array[i] = aux;
      }   
    }
  }
}

void arrayPush(int * array, int size, int value){
  array[size] = value;
}

void arrayUnshift(int * array, int size, int value){
  int i=1, copy[size+1], index =0;
  while(i <= size) copy[i++] = array[index++];

  copy[0] = value;
  for(i=0; i <= size;) array[i] = copy[i++];
}

int arraySlice(int * array, int size, int start, int end){
 if((start < end) && (end <= size)){
    int array2[size], i=0, index=0;
    while(i < size) array2[i] = array[i++];
    
    arrayReset(array, size, -1);//reiniciamos el arreglo
    for(i=start; i < end;) array[index++] = array2[i++];
  }
}

void arrayReset(int * array, int size, int value){
  int i = 0;
  while(i < size) array[i++] = value;
}

void arrayInsert(int * array, int size, int pos, int value){
              // arreglo[size]     9         2        100
   int i;
   /*
   v=valor
   p= posicion ( i del for)
        v 1, 2, 3, 4, 5, 6, 7, 8, 9
        p 0  1  2  3  4  5  6  7  8
      pos       2  2  2  2  2  2  2
      
      cuando (pos >= p == false) se sale del for y reemplaza el 3 por value (parametro de la funcion)
      
   */
   // i >= pos hacemos que el valor que esta en array[pos] sea movido a array[pos+1] para no perder ese valor
   for(i = size - 1; i >= pos; i--){
    //con i >= pos nos aseguramos que en la ultima iteracion de i en array[i] sea movido a array[i+1] es decir
    //una posicion a la derecha, asi "duplicamos" el valor en dicha posicion y nos aseguramos que no
    //perderemos el valor en array[i], con eso aseguramos que el valor que estaba en array[i] no se pierda
    //al insertar value en esa posicion
    //los demas valores antes de pos, no se veran afectados.
      array[i + 1] = array[i];
   }
   //el dato de array[pos] es decir algun valor que estaba originalmente en alli se reemplaza por
   //el dato que el usuario vaya a insertar, y el dato que estaba anteriormente nose perdera porque lo
   //hemos movido a la derecha anteriormente con el for
   array[pos] = value;
}

//mete array2 en array1
void arrayConcat(int * array1, int size1, int * array2, int size2){
  int i=0, j = size1;
  while(i < size2) array1[j++] = array2[i++];
}

void arrayRemove(int * array, int size, int value){
  int index = arrayIncludeElement(array, size, value);//obtenemos el indice del elemento a quitar
  if(index > -1){
    int i = index + 1;
    array[index] = array[index+1];
    for(; i < size; i++) array[i] = array[i+1];
  }
}

int arrayCount(int * array, int size, int value){
  int i = 0, count = 0;
  while(i < size)
    if(array[i++] == value) count++;
  return count;
}

void arrayNodeRemove(ArrayNodeIntiger * array, int value){
	int index = -1, i = 0;
	while(i < array->size){
		if(array->Array[i] == value){
			index = i++;
			break;
		}
	}
	if(index > -1){
		i= index + 1;
		array->Array[index] = array->Array[index + 1];
		for(; i < array->size; i++)
			array->Array[i] = array->Array[i + 1];
		array->size--;
	}
}

void arrayNodeReplaceAll(ArrayNodeIntiger * array, int value, int replace){
	int i = 0;
	for(; i < array->size; i++)
		if(array->Array[i] == value) array->Array[i] = replace;
	
}
void arrayNodeReverse(ArrayNodeIntiger * array){
	int i = array->size - 1, k = 0, arrayAux[array->size];
  
	while(i >= 0) arrayAux[k++] = array->Array[i--];
	for(i=0; i < array->size; i++) array->Array[i] = arrayAux[i];
}

void arrayNodePrint(ArrayNodeIntiger * array){
  int i=0;
  while(i < array->size){
    if(i+1 == array->size)
      printf("%d\n", array->Array[i++]);
    else
      printf("%d, ", array->Array[i++]);
  }
}

int arrayNodeCount(ArrayNodeIntiger * array, int value){
  int i = 0, count = 0;
  while(i < array->size) if(array->Array[i++] == value) count++;
  return count;
}

void arrayNodeConcat(ArrayNodeIntiger * array1, ArrayNodeIntiger * array2){
  int i=0, j = array1->size;
  while(i < array2->size){
    array1->Array[j++] = array2->Array[i++];
    array1->size++;
  }
}

int arrayNodeIncludeElement(ArrayNodeIntiger * array, int value){
  int i;
  for(i=0; i < array->size; i++) if(array->Array[i] == value) return i;
  return -1;
}

void arrayNodeInsert(ArrayNodeIntiger * array, int pos, int value){
   if( !(pos > array->size) ){
      int i = array->size - 1;
      while(i >= pos) array->Array[i + 1] = array->Array[i--];
      array->Array[pos] = value;
   }
}

void arrayNodeSort(ArrayNodeIntiger * array){
  int i, k, aux;
  for (i = 0; i < array->size; i++){
    for (k = 0; k < array->size; k++){
      if (array->Array[i] < array->Array[k]){ 
          aux = array->Array[k];
          array->Array[k] = array->Array[i];
          array->Array[i] = aux;
      }
    }
  }
}
void arrayNodeReset(ArrayNodeIntiger * array, int value){
  int i =0;
  while(i < array->size) array->Array[i++] = value;
}

void arrayNodePush(ArrayNodeIntiger * array, int value){
  array->Array[array->size++] = value;
}
void arrayNodePop(ArrayNodeIntiger * array){
  array->Array[array->size-1] = 0;
  array->size--;
}
void arrayNodeSlice(ArrayNodeIntiger * array, int start, int end){
 if((start < end) && (end <= array->size)){
    int array2[array->size], i, index=0;

    for(i=0; i < array->size; i++) array2[i] = array->Array[i];
    //arrayReset(array->Array, array->size, 0);//reseteamos el arreglo
    array->size = 0;
    for(i=start; i < end; i++){
      array->Array[index++] = array2[i];
      array->size++;
    }
   
  }
}

int arrayNodeSum(ArrayNodeIntiger * array){
  int i = 0, sum = 0;
  while(i < array->size) sum += array->Array[i++];
  return sum;
}
#endif
