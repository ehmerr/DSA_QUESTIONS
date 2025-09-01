#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
    double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
        // A max priority queue to store {profit, {pass, total}}
        // 'profit' is the increase in pass ratio if one student is added.
        std::priority_queue<std::pair<double, std::pair<int, int>>> pq;

        // 1. Calculate initial profit for each class and populate the priority queue.
        for (const auto& c : classes) {
            int pass = c[0];
            int total = c[1];
            double profit = calculate_profit(pass, total);
            pq.push({profit, {pass, total}});
        }

        // 2. Greedily assign extra students.
        for (int i = 0; i < extraStudents; ++i) {
            // Get the class with the highest potential profit.
            std::pair<double, std::pair<int, int>> top = pq.top();
            pq.pop();

            // Update the class by adding one brilliant student.
            int pass = top.second.first + 1;
            int total = top.second.second + 1;

            // Recalculate the profit for the updated class and push it back.
            double new_profit = calculate_profit(pass, total);
            pq.push({new_profit, {pass, total}});
        }

        // 3. Calculate the sum of final pass ratios.
        double total_ratio_sum = 0.0;
        while (!pq.empty()) {
            std::pair<int, int> c = pq.top().second;
            pq.pop();
            total_ratio_sum += static_cast<double>(c.first) / c.second;
        }

        // Return the average.
        return total_ratio_sum / classes.size();
    }

private:
    // Helper function to calculate the increase in pass ratio.
    // Profit = (new_ratio) - (old_ratio) = (pass + 1)/(total + 1) - pass/total
    double calculate_profit(int pass, int total) {
        // No profit if the class is already at 100%
        if (pass == total) {
            return 0.0;
        }
        return static_cast<double>(total - pass) / (static_cast<double>(total) * (total + 1));
    }
};