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
//1.¼�롢������ܣ�
//��ѧ��˳��¼��ѧ����Ϣ��ѧ�š����������ġ���ѧ��Ӣ������������ʾϵͳ�е�������Ϣ��

int inputInfo();

//��ѯ β��Ϊ09
int queryInfo();

//�޸�,�޸�ѧ��β��Ϊ12��ѧ���ĳɼ���Ϣ����������ɣ�������ʾ��ѧ����ȫ����Ϣ��
int updateInfo();

//��������������ĳɼ���˳���ɸߵ�����ʾ����ѧ������Ϣ��
int printByChinese();

//ͳ��ѧ����ƽ���ɼ����������ѧ�ţ�������ƽ���ɼ�����
int printAverage();

void p(int);

void swapStu(Stu a[], int i, int j);
int bubbySortStu(Stu a[], int length);
//ѧ����Ŀ
int sum = 0;
//ѧ�����ݽṹ
Stu stud[sm];

int main(int argc, char *argv[]) {
    //����ѡ��
    int choice;
    while (1) {
        printf("1.¼�룻2.��ѯ��3.�޸ģ�4.����5.ͳ�ƣ�0.�˳���\n");
        printf("��������Ҫ�Ĺ����");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                printf("�ټ���\n");
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
                printf("����ѡ������������ѡ��");
                continue;
        }
        printf("======================\n");
    }
}

int inputInfo() {
    printf("��ʼ����ѧ����Ϣ������ѧ��������");
    scanf("%d", &sum);
    int i = 0;
    while (i < sum) {
        printf("��%d��ѧ��:\n", i + 1);
        stud[i].mc = i + 1;
        printf("����ѧ��:");
        scanf("%d", &stud[i].number);
        printf("��������:");
        scanf("%s", &stud[i].name);
        printf("�������ĳɼ�:");
        scanf("%lf", &stud[i].Chinese);
        printf("������ѧ�ɼ�:");
        scanf("%lf", &stud[i].math);
        printf("����Ӣ��ɼ�:");
        scanf("%lf", &stud[i].English);
        printf("���������ɼ�:");
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
    printf("���|ѧ��|����|����|��ѧ|Ӣ��|�����\n");
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
    printf("����Ҫ��ѧ�ŵ�β�ź���λ:\n");
    scanf("%d", &endNu);
    printf("���|ѧ��|����|����|��ѧ|Ӣ��|�����\n");
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
    printf("ѧ��|����|ƽ���ɼ�\n");
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
    printf("����Ҫ�޸�ѧ�ŵ�β�ź���λ:\n");
    scanf("%d", &endNu);
    printf("�����޸ĺ�����ĳɼ���\n");
    scanf("%lf",a);
    printf("�����޸ĺ����ѧ�ɼ���\n");
    scanf("%lf",a+1);
    printf("�����޸ĺ������ɼ���\n");
    scanf("%lf",a+2);
    printf("�����޸ĺ�ļ�����ɼ���\n");
    scanf("%lf",a+3);
    printf("������������Ա�޸ĺ�ĳɼ�Ϊ\n");
    printf("���|ѧ��|����|����|��ѧ|Ӣ��|�����\n");
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