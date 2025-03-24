#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "record.dat"
#include <math.h>
     typedef struct student{
         int Admission_number;
         char name[20];
         float marks;
         char course[30];
         char hobby[20];
         char email[30];
     }student;
     student s;
     void Add_student(){
     int password = 808080;
    printf("Enter password to confirm you are working on this sector.\n");
    scanf("%d", &password);
    if(!password){
    printf("seems like you are not working here.\n");
      exit(0);
    }
    else{
     FILE *file = fopen("FILE_NAME", "ab");
     if(!file){
        printf("Error in opening the file");
        exit(1);
     }
     printf("Enter your admission number.\n");
     scanf("%d", &s.Admission_number);
     getchar();
     printf("Enter your name.\n");
     fgets(s.name, sizeof(s.name), stdin);
     s.name[strcspn(s.name, "\n")] = '\0';
     printf("Enter your marks. \n");
     scanf("%f", &s.marks);
     getchar();
     printf("Enter the course you are enrolling for.\n");
     fgets(s.course, sizeof(s.course), stdin);
     s.course[strcspn(s.course, "\n")] = '\0';
     printf("Enter your hobby for sports notification.\n");
     fgets(s.hobby, sizeof(s.hobby), stdin);
     s.hobby[strcspn(s.hobby, "\n")] = '\0';
     printf("enter your email for communication purposes.\n");
     fgets(s.email, 30, stdin);
     s.email[strcspn(s.email, "\n")] = '\0';
      fwrite(&s, sizeof(s), 1, file);
      fclose(file);
      printf("student has been added to the system.\n");
    }
 }
 void check_for_details(){
     FILE* file = fopen(FILE_NAME, "rb");
     if(!file){
        printf("Error in opening the file.\n");
        exit(1);
     }
     student s;
     while(fread(&s, sizeof(s), 1, file)){
        printf("\nAdmission number:%d\n",s.Admission_number);
        printf("Name :%s", s.name);
        printf("Marks :%f", s.marks);
        printf("Course :%s", s.course);
        printf("Hobby: %s", s.hobby);
        printf("Email: %s", s.email);
        fclose(file);
     }
 }

int main(){
    int choice;
    while(1){
        printf("Enter your choice depending on the department you are working on\n");
        printf("1. Add a new student to the system.\n");
        printf("2. Check for a students details if already on system.\n");
        printf("3. Check if qualified for the institution.\n");
        printf("4. Check for student\' cluster points.");
        printf("5. Attend to Liblary services.\n");
        printf("6. Check if qualified.\n");
        printf("7. Exit the program.\n");
        scanf("%d", &choice);
         switch(choice){
        case 1:
            Add_student();
            break;
        case 2:
            check_for_details();
            break;
        case 7:
            exit(0);
            break;
        default:
                printf("You have entered wrong choice try again.");
         break;
        }
    }
    return 0;
}
