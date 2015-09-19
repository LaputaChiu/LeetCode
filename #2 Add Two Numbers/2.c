#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *tmp_l1 = NULL, *tmp_l2 = NULL;
	struct ListNode* output = NULL;
	struct ListNode** append = NULL;
	int carry = 0, inner_carry = 0;
	
	if(!l1) return l2;
	if(!l2) return l1;
		
	tmp_l1 = l1;
	tmp_l2 = l2;
	append = &output;
	while(tmp_l1 || tmp_l2 || carry){
		*append = (struct ListNode*)calloc(1,sizeof(struct ListNode));
		if(tmp_l1 && tmp_l2){
			(*append)->val = (tmp_l1->val + tmp_l2->val + carry >= 10)?(inner_carry = 1, (tmp_l1->val + tmp_l2->val + carry)%10):tmp_l1->val + tmp_l2->val + carry;
			carry = inner_carry;
			inner_carry = 0;
			tmp_l1 = tmp_l1->next;
			tmp_l2 = tmp_l2->next;
		}else if(!tmp_l1 && tmp_l2){
			(*append)->val = (tmp_l2->val + carry >= 10)?(inner_carry = 1, (tmp_l2->val + carry)%10):tmp_l2->val + carry;
			carry = inner_carry;
			inner_carry = 0;
			tmp_l2 = tmp_l2->next;
		}else if(tmp_l1 && !tmp_l2){
			(*append)->val = (tmp_l1->val + carry >= 10)?(inner_carry = 1, (tmp_l1->val + carry)%10):tmp_l1->val + carry;
			carry = inner_carry;
			inner_carry = 0;
			tmp_l1 = tmp_l1->next;
		}else{
			(*append)->val = carry;
			break;
		}
		append = &((*append)->next);
	}
	
	return output;
}

void freeList(struct ListNode* node){
	struct ListNode* out = NULL;
	out = node;
	while(out){
		struct ListNode* tmp;
		tmp = out->next;
		free(out);
		out = tmp;
	}
}

int main(){
	struct ListNode* l1 = (struct ListNode*)calloc(1,sizeof(struct ListNode));
	l1->val = 9;
	struct ListNode* l1_2 = (struct ListNode*)calloc(1,sizeof(struct ListNode));
	l1_2->val = 8; l1->next = l1_2;
	struct ListNode* l1_3 = (struct ListNode*)calloc(1,sizeof(struct ListNode));
	l1_3->val = 7; l1_2->next = l1_3;
	
	struct ListNode* l2 = (struct ListNode*)calloc(1,sizeof(struct ListNode));
	l2->val = 1; 
	struct ListNode* l2_2 = (struct ListNode*)calloc(1,sizeof(struct ListNode));
	l2_2->val = 1; l2->next = l2_2;
	struct ListNode* l2_3 = (struct ListNode*)calloc(1,sizeof(struct ListNode));
	l2_3->val = 2; l2_2->next = l2_3;
	struct ListNode* l2_4 = (struct ListNode*)calloc(1,sizeof(struct ListNode));
	l2_4->val = 1; l2_3->next = l2_4;
	
	struct ListNode* res = addTwoNumbers(l1, l2);
	
	struct ListNode* out = NULL;
	printf("Sum: %d",res->val);
	out = res->next;
	while(out){
		printf(" -> %d",out->val);
		out = out->next;
	}
	
	freeList(l1);
	freeList(l2);
	freeList(res);
	return 0;
}
