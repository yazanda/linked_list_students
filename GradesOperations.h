#ifndef GRADESOPERATIONS_H
#define GRADESOPERATIONS_H
#include "StudentList.h"

//Operations Functions.
int numOfStudents(StudentList *);
int oneDate(StudentList *);
int didntTest(StudentList *list);
double failedPercent(StudentList *,int);
double gradesAverage(StudentList *,int);
int maxGradeId(StudentList *);
int minGradeId(StudentList *);
#endif //GRADESOPERATIONS_H
