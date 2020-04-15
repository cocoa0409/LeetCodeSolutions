class Solution {
public:

int jump(vector<int>& nums) {
    int totalLength=nums.size();
    if(totalLength<=1) return 0;
    int step=0;
    int prefin=-1,thisfin=0;
    int maxloc=0;
    while (1) {
        step++;
        for(int i=prefin+1;i<=thisfin; i++){
            maxloc=max(maxloc,i+nums[i]);
            if(maxloc>=totalLength-1)
                return step;
        }
        prefin=thisfin;
        thisfin=maxloc;
    }
}
};
