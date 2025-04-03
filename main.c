#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#define FILE_NAME "record.txt"
#define DISPLINARYFILE "displinary.txt"
#define LIBRARY_FILE "liblary.txt"
#define TEACHER_FILE "teacher.txt"
#define LIBRARY_USER "library_user.txt"
#define LIBRARY_BORROWED_RECORDS "library_records.txt"
int library_id = 1; // declare an integer variable which will be modified in any function for changes
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
void advanced_adminstration_services(){   //function for advanced administration services
    int choice;
    do{
    printf("\n Welcome to advanced administration services please proceed if you have authority only.\n");
    printf(" Enter the choice depending on what you want to do.\n");
    printf("1. Remove a student in the system.\n");
    printf("2. Remove a teacher in the system (retired or transfered).\n");
    printf("3. Calculate a salary for non governmental teacher according to the days he has attended schooling.\n");
    printf("4. Record a student disciplinary case.\n");
    printf("5. Exit the program.\n");
    scanf("%d", &choice);
    switch(choice){
        case 3:
        culclate_salary();
        break;
        case 5:
        exit(0);
        break;
        default:
        printf("You have entered an invalid choice try again.\n");
        break;
    }
    }while(choice != 5);
}
void culclate_salary(){
    float salary_per_day = 1970.65;
struct Date date1; struct Date date2;
    printf("\nEnter the last date you received the salary (dd mm yy)\n");
    scanf(" %d %d %d", &date1.days, &date1.month, &date1.year);
    printf("Enter the current date.\n");
    scanf(" %d %d %d", &date2.days, &date2.month, &date2.year);
    int datediff = datedifference(date1, date2);// call the date calculating function
    float salary = salary_per_day * datediff; // calculate the salary
    printf("Your salary is:  %.2f\n", salary);
}
     void library_services(){ //let's have a library function that will handle all library cases.
         int choice;
         printf("Welcome to the library services enter any choice to proceed");
         do{
           printf("1. Add a book in the library.\n");
           printf("2. Check for the book whether available in library.\n");
           printf("3. Borrow a book form the library.\n");
           printf("4. Pay for library charges if you have exceeded the date appointed.\n");
           printf("5. Return a book in the library.\n");
           printf("6. Register a library user.\n");
           printf("7.Display borrowed books.\n");
           printf("8. Check the number of dates that user has exceeded to apply charges\n");
           printf("9. Delete a book from the library.\n");
           printf("10. Exit from the library services.\n");
           printf("11. Search for a book in the library.\n");
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
            case 6:
               add_library_user();
               break;
           case 10:
            exit(0);
            break;
            default:
                 {
               printf("Invalid choice!!! please try again.\n");
            }
            break;
           }
         }while(choice !=10);
     }
int get_library_id(){
    int user_id = ++library_id;
    return user_id;
}
void add_library_user(){
    student s;
    FILE* ptr = fopen(LIBRARY_USER, "a");
    if(!ptr){
        perror("Error in opening the file.\n");
        return;
    }
    printf("enter the name of student to be added in library user\n");
    scanf(" [^\n]", s.name);
    getchar();
    printf("Enter the student\'s Admission number.\n");
    scanf("%d", &s.Admission_number);
    getchar();
    int library_id = get_library_id();
    scanf("%d", &library_id);
    fprintf(ptr, "%s, %d, %d", s.name, s.Admission_number, library_id);
    fclose(ptr);
    printf("student has been added successful as a library user.\n");
}
void library_charges(){
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
         FILE* file = fopen("LIBRARY_FILE", "a");
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
        while(fscanf(file, "%d,%49[^,],%49[^,]", &b.book_id, b.title, b.author) == 3){
            printf("Book ID is: %d\n", b.book_id);
            printf("Book\'s title is: %s\n", b.title);
            printf("Book\'s author is: %s\n", b.author);
        }
     }
void student_services(){
    int choice;
    do{
    printf("\n Welcome to student services. Enter the choice according to what you want to do.\n");
    printf("1. Add a student to the system.\n");
    printf("2. Check for a students details if available in the system.\n");
    printf("3. Check if qualified for the institution.\n");
    printf("4. Calculate a student\'s cut-off points.\n");
    printf("5. Exit the program.\n");
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
        case 4:
        culclate_cut_off_points();
        break;
        case 5:
        exit(0);
        break;
        default:
        printf("Invalid choice try again\n");
        break;
    }
    }while(choice != 5);
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
     FILE *file = fopen(FILE_NAME, "a");
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
void culclate_cut_off_points(){
    float a, b, c, d, e, f, g, h;
    printf("\nEnter the points for the four core subject of the course you are enrolling on(i.e A= 12, B+ =10 in that order).\n");
    scanf(" %f %f %f %f", &a, &b, &c, &d);
    printf("Enter the points for the remaining subjects.\n");
    scanf(" %f %f %f %f", &e, &f, &g, &h);
    float coresubjects = a + b + c + d;
    float allSubjects = coresubjects + (e + f + g + h);
    float firstculclation = 48 / coresubjects;
    float secondculclation = 84 / allSubjects;
    float thirdculclation = firstculclation * secondculclation;
    float answer = sqrt(thirdculclation) * 48.000;
    printf("Your cut off point is: %.7f you can use it to check for courses that you are qualified for.\n", answer);
}
 void displaystudents(){
     student s;
     FILE* file = fopen(FILE_NAME, "r");
     if(file == NULL){
        perror("Error in opening the file maybe there is no student in the system.\n");
        exit(1);
     }
     printf("students in the list are: \n");
     while(fscanf(file, "%d,%19[^,],%f,%29[^,],%19[^,],%29[^,]", &s.Admission_number, s.name, &s.marks, s.course, s.hobby, s.email) ==6){
        printf("\nAdmission number:%d\n",s.Admission_number);
        printf("Name :%s\n", s.name);
        printf("Marks :%f\n", s.marks);
        printf("Course :%s\n", s.course);
        printf("Hobby: %s\n", s.hobby);
        printf("Email: %s\n", s.email);
     }
     fclose(file);
 }
void teachers_services(){
    int choice;
    printf("\n Welcome to services teachers available in the system. Enter a choice depending on what you want\n");
    printf("1. Add a teacher to the system.\n");
    printf("2. Check for a teacher\'s details if he/she is in the system\n");
    printf("3. Remove a teacher from system (old age or transfered).\n");
    printf("4. Exit the program.\n\n");
        scanf("%d", &choice);
    switch(choice){
        case 1:
        add_a_teacher();
         break;
        case 2:
        check_for_teacher();
         break;
//        case 3:
        case 4:
        exit(0);
         break;
        default:
        printf("The choice you have entered is not among the choices. Try again\n");
        break;
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
     while(fscanf(file, "%d,%29[^,],%d,%29[^,],%29[^,]", &t.identity_no, t.name, &t.age, t.subject, t.email) != EOF){
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
        //lemme form a function that will cutter for activities classified together instead of overloading the main function
        printf("\nEnter your choice depending on the department you are working on\n\n");
        printf("1. attend to student services.\n");
        printf("2. Attend teachers services.\n");
        printf("3. Attend to the services in the library.\n");
        printf("4. Advanced administration services. \n");
        printf("5. Exit the program.\n");
        scanf("%d", &choice);
         switch(choice){
        case 1:
            student_services();
            break;
        case 2:
            teachers_services();
            break;
        case 3:
            library_services();
            break;
        case 4:
             advanced_adminstration_services();
             break;
        case 5:
            exit(0);
            break;
        default:
                printf("You have entered wrong choice try again.\n");
         break;
        }
    }
    return 0;
}
