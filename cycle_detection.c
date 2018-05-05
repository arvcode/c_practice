/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
/* Based on Floyd's cycle detection algorithm */

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node *ptr=NULL;
    Node *old_ptr=NULL;
    ptr=head;
    old_ptr=head->next;
    while (ptr!=NULL && old_ptr!=NULL) {
        old_ptr=old_ptr->next;
        if (old_ptr==NULL) {
            return false;
        }
        old_ptr=old_ptr->next;
        ptr=ptr->next;
        if (ptr==head) {
            return true;
        }
        if (ptr==old_ptr) {
            return true;
        }
    }
    return false;
}

