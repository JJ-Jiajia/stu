#include <stdio.h>
int bubbySort(int a[], int length);
void swap(int a[], int i, int j);
int main1() {
    int a[10],length=10;
    int i,result;
    printf("����ʮ�����֣�\n");
    for(i=0;i<length;i++){
        scanf("%d",a+i);
    }
    printf("===�������===\n");
    printf("===��ӡ===\n");
    result=bubbySort(a,length);
    if(0== result){
        for(i=0;i<length;i++){
            printf("%d ",a[i]);
        }
    }
    return 0;
}
//ð������
// ���������鼰���鳤��
int bubbySort(int *a, int length) {
    int i, j;
    for (i = 0; i < length; i++) {
        for (j = 1; j < length - i; j++) {
            if (a[j] < a[j - 1])
                swap(a, j, j - 1);
        }
    }
    return 0;
}
//��������˳�� '^'��������㣬һ������ͬһ����������� ֵ���䡣
//eg: 1^2^2 == 1;
void swap(int a[], int i, int j) {
    a[i] = a[j] ^ a[i] ^ (a[j] = a[i]);
}

