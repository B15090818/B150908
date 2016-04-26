	#include<stdio.h>
	#include<stdlib.h>
	#include"file.h"
	#include"student.h"
	
	void printHead( )      /*��ӡ��Ա��Ϣ�ı�ͷ*/
	{
	printf("%8s%10s%8s%6s%6s%8s%6s\n","��Ա����","����","�Ա�","�÷�","����","����");
	}
	
	void menu( )         /*����˵�����*/
	{
			printf("******** 1. ��ʾ������Ϣ ********\n");
			printf("******** 2. ������Ϣ���� ********\n");
			printf("******** 3. ��Ա�ɼ����� ********\n");
			printf("******** 4. ��ӳɼ�ͳ�� ********\n");
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
	
	void menuScore( )     /*3����Ա�ɼ�����˵�����*/
	{
			printf("@@@@@@@@ 1. ������Ա�ܷ� @@@@@@@@\n");
	
	printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
	}
	 
	void menuCount( )    /*4���÷����ͳ�Ʋ˵�����*/
	{
			printf("&&&&&&&& 1. ����Ա��ߵ÷� &&&&&&&&\n");
			printf("&&&&&&&& 2. ����Ա��͵÷� &&&&&&&&\n");
	
	printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
	}
	
	void menuSearch()    /*5������������ѯ�˵�����*/
	{
			printf("######## 1. ����Ա�����ѯ   ########\n");
			printf("######## 2. ��������ѯ   ########\n");
	
		 printf("######## 0. �����ϲ�˵� ########\n");
	}
	
	int baseManage(Player pla[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
	/*����Ž��в���ɾ���޸ģ���Ų����ظ�*/
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
				   case 1:	 readStu(&s,1);       /*����һ�����������Ա��¼*/
						 n=insertStu(pla,n,s);   /*���ú���������Ա��¼*/
						 break;
				   case 2:  printf("Input the number deleted\n");
						 scanf("%ld",&s.num);  /*����һ����ɾ������Ա���*/
						 n=deleteStu(pla,n,s);   /*���ú���ɾ��ָ���������Ա��¼*/
						 break;
				   case 3:  printf("Input the number modified\n");
						 scanf("%ld",&s.num);  /*����һ�����޸ĵ���Ա����*/
					      t=searchPla(pla,n,s,1,find) ; /*���ú�������ָ���������Ա��¼*/
					      if (t)                 /*����ú���ļ�¼����*/
						 {
							  readPla(&s,1);   /*����һ����������Ա��¼��Ϣ*/
						      pla[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
						  }					 
						 else                 /*�������ŵļ�¼������*/ 
	 printf("this player is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
						 break;
				    case 0: break;
			    }
		}while(choice);
	return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
	}
	
	void scoreManage(Player pla[],int n)          /*�ú��������Ա�ɼ�������*/
	{  
		int choice;
		do
		{
			menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);	                 /*�������ѡ��*/
			switch(choice)
			{
				case 1:   calcuTotal(pla,n);         /*��������Ա���ܷ�*/
						  break;
	
	
	case 0:   break;
			}
		}while(choice);
	}
	
	void printMarkCourse(char *s,double m[3][3],int k)   /*��ӡ����ͨ�ú�������countManage ����*/
	{                 /*��ʽ����k���������ͬ�����ݣ�0��1���ֱ��Ӧ��߷֡���ͷ�*/
	int i;
	    printf(s);                                  /*�����s������������������ʾ��Ϣ*/
	    for (i=0;i<3;i++)                           /*i������һ����Ŀ*/
			  printf("%10.2lf",m[i][k]);
		   printf("\n");
	}
	
	void countManage(Player pla[],int n)               /*�ú��������Ա�ɼ�ͳ�ƹ���*/
	{
			int choice;
			double mark[3][3];
			do
			{
				menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
				calcuMark(mark,pla,n);                 /*���ô˺�����������Ŀ����ߡ����*/
				printf("choose one operation you want to do:\n");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:   printMarkCourse("������Ŀ����߷ֱַ���:\n",mark,0);  /*�����߷�*/
					      break;
					case 2:   printMarkCourse("������Ŀ����ͷֱַ���:\n",mark,1);  /*�����ͷ�*/
					      break;
	
	
					case 0:   break;
				}
			}while (choice);
	}
	
	void searchManage(Player pla[],int n)               /*�ú�����ɸ���������ѯ����*/
	{
	    int i,choice,findnum,f[NUM];
	Player s;
		   do
	{
				menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
				printf("choose one operation you want to do:\n");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:   printf("Input a player\'s num will be searched:\n");
					      scanf("%ld",&s.num);         /*�������ѯ��Ա�����*/
						  break;
					case 2:   printf("Input a player\'s name will be searched:\n");
					      scanf("%s",s.name);	          /*�������ѯ��Ա������*/		  
					      break;   
	
	
	
				  case 0:   break;
				}
			 	if (choice>=1&&choice<=3)
				{ 
					findnum=searchStu(pla,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
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
	
	int runMain(Player pla[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
	{
			switch(choice)
			{
				case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
					 sortSPla(spla,n,1);         /*��ѧ����С�����˳�������¼*/ 
	          	 printPla(pla,n);          /*��ѧ����С�����˳��������м�¼*/
						break;
				case 2: n=baseManage(pla,n);    /* 2. ������Ϣ����*/
				   	     break;
				case 3: scoreManage(pla,n);     /* 3. ��Ա�ɼ�����*/
						break;
				case 4: countManage(pla,n);     /* 4. �÷����ͳ��*/
						break;
				case 5: searchManage(pla,n);     /* 5. ����������ѯ*/
					     break;
	          case 0: break;
			}
			return n;
	}
	
	int main( )
	{
			Player pla[NUM];                /*����ʵ��һά����洢ѧ����¼*/
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
		sortPla(pla,n,1);                   /*�����ļ�ǰ��ѧ����С��������*/ 
		     saveFile(pla,n);                   /*����������ļ�*/
	      return 0;
	}
