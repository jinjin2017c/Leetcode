#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10    //chushihuabiaochang
#define INCREMENT_SIZE 5    //feipeizengliang

typedef int Status;

typedef int Elemtype;

/*
*chunchujiegou
*/

typedef struct
{
    Elemtype *elem ;       //
    int length;            //
    int size;              //
}SqList;

/*
 * 
 */
Status InitList(SqList *L)
{
    L->elem =(Elemtype *) malloc(INIT_SIZE * sizeof(Elemtype));
    if(!L->elem) 
    {
    	return ERROR;
    }
    L->length = 0;
    L->size = INIT_SIZE ;
    return OK ;
}

/*
 * 
 */
Status ClearList(SqList *L)
{
    free(L->elem);
    L->length = 0;
    L->size = 0;
    return OK;
}
/*
 *
 */
Status ClearList(SqList *L)
{
    L->length = 0;
    return OK;
}
/*
 * 
 */
Status isEmpty(const SqList L)
{
    if(0 == L.length)
    {
        return TURE;
    }
    else
    {
        return FALSE;
    }
}
/*
 *
 */
Status getLength(const SqList L)
{
    return L.length;
}
/*
 * 
 */
Status GetElem(const SqList L, int i, Elemtype *e)
{
    if(i < 1||i > L.length)
    {
	return ERROE;
    }
    *e = L.elem[i-1];
    return OK;
}
/*
 *
 */
Status compare(Elemtype e1,Elemtype e2)
{
    if(e1 == e2)
    {
        return 0;
    }
    else if (e1<e2)
    {
	return -1;
    }
    else
    {
        return 1;
    }
}
/*
 *
 */
status FindElem(const SqList L,Elemtype e,Status(*compare)(Elemtype,Elemtype))
// yu qian yi ge hanshu de cixu qianhou huiyouguanxi ma ?
{
    int i;
    for (i = 0; i < L.length; i++)
    {
	if(!(*compare)(L.elem[i],e))
        {
            return i + 1;
        }
    }
    if(i >= L.length)
    {
        return ERROR;
    }
}
/*
 *
 */
Status PreElem(const SqList L,Elemtype cur_e,Elemtype *pre_e)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
	if(cur_e == L.elem[i])
        {
	    if(i != 0)
            {
		*pre_e = L.elem[i-1];
	    }
            else
	    {
		return ERROR;
	    }
	}
    }
    if(i >= L.length)
    {
	return ERROR;
    }
} 
/*
 *
 */
Status NextElem(const SqList L,Elemtype cur_e, Elemtype *next_e)
{
    int i;
    for(i = 0; i < L.length; i++)
    {
	if(cur_e == L.elem[i] )
	{    
            if(i < L.length -1)
	    {
		*next_e = L.elem[i+1];
		return OK;
	    }
	    else
     	    {
       	        return ERROR;
	    }
	}
    }
    if(i >= L.length)
    {
	return ERROR;
    }
}


