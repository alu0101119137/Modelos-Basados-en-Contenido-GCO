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
