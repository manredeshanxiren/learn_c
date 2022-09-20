#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADD 30
#define MAX 100


struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	int age;
	int addr[MAX_ADD];
};


struct contact
{
	struct PeoInfo data[MAX];
	int sz;
};

//初始化通讯录
void InitContact(struct contact* pc);

//向通讯录中添加数据
void AddContact(struct contact* pc);

//展示通讯录的信息
void ShowContact(const struct contact * pc);

//删除指定联系人
void DelContact(struct contact* pc);

//查找通讯录中的联系人
void SearchContact(struct contact* pc);

//修改联系人的信息
void ModifyContact(struct contact* pc);

//排序联系人
void SortContact(struct contact* pc);