#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

////��ʼ��ͨѶ¼
//void InitContact(struct contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, 100 * sizeof(struct PeoInfo));
//}


//���ͨѶ¼����
int CheckCapacity(struct contact* pc)
{
	assert(pc);
	if (pc->sz == pc->capacity)
	{
		//��������
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ�\n");
			return 1;
		}
		else
		{
			perror("AddContact()");
			return 0;
		}
	}
	else
	{
		return 1;
	}
}

//�����ļ�����Ϣ��ͨѶ¼
void LoadContact(struct contact* pc)
{
	//���ļ�
	FILE* pfr = fopen("contact.txt", "r");
	if (pfr == NULL)
	{
		perror("LoadConact::fopen");
		return;
	}
	//���ļ�
	struct PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfr) == 1)
	{
		//����Ƿ���Ҫ��������
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	//�ر��ļ�
	fclose(pfr);
	pfr = NULL;
}
void InitContact(struct contact* pc)
{
	assert(pc);
	pc->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (pc == NULL)
	{
		perror("AddContact()");
		return;
	}
	pc->sz = 0;
	pc->capacity = 3;
	LoadContact(pc);
}

//����ͨѶ¼
void DestroyContact(struct contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}
//��ͨѶ¼���������(��̬�汾)
//void AddContact(struct contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("ͨѶ¼����,�޷��������\n");
//		return;
//	}
//
//	//�����˵���Ϣ
//	printf("����������:>");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("�������Ա�:>");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("������绰:>");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("����������:>");
//	scanf("%d", &pc->data[pc->sz].age);
//	printf("�������ַ:>");
//	scanf("%s", pc->data[pc->sz].addr);
//	pc->sz++;
//	printf("�ɹ�������ϵ��\n");
//}


void AddContact(struct contact* pc)
{
	assert(pc);
	if (0 == CheckCapacity(pc))
	{
		printf("����ʧ�ܣ� �޷������Ϣ\n");
		return;
	}
	//�����˵���Ϣ
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("����������:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("�ɹ�������ϵ��\n");
}


//չʾͨѶ¼����Ϣ
void ShowContact(const struct contact* pc)
{
	if (pc->sz >= 1)
	{
		printf("%-20s\t%-5s\t%-5s\t%-5s\t%-30s\n","����", "�Ա�", "����", "�绰", "��ַ");
	}
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-5s\t%-30s\n", 
			pc->data[i].name,
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
//ɾ��ָ����ϵ��
void DelContact(struct contact* pc)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���˵�����:>");
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
	printf("ɾ���ɹ�\n");
}

//����ͨѶ¼�е���ϵ��
void SearchContact(struct contact* pc)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ��˵�����:>");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret != -1)
	{
		printf("%-20s\t%-5s\t%-5s\t%-5s\t%-30s\n", "����", 
			"�Ա�", "����", "�绰", "��ַ");
		printf("%-20s\t%-5s\t%-5d\t%-5s\t%-30s\n", pc->data[ret].name,
			pc->data[ret].sex,
			pc->data[ret].age,
			pc->data[ret].tele,
			pc->data[ret].addr
		);
	}
	else
	{
		printf("���ҵ���ϵ�˲����ڣ�\n");
	}
}

//�޸���ϵ�˵���Ϣ
void ModifyContact(struct contact* pc)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ���ϵ�˵�����:>");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����");
	}
	else
	{
		printf("����������:>");
		scanf("%s", pc->data[ret].name);
		printf("�������Ա�:>");
		scanf("%s", pc->data[ret].sex);
		printf("������绰:>");
		scanf("%s", pc->data[ret].tele);
		printf("����������:>");
		scanf("%d", &pc->data[ret].age);
		printf("�������ַ:>");
		scanf("%s", pc->data[ret].addr);
		printf("�ɹ��޸���ϵ��\n");
	}


}

int cmp_int(const void* a, const void* b)
{
	return ((struct PeoInfo*)b)->age - ((struct PeoInfo*)a)->age;
}
//������ϵ��(����)
void SortContact(struct contact* pc)
{
	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), cmp_int);
}

//����ͨѶ¼��Ϣ���ļ�
void SaveContact(struct contact* pc)
{
	//���ļ�
	FILE*pfw = fopen("contact.txt", "w");
	if (pfw == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	//д�ļ�
	for (int i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(struct PeoInfo), 1, pfw);
	}
	//�ر��ļ�
	fclose(pfw);
	pfw = NULL;
}