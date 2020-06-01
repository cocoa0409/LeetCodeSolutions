/*
 由于n+1个1-n的数字
 建立有向图，n+1个节点
 有nums[i]指向nums[nums[i]]，必然有环，反证法假设无环，则构成链表，但是n个节点有n+1个入度，必然有一个节点有2个入度
 有入度说明nums有一位置为该元素，故多入度的节点一定是环的入口
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
