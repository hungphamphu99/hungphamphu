#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
typedef struct date {
    int day;
    int month;
    int year;
} date;

typedef struct student{
    char fullname[1000];
    char studentID[50];
    char firstName[20];
    char lastName[10];
    date birthday;
    float algebra, calculus, basic_program, GPA;
} student;
void reverseString(char* str) {
    int len = strlen(str);
    int i;
    char tmp;
    for (i = 0; i < len/2; i++) {
        tmp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = tmp;
    }
}
// prompts the user to enter student's information
void enterInfor (student *st){
    printf("\n Student ID: "); scanf("%s", st->studentID);
    printf("\n Student's full name: ");
        scanf(" %[^\n]",st->fullname); 
     
    int len = strlen(st->fullname); 
    int i;
    for(i = len-1; i >= 0; i--){
        if(st->fullname[i] == ' ') break; //Check if a space character is encountered, we will stop the loop
        st->firstName[len-i-1] = st->fullname[i]; //len-i-1 is taking the symmetry of i, now it will run from 0, 1, 2, 3....
    }
     
    reverseString(st->firstName); //String reverse function
    for(i = 0; i <=len; i++){
        if(st->fullname[i] == ' ') break; 
        st->lastName[i] = st->fullname[i]; 
    }
        
 // prompts the user to enter the birth date (day, month, year)
    printf("\n Student'birthdate: \n"); 
    printf("day:\n");scanf("%d",&st->birthday.day);
    printf("month\n"); scanf("%d",&st->birthday.month); 
    printf("year:\n");scanf("%d",&st->birthday.year);

// prompts the user to enter the grades for 3 subjects
    printf("\n Overall grade of Algebra: "); scanf("%f",&st->algebra);
    printf("\n Overall grade of Calculus: "); scanf("%f",&st->calculus);
    printf("\n Overall grade of Basic Programming: "); scanf("%f",&st->basic_program);
}

void printStudent (student st){
    printf("|%10s \t |%20s \t|%12d/%2d/%4d \t |%8.2f \t |%8.2f \t |%17.2f \t |%5.2f|\n", st.studentID,st.fullname,st.birthday.day,st.birthday.month,st.birthday.year,st.algebra,st.calculus,st.basic_program,st.GPA);
   
}

void calculateGpa (student *st){
    st->GPA= (st->calculus+ st->algebra + st->basic_program)/3;
}

void noStudent(student lst[],int *n){
    do {
        printf("How many students do you want to enter?\n");
        scanf("%d", n);
    } while (*n <= 0 || *n > 1000);

    for (int i = 0; i < *n; i++) {
        printf("\nStudent %d: ", i + 1);
        enterInfor(&lst[i]);
        calculateGpa(&lst[i]);
    }
}

void printToScreen(student lst[],int n){
    printf("\n");
    for (int i= 0; i<128 ;i++)
      
        printf("_");
    printf("\n|%10s \t |%20s \t|%18s \t |%-8s \t |%8s \t |%13s \t |%-5s|\n", "Student ID", "Full name", "Birthday","Algebra","Calculus","Basic Programming","GPA");
    for (int i = 0; i < n; i++) {
        printStudent(lst[i]);
    }
}

// Print student list as a table to a text file (4)
void FileText(student* lst , int n) {
    getchar();
    char Name[26];
    printf("Please input file name: ");
    gets(Name);
    FILE* pph = fopen(Name, "w");
    for (int i= 0; i<128 ;i++){
      
        fprintf(pph,"_");
    }
    fprintf(pph,"\n|%10s \t |%20s \t|%18s \t |%-8s \t |%8s \t |%13s \t |%-5s|\n", "Student ID", "Full name", "Birthday","Algebra","Calculus","Basic Programming","GPA");
    int i;

    for( i=0; i < n; i++){
    struct student st = lst[i];
    fprintf(pph, "|%10s \t |%20s \t|%12d/%2d/%4d \t |%8.2f \t |%8.2f \t |%17.2f \t |%5.2f|\n", st.studentID,st.fullname,st.birthday.day,st.birthday.month,st.birthday.year,st.algebra,st.calculus,st.basic_program,st.GPA);
    
        
    }
    fclose(pph);
    printf("\nSuccessfully!\n");

}

//Highest GPA (5)
void highest_Gpa(student lst[], int n){
    float maximum = lst[0].GPA;
    for (int i=1; i<n;i++){
        if (lst[i].GPA>maximum){
            maximum = lst[i].GPA;
        }
    }
    printf("\n The highest GPA is: %.2f", maximum);
}
//Lowest GPA (5)
void lowest_Gpa(student lst[], int n){
    float minimum = lst[0].GPA;
    for (int i=1; i<n;i++){
        if (lst[i].GPA<minimum){
            minimum = lst[i].GPA;
        }
    }
    printf("\n The lowest GPA is: %.2f", minimum);
}
//Highest BP (5)
void highest_BP(student lst[], int n){
    float maximum = lst[0].basic_program;
    for (int i=1; i<n;i++){
        if (lst[i].GPA>maximum){
            maximum = lst[i].basic_program;
        }
    }
    printf("\n The highest GPA of Basic Programming  is: %.2f", maximum);
}
//Print out student firstName (6)
void print_FirstName(student lst[], int n){
    for (int i=0; i< n; i++){
        printf("\n First Name of the student %d is: %s",i+1,lst[i].firstName);
    }
}
//Sort the student list by GPA in descending order (10) (bubble sort)
void sort_byGPA(student lst[], int n){
    printf("\nSort the student list by GPA in descending order:\n");
    
    int i,j;
    for (int i= 0; i<128 ;i++){
      
        printf("_");}
    printf("\n|%10s \t |%20s \t|%18s \t |%-8s \t |%8s \t |%13s \t |%-5s|\n", "Student ID", "Full name", "Birthday","Algebra","Calculus","Basic Programming","GPA");
    for ( i = 0; i<n-1;i++){
            for ( j=n-1; j>i ;j--){
                if (lst[j].GPA > lst[j-1].GPA){
                    struct student st= lst[j];
                    lst[j] = lst[j-1];
                    lst[j-1] = st;
            }
        }
    }
    for (int i=0; i< n; i++){
        printStudent(lst[i]);
    }
}


int main(){
     int n;
    student lst[1000];
    noStudent(lst, &n);
    printToScreen(lst,n);
    highest_Gpa(lst,n);//5
    lowest_Gpa(lst,n);//5
    highest_BP(lst,n);//5
    print_FirstName(lst,n);//6
    sort_byGPA(lst,n);//10
    FileText(lst,n);//4
    return 0;
}


// Members and their contribution:
// ID	             Name	     Contribution
// BA12-110	    Vũ Thành Long	   Task 3
// BA12-081	    Phạm Phú Hưng	   Task 4
// 22BI13484	Đào Thảo Vy	       Task 6
// 22BI13092	Nguyễn Minh Đức	   Task 5
// 22BI13213	Vũ Duy Khánh	   Task 10
// 22BI13097	Tạ Minh Đức(leader) Task 3,5
// BA12-176	    Nguyễn Quang Trung	Task 4
// BA12-128	    Vũ Ngọc Minh	    Task 10
// 22BI13374	Nguyễn Minh Quân	Task 6
// BI12-316	    Phan Minh Quang     Can not contact



