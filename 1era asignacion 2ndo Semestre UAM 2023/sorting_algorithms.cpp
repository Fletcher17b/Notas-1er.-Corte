#pragma once
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include "utility.cpp"

/*
    Bubblesort fue usado para ordenar por que es el mas sencillo, se que quicksort es mas eficiente pero ¯\_(ツ)_/¯

    Bubblesort funciona mediante 2 ciclos "for" y un condicional, exterior se dezplaza por el arreglo agarrando un elemento, el interior agarra el elemento anterior al escojido p
    or el for exterior, el condicional compara ambos valores y los intercambia si la condicion se cumple. Esto continua hasta que no haya mas elementos que agarrar. 

*/

// Busca alumno por nombre en registered_students[]
int search_stundent_name(float cant, student_info studentarray[], char input[30]) {
    int comparator = 1;
    int flag1 = 0;
    int n = 0;

    for (n = 0 ; cant > n; n++ ) {
        comparator = strcmp(input,studentarray[n].name);

        if (comparator == 0) {
            printf("\n | Nombre: %s | Apellido %s \n",studentarray[n].name,studentarray[n].last_name);
                printf("Es este su estudiante? Si(1), no (otra tecla)\n");
                scanf("%d",&flag1);
                cleanbuffer();

                 if (flag1 == 1) { 
                    cleanscreen();
                    return n;
                 } 
        } 
    }

    if (n == cant) {
        printf("Estudiante no encontrado\n");
        cleanscreen();
        cleanbuffer();
        return -1;
    } 

    return -1;
}

// Busca alumno por apellido en registered_students[]
int search_student_lastname(float cant, student_info studentarray[], char input[30]) {
    int comparator = 1;
    int flag1 = 0;
    int n = 0;

    for (n =0; cant > n; n++ ) {
        comparator = strcmp(input,studentarray[n].last_name);

        if (comparator == 0) {
            printf("\n | Nombre: %s | Apellido %s \n",studentarray[n].name,studentarray[n].last_name);
                printf("Es este su estudiante? Si(1), no (otra tecla)\n");
                scanf("%d",&flag1);
                cleanbuffer();

                 if (flag1 == 1) { 
                    cleanscreen();
                    return n;
                 } 
 
        } 
    }

     if (n == cant) {
        printf("Estudiante no encontrado\n");
        cleanscreen();
        cleanbuffer();
        return 1;
    } 

    return 1;
}

// ordena localmente registered_students[] segun el valor de la nota, de mas baja a mas alta
void grade_sort_lowtohigh(int cant, student_info studentarray[]) {
student_info swaper;


    for (int i=0; i < cant ; i++) {

        for (int u=0; u < cant-1; u++) {
            if (studentarray[u].grade > studentarray[u+1].grade) { 
               swaper = studentarray[u];
               studentarray[u] = studentarray[u+1];
               studentarray[u+1] = swaper;
            }
        }
     }

   for (int n = 0; cant > n; n++ )  {
                printf("\n | Nombre: %s | Apellido: %s | Nota: %.2f\n",studentarray[n].name,studentarray[n].last_name,studentarray[n].grade);
                system("pause");
          }
    
}

// ordena localmente registered_students[] segun el valor de la nota, de mas alta a mas baja
void grade_sort_hightolow(int cant, student_info studentarray[]) {
student_info swaper;


    for (int i=0; i < cant; i++) {

        for (int u=0; u < cant -1; u++) {
            if (studentarray[u].grade < studentarray[u+1].grade) { 
               swaper = studentarray[u];
               studentarray[u] = studentarray[u+1];
               studentarray[u+1] = swaper;
            }
        }
     }

   for (int n = 0; cant > n; n++ )  {
                printf("\n | Nombre: %s | Apellido: %s | Nota: %.2f\n",studentarray[n].name,studentarray[n].last_name,studentarray[n].grade);
                system("pause");
          }
    
}

// Muestra el menor valor de registered_students[].grades en el arreglo dado
void show_lowest_grade(int cant, student_info studentarray[]) {
 student_info swaper;


    for (int i=0; i < cant ; i++) {

        for (int u=0; u < cant-1; u++) {
            if (studentarray[u].grade > studentarray[u+1].grade) { 
               swaper = studentarray[u];
               studentarray[u] = studentarray[u+1];
               studentarray[u+1] = swaper;
            }
        }
     }
     printf("\n Nota mas baja:");
     printf("\n | Nombre: %s | Apellido: %s | Nota: %.2f\n",studentarray[0].name,studentarray[0].last_name,studentarray[0].grade);
     system("pause");
}

// Muestra el mas alto valor de registered_students[].grades en el arreglo dado
void show_highest_grade(int cant, student_info studentarray[]) {
 student_info swaper;


    for (int i=0; i < cant; i++) {

        for (int u=0; u < cant-1; u++) {
            if (studentarray[u].grade < studentarray[u+1].grade) { 
               swaper = studentarray[u];
               studentarray[u] = studentarray[u+1];
               studentarray[u+1] = swaper;
            }
        }
     }
     printf("\n Nota mas alta:");
     printf("\n | Nombre: %s | Apellido: %s | Nota: %.2f\n",studentarray[0].name,studentarray[0].last_name,studentarray[0].grade);
     system("pause");
}