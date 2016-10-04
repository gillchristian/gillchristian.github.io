Es claro que las computadoras no se equivocan, los que lo hacemos somos los programadores. Al la hora de escribir código es importante, entonces, que nos aseguremos de que no lo estamos haciendo. Una forma de lograrlo es utilizando pruebas (tests) que validen el funcionamiento de las diferentes partes de nuestro código, basándonos en casos de prueba.

Existen diferentes tipos de tests que se encargan de testear distintos aspectos de nuestro programa. En este artículo vamos enfocarnos sólamente en las **pruebas unitarias** (_unit tests_):

> En programación, una prueba unitaria es una forma de comprobar el correcto funcionamiento de un módulo de código. Esto sirve para asegurar que cada uno de los módulos funcione correctamente por separado. Luego, con las [Pruebas de Integración][4], se podrá asegurar el correcto funcionamiento del sistema o subsistema en cuestión.

> La idea es escribir casos de prueba para cada función no trivial o método en el módulo, de forma que cada caso sea independiente del resto.

> [Wikipedia. Pruebas Unitarias.][5]

## TDD

Cuando hablamos de tests no podemos dejar de mencionar *Test Driven Development* (TDD) o *Desarrollo Guiado por Pruebas*. Suena feo en español eh? =P

De nuevo, Wikipedia...

> ... es una práctica de ingeniería de software que involucra otras dos prácticas: Escribir las pruebas primero (Test First Development) y Refactorización (Refactoring).

> Para escribir las pruebas generalmente se utilizan las pruebas unitarias (unit test en inglés). En primer lugar, se escribe una prueba y se verifica que las pruebas fallan.

> A continuación, se implementa el código que hace que la prueba pase satisfactoriamente y seguidamente se refactoriza el código escrito. El propósito del desarrollo guiado por pruebas es lograr un código limpio que funcione.

> La idea es que los requisitos sean traducidos a pruebas, de este modo, cuando las pruebas pasen se garantizará que el software cumple con los requisitos que se han establecido.


> [Wikpedia. Desarrollo guiado por pruebas.][1]


## Por donde empezar?

Los _unit tests_ puede ser manuales. Por ejemplo podríamos escribir porciones de código que creen objetos y envién mensajes para probar el funcionamiento de los métodos de una clase.

El problema es que tendríamos que repetirlos cada vez que realizemos cambios en nuestro código, introduciendo nuevas posibilidades de equivocarnos así como la ineficiencia que significa el repetir manualmente, valga la redundancia, repetidas veces una tarea. Esto no suena nada bien...

## SUnit en Pharo

[SUnit][6] es un [framework][2] enfocado en la realización de _unit tests_ para Smalltalk. El Entorno de desarrollo integrado (_IDE por sus siglas en inglés_) [Pharo][7] provee una integración con SUnit que nos permite escribir los tests y corrobar su funcionamiento de forma automática a medida que desarrollamos.

SUnit está compuesto de cuatro clases `TestSuite`, `TestCase`, `TestResource` y `TestResult`.

![SUnit UML][8]

`TestCase`

Es una clase abstracta diseñada para ser implementada. Cáda una de sus subclases representan un grupo de tests con un contenxto común: `test suite`. Cada test se ejecuta creando una instancia de una subclase de `TestCase`, ejecutando `setUp`, ejecutando el método test y luego ejecutando `tearDown`. El contexto es especificado por una variable de instacia de la subclase y por la especialización del método `setUp`, en que se inicializan dichas variables. Las sublclases de `TestCase` pueden ser sobrescritas en el método `tearDown`, que se ejecuta luego de cada test, puede ser usado para liberar los objetos que fueron alocados en `setUp`.

`TestSuite`

Las instaciass de esta clase contienen una colección de tests. Una instacia de `TestSuite` contiene tests y otros `test suite`s. Es decir, un `test suite` contiene sub-instacias de `TestCase` y `TestSuite`. Ambos `TestCase`s y `TestSuite`s entienden el mismo protocolo y pueden ser tratados de la misma forma, por ej. ambos poseen el método `run` que ejecuta los tests. Esta clase implementa el [patrón de composición][9].

`TestResult`

Representa los resultados de la ejecución de `TestSuite`. Guarda el número de test que pasaron y que fallaron, así como el número de errores.

`TestResource`

Un aspecto importante de los _unit tests_ es que deben ser independientes, no importando el orden en que se corren ni la falla de uno debería afectar a otros. `setUp` y `tearDown` ayudan mucho en este aspecto. De todas formas hay ocaciones en que establecer el context (por medio de `setUp`) para cada test consume demasiados recursos. Para esto usamos `TestResource`.


## =/ Mucha teoría . . .

Para poner en práctica lo que aprendimos vamos entonces a implementar la clase Par, que nos permite hacer operaciones simples sobre un par de números, y vamos a agregar tests para asegurarnos que los métodos funcionen bien.

```st
Object subclass: #Par
  instanceVariableNames: 'a b'
  category: 'EjemploTDD'!
```

**Métodos de insancia**:
```st
init: datos
  a := datos at: 1.
  b := datos at: 2.
```
```st
getA
  ^a.
```
```st
getB
  ^b.
```
```st
setA: val
  a := val.
```
```st
setB: val
  b := val.
```

**Métodos de clase**:
```st
new: datos
  |instance|
  instance := super new.
  instance init: datos.
  ^instance.! !
```


Pharo considera como tests a todas las clases que terminen con `Test` y ejecuta los métodos que comiensen con `test`.

Vamos a definir entonces la clase `Par_Test` y probar que `Par new:` y `Par init:` functionen correctamente.

```st
Object subclass: #Par_Test
  instanceVariableNames: 'unPar'
  category: 'EjemploTDD_Test'!
```
Definimos `test_new_init` como método de instancia de `Par_Test`:
```st
test_init
	"
	`Par new` inicializa el Par y envía el mensaje `init`, el cual
	asigna los valores correspondientes para las variables de instancia
		a
		b
	"
	unPar := Par new: #(1 2).

	self assert: (unPar getA) = 1.
	self assert: (unPar getB) = 2.
```

**Que está pasando acá?**

Primero creamos una instancia de `Par`

```st
unPar := Par new: #(1 2)
```

Luego utilizando las afirmaciones o _assertions_: `assert` y `deny` heredamos de `TestCase` nos aseguramos que los valores se hayan asignado apropiadamente.

```st
self assert: (unPar getA) = 1.
self assert: (unPar getB) = 2.
self deny: (unPar getA) = 3.
self deny: (unPar getB) = 5.
```

`TestCase assert:` espera recibir `true`. Si todos los `assert` del método reciben `true` el test va a ser considerado como approbado (`passing`). De lo contrario el test va a fallar (`failing`), o reportar un error (`error`).

`TestCase deny:` funciona de manera similar a `assert`, con la diferencia que los tests pasan al recibir `false`.

> Podemos ejecutar nuestro test haciendo click en el círculo gris que a la izquierda del nombre del método.

> Los colores indican el estado de los tests: verde _passing_, amarillo _failing_, rojo _error_, gris _pending_.

> De la misma forma, para correr toda una suite de tests podemos hacer click en el círculo correspondiente al nombre de la clase.

> Otra forma de correr los tests es con el Test Runner. `Ctrl + O + U` (o `click izquierdo` en el ambiente > `Test Runner`), filtramos los paquetes y suites que querémos, y corremos los tests con `Run Selected`.

Si todo fue bien nuestro primer test debería estar verde.

Aplicando lo que aprendimos de TDD vamos a agregar ahora los tests para los métodos `suma` y `resta`, que todavía tenémos que definir.

_Cabe destacar que ambos son métodos de instancia de_ `Par_Test`.

```st
test_suma
	"
	Par suma devuelve la suma de a y b
	"
	unPar := Par new: #(1 2).

	self assert: (unPar suma) = 3.

	unPar := Par new: #(4 5).
	self assert: (unPar suma) = 9.

test_resta
	"
	Par suma devuelve la resta entre a y b
	"
	unPar := Par new: #(1 2).

	self assert: (unPar resta) = -1.

	unPar := Par new: #(5 2).
	self assert: (unPar resta) = 3.
```

Por el momesto nuestros tests van a dar `error`, ya que no hemos si quiera implementado los métodos `suma` y `resta`.

_Ambos son métodos de instancia de_ `Par`.

```
suma
	^ (a - b).

resta
	^ (a + b).
```

Sorprendentemente los tests no están pasando. Será porque nos equivocamos en algo?

Corregimos
```
suma
	^ (a + b).

resta
	^ (a - b).
```

y ... **Passing** \o/

## Conclusión

Si bien quedaron muchos aspectos por ver, por ejemplo el uso de `setUp`, `tearDown` o `TestResource`para configurar el contexto de nuestros tests, o utilizar `TestSuite` para agrupar tests de clases relacionadas.

Con este ejemplo podimos ver el valor de agregar _unit tests_ automatizados a nuestro código. Esto nos va a permitir estar seguros que el código funcione incluso cuando tengamos que modificar algún método en el futuro. Ya que el peor escenario va a ser revisar por que los tests están fallando.

----------------------------------------------------------

[1]: https://es.wikipedia.org/wiki/Desarrollo_guiado_por_pruebas
[2]: https://es.wikipedia.org/wiki/Framework
[3]: http://pharo.gforge.inria.fr/PBE1/PBE1.html
[4]: https://es.wikipedia.org/wiki/Pruebas_de_Integraci%C3%B3n
[5]: https://es.wikipedia.org/wiki/Prueba_unitaria
[6]: http://pharo.gforge.inria.fr/PBE1/PBE1ch8.html
[7]: http://pharo.org/
[8]: http://pharo.gforge.inria.fr/PBE1/SUnit/figures/sunit-classes.png
[9]: http://pharo.gforge.inria.fr/PBE1/PBE1li2.html
