/** 
 *  Algorithm: Knuth-Morris-Pratt Substring search Algorithm
 *  Time-Complexity: O(m+n)     m: pattern size         n: string size     
 *  Resources: https://cp-algorithms.com/string/prefix-function.html
 *            https://www.coursera.org/lecture/algorithms-on-strings/prefix-function-exytr
 *            https://www.hackerearth.com/practice/notes/exact-string-matching-algorithms
**/

#include <iostream>
#include <string>
#include <vector>

#define watchitr(iterable) cout << (#iterable) << " => ";  for(auto itr=iterable.begin(); itr!=iterable.end(); itr++) cout << *itr << " "; cout << endl;

using namespace std;

vector<int> kmp(string s, string pat);
vector<int> create_lps(string pat);

int main(){
    string s, pat;
    cin >> s >> pat;
    vector<int> pos = kmp(s,pat);
    for(int x: pos)
        cout << x << endl;
}

vector<int> kmp(string s, string pat){
    vector<int> ans;
    vector<int> lps=create_lps(pat);

    int i=0; // index for lps position
    for (int j=0; j<s.size(); j++)
    {
        if(s[j]==pat[i])
        {
            if(i==pat.size()-1) // complete pattern match (pattern ENDS at index j)
            {
                ans.push_back(j-pat.size()+1); // start index of pattern
                i=lps[i]; // reset i to correct position for next search
            }
            else i++; // increment i for next match
        }
        else // pattern match breaks here
        {
            if(i==0) // can't reset i to any more position leftwards (see below )
                continue;
            j--; // don't increment current character
            i=lps[i-1]; // reset i to correct position for next search
        }
    }
    
    return ans;
}

vector<int> create_lps(string pat){
    vector<int> lps(pat.size(),0);
    int len=0; // length of matching prefix
    for (int j = 1; j < pat.size(); j++) // for substring pat[0...j]
    {
        if(pat[len]==pat[j]) // if this last char extends the previous prefix
        {   
            len++;
            lps[j]=len; // lps[j] stores max length suffix which is also prefix in pat[0..j]
        }
        else if(pat[len]!=pat[j] && len!=0){
            // check if current suffix == previous (smaller) prefix
            len=lps[len-1]; // NOTE: len goes to previous index of smaller prefix which is to be matched with pat[j] in next loop
            j--; // don't jump to next character (lps[j] not found yet)
        }
    }
    watchitr(lps);
    return lps;
}
