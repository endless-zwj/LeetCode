#define _CRT_SECURE_NO_WARNINGS
/*
	�⣺ɾ�����������е��ظ��ڵ�
*/

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL) return pHead;
		struct ListNode *prev = NULL, *cur = pHead, *next = pHead->next;
		while (next) {

			// 1) ���ظ���Ԫ�� ����cur,prev.next
			if (cur->val != next->val) {
				prev = cur;
				cur = next;
				next = next->next;
			}
			else { //�ҵ���ͬ��cur->val��ֵ
				while (next && (next->val == cur->val)) {
					next = next->next;
				}
				//ɾ���ظ�Ԫ��
				while (cur != next) {
					struct ListNode* del = cur;
					cur = cur->next;
					free(del);
				}
				//���Ӷ��˵�������Ϊɾ��Ԫ�غ�prev��û�����ӵ��µ�cur��
				//�ж�prev�Ƿ�Ϊ�գ��Ӷ�ȷ���Ƿ���Ҫ�ı�ͷ���
				if (prev == NULL) {
					pHead = cur;
				}
				else {
					prev->next = cur;
				}
				//�ж�next�Ƿ�Ϊ��,������next ;
				if (next) {
					next = next->next;
				}
			}
		}
		return pHead;
	}
};