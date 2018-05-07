//******************************************************

//*  �� �� ��: ְ����Ϣ����ϵͳ

//*  ��    ��: �ſ��ԡ���Т�֡��Ź�Ȼ

//*  ����ʱ��: 2016��1��2��

//*  ��Ҫ����: ְ����Ϣ����

//******************************************************

#include <stdio.h>

#include <windows.h>

#include <time.h>

#include <string.h>

#define N 100

struct employee
{

    int num;

    char name[10];

    char sex;

    int age;

    char xueli[30];

    int wage;

    char addr[30];

    long int tel;

} em[100];        /*����һ���ṹ��*/

void menu();

void input();

void save(int);

void display();

void del();

void add();

void search();

void search_num();

void search_xueli();

void search_tel();

void modify();  /*���������*/



void menu()   /*�˵�����*/

{

//printf("              ����������ѧ�뼼������\n");

    //printf("\n");

    //printf("                                   ��1401B�� ��\n");

    printf("\n");

    printf("        ******************��ӭ����ְ����Ϣ����ϵͳ****************\n");

    printf("           1.¼��ְ����Ϣ");

    printf("           2.���ְ����Ϣ\n");

    printf("           3.��ѯְ����Ϣ");

    printf("           4.ɾ��ְ����Ϣ\n");

    printf("           5.���ְ����Ϣ");

    printf("           6.�޸�ְ����Ϣ\n");

    printf("           7.�˳�\n");

    printf("        ********************ллʹ��******************\n");

    printf("\n");

    printf("\n");

}

int main()
{

    menu();  /*���ò˵�����*/

    int n, flag;

    char a;

    do
    {

        printf("��ѡ������Ҫ�����Ĳ���(1--7):\n");

        scanf("%d", &n);

        if (n >= 1 && n <= 7)
        {

            flag = 1;

            break;

        } else
        {

            flag = 0;

            printf("����������������ѡ��!");

        }

    } while (flag == 0);

    while (flag == 1)
    {

        switch (n)
        {

            case 1:
                printf("               ����������ְ����Ϣ������\n");
                printf("\n");
                input();
                break;

            case 2:
                printf("              ���������ְ����Ϣ������\n");
                printf("\n");
                display();
                break;

            case 3:
                printf("              ��������ְ���Ų�ѯְ����Ϣ������\n");
                printf("\n");
                search();
                break;

            case 4:
                printf("              ������ɾ��ְ����Ϣ������\n");
                printf("\n");
                del();
                break;

            case 5:
                printf("              ���������ְ����Ϣ������\n");
                printf("\n");
                add();
                break;

            case 6:
                printf("               �������޸�ְ����Ϣ������\n");
                printf("\n");
                modify();
                break;

            case 7:
                exit(0);
                break;

            default :
                break;

        }

        getchar();

        printf("\n");

        printf("�Ƿ��������(y or n):\n");

        scanf("%c", &a);

        if (a == 'y')
        {

            flag = 1;

            system("cls");  /*����*/

            menu(); /*���ò˵�����*/

            printf("���ٴ�ѡ������Ҫ�����Ĳ���(1--6):\n");

            scanf("%d", &n);

            printf("\n");

        } else

            exit(0);

    }

}


void input()   /*¼�뺯��*/

{

    int i, m;

    printf("��������Ҫ������Ϣ��ְ������(1--100):\n");

    scanf("%d", &m);

    for (i = 0; i < m; i++)
    {

        printf("ְ���ţ� ");

        srand((int) time(0));

        em[i].num = rand() % 10000 + 20000000;

        if (em[i].num != em[i - 1].num)

            printf("%8d ", em[i].num);

        printf("\n");

        printf("����������:  ");

        scanf("%s", em[i].name);

        getchar();

        printf("�������Ա�(f--Ů  m--��):  ");

        scanf("%c", &em[i].sex);

        printf("����������:  ");

        scanf("%d", &em[i].age);

        printf("������ѧ��:  ");

        scanf("%s", em[i].xueli);

        printf("�����빤��:  ");

        scanf("%d", &em[i].wage);

        printf("������סַ:  ");

        scanf("%s", em[i].addr);

        printf("������绰:  ");

        scanf("%d", &em[i].tel);

        printf("\n");

    }

    printf("\n�������!\n");

    save(m);

}

void save(int m)  /*�����ļ�����*/

{

    int i;

    FILE *fp;

    if ((fp = fopen("employee.txt", "w")) == NULL)  /*�����ļ����ж��Ƿ��ܴ�*/

    {

        printf("cannot open file\n");

        exit(0);

    }

    for (i = 0; i < m; i++) /*���ڴ���ְ������Ϣ����������ļ���ȥ*/

        if (fwrite(&em[i], sizeof(struct employee), 1, fp) != 1)

            printf("file write error\n");

    fclose(fp);

}


int load()  /*���뺯��*/

{

    FILE *fp;

    int i = 0;

    if ((fp = fopen("employee.txt", "r")) == NULL)
    {

        printf("cannot open file\n");

        exit(0);

    } else
    {

        do
        {

            fread(&em[i], sizeof(struct employee), 1, fp);

            i++;

        } while (feof(fp) == 0);

    }

    fclose(fp);

    return (i - 1);

}

void display()  /*�������*/

{

    int i;

    int m = load();

    printf("\n  ְ����\t����\t�Ա�\t����\tѧ��\t����\tסַ\t�绰   \n");

    for (i = 0; i < m; i++) /*mΪ���벿�ֵ�ְ������*/

        printf("\n  %d\t%s\t%c\t%d\t%s\t%d\t%s\t%ld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].xueli,
               em[i].wage, em[i].addr, em[i].tel);

}

void del()   /*ɾ������*/

{

    int m = load();

    int i, j, n, t, flag;

    char name[20];

    printf("\n ԭ����ְ����Ϣ:\n");

    display();   /* �����������*/

    printf("\n");

    printf("������Ҫɾ����ְ��������:\n");

    scanf("%s", name);

    for (flag = 1, i = 0; flag && i < m; i++)
    {

        if (strcmp(em[i].name, name) == 0)
        {

            printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n");

            printf("\nְ����\t����\t�Ա�\t����\tѧ��\t����\tסַ\t�绰   \n");

            printf("\n%d\t%s\t%c\t%d\t%s\t%d\t%s\t%ld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].xueli,
                   em[i].wage, em[i].addr, em[i].tel);

            printf("\nȷʵҪɾ��������Ϣ�밴1,��ɾ���밴0\n");

            scanf("%d", &n);

            if (n == 1)   /*���ɾ��������������Ϣ��������һ��*/

            {

                for (j = i; j < m - 1; j++)
                {

                    strcpy(em[j].name, em[j + 1].name);

                    em[j].num = em[j + 1].num;

                    em[j].sex = em[j + 1].sex;

                    em[j].age = em[j + 1].age;

                    strcpy(em[j].xueli, em[j + 1].xueli);

                    em[j].wage = em[j + 1].wage;

                    strcpy(em[j].addr, em[j + 1].addr);

                    em[j].tel = em[j + 1].tel;

                }

                flag = 0;

            }

        }

    }

    if (!flag)

        m = m - 1;

    else

        printf("\n�Բ��𣬲��޴���!\n");

    printf("\n ���ɾ���������ְ����Ϣ:\n");

    save(m);     /*���ñ��溯��*/

    display();  /*�����������*/

    printf("\n����ɾ���밴1������ɾ���밴0\n");

    scanf("%d", &t);

    switch (t)
    {

        case 1:
            del();
            break;

        case 0:
            break;

        default :
            break;

    }

}

void add()/*��Ӻ���*/

{

    FILE *fp;

    int n;

    int count = 0;

    int i;

    int m = load();

    printf("\n ԭ����ְ����Ϣ:\n");

    display();   /* �����������*/

    printf("\n");

    fp = fopen("employee.txt", "a");

    printf("�����������ӵ�ְ����:\n");

    scanf("%d", &n);

    for (i = m; i < (m + n); i++)
    {

        printf("\n ������������ְ������Ϣ:\n");

        printf("������ְ����:  ");

        srand((int) time(0));

        em[i].num = rand() % 10000 + 20000000;

        if (em[i].num != em[i - 1].num)

            printf("%8d ", em[i].num);

        printf("\n");

        printf("����������:  ");

        scanf("%s", em[i].name);

        getchar();

        printf("�������Ա�(f--Ů  m--��):  ");

        scanf("%c", &em[i].sex);

        printf("����������:  ");

        scanf("%d", &em[i].age);

        printf("������ѧ��:  ");

        scanf("%s", em[i].xueli);

        printf("�����빤��:  ");

        scanf("%d", &em[i].wage);

        printf("������סַ:  ");

        scanf("%s", em[i].addr);

        printf("������绰:  ");

        scanf("%d", &em[i].tel);

        printf("\n");

        count = count + 1;

        printf("�����ӵ�����:\n");

        printf("%d\n", count);

    }

    printf("\n������!\n");

    m = m + count;

    printf("\n������Ӻ������ְ����Ϣ:\n");

    printf("\n");

    save(m);

    display();

    fclose(fp);

}

void search()/*��ѯ����*/

{

    int t, flag;

    do
    {

        printf("\n��ְ���Ų�ѯ�밴1 ; ��ѧ����ѯ�밴2 ; ���绰�����ѯ�밴3,������������4\n");

        scanf("%d", &t);

        if (t >= 1 && t <= 4)
        {

            flag = 1;

            break;

        } else
        {

            flag = 0;

            printf("����������������ѡ��!");

        }

    } while (flag == 0);

    while (flag == 1)
    {

        switch (t)
        {

            case 1:
                printf("��ְ���Ų�ѯ\n");
                search_num();
                break;

            case 2:
                printf("��ѧ����ѯ\n");
                search_xueli();
                break;

            case 3:
                printf("���绰�����ѯ\n");
                search_tel();
                break;

            case 4:
                main();
                break;

            default:
                break;

        }

    }

}

void search_num()
{

    int num;

    int i, t;

    int m = load();

    printf("������Ҫ���ҵ�ְ����(20001111---20009999):\n");

    scanf("%d", &num);

    for (i = 0; i < m; i++)

        if (num == em[i].num)
        {

            printf("\n���ҵ����ˣ����¼Ϊ��\n");

            printf("\nְ����\t\t����\t�Ա�\t����\tѧ��\t����\tסַ\t�绰   \n");

            printf("\n%d\t%s\t%c\t%d\t%s\t%d\t%s\t%ld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].xueli,
                   em[i].wage, em[i].addr, em[i].tel);

            break;

        }

    if (i == m)

        printf("\n��ѯ����\n");

    printf("\n");

    printf("���ز�ѯ�����밴1,������ѯְ�����밴2\n");

    scanf("%d", &t);

    switch (t)
    {

        case 1:
            search();
            break;

        case 2:
            break;

        default:
            break;

    }

}

void search_xueli()
{

    char xueli[30];

    int i, t;

    int m = load();

    printf("������Ҫ���ҵ�ѧ��:\n");

    scanf("%s", xueli);

    for (i = 0; i < m; i++)

        if (strcmp(em[i].xueli, xueli) == 0)
        {

            printf("\n���ҵ������¼Ϊ��\n");

            printf("\nְ����\t\t����\t�Ա�\t����\tѧ��\t����\tסַ\t�绰   \n");

            printf("\n%d\t%s\t%c\t%d\t%s\t%d\t%s\t%ld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].xueli,
                   em[i].wage, em[i].addr, em[i].tel);

        }

    if (i == m)

        printf("\n��ѯ����\n");

    printf("\n");

    printf("���ز�ѯ�����밴1,������ѯѧ���밴2\n");

    scanf("%d", &t);

    switch (t)
    {

        case 1:
            search();
            break;

        case 2:
            break;

        default :
            break;

    }

}

void search_tel()
{

    long int tel;

    int i, t;

    int m = load();

    printf("������Ҫ���ҵĵ绰����:\n");

    scanf("%ld", &tel);

    for (i = 0; i < m; i++)

        if (tel == em[i].tel)
        {

            printf("\n���ҵ����ˣ����¼Ϊ��\n");

            printf("\nְ����\t\t����\t�Ա�\t����\tѧ��\t����\tסַ\t�绰   \n");

            printf("\n%d\t%s\t%c\t%d\t%s\t%d\t%s\t%ld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].xueli,
                   em[i].wage, em[i].addr, em[i].tel);

            break;

        }

    if (i == m)

        printf("\n��ѯ����\n");

    printf("\n");

    printf("���ز�ѯ�����밴1,������ѯ�绰�����밴2\n");

    scanf("%d", &t);

    switch (t)
    {

        case 1:
            search();
            break;

        case 2:
            break;

        default :
            break;

    }

}

void modify() /*�޸ĺ���*/

{

    int num;

    char name[10];

    char sex;

    int age;

    char xueli[30];

    int wage;

    char addr[30];

    long int tel;

    int b, c, i, n, t, flag;

    int m = load(); /*�����ļ��ڵ���Ϣ*/

    printf("\n ԭ����ְ����Ϣ:\n");

    display();   /* �����������*/

    printf("\n");

    printf("������Ҫ�޸ĵ�ְ��������:\n");

    scanf("%s", name);

    for (flag = 1, i = 0; flag && i < m; i++)
    {

        if (strcmp(em[i].name, name) == 0)
        {

            printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n");

            printf("\nְ����\t\t����\t�Ա�\t����\tѧ��\t����\tסַ\t�绰   \n");

            printf("\n%d\t%s\t%c\t%d\t%s\t%d\t%s\t%ld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].xueli,
                   em[i].wage, em[i].addr, em[i].tel);

            printf("\nȷʵҪ�޸Ĵ�����Ϣ�밴1 ; ���޸��밴0\n");

            scanf("%d", &n);

            if (n == 1)
            {

                printf("\n��Ҫ�����޸ĵ�ѡ��\n 1.ְ���� 2.���� 3.�Ա� 4.���� 5.ѧ�� 6.���� 7.סַ 8.�绰\n");

                printf("�����������޸ĵ���һ�����:\n");

                scanf("%d", &c);

                if (c > 8 || c < 1)

                    printf("\nѡ�����������ѡ��!\n");

            }

            flag = 0;

        }

    }

    if (flag == 1)

        printf("\n��ѯ����\n");

    do
    {

        switch (c)      /*��Ϊ���ҵ���i��ְ��ʱ,for����i�Լ���1,���������Ӧ�ðѸĺ����Ϣ��ֵ����i-1����*/

        {

            case 1:
                printf("ְ���Ÿ�Ϊ: ");
                scanf("%d", &num);

                em[i - 1].num = num;
                break;

            case 2:
                printf("������Ϊ: ");
                scanf("%s", name);

                strcpy(em[i - 1].name, name);
                break;

            case 3:
                printf("�Ա��Ϊ: ");
                getchar();
                scanf("%c", &sex);

                em[i - 1].sex = sex;
                break;

            case 4:
                printf("�����Ϊ: ");
                scanf("%d", &age);

                em[i - 1].age = age;
                break;

            case 5:
                printf("ѧ����Ϊ: ");
                scanf("%s", xueli);

                strcpy(em[i - 1].xueli, xueli);
                break;

            case 6:
                printf("���ʸ�Ϊ: ");
                scanf("%d", wage);
                break;

            case 7:
                printf("סַ��Ϊ: ");
                scanf("%s", addr);

                strcpy(em[i - 1].addr, addr);
                break;

            case 8:
                printf("�绰��Ϊ: ");
                scanf("%ld", &tel);
                em[i - 1].tel = tel;
                break;

        }

        printf("\n");

        printf("\n�Ƿ�ȷ�����޸ĵ���Ϣ?\n �� �밴1 ; ��,�����޸� �밴2:  \n");

        scanf("%d", &b);

    } while (b == 2);

    printf("\n����޸ĺ������ְ����Ϣ:\n");

    printf("\n");

    save(m);

    display();

    printf("\n�����޸��밴1�������޸��밴0\n");

    scanf("%d", &t);

    switch (t)
    {

        case 1:
            modify();
            break;

        case 0:
            break;

        default :
            break;
    }

}