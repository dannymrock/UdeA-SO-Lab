<style type="text/css">
.tg  {border-collapse:collapse;border-spacing:0;}
.tg td{font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal;border-color:black;}
.tg th{font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal;border-color:black;}
.tg .tg-0pky{border-color:inherit;text-align:left;vertical-align:top}
.tg .tg-code{font-family:"Courier New";order-color:inherit;text-align:left;vertical-align:top;border-color:inherit;}
</style>

# Servicios POSIX para la gestión de procesos #

## Identificación de procesos ##

Se identifica a cada proceso por medio de un número único con representación entera. Este es conocido como el identificador del proceso (que es de tipo **pid_t**). A continuación se describen algunas de las principales funciones empleadas para este fin:

### pid_t getpid(void) ###

Este servicio devuelve el identificador del proceso que realiza la llamada.

La siguiente tabla detalla mas a fondo esta función:

<table class="tg">
  <tr>
    <th class="tg-0pky"><b>Función</b></th>
    <th class="tg-code">getpid</th>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Sintaxis</b></td>
    <td class="tg-code">git_t getegid(void);</td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Librerías necesarias</b></td>
    <td class="tg-code"> unistd.h, sys/types.h</td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Descripción</b></td>
    <td class="tg-0pky">Devuelve el identificador “Efectivo” del grupo del proceso actual. </td>
  </tr>
   <tr>
    <td class="tg-0pky"><b>Parámetros de entrada</b></td>
    <td class="tg-0pky">Ninguno. </td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Valor retornado</b></td>
    <td class="tg-0pky">
Retorna el valor con el  ID efectivo corresponde al bit ID establecido en el fichero que se está ejecutando. 
 </td>
  </tr>
</table>

### pid_t getppid(void) ###

Devuelve el identificador del proceso padre

La siguiente tabla detalla mas a fondo esta función:

<table class="tg">
  <tr>
    <th class="tg-0pky"><b>Función</b></th>
    <th class="tg-code">getppid</th>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Sintaxis</b></td>
    <td class="tg-code">pid_t getppid(void);</td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Librerías necesarias</b></td>
    <td class="tg-code"> unistd.h, sys/types.h</td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Descripción</b></td>
    <td class="tg-0pky"> La función getppid () devolverá el ID de proceso padre de la llamada del proceso.
. </td>
  </tr>
   <tr>
    <td class="tg-0pky"><b>Parámetros de entrada</b></td>
    <td class="tg-0pky">No tiene. </td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Valor retornado</b></td>
    <td class="tg-0pky">Siempre tendrá éxito y no se reservará ningún valor de retorno para indicar un error.  
 </td>
  </tr>
</table>

### uid_t getuid(void) ###

Devuelve el identificador del usuario real (usuario que ejecuta el proceso).

La siguiente tabla detalla mas a fondo esta función:

<table class="tg">
  <tr>
    <th class="tg-0pky"><b>Función</b></th>
    <th class="tg-code">getuid</th>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Sintaxis</b></td>
    <td class="tg-code">uid_t getuid(void);</td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Librerías necesarias</b></td>
    <td class="tg-code"> unistd.h, sys/types.h</td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Descripción</b></td>
    <td class="tg-0pky"> La función getuid() devuelve el ID del usuario real del proceso actual. El identificador real corresponde con el del proceso invocador.
. </td>
  </tr>
   <tr>
    <td class="tg-0pky"><b>Parámetros de entrada</b></td>
    <td class="tg-0pky">No tiene. </td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Valor retornado</b></td>
    <td class="tg-0pky">Retorna el identificador del usuario real del proceso de llamada.  
 </td>
  </tr>
</table>

### uid_t geteuid(void) ###

Devuelve el identificador del usuario efectivo (usuario en el que se ejecuta el proceso).

La siguiente tabla detalla mas a fondo esta función:

<table class="tg">
  <tr>
    <th class="tg-0pky"><b>Función</b></th>
    <th class="tg-code">geteuid</th>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Sintaxis</b></td>
    <td class="tg-code">uid_t geteuid(void);</td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Librerías necesarias</b></td>
    <td class="tg-code"> unistd.h, sys/types.h</td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Descripción</b></td>
    <td class="tg-0pky"> Retorna el identificador de usuario efectivo. Si el programa tiene el bit setuid fijado, el programa puede correr con los permisos del "owner" independientemente. </td>
  </tr>
   <tr>
    <td class="tg-0pky"><b>Parámetros de entrada</b></td>
    <td class="tg-0pky">Ninguno. </td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Valor retornado</b></td>
    <td class="tg-0pky"> Entero ID de el usuario efectivo (usuario en el cual se está ejecutando el proceso, no confundir con el usuario que lanzó el proceso). 
 </td>
  </tr>
</table>


### gid_t getgid(void) ###


Devuelve el identificador del grupo real.

La siguiente tabla detalla mas a fondo esta función:

<table class="tg">
  <tr>
    <th class="tg-0pky"><b>Función</b></th>
    <th class="tg-code">getgid</th>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Sintaxis</b></td>
    <td class="tg-code">gid_t getgid(void);</td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Librerías necesarias</b></td>
    <td class="tg-code"> unistd.h, sys/types.h</td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Descripción</b></td>
    <td class="tg-0pky"> Función que devuelve el ID(identificador) real del grupo del proceso actual. </td>
  </tr>
   <tr>
    <td class="tg-0pky"><b>Parámetros de entrada</b></td>
    <td class="tg-0pky">Ninguno. </td>
  </tr>
  <tr>
    <td class="tg-0pky"><b>Valor retornado</b></td>
    <td class="tg-0pky">Retorna valor con el ID del grupo del proceso llamante. 
 </td>
  </tr>
</table>

### gid_t getegid(void) ###

Devuelve el identificador del grupo efectivo. La tabla no esta.

## Identificación de procesos ##

Este grupo de funciones permite la creacion y manipulacion del estado de los procesos. 

### pid_t fork(void) ###

Permite crear procesos: Se realiza una clonación del proceso que lo solicita (conocido como proceso padre). El nuevo proceso se conoce como proceso hijo.

|s|s|
|:--|:--|
|q|q|

### int execl (char *path, char *arg, ...) ###

Familia de funciones que permiten cambiar el programa que está ejecutando el proceso.

### void exit (int status) ###

Termina la ejecución de un proceso y envía el valor de “status” al padre. Es similar a “return” de la función “main”.

### pid_t wait (int *status) - pid_t waitpid(pid_t pid, int *status, int options) ###

Permite que un proceso padre espere hasta que finalice la ejecución de un proceso hijo. El proceso padre se queda bloqueado hasta que termina el proceso hijo. Ambas llamadas permiten obtener información sobre el estado de terminación.

### int sleep (unsigned int seconds) ###

Suspende el proceso durante un número de segundos. El proceso despierta cuando ha transcurrido el tiempo o cuando el proceso recibe una señal.







**Agradecimiento**: Estudiantes del curso de Sistemas operativocs por los aportes en la elaboración y mejora de estas notas.