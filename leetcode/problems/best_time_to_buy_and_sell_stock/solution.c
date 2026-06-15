
#define MAX(a,b) ( a > b ) ? a : b 
int maxProfit(int* prices, int pricesSize) {
     int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < pricesSize; i++) {
            maxCur += prices[i] - prices[i-1];
            maxCur = MAX(0, maxCur);
            maxSoFar = MAX(maxCur, maxSoFar);
            
        }
    return maxSoFar;
}
