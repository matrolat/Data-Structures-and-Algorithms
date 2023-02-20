#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int val;
	Node *next;
};


int main()
{
	//Node declarations
	Node* head = new Node;
	//dummy
	Node* dummy = new Node;
	dummy->val = -1;
	dummy->next = head;
	//
	Node* ans = new Node;
	ans = dummy;
	//
	Node* second = new Node;
	Node* third = new Node;
	head->val = 4;
	head->next = second;
	second->val = 5;
	second->next = third;
	third->val = 6;
	third->next = NULL;
	//deleting one element
	int target = 0;
	
	
	// head->next = head->next->next;
	// cout << target << endl;
	// while (head != NULL) {
// 		
		// if(head->next->val == target){
			// head->next = head->next->next;
		// }
// 						
		// head = head->next;
// 		
    // }
    
    
    while(dummy !=NULL){
    	if(dummy->next!=NULL &&  dummy->next->val == target){
    		// cout << " oh hello " ;
			dummy->next = dummy->next->next;
		}
    	// cout << head->val << " ";
    	dummy = dummy->next;
    }
    
    
    
    // cout << ans->next->val << endl;
    while(ans!=NULL)
    {
    	cout << ans->val << " ";
    	ans= ans->next;
    }
    
    
    
    
    
    
    
    
    
    
    
    
	
	
	return 0;
}