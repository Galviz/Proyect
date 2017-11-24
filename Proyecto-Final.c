#include <stdio.h>
#include <stdlib.h>

void pause()
{
	fflush(stdin);
}
void clear()
{
	system("cls");
}

struct liga
{
	char nombre[50];
	int victorias;
	int derrotas;
};

struct baloncesto
{
	struct liga datos;
	int perdidasBalon;
	char nombreMejorAnotador[50];
	int triples;
	int rebotes;
	
};
struct futbol
{
	struct liga datos;
	int empates;
	int golFavor;
	int golContra;
	char goleador[50];
	int golesGoleador;
};



void ingresarDatosBal(struct baloncesto* a);
void ingresarDatosFut(struct futbol* a);
void regresarDatosBal(struct baloncesto a);
void regresarDatosFut(struct futbol a);
void triplista(struct baloncesto a[], int i);
void equipoganador(struct baloncesto a[], int i);
void maximogoleador(struct futbol a[], int i);
void mejorEquipo(struct futbol a[], int i);


int main() 
{
	int i, j, opcion;

	printf("Ingresa el numero de equipos pertenecientes a la liga: \n");
	scanf("%d", &i); 
	
	printf("Elije una de las siguentes opciones para continuar:\n\t1- Liga baloncesto\n\t2-Liga futbol\n");
	scanf("%d", &opcion);

	
	
		struct baloncesto equiposBasket[i];
		struct futbol equiposFutbol[i];
	
		switch(opcion)
	{
		case 1:
			for (j = 0; j < i; j++)
			{
				ingresarDatosBal(&equiposBasket[j]);
			}
			
			printf("\n\nInformacion de los equipos: \n");

			for (j = 0; j < i; j++)
			{
				regresarDatosBal(equiposBasket[j]);
			}
			
			printf("\n\n\nInformacion de la liga:\n");

			triplista(equiposBasket, i); 
				
			equipoganador(equiposBasket, i); 
		break;
		case 2: 
			for (j = 0; j < i; j++)
			{
				ingresarDatosFut(&equiposFutbol[j]);
			}
			printf("\n\nInformacion de los equipos: \n");

			for (j = 0; j < i; j++)
			{
				regresarDatosFut(equiposFutbol[j]);
			}

			printf("\n\n\nInformacion de la liga:\n");

			maximogoleador(equiposFutbol, i); 

			mejorEquipo(equiposFutbol, i);		
		break;
		default:
			printf("Opcion incorrecta, vuelve a correr el programa.\n");
		break;
	}
	pause();
	
	return 0;
}


void ingresarDatosBal(struct baloncesto* a)
{

	printf("Baloncesto \n");
	fflush(stdin);
	printf("Ingrese el nombre del equipo: ");
	gets(a->datos.nombre);
	fflush(stdin);
	printf("Ingrese el numero de victorias del equipo: ");
	scanf("%d",&a->datos.victorias);
	fflush(stdin);
	printf("Ingrese el numero de derrotas del equipo: ");
	scanf("%d",&a->datos.derrotas);
	fflush(stdin);
	printf("Ingrese las perdidas de balon: ");
	scanf("%d",&a->perdidasBalon);
	fflush(stdin);
	printf("Ingrese el numero de rebotes: ");
	scanf("%d",&a->rebotes);
	fflush(stdin);
	printf("Ingrese el nombre del mejor anotador: ");
	gets(a->nombreMejorAnotador);
	fflush(stdin);
	printf("Ingrese el numero de anotaciones: ");
	scanf("%d",&a->triples);
	fflush(stdin);
	

	printf("\n\n\n");
	return;
}


void regresarDatosBal(struct baloncesto a)
{

	printf(" ");
 	
 	printf("\nNombre del equipo: %s",a.datos.nombre);
 	printf("\nNumero de victorias: %d",a.datos.victorias);
 	printf("\nNumero de derrotas: %d",a.datos.derrotas);
 	printf("\nNumero de perdidas de balon: %d",a.perdidasBalon);
 	printf("\nNumero de rebotes: %d",a.rebotes);
 	printf("\nNombre del maximo anotador: %s",a.nombreMejorAnotador);
 	printf("\nNumero de Triples: %d",a.triples);

 	printf("\n\n\n\n");
	return;
}


void triplista(struct baloncesto a[], int i){
	int j;
	for (j = 0; j < i; j++)
	{
		printf("El mejor triplista del equipo '%s': %s\n", a[j].datos.nombre, a[j].nombreMejorAnotador);
	}
	return;
}


void equipoganador(struct baloncesto a[], int i)
{

	int change=0, j;
	struct baloncesto tmp; 
	do
	{
		change=0; 
		for (j = 1; j <= (i-1); j++)
		{
			if (a[j-1].datos.victorias>a[j].datos.victorias)	
			{													
				tmp=a[j];										 
				a[j]=a[j-1];									
				a[j-1]=tmp;
				change=1; 
			}
		}
	}while(change==1);

		printf("El equipo %s es el campeon de la liga.\n", a[i-1].datos.nombre);
	return;
}


void ingresarDatosFut(struct futbol* a)
{

	printf("Futbol \n");
	fflush(stdin);
	printf("Ingrese nombre del equipo: ");
	gets(a->datos.nombre);
	fflush(stdin);
	printf("Ingrese el numero de victorias del equipo: ");
	scanf("%d",&a->datos.victorias);
	fflush(stdin);
	printf("Ingrese el numero de derrotas del equipo: ");
	scanf("%d",&a->datos.derrotas);
	fflush(stdin);
	printf("Ingrese los empates: ");
	scanf("%d",&a->empates);
	fflush(stdin);
	printf("Ingrese el numero de goles a favor: ");
	scanf("%d",&a->golFavor);
	fflush(stdin);
	printf("Ingrese el numero de goles en contra: ");
	scanf("%d",&a->golContra);
	fflush(stdin);
	printf("Ingrese el nombre del mejor goleador: ");
	gets(a->goleador);
	fflush(stdin);
	printf("Ingrese el numero de goles del goleador: ");
	scanf("%d",&a->golesGoleador);
	fflush(stdin);
	
	printf("\n\n\n");
	return;
}


void regresarDatosFut(struct futbol a)
{

	printf("\nNombre del equipo: %s",a.datos.nombre);
	printf("\nNumero de victorias: %d",a.datos.victorias);
	printf("\nNumero de derrotas: %d",a.datos.derrotas);
	printf("\nNumero de empates: %d",a.empates);
	printf("\nNumero de goles a favor: %d",a.golFavor);
	printf("\nNumero de goles en contra: %d",a.golContra);
	printf("\nNombre del mejor goleador: %s",a.goleador);
	printf("\nNumero de goles del goleador: %d",a.golesGoleador);

	printf("\n\n\n\n");
	return;
}


void maximogoleador(struct futbol a[], int i)
{
	int change=1, j;
	struct futbol tmp;
	do
	{
		change=1;
		for (j = 1; j <= (i-1); j++)
		{
			if (a[j-1].golesGoleador>a[j].golesGoleador)
			{
				tmp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;
				change=0;
			}
		}
	}while(change==0);
		
	printf("El goleador  '%s' del '%s' es el maximo goleador.\n", a[i-1].goleador, a[i-1].datos.nombre);
	return;
}


void mejorEquipo(struct futbol a[], int i)
{

	int totales[i][2], g, tot, nombreGanador, puntosGanador;

	for (g = 0; g < i; g++)
	{
		totales[g][0]= g; 
		tot =0;
		tot = (a[g].empates)+((a[g].datos.victorias)*3);	
		totales[g][1]= tot; 
	}

	int change=1, j;
	int tmp[2];


	do
	{
		change=0;
		for (j = 1; j <= (i-1); j++)
		{
			if (totales[j-1][1]<totales[j][1]) 
			{
				tmp[0]=totales[j][0];
				tmp[1]=totales[j][1];

				totales[j][0]=totales[j-1][0];
				totales[j][1]=totales[j-1][1];
				totales[j-1][0]=tmp[0];
				totales[j-1][1]=tmp[1];
				change=1;
			}
		}
	}while(change==1);

	nombreGanador = totales[0][0];
	puntosGanador = totales[0][1];

	printf("El campeon de la liga es %s con %d puntos.\n", a[nombreGanador].datos.nombre,puntosGanador);
}
