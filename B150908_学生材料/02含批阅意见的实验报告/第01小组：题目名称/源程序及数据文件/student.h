/* ��Book.h�ļ����������� */  
#ifndef _BOOK             /*�������룬��ֹ�ظ������Ĵ���*/  
#define _BOOK  
#include <string.h>  
#define NUM 20                /*����ͼ�����ೣ�����˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/  
struct Book                 /*ͼ���¼��������*/  
 {  
        char ISBN[18];               //��ı��
	char name[20];               //����
	float price;               //��ĵ���
	char category[20];          //�������
        char  authername[20];            //��������
	int remain;                  //��Ŀ��
        int  salevolume[3];             //ÿ�����������
        int total;                 //�����µ�������
        float sales                    //������۶�
 };  
 typedef struct Book Book;  
 #define sizeBk sizeof(Book)      /*һ��ͼ���¼����Ҫ���ڴ�ռ��С*/  
 int readBk(Book bk[],int n);       /*����ͼ���¼ֵ�������涨������¼ʱֹͣ*/  
 void printBk(Book  *bk , int n);   /*�������ͼ���¼��ֵ*/  
  
int equal(Book b1,Book b2,int condition);  /*����condition�����ж�����Book����������ȷ�*/  
int larger(Book b1,Book b2,int condition);  /*����condition�Ƚ�Book�������ݴ�С*/  
void reverse(Book bk[],int n);             /*ͼ���¼����Ԫ������*/  
  
void calcuTotal(Book bk[],int n);           /*����һ������ͼ�����������*/
void calcusales(Book bk[],int n);           /*����һ������ͼ������۶�*/    
void calcuRank(Book bk[],int n);           /*����ͼ����������������в�������*/  
void calcuMark(double m[3][3],Student stu[],int n); /*�������µ���ߡ���͡�ƽ��������m�����һά*/  
/*��ʾ�ĸ��£��ڶ�ά��ʾ��ߡ���͡�ƽ������*/  
void calcuremain(Book bk[],int n);      /*����һ�����ȵĿ��*/

void sortBk(Book bk[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/  
 
int searchBk(Book bk[],int n,Book b,int condition,int f[]) ;  /*������������������b��ȵĸ�Ԫ��*/  
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/  
int insertBk(Book bk[],int n,Book b);                   /*�������в���һ��Ԫ�ذ���������*/  
int deleteBk(Book bk[],int n,Book s);                   /*��������ɾ��һ��ָ��ͼ���Ԫ��*/  
#endif  
