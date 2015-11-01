class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(str.length() == 0 && pattern.length () == 0) return true;
        if(str.length() == 0 && pattern.length () != 0) return false;
        if(str.length() != 0 && pattern.length () == 0) return false;
        int ptr1 = 0, ptr2 = 0;
        map<char, string> patt;
        map<string, char> rev;
        while(ptr1 < pattern.length()){
            char pattmp = pattern[ptr1];
            string strtmp = "";
            while(str[ptr2] != ' '){
                strtmp += str[ptr2++];
                if(ptr2 >= str.length()) break;
            }
            if(patt.find(pattmp) == patt.end() && rev.find(strtmp) == rev.end()){
                patt[pattmp] = strtmp;
                rev[strtmp] = pattmp;
            }else if(patt.find(pattmp) != patt.end() && rev.find(strtmp) != rev.end()){
                if(!(patt[pattmp] == strtmp && rev[strtmp] == pattmp)){
                    return false;
                }
            }else{
                return false;
            }
            ptr2++;
            ptr1++;
            if(ptr2 >= str.length() && ptr1 >= pattern.length()) break;
            if((ptr2 >= str.length() && ptr1 < pattern.length()) || (ptr2 < str.length() && ptr1 >= pattern.length())) return false;
        }
        return true;
    }
};
