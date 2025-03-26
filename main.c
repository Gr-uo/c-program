#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define FILE_NAME "record.txt"
#include <math.h>
#define LIBLARY_FILE "liblary.txt"
#define TEACHER_FILE "teacher.txt"
    typedef struct book{
        int book_id;
        char author[50];
        char title[50];
    }book;
     typedef struct student{
         int Admission_number;
         char name[20];
         float marks;
         char course[30];
         char hobby[20];
         char email[30];
     }student;
     typedef struct teacher{
         int identity_no; //to be able to identify different teachers with number
         char name[30];
         int age;  //for retirement clarification.
         char subject[30]; //teaching subject
         char email[30]; //for better communication
     }teacher;
     void add_book(){  //function to add a book to he system
         book b;
         FILE* file = fopen("LIBLARY_FILE", "a");
         if(!file){
            printf("Error in opening the file.\n");
            return;
         }
         printf("Enter the book id: \n");
         scanf("%d", &b.book_id);
         printf("Enter the book title: \n");
         scanf(" %[^\n]", b.title);
         printf("Enter the book author:\n");
         scanf(" %[^\n]", b.author);
         fprintf(file, "%d,%s,%s", b.book_id,b.title,b.author);
         fclose(file);
     }
     void Add_student(){
         student s;
     int password = 808080;
    printf("Enter password to confirm you are working on this sector.\n");
    scanf("%d", &password);
    if(!password){
    printf("seems like you are not working here.\n");
      exit(0);
    }
    else{
     FILE *file = fopen("FILE_NAME", "a");
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
      fprintf(file, "%d,%s,%f,%s,%s,%s", s.Admission_number, s.name, s.marks, s.course, s.hobby,s.email);
      fclose(file);
      printf("student has been added to the system.\n");
    }
 }
 void displaystudents(){
     student s;
     FILE* file = fopen(FILE_NAME, "r");
     if(!file){
        printf("Error in opening the file maybe there is no student in the system.\n");
        exit(1);
     }
     printf("students in the list are: \n");
     while(fscanf(file, "%d,%19[^,],%f,%29[^,],%19[^,],%29[^,]", s.Admission_number, s.name, s.marks, s.course, s.hobby, s.email) != EOF){
        printf("\nAdmission number:%d\n",s.Admission_number);
        printf("Name :%s", s.name);
        printf("Marks :%f", s.marks);
        printf("Course :%s", s.course);
        printf("Hobby: %s", s.hobby);
        printf("Email: %s", s.email);
        fclose(file);
     }
 }
 void add_a_teacher(){
     teacher t;
     FILE* file = fopen("TEACHER_FILE", "a");
     if(!file){
        printf("Error in opening the file");
        return;
     }
     printf("\nEnter the teacher identity number:\n");
     scanf("%d", &t.identity_no);
     printf("Enter name: \n");
     scanf(" %[^\n]", t.name);
     printf("Enter the age: \n");
     scanf("%d", &t.age);
     printf("Enter the subject you are teaching: \n");
     scanf(" %[^\n]", t.subject);
     printf("Enter your email for better communication: \n");
     scanf(" [^\n]", t.email);
     fprintf(file, "%d,%s,%d,%s,%s", t.identity_no, t.name, t.age, t.subject, t.email);
     fclose(file);
     printf("Teacher has been added successfully.\n");
 }
 void check_for_teacher(){
     teacher t;
     FILE* file = fopen("TEACHER_FILE", "r");
     if(!file){
        printf("It seems like no teacher has been added to system yet.\n");
        return;
     }
     printf("------=teachers details are---------");
     while(fscanf(file, "%d,%29[^,],%d,%29[^,],%29[^,]", t.identity_no, t.name, t.age, t.subject, t.email) != EOF){
        printf("Teacher\'s ID : %d\n", t.identity_no);
        printf("Teacher\'s name: %s\n", t.name);
        printf("Teacher\'s age is: %d\n", t.age);
        printf("Teacher\'s teaching subject is: %s\n", t.subject);
        printf("Teacher\'s email is : %s\n", t.email);
     }
 }
 bool check_qualification(char *grade){
     char a = 'A'; char b ='B'; char c = 'B+'; char d ='C+'; char e = 'B-';
    // if(strcmp(grade, A) == 0|| strcmp(grade, B+) == 0 || strcmp(grade, B)==0 || strcmp(grade, B-)==0 ||strcmp(grade, C+)==0){
    switch(grade){
    case A:
    case B+:
    case B:
    case B-:
    case C+:
        return true;
    default :{
        return false;
    }
    }
 }

int main(){
    char grade;//for checking for qualification
    int choice;
    while(1){
        printf("Enter your choice depending on the department you are working on\n");
        printf("1. Add a new student to the system.\n");
        printf("2. Check for a students details if already on system.\n");
        printf("3. Check if qualified for the institution.\n");
        printf("4. Check for student\' cluster points.");
        printf("5. Attend to book to the liblary.\n");
        printf("6. Check if qualified.\n");
        printf("7. Add a new teacher to the system.\n");
        printf("8. Check for a teachers details.\n");
        printf("9. Search for a teacher in the system.\n");
        printf("10. Exit the program.\n");
        scanf("%d", &choice);
         switch(choice){
        case 1:
            Add_student();
            break;
        case 2:
            displaystudents();
            break;
        case 3:
            printf("Please enter your grade to be examined.\n");
            scanf("%s", &grade);
            if(check_qualification(grade)){
                printf("Congratulations you have qualified for institution");
            }
            else{
                printf("Sorry you haven\'t qualified but you can try one of our diploma courses");
            }
            break;

        case 7:
            add_a_teacher();
            break;
        case 8:
            check_for_teacher();
            break;
        case 10:
            exit(0);
            break;
        default:
                printf("You have entered wrong choice try again.");
         break;
        }
    }
    return 0;
}
