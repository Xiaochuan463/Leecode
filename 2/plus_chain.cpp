class ListNode{
public:
        int val;
        ListNode* next;
        ListNode(): val(0), next(nullptr){}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res, *tmp_res, *tmp1, *tmp2;
        int c = 0;
        res = new ListNode(0);
        tmp_res = res;
        c = l1->val + l2->val;
        res->val = c % 10;
        c = c/10;
        tmp1 = l1->next;
        tmp2 = l2->next;
        while (tmp1 || tmp2)
        {
                if(tmp1){
                        c += tmp1->val;
                        tmp1 = tmp1->next;
                }
                if(tmp2){
                        c += tmp2->val;
                        tmp2 = tmp2->next;
                }
                tmp_res->next = new ListNode(c%10);
                c = c / 10;
                tmp_res = tmp_res->next;
        }
        if(c){
                tmp_res->next = new ListNode(c);
        }
        return res;
}