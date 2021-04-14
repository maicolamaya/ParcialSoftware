#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//-------------------------------//
//-- Tabla Seguro de Vehiculos --//
//-------------------------------//


/*Contenido de la tabla*/

typedef struct {
	char *seguro[80];
	char *aseguradora[80];
	char *marca[80];
	char *modelo[80];
	char *asegurado[80];
	long int polizaID;
	char *tipoDoc[6];
	int tipoVeh;
	float valorpoliza;
	float valorbien;
}Vehiculo;
 

//Estructura de cada nodo
typedef struct nodo{
	Vehiculo veh;
	struct nodo *sig;
}Nodo;

Nodo* insertarvehiculo(Nodo*, Vehiculo);
void imprimirLista(Nodo*);

int main(){
	Nodo *lista=NULL;

	int opcion=0;
	char *seguro=NULL;
	char *aseguradora=NULL;
	char *marca=NULL;
	char *modelo=NULL;
	char *asegurado=NULL;
	long int polizaID=0.0;
	char *tipoDoc=NULL;
	int tipoVeh=0;
	float valorpoliza=0.0;
  float valorbien=0.0;
	
	Vehiculo *temp=NULL;

	//Datos Vehiculo
	while(opcion!= 6){
		system("clear");
		printf("-----------------------------------\n");
		printf("-- BIENVENIDO AL MENU DE USUARIO --\n");
		printf("-----------------------------------\n\n");
		printf("1.  Leer archivo\n");
		printf("2.	Insertar vehiculo\n");
		printf("3.	Borrar vehiculo\n");
		printf("4.	Buscar vehiculo\n");
		printf("5.	Filtros\n");
		printf("6.	Salir\n");
		printf("\nDigite una opcion: ");
		scanf("%d", &opcion);
		
			switch(opcion){
				case 1:
						system("clear");
						printf("-------------------------------\n");
						printf("---------Leer archivo----------\n");
						printf("-------------------------------\n");
						printf("-------------------------------\n");
						printf("---------Archivo leido---------\n");
						printf("-------------------------------\n");
						break;
				case 2:
						getchar();
						system("clear");
						temp=(Vehiculo*)malloc(sizeof(Vehiculo));
						seguro=(char*)malloc(sizeof(char)*2);
						aseguradora=(char*)malloc(sizeof(char)*80);
						marca=(char*)malloc(sizeof(char)*80);
						asegurado=(char*)malloc(sizeof(char)*80);
						tipoDoc=(char*)malloc(sizeof(char)*3);
						printf("-------------------------------\n");
						printf("-------Insertar vehiculo-------\n");
						printf("-------------------------------\n");
						printf("Digite si posee seguro (y/n): ");
						//scanf("%s",seguro);
						fgets(seguro,2,stdin);
						printf("Digite el nombre de la empresa aseguradora: ");
						//scanf("%*c%[^\n]",aseguradora);
						fgets(aseguradora,80,stdin);
						printf("Digite la marca del vehiculo: ");
						//scanf("%s",marca);
						fgets(marca,80,stdin);
						printf("Digite modelo del vehiculo: ");
						//scanf("%s",modelo);
						fgets(modelo,80,stdin);
						printf("Digite nombre del propietario: ");
						//scanf("%*c%[^\n]",asegurado);
						fgets(asegurado,80,stdin);
						printf("Digite ID poliza: ");
						scanf("%ld",&polizaID);
						getchar();
						printf("Digite tipo de documento(CC,TI,NIT): ");
						//scanf("%s",tipoDoc);
						fgets(tipoDoc,3,stdin);
						printf("Digite tipo de vehiculo:\nCamioneta(1)\nCamion(2)\nBus(3)\nSedan(4)\nMotos(5)\nTipo: ");
						scanf("%d",&tipoVeh);
						printf("Ingrese el valor de la poliza: ");
						scanf("%f",&valorpoliza);
						printf("Ingrese el valor asegurado del bien: ");
						scanf("%f",&valorbien);
						lista=insertarvehiculo(lista,*temp);
						temp->polizaID=polizaID;
						temp->tipoVeh=tipoVeh;
						temp->valorpoliza=valorpoliza;
						temp->valorbien=valorbien;
						strncpy(*temp->seguro,seguro,strlen(*seguro));
						strncpy(*temp->aseguradora,aseguradora,strlen(*aseguradora));
						strncpy(*temp->marca,marca,strlen(*marca));
						strncpy(*temp->modelo,modelo,strlen(*modelo));
						strncpy(*temp->asegurado,asegurado,strlen(*asegurado));
						strncpy(*temp->tipoDoc,tipoDoc,strlen(*tipoDoc));
						free(seguro);
						free(aseguradora);
						free(marca);
						free(modelo);
						free(asegurado);
						free(tipoDoc);
						temp=NULL;
						break;
				case 3:
						break;
				case 4:
						break;
				case 5:
						imprimirLista(lista);
						getchar();
						break;
				case 6:
						printf("Hasta luego!\n");
						break;
				default:
						break;
			}
		getchar();
	}	

	return 0;
}
//--------------------------------------//
//--------Definicion de Funciones-------//
//--------------------------------------//
Nodo *insertarvehiculo(Nodo *lista, Vehiculo veh){
	Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
	strncpy(nuevo->veh.seguro,veh.seguro,strlen(veh.seguro));
	strncpy(nuevo->veh.aseguradora,veh.aseguradora,strlen(veh.aseguradora));
	strncpy(nuevo->veh.marca,veh.marca,strlen(veh.marca));
  strncpy(nuevo->veh.modelo,veh.modelo,strlen(veh.modelo));
	strncpy(nuevo->veh.tipoDoc,veh.tipoDoc,strlen(veh.tipoDoc));
	nuevo->veh.polizaID=veh.polizaID;
	nuevo->veh.tipoVeh=veh.tipoVeh;
	nuevo->veh.valorpoliza=veh.valorpoliza;
	nuevo->veh.valorbien=veh.valorbien;
	nuevo->sig=lista;
	return nuevo;
}

void imprimirLista(Nodo *lista){
	printf("-------------------------------\n");
	printf("----Contenido Base de Datos----\n");
	printf("-------------------------------\n");
	int cont=0;
	if(lista==NULL){
		printf("Error!\nLista vacia\n");
		exit(EXIT_FAILURE);
	}
	
	for(Nodo* p=lista; p!=NULL; p=p->sig){
		printf("----------------------------------\n");
		printf("-----------Vehiculo %d------------\n",cont+1);
		printf("----------------------------------\n");
		printf("Seguro: %s\n",p->veh.seguro);
		printf("Aseguradora: %s\n",p->veh.aseguradora);
		printf("Marca: %s\n",p->veh.marca);
		printf("Modelo: %s\n",p->veh.modelo);
		printf("Propietario: %s\n",p->veh.asegurado);
		printf("ID Poliza: %ld\n",p->veh.polizaID);
		printf("Tipo de Documento: %s\n",p->veh.tipoDoc);
		printf("Tipo de Vehiculo: %d\n",p->veh.tipoVeh);
		printf("Valor Poliza: %f\n",p->veh.valorpoliza);
		printf("Valor asegurado del bien: %f\n",p->veh.valorbien);
		printf("----------------------------------\n\n");
		cont++;
	}
}
		











