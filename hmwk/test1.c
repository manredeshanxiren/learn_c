#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NIL -1   //�����ʼֵ
#define M 13333    //��
#define N 10000     //�ؼ��ָ���
// ��=0.75

typedef long keytype;
//ɢ�б�������
typedef struct {
    int no;  //���
    char* name;//����
    char* address;//��ַ
    char* tel;//�绰����
} NODE;

typedef struct pos {
    keytype pos;
    int flag;
    struct pos* next;
} POS;

//��ʼ����ϣ���������͵绰�����ʼ����
void init(POS* table);

int increment(int i);//ĳ��̽�ⷽ��

int HASH_1(keytype key, int i);//��ĳ��ֵת����λ��
//��ɢ�б�������ָ���ļ�ֵ
int search_tel(POS* table, char* tel, int* pos);

//��ɢ�б�������ָ���ļ�ֵ
int search_name(POS* table, char* name, int* pos);

//pos���ؼ�ֵ��λ��
//��һ���ؼ�����ӵ���ϣ���У��Ե绰����Ϊ�ؼ��֣�
void insert_tel(POS* table_tel, int no, char* name);

//��һ���ؼ�����ӵ���ϣ���У�������Ϊ�ؼ��֣�
void insert_name(POS* table_name, int no, char* tel);

//void insert_pos(POS *table_name, int i, int pos);

//������ϣ���Ե绰����Ϊ�ؼ��֣�
void creat(NODE* htable);

//������ת��Ϊ����
long converse_name(char* name);

//�����Ҫ�����Ĺؼ��ֵ������Ϣ
void prn(NODE* htable, int no);

//�����ϣ��
void prnnn(NODE* htable, POS* table_name, int pos);

//�ɹ����ҵ�ASL
float success_ASL();

//ʧ�ܲ��ҵ�ASL
float fail_ASL();
//*******************************************************
//������������Ϊɢ�к���������̽�ⷨ�����ͻ
//*******************************************************

void menu();

//********************************************************
//������
//********************************************************
NODE htable[N];//�������
POS table_tel[M];//�����ϣ��(�Ե绰����Ϊ�ؼ���)
POS table_name[M];//�����ϣ��(������Ϊ�ؼ���)
int main() {

    int op;//�˵�ѡ��
    int i;
    int pos;
    char* tel;
    char* name;
    init(table_tel);    //��ϣ���ʼ��
    init(table_name);    //��ϣ���ʼ��
    creat(htable);
    menu();
    scanf("%d", &op);
    printf("----------------------------------------------\n");
    while (op != 3) {
        switch (op) {
        case 1: {
            tel = (char*)malloc(sizeof(char));
            printf("����������Ҫ��ѯ�ĵ绰����:");
            scanf("%s", tel);
            i = search_tel(table_tel, tel, &pos);
            if (i) {  //����ָ����ֵ
                printf("�ҵ��õ绰���룡����\n");
                printf("�ɹ����ҵ�ƽ�����ҳ���ASL:%f\n", success_ASL());
                prn(htable, table_tel[pos].pos);//table_tel[pos].pos=no
            }
            else {
                printf("δ�ҵ��õ绰���룡����\n");
                printf("ʧ�ܲ��ҵ�ƽ�����ҳ���ASL:%f\n", fail_ASL());
            }
        }
              break;
        case 2: {//?
            name = (char*)malloc(sizeof(char));
            printf("����������Ҫ��ѯ������:");
            scanf("%s", name);
            i = search_name(table_name, name, &pos);//��ɢ�б��в��ұ�����ļ�ֵ
            if (i) {  //����ָ����ֵ
                printf("�ҵ�������������\n");
                printf("�ɹ����ҵ�ƽ�����ҳ���ASL:%f\n", success_ASL());
                if (table_name[pos].flag != 1)
                    prnnn(htable, table_name, pos);
                else
                    prn(htable, table_name[pos].pos);//table_name[pos].pos=no
            }
            else {
                printf("δ�ҵ�������������\n");
                printf("ʧ�ܲ��ҵ�ƽ�����ҳ���ASL:%f\n", fail_ASL());
            }
        }
              break;
        case 3:
            exit(0);
        default: {
            printf("������Ĳ������Ϸ������������룡\n");
            fflush(stdin);//��ֹ���ϴӻ�����ȡ�������ѭ��
            break;
        }
        }
        printf("\n");
        menu();
        scanf("%d", &op);
    }
    return 0;
}


//********************************************************
//��ʼ����ϣ��
//********************************************************
void init(POS* table) {
    POS* p = table;
    for (; p < table + M; p++) {
        p->pos = NIL;//��ʼ����Ԫ�صļ�ֵ
        p->flag = 0;
        p->next = NULL;
    }
}
//********************************************************
//���Ŷ�ַ�Ĺ�ϣ����:�۵���
//�����ϣ����
//********************************************************

//********************************************************
//���Ŷ�ַ�Ĺ�ϣ����:����������
//�����ϣ����
//********************************************************
int increment(int i)  //ĳ��̽�ⷽ��
{
    return i;  //����Ϊi
}

int HASH_1(keytype key, int i)  //��ĳ��ֵת����λ��
{
    return ((int)(key % M) + increment(i)) % M;   //����̽��
}

//********************************************************
//��ɢ�б�������ָ���ļ�ֵ
//pos���ؼ�ֵ��λ��
//********************************************************
int search_tel(POS* table_tel, char* tel, int* pos) {
    int i = 0;
    long s;
    do {
        s = atol(tel);//�ַ����绰����ת��Ϊlong������
        *pos = HASH_1(s, i);//���Ŷ�ַ��ɢ�к���
        if (table_tel[*pos].pos == NIL)
            return 0;   //��δ����û�ҵ�
        if (strcmp(htable[table_tel[*pos].pos].tel, tel) == 0) return *pos; //�ҵ�
    } while (++i < M);
    return -1; //������û�ҵ�
}

//������ת��Ϊ����
long converse_name(char* name) {
    long temp = 0;
    int i = 1000;
    while (*name != '\0') {
        temp += ((*name - 'a') * i);
        i /= 100;
        name++;
    }
    return temp;
}

int search_name(POS* table_name, char* name, int* pos) {
    int i = 0;
    long k;
    k = converse_name(name);
    do {
        *pos = HASH_1(k, i);//���Ŷ�ַ��ɢ�к���
        if (table_name[*pos].pos == NIL)
            return 0;   //��δ����û�ҵ�
        if (strcmp(htable[table_name[*pos].pos].name, name) == 0) return *pos; //�ҵ�
    } while (++i < M);
    return -1; //������û�ҵ�
}

//********************************************************
//��һ���ؼ�����ӵ���ϣ����
//********************************************************
void insert_tel(POS* table_tel, int no, char* tel) {//��һ���ؼ�����ӵ���ϣ����
    int i;
    int pos;
    i = search_tel(table_tel, tel, &pos);  //��ɢ�б��в��ұ�����ļ�ֵ
    if (i == 0) {  //�������ý�㲻����
        table_tel[pos].pos = no;
    }
    else if (i == -1)
        printf("����,�޷�����!\n");
    else printf("�ؼ����ظ����޷�����!\n");
}

void insert_name(POS* table_name, int no, char* name) {
    int i, pos;
    int t = 1;
    long k;
    i = search_name(table_name, name, &pos);  //��ɢ�б��в��ұ�����ļ�ֵ
    if (i == 0) {  //�������ý�㲻����
        table_name[pos].pos = no;
        table_name[pos].flag = 1;
    }
    else if (i == -1)
        printf("����,�޷�����!\n");
    else {
        k = converse_name(name);
        table_name[i].flag++;//�ظ��Ĵ���+1
        do {
            pos = HASH_1(k, t);//���Ŷ�ַ��ɢ�к���
            if (table_name[pos].flag == 0) {
                table_name[pos].pos = no;
                table_name[pos].flag = 1;
                //insert_pos(table_name, i, pos);
                break;
            }
        } while (++t < M);
        // printf("�ؼ����ظ����޷�����!\n");
    }
}
/*
void insert_pos(POS *table_name, int i, int position) {
    Pos p;
    p = table_name[i].next;
    while (p != NULL)
        p = p->next;
    p->next = &table_name[position];
    printf(p->next->flag);
}*/

//********************************************************
//�Ӵ����ļ��ж������ݣ������������
//********************************************************
void creat(NODE* htable) {
    FILE* fp;
    int no = 0;
    char* name;
    char* address;
    char* tel;
    if (M < N) {
        printf("ɢ������>1,������������,�޷�����!\n");
        return;
    }
    if ((fp = fopen("test.txt", "r")) == NULL) {
        printf("can't open the file!!");
        exit(0);
    }
    while (!(feof(fp))) {
        name = (char*)malloc(sizeof(char));
        address = (char*)malloc(sizeof(char));
        tel = (char*)malloc(sizeof(char));//�ǳ���Ҫ������
        fscanf(fp, "%d", no);
        fscanf(fp, "%s", name);
        fscanf(fp, "%s", address);
        fscanf(fp, "%s", tel);
        htable[no].no = no;
        htable[no].name = name;
        htable[no].address = address;
        htable[no].tel = tel;  //�ҵ�����λ��,����ֵ����
        insert_tel(table_tel, no, tel);
        insert_name(table_name, no, name);
    }
    fclose(fp);
}


//********************************************************
//�����ϣ��
//********************************************************
void prn(NODE* htable, int no) {
    printf("��ţ�%d\t", htable[no].no);
    printf("������%s\t", htable[no].name);
    printf("���У�%s\t", htable[no].address);
    printf("���У�%s\n", htable[no].tel);
    printf("\n");
}

//�����ϣ��
void prnnn(NODE* htable, POS* table_name, int pos) {
    int no = 0;
    int i = pos;
    POS* p;
    p = (POS*)malloc(sizeof(POS));
    //��pΪtable_name[i],���ظ�Ԫ��ֵ��ͬ�ĵ�һ��Ԫ��
    p->pos = table_name[pos].pos;
    p->flag = table_name[pos].flag;
    p->next = table_name[pos].next;
    printf("��ѯ���������ڸõ绰�����ѯϵͳ���ظ�!\n");
    printf("�ֽ������Ǹ��������˲�ѯ���£�\n");
    for (int k = 0; k < table_name[pos].flag;) {
        if (strcmp(htable[table_name[pos].pos].name, htable[table_name[i].pos].name) == 0) {
            no = table_name[i].pos;
            printf("��ţ�%d\t", htable[no].no);
            printf("������%s\t", htable[no].name);
            printf("���У�%s\t", htable[no].address);
            printf("���У�%s\n", htable[no].tel);
            k++;
        }
        i++;
    }
}

//�ɹ����ҵ�ASL
float success_ASL() {
    float i = 1 - (1.0 * N) / M;
    return (1 + 1 / i) / 2;
}

//ʧ�ܲ��ҵ�ASL
float fail_ASL() {
    float a = (1.0 * N) / M;
    float i = 1 - a;
    return (1 + 1 / (i * i)) / 2;
}

/*void prnnn(NODE *htable) {
    NODE *p = htable;
    for (; p < htable + M; p++)
        if (p->tel != NIL) {
            printf("��ţ�%d\t", p->no);
            printf("������%s\t", p->name);
            printf("���У�%s\t", p->address);
            printf("�绰���룺%ld\t", p->tel);//���ĳ��ַ������,�������Ӧ�ļ�ֵ
        }

    printf("\n");
}*/

void menu() {
    printf("----------------------------------------------\n");
    printf("*************��ӭʹ�õ绰�����ѯϵͳ*************\n");
    printf("----------------------------------------------\n");
    printf("��ѡ������Ҫ���еĲ�ѯ��");
    printf(" 1.�Ե绰����Ϊ�ؼ��ֽ��в�ѯ\n");
    printf("\t\t\t\t    2.������Ϊ�ؼ��ֽ��в�ѯ\n");
    printf("\t\t\t\t    3.�˳�\n");
    printf("----------------------------------------------\n");
    printf("��ѡ������Ҫ���еĲ�����");
}