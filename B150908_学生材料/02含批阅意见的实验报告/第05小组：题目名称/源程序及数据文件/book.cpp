/*��book.c�ļ�����������*/
#include "book.h"
#include <stdio.h>

int readBook(Book  *book , int n)          /*����ͼ���¼ֵ��ͼ��Ϊ0������涨������¼ʱֹͣ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one book's information\n");
		printf("num:  ");
	     scanf("%ld", &book[i].number);
		if (book[i].number==0) break;
		printf("name: ");
		scanf("%s",book[i].title);	
		printf("�����Ȿ�����������:\n");
		scanf("%d",&book[i].kc);	
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printBook ( Book  *book , int n)       /*�������ͼ���¼��ֵ*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", book[i].number);
		printf("%8s", book[i].title);
	    printf("%5d\n",book[i].kc);
	}
}

int equal(Book b1,Book b2,int condition)  /*����ж�����ͼ���¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�������*/
		return b1.number==b2.number;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(b1.title,b2.title)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����ȽϿ��*/
	     return b1.kc==b2.kc;
	else return 1;                       /*�����������1*/
} 

int larger(Book b1,Book b2,int condition)  /*����condition�����Ƚ�����ͼ�� �����ż�¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ѧ��*/
		return b1.number>b2.number;	
	else return 1; /*�����������1*/
}

void reverse(Book book[],int n)             /*����Ԫ������*/
{
	int i;
	Book temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=book[i];
		book[i]=book[n-1-i];
		book[n-1-i]=temp;
	}
}
void sortBook(Book book[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Book t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(book[minpos],book[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=book[i];
			book[i]=book[minpos];
			book[minpos]=t;
		}
	}
}

int searchBook(Book book[],int n,Book b,int condition,int f[ ])  /*��book��������condition��������*/
/*��b��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(book[i],b,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int addBook(Book book[],int n,Book b)              /*��book��������ѧ�ŵ�������һ��Ԫ��s*/
{
	int i;
	sortBook(book,n,1);                              /*�Ȱ�ѧ������*/
	for (i=n-1;i>=0;i--)                          /*��ѧ�Ŵ�С��������*/
	{
		if (!larger(book[i],b,1))                    /*���b���ڵ�ǰԪ��book[i]�����˳�ѭ��*/
		break;
		book[i+1]=book[i];                         /*����Ԫ��book[i]����һ��λ��*/
	}
	book[i+1]=b;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteBook(Book book[],int n,Book b)            /*��������ɾ��ָ��ѧ�ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(book[i],b,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(book[i],b,1)����*/ 
		book[j]=book[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}