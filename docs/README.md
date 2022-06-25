![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de personas en secuencias de imágenes o video

**Alumnos:**

* Brayan Alexis Maldonado Carrasco - Programador Pricipal / Lider
* Martín Enrique A. Díaz Tapia - Programador Secundario

## Resumen 

> En este taller se realizara un software de identificacion de personas el cual funcionara a base a inteligencia artificial previamente entrenada , el que reconocerá personas en secuencias de imagenes o videos mediante una cámara o un video ya previamente grabado. En el programa, durante su ejecución, se podrá ver como identifica a las personas presentes en el video y las clasifica según diversos parametros (como por ejemplo posición), además de resaltar un rectangulo de color rojo sobre cada una de estas personas , al terminar la ejecucion del programa se podra saber cuantas personas diferentes hay entre sí a la vez de saber si han pasado por en frente de la camara , cuantas han entrado y cuantas han salido del recinto, entre otros. Recordemos que para este programa se pretende que cada persona sea única dentro del analísis para evitar que una misma persona sea reconocida 2 o más veces independiente de si esta ha entrado o salido.

## 1. Introducción

El proyecto en desarrollo propone implementar un sistema de vigilancia y conteo mediante el reconocimiento de personas , para esto se utilizaran diferentes recursos como OpenCV , CMake y se programará todo el ya conocido software IDE: Visual Studio Code.

En primera instancia en este proyecto habrán tres etapas, la primera es la descripción de la problematica a resolver, la segunda etapa hablara sobre como abordar dicha problematica y como será el desarrollo para llegar a la solucion de la misma y finalmente en la tercera etapa se obtendran retroalimentaciones sobre los resultados obtenidos para finalizar con la conclusión del proyecto.

### 1.1 Descripción del problema

Para este proyecto se ha soliciado un programa que sea caaz de detectar personas que entran y salen de un recinto además de poder diferenciar entre personas diferentes, es decir que esta persona sea única a sabiendas de que pueda existir una persona con características similares, y con ellos calcular datos sobre el flujo y tránsito de personas.

### 1.2 Objetivos 

**Objetivo General**

Desarrollar un sistema capaz de contar la cantidad de personas que entran y salen de un lugar. Además de reconocer a las personas para que esta sea única al entrar y única al salir.

**Objetivos específicos**

1. Lograr que el programa detecte personas, enfocadas a cuantas entran y cuantas salen diferenciandolas.
2. Lograr que el programa identifique a las personas mediante un tipo de reconomiento, generando que la persona sea única. 
3. Lograr que el programa funcione completamente con ambos puntos anteriores.

### 1.3 Solución propuesta

Para la resolucion utilizaremos la ayuda de OpenCV combinado con la implementacion de algoritmos basado en listas enlazadas para resolver la problematica propuesta. Todo codificado en VS Code y llevando registro de los avances en GitHub.

## 2. Materiales y métodos

Esperamos desarrollar el trabajo mediante, y en su mayoría, investigación personal además de los datos y asistencia recibida por los videos de Ayudantía entregados.

### 2.1 Instalación

La librería utilizada es OpenCV en C++ , la que en un principio nos presentó inconvenientes junto a Visual Studio, debido a recurrentes errores durante la instalacion en 3 equipos diferentes. Uno de esos errores, y el más complicado de resolver, fué que al momento de instalar Visual Studio este arrojaba error de archivos durante la descarga y por lo tanto se asociaba a un problema de conexion de internet. Investigando descubirmos que hay errores al respecto pero nada que nos pudiera ayudar de primera mano ya que nuestra conexion a internet no era el inconveniente. Finalmente Re-instalando todo nuevamente, funcionó.  

### 2.2 Diseño 

Se utilizaron las siguientes clases : Detector.hpp Detector.cpp Persona.hpp Persona.cpp main.cpp Nodo.hpp Nodo.cpp LinkedList.hpp LinkedList.cpp CMakeList.txt 
La arquitectura propuesto o algoritmo se centra en dividir un video frame por frame y luego trabajar de forma individual en cada uno de ellos , primero se reconocen las personas en un frame y luego se almacenan dichas personas en una lista enlazada , luego cuando se trabaja con el frame siguiente se compararan las posiciones de las personas del nuevo frame con las del frame anterior para determinar si la persona aun esta en el rango de la camara del video , determinar si la persona ya salio de este rango etc.


### 2.3 Implementación

### Detector de personas 

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

- Se logró abrir un video y que en este se puedan identificar personas en cada frame del mismo.
- Se logró poder implementar un rectangulo y circulos en cada una de las personas para destacar el reconocimiento en la imagen. 
- Se logró implementar los modulos de listas enlazadas con sus correspondientes metodos para la realizacion de el algoritmo propuesto.


## 4. Conclusiones

En la realización de este proyecto (etapa 1) se busco resolver una problematica la cual es la identificacion de personas que entraban o salian de un recinto , para ellos se implementaron algoritmos y programas para la resolucion de dicha problematica. Además cabe destacar que gracias a este taller se pudo salir de la zona de confort en programación, aprender de la manera correcta y aprender más del trabajo "real" al que nos podemos exponer en al vida real.

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


