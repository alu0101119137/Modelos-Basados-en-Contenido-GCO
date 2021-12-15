# Sistemas de Recomendación. Modelos Basados en el Contenido
- Andrea Hernández Martín
- Alu0101119137

## Introducción
En esta práctica se ha implementado un sistema de recomendación siguiendo el modelo basado en el contenido, en mi caso ha sido realizado mediante el lenguaje de programación C++.

## Descripción del código
Para la realización de la práctica, se han creado clases clases: artículo, símbolo, preprocesador y recomendación. Las cuales se explica el código implementado a continuación.
- Clase Simbolo:  
La clase símbolo lo único que hace es encargase de representar cada palabra de cada artículo. Para ello, guarda los valores de TF, IDF, TF-IDF y el valor del vector normalizado que se calculan en la clase artículo, la cual se va a explicar a continuación.
