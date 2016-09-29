#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <alloc.h>
#include <iostream.h>
#define localizar (struct pila *)malloc(sizeof(struct pila))  //IMPORTANTE, busca espacios disponibles

struct pila{
char estudiantes[20];
char cedula[15];
struct pila *pt; //es el nodo o como yo le digo enlace
} *ini=NULL, *fin=NULL; //*ini va a tener el valor del espacio y *fin va a copiarlo para que en la siguiene *ini pueda tener el siguiente valor

void insertar(void);
void eliminar(void);
void mostrar(void);
void main()
{ int op;
 do{ clrscr();
printf("que desea hacer: ");
printf("\n1.INSERTAR\n2.ELIMINAR\n3.MOSTRAR\n"); cin>>op;

switch(op)
{ case 1: insertar();  break;
  case 2: eliminar(); break;
	case 3: mostrar(); break;

}
    } while(op!=4);
 getch();
}

void insertar()
{  ini=localizar;   //busca un espacio vacio

clrscr(); printf("espacio:%d\n",ini);
 printf("ingrese el nombre: "); gets(ini->estudiantes); //guarda el nombre en el espacio buscado
 printf("cedula: ");  gets(ini->cedula);
 printf("\nnombre=%d cedula=%d\n",ini->estudiantes,ini->cedula);   //imprime sus direcciones
 if(fin==NULL)
 { fin=ini;    //fin es igual al espacio buscado
ini->pt=NULL;   printf("\nini->pt=%d",ini->pt);   //inicia el puntero de la estructura en 0
}
 else
{
ini->pt=fin;  printf("\nini->pt=%d\n",ini->pt);  //le asigna pt la ultima direccion conocida
fin=ini;  printf("\nfin=%d",fin);         //y fin ahora tiene el nuevo valor buscado
}
getch();
}

void eliminar()
{ clrscr();
   if (fin==NULL) {return;}
ini=fin;     printf("%d\n",ini);
fin=fin->pt;  printf("fin->pt=%d",fin->pt);
free(ini);

if (fin==NULL)
{ printf("\nla pila no tiene datos"); }
else
{ printf("\nla pila aun tiene datos"); }
getch();
}

void mostrar()
{ clrscr();
   if(fin==NULL){ return; }
   int n=0;
   ini=fin; printf("%d\n\n",ini);
 while(ini!=NULL)
 { printf(ini->estudiantes); cout<<" "; printf(ini->cedula); cout<<"\n";
   printf("%d	%d",ini->estudiantes,ini->cedula);
  n++;
  ini=ini->pt;   printf("	ini->pt=%d\n\n",ini);

     }

 getch();


}
