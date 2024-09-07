#include<bits/stdc++.h>
using namespace std;


    stack<pair<int,int>> stock; 

    StockSpanner() {}
    
    int next(int price) {

        // Note :- yaha pe monotonic aise istemaal kiya gaya hai : jo minimum hain unhe hata do unka sirf span kaam karega but jo bigger hai unko rakho may be unse bada number aage.

        int  stockSpan = 1;

        while(!stock.empty() && stock.top().first <= price){
            stockSpan += (stock.top().second);
            stock.pop();
        }
        
        stock.push({price,stockSpan});
        return stockSpan;
    }

    // T.C : O(N)
    // S.C : O(N)

int main(){

}
