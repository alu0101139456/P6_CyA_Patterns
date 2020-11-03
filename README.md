# Práctica 6. Búsqueda de patrones

## Ángel Julián Bolaño Campos
## Computabilidad y Algoritmia

---

### Introducción
La búsqueda de patrones es un problema importante y de gran aplicación práctica en el ámbito de las Ciencias de la Computación. 
El problema surge cuando se quiere comprobar si un patrón está presente en una determinada secuencia de elementos. 
Esto suele ocurrir, por ejemplo, cuando se desea localizar una determinada palabra o cadena de caracteres dentro de un fichero de texto. 
En muchas herramientas como los editores o procesadores de texto, a menudo se describen los patrones de búsqueda 
(para ejecutar comandos del tipo "buscar y reemplazar") mediante el uso de expresiones regulares. 
Sin embargo, este ejercicio se restringe a casos en los que el patrón de búsqueda sea una única cadena. 

Se han desarrollado múltiples algoritmos para resolver el problema de la búsqueda de patrones pero, en este caso, 
se propone aplicar un algoritmo de búsqueda de patrones basado en un autómata finito. 
Para aplicar el algoritmo es necesario construir un autómata finito a partir del patrón o cadena de búsqueda. 
Dicho autómata será luego utilizado para analizar las cadenas de entrada y determinar si en ellas se encuentra o no el patrón buscado.

### Ejercicio práctico

Se debe diseñar un programa que reciba por línea de comandos tres argumentos: el patrón de búsqueda, un fichero de entrada y un fichero de salida:

~~~

`./pattern_search pattern infile.txt outfile.txt`

~~~

El parámetro `pattern` especifica el patrón de búsqueda, que en este caso será una cadena de símbolos de un determinado alfabeto. 
El fichero de entrada contendrá una línea por cada cadena que se desee analizar en busca del patrón.
En el fichero de salida el programa escribirá una línea indicando "Sí" o "No" en función de si se ha hallado el patrón en la cadena 
correspondiente a esa línea del fichero de entrada. 
 
A modo de ejemplo, si se especifica como patrón de búsqueda `abc` y el fichero de entrada tiene el siguiente
contenido:

```
caaccab
cccabccccc
abcabc
aaa
```

El fichero de salida deberá contener las siguientes líneas:

```
No
Sí
Sí
No
```

En principio, el conjunto de símbolos que se utilizará como alfabeto serán las letras minúsculas (sin incluir la ñ). 
Puesto que un alfabeto es un conjunto finito y no vacío de símbolos, se podría representar el alfabeto con una clase conjunto. 
De hecho, se propone hacer uso de la clase `Set` diseñada en la práctica anterior adaptándola al caso de caracteres alfanuméricos. 
Para ello se tendrá en cuenta el código ASCII de cada carácter (letra) como método para establecer una correspondencia entre cadenas 
de bits y los caracteres alfanuméricos que podrán conformar los símbolos del alfabeto. 
Así, por ejemplo, puesto que el código ASCII del carácter `a` es 97, la pertenencia de la letra `a` al
alfabeto se representará incluyendo el número 97 en el conjunto que representa al alfabeto.

El patrón de búsqueda que se proporcione al programa mediante el parámetro `pattern` representará por lo tanto, 
una cadena formada por *n* letras minúsculas. 
Los símbolos de este patrón se enumeran desde *0* a *n - 1*, de izquierda a derecha.

Partiendo del patrón de búsqueda se construirá un autómata finito con *n + 1* estados enumerados desde *q0* hasta *qn*. 
En el estado *qi* se debe analizar el símbolo que se encuentre en la posición *i* del patrón de búsqueda.

En cada estado *qi* del autómata hay dos comportamientos posibles: 
transitar al estado *qi + 1* con el símbolo `pattern[i]` o transitar al estado *q0* y parar con cualquier otro símbolo. 
Cuando esto ocurre se sabe que es porque no se ha detectado el patrón en la subcadena de entrada. 
En el momento en el que se alcance el estado final *qn* se habrá determinado que el patrón ha sido detectado en la cadena de entrada. 

A modo de ejemplo, si `pattern = abcb`, se debe construir un autómata finito con 5 estados: *q0*, *q1*, ... *q4*. 
* Estado *q0*:  
  - Con el símbolo *a* se transita al estado *q1*
  - Con cualquier otro símbolo se transita a *q0* y se para
* Estado *q1*:  
   - Con el símbolo *b* se transita al estado *q2*
   - Con cualquier otro símbolo se transita a *q0* y se para
* Estado *q2*:  
   - Con el símbolo *c* se transita al estado *q3*
   - Con cualquier otro símbolo se transita a *q0* y se para
* Estado *q3*:  
   - Con el símbolo *b* se transita al estado *q4*
   - Con cualquier otro símbolo se transita a *q0* y se para
* Estado *q4*:  
   - Si se ha alcanzado este estado es que se ha detectado el patrón de búsqueda

Una vez se haya construido el autómata, será necesario iniciar el proceso de reconocimiento. 
Dicho proceso deberá realizarse por cada una de las cadenas de entrada (cada cadena de entrada se encuentra en una línea independiente del fichero de entrada). 
Dada una cadena de entrada *w* con *m* símbolos, el primer análisis de la cadena se realizará desde la posición *j = 0*. 
Si al analizar la cadena desde esa posición, y siguiendo las transiciones del autómata, se alcanza el estado final, 
entonces se puede indicar en la línea correspondiente del fichero de salida que sí se ha detectado el patrón de búsqueda en la cadena de entrada. 
Si, por el contrario, el reconocimiento conduce a transitar al estado inicial *q0* y, por lo tanto, parar, 
habrá que mover *j* una posición a la derecha *j = j + 1* y reiniciar de nuevo el proceso de reconocimiento para otra subcadena de la cadena actual. 
Si se realizan todos los recorridos posibles de la cadena y se sigue sin detectar el patrón, 
entonces se puede indicar en el fichero de salida que el patrón no ha sido detectado en la cadena de entrada.

Cuando finalice el reconocimiento sobre una cadena, ya sea determinando que sí que contiene el patrón buscado o, por el contrario, detectando que no lo contiene, 
se pasará a realizar el reconocimiento sobre la siguiente cadena especificada en el fichero de entrada. 
En el caso de que se detecten cadenas con símbolos no pertenecientes al alfabeto (que en principio se define con letras minúsculas) 
no se realizará el proceso de reconocimiento; en este caso, se escribirá directamente en la línea correspondiente del fichero de salida la palabra `Error`.

**NOTA: Es importante tener en cuenta que para realizar el proceso de reconocimiento es 
imprescindible utilizar el algoritmo que se ha detallado en este guión y que se basa en la definición de un autómata finito. 
NO se podrán utilizar los diferentes métodos de búsqueda en cadenas de texto que proporciona la clase `std::string` ni similares.**

 
### Referencias
* [Wikipedia: búsqueda de patrones] (https://es.wikipedia.org/wiki/B%C3%BAsqueda_de_patrones)
* [Wikipedia: código ASCII] (https://es.wikipedia.org/wiki/ASCII)
* [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
* [Debug helloworld](https://code.visualstudio.com/docs/cpp/config-linux#_debug-helloworldcpp).
* [Learn to debug C++ code using Visual Studio](https://docs.microsoft.com/en-us/visualstudio/debugger/getting-started-with-the-debugger-cpp?view=vs-2019)
* [First look at the Visual Studio Debugger](https://docs.microsoft.com/en-us/visualstudio/debugger/debugger-feature-tour?view=vs-2019)

