class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        vector<pair<int, int>> st;
        st.reserve(n);

        for(int i=0; i<n; i++){
            int startIdx = i;
            while(!st.empty() && st.back().second > heights[i]){
                auto [idx, height] = st.back();
                st.pop_back();

                maxArea = max(maxArea, height*(i-idx));
                startIdx = idx;
            }
            st.emplace_back(startIdx, heights[i]);
        }
        for(const auto& [idx, height] : st){
            maxArea = max(maxArea, height*(n-idx));
        }
        return maxArea;
    }
};
