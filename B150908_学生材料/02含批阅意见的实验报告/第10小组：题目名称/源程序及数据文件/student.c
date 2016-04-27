/*��player.c�ļ�����������*/
	#include "player.h"
	#include <stdio.h>
	
	int readPla(Player  *pla , int n)          /*������Ա��¼ֵ����Ա����Ϊ0������涨������¼ʱֹͣ*/
	{
		int i,j;
		for (i=0;i<n;i++)
		{
			printf("Input one player\'s information\n");
			printf("num:  ");
		     scanf("%ld", &pla[i].num);
			if (pla[i].num==0) break;
			printf("name: ");
			scanf("%s",pla[i].name);	
			printf("nation:  ");
			scanf("%s",pla[i].nation);
	    	     pla[i].total=0;                /*�ܷ���Ҫ������ã���ֵ��Ϊ0*/
			printf("Input three courses of the player:\n");
			for (j=0;j<3;j++)
		    {
			    scanf("%d",&pla[i].score[j]);	
			}
			      
		}
		return i;                         /*����ʵ�ʶ���ļ�¼����*/
	}
	
	void printPla ( Player  *pla , int n)       /*���������Ա��¼��ֵ*/
	{
	    int i,j;
		for (i=0;i<n;i++)
		{
			printf("%8ld  ", pla[i].num);
			printf("%8s", pla[i].name);
			printf("%8s", pla[i].nation);
			for (j=0;j<3;j++)
			   printf("%6d",pla[i].score[j]);
	
		    printf("%5d\n",pla[i].rank);
		}
	}
	
	int equal(Player s1,Player s2,int condition)  /*����ж�����Player��¼���*/
	{
		if (condition==1)                    /*�������condition��ֵΪ1����Ƚ���Ա����*/
			return s1.num==s2.num;
		else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
	     {
		     if (strcmp(s1.name,s2.name)==0) 	return 1;
			else return 0;
	     }
	 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
		     return s1.rank==s2.rank;
	             
			
		else return 1;                       /*�����������1*/
	} 
	
	int larger(Player s1,Player s2,int condition)  /*����condition�����Ƚ�����Player��¼�Ĵ�С*/
	{
		if (condition==1)                    /*�������condition��ֵΪ1����Ƚ���Ա����*/
			return s1.num>s2.num;
	
	
		else return 1; /*�����������1*/
	}
	
	void reverse(Player pla[],int n)             /*����Ԫ������*/
	{
		int i;
		Player temp;
		for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
		{
			temp=pla[i];
			pla[i]=pla[n-1-i];
			pla[n-1-i]=temp;
		}
	}
	
	void calcuTotal(Player pla[],int n)         /*����������Ա���ܷ�*/
	{
		int i,j;
		for (i=0;i<n;i++)                    /*���ѭ������������Ա��¼*/
		{
			pla[i].total =0;
			     
				pla[i].total +=pla[i].score[1];
		}	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	void calcuMark(double m[3][3],Player pla[],int n) /*���������ݵ���ߡ������*/
	/*������ʽ������ά����m�ĵ�һά�������ſΣ��ڶ�ά������ߡ����*/
	{
		int i,j;
		for (i=0;i<3;i++)                 /*���������ݵ���߷�*/		
		{ 
			m[i][0]=pla[0].score[i];     
			for (j=1;j<n;j++)
				if (m[i][0]<pla[j].score[i])
					m[i][0]=pla[j].score[i];
		}
		for (i=0;i<3;i++)                  /*���������ݵ���ͷ�*/
		{ 
			m[i][1]=pla[0].score[i];      
			for (j=1;j<n;j++)
				if (m[i][1]>pla[j].score[i])
					m[i][1]=pla[j].score[i];
		}
	
	
	 ��
	
	
		
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	void sortPla(Player pla[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
	{
		int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
		Player t;
		for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
		{
			minpos=i;
			for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
				if (larger(pla[minpos],pla[j],condition))
					minpos=j;
			if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
			{
				t=pla [i];
				pla[i]=stu[minpos];
				pla[minpos]=t;
			}
		}
	}
	
	int searchPla(Player pla[],int n,Player s,int condition,int f[ ])  /*��pla��������condition��������*/
	/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
	{
		int i,j=0,find=0;
		for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
			if (equal(pla[i],s,condition))  
			{
				f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
				find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
			}
		 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
	}
	
	int insertPla(Player pla[],int n,Player s)              /*��pla����������Ա�����������һ��Ԫ��s*/
	{
		int i;
		sortPla(pla,n,1);                              /*�Ȱ���Ա��������*/
		for (i=0;i<n;i++)
		{
			if (equal(pla[i],s,1))                      /*��Ա������ͬ��������룬��֤��Ա�����Ψһ��*/
			{
			    printf("this record exist,can not insert again!\n");
			    return n;
			}
		}
		for (i=n-1;i>=0;i--)                          /*����Ա�����С��������*/
		{
			if (!larger(pla[i],s,1))                    /*���s���ڵ�ǰԪ��pla[i]�����˳�ѭ��*/
			break;
			pla[i+1]=pla[i];                         /*����Ԫ��pla[i]����һ��λ��*/
		}
		pla[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                   
		n++;                                     /*Ԫ�ظ�������1*/
		return n;                                  /*��������Ԫ�ظ���*/
	}
	
	int deleteStu(Player stu[],int n,Player s)            /*��������ɾ��ָ����Ա�����һ��Ԫ��*/
	{
		int i,j;
		for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
			if (equal(pla[i],s,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
		if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
		{
			printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
			return n;
		}
		for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(pla[i],s,1)����*/ 
			pla[j]=pla[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
	                                                                            
		n--;                                      /*Ԫ�ظ������ټ�1*/
		return n;                                  /*�������и���*/
	}
