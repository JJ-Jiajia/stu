#include<stdio.h>
#include<stdlib.h>

#define sm 50
typedef struct Stu {
    int mc;
    long number;
    char name[10];
    double Chinese;
    double math;
    double English;
    double computer;
    double avg;
} Stu;

void printAll();
//1.录入、浏览功能：
//按学号顺序录入学生信息（学号、姓名、语文、数学、英语、计算机），显示系统中的所有信息。

int inputInfo();

//查询 尾号为09
int queryInfo();

//修改,修改学号尾号为12的学生的成绩信息（任意两项即可），并显示该学生的全部信息。
int updateInfo();

//排序输出，按语文成绩的顺序，由高到低显示所有学生的信息。
int printByChinese();

//统计学生的平均成绩，并输出（学号，姓名，平均成绩）。
int printAverage();

void p(int);

void swapStu(Stu a[], int i, int j);
int bubbySortStu(Stu a[], int length);
//学生数目
int sum = 0;
//学生数据结构
Stu stud[sm];

int main(int argc, char *argv[]) {
    //功能选项
    int choice;
    while (1) {
        printf("1.录入；2.查询；3.修改；4.排序；5.统计；0.退出；\n");
        printf("请输入需要的功能项：");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                printf("再见！\n");
                system("pause");
                return 0;
            case 1:
                inputInfo();
                break;
            case 2:
                queryInfo();
                break;
            case 3:
                updateInfo();
                break;
            case 4:
                printByChinese();
                break;
            case 5:
                printAverage();
                break;
            default:
                printf("功能选择有误，请重新选择。");
                continue;
        }
        printf("======================\n");
    }
}

int inputInfo() {
    printf("开始输入学生信息，输入学生总数：");
    scanf("%d", &sum);
    int i = 0;
    while (i < sum) {
        printf("第%d个学生:\n", i + 1);
        stud[i].mc = i + 1;
        printf("输入学号:");
        scanf("%d", &stud[i].number);
        printf("输入姓名:");
        scanf("%s", &stud[i].name);
        printf("输入语文成绩:");
        scanf("%lf", &stud[i].Chinese);
        printf("输入数学成绩:");
        scanf("%lf", &stud[i].math);
        printf("输入英语成绩:");
        scanf("%lf", &stud[i].English);
        printf("输入计算机成绩:");
        scanf("%lf", &stud[i].computer);
        printf("\n");
        stud[i].avg = (stud[i].Chinese + stud[i].math + stud[i].English + stud[i].computer) / 4;
        i++;
    }
    printAll();
    return 0;
}

void printAll() {
    int j = 0;
    printf("序号|学号|姓名|语文|数学|英语|计算机\n");
    while (j < sum) {
        p(j);
        j++;
    }
}

void p(int j) {
    printf("%d|%ld|%s|%.2lf|%.2lf|%.2lf|%.2lf\n", stud[j].mc, stud[j].number, stud[j].name, stud[j].Chinese,
           stud[j].math, stud[j].English, stud[j].computer);
}

int queryInfo() {
    if (sum == 0) return 1;
    int endNu;
    int i;
    printf("输入要查学号的尾号后两位:\n");
    scanf("%d", &endNu);
    printf("序号|学号|姓名|语文|数学|英语|计算机\n");
    for (i = 0; i < sum; i++) {
        if (stud[i].number % 100 == endNu)
            p(i);
    }
    return 0;
}

int printByChinese() {
    bubbySortStu(stud,sum);
    printAll();
}

int printAverage() {
    int j = 0;
    printf("学号|姓名|平均成绩\n");
    while (j < sum) {
        printf("%d|%s|%.2lf\n", stud[j].number, stud[j].name, stud[j].avg);
        j++;
    }
}

int bubbySortStu(Stu a[], int length) {
    int i, j;
    for (i = 0; i < length; i++) {
        for (j = 1; j < length - i; j++) {
            if (a[j].Chinese > a[j - 1].Chinese)
                swapStu(a, j, j - 1);
        }
    }
    return 0;
}
void swapStu(Stu a[], int i, int j) {
    Stu temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int updateInfo(){
    if (sum == 0) return 1;
    int endNu;
    int i;
    double a[4];
    printf("输入要修改学号的尾号后两位:\n");
    scanf("%d", &endNu);
    printf("输入修改后的语文成绩：\n");
    scanf("%lf",a);
    printf("输入修改后的数学成绩：\n");
    scanf("%lf",a+1);
    printf("输入修改后的外语成绩：\n");
    scanf("%lf",a+2);
    printf("输入修改后的计算机成绩：\n");
    scanf("%lf",a+3);
    printf("符合条件的人员修改后的成绩为\n");
    printf("序号|学号|姓名|语文|数学|英语|计算机\n");
    for (i = 0; i < sum; i++) {
        if (stud[i].number % 100 == endNu){
            stud[i].Chinese=a[0];
            stud[i].math=a[1];
            stud[i].English=a[2];
            stud[i].computer=a[3];
            stud[i].avg=(a[0]+a[1]+a[2]+a[3])/4;
            p(i);
        }

    }
}