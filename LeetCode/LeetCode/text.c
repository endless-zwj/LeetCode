#define _CRT_SECURE_NO_WARNINGS

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode* p1 = headA;
	struct ListNode* p2 = headB;

	while (p1 != NULL)
	{
		if (p2 == NULL)
		{
			p2 = headA;
		}
		p1 = p1->next;
		p2 = p2->next;
	}

	p1 = headB;
	while (p1 != NULL)
	{
		if (p2 == NULL)
		{
			p2 = headA;
		}
		if (p1 == p2)
		{
			return p1;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return NULL;



}