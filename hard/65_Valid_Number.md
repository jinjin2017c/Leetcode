```cpp
//主要思路是讲该数字做两部分考虑
//关键点在于匹配到最后的关键点，任何异常的停止不需要额外的return false

bool isNumber(string s)
{
    int i = 0;
    //skip the whilespaces
    for (;, s[i] == ' '; ++i){}
    
    //check the significand
    if(s[i] == '+' || s[i] == '-') ++i;  //skip the sign if exist
    
    int n_nm, n_pt;   //n_nm 记录数字个数， n_pt记录点的个数
    for(n_nm=0,n_pt=0; (s[i]<='9' && s[i] >= '0') || s[i] == '.'; ++i){
        s[i] == '.' ? n_pt++:n_nm++;   
    }
    
    //no more than one point, at least on digit 
    //if a letter is appear first, false
    //if not, stop at the first letter
    if(n_pt>1) || n_nm<1) {
        return false;
    }
    
    
    //check the exponent if exist
    if(s[i] == 'e'){
        ++i;
        if(s[i] == '+' || s[i] == '-'){
            ++i;   //skip the sign
        }
        
        int n_nm = 0;    //指数为小数不被允许
        for(;s[i]>='0' && s[i] <= '9'; ++i, ++n_nm) {}
        if(n_nm < 1) return false;
    }
    
    //skip the trailing whitespaces
    for(;s[i] == ' '; ++i) {}
    
    return i == s.size();     
}
```
