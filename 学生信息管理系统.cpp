#include <stdio.h>   
#include <stdlib.h>   
#include <string.h>     
#define LEN sizeof(struct student) 
#define N 5  
struct student { 
    char name[10];//姓名；
	int age;//年龄
	char major[10];//专业；
	char classNO[10];//班级；
    char num[12];//学号；
    int score[3];//3科成绩；
    struct student *next; //指向下一结点的指针
};
void Output(student *p);//函数声明，输出学生信息；
void Save(student *p);//函数声明，保存学生总信息；
void Fetch(student *p);//函数声明，引用已存在的学生信息；
struct student *head=NULL;
struct student *p;
char filename[10];
char a[10]="yes";
//------------主函数开始---------------
void main()
{ int n,i,id;
struct student *head=NULL;
while(1){
   printf("\n请输入功能编号，运行系统相应功能:\n");
   printf("1-输入学生总信息(引用已存在学生信息请直接case8功能，输入文件名：students)\n");	   
   printf("2-输出学生总信息;\n3-文件存盘; \n4-读取每个学生的姓名和专业信息;\n");
   printf("5-查找指定学号的学生;\n6-插入一个学生信息到链表;\n7-删除指定学号的学生;\n");
   printf("8-引用已存在学生链表信息；\n其他-退出;\n");
   printf("\n所选编号为：");
   scanf("%d",&id);
switch(id){
   case 1:               //链表式头插法，输入学生总信息；
	   { n=N-1;
    p=(struct student *)malloc(LEN);
    printf("\n请输入姓名，按Enter键结束：");
	 scanf("%s",p->name);
	   getchar();
      printf("\n请输入年龄，按Enter键结束：");
	 scanf("%d",&p->age);
	   getchar();
      printf("\n请输入专业，按Enter键结束：");
	 scanf("%s",p->major);
	   getchar();
      printf("\n请输入班级，按Enter键结束：");
 	 scanf("%s",p->classNO);
	   getchar();
      printf("\n请输入学号，按Enter键结束：");
	 scanf("%s",p->num);
	   getchar();
      printf("\n请输入三科成绩，按Enter键结束：");
	for(i=0;i<3;i++)
	  scanf("%d",&p->score[i]);
	   while(n>0){
		   p->next=head;
		   head=p;
		   p=(struct student *)malloc(LEN);
      printf("\n请输入姓名，按Enter键结束：");
	 scanf("%s",p->name);
	   getchar();
      printf("\n请输入年龄，按Enter键结束：");
	 scanf("%d",&p->age);
	   getchar();
      printf("\n请输入专业，按Enter键结束：");
	 scanf("%s",p->major);
	   getchar();
      printf("\n请输入班级，按Enter键结束：");
 	 scanf("%s",p->classNO);
	   getchar();
      printf("\n请输入学号，按Enter键结束：");
	 scanf("%s",p->num);
	   getchar();
      printf("\n请输入三科成绩，按Enter键结束：");
    for(i=0;i<3;i++)
	  scanf("%d",&p->score[i]);
	  n--;} 
	   p->next=head;
		   head=p;
	   break;}
   case 2:             //调用Output子函数输出学生总信息；
	   { printf("下面是学生总信息：\n");
		Output(head);
	     	   break;}
   case 3:             //调用Save子函数保存学生总信息；
	   { getchar();    
	    Save(head);
		 break;}
   case 4:             //输出每位学生的专业和姓名；
	   {printf("下面是每位同学的姓名和所在专业;\n");
	   struct student *p;
	   p=head;
	    for(p=head;p!=NULL;p=p->next){printf("\n姓名：%s\n专业：%s\n",
	   p->name ,p->major);}
	    break;}
   case 5:             //查找指定学生的个人信息；
	   {struct student *p;
	   char Num[10];
	   p=head;
		   printf("请输入您想查找的学生学号(02,04,06,08,10):\n");
	   scanf("%s",Num);
	   for(p=head;p!=NULL;p=p->next)
		   if(!strcmp(Num,p->num)){
			   printf("下面是您查找的学生个人信息：\n");
	   printf("\n姓名：%s\n年龄：%d岁\n专业：%s\n班级：%s\n学号：%s\nC语言：%d分\n高数：%d分\n大英：%d分\n",
	p->name ,p->age,p->major,p->classNO,p->num,p->score[0],p->score[1],p->score[2]);}
		   else continue;
	  break;}
   case 6:             //插入一位学生的信息到原链表中与保存修改后的信息；
	   {    struct student ps,*p1,*p2;
	    p1=head;
	        char number[10];
	   printf("请输入准备插入的那个学生信息：\n");
     printf("\n请输入姓名，按Enter键结束：");
	 scanf("%s",ps.name);
	   getchar();
      printf("\n请输入年龄，按Enter键结束：");
	 scanf("%d",&ps.age);
	   getchar();
      printf("\n请输入专业，按Enter键结束：");
	 scanf("%s",ps.major);
	   getchar();
      printf("\n请输入班级，按Enter键结束：");
 	 scanf("%s",ps.classNO);
	   getchar();
       printf("\n请输入学号，按Enter键结束：");
	 scanf("%s",ps.num);
	   getchar();
      printf("\n请输入三科成绩，按Enter键结束：");
    for(i=0;i<3;i++)
	  scanf("%d",&ps.score[i]);
   p2=&ps;
	getchar();
	  printf("\n您想把该同学放在哪位同学之后，请输入对应学号(02,04,06,10);\n",N);
	  printf("您输入的学号为：");
	 scanf("%s",number);
	 while(p1->next!=NULL){
		 if(!strcmp(number,(p1->num)))
			 break;
		 else  p1=p1->next;}
			p2->next=p1->next;
			p1->next=p2;
     printf("下面是修改后学生总信息：\n");
		Output(head);
		 printf("\n您是否想保存已修改文件？：\n");
		 printf("yes-保存；\t其他-不保存；\n");
		 printf("\n您选择为：");
		 scanf("%s",filename);
		 if(!strcmp(a,filename))Save(head);	//判断是否保存已修改文件；	
	  break;
	   }
   case 7:                    //删除指定学号的学生信息与保存修改后的信息；
	   {char b[10];
	   struct student *pt,*pq;
	   pt=head->next;
	   pq=head;
		   printf("请输入您想删除的学生的学号(04,06,08,10;不能为头链表02；)：\n");
	   printf("您输入的学号为：\t");
	   scanf("%s",b);
	   while(pq!=NULL){
		   if(!strcmp(b,(pt->num)))
			   break;
			   pt=pt->next;
			  pq=pq->next;}
	   pq->next=pt->next;
      printf("下面是修改后学生总信息：\n");
		Output(head);
         printf("您是否想保存已修改文件？：\n");
		 printf("yes-保存；\tno-不保存；");
         printf("\n您选择为：");
		 scanf("%s",filename);
		 if(!strcmp(a,filename))Save(head);  //判断是否保存已修改文件；
	  break;}
   case 8:
	   {Fetch(head);	
         break;}
  default:
	   { break;}} if((id<1)||(id>8))	break;}}

void Save(student *head)
{ FILE *fp;     //定义文件
	    printf("请输入保存的文件名：");
		  scanf("%s",filename);
	      if((fp=fopen(filename,"wb"))==NULL)
		{	printf("cannot open this file\n");
		  exit (0);}
		  else {p=head;		
		    fwrite(p,LEN,1,fp);
			do{p=p->next;
			fwrite(p,LEN,1,fp);    //将信息逐个存入文件；
			}while(p->next!=NULL);
		 fclose(fp);}
}
void Fetch(student *head)
{FILE *fp;
	printf("请输入打开的文件名：");
	scanf("%s",filename);
	if((fp=fopen(filename,"rb"))==NULL)
	{	printf("cannot open this file\n");
		exit(0);}
	else{struct student *p3,*p4;
		p3=p4=head;
		p3=(struct student *)malloc(LEN);	 
	fread(p3,LEN,1,fp);          //将文件中第一个内容读到链表中
printf("\n姓名：%s\n年龄：%d岁\n专业：%s\n班级：%s\n学号：%s\nC语言：%d分\n高数：%d分\n大英：%d分\n",
p3->name ,p3->age,p3->major,p3->classNO,p3->num,p3->score[0],p3->score[1],p3->score[2]);
    do{ p3=(struct student *)malloc(LEN);
	fread(p3,LEN,1,fp);          //将文件中的内容一一读到链表中
	p4=p3->next;
	p4=p3;
printf("\n姓名：%s\n年龄：%d岁\n专业：%s\n班级：%s\n学号：%s\nC语言：%d分\n高数：%d分\n大英：%d分\n",
p4->name ,p4->age,p4->major,p4->classNO,p4->num,p4->score[0],p4->score[1],p4->score[2]);
	}while(p3->next!=NULL);
	}
}
void Output(student *head)
{
	for(p=head;p!=NULL;p=p->next){printf("\n姓名：%s\n年龄：%d岁\n专业：%s\n班级：%s\n学号：%s\nC语言：%d分\n高数：%d分\n大英：%d分\n",
p->name ,p->age,p->major,p->classNO,p->num,p->score[0],p->score[1],p->score[2]);}
}