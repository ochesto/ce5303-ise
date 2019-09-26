Por Ernesto Ulate.

### Crear directorio build

    mkdir build

### Compilar las bibliotecas y el programa de prueba mediante:

    cmake ../ -DCMAKE_INSTALL_PREFIX:PATH=/path/to/taller-5/calculadora/build/usr

    make

    make install

### Ejecutar aplicaciones de prueba:

#### Programa con biblioteca estática
En el directorio build:

    usr/bin/calculadora

##### Recuerde establecer la variable de entorno mediante:
En el directorio build:

    export LD_LIBRARY_PATH=$(pwd)/usr/lib
