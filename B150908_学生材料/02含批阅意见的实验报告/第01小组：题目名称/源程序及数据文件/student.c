/*��book.c�ļ�����������*/  
#include "bookt.h"  
#include <stdio.h>  
  
int readBook(Book  *bk , int n)          /*����ͼ���¼ֵ�����Ϊ0������涨������¼ʱֹͣ*/  
{  
 	int i,j;  
	for (i=0;i<n;i++)  
	{  
	printf("Input one book\'s information\n");  
	printf("ISBN:  ");                    /*ÿ����ı��*/
     scanf("%s", bk[i].ISBN);  
	if (book[i].num==0) break;  
	printf("name: ");                    /*����*/
	scanf("%s",bk[i].name);
printf("category: ");                  /*�������*/
	scanf("%s",bk[i].category);
    printf("price: ");                     /*ÿ����ĵ���*/
	scanf("%ld",bk[i].price);
    printf("remain: ");                   /*ÿ����Ŀ��*/
	scanf("%ld",bk[i].remain); 
    printf("authorname: ");               /*������*/
	scanf("%s",bk[i].authorname);
printf("total: ");                     /*ÿ���������µ�������*/
	scanf("%ld",bk[i].total);
    bk[i].sales=0;                    /*ÿ�������۶���Ҫ������ã���ֵ��Ϊ0*/  
	printf("Input three datum of the book:\n");  
	for (j=0;j<3;j++)  
    {  
	    scanf("%d",&stu[i].date[j]);	  
	}  
		book[i].rank=0;                 /*������Ҫ����ÿ��������۶������㣬��ֵ��Ϊ0*/  
	}  
	return i;                         /*����ʵ�ʶ���ļ�¼����*/  
}  
   
 void printBook ( Book  *bk , int n)       /*�������ͼ���¼��ֵ*/  
{  
     int i,j;  
 	for (i=0;i<n;i++)  
 	{  
 	printf("%8ld  ", bk[i].num);  
	printf("%8s", bk[i].name); 
        printf("%8ld  ", bk[i].price);
        printf("%8ld  ", bk[i].totalnum);
        printf("%8s", bk[i].authorname);
		for (j=0;j<2;j++)  
 	   printf("%6d",book[i].date[j]);  
 	    printf("%7d",book[i].total);  
    printf("%5d\n",[i].rank);  
 	}  
 }  
   
 int equal(Book s1,Book s2,int condition)  /*����ж�����Book��¼���*/  
 {  
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϱ��*/  
		return s1.num==s2.num;  
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/  
     {  
    if (strcmp(s1.name,s2.name)==0) 	return 1;  
	else return 0;  
    }  
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/  
 	     return s1.rank==s2.rank;  
  else if (condition==4)                /*�������condition��ֵΪ4����Ƚ��ܷ�*/  
		return s1.total==s2.total;  
	else return 1;                       /*�����������1*/  
 }   
  
int larger(Book s1,Book s2,int condition)  /*����condition�����Ƚ�����Book��¼�Ĵ�С*/  
 {  
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ѧ��*/  
		return s1.num>s2.num;  
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ��ܷ�*/  
 		return s1.total>s2.total;	  
	else return 1; /*�����������1*/  
}  
  
 void reverse(Book bk [],int n)             /*����Ԫ������*/  
 {  
 	int i;  
 	Book temp;  
 	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/  
{  
		temp=stu[i];  
 	bk[i]=bk[n-1-i];  
 	bk[n-1-i]=temp;  
}  
 }  
 
 void calcuTotal(Book bk[],int n)         /*����ÿ���������µ�������*/  
 {  
 	int i,j;  
 	for (i=0;i<n;i++)                    /*���ѭ����������ͼ���¼*/  
 {  
		bk[i].total =0;  
 	for (j=0;j<3;j++)               /*�ڲ�ѭ������������*/  
 		bk[i].total +=bk[i].score[j];  
 }	  
 }  
   
 void calcuRank(Book stu[],int n)          /*����������������ͼ���������������ͬ��������ͬ*/  
 {  
 int i ;                         
	sortBook(bk,n,2);                     /*�ȵ���sortStu�㷨�����ܷ���С��������*/  
	reverse(bk,n);                      /*�����ã����ܷ��ɴ�С������*/  
 bk[0].rank=1;                      /*��һ����¼������һ����1*/  
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/  
{  
 		if (equal(bk[i],bk[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼����ܷ����*/  
			bk[i].rank=bk[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/   
	    else  
			bk[i].rank=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/  
 	}  
}  
 
void calcuMark(double m[3][3],Book bk[],int n) /*�������µ����۶���ߡ����*/  
/*������ʽ������ά����m�ĵ�һά���������£��ڶ�ά������ߡ����*/  
{  
 	int i,j;  
	for (i=0;i<3;i++)                 /*�����������۶����*/		  
	{   
		m[i][0]=bk[0].score[i];       
		for (j=1;j<n;j++)  
			if (m[i][0]<bk[j].score[i])  
				m[i][0]=stu[j].score[i];  
	}  
	for (i=0;i<3;i++)                  /*�������������۶����*/  
 	{   
 		m[i][1]=bk[0].score[i];        
		for (j=1;j<n;j++)  
 			if (m[i][1]>bk[j].score[i])  
				m[i][1]=bk[j].score[i];  
 	}  
	 
 }  
  
 void sortStu(Book stu[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/  
 {  
 	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/  
 	Book t;  
 	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/  
	{  
		minpos=i;  
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/  
			if (larger(bk[minpos],bk[j],condition))  
				minpos=j;  
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/  
		{  
			t=bk[i];  
			bk[i]=bk[minpos];  
		        bk[minpos]=t;  
		}  
	}  
}  
  
int searchBook(Book stu[],int n,Book s,int condition,int f[ ])  /*��stu��������condition��������*/  
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/  
{  
	int i,j=0,find=0;  
 	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/  
 		if (equal(bk[i],s,condition))    
 		{  
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/  
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                                
		}  
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/   
}  
   
int insertBook(Book bk[],int n,Book s)              /*��stu��������ѧ�ŵ�������һ��Ԫ��s*/  
{  
 	int i;  
 	sortBook(bk,n,1);                              /*�Ȱ��������*/  
	for (i=0;i<n;i++)  
	{  
		if (equal(bk[i],s,1))                      /*�����ͬ��������룬��֤ѧ�ŵ�Ψһ��*/  
		{  
                   printf("this record exist,can not insert again!\n"); 
		    return n;  
		}  
	}  
	for (i=n-1;i>=0;i--)                          /*����Ŵ�С��������*/  
	{  
		if (!larger(bk[i],s,1))                    /*���s���ڵ�ǰԪ��stu[i]�����˳�ѭ��*/  
		break;  
		bk[i+1]=bk[i];                         /*����Ԫ��stu[i]����һ��λ��*/  
	}  
	bk[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                     
	n++;                                     /*Ԫ�ظ�������1*/  
	return n;                                  /*��������Ԫ�ظ���*/  
}  
  
int deleteBook(Book bk[],int n,Book s)            /*��������ɾ��ָ��ѧ�ŵ�һ��Ԫ��*/  
{  
	int i,j;  
		if (equal(bk[i],s,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/  
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/  
	{  
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/  
		return n;  
	}  
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(stu[i],s,1)����*/   
		stu[j]=stu[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/  
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/  
	return n;                                  /*�������и���*/  
}  
