 int lastRemaining(int n) {

        // Math problem: first observe the pattern and then find the fixed road

        // 1. if we don't have to eliminate the number from start and the remaining numbers are even then
        // the answer is same,

        // 2. with each eliminaltion the the distance between two indexes becomes twice.

        // 3. and the size becomes of the previous at each stage

       if(n==1)
        return 1;
        int ord =1;
        int ans=1;
        int remain =n;
        bool left =0;
        while(remain>1){
            if(left==0 || remain%2 ==1 ){
                ans = ans + ord;
                }

                ord = ord*2;
                remain= remain/2;
                left = !left;
        }
        return ans;
    
        
    }
