class Solution {
public:
    int findClosest(int x, int y, int z) {
        if (x == z && y == z) return 0;
        if (x == z) return 1;
        if (y == z) return 2;
        int nextX = x + (x < z ? 1 : -1), nextY = y + (y < z ? 1 : -1);
        return findClosest(nextX, nextY, z);
    }
};