class Solution {
public:
    string minWindow(string s, string t) {
        if(s==t) return s;
        if(s.size()<t.size()) return "";
        int arr1[256]={0};
        int arr2[256]={0};
        for(int i=0;i<t.size();i++){
            arr2[t[i]]++;
        }
        int i=0,j=0,mini=INT_MAX,st=-1,e=-1,n=s.size(),m=t.size();
        int count=0;
        while(j<n){
            arr1[s[j]]++;
            if(arr2[s[j]]!=0 && arr1[s[j]]<=arr2[s[j]]) count++;
            while(i<=j && count==m){
                    if(mini>(j-i+1)){
                    mini=(j-i+1);
                    st=i;
                    e=j;
                    }
                    arr1[s[i]]--;
                    if(arr2[s[i]]!=0 && arr1[s[i]]<arr2[s[i]]) count--;
                    i++;
            }
            if(mini==m) break;
            j++;
        }
        string ans="";
        if(st!=-1)
        for(int i=st;i<=e;i++) ans+=s[i];
        return ans;
    }
};
