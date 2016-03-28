#include <iostream>
/*
ADT List
Data
	The data of List set is {a1,a2,...,an},the type of element is DataType. Among them,except for the first one,each element has a direct precuisor and except for the last one,each of wich has a direct successor. The relationship between data elements is one to one relationship.
Operation
	InitList(*L):Init the List L
	ListEmpty(*L): if the List L is empty ,return ture,else return false
	ClearList(*L): clear the List L
	GetElem(L,i,*e):return the i element of L to e
	LocalElem(L,e): 
	ListInsert(*L,i,e):
	ListDelete(*L,i,*e):
	ListLength(L):
	unionL(*La,Lb):
	ListTraverse(SqList L):
endADT
*/

using namespace std;

#define MAXSIZE 20
typedef int ElemType;
typedef struct 
{
	ElemType data[MAXSIZE];
	int length;	
}SqList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

Status InitList(SqList *L)
{
	L->length =0;
	return OK;
}

Status ListEmpty(SqList *L)
{
	if (L->length == 0)
		return TRUE;
	else
		return FALSE;
}

Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

int ListLength(SqList *L)
{
	return L->length;
}

Status GetElem(SqList L,int i,ElemType *e)
{
	if(L.length == 0 || i < 1 || i>i.length)
		return ERROR;
	*e = L.data[i];
	return OK;
}


int LocalElem(SqList L,e)
{
	int k;
	if (L.length == 0)
		return ERROR;
	for (k = 0;k < L.length;k++)
	{
		if (L.data[k] == e) 
		{
			break;
		}
	}
	if  (k < L.length - 1)
		return k;
	else
		return ERROR;

}

Status ListInsert(SqList *L,int i, ElemType e)
{
	int k;
	if(L->length == MAXSIZE)
		return ERROR;
	if(i < 1 || i > L-> length)
		return ERROR;
	if (i < L->length)
	{
		for (k = L->length - 1;k >= i ; k--)
		{
			L->data[k+1] = L->data[k];			
		}
	}
	L->data[i] = e;
	L->length ++;
	return OK;
}

Status ListDelete(SqList *L,int i,ElemType e)
{
	int k;
	if (L->length == 0)
		return ERROR;
	if (i < 1 || i > L->length)
		return ERROR;
	*e = L->data[i];
	if (i < L->length)
	{
		for (k = i+1; k<L->length;k++)
			L->data[k-1] = L->data[k];
	}
	L->length--;
	return OK;
}



void unionL(List *La,List Lb)
{
	int La_len,Lb_len,i;
	ElemType e;
	La_len = ListLength(*La);
	Lb_len = ListLength(*Lb);
	for (i = 0; i < La_len i++)
	{
		GetElem(Lb,i,&e);
		if(!LocalElem(*La,e))
		{
			ListInsert(La,++La_len,e);
		}
	}
}

Status ListTraverse(SqList L)
{
	int i;
	for (i = 0;i < L.length; i++)
	{
		cout << L[i] << endl;
	}
}

int main()
{
	SqList L;
	SqList Lb;
	ElemType e;
	Status i;
	int j,k;

	i = InitList(&L);
	cout << "is the SqList L is empty: " << ListEmpty(&L) << endl;
	cout << "after init the SqList L : L.ength = " << ListLength(&L) << endl;

	for ( j = 0; j <= 5; j++)
		i = ListInsert(&L,j,j);
	i = ListTraverse(L);

	GetElem(L,3,&e);
	cout << "the 3 element of L is "<< e << endl;

	cout << "element 2 in L local is " << LocalElem(L,2) << endl;

	cout << "the length of SqList L is : " << L.length << endl;


	i = ClearList(&L);
	cout << "after clear the SqList L ,is L is empty ? "<< ListEmpty(&L);


	return 0;

}