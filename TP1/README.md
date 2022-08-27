## Laboratorio N2
# Repaso Lenguaje C
### SOI - FCEFyN - UNC

## Compilacion
**Para la compilacion de este proyecto debera utilizar GCC**
Dentro de este repositorio se encuentra el archivo **Makefile** que le permitira compilar.

*Comandos necesarios*

**Compilacion**
- make *(Realiza la compilacion)*
*Este comando genera un ejecutable llamado* **execute** 

**Ejecucion**
- ./execute *(Ejecuta el programa)*
El programa cuenta con un menu para sastifacer los item **C-Strings y Arreglos**

Podra obtener:
 - Obtener la **memoria ram total**, **libre** y **disponible** en *Megabytes*. A partir del archivo */proc/meminfo*. 
 - Obtener la memoria *swap* **Ocupada**. A partir del archivo */proc/meminfo*.
 - Obtener información referida al CPU, a partir del archivo */proc/cpuinfo*:
 - Obtener informacion en un array dinamico del archivo */proc/version*

**Clean Make**
- make clean *(Limpia el directorio de los archivos ejecutables generados a partir de la compilacion)*

**--------------------------------------------------------------------------------------------------**

1. **Estructuras**
- **¿Cómo utilizar typedef junto a struct? ¿Para qué sirve? Ejemplo**.
 Como sabemos las estructuras son una coleccion de variables bajo un nombre.
 Mediante *typedef* podemos definir un mecanimos de alias para el tipo de dato que usaremos en nuestra definicion de *struct* dando la posibilidad de crear nuevo tipo de datos. Por ejemplo:
 ```c
 typedef struct Persona{
		char nombre[20];
		char apellidos[40];
		int edad;
	}Persona;

 int main(){
    Persona persona1;
    
    return 0;
 }
 ```


- **¿Qué es packing and padding ?**
Los miembros de la estructura se colocan uno tras otro en orden creciente de memoria.
Dependiendo de la arquitectura sea de 32 o 64 bits se usaran 4 u 8 bytes para reservar espacio de memoria por el compilador para estos miembros a pesar de que el tipo de dato requiera menos bytes, de todas maneras se insertan bytes vacios para respetar el tamaño de palabra segun la arquitectura. Este concepto es llamado **padding**. 
Se puede evitar esto utilizando **packing** especificando al compilador que evite realizar el relleno de bytes y significa eliminar espacios no asginado asignado por la estructura.
Se debe especficar en GCC como **__attribute__((__packed__))**

2. **A partir de los archivos struct.h y lab2.c, asociados a este laboratorio:**
**Para compilar estos archivos moverse al directorio */src* dentro de este repositorio**
**Alli se encuntra el archivo Makefile que permite compilar el *lab2***

**Comandos**

Con *make* genera la compilacion y un archivo ejecutable **lab2**

Con *./lab2* podra ejecutar el programa

Con *make clean* podra eliminar los archivos generados a partir de la compilacion

 **Respuestas**
 Los tamaños de las estructuras varian debido al orden que se han declarado los miembros que contiene la estructura. En primer lugar *BaseData*, y segun lo mencionado de los concptos de padding, podemos ver como se completan los bytes dependiendo la arquitectura. Las primeras 3 variables *a, b, x* ocuparan 12 bytes a pesar que sean del tipo *char* dos de ellas y que ocupan 1 bytes este tipo de dato. Mientras que las variables *y, c* ocupara 2 bytes en el caso unsigned short int y solo 1 bytes para char, dejando lugar a rellenar solo 1 bytes para respetar el tamaño de la palabra. De manera similar ocurre con las variables *z, d*. 
Cuando reordenamos la declaracion de variables podemos ser mas eficiente en el uso de memoria y evitar estos bytes "vacios". Para el caso de la estructura *ReorderData* se puede ver como reordenando las variables *unsigned short int y; unsigned short int z;* podemos completar los 4 bytes evitando como el caso anterior tener 1 byte de relleno y de esta manera liberar espacio de memoria.
NO es el caso para la estructura *ExtendedData* en el cual la declaracion de los miembros de la estructura genera un relleno de hasta por de mas bytes de lo necesario para repetar la arquitectura cuando el compilador reserva memoria. Este caso es de lo menos eficiente ya que utiliza mas bytes de los que realmente necesita.
El ultimo caso de la estructura *BaseDataPacked* podemos ver como utilizar el concepto de **packing** lo cual nos permite indicar al compilador que evite realizar el relleno de bytes independiente de como se definieron los mimbros de la estructura. El compilador respetara de esta manera el tamaño del tipo de dato declarado.