class MyLinkedList {
public:
    // Define ListNode
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v) : val(v), next(nullptr) {}
    };

    ListNode* head;
    int size;

    // Constructor
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    // Get value at index
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode* curr = head;
        for (int i = 0; i < index; i++) curr = curr->next;
        return curr->val;
    }
    
    // Add node at head
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
        size++;
    }
    
    // Add node at tail
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        if (!head) head = node;
        else {
            ListNode* curr = head;
            while (curr->next) curr = curr->next;
            curr->next = node;
        }
        size++;
    }
    
    // Add node at specific index
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        ListNode* curr = head;
        for (int i = 0; i < index - 1; i++) curr = curr->next;
        ListNode* node = new ListNode(val);
        node->next = curr->next;
        curr->next = node;
        size++;
    }
    
    // Delete node at specific index
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size || !head) return;
        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        } else {
            ListNode* curr = head;
            for (int i = 0; i < index - 1; i++) curr = curr->next;
            ListNode* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        size--;
    }
};