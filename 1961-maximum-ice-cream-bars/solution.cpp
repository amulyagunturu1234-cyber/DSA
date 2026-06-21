class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Find the maximum cost to size our counting array
        int maxCost = *max_element(costs.begin(), costs.end());
        
        // Counting sort: count[i] = number of ice creams with price i
        vector<int> count(maxCost + 1, 0);
        for (int cost : costs) {
            count[cost]++;
        }
        
        int bars = 0;
        // Go through prices from cheapest to most expensive
        for (int price = 1; price <= maxCost; price++) {
            if (count[price] == 0) continue;
            
            // Buy as many as possible at this price
            int canBuy = min(count[price], coins / price);
            bars += canBuy;
            coins -= canBuy * price;
            
            if (coins == 0) break;
        }
        
        return bars;
    }
};
