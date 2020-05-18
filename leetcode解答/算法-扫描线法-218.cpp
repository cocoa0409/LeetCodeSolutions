class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> h;
        multiset<int> m;
        vector<vector<int>> res;

        //1、将每一个建筑分成“两个部分”，例如:[2,9,10]可以转换成[2，-10][9,10]，我们用负值来表示左边界
        for(const auto& b:buildings)
        {
            h.push_back({b[0], -b[2]});
            h.push_back({b[1], b[2]});
        }

        //2、根据x值对分段进行排序
        sort(h.begin(),h.end());
        int prev = 0, cur = 0;
        m.insert(0);

        //3、遍历
        for (auto i:h)
        {
            if (i.second < 0) m.insert(-i.second);  //左端点，高度入堆
            else m.erase(m.find(i.second));         //右端点，高度出堆
            cur = *m.rbegin();                      //当前最大高度高度
            if (cur != prev) {                      //当前最大高度不等于最大高度perv表示这是一个转折点
                res.push_back({i.first, cur});      //添加坐标
                prev = cur;                         //更新最大高度
            }
        }
        return res;
    }
};


/*
 =================================================================================
 */

class EventPoint{
public:
    int _x;
    vector<int> _IN;//在此时间点加入扫描线的点
    vector<int> _OUT;//在此时间点退出扫描线的点
    
    EventPoint(int x):_x(x){}
    ~EventPoint(){}
    
    void AddIN(int in){_IN.push_back(in);}
    void AddOUT(int out){_OUT.push_back(out);}
};


bool Comp(shared_ptr<EventPoint> i,shared_ptr<EventPoint> j){
    return (i->_x < j->_x);
}

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    unordered_map<int, shared_ptr<EventPoint>> map;
    vector<shared_ptr<EventPoint>> Q;
    for(auto it=buildings.begin();it!=buildings.end();it++){//加入起点事件
        if(map.count((*it)[0])==0){//如果事件点没有加入Q
            auto pt=make_shared<EventPoint>((*it)[0]);
            map[(*it)[0]]=pt;
            pt->AddIN((*it)[2]);
            Q.push_back(pt);
        }
        else{//如果事件点已经加入Q了
            map[(*it)[0]]->AddIN((*it)[2]);
        }
        
        if(map.count((*it)[1])==0){//如果事件点没有加入Q
            auto pt=make_shared<EventPoint>((*it)[1]);
            map[(*it)[1]]=pt;
            pt->AddOUT((*it)[2]);
            Q.push_back(pt);
        }
        else{//如果事件点已经加入Q了
            map[(*it)[1]]->AddOUT((*it)[2]);
        }
    }
    //需要将事件点排序
    
    
    sort(Q.begin(), Q.end(), Comp);
    
    
    //事件点已经按照Li排序
    vector<vector<int>> res;
    
    int preHeight = -1;
    int Height ;
    vector<int> ScanLine;
    ScanLine.push_back(0);
    
    //事件点加入
    for(auto it=Q.begin();it!=Q.end();it++){
        for(auto itIN=(*it)->_IN.begin();itIN!=(*it)->_IN.end();itIN++){//加入一些事件
            ScanLine.push_back(*itIN);
        }
        for(auto itOUT=(*it)->_OUT.begin();itOUT!=(*it)->_OUT.end();itOUT++){//结束一些事件
            auto isSL=find(ScanLine.begin(), ScanLine.end(), *itOUT);
            ScanLine.erase(isSL);
        }
        Height= * max_element(ScanLine.begin(), ScanLine.end());
        if(Height==preHeight)
            continue;
        else{
            preHeight=Height;
            vector<int> newNode;
            newNode.push_back((*it)->_x);
            newNode.push_back(Height);
            res.push_back(newNode);
        }
    }
    
    return res;
}
