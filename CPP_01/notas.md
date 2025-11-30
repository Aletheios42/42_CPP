# CPP_MODULE_01

## Ejercicios:
### ex00:  BraiiiiiiinnnzzzZ
Implementar una clase zombie
### ex01: Moar brainz!
Allocar varios zombies en memoria, tener cuidado con las llamadas implicitas al constructor
### ex02: HI THIS IS BRAIN
Printear por pantalla punteros, referencias y valores
### ex03: Unnecessary violence
Crear varias clases y utilizar constroctures dento de contructores, esencial entender referencias y setters
### ex04: Sed is for losers
Aprender los metodos de string, en especial, find, erase e insert
### ex05: Harl 2.0
Consiste en seleccionar un metodo miembro de una clase gracias al uso de punteros
### ex06: Harl filter
Consiste en ejecutar varios metodo miembro de una clase.

## Conceptos Aprendidos
- Memoria Dinamica: en cpp se utiliza new y delete para manejar la memoria.
``` cpp
int *ptr;
Zombie *zombie = New Zombie();
delete zombie;
new prt;
delete ptr;
```
- referencia: no es una copia, es un alias a una variable ya existente, es inmutable es decir no podra apuntarse a otra refenecia y siempre tiene que guardar una dirección de memoria válida.
``` cpp
int valor = 10;
int &refValor = valor;
refValor = 20;
// ahora valor = 20;
```
- Archivos: 
para crear o escribir archivos:
``` cpp
  ofstream myFile("filename.txt")
  myFile << "content";
  myFile.close();
```
para leer archivos:
``` cpp
  std::string line;
  ifstream myReadFile("filename.txt");
  while (getline (myReadFile, myText)
  {
  	std::cout << line << std::endl;
  }
  myReadFile.close();
```
