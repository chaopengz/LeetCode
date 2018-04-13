//
// Created by cpz on 2018/3/26.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define T 5                           //题目的个数，可以根据需求修改
int chouqu(int s[], int b);             //抽取题目函数
int jifen(char ans0[]);                //多选计分函数
int count = 1;

struct student                         //学生结构体
{
    int id;                            //学号
    char name[100];                    //姓名
    int score;                         //分数
};
typedef struct student student;

void maxmin(student q[], int b);        //最值、平均值函数
void paixu(student q[], int b);         //排序函数

struct exam                            //试题结构体
{
    int no;                            //题号
    char text[1000];                   //题身
    char answer[5];                    //答案
};
typedef struct exam exam;

void menu()                                                                   //一级菜单目录
{
    printf("\t\t----------------------------------------------\n\n\n");
    printf("\t\t\t   欢迎进入试题信息管理系统\n\n\n");
    printf("\t\t----------------------------------------------\n\n");
    printf("\t\t\t--------1.试题信息录入--------\n");
    printf("\t\t\t--------2.试题考试系统--------\n");
    printf("\t\t\t--------3.考试成绩查询--------\n");
    printf("\t\t\t--------0.退        出--------\n");
}


void menuInput1()                                                           //二级菜单目录
{
   
    printf("\t\t----------------------------------------------\n\n\n");
    printf("\t\t\t   欢迎进入试题信息管理系统\n\n\n");
    printf("\t\t----------------------------------------------\n\n");
    printf("\t\t\t--------1.录入试题信息--------\n");
    printf("\t\t\t--------2.修改试题信息--------\n");
    printf("\t\t\t--------3.增加试题信息--------\n");
    printf("\t\t\t--------4.删除试题信息--------\n");
    printf("\t\t\t--------5.查看试题信息--------\n");
    printf("\t\t\t--------0.返回上一级菜单------\n");
}

void menuInput2()                                                          //二级菜单目录
{
   
    printf("\t\t----------------------------------------------\n\n\n");
    printf("\t\t\t       祝您考出满意的成绩\n\n\n");
    printf("\t\t----------------------------------------------\n\n");
    printf("\t\t\t--------1.请输入您的学号------\n");
    printf("\t\t\t--------2.抽取题目------------\n");
    printf("\t\t\t--------3.开始考试------------\n");
    printf("\t\t\t--------0.返回上一级菜单------\n");
}

void menuInput3()                                                         //二级菜单目录
{
   
    printf("\t\t----------------------------------------------\n\n\n");
    printf("\t\t\t   欢迎进入试题信息管理系统\n\n\n");
    printf("\t\t----------------------------------------------\n\n");
    printf("\t\t\t-----1.查看全部分数--------------\n");
    printf("\t\t\t-----2.按成绩排名----------------\n");
    printf("\t\t\t-----3.最高分，最低分，平均分----\n");
    printf("\t\t\t-----0.返回上一级菜单------------\n");
}


void inputstudent(student a[])                      //学生信息录入函数
{
    printf("请先输入试题考试学生相关信息\n");
    int i;
    FILE *fp;                                            //文件打开判断，下同
    fp = fopen("./学生.txt", "rb+");
    if (fp == NULL)
    {
        printf("file cannot be opened");
        exit(1);
    }
    for (i = 0; i < 1; i++)                            //读入结构体,只输入一个学生
    {
        printf("请输入学号:");
        scanf("%d", &a[i].id);
        printf("请输入姓名:");
        scanf("%s", a[i].name);
        a[i].score = 0;
        fwrite(a + i, sizeof(student), 1, fp);       //写入文件，下同
    }
    getchar();
    printf("成功录入！\n 按回车进入试题信息管理系统。\n");
    getchar();
    fclose(fp);                                 //关闭文件，下同
}




void printstudent(student a[], int b)                 //学生信息读出函数
{
    int i;
    FILE *fp;
    fp = fopen("./学生.txt", "rb");
    if (fp == NULL)
    {
        printf("file cannot be opened");
        exit(1);
    }

    for (i = 0; i < b; i++)
        fread(a + i, sizeof(student), 1, fp);
    for (i = 0; i < b; i++)
        printf("%d,%s,%d\n", a[i].id, a[i].name, a[i].score);
    fclose(fp);
}



int inputquestion(exam a[], int b)                     //试题录入函数
{
    int i, j;
    FILE *fp;
    fp = fopen("./试题.txt", "rb+");
    if (fp == NULL)
    {
        printf("file cannot be opened");
        exit(1);
    }
    printf("请输入数据:\n");
    b = 0;                                     //count0清零
    for (i = 0; i < T; i++)
    {
        j = 0;
        printf("请输入题号:");
        scanf("%d", &a[i].no);
        printf("请输入题目:");
        getchar();
        {
            do
            {
                a[i].text[j] = getchar();
                j++;
            } while (a[i].text[j - 1] != '\n');
        }       //以回车结尾
        a[i].text[j - 1] = '\0';
        printf("请输入答案:");
        scanf("%s", a[i].answer);
        fwrite(a + i, sizeof(exam), 1, fp);
        b++;                                 //成功增加，coun0t++
    }
    getchar();
    printf("成功录入！\n");
    getchar();
    fclose(fp);
    return b;
}

void changequestion(exam a[], int b)                  //修改试题函数
{
    int i, j, chno;                                   //changenumber
    FILE *fp;
    fp = fopen("./试题.txt", "rb+");
    if (fp == NULL)
    {
        printf("file cannot be opened");
        exit(1);
    }
    j = 0;
    printf("请按照题号修改");
    printf("请输入题号:");
    scanf("%d", &chno);
    {
        for (i = 0; i < b; i++)                        //比较题号
            if (a[i].no == chno) break;
    }
    printf("请输入题目:");
    getchar();
    do
    {
        a[i].text[j] = getchar();
        j++;
    } while (a[i].text[j - 1] != '\n');
    a[i].text[j - 1] = '\0';
    printf("请输入答案:");
    scanf("%s", a[i].answer);
    for (i = 0; i < b; i++)
        fwrite(a + i, sizeof(exam), 1, fp);
    fclose(fp);
}

int addquestion(exam a[], int b)                      //试题增加函数
{
    exam new0;
    int i, j;
    FILE *fp;
    fp = fopen("./试题.txt", "ab+");
    if (fp == NULL)
    {
        printf("file cannot be opened\n");
        exit(1);
    }
    j = 0;
    printf("请输入你要增加的题目信息\n");
    printf("请输入题号:");
    scanf("%d", &new0.no);
    printf("请输入题目:");
    getchar();
    do                                       //将新题输入到结构体new0中
    {
        new0.text[j] = getchar();
        j++;
    } while (new0.text[j - 1] != '\n');
    new0.text[j - 1] = '\0';
    printf("请输入答案:");
    scanf("%s", new0.answer);
    for (i = 0; i < b; i++)                          //逐个比较题目是否存在
    {
        strcmp(a[i].text, new0.text);
        if (strcmp(a[i].text, new0.text) == 0)
            break;
    }
    if (strcmp(a[i].text, new0.text) != 0)                //不存在则输入,count0++
    {
        a[b].no = new0.no;
        strcpy(a[b].text, new0.text);
        strcpy(a[b].answer, new0.answer);
        fwrite(a + b, sizeof(exam), 1, fp);
        b++;
        getchar();
        printf("成功增加！\n");
        getchar();
    } else
    {
        getchar();
        printf("题目已存在！\n");
        getchar();
    }                                                  //已存在的提示,count0不变
    fclose(fp);
    return b;
}

int delquestion(exam a[], int b)                        //试题删除函数
{
    int i, j, k, delno;
    FILE *fp;
    fp = fopen("./试题.txt", "rb+");
    if (fp == NULL)
    {
        printf("file cannot be opened");
        exit(1);
    }
    printf("请输入你要删除的题目信息\n");
    printf("请输入题号:");
    scanf("%d", &delno);                        //删除的号码delno
    {
        for (i = 0; i < b; i++)
            if (a[i].no == delno) break;
    }
    if (i != b)                                   //排除非break跳出情况
    {
        for (k = i; k < b - 1; k++)
        {
            a[k].no = a[k + 1].no;
            strcpy(a[k].text, a[k + 1].text);
            strcpy(a[k].answer, a[k + 1].answer);     //成功覆盖,count0--
        }
        b--;
        getchar();
        printf("成功删除！\n");
        getchar();
    } else
    {
        getchar();
        printf("试题不存在！\n");              //删除不成功,count0不变
        getchar();
    }
    fclose(fp);
    fp = fopen("./试题.txt", "wb+");            //wb+形式打开保证切除赘余的一个结构体
    if (fp == NULL)
    {
        printf("file cannot be opened");
        exit(1);
    }

    for (k = 0; k < b; k++)
    {
        fwrite(a + k, sizeof(exam), 1, fp);
    }
    fclose(fp);

    return b;

}

void printquestion(exam a[], int b)                    //试题显示函数
{
    int i;
    FILE *fp;
    fp = fopen("./试题.txt", "rb+");
    if (fp == NULL)
    {
        printf("file cannot be opened");
        exit(1);
    }
    for (i = 0; i < b; i++)
    {
        fread(a + i, sizeof(exam), 1, fp);
        printf("%d,%s答案%s\n", a[i].no, a[i].text, a[i].answer);
    }
    fclose(fp);
}


void shitiluru(exam t[])                             //教师录入试题信息
{
    int choice;
    FILE *fp;
    char code[10] = "teacher", c[10];
    int count;
    fp = fopen("./试题.txt", "rb");
    if (fp == NULL)
    {
        printf("file cannot be opened");
        exit(1);
    }
    count = 0;
    while (fread(t, sizeof(exam), 1, fp) == 1)             //读取文件中原有试题数
        count++;
    //printf("%d",count);
    fclose(fp);
    printf("请输入密码：");
    scanf("%s", c);
    if (strcmp(c, code) == 0)                        //密码验证
    {
        do
        {
            menuInput1();

            printf("请选择:\n");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:                                     //试题录入
                    count = inputquestion(t, count);
                    break;
                case 2:                                     //试题修改
                    changequestion(t, count);
                    break;
                case 3:                                     //试题增加
                    count = addquestion(t, count);
                    break;
                case 4:                                     //试题删除
                    count = delquestion(t, count);
                    break;
                case 5:                                     //试题显示
                    printquestion(t, count);
                    getchar();
                    getchar();
                    break;
                case 0:
                    break;                              //返回上级菜单
            }
        } while (choice);
    } else
    {
        getchar();
        printf("密码错误!\n");
        getchar();
    }
}


void kaoshi(student s[], exam t[])                   //考试函数
{
    int count, count1;
    int choice, i, j, f, k, nono, grade = 0;                //nono记录抽到题目的数量
    char ch[10];                                    //姓名储存
    char ans[5], txt[1000];                          //答案、题目抽取
    int a[5];                                       //抽取题目储存
    int xuehao, xuehaojudge = 0;
    FILE *fp;
    fp = fopen("./学生.txt", "rb");
    if (fp == NULL)
    {
        printf("file cannot be opened");
        exit(1);
    }
    count = 0;
    while (fread(s, sizeof(student), 1, fp) == 1)
        count++;
    fclose(fp);

    do
    {
        menuInput2();
        printf("请选择:\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:                                 //输入学号
                fp = fopen("./学生.txt", "rb");
                if (fp == NULL)
                {
                    printf("file cannot be opened");
                    exit(1);
                }
                printf("请输入学号");
                scanf("%d", &xuehao);
                xuehaojudge = 0;
                for (i = 0; i < count; i++)
                    fread(s + i, sizeof(student), 1, fp);
                for (i = 0; i < count; i++)
                    if (s[i].id == xuehao)break;            //判断学号相等
                if (i != count)
                    xuehaojudge = 1;
                if (xuehaojudge == 1)
                {
                    strcpy(ch, s[i].name);
                    printf("您的姓名是：%s\n", ch);
                    printf("请抽取题目\n");
                } else
                    printf("您的学号不存在，请与老师联系\n");
                fclose(fp);
                getchar();
                getchar();
                break;

            case 2:                              //随机抽取试题
                fp = fopen("./试题.txt", "rb");
                if (fp == NULL)
                {
                    printf("file cannot be opened");
                    exit(1);
                }
                count1 = 0;
                while (fread(t, sizeof(exam), 1, fp) == 1)
                    count1++;
                fclose(fp);
                nono = chouqu(a, count1);
                getchar();
                getchar();
                break;

            case 3:                               //开始考试
                getchar();
                //printf("%d\n",nono);
                fp = fopen("./试题.txt", "rb+");
                if (fp == NULL)
                {
                    printf("file cannot be opened");
                    exit(1);
                }
                for (i = 0; i < 5; i++)                   //试题输出
                {
                    j = a[i];

                    {
                        for (k = 0; k < count1; k++)
                        {
                            f = 0;
                            fread(t + k, sizeof(exam), 1, fp);
                            {
                                if (t[k].no == j)
                                    f = 1;
                                strcpy(txt, t[k].text);
                                strcpy(ans, t[k].answer);
                                if (f == 1)
                                    break;
                            }
                        }
                        printf("%s", txt);
                        printf("请输入答案：\n");
                        grade += jifen(ans);             //加入总分

                    }
                    if (i == nono - 1) break;
                }
                printf("您的分数是%d\n\n", grade);
                fclose(fp);
                getchar();
                fp = fopen("./学生.txt", "rb+");
                if (fp == NULL)
                {
                    printf("file cannot be opened");
                    exit(1);
                }
                for (i = 0; i < count; i++)                    //分数写入
                { if (s[i].id == xuehao) break; }
                s[i].score = grade;
                for (i = 0; i < count; i++)
                    fwrite(s + i, sizeof(student), 1, fp);
                fclose(fp);
                break;

            case 0:                                 //返回上级菜单
                break;
        }
    } while (choice);
}

void chaxun(student s[])                            //学生信息查询函数
{
    int i, choice;
    int count;
    FILE *fp;
    fp = fopen("./学生.txt", "rb");
    if (fp == NULL)
    {
        printf("file cannot be opened");
        exit(1);
    }
    count = 0;                                        //重新获取学生数
    while (fread(s, sizeof(student), 1, fp) == 1)
        count++;
    fclose(fp);

    do
    {
        menuInput3();
        printf("请选择:\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:                                     //全部学生信息
                fp = fopen("./学生.txt", "rb+");
                if (fp == NULL)
                {
                    printf("file cannot be opened");
                    exit(1);
                }
                for (i = 0; i < count; i++)
                {
                    fread(s + i, sizeof(student), 1, fp);
                    printf("%d,%s,%d\n", s[i].id, s[i].name, s[i].score);
                }
                fclose(fp);
                getchar();
                getchar();
                break;
            case 2:                                    //成绩排名
                fp = fopen("./学生.txt", "rb+");
                if (fp == NULL)
                {
                    printf("file cannot be opened");
                    exit(1);
                }

                printf("显示排名：\n");
                {
                    for (i = 0; i < count; i++)
                        fread(s + i, sizeof(student), 1, fp);
                }

                paixu(s, count);                            //调用排序函数
                fclose(fp);
                getchar();
                getchar();
                break;
            case 3:                                    //最高分、最低分、平均分
                fp = fopen("./学生.txt", "rb+");
                if (fp == NULL)
                {
                    printf("file cannot be opened");
                    exit(1);
                }
                for (i = 0; i < count; i++)
                    fread(s + i, sizeof(student), 1, fp);

                maxmin(s, count);
                getchar();
                getchar();
                break;
            case 0:
                break;                              //跳出
        }
    } while (choice);
}

int chouqu(int s[], int b)
{
    int n, i, j, step;
    printf("请输入需要的题数，在1到5之间!\n");
    scanf("%d", &n);
    printf("loading…\n");
    if (n < 1 || n > 5)
        n = 5;                                         //默认n=5
    for (i = 0; i < n; i++)
    {
        srand((unsigned) time(NULL));                 //随机生成题号
        s[i] = rand() % b + 1;
        if (i != 0)                                     //选择一题的可能
            for (j = 0; j < i; j++)                             //选择多题时防重复
                if (s[i] == s[j])
                    i--;
    }
    if (n != 1)                                         //选择多题时
        for (j = n; j > 1; j--)                                 //题号排序
            for (i = n - 1; i > n - j; i--)
            {
                if (s[i] < s[i - 1])
                {
                    step = s[i];
                    s[i] = s[i - 1];
                    s[i - 1] = step;
                }
            }
    printf("您所抽取的题号为:\n");                   //输出
    for (i = 0; i < n; i++)
        printf("%d ", s[i]);
    printf("\n");
    return i;
}

int jifen(char ans0[])                               //多选计分函数
{
    int static sum;
    int n, change, i, step = 1, ans = 0, sco, right = 0, s[14] = {1, 3, 4, 9, 10, 12, 13, 27, 28, 30, 31, 36, 37, 39};
    //三进制下漏选对应的值
    char alter[5], head;//ans0[5];                    //所选答案、‘a’、正确答案
    //getchar();
    printf("请输入选项,以回车结尾。\n");

    do
    {                                              //循环开始的清零
        change = 0;
        n = 0;
        do                                           //输入所选答案
        {
            alter[n] = getchar();
            n++;
        } while (alter[n - 1] != '\n');
        for (i = 0; i < n - 1; i++)                               //答案不属于‘a’到‘d’的情况
        {
            if (alter[i] > 'd' || alter[i] < 'a')
            {
                printf("请重新输入'a'到'd'的小写英文选项！\n");
                break;
            }
            change++;                                    //判断是否有上述情况的变量
        }
    } while (change != n - 1);
    printf("您的答案是：");                          //输出确认答案
    for (i = 0; i < n - 1; i++)
        printf("%c", alter[i]);
    printf("\n");
    for (head = 'a'; head < 'e'; head++)                    //三进制计算答案对应数值
    {
        for (i = 0; i < n - 1; i++)
        {
            if (head == alter[i])
            {
                ans += step;
                break;                                   //考虑重复输入同一答案情况
            }
        }
        step = 3 * step;
    }
    step = 1;
    for (head = 'a'; head < 'e'; head++)                    //计算正确答案对应的三进制数值
    {
        for (i = 0; i < n; i++)
            if (head == ans0[i])
                right += step;
        step = 3 * step;
    }
    if (ans == 0)                                       //不选情况
        sco = 0;
    else if (right < ans)                               //多选、错选情况
        sco = 0;
    else if (right == ans)                              //选对情况
        sco = 20;
    else if (right > ans)                               //漏选、错选判断
    {
        sco = 0;
        for (i = 0; i < 14; i++)
            if (right - ans == s[i])
                sco = 10;
    }
    sum = sco;                                         //总分增加
    return sum;
}


void paixu(student q[], int b)                        //成绩排序函数
{
    int i, j, step, num[20];
    char nastep[100];
    student s[20];
    for (i = 0; i < b; i++)
    {
        num[i] = i + 1;                                     //名次初始化
        s[i].id = q[i].id;                                //不改变存根，只排序复制版本
        s[i].score = q[i].score;
        strcpy(s[i].name, q[i].name);
    }

    for (j = b; j > 1; j--)                                 //冒泡排序
        for (i = b - 1; i > 0; i--)
        {
            if (s[i].score > s[i - 1].score)
            {

                step = s[i].score;
                s[i].score = s[i - 1].score;
                s[i - 1].score = step;
                step = s[i].id;
                s[i].id = s[i - 1].id;
                s[i - 1].id = step;
                strcpy(nastep, s[i].name);
                strcpy(s[i].name, s[i - 1].name);
                strcpy(s[i - 1].name, nastep);
            }
        }
    for (i = 0; i < b; i++)                                 //同分情况
        if (s[i].score == s[i - 1].score)
            num[i] = num[i - 1];

    for (i = 0; i < b; i++)                                 //输出
        printf("排名：%d   学号：%d  姓名： %s  分数：%d\n", num[i], s[i].id, s[i].name, s[i].score);
    //return 0;
}


void maxmin(student q[], int b)                       //最值、均值函数
{
    int i, j, step, num[20];
    double sum = 0;
    char nastep[100];
    student s[20];
    for (i = 0; i < b; i++)
    {
        num[i] = i + 1;
        s[i].id = q[i].id;
        s[i].score = q[i].score;
        strcpy(s[i].name, q[i].name);
    }
    for (i = 0; i < b; i++)                                 //获取所有学生总分
        sum += s[i].score;
    for (j = b; j > 1; j--)                                 //冒泡排序
        for (i = b - 1; i > 0; i--)
        {
            if (s[i].score > s[i - 1].score)
            {

                step = s[i].score;
                s[i].score = s[i - 1].score;
                s[i - 1].score = step;
                step = s[i].id;
                s[i].id = s[i - 1].id;
                s[i - 1].id = step;
                strcpy(nastep, s[i].name);
                strcpy(s[i].name, s[i - 1].name);
                strcpy(s[i - 1].name, nastep);
            }
        }
    for (i = 0; i < b; i++)                                    //同分情况
        if (s[i].score == s[i - 1].score)
            num[i] = num[i - 1];
    i = 0;
    printf("最高分为:\n");
    do
    {
        printf("学号：%d  姓名： %s  分数：%d\n", s[i].id, s[i].name, s[i].score);
        i++;
    } while (num[i] == num[i - 1]);               //同为最高分一起输出
    i = b - 1;
    printf("最低分为:\n");
    do
    {
        printf("学号：%d  姓名： %s  分数：%d\n", s[i].id, s[i].name, s[i].score);
        i--;
    } while (num[i] == num[i + 1]);
    printf("平均分为:%.2lf\n", sum / b);       //平均分
    //return 0;
}


int main()                                          //主函数
{

    int choice;
    student stu[1];                                //学生结构体组
    exam que[100];                                  //试题结构体组
    inputstudent(stu);
    int count = 1;
    do
    {
        menu();
        printf("请选择:\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:                                     //试题录入
                shitiluru(que);
                break;
            case 2:                                     //考试
                kaoshi(stu, que);
                break;
            case 3:                                     //查询
                chaxun(stu);
                break;
            case 0:
                printf("   欢迎再次使用试题信息管理系统   \n");
        }
    } while (choice);
    return 0;
}
