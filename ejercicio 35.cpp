#include <stdlib.h>
#include <stdio.h>

typedef struct{
	char nombre[30];
	char apellido[30];
	int edad;
	long telefono;
	char mail[50];
	void *siguiente;
}persona_t;

typedef struct {
    persona_t dato;
    void *siguiente;
} nodo;

persona_t * primero = NULL;
void cargarDatos();
void imprimir();

int main (){
	
	cargarDatos ();
	imprimir();
	
	return 0;
	
}

void cargarDatos(){
	int a,i;
	a=0;
	i=0;
	
	persona_t * nuevo = (nodo*) malloc(sizeof(nodo));
	
	
	while(a==1){
		printf("ingrese nombre");
		scanf("%s",&nuevo->nombre);
		printf("ingrese apellido");
		scanf("%s",&nuevo->apellido);
		printf("ingrese edad");
		scanf("%d",nuevo->edad);
		printf("ingrese telefono");
		scanf("%f",nuevo->telefono);
		printf("ingrese mail");
		scanf("%s",nuevio->mail);
		nuevo->siguiente = NULL;
		primero = nuevo;
		
		printf("desea ingresar otro registro ? si = 1 / no = 0");
		scanf("%d",&i;)
		a = i;
		
	}
	
	
}

void imprimir(){
	
	FILE * contactos.dat;
	
	contactos.dat = fopen("pacientes.txt", "r");
	
	persona_t * actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	if (primero!=NULL){
		while (actual != NULL){
			if (actual->edad >21){
				fprintf(contactos.dat, primero->dato)
			}
			printf ("%s",actual->nombre);
			printf ("%s",actual->apellido);
			printf ("%d",actual->edad);
			printf ("%f",actual->telefono);
			printf ("%s",actual->mail);
		actual = actual->siguiente;
		}
	}
}
//Hacer un programa que tome los datos de contacto de una persona (Nombre, Apellido, edad, teléfono, mail)
 //y los cargue, en forma directa, en una pila de memoria dinámica.
  //Imprimir en pantalla y cargar en un archivo llamado "contactos.dat", de organización secuencial,
 //los registros ingresados por el usuario si la persona tiene una edad mayor a 21 años.
