#include <stdio.h>
#include <stdlib.h>
#include "StudentList.h"
#include "GradesOperations.h"
//main functions.
void fileToList(char[],StudentList*);
void reportFile(StudentList*);
//method that opens and reads the "StudentsGrades" file then copy the grades to the students list.
void fileToList(char path[] ,StudentList* list){
    list->head = NULL;
    FILE *fr; //new file reader.
    fr = fopen(path, "r");
    //if the file hadn't opened then stop the programme.
    if (fr == NULL) {
        printf("Cannot open the file!");
        exit(1);
    }
    int idS, grS1, grS2;
    //read from the file until the last line.
    while (fscanf(fr, "%d %d %d", &idS, &grS1, &grS2) != EOF) {
        //make a new student object to copy the grades and the id.
        Student *st;
        st = (Student *) malloc(sizeof(Student));
        st->id = idS, st->grade1 = grS1, st->grade2 = grS2;
        //add the new student to the end of the list.
        addToList(list,st);
    }
    //closing the file.
    fclose(fr);
}
//method that opens a new file "report.txt" then write to the file all the grades operations.
void reportFile(StudentList* list){
    FILE *fw;//new file writer.
    fw = fopen("Report.txt","w");
    //print the grades operations to the file.
    fprintf(fw,"The number of students in the list: %d\n",numOfStudents(list));
    fprintf(fw,"The number of students that had test in one session: %d\n",oneDate(list));
    fprintf(fw,"The number of students that hadn't test: %d\n",didntTest(list));
    fprintf(fw,"Fail Percentage in the first session: %.2f %c\n",failedPercent(list,1),'%');
    fprintf(fw,"Fail Percentage in the second session: %.2f %c\n",failedPercent(list,2),'%');
    fprintf(fw,"Grade Average in the first session: %.2f %c\n",gradesAverage(list,1),'%');
    fprintf(fw,"Grade Average in the second session: %.2f %c\n",gradesAverage(list,2),'%');
    fprintf(fw,"Maximum Graded student ID: %d\n",maxGradeId(list));
    fprintf(fw,"Minimum Graded student ID: %d\n",minGradeId(list));
    //closing the file.
    fclose(fw);
}

int main() {
    //create a new list.
    StudentList *List;
    List = createList();
    //reading the grades file.
    fileToList("StudentsGrades.txt",List);
    //creating the report file.
    reportFile(List);
    printStudentList(List);
    //delete list(free all the memory).
    deleteList(List);
    free(List);
    return 0;
}
