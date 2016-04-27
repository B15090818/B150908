/* ��player.h�ļ����������� */
#ifndef _PLAYER             /*�������룬��ֹ�ظ������Ĵ���*/
#define _PLAYER
#include <string.h>
#define NUM 20                /*������Ա�����������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Player                   /*ѧ����¼��������*/
{
		long number;
		char name[20];
		int score[5];
		int assist[5];
		int rebounds[5];
		int steals[5];
            int  turnover[5];
              int sum;
              int rank;
};
typedef struct Player player;
#define sizeStu sizeof(Player)      /*һ����Ա��¼����Ҫ���ڴ�ռ��С*/
int readPla(Player pla[],int n);       /*������Ա��¼ֵ�����º�Ϊ0������涨������¼ʱֹͣ*/
void printStu(Player  *pla , int n);   /*���������Ա��¼��ֵ*/

int equal(Player s1,Player s2,int condition);  /*����condition�����ж�����Player����������ȷ�*/
int larger(Player s1,Player s2,int condition);  /*����condition�Ƚ�Player�������ݴ�С*/
void reverse(Player pla[],int n);             /*��Ա��¼����Ԫ������*/

void calcuTotal(Player pla[],int n);           /*����������Ա���ܵ÷�*/
void calcuRank(Player pla[],int n);           /*�����ּܷ���ѧ�������Σ������в�������*/
void sortStu(Player pla[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/

int searchPla(Player pla[],int n,Player s,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertPla(Player pla[],int n,Player s);                   /*�������в���һ��Ԫ�ذ����º�����*/
int deletePla(Player pla[],int n,Player s);                   /*��������ɾ��һ��ָ�����ºŵ�Ԫ��*/
#endif
