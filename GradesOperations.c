#include "GradesOperations.h"

//method that calculate and returns the number of students in the list.
int numOfStudents(StudentList *list){
    if(list->head == NULL)
        return 0;
    int countS = 0;
    StudentNode *stN = list->head;
    while(stN->next != NULL){
        countS++;
        stN = stN->next;
    }
    return ++countS;
}
//method that calculate and returns the number of students that tested in just one session.
int oneDate(StudentList *list){
    int count = 0;
    StudentNode *stN = list->head;
    while(stN != NULL){
        Student *tmp;
        tmp = stN->st;
        if((tmp->grade1 == -1 && tmp->grade2 != -1) || (tmp->grade2 == -1 && tmp->grade1 != -1))
            count++;
        stN = stN->next;
    }
    return count;
}
//method that calculate and returns the number of students that hadn't gone to any exam session.
int didntTest(StudentList *list){
    int count = 0;
    StudentNode *stN = list->head;
    while(stN != NULL){
        Student *tmp;
        tmp = stN->st;
        if(tmp->grade1 == -1 && tmp->grade2 == -1)
            count++;
        stN = stN->next;
    }
    return count;
}
//method that calculate and returns the failers percentage at an exam session(date).
double failedPercent(StudentList *list,int date){
    int count = 0,countFaild = 0;
    StudentNode *stN = list->head;
    while(stN != NULL){
        Student *tmp;
        tmp = stN->st;
        if((tmp->grade1 < 60 && tmp->grade1 != -1 && date == 1) || (tmp->grade2 < 60 && tmp->grade2 != -1 && date == 2))
            countFaild++;
        if((tmp->grade2 != -1 && date == 2) || (tmp->grade1 != -1 && date == 1))
            count++;
        stN = stN->next;
    }
    //if there's no one failed return 0
    return count == 0? 0:((double)countFaild/count)*100;
}
//method that calculate and returns the average grades' percentage at an exam session(date).
double gradesAverage(StudentList*list,int date){
    int count = 0,sum = 0;
    StudentNode *stN = list->head;
    while(stN != NULL){
        Student *tmp;
        tmp = stN->st;
        if(tmp->grade2 != -1 && date == 2) {
            count++;
            sum += tmp->grade2;
        }
        else if(tmp->grade1 != -1 && date == 1){
            count++;
            sum += tmp->grade1;
        }
        stN = stN->next;
    }
    return count == 0? 0:((double)sum/count);
}
//method that calculate and returns the max graded student id.
int maxGradeId(StudentList *list){
    int id = 0,max = -1;
    StudentNode *stN = list->head;
    while(stN != NULL){
        Student *tmp;
        tmp = stN->st;
        if(tmp->grade2 != -1 && tmp->grade2 > max) {
            max = tmp->grade2;
            id = tmp->id;
        }
        if(tmp->grade1 != -1 && tmp->grade1 > max){
            max = tmp->grade1;
            id = tmp->id;
        }
        stN = stN->next;
    }
    return id;
}
//method that calculate and returns the min graded student id.
int minGradeId(StudentList *list){
    int id = 0,min = 101;
    StudentNode *stN = list->head;
    while(stN != NULL){
        Student *tmp;
        tmp = stN->st;
        if(tmp->grade2 != -1 && tmp->grade2 < min) {
            min = tmp->grade2;
            id = tmp->id;
        }
        if(tmp->grade1 != -1 && tmp->grade1 < min){
            min = tmp->grade1;
            id = tmp->id;
        }
        stN = stN->next;
    }
    return id;
}
