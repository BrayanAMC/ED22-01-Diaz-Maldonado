![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de personas en secuencias de imágenes o video

**Alumnos:**

* Brayan Alexis Maldonado Carrasco - Programador Pricipal / Lider
* Martín Enrique A. Díaz Tapia - Programador Secundario

## Resumen 

> En este taller se realizara un software de identificacion de personas el cual funcionara a base a inteligencia artificial previamente entrenada , el cual reconocera personas en secuencias de imagenes o videos mediante una camara o un video ya previamente grabado.El programa en el transcurso de su ejecucion se podra ver como identifica a las personas presentes en el video y las clasifica segun diversos parametros(como por ejemplo posicion), ademas de resaltar un rectangulo de color rojo sobre cada una de estas personas , al terminar la ejecucion del programa se podra saber cuantas personas diferentes entre si han pasado por en frente de la camara , cuantas han entrado y salido del resinto entre otros. 

## 1. Introducción

El proyecto en desarrollo propone implementar un sistema de vigilancia basado en el reconocimiento de personas , para esto se utilizaran diferentes recursos como openCV , cmake y se programara en visual studio code como IDE.

En primera instancia en este proyecto habran tres etapas, la primera es la descripcion de la problematica a resolver,la segunda etapa hablara sobre como abordar dicha problematica y como se desarrollara para llegar a la solucion de la misma, y por ultimo en la tercera etapa se obtendran retroalimentaciones sobre los resultados obtenidos para finalizar con la conclusion del proyecto.

### 1.1 Descripción del problema

El problema planteado en este proyecto se basa en la problematica propuesta la cual consiste en un programa que pueda detectar personas que entran y salen de un recinto ademas de poder diferenciar entre personas diferentes y calcular datos en base al flujo de personas.

### 1.2 Objetivos 

**Objetivo General**

Desarrollar un sistema capaz de contar la cantidad de personas que entran, están y salen de un lugar. Además de reconocer a las personas para que esta sea única al entrar y única al salir.

**Objetivos específicos**

1. Lograr que el programa detecte personas, enfocadas a cuantas entran y cuantas salen diferenciandolas.
2. Lograr que el programa identifique a las personas mediante un tipo de reconomiento, generando que la persona sea única. 
3. Lograr que el programa funcione completamente con ambos puntos anteriores.

### 1.3 Solución propuesta

Para la resolucion se busca utilizar la ayuda de openCV combinado con la implementacion de algoritmos basado en listas enlazadas para resolver la problematica propuesta

## 2. Materiales y métodos

Explicar brevemente como se espera desarrollar el trabajo de implementación.

### 2.1 Instalación

La librería utilizada es OpenCV en C++ , la que en un principio nos presentó inconvenientes junto a Visual Studio, debido a recurrentes errores durante la instalacion en 3 equipos diferentes. Uno de esos errores, y el más complicado de resolver, fué que al momento de instalar Visual Studio este arrojaba error de archivos durante la descarga y por lo tanto se asociaba a un problema de conexion de internet. Investigando, hay errores al respecto pero nada que nos pudiera ayudar de primera mano ya que nuestra conexion a internet no era el inconveniente. Finalmente Re-instalando todo nuevamente, funcionó.  

### 2.2 Diseño 

Se utilizaron las siguientes clases : Detector.hpp Detector.cpp Persona.hpp Persona.cpp main.cpp Nodo.hpp Nodo.cpp LinkedList.hpp LinkedList.cpp CMakeList.txt 
La arquitectura propuesto o algoritmo se centra en dividir un video frame por frame y luego trabajar de forma individual en cada uno de ellos , primero se reconocen las personas en un frame y luego se almacenan dichas personas en una lista enlazada , luego cuando se trabaja con el frame siguiente se compararan las posiciones de las personas del nuevo frame con las del frame anterior para determinar si la persona aun esta en el rango de la camara del video , determinar si la persona ya salio de este rango etc.


### 2.3 Implementación

### Detecor de personas 

El modelo de deteccion de personas funciona gracias a las librerias de openCV las cuales identifican a una persona en un frame(o mas de una ) y las almacena en un vector que solo contiene objetos de tipo persona para posteriormente con un ciclo como se puede observar en la imagen se le asigna a cada persona un rectangulo y tres puntos criticos.
  
![](imagenes/codigo_deteccion_personas.png)

Por ejemplo, 

#### Detector de caras

El detector de caras utilizado fue xxx. Para utilizarlo se debe.... El código para detectar una cara en una imagen se muestra a continuación:

```c++
 1. faceCascadePath = "./haarcascade_frontalface_default.xml";
 2. faceCascade.load( faceCascadePath )
 3. std::vector<Rect> faces;
 4. faceCascade.detectMultiScale(frameGray, faces);

 5. for ( size_t i = 0; i < faces.size(); i++ )
 6. {
 7.  int x1 = faces[i].x;
 8.  int y1 = faces[i].y;
 9.  int x2 = faces[i].x + faces[i].width;
10.  int y2 = faces[i].y + faces[i].height;
11. }
```
La primera linea carga el archivo de entrenamiento... etc

## 3. Resultados obtenidos

## 4. Conclusiones

# Anexos

## Anexo A: Instalación librerías OpenCV

## Anexo B: Instalación de IDE y configuración librerías OpenCV

# Referecia

Indicar los libros, páginas web, documentos, etc. Utilizados en el trabajo. Por ejemplo:

1. MONTERO, J.,Metodos matemáticos aplicados a la ganadería.3aed. Sevilla: Ediciones de la pradera,2007.
2. LVARADO,   J.   P.,¿Qué   debe   contener   un   artículo   científico?.http://www.ie.tec.ac.cr/palvarado/pmwiki/index.php/MSc/Art\%c3\%adculoCient\%c3\%adfico. Fe-cha de acceso:13/Nov/2018


