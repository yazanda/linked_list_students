#include <stdio.h>
#include "StudentList.h"
//method that initialise and return a new list.
StudentList *createList() {
    StudentList *List;
    List = (StudentList *) malloc(sizeof(StudentList));
    List->head = NULL;
    return List;
}
//method that delete the list.
void deleteList(StudentList *List) {
    StudentNode *temp = List->head;
    //free all the memory that be used.
    while (temp != NULL) {
        List->head = List->head->next;
        free(temp->st);
        free(temp);
        temp = List->head;
    }
}
//method that print a student node(id, grade1 and grade 2).
void printStudentNode(StudentNode *const stN) {
    if (stN == NULL) return;
    Student *student;
    student = stN->st;
    if (student != NULL) {
        printf("Student id:%d ",student->id);
        if(student->grade1 == -1)
            printf("Session 1:hadn't test ");
        else printf("Session 1:%d ",student->grade1);
        if(student->grade2 == -1)
            printf("Session 2:hadn't test\n");
        else printf("Session 2:%d\n",student->grade2);
    }
}
//method that prints the id and the grades of all the students in the list.
void printStudentList(StudentList *const List) {
    StudentNode *curr;
    curr = List->head;
    while (curr != NULL) {
        printStudentNode(curr);
        curr = curr->next;
    }
}
//method that add a new student to the list.
void addToList(StudentList *List, Student *student) {
    StudentNode *stN = (StudentNode *) malloc(sizeof(StudentNode));
    stN->st = student;
    stN->next = NULL;
    if (List->head == NULL) {
        List->head = stN;
        return;
    }
    StudentNode *curr = List->head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = stN;
}