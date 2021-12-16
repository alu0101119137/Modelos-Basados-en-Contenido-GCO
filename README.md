# Sistemas de Recomendación. Modelos Basados en el Contenido
- Andrea Hernández Martín
- Alu0101119137

## Introducción
En esta práctica se ha implementado un sistema de recomendación siguiendo el modelo basado en el contenido, en mi caso ha sido realizado mediante el lenguaje de programación C++.

## Descripción del código
Para la realización de la práctica, se han creado clases clases: artículo, símbolo, preprocesador y recomendación. Las cuales se explica el código implementado a continuación.
- Clase Simbolo:  
La clase símbolo lo único que hace es encargase de representar cada palabra de cada artículo. Para ello, guarda los valores de TF, IDF, TF-IDF y el valor del vector normalizado que se calculan en la clase artículo, la cual se explicará más adelante.
- Clase Preprocesador:  
La clase Preprocesador se encarga de almacenar las palabras de los articulos de manera correcta, es decir, eliminado los signos de puntuación y espacios que puedan tener los artículos además de pasarlas a minúsculas. Para esto, se utilizan tres funciones, la primera es *generarPalabras* que se encarga de saltarse los espacios en blanco y los saltos de líneas, y mete las palabras en un vector que se encargará de almacenarlas todas para poder trabajar con ellas. Antes de meter la palabra en el vector, las convierte a minúscula y les quita todos los signos de puntuación que no necesitamos almacenar en el vector final de simbolos, para esto se usa la segunda función que es *preprocesar*. Una vez tenemos las palabras como las queremos comprueba si cada palabra está en el vector, en caso de que no lo esté la mete en el vector y continua comprobando, en caso de que sí esté no la mete en el vector pero aunmenta el TF de esa palabra, utilizando para la comprobación la tercera función *tieneSimbolo* que comprueba si el nombre de esa palabra ya está almacensada en el vector final.   
- Clase Articulo:  
Esta clase es la encargada de almacenar todos los símbolos de cada artículo y calcula los datos de cada uno de ellos. Es decir, tiene un vector de símbolos en los que almacena las palabras de cada artículo ya procesadas. Para cada símbolo calcula el TF, IDF y el TF-IDF mediante las formulas aprendidas en clase, las cuales son para el TF es simplemente contar el número de veces que está la palabra en el artículo, para el IDF lo que hay que hacer es el logaritmo en base 10 de el número total de documentos divido entre el número total de documentos en los que aparece la palabra, y por último para el TF-IDF lo que se hace es multiplicar el valor del TF por el del IDF. En esta clase también se calcula la longitud del vector que se utilizará más adelante para obtener el valor normalizado, dicha longitud se calcula mediante la función *generarVectorSize* la cual devuelve la raiz cuadrada de la suma al cuadrado del valor TF-IDF de cada palabra. Una vez tenemos el valor del vector longitud calculamos el valor normalizado de cada palabra dividiendo el valor del TF-IDF entre el valor del vector longitud, esto se hace en la función *generarValorNormalizado*. También tenemos un atributo que almacena el valor del coseno para averiguar la similaridad entre los artículos.
- Clase Recomendacion:  
La clase recomendación en primer lugar se encarga de leer el fichero que se pasa por parámetros, crea los artículos y los almacena en un vector de artículos, llamando a las funciones de la clase Articulo, esto lo hace en la función *generarArticulos*. Luego, tiene una función *runPrograma* que se encarga de poner en funcionamiento el programa, llamando a los métodos que generan las tablas con todos los datos a imprimir por pantalla. Para generar las tablas se utiliza la función *generarTablas* la cual para cada artículo, llama a los metodos de las clases explicadas anteriormente que hacen el cálculo de los datos que queremos mostrar. Con esta clase también calculamos el coseno de cada artículo aplicando la fórmula correspondiente, la cual solo se aplica a palabras que están en ambos artículos, es decir, si la palabra no está en uno de los artículos no se les calcula el coseno. Una vez hecho los calculos, se procede a imprimir las tablas mediante la funcion *printTables* que muestra por pantalla cada artículo con todas las palabras y los valores TF, IDF, TF-IDF y valor normalizado, y la función *printTablaCoseno* que muestra el valor del coseno entre todos los articulos.

## Ejemplo de uso
Para el uso del código, se necesita crear la estructura de directorios como la que hay en este repositorio,es decir, un directorio bin, otro build dentro del cual se encuentra el Makefile, un directorio include con todos los ficheros de cabeceras de la clase, un directorio inputs donde está el fichero de entrada del programa con los artículos a utilizar y por último, el directorio src donde se encuentra el código fuente de las clases y el programa pincipal. Una vez tenemos la estructura de directorios creada, tenemos que posicionarnos en el directorio build y ejecutar el comando make, una vez compilado se ejecuta mediante make run y el programa muestra por pantalla el resultado de los artículos que están en el ficher de entrada. Si quisieramos probar otros artículos lo que tenemos que hacer es copiar los que queremos probar en el fichero de entrada *input_file.txt*. Una vez ejecutado el programa se vería así en la terminal:
