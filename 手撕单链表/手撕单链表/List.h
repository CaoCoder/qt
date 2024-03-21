// slist.h
#include <assert.h>
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;//����
	struct SListNode* next;//ָ����һ���ڵ�
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);
// �������ӡ
void SListPrint(SListNode* plist);
// ������β��
void SListPushBack(SListNode* pplist, SLTDateType x);
// �������ͷ��
void SListPushFront(SListNode* pplist, SLTDateType x);
// �������βɾ
void SListPopBack(SListNode* pplist);
// ������ͷɾ
void SListPopFront(SListNode* pplist);
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);

//����
void SLDestroy(SListNode* pphead);
// ��pos��ǰ�����
//void SLInsert(SLNode** pphead, SLNode* pos, SLNDataType x);
//// ɾ��posλ��
//void SLErase(SLNode** pphead, SLNode* pos);
//void SLDestroy(SLNode** pphead);


