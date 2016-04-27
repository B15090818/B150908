#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"file.h"
#include"consumption.h"

void printHead( )      /*��ӡѧ��������Ϣ�ı�ͷ*/
{
printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n","����","����","����","����","��ͨ","����","����");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ�����˵���Ϣ  ********\n");
		printf("******** 2. ������Ϣ����      ********\n");
		printf("******** 3. ������Ϣ����      ********\n");
		printf("******** 4. ������Ϣͳ��      ********\n");
        printf("******** 5. ����������ѯ      ********\n");
		printf("******** 0. �˳�              ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ���һ���˵� %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ��һ���˵� %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸�һ���˵� %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )     /*3��������Ϣ����˵�����*/
{
		printf("@@@@@@@@ 1. ����ÿ�����ѵ��ܽ�� @@@@@@@@\n");
		printf("@@@@@@@@ 2. ����ÿ�ս������     @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵�         @@@@@@@@\n");
}

void menuCount( )    /*4��������Ϣͳ�Ʋ˵�����*/
{
		printf("&&&&&&&& 1. ĳ��ĳ�������ܶ�          &&&&&&&&\n");
		printf("&&&&&&&& 2. ĳ��ĳ����Ŀ���ѱ���      &&&&&&&&\n");
		printf("&&&&&&&& 3. ĳ��ĳ�³���Ԥ��������  &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵�              &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. �����ڣ��꣩��ѯ�˵�����  ########\n");
		printf("######## 2. �����ڣ��£���ѯ�˵�����  ########\n");
		printf("######## 3. �����ڣ��գ���ѯ�˵�����  ########\n");
		printf("######## 0. �����ϲ�˵�              ########\n");
}

int baseManage(Consumption con[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*��date���в���ɾ���޸ģ�date�����ظ�*/
{  
	int choice,t, find[NUM];
    Consumption c;
	do{   
	menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
	printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	readCon(&c,1);       /*����һ���������date��¼*/
						n=insertCon(con,n,c);   /*���ú�������date��¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					    scanf("%d%d%d",&c.date.year,&c.date.month,&c.date.day);  /*����һ����ɾ����dateѧ��*/
					    n=deleteCon(con,n,c);   /*���ú���ɾ��ָ��date�����Ѽ�¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					    scanf("%d%d%d",&c.date.year,&c.date.month,&c.date.day);  /*����һ�����޸ĵ�date*/
						t=searchCon(con,n,c,3,find) ; /*���ú�������ָ��date�����Ѽ�¼*/
						 if (t)                 /*��������ѵļ�¼����*/
						{
							readCon(&c,1);   /*����һ�����������Ѽ�¼��Ϣ*/
							con[t] = c;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
						}					 
						else                 /*�����date�ļ�¼������*/ 
						printf("this consumption is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			   case 0: break;
		    }
	}while(choice);
	return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void scoreManage(Consumption con[],int n)          /*�ú������������Ϣ������*/
{  
	int choice;
	do
	{
		menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(con,n);         /*������ÿ�����ѽ����ܶ�*/
					  break;
			case 2:   calcuRank(con,n);         /*����ÿ�����ѽ����ܶ�������*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void countManage(Consumption con[],int n)               /*�ú������������Ϣͳ�ƹ���*/
{
		int choice,i,temp;
		int find[NUM],f;
		double sum,sum0,sum1,sum2,sum3;
		double spend = 0;
		Consumption c;
		sortCon(con, n);
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			readDate(&c, 2);
			f = searchCon(con, n, c,2,find);
			switch(choice)
			{
				case 1:	                                                                      /*ʵ��ĳ��ĳ�������ܶ��*/
						for (sum = 0,i = 0; i < f; i++)
						{
							sum += con[find[i]].total;
							printCon(&con[i],1);
						}
						printf("Totail consumption of this month :\n");
						printf("%ld",sum);
				      break;
				case 2:	 sum0 = sum1 = sum2 = sum3 = 0;                     					/*ʵ��ĳ��ĳ����Ŀ���ѱ�������*/
						for (i = 0; i < f; i++)
						{
							temp = find[i];
							sum0 += con[temp].fourObj[0];
							sum1 += con[temp].fourObj[1];
							sum2 += con[temp].fourObj[2];
							sum3 += con[temp].fourObj[3];
							printCon(&con[i],1);
						}
						printf("Catering,shopping,entertainment,trasportation accounted for the proportion totail:");
						printf("%ld\t%ld\t%ld\t%ld\t\n",(sum0 / f),(sum1 / f),(sum2 / f),(sum3 / f));
				      break;
				 case 3:	                                       /*ʵ��ĳ��ĳ�³���Ԥ������������*/
						printf("please input the budget of this month:");
						scanf("%ld",&spend);
						for (i = 0,temp = 0; i < n; i++)
						{
							if (fabs(c.total - spend) > 0)
							{
								temp++;
							}
						}
						printf("The over budget days of this month:%d\n",temp);
				      break;
				  case 0:											/*�����ϼ��˵�*/
					  break;
			}
		}while (choice);
}

void searchManage(Consumption con[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,f,find[NUM];
	Consumption c;
	sortCon(con, n);
	   do
		{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			readDate(&c,choice);                    /*�������ڲ�ѯ*/
		 	if (choice>=1&&choice<=3)
			{ 
				f=searchCon(con,n,c,choice,find);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (f)				     /*������ҳɹ�*/
				{
			   		printHead( );                  /*��ӡ��ͷ*/
					for (i=0;i<f;i++){}         /*ѭ������f������±�*/
	      			   printCon(&con[find[i]],1);      /*ÿ�����һ����¼*/
				}
				else
			    	printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Consumption con[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
					sortCon(con,n);         /*��date��С�����˳�������¼*/ 
          			printCon(con,n);          /*��date��С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(con,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: scoreManage(con,n);     /* 3. ������Ϣ����*/
					break;
			case 4: countManage(con,n);     /* 4. ������Ϣͳ��*/
					break;
			case 5: searchManage(con,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
	Consumption con[NUM];        /*����ʵ��һά����洢����                                                                                                                                                 ��¼*/
    int choice,n = 0;
	n=readFile(con);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/      
	if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	{
		n=createFile(con);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/       
	}	 	 
	do
	{
		menu();                      /*��ʾ���˵�*/
	    printf("Please input your choice: ");
	    scanf("%d",&choice);
	    if (choice >= 0 && choice <= 5)
	         n=runMain(con,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/         
	    else 
		     printf("error input,please input your choice again!\n");
	} while (choice);
	sortCon(con,n);                   /*�����ļ�ǰ��date��С��������*/               
	saveFile(con,n);                   /*����������ļ�*/                        
    return 0;
}


