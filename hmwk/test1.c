#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NIL -1   //定义初始值
#define M 13333    //表长
#define N 10000     //关键字个数
// α=0.75

typedef long keytype;
//散列表结点类型
typedef struct {
    int no;  //编号
    char* name;//名字
    char* address;//地址
    char* tel;//电话号码
} NODE;

typedef struct pos {
    keytype pos;
    int flag;
    struct pos* next;
} POS;

//初始化哈希表，将姓名和电话号码初始化！
void init(POS* table);

int increment(int i);//某种探测方法

int HASH_1(keytype key, int i);//将某键值转换成位置
//在散列表中搜索指定的键值
int search_tel(POS* table, char* tel, int* pos);

//在散列表中搜索指定的键值
int search_name(POS* table, char* name, int* pos);

//pos返回键值的位置
//将一个关键字添加到哈希表中（以电话号码为关键字）
void insert_tel(POS* table_tel, int no, char* name);

//将一个关键字添加到哈希表中（以姓名为关键字）
void insert_name(POS* table_name, int no, char* tel);

//void insert_pos(POS *table_name, int i, int pos);

//创建哈希表（以电话号码为关键字）
void creat(NODE* htable);

//将姓名转化为数字
long converse_name(char* name);

//输出想要搜索的关键字的相关信息
void prn(NODE* htable, int no);

//输出哈希表
void prnnn(NODE* htable, POS* table_name, int pos);

//成功查找的ASL
float success_ASL();

//失败查找的ASL
float fail_ASL();
//*******************************************************
//除留余数法作为散列函数，线性探测法解决冲突
//*******************************************************

void menu();

//********************************************************
//主函数
//********************************************************
NODE htable[N];//定义结点表
POS table_tel[M];//定义哈希表(以电话号码为关键字)
POS table_name[M];//定义哈希表(以姓名为关键字)
int main() {

    int op;//菜单选择
    int i;
    int pos;
    char* tel;
    char* name;
    init(table_tel);    //哈希表初始化
    init(table_name);    //哈希表初始化
    creat(htable);
    menu();
    scanf("%d", &op);
    printf("----------------------------------------------\n");
    while (op != 3) {
        switch (op) {
        case 1: {
            tel = (char*)malloc(sizeof(char));
            printf("请输入你想要查询的电话号码:");
            scanf("%s", tel);
            i = search_tel(table_tel, tel, &pos);
            if (i) {  //搜索指定键值
                printf("找到该电话号码！！！\n");
                printf("成功查找的平均查找长度ASL:%f\n", success_ASL());
                prn(htable, table_tel[pos].pos);//table_tel[pos].pos=no
            }
            else {
                printf("未找到该电话号码！！！\n");
                printf("失败查找的平均查找长度ASL:%f\n", fail_ASL());
            }
        }
              break;
        case 2: {//?
            name = (char*)malloc(sizeof(char));
            printf("请输入你想要查询的姓名:");
            scanf("%s", name);
            i = search_name(table_name, name, &pos);//在散列表中查找被插入的键值
            if (i) {  //搜索指定键值
                printf("找到该姓名！！！\n");
                printf("成功查找的平均查找长度ASL:%f\n", success_ASL());
                if (table_name[pos].flag != 1)
                    prnnn(htable, table_name, pos);
                else
                    prn(htable, table_name[pos].pos);//table_name[pos].pos=no
            }
            else {
                printf("未找到该姓名！！！\n");
                printf("失败查找的平均查找长度ASL:%f\n", fail_ASL());
            }
        }
              break;
        case 3:
            exit(0);
        default: {
            printf("您输入的操作不合法，请重新输入！\n");
            fflush(stdin);//防止不断从缓冲区取数，造成循环
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
//初始化哈希表
//********************************************************
void init(POS* table) {
    POS* p = table;
    for (; p < table + M; p++) {
        p->pos = NIL;//初始化表元素的键值
        p->flag = 0;
        p->next = NULL;
    }
}
//********************************************************
//开放定址的哈希函数:折叠法
//构造哈希函数
//********************************************************

//********************************************************
//开放定址的哈希函数:除留余数法
//构造哈希函数
//********************************************************
int increment(int i)  //某种探测方法
{
    return i;  //增量为i
}

int HASH_1(keytype key, int i)  //将某键值转换成位置
{
    return ((int)(key % M) + increment(i)) % M;   //线性探测
}

//********************************************************
//在散列表中搜索指定的键值
//pos返回键值的位置
//********************************************************
int search_tel(POS* table_tel, char* tel, int* pos) {
    int i = 0;
    long s;
    do {
        s = atol(tel);//字符串电话号码转换为long型数据
        *pos = HASH_1(s, i);//开放定址的散列函数
        if (table_tel[*pos].pos == NIL)
            return 0;   //表未满，没找到
        if (strcmp(htable[table_tel[*pos].pos].tel, tel) == 0) return *pos; //找到
    } while (++i < M);
    return -1; //表满，没找到
}

//将姓名转化为数字
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
        *pos = HASH_1(k, i);//开放定址的散列函数
        if (table_name[*pos].pos == NIL)
            return 0;   //表未满，没找到
        if (strcmp(htable[table_name[*pos].pos].name, name) == 0) return *pos; //找到
    } while (++i < M);
    return -1; //表满，没找到
}

//********************************************************
//将一个关键字添加到哈希表中
//********************************************************
void insert_tel(POS* table_tel, int no, char* tel) {//将一个关键字添加到哈希表中
    int i;
    int pos;
    i = search_tel(table_tel, tel, &pos);  //在散列表中查找被插入的键值
    if (i == 0) {  //表不满，该结点不存在
        table_tel[pos].pos = no;
    }
    else if (i == -1)
        printf("表满,无法插入!\n");
    else printf("关键字重复，无法插入!\n");
}

void insert_name(POS* table_name, int no, char* name) {
    int i, pos;
    int t = 1;
    long k;
    i = search_name(table_name, name, &pos);  //在散列表中查找被插入的键值
    if (i == 0) {  //表不满，该结点不存在
        table_name[pos].pos = no;
        table_name[pos].flag = 1;
    }
    else if (i == -1)
        printf("表满,无法插入!\n");
    else {
        k = converse_name(name);
        table_name[i].flag++;//重复的次数+1
        do {
            pos = HASH_1(k, t);//开放定址的散列函数
            if (table_name[pos].flag == 0) {
                table_name[pos].pos = no;
                table_name[pos].flag = 1;
                //insert_pos(table_name, i, pos);
                break;
            }
        } while (++t < M);
        // printf("关键字重复，无法插入!\n");
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
//从磁盘文件中读入数据，并存入结点表中
//********************************************************
void creat(NODE* htable) {
    FILE* fp;
    int no = 0;
    char* name;
    char* address;
    char* tel;
    if (M < N) {
        printf("散列因子>1,结点个数超过表长,无法创建!\n");
        return;
    }
    if ((fp = fopen("test.txt", "r")) == NULL) {
        printf("can't open the file!!");
        exit(0);
    }
    while (!(feof(fp))) {
        name = (char*)malloc(sizeof(char));
        address = (char*)malloc(sizeof(char));
        tel = (char*)malloc(sizeof(char));//非常重要！！！
        fscanf(fp, "%d", no);
        fscanf(fp, "%s", name);
        fscanf(fp, "%s", address);
        fscanf(fp, "%s", tel);
        htable[no].no = no;
        htable[no].name = name;
        htable[no].address = address;
        htable[no].tel = tel;  //找到开放位置,将键值加入
        insert_tel(table_tel, no, tel);
        insert_name(table_name, no, name);
    }
    fclose(fp);
}


//********************************************************
//输出哈希表
//********************************************************
void prn(NODE* htable, int no) {
    printf("编号：%d\t", htable[no].no);
    printf("姓名：%s\t", htable[no].name);
    printf("城市：%s\t", htable[no].address);
    printf("城市：%s\n", htable[no].tel);
    printf("\n");
}

//输出哈希表
void prnnn(NODE* htable, POS* table_name, int pos) {
    int no = 0;
    int i = pos;
    POS* p;
    p = (POS*)malloc(sizeof(POS));
    //令p为table_name[i],即重复元素值相同的第一个元素
    p->pos = table_name[pos].pos;
    p->flag = table_name[pos].flag;
    p->next = table_name[pos].next;
    printf("查询到该姓名在该电话号码查询系统中重复!\n");
    printf("现将所有是该姓名的人查询如下：\n");
    for (int k = 0; k < table_name[pos].flag;) {
        if (strcmp(htable[table_name[pos].pos].name, htable[table_name[i].pos].name) == 0) {
            no = table_name[i].pos;
            printf("编号：%d\t", htable[no].no);
            printf("姓名：%s\t", htable[no].name);
            printf("城市：%s\t", htable[no].address);
            printf("城市：%s\n", htable[no].tel);
            k++;
        }
        i++;
    }
}

//成功查找的ASL
float success_ASL() {
    float i = 1 - (1.0 * N) / M;
    return (1 + 1 / i) / 2;
}

//失败查找的ASL
float fail_ASL() {
    float a = (1.0 * N) / M;
    float i = 1 - a;
    return (1 + 1 / (i * i)) / 2;
}

/*void prnnn(NODE *htable) {
    NODE *p = htable;
    for (; p < htable + M; p++)
        if (p->tel != NIL) {
            printf("编号：%d\t", p->no);
            printf("姓名：%s\t", p->name);
            printf("城市：%s\t", p->address);
            printf("电话号码：%ld\t", p->tel);//如果某地址不开放,则输出相应的键值
        }

    printf("\n");
}*/

void menu() {
    printf("----------------------------------------------\n");
    printf("*************欢迎使用电话号码查询系统*************\n");
    printf("----------------------------------------------\n");
    printf("请选择你想要进行的查询：");
    printf(" 1.以电话号码为关键字进行查询\n");
    printf("\t\t\t\t    2.以姓名为关键字进行查询\n");
    printf("\t\t\t\t    3.退出\n");
    printf("----------------------------------------------\n");
    printf("请选择你想要进行的操作：");
}