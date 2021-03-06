struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode * scout_ptr = head;
    int list_size = 0;
    while (scout_ptr != nullptr) {
      scout_ptr = scout_ptr->next;
      list_size ++;
    }

    if (list_size < k) {
      return head;
    }

    ListNode * cur_node = head;
    ListNode * pre_node = nullptr;
    ListNode * next_node = nullptr;
    ListNode * group_start_node = head;
    ListNode ** ptr_to_node_ptr = &head;
    int group_size = 0;
    while (cur_node != nullptr) {
      next_node = cur_node->next;
      cur_node->next = pre_node;
      pre_node = cur_node;
      cur_node = next_node;
      group_size ++;

      if (group_size == k) {
        group_start_node->next = cur_node;
        *ptr_to_node_ptr = pre_node;
        ptr_to_node_ptr = &(group_start_node->next);
        group_start_node = cur_node;
        group_size = 0;
        list_size = list_size - k;
        if (list_size < k) {
          break;
        }
      }
    }

    return head;
  }

  ListNode* reverseKGroup2(ListNode* head, int k) {
    ListNode * sentry_node = new ListNode(0);
    ListNode * pre_node = sentry_node;
    // so we can access cur_node->next directly
    ListNode * cur_node = pre_node;
    sentry_node->next = head;
    int len = 0;

    while (cur_node->next != nullptr) {
      cur_node = cur_node->next;
      len++;
    }

    while (len >= k) {
      // assgin cur_node to head
      cur_node = pre_node->next;
      for (int i = 1; i < k; i++) {
        ListNode * next_node = cur_node->next;
        cur_node->next = next_node->next;
        next_node->next = pre_node->next;
        pre_node->next = next_node;
      }

      pre_node = cur_node;
      len -= k;
    }

    return sentry_node->next;
  }

  ListNode * reverseKGroup3(ListNode * head, int k) {
    if (head == nullptr || head->next == nullptr || k == 1) {
        return head;
    }

    ListNode *sub_list_head = head;
    int sub_list_length = k;
    while (--sub_list_length && sub_list_head->next != nullptr) {
        sub_list_head = sub_list_head->next;
    }

    if (sub_list_length != 0) {
        return head;
    }

    ListNode * pre_node = ReverseNodeinKGroup(sub_list_head->next, k);
    ListNode * cur_node = head;
    ListNode * next_node = nullptr;

    for (int i = 0; i < k; i++) {
        next_node = cur_node->next;
        cur_node->next = pre_node;
        pre_node = cur_node;
        cur_node = next_node;
    }

    return pre_node;
  }
};
