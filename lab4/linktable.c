#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
tLinkTable *CreateLinkTable(){
tLinkTable *pLinkTable=(tLinkTable*)malloc(sizeof(tLinkTable));
pLinkTable->pHead=NULL;
pLinkTable->SumOfNode=0;
return pLinkTable;
}//实例化链表结构体
int DeleteLinkTable(tLinkTable *pLinkTable){
if(pLinkTable==NULL){
return FAILURE;
}
if(pLinkTable->pHead==NULL){
free(pLinkTable);
return SUCCESS;
}
tLinkTableNode *pNode=GetLinkTableHead(pLinkTable);
tLinkTableNode *pTempNode;
while(pNode!=NULL){
pTempNode=pNode;
pNode=GetNextLinkTableNode(pLinkTable,pNode);
free(pTempNode);
}
free(pNode);
return SUCCESS;

}//删除链表
int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode){
if(pLinkTable==NULL || pNode==NULL){
return FAILURE;
}
if(pLinkTable->pHead==NULL){
pLinkTable->pHead=pNode;
return SUCCESS;
}
tLinkTableNode *ptrNode=GetLinkTableHead(pLinkTable);
while(ptrNode->pNext !=NULL){
ptrNode=ptrNode->pNext;
}
ptrNode->pNext=pNode;
return SUCCESS;

}//尾插节点
int DeleteLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode){
if(pLinkTable==NULL || pNode==NULL){
return FAILURE;
}
if(pLinkTable->pHead==NULL){
free(pLinkTable->pHead);
return SUCCESS;
}
tLinkTableNode *ptrNode=GetLinkTableHead(pLinkTable);
while(ptrNode->pNext!=pNode){
ptrNode=ptrNode->pNext;
}
tLinkTableNode *ptrTemp=ptrNode->pNext;
ptrNode->pNext=ptrTemp->pNext;
free(ptrTemp);
return SUCCESS;
}//删除节点
tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable){
if(pLinkTable==NULL || pLinkTable->pHead==NULL){
return NULL;
}
tLinkTableNode *pNode=pLinkTable->pHead;
return pNode;
}//取头节点
tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode){
if(pLinkTable==NULL||pLinkTable->pHead==NULL){
return NULL;
}
return pNode->pNext;
}//获取下一节点
