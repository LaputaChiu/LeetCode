#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 /* Definition for singly-linked list. */
struct ListNode {
	int val;
	struct ListNode *next;
};

/*struct ListNode* swapNode(struct ListNode* head, struct ListNode* preNodeA, struct ListNode* NodeA, struct ListNode* preNodeB, struct ListNode* NodeB){
	struct ListNode* temp = NULL;

	if(preNodeA) preNodeA->next = NodeB;
	if(NodeA != preNodeB){
		preNodeB->next = NodeA;
	
		temp = NodeB->next;
		NodeB->next = NodeA->next;
		NodeA->next = temp;
	}else{
		NodeA->next = NodeB->next;
		NodeB->next = NodeA;
	}

	return (preNodeA)?head:NodeB;
}*/

/* move a node to head */
struct ListNode* moveNodeToFront(struct ListNode* head, struct ListNode* preNode, struct ListNode* Node){
	preNode->next = Node->next;
	Node->next = head;
	return Node;
}

/* although it has worst case of time complexity of O(n^2) for Quick Sort, 
 * i insisted on conquering the constraint by setting up 'diff' checking in each comparison to pivot */
struct ListNode* innerSortList(struct ListNode* head, struct ListNode* end) {
	bool isSorted = true;
	int lastdiff = 0;
	struct ListNode* newHead = head;

	if(head != end && head->next != end){
		struct ListNode* pivot = head;
		struct ListNode* preNode = head;
		struct ListNode* Node = head->next;
		struct ListNode* postNode = NULL; 
		// compare if it is smaller than pivot, then move it to the head
		while(Node != end){
			int curdiff = 0;
			postNode = Node->next;
			if((curdiff = Node->val - pivot->val) < 0){
				//newHead = moveNodeToFront(newHead, preNode, Node);
				preNode->next = Node->next;
				Node->next = newHead;
				newHead = Node;
			}
			if(curdiff < lastdiff) isSorted = false;
			lastdiff = curdiff;

			preNode = (Node->val < pivot->val)?preNode:Node;
			Node = postNode;
		}
		if(isSorted) return newHead;

		// sort nodes at left of head
		newHead = innerSortList(newHead, pivot);
	
		// sort nodes at right of head
		pivot->next = innerSortList(pivot->next, NULL);
	}

	return newHead;
}

struct ListNode* sortList(struct ListNode* head) {
	return innerSortList(head, NULL);
}

int main(){
	struct ListNode head = {0};
	struct ListNode node1 = {0};
	struct ListNode node2 = {0};
	struct ListNode node3 = {0};
	struct ListNode node4 = {0};
	struct ListNode node5 = {0};
	struct ListNode node6 = {0};
	struct ListNode node7 = {0};
	head.val = 4;
	head.next = &node1;
	node1.val = 1;
	node1.next = &node2;
	node2.val = 5;
	node2.next = &node3;
	node3.val = 2;
	node3.next = &node4;
	node4.val = 7;
	node4.next = &node5;
	node5.val = 8;
	node5.next = &node6;
	node6.val = 3;
	node6.next = &node7;
	node7.val = 6;
	node7.next = NULL;
	
	// head -> node1 -> node2 -> node3 -> node4
	
	struct ListNode *node = &head;
	printf("Before sorting ...\n");
	while(node != NULL){
		printf("%d->",node->val);
		node = node->next;
	}
	printf("NULL\n");

	//node = swapNode(&head, NULL, &head, &node3, &node4);
	//node = moveNodeToFront(&head, &node3, &node4);
	node = sortList(&head);

	printf("After sorting ...\n");
	while(node != NULL){
		printf("%d->",node->val);
		node = node->next;
	}
	printf("NULL\n");
	return 0;
}
