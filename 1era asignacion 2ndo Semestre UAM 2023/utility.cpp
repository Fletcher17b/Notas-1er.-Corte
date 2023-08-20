#pragma once

/*
    Funciones que se utilizan en ambos archivos
*/

// Struct principal 
typedef struct {
     int student_number;
     char name[30];
     char last_name[30];
     float grade;
} student_info;

// Limpia los buffers, necesario al usar stdio
void cleanbuffer() {
    fflush(stdin);
    fflush(stdout);
}
// funcion estetica, pause y limpia pantalla
void cleanscreen() {
    system("pause");
    system("cls");
}

// tostring
int printall(student_info studentarray[101], int student_counter) {
    for (int n = 0; student_counter > n; n++ )  {
                printf("\nname: %s \nlast_name %s \ngrade: %.2f\n",studentarray[n].name,studentarray[n].last_name,studentarray[n].grade);
                system("pause");
          }
    return 0;
}
