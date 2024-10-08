#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trapRainWater(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> left_max(n), right_max(n);
    int total_water = 0;

    // Fill left_max array
    left_max[0] = height[0];
    for (int i = 1; i < n; i++) {
        left_max[i] = max(left_max[i - 1], height[i]);
    }

    // Fill right_max array
    right_max[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right_max[i] = max(right_max[i + 1], height[i]);
    }

    // Calculate the trapped water
    for (int i = 0; i < n; i++) {
        int water_at_i = min(left_max[i], right_max[i]) - height[i];
        if (water_at_i > 0) {
            total_water += water_at_i;
        }
    }

    return total_water;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Total water trapped: " << trapRainWater(height) << endl;
    return 0;
}
