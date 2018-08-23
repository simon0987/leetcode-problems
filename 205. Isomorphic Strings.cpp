/*
解題思路: 一個字符對應一個字符，所以可以想到用map去對應。那a>b 也要讓b>a回來，不然有個情況 ex: ab aa 
這樣要回傳false 但如果沒有兩邊對應 只讓a > a，b > a 不會return false 要對應回來才會發現是錯的。
所以用2個map 來裝字符，還沒加的加進去，加過的確認這個對應到的值就是目前在判斷的t[i]
*/
bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,char> s2t;
        unordered_map<char,char> t2s;
        
        for(int i = 0 ; i < s.size(); i++){
            if(s2t.find(s[i])==s2t.end())
                s2t.insert({s[i],t[i]});
            else{
                if(s2t[s[i]]!=t[i])
                    return false;
            }
            if(t2s.find(t[i])==t2s.end())
                t2s.insert({t[i],s[i]});
            else{
                if(t2s[t[i]]!=s[i])
                    return false;
            }
        }
        return true;
    }
