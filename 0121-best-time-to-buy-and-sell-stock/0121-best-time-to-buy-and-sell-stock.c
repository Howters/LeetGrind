int maxProfit(int* prices, int pricesSize){
    int profit=0,min = prices[0];
    for(int i=0;i<pricesSize;i++){  
       if(prices[i]>min){
           if(profit < prices[i]-min){
               profit = prices[i]-min;
           }
           else{
               profit=profit;
           }

       }
       else{
           min = prices[i];
       }
    }
    return profit;
}