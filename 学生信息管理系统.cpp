#include <stdio.h>   
#include <stdlib.h>   
#include <string.h>     
#define LEN sizeof(struct student) 
#define N 5  
struct student { 
    char name[10];//������
	int age;//����
	char major[10];//רҵ��
	char classNO[10];//�༶��
    char num[12];//ѧ�ţ�
    int score[3];//3�Ƴɼ���
    struct student *next; //ָ����һ����ָ��
};
void Output(student *p);//�������������ѧ����Ϣ��
void Save(student *p);//��������������ѧ������Ϣ��
void Fetch(student *p);//���������������Ѵ��ڵ�ѧ����Ϣ��
struct student *head=NULL;
struct student *p;
char filename[10];
char a[10]="yes";
//------------��������ʼ---------------
void main()
{ int n,i,id;
struct student *head=NULL;
while(1){
   printf("\n�����빦�ܱ�ţ�����ϵͳ��Ӧ����:\n");
   printf("1-����ѧ������Ϣ(�����Ѵ���ѧ����Ϣ��ֱ��case8���ܣ������ļ�����students)\n");	   
   printf("2-���ѧ������Ϣ;\n3-�ļ�����; \n4-��ȡÿ��ѧ����������רҵ��Ϣ;\n");
   printf("5-����ָ��ѧ�ŵ�ѧ��;\n6-����һ��ѧ����Ϣ������;\n7-ɾ��ָ��ѧ�ŵ�ѧ��;\n");
   printf("8-�����Ѵ���ѧ��������Ϣ��\n����-�˳�;\n");
   printf("\n��ѡ���Ϊ��");
   scanf("%d",&id);
switch(id){
   case 1:               //����ʽͷ�巨������ѧ������Ϣ��
	   { n=N-1;
    p=(struct student *)malloc(LEN);
    printf("\n��������������Enter��������");
	 scanf("%s",p->name);
	   getchar();
      printf("\n���������䣬��Enter��������");
	 scanf("%d",&p->age);
	   getchar();
      printf("\n������רҵ����Enter��������");
	 scanf("%s",p->major);
	   getchar();
      printf("\n������༶����Enter��������");
 	 scanf("%s",p->classNO);
	   getchar();
      printf("\n������ѧ�ţ���Enter��������");
	 scanf("%s",p->num);
	   getchar();
      printf("\n���������Ƴɼ�����Enter��������");
	for(i=0;i<3;i++)
	  scanf("%d",&p->score[i]);
	   while(n>0){
		   p->next=head;
		   head=p;
		   p=(struct student *)malloc(LEN);
      printf("\n��������������Enter��������");
	 scanf("%s",p->name);
	   getchar();
      printf("\n���������䣬��Enter��������");
	 scanf("%d",&p->age);
	   getchar();
      printf("\n������רҵ����Enter��������");
	 scanf("%s",p->major);
	   getchar();
      printf("\n������༶����Enter��������");
 	 scanf("%s",p->classNO);
	   getchar();
      printf("\n������ѧ�ţ���Enter��������");
	 scanf("%s",p->num);
	   getchar();
      printf("\n���������Ƴɼ�����Enter��������");
    for(i=0;i<3;i++)
	  scanf("%d",&p->score[i]);
	  n--;} 
	   p->next=head;
		   head=p;
	   break;}
   case 2:             //����Output�Ӻ������ѧ������Ϣ��
	   { printf("������ѧ������Ϣ��\n");
		Output(head);
	     	   break;}
   case 3:             //����Save�Ӻ�������ѧ������Ϣ��
	   { getchar();    
	    Save(head);
		 break;}
   case 4:             //���ÿλѧ����רҵ��������
	   {printf("������ÿλͬѧ������������רҵ;\n");
	   struct student *p;
	   p=head;
	    for(p=head;p!=NULL;p=p->next){printf("\n������%s\nרҵ��%s\n",
	   p->name ,p->major);}
	    break;}
   case 5:             //����ָ��ѧ���ĸ�����Ϣ��
	   {struct student *p;
	   char Num[10];
	   p=head;
		   printf("������������ҵ�ѧ��ѧ��(02,04,06,08,10):\n");
	   scanf("%s",Num);
	   for(p=head;p!=NULL;p=p->next)
		   if(!strcmp(Num,p->num)){
			   printf("�����������ҵ�ѧ��������Ϣ��\n");
	   printf("\n������%s\n���䣺%d��\nרҵ��%s\n�༶��%s\nѧ�ţ�%s\nC���ԣ�%d��\n������%d��\n��Ӣ��%d��\n",
	p->name ,p->age,p->major,p->classNO,p->num,p->score[0],p->score[1],p->score[2]);}
		   else continue;
	  break;}
   case 6:             //����һλѧ������Ϣ��ԭ�������뱣���޸ĺ����Ϣ��
	   {    struct student ps,*p1,*p2;
	    p1=head;
	        char number[10];
	   printf("������׼��������Ǹ�ѧ����Ϣ��\n");
     printf("\n��������������Enter��������");
	 scanf("%s",ps.name);
	   getchar();
      printf("\n���������䣬��Enter��������");
	 scanf("%d",&ps.age);
	   getchar();
      printf("\n������רҵ����Enter��������");
	 scanf("%s",ps.major);
	   getchar();
      printf("\n������༶����Enter��������");
 	 scanf("%s",ps.classNO);
	   getchar();
       printf("\n������ѧ�ţ���Enter��������");
	 scanf("%s",ps.num);
	   getchar();
      printf("\n���������Ƴɼ�����Enter��������");
    for(i=0;i<3;i++)
	  scanf("%d",&ps.score[i]);
   p2=&ps;
	getchar();
	  printf("\n����Ѹ�ͬѧ������λͬѧ֮���������Ӧѧ��(02,04,06,10);\n",N);
	  printf("�������ѧ��Ϊ��");
	 scanf("%s",number);
	 while(p1->next!=NULL){
		 if(!strcmp(number,(p1->num)))
			 break;
		 else  p1=p1->next;}
			p2->next=p1->next;
			p1->next=p2;
     printf("�������޸ĺ�ѧ������Ϣ��\n");
		Output(head);
		 printf("\n���Ƿ��뱣�����޸��ļ�����\n");
		 printf("yes-���棻\t����-�����棻\n");
		 printf("\n��ѡ��Ϊ��");
		 scanf("%s",filename);
		 if(!strcmp(a,filename))Save(head);	//�ж��Ƿ񱣴����޸��ļ���	
	  break;
	   }
   case 7:                    //ɾ��ָ��ѧ�ŵ�ѧ����Ϣ�뱣���޸ĺ����Ϣ��
	   {char b[10];
	   struct student *pt,*pq;
	   pt=head->next;
	   pq=head;
		   printf("����������ɾ����ѧ����ѧ��(04,06,08,10;����Ϊͷ����02��)��\n");
	   printf("�������ѧ��Ϊ��\t");
	   scanf("%s",b);
	   while(pq!=NULL){
		   if(!strcmp(b,(pt->num)))
			   break;
			   pt=pt->next;
			  pq=pq->next;}
	   pq->next=pt->next;
      printf("�������޸ĺ�ѧ������Ϣ��\n");
		Output(head);
         printf("���Ƿ��뱣�����޸��ļ�����\n");
		 printf("yes-���棻\tno-�����棻");
         printf("\n��ѡ��Ϊ��");
		 scanf("%s",filename);
		 if(!strcmp(a,filename))Save(head);  //�ж��Ƿ񱣴����޸��ļ���
	  break;}
   case 8:
	   {Fetch(head);	
         break;}
  default:
	   { break;}} if((id<1)||(id>8))	break;}}

void Save(student *head)
{ FILE *fp;     //�����ļ�
	    printf("�����뱣����ļ�����");
		  scanf("%s",filename);
	      if((fp=fopen(filename,"wb"))==NULL)
		{	printf("cannot open this file\n");
		  exit (0);}
		  else {p=head;		
		    fwrite(p,LEN,1,fp);
			do{p=p->next;
			fwrite(p,LEN,1,fp);    //����Ϣ��������ļ���
			}while(p->next!=NULL);
		 fclose(fp);}
}
void Fetch(student *head)
{FILE *fp;
	printf("������򿪵��ļ�����");
	scanf("%s",filename);
	if((fp=fopen(filename,"rb"))==NULL)
	{	printf("cannot open this file\n");
		exit(0);}
	else{struct student *p3,*p4;
		p3=p4=head;
		p3=(struct student *)malloc(LEN);	 
	fread(p3,LEN,1,fp);          //���ļ��е�һ�����ݶ���������
printf("\n������%s\n���䣺%d��\nרҵ��%s\n�༶��%s\nѧ�ţ�%s\nC���ԣ�%d��\n������%d��\n��Ӣ��%d��\n",
p3->name ,p3->age,p3->major,p3->classNO,p3->num,p3->score[0],p3->score[1],p3->score[2]);
    do{ p3=(struct student *)malloc(LEN);
	fread(p3,LEN,1,fp);          //���ļ��е�����һһ����������
	p4=p3->next;
	p4=p3;
printf("\n������%s\n���䣺%d��\nרҵ��%s\n�༶��%s\nѧ�ţ�%s\nC���ԣ�%d��\n������%d��\n��Ӣ��%d��\n",
p4->name ,p4->age,p4->major,p4->classNO,p4->num,p4->score[0],p4->score[1],p4->score[2]);
	}while(p3->next!=NULL);
	}
}
void Output(student *head)
{
	for(p=head;p!=NULL;p=p->next){printf("\n������%s\n���䣺%d��\nרҵ��%s\n�༶��%s\nѧ�ţ�%s\nC���ԣ�%d��\n������%d��\n��Ӣ��%d��\n",
p->name ,p->age,p->major,p->classNO,p->num,p->score[0],p->score[1],p->score[2]);}
}