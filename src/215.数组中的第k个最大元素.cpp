/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 * 基于堆排序的算法，需要好好了解
 */
// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    // 递归处理根节点与子节点最大值互换
    void maxHeapify(vector<int> &a, int i, int heapSize) {
        // 对于完全二叉树，根节点索引为 i ，其左右子节点的索引分别为
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int largest = i;

        // 将根节点的值与左右节点值比较，取最大
        if (left < heapSize && a[left] > a[largest]) largest = left;
        if (right < heapSize && a[right] > a[largest]) largest = right;

        // 当发生了替换时，对数组进行操作
        // 递归处理发生了改变的子节点的子节点（若存在孙子节点）
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    // 初步构造大根堆，将各子树最大值上浮
    void buildMaxHeap(vector<int> &a, int heapSize) {
        // 从倒数第一个非叶子节点的根节点开始，调整顺序
        // 对于完全二叉树，最后一个非叶子的根节点的索引为 size / 2 - 1
        for (int i = heapSize / 2 - 1; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        // 初步构造大根堆，此时堆顶为第一大元素
        buildMaxHeap(nums, heapSize);
        // 删除 k-1 次堆顶并递归构造大根堆，最后的堆顶即为第 k 大元素
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};
// @lc code=end

