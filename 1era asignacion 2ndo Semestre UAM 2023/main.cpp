#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include "sorting_algorithms.cpp"
#include "utility.cpp"

/*
  Autor: Mario Grillo
  Repositorio: https://github.com/Fletcher17b/Notas-1er.-Corte
  cleanbuffer() y cleanscreen() estan declaradas y definidas en utility.cpp junto con la estructura.
  Todo lo que tiene que ver con ordenar arreglos esta en sorting_algorithms.cpp .
  Se me hace mas familiar la libreria de stdio que iostrem, al final son casi iguales.
  Veo apropiado indicar que parte del codigo escrito en este programa fue rehusado de proyectos en los que he trabajado anteriormente:
    -https://github.com/Fletcher17b/Cycles
    -https://github.com/Fletcher17b/Structs-and-arrays-practice-

   
*/


// obtiene datos del estudiante
student_info get_student_info() {
    cleanbuffer();
    system("cls");
    student_info temp; // struct temporal
    int all_clear_flag = 0; // una bandera, fuerza al while a terminar si la condicion se cumple
      

  while( all_clear_flag != 1) {
   printf("! Numero maximo de caracteres: 30 !\n"); 
   printf("Nombre: ");
   fgets(temp.name,30,stdin);
   cleanbuffer();

   printf("\nApellido: ");
   fgets(temp.last_name,30,stdin);
   cleanbuffer();

   printf("\nNota: ");
   scanf("%f", &temp.grade);
   while (temp.grade > 100 || temp.grade < 0) {
      printf("Valor invalidom intente denuevo\n");
      printf("\nNota: ");
      scanf("%f", &temp.grade);
      cleanbuffer();
   }
   cleanbuffer();

   printf("\nNombre: %s | Apellido %s | Nota: %.2f\n",temp.name,temp.last_name,temp.grade);
   printf("La informacion es corecta? si (1) no (cualquier otra tecla) \n");
   scanf("%d",&all_clear_flag);
   cleanbuffer();
    if(all_clear_flag == 1) {
         printf("\nInformacion guardad correctamente \n");
         cleanscreen();
        break;
    } else {
        cleanscreen();
        break;
    }

  }

   cleanscreen();
   cleanbuffer();

   return temp;
}

// C++ provee "method overloading", por que no usarlo? ¯\_(ツ)_/¯ 
// Se que es OOP pero se me hace mas rapido asi
student_info get_student_info(int student_counter) {
   system("cls"); 
   student_info temp;
   int all_clear_flag = 0;
   cleanbuffer();

   temp.student_number = student_counter;
   
  while( all_clear_flag != 1) {
   cleanscreen();
   printf("! Numero maximo de caracteres: 30 !\n"); 
   printf("Nombre: ");
   fgets(temp.name,30,stdin);
   cleanbuffer();

   printf("\nApellido: ");
   fgets(temp.last_name,30,stdin);
   cleanbuffer();

   printf("\nNota: ");
   scanf("%f", &temp.grade);
   while (temp.grade > 100 || temp.grade < 0) {
      printf("Valor invalidom intente denuevo\n");
      printf("Nota: ");
      scanf("%f", &temp.grade);
      cleanbuffer();
   }
   cleanbuffer();

   printf("\n | Nombre: %s | Apellido %s | Nota: %.2f\n",temp.name,temp.last_name,temp.grade);
   printf("La informacion es corecta? si (1) no (cualquier otra tecla) \n");
   scanf("%d",&all_clear_flag);
   cleanbuffer(); 
    if(all_clear_flag == 1) {
        printf("\n Numero de registro del estudiante es: %d \n", student_counter);
        printf("Informacion guardad correctamente \n");
         cleanscreen();
        break;
    } else {
        cleanscreen();
    }

  }
   cleanbuffer();

   return temp;
}

//Menu para editar
int search_stundent_menu(int cant, student_info studentarray[]) {

    cleanbuffer();
    system("cls");

    int exit =0;
    
    int flag1 = 0;
   
    int number= 0;
    char input[30];
    int selected_student = 0;
    int switch_choice = 0;

    while (exit != 1) {

        printf("Seleccione el metodo de busqueda: \n 1. Numero asignado\n 2. Nombre \n 3. Apellido\n 4. Volver \n");
        scanf("%d",&switch_choice);
        cleanbuffer();
        switch (switch_choice)
        {
        case 1:
            printf("\nPara editar un estudiente inserte su numero asignado: ");
            scanf("%d",&number);
            cleanbuffer();

          for (int n = 0; cant > n; n++ )  {
             if (number == studentarray[n].student_number) {
                printf("\nNombre: %s \nApellido: %s \nNota: %.2f\n",studentarray[n].name,studentarray[n].last_name,studentarray[n].grade);
                printf("Es este su estudiante? Si(1), no (otra tecla) \n");
                scanf("%d",&flag1);
                cleanbuffer();

                 if (flag1 == 1) { 
                    studentarray[n] = get_student_info();
                    return 0;
                 } else {
                    printf("Estudiante no encontrado\n");
                    cleanscreen();
                    cleanbuffer();
                    return 0;
                    break;
                 }

                
             }
          }
            break;
        case 2:
            printf("\n Nombre: ");
            fgets(input,30,stdin);
            cleanbuffer();
            selected_student = search_stundent_name(cant,studentarray, input);
            if (selected_student != -1) {
                studentarray[selected_student] = get_student_info();
            }

            break;

        case 3:
            printf("\n Apellido: ");
            fgets(input,30,stdin);
            cleanbuffer();
            search_student_lastname(cant,studentarray, input);
            selected_student = search_student_lastname(cant,studentarray, input);
             if (selected_student != 1) {
                studentarray[selected_student] = get_student_info();
            }
            break;
        
         case 4:
            cleanscreen();
            return 0;
            break;

        default:
           printf("\nOpcion invalida\n");
           cleanscreen();
            break;
        }
        


    }
    

    return 0;
}

// Saca promedio de los valores registrados en registered_students[]
float get_promedio(int cant, student_info studentarray[]) {
   float prom = 0;
   float total = 0;
     for (int j; j <= cant; j++) {
        total = total + studentarray[j].grade;
     }

     prom = total/cant;

    return prom;
}


int main() {
    student_info registered_students[101]; //array que guarda alumnos registrados
    int student_counter = 0; // cuenta alumnos registrados
    int exit_var1 = 0;   // una bandera, fuerza al while a terminar
    float promedio = 0; // self-explainatory 
   // float sizeofthestruct = sizeof(registered_students)/sizeof(registered_students[0]);
 
     while (exit_var1 != 1)
     {
        system("cls");
        int choice = 0;
        printf("Menu: \n 1. Registrar Estudiante \n 2. Ver nota mas alta  \n 3. Ver nota mas baja \n 4. Ver promedio \n 5. Editar  \n 6. Ver todos (ascendente) \n 7. Ver todos (descendente)\n 8. Salir \n");
        scanf("%d", &choice);
        cleanbuffer();

        switch (choice)
        {
        case 1:
            registered_students[student_counter] = get_student_info(student_counter);
            student_counter++;
            cleanbuffer();
            break;
        case 2:
            if (student_counter == 0) {
                printf("No hay estudiantes registados");
            } else {
                show_highest_grade(student_counter,registered_students);
            }
            
            break;
        case 3:
            if (student_counter == 0) {
                printf("No hay estudiantes registados");
            } else {
                show_lowest_grade(student_counter,registered_students);
            }
            
            break;
        case 4:
         if (student_counter == 0) {
                printf("No hay estudiantes registados");
            } else if (student_counter == 1)
            {
                promedio = get_promedio(student_counter,registered_students);
                printf("El promedio de 1 estudiante es de %.2f", promedio);
                // Veo necesario este elif debido a que hay que seguir las reglas del buen castellano y evitar que decir "... de 1 estudiantes..."
            } else {
                promedio = get_promedio(student_counter,registered_students);
                printf("El promedio de %d estudiantes es de %.2f", student_counter,promedio);
            }
            
            
            break;
        case 5:
            if (student_counter == 0) {
                printf("No hay estudiantes registados");
            } else {
                system("pause");
                search_stundent_menu(student_counter, registered_students); 
            }
            
            break;
        case 6:
         if (student_counter == 0) {
                printf("No hay estudiantes registados");
            } else {
                grade_sort_lowtohigh(student_counter, registered_students);
            }
            
            break;
        case 7:
         if (student_counter == 0) {
                printf("No hay estudiantes registados");
                // Propiedad intelectual de Mario Grillo
            } else {
                grade_sort_hightolow(student_counter, registered_students);
            }
            
            break;
        case 8:
            exit_var1 = 1;
            system("cls"); 
            break;
        default:
        printf("\n Opcion invalida");
        system("pause");
        system("cls");
            break;
        }
     }
     
    return 0;
}