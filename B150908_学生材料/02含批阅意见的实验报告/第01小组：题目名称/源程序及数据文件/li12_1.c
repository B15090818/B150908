/*li12_1.c*/  
#include<stdio.h>  
#include<stdlib.h>  
#include"file.h"  
#include"book.h"  
void printHead( )/*��ӡͼ����Ϣ�ı�ͷ*/  
{
     printf("%8s%10s%8s%6s%6s%8s%6s%6s\n","���","����","����","һ������","��������","��������","������","��������");  
}   
void menu( )         /*����˵�����*/  
{  
 printf("******** 1. ��ʾ������Ϣ ********\n");  
 printf("******** 2. ������Ϣ���� ********\n");  
 printf("******** 3. ͼ���������� ********\n");
 printf("******** 4. ͼ������ͳ�ƹ��� ********\n");  
 printf("******** 5. ����ͼ��������ѯ ********\n"); 
 printf("******** 0. �˳�         ********\n");  
 } 
 void menuBase( )     /*2��������Ϣ����˵�����*/  
 {  
 		printf("%%%%%%%% 1. ���ͼ���¼ %%%%%%%%\n");  
 		printf("%%%%%%%% 2. �޸�ͼ���¼ %%%%%%%%\n");  
 		printf("%%%%%%%% 3. ɾ��ͼ���¼ %%%%%%%%\n");  
 		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");  
 }  
 void menuSale( )     /*3��ͼ����������˵�����*/  
 {  
 		printf("@@@@@@@@ 1. ����ͼ������ @@@@@@@@\n");  
 		printf("@@@@@@@@ 2. ������������ @@@@@@@@\n");  
 		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");  
 }    
 void menuCount( )    /*4��ͼ������ͳ�Ʋ˵�����*/  
 {  
 		printf("&&&&&&&& 1. ��ͼ��������� &&&&&&&&\n");  
 		printf("&&&&&&&& 2. ��ͼ��������� &&&&&&&&\n");  
 		printf("&&&&&&&& 3. ��ͼ��ƽ������ &&&&&&&&\n");  
 		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");  
 }  
   
 void menuSearch()    /*5������ͼ��������ѯ�˵�����*/  
 {  
 	    printf("######## 1. ��ͼ���Ų�ѯ   ########\n");  
 		printf("######## 2. ��������ѯ   ########\n");  
                printf("######## 3. ��ͼ������ѯ   ########\n");
                printf("######## 4. �����߲�ѯ   ########\n");
                printf("######## 5. Ӫҵ���ѯ   ########\n");
	    printf("######## 0. �����ϲ�˵� ########\n");  
 }  
  
 int baseManage(Book bk[],int n)    	     /*�ú�����ɻ�����Ϣ����*/  
 /*��ͼ���Ž��в���ɾ���޸ģ���Ų����ظ�*/  
 {    
 	int choice,t,find[NUM];  
    Book b;  
    do  
	{     
     menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/  
     printf("choose one operation you want to do:\n");  
     scanf("%d",&choice);	          /*����ѡ��*/  
	 switch(choice)  
		  {  
 		   case 1:	 readBk(&b,1);       /*����һ���������ͼ���¼*/  
			   n=insertBk(bk,n,b);   /*���ú�������ͼ���¼*/  
 					 break;  
		   case 2:  printf("Input the number deleted\n");  
 					 scanf("%ld",&b.num);  /*����һ����ɾ����ͼ����*/  
 					 n=deleteStu(stu,n,b);   /*���ú���ɾ��ָ����ŵ�ͼ���¼*/  
 					 break;  
 		   case 3:  printf("Input the number modified\n");  
 					 scanf("%ld",&b.num);  /*����һ�����޸ĵ�ͼ����*/  
 				      t=searchStu(stu,n,b,1,find) ; /*���ú�������ָ��ѧ�ŵ�ͼ����*/  
 				      if (t)                 /*����ñ�ŵļ�¼����*/  
 					 {  
 						  readBk(&b,1);   /*����һ��������ͼ���¼��Ϣ*/  
 					      bk[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					   
 					  }					   
 					 else                 /*����ñ�ŵļ�¼������*/   
  printf("this book is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/  
 					 break;  
 			    case 0: break;  
 		   }  
 	}while(choice);  
 return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/  
 }  
 void scoreManage(Book bk[],int n)          /*�ú������ͼ������������*/  
 {    
 	int choice;  
 	do  
 	{  
 		menuSale( );                        /*��ʾ��Ӧ�Ķ����˵�*/  
 		printf("choose one operation you want to do:\n");  
 		scanf("%d",&choice);	                 /*�������ѡ��*/  
 		switch(choice)  
 		{  
 			case 1:   calcuTotal(bk,n);         /*������ͼ�������*/  
 					  break;  
 			case 2:   calcuRank(bk,n);         /*��������ͼ�������������*/  
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
   
 void countManage(Bk bk[],int n)               /*�ú������ͼ������ͳ�ƹ���*/  
 {  
 		int choice;  
 		double mark[3][3];  
 		do  
 		{  
 			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/  
 			calcuMark(mark,bk,n);                 /*���ô˺����������µ���ߡ���͡�ƽ������*/  
 			printf("choose one operation you want to do:\n");  
 			scanf("%d",&choice);  
 			switch(choice)  
 			{  
 				case 1:   printMarkCourse("�����µ���������ֱ���:\n",mark,0);  /*����������*/  
 				      break;  
 				case 2:   printMarkCourse("�����µ���������ֱ���:\n",mark,1);  /*����������*/  
 				      break;  
 				case 3:   printMarkCourse("�����µ�ƽ�������ֱ���:\n",mark,2);  /*���ƽ������*/  
 				      break;  
 				case 0:   break;  
 			}  
 		}while (choice);  
 }  
   
 void searchManage(Bk bk[],int n)               /*�ú�����ɸ���������ѯ����*/  
 {  
     int i,choice,findnum,f[NUM];  
 Book b;  
 	   do  
 {  
 			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/  
 			printf("choose one operation you want to do:\n");  
 			scanf("%d",&choice);  
 			switch(choice)  
 			{  
 				case 1:   printf("Input a book\'s num will be searched:\n");  
 				      scanf("%ld",&s.num);         /*�������ѯͼ��ı��*/  
 					  break;  
 				case 2:   printf("Input a book\'s name will be searched:\n");  
 				      scanf("%s",s.name);	          /*�������ѯͼ�������*/		    
 				      break;     
 				case 3:   printf("Input  book\'s kind will be searched:\n");  
 				      scanf("%d",&s.kind);          /*�������ѯͼ��ķ���*/  
 					  break;
                                case 4:   printf("Input  book\'s writer will be searched:\n")
                                      scanf("%d",&b.writer);        /*�������ѯͼ�������*/
                case 5:   printf("Input sales will be searched:\n")
							          scanf("%d",&b.sales);   
 				case 0:   break;  
 			}  
 		 	if (choice>=1&&choice<=3)  
 			{   
 				findnum=searchBk(bk,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/  
 				if (findnum)				     /*������ҳɹ�*/  
 				{  
 			   		 printHead( );                  /*��ӡ��ͷ*/  
 					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/  
 	      	 printStu(&bk[f[i]],1);      /*ÿ�����һ����¼*/  
 				}  
 		    		else  
 			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/  
 		     }		  
 	    }while (choice);  
 }  
   
 int runMain(Bk bk[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/  
 {  
 		switch(choice)  
 		{  
 			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/  
 				 sortBk(bk,n,1);         /*��ѧ����С�����˳�������¼*/   
           	 printStu(stu,n);          /*��ѧ����С�����˳��������м�¼*/  
 					break;  
 			case 2: n=baseManage(bk,n);    /* 2. ������Ϣ����*/  
 			   	     break;  
 			case 3: scoreManage(bk,n);     /* 3. ͼ����������*/  
 					break;  
 			case 4: countManage(bk,n);     /* 4. ͼ������ͳ��*/  
 					break;  
 			case 5: searchManage(bk,n);     /* 5. ����������ѯ*/  
 				     break;  
           case 0: break;  
 		}  
 		return n;  
 }  
 
int main( )
{ 
     char pwd[10] = {'p','a','s','s','b','o','o','k','\0','\0'}; 
     char pwd_input[10]; 
     for(int i = 0; i < 10; i++) 
     pwd_input[i] = '\0'; 
     printf("����������:\n"); 
     scanf("%s",pwd_input); 
     if(0 == strcmp(pwd, pwd_input)) 
     printf("������ȷ!��¼�ɹ���\n"); 
     else 
     printf("�������!�����˳���\n"); 
   return 1;  
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
