//
//  main.c
//  me code
//
//  Created by Steven Hernandez on 8/14/17.
//  Copyright © 2017 Steven Hernandez. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Menu (int opt);


/*BIENVENIDOS A DON SALUDERO */

typedef struct {
    
    char Nombre[20];
    char Laboratorio[20];
    int Costo;
}Products;

void Ingresar (Products Ingreso);
void Listar (Products Ingreso);
void Buscar (Products Ingreso);

FILE *puntero;

int main(void)
{
    Products Ingreso;
    const char CONTRASENA1[] ="admin";
    const char CONTRASENA2[] ="invitado";
    const int numIntentos =3;
    int i;
    char contrasena[100];
    int opcion;
    int opt;
    int count;
    
    do{
        printf("BIENVENIDOS A DON SALUDERO\n\n");
        printf("ELIJA UNA OPCION:\n \n");
        printf("1. Administrador. \n");
        printf("2. Cajero. \n");
        printf("3. Salir. \n");
        scanf("%d",&opcion);
        
        system ("cls");
        
        switch(opcion)
        {
            case 1:{
                for (i=0; i<numIntentos; i++)
                {
                    printf("contrasena: ");
                    scanf("%s", contrasena);
                    
                    system ("cls");
                    
                    if (strcmp(CONTRASENA1, contrasena) != 0)
                    {
                        printf("\t***CONTRASENA INVALIDA***\n\n");
                        continue;
                    }
                    
                    printf("\nBIENVENIDO ADMINISTRADOR\n");
                    
                    break;
                    
                }
                
                if (i == numIntentos)
                {
                    printf("\nPrograma no ejecutado.\n");
                    return 1;
                }
                
                
                
                do{
                    
                    opt= Menu(opt);
                    
                    switch (opt)
                    {
                        case 1:
                            Ingresar(Ingreso);
                            break;
                            
                        case 2:
                            break;
                            
                        case 3:
                            break;
                            
                        case 4:
                            Buscar(Ingreso);
                            break;
                            
                        case 5:
                            Listar(Ingreso);
                            break;
                            
                        case 6:
                            break;
                            
                        //    system ("cls");
                    }
                    
                }while (opt!=7);
                
                
            }
                break;
                
                
            case 2:
            {
                for (i=0; i<numIntentos; i++)
                {
                    printf("contrasena: ");
                    scanf("%s", contrasena);
                    if (strcmp(CONTRASENA2, contrasena) != 0)
                    {
                        printf("\tcontrasena invalida\n");
                        continue;
                    }
                    printf("\nBIENVENIDO CAJERO \n");
                    break;
                }
                if (i == numIntentos)
                {
                    printf("\nPrograma no ejecutado.\n");
                    return 1;
                }
                printf("\nPrograma ejecutando...\n");
            } break;
                
        }
        
    }while(opcion!=3);
    
    return 0;
}



void Ingresar (Products Ingreso)
{
    puntero=fopen ("inventario.txt", "a+");
    
    if(puntero==NULL)
    {
        printf("\n Error al abrir el archivo. \n");
    }
    else
    {
        printf("\n Ingrese el Nombre: \n");
        fflush(stdin);
        gets(Ingreso.Nombre);
        
        
        
        
        printf("\n Ingrese el Laboratorio:\n");
        fflush(stdin);
        gets(Ingreso.Laboratorio);
        
        
        
        
        printf ("\n Ingrese el Costo: \n");
        scanf ("%d", &Ingreso.Costo);
        
        
        
        fwrite(&Ingreso, sizeof(Products), 1, puntero);
        
        
        
        system ("cls");
        return;
    }
    fclose (puntero);
    
    
}



int Menu (int opt)
{
    printf ("\nQue desea hacer\n\n");
    printf ("1. Ingresar\n");
    printf ("2. Eliminar\n");
    printf ("3. Actualizar\n");
    printf ("4. Buscar\n");
    printf ("5. Listar\n");
    printf ("6. Vender\n");
    printf ("7. Salir del programa\n");
    
    scanf ("%d", &opt);
    
    system ("cls");
    
    return opt;
    
}

void Listar (Products Ingreso) {
    
    int cont=0;
    puntero=fopen("inventario.txt", "r");
    if(puntero==NULL)
    {
        printf("\n Error al abrir el archivo o archivo vacio \n");
        return;
    }
    else
    {
        
        printf("Nombre \t\tLaboratorio \tCosto");
        while(!feof(puntero))
        {
            
            
            if(cont==0){
                
                fread(&Ingreso, sizeof(Products), 1, puntero);
                
                printf("\n%s \t%s \t%d\n", Ingreso.Nombre, Ingreso.Laboratorio, Ingreso.Costo);
                
            }
            cont++;
        }
        
    }
    fclose(puntero);
}


void Buscar (Products Ingreso) {
    
    char nom[100];
    
    puntero=fopen("inventario.txt","r");
    
    if (puntero==NULL){
        
        printf("Error en el archivo");
        
        return;
    }
    else{
        
        printf("Digite el nombre que busca: ");
        fflush(stdin);
        gets(nom);
    }
    
    
    
    
    while(!feof(puntero)){
        
        fread(&Ingreso, sizeof(Products), 1,puntero);
        
        
        if(strstr(nom,Ingreso.Nombre)!=NULL)
        {
            printf("\nNombre encontrado: \n\nNombre: %s \nLaboratorio: %s \n Costo: %d",Ingreso.Nombre, Ingreso.Laboratorio, Ingreso.Costo);
            break;
        }
        else{
            printf("\n El medicamento %s no existe", nom);
            break;
        }
        
        
    }
    
    
    
    
    fclose(puntero);
    
   // getch();
    
}
