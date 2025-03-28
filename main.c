#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#define FILE_NAME "record.txt"
#include <math.h>
#define LIBRARY_FILE "liblary.txt"
#define TEACHER_FILE "teacher.txt"
#define LIBRARY_USRE "library_user.txt"
#define LIBRARY_BORROWED_RECORDS "library_records.txt"
    typedef struct book{
        int book_id;
        char author[50];
        char title[50];
    }book;
    struct Date{
     int days;
     int month;
     int year;
    };
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
     void library_services(){ //let's have a library function that will handle all library cases.
         int choice;
         printf("Welcome to the library services enter any choice to proceed");
         do{
           printf("1. Add a book in the library.\n");
           printf("2. Check for the book whether available in library.\n");
           printf("3. Borrow a book form the library.\n");
           printf("4. Pay for library charges.\n");
           printf("5. Return a book in the library.\n");
           printf("6. Register a library user.\n");
           printf("10. Check the number of dates that user has exceeded to apply charges");
           printf("7. Delete a book from the library.\n");
           printf("8. Exit from the library services.\n");
           printf("9. Search for a book in the library.\n");
           scanf("%d", &choice);
           switch(choice){
           case 1:
            add_book();
            break;
           case 2:
            display_books();
            break;
               case  4:
               library_charges();
               break;
           case 8:
            exit(0);
            break;
            default:
                 {
               printf("Invalid choice!!! please try again.\n");
            }
            break;
           }
         }while(choice !=8);
     }
void libray_charges(){
    float charge_per_day = 4.956070; // charge per day
    int no_of_days = check_no_of_days();//call check_no_of_days and store the result in the no_of_days variable
    float charges = charge_per_day * no_of_days;  //multiply it by charge per day.
    printf("Your Library overall bill is: %.2f\n", charges);
    return;
}
int leap_year_check(int year){
    if((year % 4 == 0 && year % 100 != 0)|| (year % 400 == 0))return 1;
     else return 0;
}
int get_days_in_month(int month, int year){
    switch(month){
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return leap_year_check(year)? 29 : 28;
    default:
        return 0;
    }
}
int datedifference(struct Date date1, struct Date date2){
    int totaldays1 = numberofdays(date1);
    int totaldays2 = numberofdays(date2);
    return abs(totaldays2 - totaldays1); // it will return absolute value hence will prevent getting negative answers.
}
int numberofdays(struct Date date){
 int totalDays = 0;
 // add the number of days before the given year
 for(int i = 1; i < date.year; i++){
    totalDays += leap_year_check(date.year)? 366: 365;
 }
 for (int i = 1; i < date.month; i++) {
        totalDays += get_days_in_month(i, date.year);
 }
 totalDays += date.days; // add days to it to get the total number of days
 return totalDays; // to be used by function that called or caller
}
int check_no_of_days(){
    struct Date date1; struct Date date2;
    printf("Enter the date month and year which you borrowed the book(DD MM YY)\n");
    scanf("%d %d %d", &date1.days, &date1.month, &date1.year);
    getchar(); // to consume the white spaces left possibly by scanf
    printf("Enter the date month and year which you returned the book(DD MM YY)\n");
    scanf("%d %d %d", &date2.days, &date2.month, &date2.year);
     int no_of_days = datedifference(date1, date2);
     return no_of_days;
}
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
     void display_books(){
         book b;
         FILE *file = fopen(LIBRARY_FILE, "r");
         if(file == NULL){
            printf("Unable to open the file maybe there isn\'t book available. \n");
            return;
         }
        printf("----BOOKS IN THE LIBRARY ARE-------\n");
        while(fscanf(file, "%d,%49[^,],%49[^,]", b.book_id, b.title, b.author) == EOF){
            printf("Book ID is: %d\n", b.book_id);
            printf("Book\'s title is: %s\n", b.title);
            printf("Book\'s author is: %s\n", b.author);
        }
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
 void check_qualification(){
   char grade;
    printf("Enter the grade to be examined.\n");
    scanf(" %c", &grade);
    if(grade == 'A' || grade == 'B' || grade == 'C' || grade == 'B+' || grade == 'C+' || grade == 'A-'){
        printf("Congratulations have qualified for the institution.\n");
        exit(0);
    }
    else{
        printf("Sorry you does not qualify for the institution but you can still one of our diploma courses.\n");
    }
 }

int main(){
   //char grade;//for checking for qualification
    int choice;
    while(1){
        printf("\nEnter your choice depending on the department you are working on\n");
        printf("1. Add a new student to the system.\n");
        printf("2. Check for a students details if already on system.\n");
        printf("3. Check if qualified for the institution.\n");
        printf("4. Check for student\' cluster points.");
        printf("5. Attend to the services in the library.\n");
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
            check_qualification();
            break;
        case 5:
            library_services();
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
