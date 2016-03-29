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
typedef int Element;
typedef int Status;
#define ERROR 0
#define OK 1
#define TURE 1
#define FALSE 0

typedef struct Node
{
	Element data;
	struct Node *next;
}Node;

typedef struct Node *LinkList;
Status GetElem(LinkList L,int i,Element *e)
{
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while (p&&j < i)
	{
		p = p->next;
		++j;
	}
	if( !p || j>i)
		return ERROR;
	*e = p->data;
	return OK;
}

Status ListInsert(LinkList *L,int i,Element e)
{
	int j;
	LinkList p,s;
	p = *L;
	j =  1;
	while(p && j < i)
	{
		p = p->next;
		++j
	}
	if (!p || j > i)
		return ERROR;
	s = (LinkList) malloc (sizeof(Node));
	s -> data = e;
	s -> next = p -> next;
	p ->next = s;
	return OK;
}

Status ListDelete(LinkList *L,int i , Element *e)
{
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (!p || j < i)
	{
		p = p->next;
		++j;
	}

	if ( !p->next || j > i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q -> data;
	free (q);
	return OK;
}

void CreateListHead(LinkList *L,int n)
{
	LinkList p;
	int i;
	srand (time(0));
	*L = (LinkList) malloc (sizeof(Node));
	(*L) -> next = NULL;
	for (i = 0;i < n;i++)
	{
		p = (LinkList) malloc (sizeof(Node));
		p->data = rand() % 100 +1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void CreateListTail (LinkList *L,int n)
{
	LinkList p,r;
	int i;
	srand(time(0));
	*L = (LinkList) malloc (sizeof(Node));
	r = *L;
	for(i = 0;i < n;i++)
	{
		p = (LinkList) malloc (sizeof(Node));
		p ->data = rand() % 100 + 1;
		r -> next = p;
		r = p;
	}
	r -> next = NULL;
}

Status ClearList(LinkList *L)
{
	LinkList p,q;
	p = (*L)->next;
	while(p)
	{
		q = p ->next;
		free(p);
		p = q;		
	}
	(*L) -> next = NULL;
	return OK;
}