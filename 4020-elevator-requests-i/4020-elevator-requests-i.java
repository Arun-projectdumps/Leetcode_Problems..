class Solution {
    public int elevatorRequests(int n, int[] requests) {
        int current = 0 ;
        int ans = 0 ;
        for(int x : requests){
            ans += Math.abs(current - x);
            current = x;
        }
        return ans;
    }
}