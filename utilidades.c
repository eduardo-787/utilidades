////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE IMPORTACIÃ“N: FICHEROS NECESARIOS A INCLUIR
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include "utilidades.h"   // Mi propia colecciÃ³n de subprogramas Ãºtiles.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE MACROS, CONSTANTES Y VARIABLES GLOBALES: PARA USO GLOBAL.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

char MSJxERROR[] = "Â¡VALOR NO VÃLIDO!";
char MSJxPAUSA[] = "Pulse INTRO para continuar... ";

int codigoError; // VARIABLE GLOBAL: Visible por todos los subprogramas.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE CÃ“DIGO: CUERPOS DE LOS SUBPROGRAMAS DECLARADOS ANTES.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÃ“N:
//
//    void esperarINTRO (void);
//
//  USO:
//
//    Programa que produce una espera hasta que se pulse INTRO.
//
//  DETALLES:
//
//    Es un envoltorio de la funciÃ³n vaciarBuffer(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinÃ³nimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÃMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningÃºn valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
//      Se delega toda la carga de trabajo a esta funciÃ³n.
//
////////////////////////////////////////////////////////////////////////////////

void esperarINTRO (void)
{
  vaciarBuffer();
}


void descartarEntrada (void)
{
  vaciarBuffer();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÃ“N:
//
//    void vaciarBuffer (void);
//
//  USO:
//
//    Programa que espera que el usuario pulse teclas a la espera de INTRO.
//
//  DETALLES:
//
//    Se basa en un bucle que va pidiendo letras del buffer de teclado y no
//    termina hasta que detecta que ha encontrado un "INTRO" (0x10). Cualquier
//    otro cÃ³digo ASCII introducido por el usuario se descarta. Se produce ECO
//    de cualquier tecla pulsada.
//
//  PARÃMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningÃºn valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
//      Es el programa estÃ¡ndar ("prefabricado") que hace la logÃ­stica de
//      comunicarse con el sistema operativo y con el hardware del teclado.
//
////////////////////////////////////////////////////////////////////////////////

void vaciarBuffer (void)
{
  // ENTER CREADO EN DEFINE = ASCII(10) = 0x0A
  
  // MEDIANTE BUCLE DO-WHILE:
  char letra;
  do
  {
    letra = getchar();
  } while (letra != ENTER);
  
  // MEDIANTE BUBLE WHILE:
  // while (getchar() != '\n')   ; // Bucle vacÃ­o
}


void borrarPantalla (void)
{
  limpiarPantalla();
}


void limpiarPantalla (void)
{
  system(BORRAR);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÃ“N:
//
//    void bajar (int nlineas);
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas lÃ­neas como se le indique.
//
//  DETALLES:
//
//    Crea tantas lÃ­neas en blanco como se le suministre como dato. No ubica el
//    cursor de texto en ninguna coordenada concreta, sino que genera contenido
//    en blanco en la pantalla, desplazando el punto donde se escribirÃ¡ texto en
//    acciones posteriores. Utiliza para ello un bucle en cuyo interior se llama
//    a printf() con el cÃ³digo ASCII de salto de lÃ­nea '\n' Ã³ 0x10.
//
//  PARÃMETROS DE ENTRADA:
//
//    nlineas
//
//      Variable entera que recibirÃ¡ del exterior el nÃºmero de lÃ­neas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningÃºn valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Es el programa estÃ¡ndar ("prefabricado") que hace la logÃ­stica de
//      emitir por pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void bajar (int nlineas)
{
  while(nlineas>0)
  {
    printf("\n");   // No se puede usar "mostrar()" porque crearÃ­amos un bucle de llamadas.
    
    nlineas--;
  }
}


void abajo (int nfils)
{
  bajar(nfils);
}


void saltar (int nfils)
{
  bajar(nfils);
}


void desplazarFils (int nfils)
{
  bajar(nfils);
}


void desplazarV (int nfils)
{
  bajar(nfils);
}


void desplazarY (int nfils)
{
  bajar(nfils);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void indentar (int ncolumnas);
//
//  USO:
//
//    Permite mover el cursor hacia la derecha en la pantalla, tantos espacios
//    como se le indique.
//
//  DETALLES:
//
//    Crea tantos espacios en blanco como se le suministre como dato. No ubica
//    el cursor en ninguna coordenada concreta, sino que genera espacios en la
//    pantalla, desplazando el punto donde se escribirá texto hacia la derecha.
//    Utiliza para ello un bucle en cuyo interior se llama a printf() con un
//    espacio en blanco ' '.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncolumnas
//
//      Variable entera que recibirá del exterior el número de espacios en
//      blanco que se va a desplazar el cursor hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      emitir por pantalla.
//
////////////////////////////////////////////////////////////////////////////////


void indentar (int ncolumnas)
{
  for(int i=0; i<ncolumnas; i++)
  {
    printf(" ");   // No se puede usar "mostrar()" porque crearÃ­amos un bucle de llamadas.
  }
}


void derecha (int ncols)
{
  indentar(ncols);
}


void tabular (int ncols)
{
  indentar(ncols);
}


void desplazarCols (int ncols)
{
  indentar(ncols);
}


void desplazarX (int ncols)
{
  indentar(ncols);
}


void desplazarH (int ncols)
{
  indentar(ncols);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void posicionar (int nfils, int ncols);
//
//  USO:
//
//    Mueve el cursor a un punto de la pantalla indicando filas y columnas.
//
//  DETALLES:
//
//    Junta las dos acciones básicas de movimiento: primero baja el cursor
//    tantas líneas como se indique, y luego lo mueve tantos espacios hacia
//    la derecha como se indique. Para ello llama a bajar() y a tabular().
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Número entero con las líneas que se baja el cursor hacia abajo.
//
//    ncols
//
//      Número entero con los espacios que se mueve el cursor hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Se encarga de mover el cursor hacia abajo.
//
//    tabular()
//
//      Se encarga de mover el cursor hacia la derecha.
//
////////////////////////////////////////////////////////////////////////////////

void posicionar (int nfils, int ncols)
{
  bajar(nfils);
  tabular(ncols);
}


void desplazar (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}


void desplazarXY (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retardoSegundos (int segundosmax);
//
//  USO:
//
//    Produce una espera en el programa de aproximadamente los segundos
//    que se le indiquen.
//
//  DETALLES:
//
//    Usa cuatro bucles metidos uno dentro del otro que se repiten muchas
//    veces para gastar tiempo. 
//
//  PARÁMETROS DE ENTRADA:
//
//    segundosmax
//
//      Número entero con los segundos aproximados que debe durar la espera.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Ninguna.
//
////////////////////////////////////////////////////////////////////////////////


void retardoSegundos (int segundosmax)
{
  // POSIBILIDAD: Poner en funciÃ³n de la que usa milisegundos.
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for(int nseg=0; nseg < segundosmax ; nseg++)
  {
    for(int j=0; j<100; j++)
      for(int j=0; j<1000; j++)
        for(int k=0; k<1000; k++)   ;
  }
}



////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retardoMilisegundos (int milisegundosmax);
//
//  USO:
//
//    Produce una espera en el programa de aproximadamente los milisegundos
//    que se le indiquen.
//
//  DETALLES:
//
//    Igual que retardoSegundos() pero ajustado a milisegundos. Usa tres
//    bucles metidos uno dentro del otro para gastar tiempo.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundosmax
//
//      Número entero con los milisegundos aproximados que debe durar
//      la espera.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Ninguna
//
////////////////////////////////////////////////////////////////////////////////

void retardoMilisegundos (int milisegundosmax)
{
  int i, j;
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for (int nmiliseg=0; nmiliseg<milisegundosmax ; nmiliseg++)
    for (i=0; i<100; i++)
      for (j=0; j<1000; j++)   ;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retrasoMilisegundos (int milisegundos);
//
//  USO:
//
//    Produce una espera más exacta que retardoMilisegundos(), usando el
//    reloj interno del ordenador.
//
//  DETALLES:
//
//    En lugar de contar bucles, mide el tiempo real que ha pasado usando
//    clock().
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//
//      Número entero con los milisegundos que debe durar la espera.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    clock()
//
//      Función estándar que consulta el reloj interno del programa para
//      saber el tiempo que ha pasado desde que inició.
//
////////////////////////////////////////////////////////////////////////////////


void retrasoMilisegundos (int milisegundos)
{
  double e = 0;

  clock_t t0 = clock();   // clock_t es un tipo interno equivalente a UINT32.
  
  do
  {
    
    e = 1000*(double)(clock()-t0)/CLOCKS_PER_SEC;

  } while (e<milisegundos);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarSegundos (int segundos);
//
//  USO:
//
//    Produce una espera de los segundos indicados.
//
//  DETALLES:
//
//    Según el sistema operativo en el que se ejecute el programa, usa una
//    función u otra. En Windows usa Sleep() con los segundos multiplicados
//    por 1000 porque Sleep() trabaja en milisegundos. En Linux usa sleep()
//    directamente con los segundos. El #ifdef es el que decide cuál de las
//    dos usar según el sistema operativo.
//
//  PARÁMETROS DE ENTRADA:
//
//    segundos
//
//      Número entero con los segundos que debe durar la espera.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep()  (en Windows)
//
//      Función del sistema operativo Windows que pausa el programa los
//      milisegundos que se le indiquen.
//
//    sleep() (en Linux)
//
//      Función del sistema operativo Linux que pausa el programa los
//      segundos que se le indiquen.
//
////////////////////////////////////////////////////////////////////////////////


void esperarSegundos (int segundos)
{
  #ifdef SO_WINDOWS
    Sleep(segundos*1000);
  #else
    sleep(segundos);
  #endif
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarMilisegundos (int milisegundos);
//
//  USO:
//
//    Igual que esperarSegundos() pero la unidad de tiempo es el milisegundo
//    en lugar del segundo.
//
//  DETALLES:
//
//    Igual que esperarSegundos() pero ajustado a milisegundos. En Windows
//    usa Sleep() directamente con los milisegundos. En Linux usa usleep()
//    que trabaja en microsegundos, por lo que multiplica por 1000.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//
//      Número entero con los milisegundos que debe durar la espera.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep()  (en Windows)
//
//      Igual que en esperarSegundos().
//
//    usleep() (en Linux)
//
//      Función del sistema operativo Linux que pausa el programa los
//      microsegundos que se le indiquen.
//
////////////////////////////////////////////////////////////////////////////////

void esperarMilisegundos (int milisegundos)
{
  #ifdef SO_WINDOWS
    Sleep(milisegundos);
  #else
    usleep(milisegundos*1000);   // Alternativa: nanosleep() de "time.h".
  #endif
}






//////////////////////////////////////////////////////////////////////////////////
//  FUNCIÓN:
//    void pausaSimple (); / void pausa ();
//
//  USO:
//    Espera a que el usuario pulse INTRO.
//
//  DETALLES:
//    Es un alias de las funciones de pausa. Básicamente hace lo mismo que
//    la pausaGenerica pero de forma automática. No le pasas coordenadas
//    ni mensajes; simplemente saca el aviso de "Pulsa INTRO".
//
//  PARÁMETROS DE ENTRADA:
//    No necesita ningún dato (está vacío).
//
//  VALOR DE SALIDA:
//    No devuelve nada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//    pausaGenerica()
//    
//////////////////////////////////////////////////////////////////////////////////


void pausa (void)
{
  pausaEstandar(1, 2);
}


void pausaEstandar (int nfils, int ncols)
{
  pausaGenerica(MSJxPAUSA, nfils, ncols, FALSE);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea);
//
//  USO:
//
//    Muestra un mensaje en pantalla y espera a que el usuario pulse INTRO.
//
//  DETALLES:
//
//    Primero muestra el mensaje que recibe en la posición de pantalla
//    indicada por nfils y ncols. Luego se queda esperando hasta que el
//    usuario pulse INTRO. Es la más completa de las tres porque permite
//    configurar todos los datos: el mensaje, la posición y si se añade
//    una línea nueva al final.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Texto que se mostrará en pantalla antes de esperar.
//
//    nfils
//
//      Número entero con las líneas que se baja antes de mostrar el mensaje.
//
//    ncols
//
//      Número entero con los espacios a la derecha antes de mostrar el mensaje.
//
//    nuevalinea
//
//      Valor verdadero o falso que indica si se añade una línea nueva
//      al final del mensaje.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Se encarga de mostrar el mensaje en la posición indicada, dependiendo 
//      de nfils y ncols.
//
//    esperarINTRO()
//
//      Se encarga de esperar a que el usuario pulse INTRO.
//
////////////////////////////////////////////////////////////////////////////////


void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  mensaje_x_y(msjtxt, nfils, ncols, nuevalinea);

  esperarINTRO();
}

//////////////////////////////////////////////////////////////////////////////////
//  FUNCIÓN:
//    void texto (char msjtxt[]);
//
//  USO:
//    Escribe una frase en la pantalla.
//
//  DETALLES:
//    Al terminar de escribir, baja automáticamente a la
//    siguiente línea, así que lo siguiente que escribas no saldrá pegado.
//
//  PARÁMETROS DE ENTRADA:
//    msjtxt
//      Es la cadena de texto (frase) que quieres que se vea en el programa.
//
//  VALOR DE SALIDA:
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//    puts()
//      Es la función que se encarga de imprimir el texto.
//////////////////////////////////////////////////////////////////////////////////


void texto (char msjtxt[])
{
  puts(msjtxt);
}

//////////////////////////////////////////////////////////////////////////////////
//  FUNCIÓN:
//    void separar();
//
//  USO:
//    Sirve para dejar un espacio en blanco en la pantalla.
//
//  DETALLES:
//    Es una función muy simple que lo único que hace es saltar de línea.
//   Es un alias o atajo de la función mostrar pasándole un salto de línea.
//
//  PARÁMETROS DE ENTRADA:
//    Ninguno.
//
//  VALOR DE SALIDA:
//    No devuelve nada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//    mostrar()
//      La usa para imprimir el carácter y que salte de línea.
//////////////////////////////////////////////////////////////////////////////////


void separar()
{
  mostrar("\n");
}

//////////////////////////////////////////////////////////////////////////////////
//  FUNCIÓN:
//    void nuevaLinea (void);
//
//  USO:
//    Hace que el cursor baje a la siguiente línea en la pantalla.
//
//  DETALLES:
//    Esta función es un alias o una forma simplificada de usar la función 
//    saltar.
//
//  PARÁMETROS DE ENTRADA:
//    Ninguno.
//
//  VALOR DE SALIDA:
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//    saltar()
//      Es la función que realmente hace el trabajo de mover el cursor hacia 
//      abajo el número de veces que se le indique.
//////////////////////////////////////////////////////////////////////////////////


void nuevaLinea (void)
{
  saltar(1);
}


//////////////////////////////////////////////////////////////////////////////////
//  FUNCIÓN:
//    void mostrar (char msjtxt[]);
//
//  USO:
//    Escribe un texto en la pantalla en la posición donde esté el cursor.
//
//  DETALLES:
//    Esta función es una versión simplificada de mostrar_x_y. Actúa como un 
//    alias que te ahorra poner las coordenadas a mano.
//
//  PARÁMETROS DE ENTRADA:
//    msjtxt
//      La frase o cadena de caracteres que quieres que aparezca escrita.
//
//  VALOR DE SALIDA:
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//    mostrar_x_y()
//      Es la función principal que se encarga de colocar y escribir el texto.
//////////////////////////////////////////////////////////////////////////////////

void mostrar (char msjtxt[])
{
  mostrar_x_y (msjtxt, 0, 0);
}


//////////////////////////////////////////////////////////////////////////////////
//  FUNCIÓN:
//    void mostrar_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//    Muestra un mensaje en una posición específica de la pantalla.
//
//  DETALLES:
//    Básicamente te permite colocar un texto en las filas y columnas que quieras, pero 
//    con la diferencia de que siempre lo hace sin añadir una línea nueva 
//    al final (por eso envía el valor FALSE internamente).
//
//  PARÁMETROS DE ENTRADA:
//    msjtxt
//      El texto que se va a mostrar.
//    nfils
//      El número de líneas que baja antes de escribir.
//    ncols
//      El número de espacios a la derecha antes de escribir.
//
//  VALOR DE SALIDA:
//    No devuelve nada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//    mensaje_x_y()
//      La función principal que coloca el texto en las coordenadas dadas.
//////////////////////////////////////////////////////////////////////////////////

void mostrar_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}


//////////////////////////////////////////////////////////////////////////////////
//  FUNCIÓN:
//    void escribir (char msjtxt[]);
//
//  USO:
//    Muestra un texto en la pantalla en la posición actual.
//
//  DETALLES:
//    Esta función es un alias o versión corta de escribir_x_y. Se usa para 
//    poner un mensaje sin tener que especificar coordenadas a mano. Lo que 
//    hace internamente es llamar a la otra función pasándole los valores 
//    0 y 0.
//
//  PARÁMETROS DE ENTRADA:
//    msjtxt
//      La cadena de texto que quieres que se imprima.
//
//  VALOR DE SALIDA:
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//    escribir_x_y()
//      Se encarga de procesar el texto y las coordenadas.
//////////////////////////////////////////////////////////////////////////////////

void escribir (char msjtxt[])
{
  escribir_x_y (msjtxt, 0, 0);
}

//////////////////////////////////////////////////////////////////////////////////
//  FUNCIÓN:
//    void escribir_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//    Sirve para poner un texto en un sitio concreto de la pantalla.
//
//  DETALLES:
//    Esta función hace exactamente lo mismo que mostrar_x_y.
//
//  PARÁMETROS DE ENTRADA:
//    msjtxt
//      El mensaje o frase que se quiere escribir.
//    nfils
//      El número de saltos de línea (filas) para posicionar el texto.
//    ncols
//      El número de espacios (columnas) para mover el texto a la derecha.
//
//  VALOR DE SALIDA:
//    No devuelve nada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//    mensaje_x_y()
//     Coloca el cursor y escribe el mensaje.
//////////////////////////////////////////////////////////////////////////////////


void escribir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

//////////////////////////////////////////////////////////////////////////////////
//  FUNCIÓN:
//    void imprimir (char msjtxt[]);
//
//  USO:
//    Pone un mensaje en la pantalla de forma rápida.
//
//  DETALLES:
//    Funciona igual que la función escribir o mostrar. Lo que hace es llamar a 
//    imprimir_x_y pasándole un 0 en las filas y un 0 en las columnas para 
//    que el texto salga en la posición normal.
//
//  PARÁMETROS DE ENTRADA:
//    msjtxt
//      El texto o la frase que quieres que aparezca en la consola.
//
//  VALOR DE SALIDA:
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//    imprimir_x_y()
//      Es la función que se encarga de posicionar el texto antes de escribirlo.
//////////////////////////////////////////////////////////////////////////////////


void imprimir (char msjtxt[])
{
  imprimir_x_y (msjtxt, 0, 0);
}

//////////////////////////////////////////////////////////////////////////////////
//  FUNCIÓN:
//    void imprimir_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//    Muestra un texto en las coordenadas de pantalla que tú decidas.
//
//  DETALLES:
//    Básicamente hace lo mismo que mostrar_x_y o escribir_x_y. 
//
//  PARÁMETROS DE ENTRADA:
//    msjtxt
//      El texto que se va a imprimir en la pantalla.
//    nfils
//      El número de líneas que baja antes de empezar a escribir.
//    ncols
//      El número de espacios a la derecha antes de empezar a escribir.
//
//  VALOR DE SALIDA:
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//    mensaje_x_y()
//      La función general que se encarga de posicionar y mostrar el mensaje.
//////////////////////////////////////////////////////////////////////////////////


void imprimir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}


void mensaje (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}



//////////////////////////////////////////////////////////////////////////////////
//  FUNCIÓN:
//    void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea);
//
//  USO:
//    Es la función principal para colocar y escribir textos .
//
//  DETALLES:
//    Esta función es la que hace el trabajo real para casi todas las demás. 
//    Primero baja las líneas que le digas, luego se mueve a la derecha los 
//    espacios indicados y escribe el texto. Además, tiene un  
//    boolean para decidir si, al terminar de escribir, el cursor debe 
//    bajar a la siguiente línea o quedarse donde está.
//
//  PARÁMETROS DE ENTRADA:
//    msjtxt
//      El texto que se va a mostrar en la pantalla.
//    nfils
//      El número de saltos de línea que da antes de escribir.
//    ncols
//      El número de espacios (tabulaciones) que se mueve a la derecha.
//    nuevalinea
//      Un valor (verdadero o falso) que indica si salta de línea al final.
//
//  VALOR DE SALIDA:
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//    saltar()
//      Para mover el cursor hacia abajo.
//    tabular()
//      Para mover el cursor hacia la derecha.
//    printf()
//      La función estándar que imprime el texto en pantalla.
//////////////////////////////////////////////////////////////////////////////////


void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  saltar(nfils);
  tabular(ncols);
  printf("%s", msjtxt);
  
  if (nuevalinea)   printf("\n");   // ALTERNATIVA: if (nuevalinea)   putchar(ENTER);
}


//////////////////////////////////////////////////////////////////////////////////
//  FUNCIÓN:
//    void iniciaAleatorizador (void);
//
//  USO:
//    Prepara el programa para que los números al azar no se repitan siempre.
//
//  DETALLES:
//    Esta función sirve para que no se repitan los números aleatorio.
//    Si no la usáramos, el ordenador sacaría siempre los mismos 
//    números cada vez que abres el programa. 
//
//  PARÁMETROS DE ENTRADA:
//    Ninguno.
//
//  VALOR DE SALIDA:
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//    srand()
//      Establece el punto de inicio para el cálculo de números al azar.
//    time()
//      Coge la hora del sistema para que el número sea siempre distinto.
//////////////////////////////////////////////////////////////////////////////////

void iniciaAleatorizador (void)
{
  srand(time(NULL));
}


//////////////////////////////////////////////////////////////////////////////////
//  FUNCIÓN:
//    int generaAleatorioEntero (int limite);
//
//  USO:
//    Sirve para obtener un número al azar dentro de un rango.
//
//  DETALLES:
//    Esta función calcula un número aleatorio que empieza en 0 y llega hasta 
//    uno menos que el número que le pases como límite. Por ejemplo, si le 
//    pones un 10, te dará un número entre 0 y 9.
//
//  PARÁMETROS DE ENTRADA:
//    limite
//      Es el número entero que marca el tope (sin llegar a incluirlo).
//
//  VALOR DE SALIDA:
//    Devuelve el número entero que ha salido al azar.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//    rand()
//      La función estándar de C que genera el número aleatorio base.
//////////////////////////////////////////////////////////////////////////////////

int generaAleatorioEntero (int limite)
{
  // GenerarÃ¡ un nÃºmero entre 0 y limite - 1, nunca llega a limite.
  return (rand() % limite);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÃ“N:
//
//    int obtenerEntero (void);
//
//  USO:
//
//    SustituciÃ³n mejorada de scanf() que impide que queden letras almacenadas
//    en el buffer de teclado para posteriores operaciones de entrada de datos.
//
//  DETALLES:
//
//    La funciÃ³n scanf() no retira el cÃ³digo ASCII de la letra INTRO del buffer
//    de teclado ni posibles letras despuÃ©s de un texto que se pueda convertir
//    en una cantidad. Nos ayudamos de otra funciÃ³n creada en esta librerÃ­a,
//    vaciarBuffer() para ello. No muestra ningÃºn mensaje por pantalla.
//
//  PARÃMETROS DE ENTRADA:
//
//    nlineas
//
//      Variable entera que recibirÃ¡ del exterior el nÃºmero de lÃ­neas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    Devuelve al exterior el valor entero que a su vez ha recibido en la
//    variable "valor" de la funciÃ³n scanf(), mediante paso por referencia.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    scanf()
//
//      Es el programa estÃ¡ndar ("prefabricado") que hace la logÃ­stica de
//      leer caracteres del teclado y convertirlos en la cantidad entera.
//
////////////////////////////////////////////////////////////////////////////////




int obtenerEntero (void)
{
  int valor;
  
  scanf("%d", &valor);
  vaciarBuffer();

  return valor;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerCaracterASCII();
//
//  USO:
//
//    Funciona como un alias de la función obtenerLetra para conseguir un
//    carácter del teclado.
//
//  DETALLES:
//
//   Llama a obtenerLetra() y devuelve lo que esta le dé. 
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
//  VALOR DE SALIDA:
//
//    Devuelve un dato de tipo char (carácter) que ha sido procesado por
//    la función obtenerLetra.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    obtenerLetra()
//
//      Es la función que realmente lee el teclado y comprueba si el
//      carácter es válido.
//
////////////////////////////////////////////////////////////////////////////////

char obtenerCaracterASCII()
{
  return obtenerLetra();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerLetra (void);
//
//  USO:
//
//    Lee una letra del teclado y se asegura de que sea un carácter ASCII
//    estándar, limpiando además el buffer para evitar errores.
//
//  DETALLES:
//
//    La función obtiene un carácter con getchar(). Al terminar,
//    limpia el buffer del teclado llamando a vaciarBuffer(),
//    evitando que se queden letras o el INTRO guardados para la próxima vez.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
//  VALOR DE SALIDA:
//
//    Devuelve la letra pulsada si es válida.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
//      Función estándar que captura el carácter del teclado.
//
//    vaciarBuffer()
//
//      Función de esta librería que limpia los restos del buffer de entrada.
//
////////////////////////////////////////////////////////////////////////////////


char obtenerLetra (void)   // SÃ³lo ASCII VÃLIDO.
{
  char letra, valida;
  
  letra = getchar();
  
  if (letra < 128)
    valida = letra; // Devolveremos la letra
  else
    valida = '\0';  // Devolveremos la letra nula.
  
  // VACIAMOS POSIBLES CÃ“DIGOS EN EL BUFFER.
  //   Se incluye el INTRO EXTRA y una posible escritura de mÃºltiples letras.
  if (letra != ENTER)   vaciarBuffer();

  return valida;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÃ“N:
//
//    int pedirEntero (char msjtxt[], int ncols);
//
//  USO:
//
//    Muestra un mensaje en pantalla para pedir un dato entero al usuario. El
//    mensaje es configurable y desplazable un nÃºmero de caracteres desde la
//    izquierda de la pantalla.
//
//  DETALLES:
//
//    Es como un printf() mÃ¡s un scanf(), mejorados. Puede desplazarse el texto
//    recibido mediante un segundo dato entero. TambiÃ©n impide problemas del
//    buffer de teclado con scanf(). Para ello, delega el emitir el mensaje por
//    pantalla a las funciones msj() y mostrar(), y la toma del dato entero a la
//    funciÃ³n obtenerEntero().
//
//  PARÃMETROS DE ENTRADA:
//
//    mensaje
//
//      Variable de tipo vector de caracteres donde se recibirÃ¡ el texto que se
//      debe mostrar, que debe ser una cadena terminada en '\0'.
//
//    tabs
//
//      Variable entera donde se recibirÃ¡ del exterior el nÃºmero de espacios en
//      blanco a aÃ±adir antes del mensaje.
//
//  VALOR DE SALIDA:
//
//    Devuelve al programa donde se invoque, un valor entero que a su vez esta
//    funciÃ³n ha recibido desde la funciÃ³n obtenerEntero().
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    msj()
//
//      Se encarga efectivamente de mostrar el mensaje.
//
//    mostrar()
//
//      Usada para aÃ±adir en pantalla un texto adicional despuÃ©s del mensaje.
//
//    obtenerEntero()
//
//      Es la funciÃ³n que se encarga en la prÃ¡ctica de obtener la cantidad.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEntero (char msjtxt[], int ncols)
{
  mensaje(msjtxt, 0, ncols);
  mostrar(": ");
  
  return obtenerEntero();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror);
//
//  USO:
//
//    Se encarga de solicitar al usuario un número entero y no para de 
//    preguntar hasta que el número sea 0 o mayor (que no sea negativo).
//
//  DETALLES:
//
//    Utiliza un bucle "do-while" para repetir la pregunta mientras el usuario 
//    escriba números menores que cero. Si se activa la opción "mostrarerror", 
//    el programa avisará con un mensaje de error cada vez que se meta un 
//    dato incorrecto.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Es el texto que se verá en pantalla para pedir el dato.
//
//    ncols
//
//      Número de espacios a la derecha para posicionar el mensaje.
//
//    mostrarerror
//
//      Valor verdadero o falso que indica si queremos que el programa avise 
//      cuando el número sea negativo.
//
//  VALOR DE SALIDA:
//
//    Devuelve el número entero que ha introducido 
//    finalmente el usuario.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje(), mostrar(), mensaje_x_y()
//
//      Se usan para pintar las instrucciones y los errores en la pantalla.
//
//    obtenerEntero()
//
//      Es la que lee el teclado y captura el número.
//
//    nuevaLinea()
//
//      Sirve para separar el mensaje de error de la pregunta.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < 0)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < 0);
  
  return num;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max);
//
//  USO:
//
//    Pide un número al usuario y se asegura de que esté dentro de un rango
//    o límites determinados (entre un mínimo y un máximo).
//
//  DETALLES:
//
//    Funciona de forma parecida a pedirEnteroPositivo, pero más estricta. El 
//    programa muestra el mensaje y el rango permitido. 
//    Si el usuario mete un número más pequeño que el mínimo o más grande 
//    que el máximo, el bucle se repite. Si mostrarerror esta activado, 
//    avisará en pantalla cuando el número esté fuera de los límites.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El texto para pedir el dato.
//
//     ncols
//
//      Los espacios a la derecha para colocar el texto en la pantalla.
//
//    mostrarerror
//
//      Valor verdadero o falso para decidir si se muestra un aviso de error.
//
//      min
//
//      El número más pequeño que se permite introducir.
//
//    max
//
//      El número más grande que se permite introducir.
//
//  VALOR DE SALIDA:
//
//    Devuelve el número entero que el usuario ha escrito, una vez que el 
//    programa ha comprobado que es correcto y está en el intervalo.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje(), mensaje_x_y(), nuevaLinea(), printf()
//
//      Se usan para la parte visual y mostrar los límites y errores.
//
//    obtenerEntero()
//
//      Se encarga de leer el número que el usuario teclea.
//
////////////////////////////////////////////////////////////////////////////////


int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%d,%d]: ", min, max);
    
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < min || num > max)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < min || num > max);
  
  return num;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra);
//
//  USO:
//
//    Solicita al usuario que pulse una tecla específica y no permite continuar
//    hasta que la tecla pulsada coincida con la que se espera.
//
//  DETALLES:
//
//    La función convierte  la letra pulsada por el usuario
//    a mayúsculas mediante toupper(). 
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El texto o pregunta que se le muestra al usuario.
//
//    ncols
//
//      El desplazamiento horizontal (columnas) para colocar el mensaje.
//
//    mostrarerror
//
//      Valor booleano que decide si se muestra un mensaje de error en caso 
//      de que la letra no coincida.
//
//    letra
//
//      El carácter específico que el programa está esperando recibir.
//
//  VALOR DE SALIDA:
//
//    Devuelve el carácter recibido en mayúsculas.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//   toupper()
//
//      Función estándar que convierte caracteres a mayúsculas.
//
//    obtenerLetra()
//
//      Función que lee la pulsación del teclado y limpia el buffer.
//
//    mensaje(), mostrar(), mensaje_x_y(), nuevaLinea()
//
//      Funciones para la gestión visual como lineas en blanco 
//      y para introducir textos.
////////////////////////////////////////////////////////////////////////////////

int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra)
{
  char pedida;
  
  letra = toupper(letra);
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    
    pedida = obtenerLetra();
    pedida = toupper(pedida);   // Convertimos a mayÃºsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != pedida)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != pedida);
  
  return pedida;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror);
//
//  USO:
//
//    Solicita al usuario una respuesta de tipo afirmativa o negativa
//    y no permite avanzar hasta que se pulse una de las dos opciones.
//
//  DETALLES:
//
//    La función muestra el mensaje de pregunta seguido de las opciones válidas
//    Convierte la entrada a mayúsculas.
//    Si el usuario introduce cualquier otro carácter y "mostrarerror" está
//    activado, se visualiza un aviso de error antes de repetir la pregunta.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El texto o pregunta de confirmación que se muestra al usuario.
//
//    ncols
//
//      El número de espacios para desplazar el mensaje horizontalmente.
//
//    mostrarerror
//
//      Valor booleano que determina si se debe avisar al usuario cuando
//      la tecla pulsada no sea una de las opciones válidas.
//
//  VALOR DE SALIDA:
//
//    Devuelve el carácter que el usuario ha elegido finalmente.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    toupper()
//
//      Normaliza la entrada del usuario a mayúsculas.
//
//    obtenerLetra()
//
//      Captura la pulsación del teclado y gestiona la limpieza del buffer.
//
//    mensaje(), mensaje_x_y(), nuevaLinea(), printf()
//
//      Se encargan de la presentación visual, las opciones y los errores.
//
////////////////////////////////////////////////////////////////////////////////


int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror)
{
  char letra;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%c/%c]: ", SI, NO);
    
    letra = obtenerLetra();
    letra = toupper(letra);   // Convertimos a mayÃºsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != SI && letra != NO)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != SI && letra != NO);
  
  return letra;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas);
//
//  USO:
//
//    Compara dos letras para ver si son la misma, permitiendo elegir si se
//    quieren ignorar las diferencias entre mayúsculas y minúsculas.
//
//  DETALLES:
//
//    La función recibe dos caracteres y un parámetro de "sensibilidad". Si
//    "sensibleamayusculas" es falso (FALSE), la función convierte ambas letras
//    a mayúsculas. Si es verdadero (TRUE), las comparará tal cual, 
//    siendo diferentes si una es mayúscula y la otra no.
//
//  PARÁMETROS DE ENTRADA:
//
//    original
//
//      La letra de referencia o la que se espera que sea correcta.
//
//    dada
//
//      La letra que ha introducido el usuario o que se quiere comprobar.
//
//    sensibleamayusculas
//
//      Valor booleano que decide si se distingue entre mayúsculas y minúsculas.
//
//  VALOR DE SALIDA:
//
//    Devuelve un valor booleano: verdadero (TRUE) si las letras coinciden y
//    falso (FALSE) si son diferentes.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    toupper()
//
//      Función estándar utilizada para convertir los caracteres a mayúsculas
//      cuando la comparación no es sensible a éstas.
//
////////////////////////////////////////////////////////////////////////////////


boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas)
{
  if (!sensibleamayusculas)
  {
    original = toupper(original);
      dada   = toupper(dada);
  }
  
  return (original == dada);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas);
//
//  USO:
//
//    Comprueba si una letra específica se encuentra dentro de un grupo o 
//    lista de letras permitidas.
//
//  DETALLES:
//
//    La función recorre todos los caracteres de la cadena "seleccion" 
//    usando un bucle. En cada paso, utiliza la función validarLetraUnica para 
//    ver si la letra coincide con alguna del conjunto. Si la encuentra, activa 
//    el resultado como verdadero y detiene la búsqueda (break). Al igual que 
//    en funciones anteriores, se puede elegir si se ignoran las mayúsculas 
//    y minúsculas mediante el parámetro "sensibleamayusculas".
//
//  PARÁMETROS DE ENTRADA:
//
//    letra
//
//      El carácter individual que queremos buscar o validar.
//
//    seleccion[]
//
//      Una cadena de caracteres (array) que contiene todas las letras que 
//      consideramos válidas.
//
//    sensibleamayusculas
//
//      Valor booleano que determina si la búsqueda debe distinguir entre 
//      mayúsculas y minúsculas.
//
//  VALOR DE SALIDA:
//
//    Devuelve TRUE (verdadero) si la letra está en el conjunto, o FALSE 
//    (falso) si no lo está.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    strlen()
//
//      Función que calcula la longitud del conjunto de letras.
//
//    validarLetraUnica()
//
//      Función que realiza la comparación individual entre dos caracteres.
//      
//
////////////////////////////////////////////////////////////////////////////////


boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas)
{
  boolean resultado = FALSE;
  int largo = strlen(seleccion);
  
  for(int i = 0; i < largo ; i++)
  {
    if (validarLetraUnica(letra, seleccion[i], sensibleamayusculas))
    {
      resultado = TRUE;
      break;
    }
  }
  
  return resultado;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char *cadenaOpcionesDisponibles (char entrada[]);
//
//  USO:
//
//    Toma una lista de caracteres pegados y los convierte en una cadena
//    con barras.
//
//  DETALLES:
//
//    Esta función reserva memoria de forma dinámica (usando malloc) para crear
//    una nueva frase. Calcula el espacio necesario basándose en la cantidad de
//    letras de entrada, añadiendo hueco para las barras  y el carácter de
//    final de cadena. Si la entrada es nula o vacía,
//    gestiona el error devolviendo una cadena vacía o NULL.
//
//  PARÁMETROS DE ENTRADA:
//
//    entrada[]
//
//      La cadena original que contiene las letras de las opciones.
//
//  VALOR DE SALIDA:
//
//    Devuelve un puntero (char *) a la nueva cadena de texto generada. 
//    
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    strlen()
//
//      Para medir cuántas letras tiene la cadena original.
//
//    malloc()
//
//      Para solicitar al sistema el espacio de memoria donde se guardará
//      la nueva cadena con las barras.
//
////////////////////////////////////////////////////////////////////////////////

char *cadenaOpcionesDisponibles (char entrada[])
{
  if (entrada == NULL) return NULL;   // Si no dan nada, petas mÃ¡ximus ...
  
  char *textoinicial, *textofinal;
  
  textoinicial = entrada;
  
  int largoinicial, largofinal;
  
  largoinicial = strlen(textoinicial);

  if (largoinicial == 0)
  {
    // Nos dan cadena vacÃ­a, asÃ­ que generamos vacÃ­a. Pero consideramos el '\0'.
    largofinal = 1;
    textofinal = (char *) malloc(1*sizeof(char));
    textofinal[0] = '\0';
  }
  else
  {
    // CASO 1: "A" -> "A" => largo 2 = 1 (letra) + 1 ('\0')
    // CASO 2: "ABC" -> "A/B/C" => largo 6 = 3 (letras) + 2 (sepadores) +1 ('\0'); 
    largofinal = 2 * largoinicial;
    textofinal = (char *) malloc(largofinal*sizeof(char));
    
    if (textofinal != NULL)
    {
      int j = 0;
      for (int i = 0; i < largoinicial; i++, j++)
      {
        textofinal[j] = textoinicial[i];
        j++;
        textofinal[j] = '/';
      }
      
      // Sustituimos la Ãºltima '/' por un ' 0'.
      j--;
      textofinal[j] = '\0';
    }
  }

  return textofinal;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas);
//                           
//
//  USO:
//
//    Pide al usuario que elija una letra de entre un grupo de opciones 
//    permitidas y no permite avanzar hasta que la elección sea correcta.
//
//  DETALLES:
//
//    Utiliza cadenaOpcionesDisponibles() para presentar las opciones.
//      Entra en un bucle donde solicita la letra y 
//    comprueba si pertenece al conjunto mediante validarLetraConjunto(). Si la 
//    búsqueda no era sensible a mayúsculas, devuelve el carácter en mayúsculas 
//    para estandarizar el resultado.
//
//  PARÁMETROS DE ENTRADA:
//
//     msjtxt
//      El texto descriptivo de la solicitud.
//
//    ncols
//      Desplazamiento horizontal para la interfaz.
//
//      mostrarerror
//      Interruptor booleano para mostrar el mensaje de error estándar.
//
//   seleccion[]
//      Cadena que contiene todos los caracteres que se aceptan como válidos.
//
//    sensibleamayusculas
//      Determina si el programa distingue entre mayúsculas o minúsculas.
//
//  VALOR DE SALIDA:
//
//    Devuelve el carácter que el usuario ha seleccionado si es válido.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    cadenaOpcionesDisponibles(), free()
//      Para crear la interfaz visual de opciones.
//
//    validarLetraConjunto()
//      Para verificar si la entrada del usuario está en la lista.
//
//    obtenerLetra(), toupper()
//      Para capturar y normalizar el dato de entrada.
//
//    mensaje(), mostrar(), mensaje_x_y(), nuevaLinea()
//      Para la gestión de la salida por pantalla.
//
////////////////////////////////////////////////////////////////////////////////


int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas)
{
  // HACER: Evitar que falle con Â«seleccionÂ» a valor NULL.
  
  // Usar Â«cadenaOpcionesDisponibles()Â» implica luego liberar memoria con Â«free()Â».
  char *editada = cadenaOpcionesDisponibles(seleccion);
  
  char letra;
  
  boolean validada;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(" [");
    printf("%s", editada);
    mostrar("]: ");
    
    letra = obtenerLetra();

    validada = validarLetraConjunto(letra, seleccion, sensibleamayusculas);
    
    if (mostrarerror)
    {
      if (!validada)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
  } while (!validada);
  
  // Liberamos la memoria para cadena modificada.
  free(editada);
  
  // Si no era sensible a mayÃºsculas, siempre la devolvemos mayÃºscula.
  if (!sensibleamayusculas)   letra = toupper(letra);
  
  return letra;
}







////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerTeclaInteractiva (void);
//
//  USO:
//
//    Captura una pulsación del teclado, detectando tanto
//    letras normales como teclas especiales.
//
//  DETALLES:
//   Esta no espera a que se pulse INTRO, ya  que utiliza _getch().
//    Es capaz de detectar teclas especiales. Mediante un switch, traduce
//    esos códigos de Windows a constantes propias.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
//  VALOR DE SALIDA:
//
//    Devuelve el carácter o el código correspondiente a la tecla pulsada,
//    convertido a tipo char.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    _getch()
//
//      Función que captura una tecla del buffer sin mostrarla en pantalla y sin esperar al INTRO.
//
////////////////////////////////////////////////////////////////////////////////


#ifdef SO_WINDOWS

#include <conio.h>

char obtenerTeclaInteractiva(void)
{
  int caracter = _getch();   // En Windows, getch() ya es bloqueante por defecto.

  if (caracter == 0 || caracter == 224)
  {
    // Tecla especial, depende de un segundo cÃ³digo. Lo leemos.
    caracter = _getch();
    
    switch(caracter)
    {
      case 72: caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
      case 80: caracter = TECLA_ABAJO;     break;   // Flecha Abajo
      case 75: caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
      case 77: caracter = TECLA_DERECHA;   break;   // Flecha Derecha
      default: caracter = TECLA_NULA;               // Tecla nula.
    }
    else
    {
      // NormalizaciÃ³n de teclas conflictivas no estÃ¡ndar.
      switch(caracter)
      {
        case 13: caracter = TECLA_ENTER;
        case 8:  caracter = TECLA_RETROCESO;
      }
    }
    
    return (char)caracter;
}
  
  
  ////////////////////////////////////////////////////////////////////////////////
  //
  //  FUNCIÓN:
  //
  //    int obtenerTeclaInteractiva (void);
  //
  //  USO:
  //
  //    Versión para Linux que permite capturar teclas al instante 
  //    sin esperar a que el usuario pulse la tecla INTRO.
  //
  //  DETALLES:
  //
  //    Igual que el anterior (char obtenerTeclaInteractiva)
  //
  //  PARÁMETROS DE ENTRADA:
  //
  //    Ninguno.
  //
  //  VALOR DE SALIDA:
  //
  //    Devuelve la tecla pulsada.
  //
  //  FUNCIONES DE LAS QUE DEPENDE:
  //
  //    tcgetattr() y tcsetattr()
  //      Para leer y cambiar la configuración de la terminal.
  //
  //    fcntl()
  //      Para cambiar entre modo bloqueante y no bloqueante al leer secuencias.
  //
  //    getchar()
  //      Para capturar los caracteres del buffer de entrada.
  //
  ////////////////////////////////////////////////////////////////////////////////

#else

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int obtenerTeclaInteractiva(void)
{
  struct termios terminaloriginal, terminalnueva;
  int caracter;

  // 1. Obtenemos la configuraciÃ³n actual de la terminal.
  tcgetattr(STDIN_FILENO, &terminaloriginal);
  terminalnueva = terminaloriginal;

  // 2. Desactivamos el modo canÃ³nico (espera de INTRO) y el ECO (ver la tecla al pulsar).
  terminalnueva.c_lflag &= ~(ICANON | ECHO); // Quitamos espera de INTRO y eco
  tcsetattr(STDIN_FILENO, TCSANOW, &terminalnueva);
  
  // 3. El programa se detiene aquÃ­ hasta recibir un carÃ¡cter.
  // Las flechas envÃ­an una secuencia de escape: 27 (ESC), 91 ('['), y una letra.
  caracter = getchar();
  
  if (caracter == ESCAPE)
  {
    // Cambiamos a NO BLOQUEANTE un instante para ver si hay bytes extra
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    
    // Pedimos a ver si hay otro caracter.
    int siguiente = getchar();
    
    // Â¿Es '[' (91)?
    if (siguiente == '[')
    {
      // Lo desechamos simplemente no usando "siguiente".

      // Pedimos el tercer cÃ³digo de caracter generado.
      caracter = getchar();
      
      while ((siguiente = getchar()) != EOF && siguiente != -1);

      switch(caracter)
      {
        case 'A': caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
        case 'B': caracter = TECLA_ABAJO;     break;   // Flecha Abajo
        case 'D': caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
        case 'C': caracter = TECLA_DERECHA;   break;   // Flecha Derecha
        default:  caracter = TECLA_NULA;      break;
      }
    }
    else
    {
      if (siguiente == EOF || siguiente == -1)
      {
        // Era sÃ³lo la tecla ESCAPE.
        caracter = TECLA_ESCAPE;
      }
      else
      {
        // Era una secuencia no contemplada.
        caracter = TECLA_NULA;
      }
    }

    // Restauramos el modo BLOQUEANTE de la terminal.
    fcntl(STDIN_FILENO, F_SETFL, flags);
  }

  // 4. Restauramos la configuraciÃ³n original antes de salir.
  tcsetattr(STDIN_FILENO, TCSANOW, &terminaloriginal);
  
  return caracter;
}

#endif
