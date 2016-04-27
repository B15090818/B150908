/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"owner.h"

void printHead( )      /*��ӡ������Ϣ�ı�ͷ*/
{
printf("%8s%10s%8s%6s%10s%6s\n","���ƺ�","����","�Ա�","����ʱ��","��ʱ��","ƽ������");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. ������Ϣ���� ********\n");
		printf("******** 4. ͣ����Ϣͳ�� ********\n");
		printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ��ӳ�����Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ��������Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸ĳ�����Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )     /*3��������Ϣ����˵�����*/
{
		printf("@@@@@@@@ 1. ����ͣ����ʱ�� @@@@@@@@\n");
		printf("@@@@@@@@ 2. ����ƽ��ͣ������ @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )    /*4��ͣ����Ϣͳ�Ʋ˵�����*/
{
		printf("&&&&&&&& 1. ����ͣ���ʱ�� &&&&&&&&\n");
		printf("&&&&&&&& 2. ����ͣ�����ʱ�� &&&&&&&&\n");
		printf("&&&&&&&& 3. ����ͣ��ƽ��ƽ���� &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. �����ƺŲ�ѯ   ########\n");
		printf("######## 2. ��������ѯ   ########\n");
		/*����ĸ������β�ѯɾ��*/
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(Owner own[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*�����ƺŽ��в���ɾ���޸ģ����ƺŲ����ظ�*/
{  
		int choice,t,find[NUM];
     Owner s;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readOwn(&s,1);       /*����һ��������ĳ�����¼*/
					 n=insertOwn(own,n,s);   /*���ú������복����¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*����һ����ɾ���ĳ������ƺ�*/
					 n=deleteOwn(own,n,s);   /*���ú���ɾ��ָ�����ƺŵĳ�����¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*����һ�����޸ĵĳ������ƺ�*/
				      t=searchOwn(own,n,s,1,find) ; /*���ú�������ָ�����ƺŵĳ�����¼*/
				      if (t)                 /*����ó��ƺŵļ�¼����*/
					 {
						  readOwn(&s,1);   /*����һ�������ĳ�����¼��Ϣ*/
					      own[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*����ó��ƺŵļ�¼������*/ 
 printf("this owner is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void informationManage(Owner own[],int n)          /*�ú�����ɳ�����Ϣ������*/
{  
	int choice;
	do
	{
		menuInformatiom( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(own,n);         /*�����г�������ͣ��ʱ��*/
					  break;
			case 2:   calcuTimetable(own,n);         /*�������г���ƽ��ͣ������*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void printMarkCourse(char *s,double m[3][3],int k)   /*��ӡ����ͨ�ú�������countManage ����*/
{                 /*��ʽ����k���������ͬ�����ݣ�0��1��2�ֱ��Ӧ��߷֡���ͷ֡�ƽ����*/
int i;
    printf(s);                                  /*�����s������������������ʾ��Ϣ*/
    for (i=0;i<3;i++)                           /*i������һ�ſ�*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(Student stu[],int n)               /*�ú�����ɿ��Գɼ�ͳ�ƹ���*/
{
		int choice;
		double mark[3][3];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuMark(mark,stu,n);                 /*���ô˺��������ſε���ߡ���͡�ƽ��ֵ*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("���ſε���߷ֱַ���:\n",mark,0);  /*�����߷�*/
				      break;
				case 2:   printMarkCourse("���ſε���ͷֱַ���:\n",mark,1);  /*�����ͷ�*/
				      break;
				case 3:   printMarkCourse("���ſε�ƽ���ֱַ���:\n",mark,2);  /*���ƽ����*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Student stu[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
Student s;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a student\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*�������ѯѧ����ѧ��*/
					  break;
				case 2:   printf("Input a student\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*�������ѯѧ��������*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&s.rank);          /*�������ѯѧ��������*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchStu(stu,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printStu(&stu[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Student stu[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortStu(stu,n,1);         /*��ѧ����С�����˳�������¼*/ 
          	 printStu(stu,n);          /*��ѧ����С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(stu,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: scoreManage(stu,n);     /* 3. ѧ���ɼ�����*/
					break;
			case 4: countManage(stu,n);     /* 4. ���Գɼ�ͳ��*/
					break;
			case 5: searchManage(stu,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Student stu[NUM];                /*����ʵ��һά����洢ѧ����¼*/
      int choice,n;
	 n=readFile(stu);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(stu);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(stu,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortStu(stu,n,1);                   /*�����ļ�ǰ��ѧ����С��������*/ 
	     saveFile(stu,n);                   /*����������ļ�*/
      return 0;
}
