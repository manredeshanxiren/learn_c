#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define N 100 //Ԫ��������
typedef struct {
    int no;  //���
    char name[3];//����
    char address[10];//��ַ
    char tel[12];//�绰����
} NODE;
typedef struct {
    char data[10];
} Country;
Country country[10];

void creatfile(NODE data[], int* n);
int isTelRepeated(char tel[]);

void initCountry();

int main() {
    NODE DATA[N];
    int n;
    creatfile(DATA, &n);
    return 0;
}

void creatfile(NODE data[], int* n) {
    FILE* fp;
    int i, key, flag;
    int temp_n;
    char temp_tel[11];
    unsigned seed;
    *n = N;
    char num[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                         'h', 'i', 'j', 'k', 'l', 'm', 'n',
                         'o', 'p', 'q', 'r', 's', 't',
                         'u', 'v', 'w', 'x', 'y', 'z' };//��ĸ��
    /*char ALPHABET[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
                         'H', 'I', 'J', 'K', 'L', 'M', 'N',
                         'O', 'P', 'Q', 'R', 'S', 'T',
                         'U', 'V', 'W', 'X', 'Y', 'Z'};//��ĸ��*/
    initCountry();
    if ((fp = fopen("test.txt", "w")) == NULL) {
        printf("can't open the file!\n");
        exit(0);
    }
    seed = time(NULL);
    srand(seed);  //�����������
    for (i = 0; i < *n; i++) {
        for (int k = 0; k < 3; k++) {
            key = rand() % 26;
            data[i].name[k] = alphabet[key];
        }
        data[i].name[3] = '\0';
    }

    for (i = 0; i < *n; i++) {
        key = rand() % 20;
        for (int k = 0; k < 10; k++) {
            data[i].address[k] = country[key].data[k];
        }
    }

    for (i = 0; i < *n;) {
        temp_tel[0] = '1';
        for (int k = 1; k < 11; k++) {
            key = rand() % 10;
            temp_tel[k] = num[key];
        }
        temp_tel[10] = '\0';
        //дһ�������������ļ�
        flag = 1;
        if (isTelRepeated(temp_tel)) {
            flag = 0;
            break;
        }
        if (flag) {
            for (int k = 0; k < 11; k++) {
                data[i].tel[k] = temp_tel[k];
            }
            i++;
        }
    }

    for (i = 0; i < *n; i++) {
        fprintf(fp, "%d ", i + 1);  //дһ�������������ļ�
        fprintf(fp, "%s ", data[i].name);  //дһ�������������ļ�
        fprintf(fp, "%s ", data[i].address);  //дһ�������������ļ�
        fprintf(fp, "%s\n", data[i].tel);  //дһ�������������ļ�
    }
    fclose(fp);
}

void initCountry() {
    FILE* fp;
    char temp[10];
    if ((fp = fopen("test.txt", "r")) == NULL) {
        printf("can't open the file!\n");
        exit(0);
    }
    for (int i = 0; i < 20; i++) {
        fscanf(fp, "%s", temp);
        for (int j = 0; j < 10; j++) {
            country[i].data[j] = temp[j];
        }

    }
}

int isTelRepeated(char tel[]) {
    FILE* fp;
    char temp_tel[11];
    if ((fp = fopen("test.txt", "r")) == NULL) {
        printf("can't open the file!\n");
        exit(0);
    }
    for (int i = 1; i <= N; i++) {
        fscanf(fp, "%s", temp_tel);
        if (strcmp(tel, temp_tel) == 0) {
            return 1;
        }
    }
    return 0;
}
