int hIndex(vector<int>& citations) {
    vector<int> CountSort(citations.size()+1,0);
    for(const auto & cit:citations){
        CountSort[min(cit, (int)citations.size())]++;
    }
    int MaxCount=0;
    int i=citations.size();
    while(true){
        MaxCount+=CountSort[i];
        if(MaxCount>=i) return i;
        i--;
    }
    return 0;
}
