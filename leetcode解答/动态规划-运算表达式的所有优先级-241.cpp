int execute(int op1,int op2,char opr){
    if(opr=='+') return op1+op2;
    else if(opr=='-') return op1-op2;
    else return op1*op2;
}

vector<int> diffWaysToCompute(string input) {
    vector<int> operands{};
    vector<char> operators{};
    for(auto i=0;i<input.size();){
        if(input[i]>='0' and input[i]<='9'){
            size_t j {};
            operands.push_back(std::stod(input.substr(i), &j));  // Push rhs operand
            i += j;
        }
        else{
            operators.push_back(input[i]);
            i++;
        }
    }
    vector<vector<vector<int>>> DP(operands.size(),vector<vector<int>>(operands.size(),vector<int>()));
    for(int i=0;i<operands.size();i++){
        DP[i][i].push_back(operands[i]);
    }
    
    for(int dis=1;dis<operands.size();dis++){
        for(int i=0;i+dis<operands.size();i++){//i->i+dis 分割点 i i+1 .... i+dis-1 i+dis
            for(int sp=i+1;sp<=i+dis;sp++){ // sp表示分割点 sp=i+k 表示 i..i+k-1 i+k..i+dis
                for(auto it1=DP[i][sp-1].begin();it1!=DP[i][sp-1].end();it1++){
                    for(auto it2=DP[sp][i+dis].begin();it2!=DP[sp][i+dis].end();it2++){
                        DP[i][i+dis].push_back(execute(*it1, *it2, operators[sp-1]));
                    }
                }
            }
        }
    }
    
    return DP[0][operands.size()-1];
}
