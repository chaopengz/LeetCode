////
//// Created by cpz on 2018/3/10.
////
//
//#include<stdio.h>
//#include<string.h>
//#include <stdlib.h>
//
//#define N 100 /*最多存储100个课程的信息*/
//struct class {
//    char id[20];/*课程编号*/
//    char name[25];/*课程名称*/
//    int score;/*学分*/
//    char pre[20];/*先修课号*/
//    char teacher[50];/*任课教师*/
//
//} course[N];
//
//void printf_one(int k) /*输出一个课程的信息*/
//{
//    printf("课程编号：%s\n", course[k].id);
//    printf("课程名称：%s\n", course[k].name);
//    printf("课程学分：%d\n", course[k].score);
//    printf("先修课号：%s\n", course[k].pre);
//    printf("任课老师：%s\n", course[k].teacher);
//}
//
//void printf_n(int n) /*浏览时输出所有课程的信息*/
//{
//    int j, i = 1;
//    for (j = 0; j < n; j++)
//    {
//        printf("第%d个课程：\n", i++);
//        printf_one(j);
//        printf("\n");
//    }
//    getchar();
//}
//
//int load() /*打开文件,读取里面的数据*/
//{
//    FILE *fp;
//    int i;
//    if ((fp = fopen("./course.txt", "rb")) == NULL) /*读入空文件，rb表示打开一个二进制文件，只允许读数据*/
//    {
//        printf("\n文件不存在!请输入:\n");
//        return 0;
//    }
//    for (i = 0; !feof(fp); i++)  /*处理到文件结尾*/
//        fread(&course[i], sizeof(struct class), 1, fp);
//    fclose(fp);
//    return (i - 1);
//}
//
//void input(int k) /*输入课程信息*/
//{
//
//    puts("课程编号："),
//            scanf("%s", course[k].id),
//            printf("\n");
//    puts("课程名称："),
//            scanf("%s", course[k].name),
//            printf("\n");
//    puts("课程学分："),
//            scanf("%d", &course[k].score),
//            printf("\n");
//    printf("先修课号："),
//            scanf("%s", course[k].pre),
//            printf("\n");
//    printf("任课教师："),
//            scanf("%s", course[k].teacher),
//            printf("\n");
//}
//
//void save(int n) /*保存课程信息*/
//{
//    FILE *fp;
//    int i;
//    if ((fp = fopen("./course.txt", "wb")) == NULL) /*只打开或建立一个二进制文件，只允许写数据*/
//    {
//        printf("\nCan not open file!\n");
//        exit(0);
//    }
//    for (i = 0; i < n; i++)
//        if (course[i].name[0] != '\0')
//            if (fwrite(&course[i], sizeof(struct class), 1, fp) != 1) /*将一批数据作为一个整体一次性写入磁盘文件*/
//                printf("文件写入错误!\n");
//    fclose(fp);
//}
//
//void printf_back()/*添加课程信息后显示的“是浏览还是返回”*/
//{
//    int w, k = 0;
//    void browse();
//    void menu();
//    printf("\n\n\t^_^.插入成功. ^_^\n\n");
//    do
//    {
//        printf("What do you want to do next?\n\n\t1).浏览所有\t2).返回:  [ ]\b\b");
//        scanf("%d", &w);
//        if (w == 1)
//        {
//            browse();
//        } else if (w == 2)
//        {
//            menu();
//        } else
//            printf("  选择错误!请重新选择!\n");
//    } while (k == 0);
//}
//
//void insert() /*添加课程信息*/
//{
//    int i, n, k, t;
//    FILE *fp;
//    if ((fp = fopen("./course.txt", "rb")) == NULL) /*读入空文件，rb表示打开一个二进制文件，只允许读数据*/
//    {
//        printf("How many people do you want to add(1-%d)?:", N - 1);
//        n = 0;
//    } else
//    {
//        n = load();
//        printf("How many student do you want to insert (1-%d)?:", N - n - 1);
//    }
//    scanf("%d", &t);
//    k = n + t;
//    for (i = n; i < k; i++)
//    {
//        printf("\n输入第 %d 个课程信息.\n", i - n + 1);
//        input(i);
//    }
//    save(k); /*保存所有课程的信息*/
//    printf_back();
//}
//
//void deleter() /*删除*/
//{
//    void menu();
//
//    struct class s;
//    int i, n, k, w0, w1;
//    n = load();
//    do
//    {
//        k = -1;
//        do
//        {
//            printf("\n\n请输入您想要删除的课程的课程编号!\nName:");
//            scanf("%s", s.id);
//            for (i = 0; i < n; i++)
//                if (strcmp(s.id, course[i].id) == 0)
//                {
//                    k = i;
//                    s = course[i];
//                }
//            if (k == -1)
//            {
//                int m;
//                printf("\n\n没有这个课程的信息!\n");
//                printf("What do you want to do next? 1.继续输入  2.返回主菜单    [ ]\b\b");
//                scanf("%d", &m);
//                if (m == 1)
//                    deleter();
//                else
//                {
//                    k = 0;
//                    menu();
//                }
//            }
//        } while (k == -1);
//        printf_one(k);
//        printf("\n\t确定删除?\n\t1).是   2).返回  [ ]\b\b");/*再次询问是否删除*/
//        scanf("%d", &w0);
//        if (w0 == 1)
//        {
//            course[k].id[0] = '\0';
//            save(n);
//        } else
//            break;
//        printf("\n\t^_^.成功删除^_^.\n");
//        printf("What do you want to do?\n\t1).继续   2).返回  [ ]\b\b");
//        scanf("%d", &w1);
//    } while (w1 == 1);
//    menu(); /*不再删除时返回主菜单，w1!=1*/
//}
//
//void search() /*查询*/
//{
//    void menu();
//    int w0, k, i, n, w1, w2;
//    struct class s;
//    FILE *fp;
//    if ((fp = fopen("./course.txt", "rb")) != NULL) /*不是空文件*/
//        n = load();
//    do
//    {
//        printf("请选择查找类别:  1.课程编号  2.课程名称   [ ]\b\b");
//        scanf("%d", &w1);
//        if (w1 < 1 || w1 > 2)
//        {
//            printf("输入错误!请重新输入!\n");
//            w2 = 1;
//        } else
//            w2 = 0; /*这里要注意：不加这句话会陷入死循环，跳不出来*/
//    } while (w2 == 1);
//    if (w1 == 1) /*按课程编号查找*/
//    {
//        do
//        {
//            k = -1;
//            do
//            {
//                printf("\n请输入您想要查找的课程的编号!\nId:");
//                scanf("%s", s.id);
//                for (i = 0; i < n; i++)
//                    if (strcmp(s.id, course[i].id) == 0)
//                    {
//                        k = i;
//                        s = course[i];
//                    }
//                if (k == -1) /*没有找到*/
//                {
//                    int o;
//                    printf("\n\n没有这个课程的信息!\n!");
//                    printf("What do you want to do?\n\t1.继续    2.返回菜单  [ ]\b\b");
//                    scanf("%d", &o);
//                    if (o == 1)
//                    {
//                        search(); /*继续查找*/
//                    } else
//                    {
//                        menu();
//                    }
//                }
//            } while (k == -1);
//            printf_one(k); /*找到以后输出这个课程的信息*/
//            printf("\nWhat do you want to do next?\n\t1).继续    2).返回菜单   [ ]\b\b");
//            scanf("%d", &w0);
//        } while (w0 == 1);
//        menu(); /*不再查找时返回主菜单*/
//    } else /*按课程名称查找*/
//    {
//        do
//        {
//            k = -1;
//            do
//            {
//                printf("\n请输入您想要查找的课程的名称!\nName:");
//                scanf("%s", s.name);
//                for (i = 0; i < n; i++)
//                    if (strcmp(s.name, course[i].name) == 0) /*找到了*/
//                    {
//                        k = i;
//                        s = course[i];
//                    }
//                if (k == -1) /*没有找到*/
//                {
//                    int o;
//                    printf("\n\n没有这个课程的信息!\n!");
//                    printf("What do you want to do?\n\t1.继续    2.返回菜单  [ ]\b\b");
//                    scanf("%d", &o);
//                    if (o == 1)
//                    {
//                        search(); /*继续查找*/
//                    } else
//                    {
//                        menu();
//                    }
//                }
//            } while (k == -1);
//            printf_one(k); /*找到以后输出这个课程的信息*/
//            printf("\nWhat do you want to do?\n\t1).继续   2).返回菜单   [ ]\b\b");
//            scanf("%d", &w0);
//        } while (w0 == 1);
//        menu();/*不再查找时返回主菜单*/
//    }
//}
//
//int modify_data(int i) /*修改课程信息函数*/
//{
//    int c, w1;
//    void menu();
//    do
//    {
//        puts("\n请选择要修改的选项：\n\n1.课程编号 2.课程名称  3.课程学分  4.先修课号  5.任课教师 6.所有信息 7.取消并返回");
//        printf("请选择?: [  ]\b\b\b");
//        scanf("%d", &c);
//        if (c > 7 || c < 1)
//        {
//            puts("\n选择错误!请重新选择!");
//            getchar();
//        }
//    } while (c > 7 || c < 1);
//    do
//    {
//        switch (c)
//        {
//            case 1:
//                printf("课程编号:");
//                scanf("%s", course[i].id);
//                break;
//            case 2:
//                printf("课程名称:");
//                scanf("%s", course[i].name);
//                break;
//            case 3:
//                printf("课程学分:");
//                scanf("%d", &course[i].score);
//                break;
//            case 4:
//                printf("先修课号:");
//                scanf("%s", course[i].pre);
//                break;
//            case 5:
//                printf("任课教师:");
//                scanf("%s", course[i].teacher);
//                break;
//            case 11:
//                input(i);
//                break;  /*修改这个课程的所有信息*/
//            case 12:
//                menu();  /*返回主菜单*/
//        }
//        puts("\nNow:\n");
//        printf_one(i); /*输出 修改后 的这个课程的信息*/
//        printf("\n确定?\n\n\t1).是  2).不，重新修改  3).返回不保存 [ ]\b\b");
//        scanf("%d", &w1);
//    } while (w1 == 2);
//    return (w1); /*修改成功并选择1后返回1*/
//}
//
//void modify() /*修改*/
//{
//    void menu();
//
//    struct class s;
//    int i, n, k, w0 = 1, w1, w2 = 0;
//    n = load();
//    do
//    {
//        k = -1;
//        do
//        {
//            printf("\n请输入您想要修改的课程的课程编号!\nId:");
//            scanf("%s", s.id);
//            for (i = 0; i < n; i++)
//                if (strcmp(s.id, course[i].id) == 0) /*与其中一个课程匹配*/
//                {
//                    k = i;
//                    s = course[i];
//                }
//            if (k == -1) /*没有找到输入的课程*/
//            {
//                int o;
//                printf("\n\n没有这个课程的信息!\n");
//                printf("What do you want to do?\n\t1.继续    2.返回菜单  [ ]\b\b");
//                scanf("%d", &o);
//                if (o == 1)
//                {
//                    modify(); /*继续修改*/
//                } else
//                {
//                    menu();
//                }
//            }
//        } while (k == -1);
//        printf_one(k); /*输出这个课程的信息*/
//        w1 = modify_data(k);
//        if (w1 == 1) /*判断是否修改成功修改*/
//        {
//            printf("\n\t^_^.修改成功 ^_^.\n\n是否继续?\n\n\t1).是 2).保存返回\t[ ]\b\b");
//            scanf("%d", &w0);
//            w2 = 1;
//        } else
//        {
//            w0 = 0;
//            if (w2 == 0)
//                course[k] = s;
//        }
//        if ((w0 != 1) && (w2 == 1)) /*修改成功保存*/
//            save(n);
//    } while (w0 == 1);
//    menu();/*不再修改返回主菜单*/
//
//}
//
//void browse()/*浏览*/
//{
//    void menu();
//    int n;
//    n = load();
//    printf_n(n);
//    printf("  共有 %d 个课程的记录.\n", n);
//    menu(); /*返回主函数*/
//}
//
//int CMP1(const struct class *a, const struct class *b)//课程编号排序
//{
//    if (strcmp(a->id, b->id) > 0)
//        return 1;
//    else if (strcmp(a->id, b->id) == 0)
//        return 0;
//    else
//        return -1;
//}
//
//int CMP2(const struct class *a, const struct class *b)//课程学分排序
//{
//    if (a->score > b->score)
//        return -1;
//    else if (a->score == b->score)
//        return 0;
//    else
//        return 1;
//}
//
//void sort()
//{
//    void menu();
//    int n, c = -1;
//    n = load();
//    while (c < 1 || c > 2)
//    {
//        printf("请输入排序依据： 1：课程编号，2：课程学分\n");
//        scanf("%d", &c);
//    }
//    if (c == 1)//课程编号排序
//    {
//        qsort(&course, n, sizeof(struct class), CMP1);
//    } else//课程学分排序
//    {
//        qsort(&course, n, sizeof(struct class), CMP2);
//    }
//    save(n);
//    menu();
//}
//
//
//void exit() /*退出*/
//{
//    exit(0);
//}
//
//void face()  /*访问页面*/
//{
//    printf("\n\t    ★ ★ ★ ★ ★ ★  ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★\n\n");
//    puts("\t    ※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
//    puts("\t    ※※                                              ※※");
//    puts("\t    ※※                                              ※※");
//    puts("\t    ※※           欢迎访问课程信息管理系统!             ※※");
//    puts("\t    ※※                                              ※※");
//    puts("\t    ※※                                              ※※");
//    puts("\t    ※※                                              ※※");
//    puts("\t    ※※                                              ※※");
//    puts("\t    ※※                                制作人：李子昂  ※※");
//    puts("\t    ※※                                   2018.3.11  ※※");
//    puts("\t    ※※                                              ※※");
//    puts("\t    ※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
//}
//
//void menu() /*主菜单*/
//{
//    printf("\n\t\t\t欢迎使用课程信息管理系统!\n");
//    printf("\n");
//    int n, w1;
//    do
//    {
//        puts("\t\t★★★★★★★★★★★★★★    菜单  ★★★★★★★★★★★★★★");
//        puts("\t\t★               1.插  入             ★");
//        puts("\t\t★               2.删  除             ★");
//        puts("\t\t★               3.查  询             ★");
//        puts("\t\t★               4.修  改             ★");
//        puts("\t\t★               5.浏  览             ★");
//        puts("\t\t★               6.排  序             ★");
//        puts("\t\t★               7.退  出             ★");
//        puts("\t\t★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★");
//        printf("请选择服务种类(1-7) : [ ]\b\b");
//        scanf("%d", &n);
//        if (n < 1 || n > 7)
//        {
//            printf("选择错误!  请重新选择!\n");
//            w1 = 1;
//        } else
//            w1 = 0;
//    } while (w1 == 1);
//    switch (n)
//    {
//        case 1:
//            insert();
//            break; /*插入*/
//        case 2:
//            deleter();
//            break; /*删除*/
//        case 3:
//            search();
//            break; /*查找*/
//        case 4:
//            modify();
//            break; /*修改*/
//        case 5:
//            browse();
//            break; /*浏览*/
//        case 6:
//            sort();
//            break;
//        case 7:
//            exit(0);
//            break; /*退出*/
//    }
//}
//
////int main()
////{
////    face();
////    menu();
////    return 0;
////}