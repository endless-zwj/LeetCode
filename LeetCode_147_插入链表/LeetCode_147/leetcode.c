#define _CRT_SECURE_NO_WARNINGS

/*
对链表进行插入排序。

从第一个元素开始，该链表可以被认为已经部分排序。
每次迭代时，从输入数据中移除一个元素，并原地将其插入到已排好序的链表中。

插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/insertion-sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	struct ListNode *sortHead = head, *cur = head->next;
	sortHead->next = NULL;

	while (cur) {

		//进行迭代的条件
		struct ListNode* next = cur->next;
		struct ListNode *p = NULL, *q = sortHead;

		//该循环用于插入元素
		while (q != NULL) {
			if (cur->val < q->val) {
				break;//在外部进行插入操作,在内部操作
				//如果插入元素大于已排序的所有元素，
				//那么其将无法插入,造成元素丢失
			}
			else {
				p = q;
				q = q->next;
			}
		}

		if (p == NULL) {
			cur->next = q;
			sortHead = cur;
		}
		else {
			//无论cur是否为最大值,都能将其插入
			p->next = cur;
			cur->next = q;
		}

		cur = next;

	}
	return sortHead;
}
void Print(struct ListNode* head) {
	while (head) {
		printf("%d->", head->val);
		head = head->next;
	}
	printf("NULL\n");
}

int main() {
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->val = 4;
	n2->val = 2;
	n3->val = 1;
	n4->val = 5;
	n5->val = 3;
	n6->val = 6;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;


	struct ListNode* head = insertionSortList(n1);
	Print(head);

	return 0;
}
