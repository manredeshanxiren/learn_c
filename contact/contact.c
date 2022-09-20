#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//初始化通讯录
void InitContact(struct contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, 100 * sizeof(struct PeoInfo));
}

//向通讯录中添加数据
void AddContact(struct contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("通讯录已满,无法添加数据\n");
		return;
	}

	//增加人的信息
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入年龄:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("成功增加联系人\n");
}

//展示通讯录的信息
void ShowContact(const struct contact* pc)
{
	if (pc->sz >= 1)
	{
		printf("%-20s\t%-5s\t%-5s\t%-5s\t%-30s\n","姓名", "性别", "年龄", "电话", "地址");
	}
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-5s\t%-30s\n", pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr
		);
	}
}

static int FindByName(struct contact* pc, char* name)
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
//删除指定联系人
void DelContact(struct contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要删除人的姓名:>");
	scanf("%s", name);
	int ret = FindByName(pc ,name);
	if (ret != -1)
	{
		//for (int j = ret; j < pc->sz - 1; j++)
		//{
		//	pc->data[j] = pc->data[j + 1];
		//}
		memmove(&pc->data[ret], &pc->data[ret + 1],(pc->sz - 1 - ret) * sizeof(struct PeoInfo));
		pc->sz--;
	}
	printf("删除成功\n");
}

//查找通讯录中的联系人
void SearchContact(struct contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要查找的人的姓名:>");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret != -1)
	{
		printf("%-20s\t%-5s\t%-5s\t%-5s\t%-30s\n", "姓名", 
			"性别", "年龄", "电话", "地址");
		printf("%-20s\t%-5s\t%-5d\t%-5s\t%-30s\n", pc->data[ret].name,
			pc->data[ret].sex,
			pc->data[ret].age,
			pc->data[ret].tele,
			pc->data[ret].addr
		);
	}
	else
	{
		printf("查找的联系人不存在！\n");
	}
}

//修改联系人的信息
void ModifyContact(struct contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要修改的联系人的姓名:>");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要修改的联系人不存在");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[ret].name);
		printf("请输入性别:>");
		scanf("%s", pc->data[ret].sex);
		printf("请输入电话:>");
		scanf("%s", pc->data[ret].tele);
		printf("请输入年龄:>");
		scanf("%d", &pc->data[ret].age);
		printf("请输入地址:>");
		scanf("%s", pc->data[ret].addr);
		printf("成功修改联系人\n");
	}


}

int cmp_int(const void* a, const void* b)
{
	return ((struct PeoInfo*)b)->age - ((struct PeoInfo*)a)->age;
}
//排序联系人(年龄)
void SortContact(struct contact* pc)
{
	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), cmp_int);
}