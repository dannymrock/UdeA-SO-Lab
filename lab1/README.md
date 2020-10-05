# LABORATORIO DE PROCESOS - INTRODUCCIÓN TEÓRICA BREVE #

## Contenido detallado ##

La siguiente sección dispone de material teorico y ejemplos para comprender todos aquellos conceptos relacionados con el API de procesos. Como se podra notar existen varios directorios los cuales poseen el material descrito a continuación:

|Directorio|Contenido
|--|--|
|[documentacion](documentacion)|Contiene documentos PDF y tablas con información sobre el API Posix|
|[documentacion_basica](./documentacion_basica)|Contiene los [ejemplos](https://github.com/remzi-arpacidusseau/ostep-code/tree/master/cpu-api) del [Interlude: Process API](http://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf) de procesos del libro de Remzi y la descripción de algunas de las funciones del API de procesos|
|[ejemplo_basico](./ejemplo_basico)|Este directorio contiene cuatro ejemplos basicos. El objetivo de estos, es mostrar el uso de las funciones del API de procesos mas comunes (```getpid```, ```fork```, ```wait``` y ```execl```)|
|[miselanea_ejemplos](./miselanea_ejemplos)|Este directorio contiene un conjunto de ejemplos adicionales de diversa indole para reforzar los conceptos del API de procesos|

## ¿Como abordar esta documentación teorica tan desorganizada? ##

Para abordar el estudio no hay un orden especificado siempre y cuando usted ya se encuentre familiarizado con los conceptos del API de procesos; sin embargo, como guia de estudio le recomendamos que siga los siguientes pasos:
1. Lea el [Interlude: Process API](http://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf) del libro de Remzi y analice y comprenda lo que alli se explica.
2. Una vez que halla leido el capitulo del API de procesos del libro de Remzi, compile y ejecute los ejemplos allí mostrados; esto lo puede hacer accediendo al directorio [documentacion_basica](./documentacion_basica) previamente mencionado.
3. Una vez halla hecho lo anterior, si desea mirar mas ejemplos, acceda al directorio [ejemplo_basico](./ejemplo_basico) y comprenda y ejecute los códigos allí mostrados.
4. Acceda a la miselanea de ejemplos ([miselanea_ejemplos](./miselanea_ejemplos)) alli podrá encontrar varios códigos un poco mas complejos de modo que estudiarlos le permitirá tener una perspectiva mas amplia sobre este API.