/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(int l, int r, int target, MountainArray &mountainArr, bool up) {
        while (l <= r) {
            
            int mid = (l + r) / 2;
            int now = mountainArr.get(mid);

            if (now == target) {
                return mid;
            } else {
                if (up) {
                    if (now < target) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                } else {
                    if (now < target) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0, r = mountainArr.length() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }

        int peak = l;
        int idx = binarySearch(0, peak, target, mountainArr, true);
        if (idx != -1) {
            return idx;
        } else {
            return binarySearch(peak, mountainArr.length() - 1, target, mountainArr, false);
        }
        return -1;
    }
};