# Servicios POSIX para la gestión de procesos #

## Identificación de procesos ##

Se identifica a cada proceso por medio de un número único con representación entera. Este es conocido como el identificador del proceso (que es de tipo **pid_t**). A continuación se describen algunas de las principales funciones empleadas para este fin:

### pid_t getpid(void) ###

Este servicio devuelve el identificador del proceso que realiza la llamada.

La siguiente tabla detalla mas a fondo esta función:

|Función|```getpid```|
|:--|:--|
|**Sintaxis**|```pid_t getpid(void);```|
|**Librerías necesarias**|```#include <unistd.h>``` <br>```#include sys/types.h```|
|**Descripción**|Devuelve el identificador “Efectivo” del grupo del proceso actual.|
|**Parámetros de entrada**|No tiene|
|**Valor retornado**|Retorna el valor con el ID efectivo corresponde al bit ID establecido en el fichero que se está ejecutando.|


### pid_t getppid(void) ###

Devuelve el identificador del proceso padre

La siguiente tabla detalla mas a fondo esta función:

|Función|```getppid```|
|:--|:--|
|**Sintaxis**|```pid_t getppid(void);```|
|**Librerías necesarias**|```#include <unistd.h>``` <br>```#include sys/types.h```|
|**Descripción**|La función getppid () devolverá el ID de proceso padre de la llamada del proceso.|
|**Parámetros de entrada**|No tiene|
|**Valor retornado**|Siempre tendrá éxito y no se reservará ningún valor de retorno para indicar un error.|


### uid_t getuid(void) ###

Devuelve el identificador del usuario real (usuario que ejecuta el proceso).

La siguiente tabla detalla mas a fondo esta función:

|Función|```getuid```|
|:--|:--|
|**Sintaxis**|```uid_t getuid(void);```|
|**Librerías necesarias**|```#include <unistd.h>``` <br>```#include sys/types.h```|
|**Descripción**|La función getuid() devuelve el ID del usuario real del proceso actual. El identificador real corresponde con el del proceso invocador.|
|**Parámetros de entrada**|No tiene|
|**Valor retornado**|Retorna el identificador del usuario real del proceso de llamada.|

### uid_t geteuid(void) ###

Devuelve el identificador del usuario efectivo (usuario en el que se ejecuta el proceso).

La siguiente tabla detalla mas a fondo esta función:

|Función|```geteuid```|
|:--|:--|
|**Sintaxis**|```uid_t geteuid(void);```|
|**Librerías necesarias**|```#include <unistd.h>``` <br>```#include sys/types.h```|
|**Descripción**|Retorna el identificador de usuario efectivo. Si el programa tiene el bit setuid fijado, el programa puede correr con los permisos del "owner" independientemente.|
|**Parámetros de entrada**|No tiene|
|**Valor retornado**|Entero ID de el usuario efectivo (usuario en el cual se está ejecutando el proceso, no confundir con el usuario que lanzó el proceso).|

### gid_t getgid(void) ###

Devuelve el identificador del grupo real.

La siguiente tabla detalla mas a fondo esta función:

|Función|```getgid```|
|:--|:--|
|**Sintaxis**|```gid_t getgid(void);```|
|**Librerías necesarias**|```#include <unistd.h>``` <br>```#include sys/types.h```|
|**Descripción**|Función que devuelve el ID(identificador) real del grupo del proceso actual.|
|**Parámetros de entrada**|No tiene|
|**Valor retornado**|Retorna valor con el ID del grupo del proceso llamante.|

### gid_t getegid(void) ###

Devuelve el identificador del grupo efectivo. La tabla no esta.

## Gestión de procesos ##

Este grupo de funciones permite la creacion y manipulacion del estado de los procesos. 

### fork ###

Permite crear procesos: Se realiza una clonación del proceso que lo solicita (conocido como proceso padre). El nuevo proceso se conoce como proceso hijo.

|Función|```fork```|
|:--|:--|
|**Sintaxis**|```pid_t fork(void);```|
|**Librerías necesarias**|```#include <unistd.h>```|
|**Descripción**|La función ```fork()``` crea un nuevo proceso hijo como duplicado del proceso que la invoca (padre).|
|**Parámetros de entrada**|No tiene|
|**Valor retornado**|Cuando la ejecución de la función es exitosa se retorna un valor diferente para el padre y para el hijo:<br>- Al padre se le retorna el PID del hijo. <br> - Al hijo se le retorna 0.<br><br>El valor retornado será -1 en caso de que la llamada falle y no se pueda crear un proceso hijo.|

### exe ###

Familia de funciones que permiten cambiar el programa que está ejecutando el proceso.

|Función|Familia de funciones exec|
|:--|:--|
|**Librerías necesarias**|```#include <unistd.h>```|
|**Sintaxis de las diferentes funciones**|```int execl(const char *path, const char *arg,...);``` <br>```int execlp(const char *path, const char *arg,...);``` <br>```int execle(const char *path, const char *arg,...,char *const envp[]);``` <br>```int execv(const char *path, char *const argv[]);``` <br>```int execvp(const char *file, char *const argv[]);``` <br>|
|**Descripción**|Esta familia de funciones, reemplaza la imagen de memoria actual del proceso con una nueva imagen de memoria. En caso de que la llamada a la función sea correcta esta no retorna nada, si hay una falla el valor retornado será -1|
|**Parámetros de entrada**|- **path o file**: Cadena de caracteres que contiene el nombre del nuevo programa a ejecutar con su ubicación, **/bin/cp** por ejemplo.<br>**const char *arg**: Lista de uno o más apuntadores a cadenas de caracteres que representan la lista de argumentos que recibirá el programa llamado. Por convención, el primer argumento deberá contener el nombre del archivo que contiene el programa ejecutado. El último elemento de la lista debe ser un apuntador a NULL.<br>**char *const arg[]**: Array de punteros a cadenas de caracteres que representan la lista de argumentos que recibirá el programa llamado. Por convención,  el primer argumento (arg0) deberá tener el  nombre del archivo que contiene el programa ejecutado y el último elemento deberá ser un apuntador a NULL.<br>**char *const envp[]**: Array de apuntadores a cadenas que contienen el entorno de ejecución (variables de entorno) que tendrá accesible el nuevo proceso. El último elemento deberá ser un apuntador a NULL.|


### exit ###

Termina la ejecución de un proceso y envía el valor de “status” al padre. Es similar a “return” de la función “main”.

|Función|```exit```|
|:--|:--|
|**Sintaxis**|```void exit(int status);```|
|**Librerías necesarias**|```#include <stdlib.h>```|
|**Descripción**|Esta función causa la terminación normal de un proceso. La variable entera status es empleada para transmitir al proceso padre la forma en que el proceso hijo ha terminado. Por convención este valor suele ser 0 si el programa termina de manera exitosa u otro valor cuando la terminación de este es anormal.|
|**Parámetros de entrada**||
|**Valor retornado**|Ninguno.|


### wait ###

Permite que un proceso padre espere hasta que finalice la ejecución de un proceso hijo. El proceso padre se queda bloqueado hasta que termina el proceso hijo. Ambas llamadas permiten obtener información sobre el estado de terminación.

|Función|```wait```|
|:--|:--|
|**Sintaxis**|```pid_t wait(int *status)```|
|**Librerías necesarias**|```#include <sys/types.h>``` <br> ```#include <sys/wait.h>```|
|**Descripción**|Esta función suspende la ejecución del proceso padre hasta que su hijo termine.|
|**Parámetros de entrada**|**status** es el puntero a la dirección donde la llamada al sistema debe almacenar el estado de finalización, o valor de retorno del proceso hijo|
|**Valor retornado**|Retorna un entero que contiene el PID del proceso hijo que finalizó o -1 si no se crearon hijos o si ya no hay hijos por los cuales esperar.|


### pwaitpid ###


### sleep ###

Suspende el proceso durante un número de segundos. El proceso despierta cuando ha transcurrido el tiempo o cuando el proceso recibe una señal.

|Función|```sleep```|
|:--|:--|
|**Sintaxis**|```sleep(int second);```|
|**Librerías necesarias**|```#include <unistd.h>``` <br> ```#include <sys/types.h>```|
|**Descripción**|Sleep() hace que el hilo de llamada esté inactivo hasta que hayan transcurrido ciertos segundos o hasta que llegue una señal que no se ignore.|
|**Parámetros de entrada**|Número de segundos que se quiere esperar.|
|**Valor retornado**|Retorna cero si el tiempo solicitado a transcurrido, o el número de segundos que quedan para “dormir”, si la llamada fue interrumpida por un “signal handler”|

### kill ###

Permite terminar de manera forzada un proceso un proceso.

|Función|```kill```|
|:--|:--|
|**Sintaxis**|```int kill(pid_t pid, int sig);```|
|**Librerías necesarias**|```#include <signal.h>```|
|**Descripción**|Envía una señal a un proceso o a un grupo de procesos. Un proceso puede enviar señales a otro proceso que tenga el mismo ID real o efecto o siempre y cuando tenga los permisos para hacerlo. Un programa puede hacer un llamada kill() a sí mismo.|
|**Parámetros de entrada**|1. **pid_t pid**: Especifica el proceso al cual se le quiere enviar la señal.<br>- **Si pid > 0**, se enviará una señal al proceso cuyo ID sea igual a pid.<br>- **Si pid = 0**, se enviará una señal a todos los procesos cuyos ID de grupo sea igual al del proceso que envía la señal (excepto de los que no posee permisos para hacerlo).<br>- **Si pid < -1**, se envía la señal a todos los procesos cuyo ID de grupo sea igual al valor absoluto de pid.<br>2. **int sig**: Especifica la señal que debe ser enviada al proceso. Las lista de señales se puede consultar en la siguiente [enlace](https://docs.google.com/document/d/1lXv7xkjbAYdNDS0nEYEcB71psUchEWcmjmcnB0Zj3ps/edit), en la sección signals.|
|**Valor retornado**|La función retorna 0 si el proceso tiene permiso para enviar la señal. Si el envío de la señal falla, retorna -1.|


**Agradecimiento**: Estudiantes del curso de Sistemas operativocs por los aportes en la elaboración y mejora de estas notas.