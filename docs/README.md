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

Desarrollar un sistema capaz de contar la cantidad de personas que entran y salen de un lugar. Además de reconocer a las personas para que esta sea única al entrar y única al salir.

**Objetivos específicos**

1. Lograr que el programa detecte personas, enfocadas a cuantas entran y cuantas salen diferenciandolas.
2. Lograr que el programa identifique a las personas mediante un tipo de reconomiento, generando que la persona sea única. 
3. Lograr que el programa funcione completamente con ambos puntos anteriores.

### 1.3 Solución propuesta

Para la resolucion se busca utilizar la ayuda de openCV combinado con la implementacion de algoritmos basado en listas enlazadas para resolver la problematica propuesta.

## 2. Materiales y métodos

Explicar brevemente como se espera desarrollar el trabajo de implementación.

### 2.1 Instalación

La librería utilizada es OpenCV en C++ , la que en un principio nos presentó inconvenientes junto a Visual Studio, debido a recurrentes errores durante la instalacion en 3 equipos diferentes. Uno de esos errores, y el más complicado de resolver, fué que al momento de instalar Visual Studio este arrojaba error de archivos durante la descarga y por lo tanto se asociaba a un problema de conexion de internet. Investigando, hay errores al respecto pero nada que nos pudiera ayudar de primera mano ya que nuestra conexion a internet no era el inconveniente. Finalmente Re-instalando todo nuevamente, funcionó.  

### 2.2 Diseño 

Se utilizaron las siguientes clases : Detector.hpp Detector.cpp Persona.hpp Persona.cpp main.cpp Nodo.hpp Nodo.cpp LinkedList.hpp LinkedList.cpp CMakeList.txt 
La arquitectura propuesto o algoritmo se centra en dividir un video frame por frame y luego trabajar de forma individual en cada uno de ellos , primero se reconocen las personas en un frame y luego se almacenan dichas personas en una lista enlazada , luego cuando se trabaja con el frame siguiente se compararan las posiciones de las personas del nuevo frame con las del frame anterior para determinar si la persona aun esta en el rango de la camara del video , determinar si la persona ya salio de este rango etc.


### 2.3 Implementación

### Detecor de personas 

El modelo de deteccion de personas funciona gracias a las librerias de openCV las cuales identifican a una persona en un frame(o mas de una) y las almacena en un vector que solo contiene objetos de tipo persona para posteriormente con un ciclo como se puede observar en el codigo se le asigna a cada persona un rectangulo y tres puntos criticos.

```c++
  cv::Mat frame;
	Detector detector;
	LinkedList lista;//creamos la lista enlazada

	// Loop through available frames
	while (video.read(frame)) {
    
		
		//detector.toggleMode();
		//cout << detector.modeName();
    vector<Persona> found = detector.detect(frame);//lista de personas identificadas con el opencv
    for (vector<Persona>::iterator i = found.begin(); i != found.end(); ++i)
    {	
		    
        Persona &p = *i;//el algoritmo detecta a mas de una persona y los introduce en un vector , luego found[i] iterara en el for
        lista.insertarPrimer(&p);
        cout << "(" << p.getXCentro() << ", " << p.getYCentro() << ")" << endl;

        rectangle(frame, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
        circle(frame, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);
        circle(frame, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
        circle(frame, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
			
      }   

```


## 3. Resultados obtenidos

Se logro el poder abrir un video y que en este se puedan identificar personas en cada frame del mismo.
Se logro poder implementar rectangulo y circulos en cada una de las personas 
se logro implementar los modulos de listas enlazadas con sus correspondientes metodos para la realizacion de el algoritmo propuesto.


## 4. Conclusiones

En la realizacion de este proyecto(etapa 1) se busco resolver una problematica la cual se basaba en la identificacion de personas que entraban o salian de un recinto , para ellos se implementaron algoritmos y programas para la resolucion de dicha problematica.Ademas cabe destacar que gracias a este taller se pudo salir de la zona de confort y aprender de la manera correcta y aprender de verdad.

# Anexos

## Anexo A: Instalación librerías OpenCV

Para instalar las librerias de openCV primero se descargo el programa y luego se agregaron las direcciones de bin y lib a las variables de entorno del sistema operativo de el ordenador.

## Anexo B: Instalación de IDE y configuración librerías OpenCV

Para la cofiguracion de la IDE se presentaron diversos problemas , al principio no se tenia muy claro el como configurar todo lo que tomo aproximadamente un dia , en palabras simples se descargaron 4 extensiones en el visual studio code las cuales fueron c/c++ ,c/c++ compile run , cmake,cmake tools

## Anexo C: Principales problemas en el desarrollo del proyecto

En primer lugar una de las grandes problematicas que se presentaron fue la poca experiencia y poca familiarizacion con visual studio code , ya que tomo aproximadamente un dia completo en poder configurarlo para que funcionara correctamente.

La segunda problematica fue la poca experiencia practica con c++ lo cual dificulto el progreso,la lentitud de el algoritmo de deteccion de personas ya que para una sola imagen funciona bien pero para un video se tarda aproximadamente unos 20 segundos en cargar de frame a frame.


# Referecia

Indicar los libros, páginas web, documentos, etc. Utilizados en el trabajo. Por ejemplo:

1. MONTERO, J.,Metodos matemáticos aplicados a la ganadería.3aed. Sevilla: Ediciones de la pradera,2007.
2. LVARADO,   J.   P.,¿Qué   debe   contener   un   artículo   científico?.http://www.ie.tec.ac.cr/palvarado/pmwiki/index.php/MSc/Art\%c3\%adculoCient\%c3\%adfico. Fe-cha de acceso:13/Nov/2018


