#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define LEN sizeof(stu)
//定义一个结构体
typedef struct stu
{
    int ID;
    int score;
    struct stu *next;
}stu;
//声明
stu *input();
void output(stu *head);
stu *dele(stu*head,int DID);
stu *increase(stu *head,int AID);
stu *lookfor(stu *head, int LID);
stu *front(stu *head,int AID);
stu *sort(stu *head);
//输入
stu *input()
{
    printf("输入:\n");
    stu *p1, *p2, *head = NULL;
    p1 = p2 = (stu *)malloc(LEN);
    scanf("%d%d", &p1->ID, &p1->score);
    if(p1->ID==0)
    {
        return head;
    }
    else
    {
        head = p1;
    }
    while(p1->ID!=0)
    {
        p2->next = p1;
        p2 = p1;
        p1 = (stu *)malloc(LEN);
        scanf("%d%d", &p1->ID, &p1->score);
    }
    p2->next = NULL;
    return head;
}
//输出
void output(stu *head)
{
    printf("输出:\n");
    stu *p;
    p = head;
    int i = 1;
    while(p!=NULL)
    {
        printf("%2d|  %d   %d\n",i, p->ID, p->score);
        p = p->next;
        i++;
    }
}
//删除
stu *dele(stu*head,int DID)
{
    printf("删除以后的是\n");
    stu *p1, *p2;
    if(head->ID==DID)
    {
        p1 = head->next;
        free(head);
        return p1;
    }
    else
    {
        for (p1 = head, p2 = p1; p1 != NULL;p2=p1,p1=p1->next)
        {
            if(p1->ID==DID)
            {
                p2->next = p1->next;
                free(p1);
                return head;
            }
        }
    }
    printf("SORRY,YOU WANTDE ID NO FIND.\n原数据如下：\n");
    return head;//争议地区  head or NULL?
}
//后部增加
stu *increase(stu *head,int AID)
{
    stu *p, *p1;
    p = (stu *)malloc(LEN);
    printf("请输入你要插入的数据：\n");
    scanf("%d%d", &p->ID, &p->score);
    for (p1 = head; p1 != NULL;p1=p1->next)
    {
        if(p1->ID==AID)
        {
            p->next = p1->next;
            p1->next = p;
            return head;
        }
    }
    printf("SORRY,没有找到该位置\n");
    return head;
}
//检索
stu *lookfor(stu *head, int LID)
{
    stu *p1;
    for (p1 = head; p1 != NULL;p1 = p1->next)
    {
        if(p1->ID==LID)
        {
            return p1;
        }
    }
    return NULL;
}
//前部增加
stu *front(stu *head,int AID)
{
    stu *p1, *p2,*p;
    p = (stu *)malloc(LEN);
    printf("请输入你要插入的数据：\n");
    scanf("%d%d", &p->ID, &p->score);
    if(head->ID==AID)
    {
        p->next = head;
        return p;
    }
    else
    {
        for (p1 = head, p2 = p1; p1 != NULL;p2=p1,p1=p1->next)
        {
            if(p1->ID==AID)
            {
                p2->next = p;
                p->next = p1;
                return head;
            }
        }
    }
    printf("SORRY,没有找到该位置\n");
    return head;
}
/*
//排序2.0
stu *sort(stu *head)
{
    stu *p1, *p2, *p,temp;
    for (p1 = head; p1->next != NULL;p1=p1->next)
    {
        for (p2=p1->next;;p2=p2->next)
        {
            if(p1->ID>p2->ID)
            {
                temp = *p1;
                *p1 = *p2;
                *p2 = temp;
            }
        }//插入排序法
    }
    return head;
}
*/

/*
stu *input();
void output();
stu *dele(stu*head,int DID);
stu *increase(stu *head,int AID);
stu lookfor(stu *head,int LID);
stu *front(stu *head,int AID);
stu *sort(stu *head);
*/

int main()
{
    stu *head, *p1, *p2, *p3, *p4; 
    int DID,AID,LID;
    //输入
    head = input();
    output(head);
 
    //后增加
    printf("你要在哪个数据后面增加什么数据：");
    scanf("%d", &AID);
    p1 = increase(head, AID);
    output(p1);

    //删除
    printf("你要删除那个号：");
    scanf("%d", &DID);
    p2=dele(head,DID);
    output(p2);

    //前增加
    printf("请问你要在哪个数前面增加数据；");
    scanf("%d", &AID);
    p4=front(head, AID);
    output(p4);

    //检索
    printf("你要查找哪号学生的成绩：");
    scanf("%d", &LID);
    p3=lookfor(head, LID);
    printf("你要查找的学生信息如下：\n");
    printf("%d   %d\n", p3->ID, p3->score);

    //结束
    system("pause");
    return 0;
}
