/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"car.h"

void printHead( )      /*��ӡ������Ϣ�ı�ͷ*/
{
printf("%8s%10s%8s%6s%6s%8s%6s%6d\n","����","���ƺ�","���ͺ�","����ɫ","Υ���¼","�ɷ�״̬","Υ��ʱ��","�۷����");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. ������Ϣ���� ********\n");
		printf("******** 4. Υ��۷�ͳ�� ********\n");
        printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ���복����Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ��������Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸ĳ�����¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}


void menuCount( )    /*4��Υ��۷�ͳ�Ʋ˵�����*/
{
		printf("&&&&&&&& 1. ��۳���߷� &&&&&&&&\n");
		printf("&&&&&&&& 2. ��۳���ͷ� &&&&&&&&\n");
		printf("&&&&&&&& 3. ��۳�ƽ���� &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. �����ƺŲ�ѯ   ########\n");
		printf("######## 2. ��������ѯ   ########\n");
		printf("######## 3. ���۷ֲ�ѯ   ########\n");
		printf("######## 4. �����ͺŲ�ѯ   ########\n");
		printf("######## 5. ������ɫ��ѯ  ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(cl che[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*�����ƺŽ��в���ɾ���޸ģ����ƺŲ����ظ�*/
{  
		int choice,t,find[NUM];
     che s;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readche(&s,1);       /*����һ���������Υ���¼*/
					 n=insertche(che,n,s);   /*���ú�������Υ���¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*����һ����ɾ���ĳ��ƺ�*/
					 n=deleteche(che,n,s);   /*���ú���ɾ��ָ��������Υ���¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*����һ�����޸ĵĳ��ƺ�*/
				      t=searchche(che,n,s,1,find) ; /*���ú�������ָ�����ƺŵ�Υ���¼*/
				      if (t)                 /*����ó��ƺŵļ�¼����*/
					 {
						  readche(&s,1);   /*����һ�������ĳ���Υ���¼��Ϣ*/
					      che[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*����ó����ļ�¼������*/ 
 printf("this student is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void scoreManage(cl che[],int n)          /*�ú�����ɳ����Ŀ۷ֹ�����*/
{  
	int choice;
	do
	{
		menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(che,n);         /*�����г����۳����ܷ�*/
					  break;
			case 2:   calcuRank(che,n);         /*�������г����۷�������*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void printMarkCourse(char *s,double m[3][3],int k)   /*��ӡ����ͨ�ú�������countManage ����*/
{                 /*��ʽ����k���������ͬ�����ݣ�0��1��2�ֱ��Ӧ��߷֡���ͷ֡�ƽ����*/
int i;
    printf(s);                                  /*�����s�����������۷ֵ���ʾ��Ϣ*/
    for (i=0;i<3;i++)                           /*i������һ����*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}



void searchManage(cl che[],int n)               /*�ú�����ɸ���������ѯ����*/
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
				case 1:   printf("Input a cheliang\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*�������ѯ�����ĳ��ƺ�*/
					  break;
				case 2:   printf("Input a cheliang\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*�������ѯ�����ĳ�����*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&s.rank);          /*�������ѯ����Υ��۷ֵ�����*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchche(che,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printche(&che[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(cl che[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortche(che,n,1);         /*���۷���С�����˳�������¼*/ 
          	 printche(che,n);          /*���۷���С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(che,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: scoreManage(stu,n);     /* 3. �����۷ֹ���*/
					break;
			case 4: countManage(che,n);     /* 4. �۷����ͳ��*/
					break;
			case 5: searchManage(che,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		cl che[NUM];                /*����ʵ��һά����洢����Υ���¼*/
      int choice,n;
	 n=readFile(che);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(che);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(che,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortche(che,n,1);                   /*�����ļ�ǰ�������۷���С��������*/ 
	     saveFile(che,n);                   /*����������ļ�*/
      return 0;
}
