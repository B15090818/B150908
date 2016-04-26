/* ��book.h�ļ����������� */
#ifndef _BOOK             /*�������룬��ֹ�ظ������Ĵ���*/
#define _BOOK
#include <string.h>
#define NUM 20                /*����ͼ�鳣�����˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Student                   /*ѧ����¼��������*/
{
		long num;              /*ѧ�� */
		char name[20];        /*���� */
		 
};
struct Book
{
	char title[20];          /*���� */
	long number[20];            /*������ */
	char state[4];             /*����״̬ */
	int kc;                    /*���*/
};
typedef struct Book Book;
#define sizeBook sizeof(Book)      /*һ��ͼ���¼����Ҫ���ڴ�ռ��С*/
int readBook(Book book[],int n);       /*�������鼮����*/
void printB00k( Book  *Book , int n);   /*��������鼮��¼��ֵ*/
void sortBook(Book book[],int n,int condition);   /*ѡ�񷨴Ӵ�С���򣬰�condition���涨������*/
int searchBook(Book book[],int n,Book b,int condition,int f[]) ;  /*������������������b��ȵĸ�Ԫ��*/
int addBook(Book book[],int n,Book b);                   /*������������һ��ͼ����Ϣ*/
int deleteBook(Book book[],int n,Book b);                   /*��������ɾ��һ��ͼ����Ϣ*/
#endif