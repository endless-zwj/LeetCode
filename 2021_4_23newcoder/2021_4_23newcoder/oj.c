#define _CRT_SECURE_NO_WARNINGS
/*
	题：删除有序链表中的重复节点
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

			// 1) 找重复的元素 后移cur,prev.next
			if (cur->val != next->val) {
				prev = cur;
				cur = next;
				next = next->next;
			}
			else { //找到不同于cur->val的值
				while (next && (next->val == cur->val)) {
					next = next->next;
				}
				//删除重复元素
				while (cur != next) {
					struct ListNode* del = cur;
					cur = cur->next;
					free(del);
				}
				//链接断了的链表，因为删除元素后，prev是没有链接到新的cur的
				//判断prev是否为空，从而确定是否需要改变头结点
				if (prev == NULL) {
					pHead = cur;
				}
				else {
					prev->next = cur;
				}
				//判断next是否为空,并更新next ;
				if (next) {
					next = next->next;
				}
			}
		}
		return pHead;
	}
};