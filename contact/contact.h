#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADD 30
#define MAX 100
#define DEFAULT_SZ 3
#define INC_SZ 2 //Ĭ�����ӵĴ�С


struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	int age;
	int addr[MAX_ADD];
};


//struct contact
//{
//	struct PeoInfo data[MAX];
//	int sz;
//};


struct contact
{
	struct PeoInfo *data;
	int sz;//�Ѿ��Ž�ȥ����Ϣ
	int capacity;//����
};

//��ʼ��ͨѶ¼
void InitContact(struct contact* pc);

//��ͨѶ¼���������
void AddContact(struct contact* pc);

//չʾͨѶ¼����Ϣ
void ShowContact(const struct contact * pc);

//ɾ��ָ����ϵ��
void DelContact(struct contact* pc);

//����ͨѶ¼�е���ϵ��
void SearchContact(struct contact* pc);

//�޸���ϵ�˵���Ϣ
void ModifyContact(struct contact* pc);

//������ϵ��
void SortContact(struct contact* pc);

//����ͨѶ¼
void DestroyContact(struct contact* pc);