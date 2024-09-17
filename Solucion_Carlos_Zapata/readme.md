# Programa de Inversión de Líneas

Este es un programa en C que lee las líneas de un archivo de entrada o de la entrada estándar y las imprime en orden inverso. El resultado puede ser mostrado en la terminal o guardado en un archivo de salida.

## Descripción

El programa utiliza una lista enlazada para almacenar cada línea del archivo o entrada estándar y luego las imprime en orden inverso. Tiene tres modos de operación:

1. **Sin argumentos**: Lee de la entrada estándar (teclado) y escribe en la salida estándar (terminal).
2. **Un archivo de entrada**: Lee de un archivo de entrada y escribe en la salida estándar (terminal).
3. **Un archivo de entrada y uno de salida**: Lee de un archivo de entrada y escribe en un archivo de salida.

## Instrucciones de Uso

### 1. Crear el archivo fuente en C

1. Abre la terminal.
2. Usa el editor de texto `nano` para crear el archivo `reverse.c`:
   ```bash
   nano reverse.c
3.Dentro del archivo `reverse.c`, copia el código fuente del programa (disponible en el repositorio de GitHub).

Guarda el archivo presionando `Ctrl + O` y luego presiona `Enter`.

Sal de `nano` presionando `Ctrl + X`.

### 2. Compilar el programa

Para compilar el archivo `reverse.c`, ejecuta el siguiente comando en la terminal:

\```bash

gcc -o reverse reverse.c

Esto generará un archivo ejecutable llamado `reverse`.

### 3. Ejecutar el programa

El programa puede ejecutarse de tres maneras diferentes:


#### 3.2. Con un archivo de entrada

Puedes ejecutar el programa especificando un archivo de entrada. El programa leerá el archivo y mostrará las líneas en orden inverso en la terminal. Para ello, crea un archivo llamado input.txt (puedes usar nano):

bash

Copiar código

nano input.txt

Escribe algunas líneas en el archivo:

Copiar código

Línea 1

Línea 2

Línea 3

Guarda y cierra el archivo. Luego ejecuta el programa con el archivo de entrada:

bash

Copiar código

./reverse input.txt

El programa imprimirá el contenido del archivo en orden inverso:

Copiar código

Línea 3

Línea 2

Línea 1

#### 3.3 Con un archivo de entrada y un archivo de salida

Si deseas que el resultado se guarde en un archivo de salida, especifica tanto el archivo de entrada como el de salida:

bash

Copiar código

./reverse input.txt salida.txt

El programa leerá el contenido de input.txt y lo guardará en salida.txt en orden inverso. Para ver el contenido del archivo de salida, usa:

bash

Copiar código

cat salida.txt

El resultado será:

Copiar código

Línea 3

Línea 2

Línea 1

#### 4. Errores comunes

Si el archivo de entrada y salida son el mismo, el programa devolverá un error:

javascript

Copiar código

Error: el archivo de entrada y salida deben ser diferentes

Si no se puede abrir el archivo de entrada, se mostrará:

javascript

Copiar código

Error: no se puede abrir el archivo 'input.txt'

Requisitos

Tener instalado un compilador de C, como gcc.

Acceso a la terminal de Linux o similar.

Contribución

Si quieres contribuir a este proyecto, puedes hacer un fork del repositorio, realizar cambios y enviar un pull request.


