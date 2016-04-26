/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"player.h"

void printHead( )      /*��ӡ��Ա��Ϣ�ı�ͷ*/
{
printf("%3d%8s%2d%2d%2d%2%2d%2d\n","��Ա����","����","�÷�","����","����","����","ʧ��","����");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. ��Ա���ݹ��� ********\n");
		printf("******** 4. �����÷�ͳ�� ********\n");
     printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ������Ա��¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ����Ա��¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸���Ա��¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )     /*3����Ա���ݹ���˵�����*/
{
		printf("@@@@@@@@ 1. ������Ա�ܵ÷� @@@@@@@@\n");
		printf("@@@@@@@@ 2. �����ܵ÷����� @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )    /*4�������÷�ͳ�Ʋ˵�����*/
{
		printf("&&&&&&&& 1. ���ܵ÷���߷� &&&&&&&&\n");
		printf("&&&&&&&& 2. ���ܵ÷���ͷ� &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. ��������ѯ   ########\n");
		printf("######## 2. �����º����ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(Player pla[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*��ѧ�Ž��в���ɾ���޸ģ����º��벻���ظ�*/
{  
		int choice,t,find[NUM];
     Player s;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readPla(&s,1);       /*����һ�����������Ա��¼*/
					 n=insertPla(pla,n,s);   /*���ú���������Ա��¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*����һ����ɾ������Ա���º���*/
					 n=deletePla(stu,n,s);   /*���ú���ɾ��ָ�����º������Ա��¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*����һ�����޸ĵ���Ա���º���*/
				      t=searchPla(pla,n,s,1,find) ; /*���ú�������ָ�����º������Ա��¼*/
				      if (t)                 /*��������º���ļ�¼����*/
					 {
						  readPla(&s,1);   /*����һ����������Ա��¼��Ϣ*/
					      stu[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*��������º���ļ�¼������*/ 
 printf("this player is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void scoreManage(Player pla[],int n)          /*�ú��������Ա���ݹ�����*/
{  
	int choice;
	do
	{
		menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%2d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(stu,n);         /*��������Ա���ܵ÷�*/
					  break;
			case 2:   calcuRank(stu,n);         /*����������Ա���ܵ÷�������*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void printMarkCourse(char *s,double m[5][2],int k)   /*��ӡ����ͨ�ú�������countManage ����*/
{                 /*��ʽ����k���������ͬ�����ݣ�0��1�ֱ��Ӧ��߷֡���ͷ�*/
int i;
    printf(s);                                  /*�����s������������������ʾ��Ϣ*/
    for (i=0;i<5;i++)                           /*i������һ������*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(Player pla[],int n)               /*�ú�����ɱ�������ͳ�ƹ���*/
{
		int choice;
		double mark[5][2];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuMark(mark,pla,n);                 /*���ô˺������峡��������ߡ���ͷ�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("�峡��������߷ֱַ���:\n",mark,0);  /*�����߷�*/
				      break;
				case 2:   printMarkCourse("�峡��������ͷֱַ���:\n",mark,1);  /*�����ͷ�*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Player pla[],int n)               /*�ú�����ɸ���������ѯ����*/
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
				case 1:   printf("Input a player\'s num will be searched:\n");
				      scanf("%2d",&s.num);         /*�������ѯ��Ա�����º���*/
					  break;
				case 2:   printf("Input a player\'s name will be searched:\n");
				      scanf("%8s",s.name);	          /*�������ѯ��Ա������*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%2d",&s.rank);          /*�������ѯ��Ա������*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=2)
			{ 
				findnum=searchPla(pla,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printPla(&pla[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Player pla[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortPla(pla,n,1);         /*�����º�����С�����˳�������¼*/ 
          	 printStu(pla,n);          /*�����º�����С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(pla,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: scoreManage(pla,n);     /* 3. ��Ա���ݹ���*/
					break;
			case 4: countManage(pla,n);     /* 4. �����÷�ͳ��*/
					break;
			case 5: searchManage(pla,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Player pla[NUM];                /*����ʵ��һά����洢��Ա��¼*/
      int choice,n;
	 n=readFile(pla);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(pla);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(pla,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortPla(pla,n,1);                   /*�����ļ�ǰ�����º�����С��������*/ 
	     saveFile(pla,n);                   /*����������ļ�*/
      return 0;
}
