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

//学生数目
int sum = 0;
//学生数据结构
Stu stud[sm];

int main(int argc, char *argv[]) {
    //功能选项
    int choice;
    while (1) {
        printf("录入：1；查询：2；修改：3；排序：4；统计：5；退出：0；\n");
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
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("功能选择有误，请重新选择。");
                continue;
        }
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
    printf("%d|%d|%s|%.2lf|%.2lf|%.2lf|%.2lf\n", stud[j].mc, stud[j].number, stud[j].name, stud[j].Chinese,
           stud[j].math, stud[j].English, stud[j].computer);
}

int queryInfo() {
    if (sum == 0) return 1;
    int endNu;
    int i;
    printf("输入要查学号的尾号后两位:\n");
    scanf("%d", &endNu);
    for (i = 0; i < sum; i++) {
        if (stud[i].number % 100 == endNu)
            p(i);
    }
    return 0;
}

int printByChinese() {
    int rang[sum];
    for(int m=0;m<sum;m++){
        rang[m]=-1;
    }
    for (int i = 0; i < sum; i++) {
        int count = 0;
        for (int j = 0; j < sum; j++) {
            if (stud[i].Chinese <= stud[j].Chinese) count++;
            while(rang[count] !=-1){
                count--;
            }
            rang[count] = i;
        }
    }
    for(int n=0;n<sum;n++){
        p(rang[n]);
    }
}