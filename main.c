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

//ѧ����Ŀ
int sum = 0;
//ѧ�����ݽṹ
Stu stud[sm];

int main(int argc, char *argv[]) {
    //����ѡ��
    int choice;
    while (1) {
        printf("¼�룺1����ѯ��2���޸ģ�3������4��ͳ�ƣ�5���˳���0��\n");
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
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("����ѡ������������ѡ��");
                continue;
        }
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
    printf("%d|%d|%s|%.2lf|%.2lf|%.2lf|%.2lf\n", stud[j].mc, stud[j].number, stud[j].name, stud[j].Chinese,
           stud[j].math, stud[j].English, stud[j].computer);
}

int queryInfo() {
    if (sum == 0) return 1;
    int endNu;
    int i;
    printf("����Ҫ��ѧ�ŵ�β�ź���λ:\n");
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