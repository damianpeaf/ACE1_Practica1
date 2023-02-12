# **Práctica 1**
### Universidad de San Carlos de Guatemala
### Facultad de Ingeniería
### Escuela de Ciencias y Sistemas
### Arquitectura de Computadores y Ensambladores 1
### Sección B
<br></br>

## **Manual Técnico**
<br></br>

| Nombre | Carnet | 
| --- | --- |
| Daniel Estuardo Cuque Ruíz | 202112145 |
| Damián Ignacio Peña Afre | 202110568 |
| Alvaro Norberto García Meza | 202109567 |
| José Manuel Ibarra Pirir | 202001800 |
----
# **Introducción**
## Descripción general
La práctica consiste en la creación de un prototipo que contiene un display que está conformado por 2 matrices LED de 8x8. Es capaz de presentar un mensaje de forma dinámica que puede ser manejado por medio de dos botones. Un tercer botón permite al usuario ingresar a una partida de una variación del juego "breakout" permitiendo interactual al usuario con el juego. 
## Objetivos y Alcance
El objetivo del prototipo es el manejo de matrices de dos maneras: por medio de controladores y sin controladores. Permitiendo al usuario experimentar con los mensajes y jugar una variación del juego "breakout". 
## Términos clave
- MAX7219
- Driver
- Matriz LED
- Potenciómetro
# **Materiales y Herramientas**
- Una placa Arduino MEGA
- Un controlador MAX7219: es un circuito integrado que facilita el control de LEDs. Es usado principalmente en pantallas de 7 segmentos, paneles de LEDs industriales y como controlador de matriz de LED con Arduino.
- Matrices LED de 8x8: es un display formado por múltiples LED en distribución rectangular.
- 3 Botones
- Un potenciómetro: es un componente electrónico similar a los resistores pero cuyo valor de resistencia en vez de ser fijo es variable, permitiendo controlar la intensidad de corriente a lo largo de un circuito conectándolo en paralelo ó la caida de tensión al conectarlo en serie.
- Resistencias
- Sounder
# **Montaje del Hardware**
A continuación se explica la conexión entre la placa Arduino MEGA y los demás componentes.
- Conexión para Comunicación Serial: Se utilizaron los pines RXO Y TX0. 
![Proteus Ejecutado](https://gitlab.com/grupo-7-ace1b-1s2023/ACE1-231S0778BG07PRA1/-/tree/main/docs/tech/images/tecnico/instalacion1.jpg)
- Conexión con los botones: se utilizaron los pines 5, 6 y 7.
![Proteus Ejecutado](images\tecnico\instalacion2.jpg)
- Conexión con el sounder: se utilizó el pin 8. <br>
![Proteus Ejecutado](images\tecnico\instalacion3.jpg)
- Conexión con el driver MAX7219: se utilizaron los pines 10, 11 y 13, el pin 10 se conectó con el LOAD del MAX7219, el pin 11 se conectó con el DIN del MAX7219 y el pin 13 se conectó al CLK del MAX7219.
![Proteus Ejecutado](images\tecnico\instalacion4.jpg)
- Conexión con las Matrices LED sin driver: se utilizaron los pines del 30 al 37 para la conexión de las filas y los pines del 40 al 47 para la conexión de las columnas.
![Proteus Ejecutado](images\tecnico\instalacion5.jpg)

A continuación se muestra la conexión entre el driver MAX7219 con la matriz que es manejada por el mismo:
por parte del Driver, se conectó de las salidas A-G y DP, con las columnas y de las salidas DIG0-DIG7 las filas. Adicional a esto de la salida ISET se colocó la alimentación y una resistencia. 
![Proteus Ejecutado](images\tecnico\instalacion6.jpg)
# **Programación del Software**
## Carga del código en la placa Arduino
- Es necesario corroborar que el archivo *.hex* generado en la compilación del archivo con el *IDE Arduino* esté instalado en la placa, para ello debemos dar doble click sobre la placa Arduino y verificar la dirección en el apartado de *PROGRAM FILE*. 
![Program File](images\usuario\instrucciones2.jpg)
![Program File](images\usuario\instrucciones3.jpg)
- De no encontrarse algún archivo seleccionado, es necesario colocar el archivo *.hex*, para ello debemos darle click al ícono de folder en el apartado de *PROGRAM FILE*, esto nos abrirá un selector de archivos, donde debemos buscar la carpeta de nombre *build* el ella se encontrarán 3 archivos, debemos seleccionar el de nombre *src.ino.with_bootloader.hex*
![Program File](images\usuario\instrucciones4.jpg)
## Código
### Manejo del Mensaje de inicio
### Lógica del Juego
### Manejo de botones y apartado de configuración
# **Pruebas y Depuración**
# **Uso y Mantenimiento**
# **Anexos**