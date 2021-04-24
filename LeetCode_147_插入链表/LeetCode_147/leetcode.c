#define _CRT_SECURE_NO_WARNINGS

/*
��������в�������

�ӵ�һ��Ԫ�ؿ�ʼ����������Ա���Ϊ�Ѿ���������
ÿ�ε���ʱ���������������Ƴ�һ��Ԫ�أ���ԭ�ؽ�����뵽���ź���������С�

���������㷨��

���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
�ظ�ֱ�������������ݲ�����Ϊֹ��

��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/insertion-sort-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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

		//���е���������
		struct ListNode* next = cur->next;
		struct ListNode *p = NULL, *q = sortHead;

		//��ѭ�����ڲ���Ԫ��
		while (q != NULL) {
			if (cur->val < q->val) {
				break;//���ⲿ���в������,���ڲ�����
				//�������Ԫ�ش��������������Ԫ�أ�
				//��ô�佫�޷�����,���Ԫ�ض�ʧ
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
			//����cur�Ƿ�Ϊ���ֵ,���ܽ������
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
