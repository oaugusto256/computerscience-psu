void remove_match(node * & head, int match)
{
    // case #1
    if (!head) return;
    
    // case #2 - matches with head
    if (head -> data == match)
    {    
        node * temp = head -> next
        delete head;
        head = temp;
    }
    else remove_match(head -> next , match);
}
