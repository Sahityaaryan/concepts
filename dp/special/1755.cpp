        #include<bits/stdc++.h>
        using namespace std;

        class Solution {
        public:
            set<long long> getSubsetSum(int l, int r, vector<int>& nums){
                set<long long> subseqSums;

                int elems = r-l;
                for(long long mask = 0;mask<(1<<elems);mask++){
                    long long sum = 0;
                    for(int i=l;i<r;i++){
                        if( (mask&(1ll<<(i-l))) >= 1){
                            sum += nums[i];
                        }
                    }

                    subseqSums.insert(sum);
                }

                return subseqSums;
            }
            int minAbsDifference(vector<int>& nums, int goal) {
                int n = nums.size();
                set<long long> firstHalfSums = getSubsetSum(0,n/2, nums);
                set<long long> secondHalfSums = getSubsetSum(n/2,n, nums);

                long long ans = LLONG_MAX;
                for(auto el:firstHalfSums){
                    long long diff = goal - el;
                    auto it = secondHalfSums.lower_bound(diff);
                    if(it!=secondHalfSums.end()){
                        ans = min(ans, abs(goal - (el + *it)));
                    }
                    if(it!=secondHalfSums.begin()){
                        it--;
                        ans = min(ans, abs(goal - (el + *it)));
                    }
                }

                return ans;
            }
        };

        int main(){

            return 0;
        }
