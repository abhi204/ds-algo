/** 
 *  Data-Structure: Suffix Array
 *  Time-complexity: O(n(logn)^2) [ OR O(nlogn) using Radix Sort Below]
 *  Resources :  https://www.hackerearth.com/practice/data-structures/advanced-data-structures/suffix-arrays/tutorial/
 *               https://cp-algorithms.com/string/suffix-array.html
**/
#include <bits/stdc++.h>

#define pause
#define watch(x) cout << (#x) << " => " << x << endl;
#define watcharr(arr,size) cout << (#arr) << " => ";  for(int zz=0; zz<size; zz++) cout << arr[zz] << " "; cout << endl;
#define watchitr(iterable) cout << (#iterable) << " => ";  for(auto itr=iterable.begin(); itr!=iterable.end(); itr++) cout << *itr << " "; cout << endl;

using namespace std;


// considering small alphabets a-z only
int alphabet_size=26;

void generate_SA(string s, string sa[]){
    int s_len=s.size(), i, temp;
    int p[s_len], rank[s_len];
    fill_n(rank, s_len, 0);

    // Sorting based on 1st letter of suffixes using count-sort
    // and, generating p and rank array
    int count[alphabet_size];
    fill_n(count, alphabet_size, 0);

    for (i = 0; i < s_len; i++)
        count[s[i]-'a']++;
    
    for(i=1; i<alphabet_size; i++)
        count[i]+=count[i-1];

    for(i=0; i<s_len; i++)
        p[--count[s[i]-'a']]=i;
    
    int rank_counter=0;
    rank[p[0]]=rank_counter;
    for(i=1; i<s_len; i++){
        if(s[p[i]] != s[p[i-1]])
            rank_counter++;
        rank[p[i]]=rank_counter;
    }


    for(int suf_len=1; suf_len<s_len; suf_len*=2){
        // create copy of p and rank
        int p_new[s_len], rank_new[s_len];
        for(i=0; i<s_len; i++){
            p_new[i]=p[i]-suf_len;
            if(p_new[i]<0)
                p_new[i]+=s_len;
        }

        fill_n(count, rank_counter+1, 0);
        // using 2nd half of the new (increased length) suffix for radix sort (stable sort)
        for(i=0; i<s_len; i++)
            count[rank[p_new[i]]]++;
        
        for(i=1; i<alphabet_size; i++)
            count[i]+=count[i-1];

        for(i=s_len-1; i>=0; i--)
            p[--count[rank[p_new[i]]]]=p_new[i];

        rank_counter=0;
        rank_new[p[0]]=rank_counter;
        for(i=1; i<s_len; i++){
            pair<int,int> cur = { rank[p[i]], rank[ (p[i]+suf_len) % s_len] };
            pair<int,int> prev = { rank[p[i-1]], rank[ (p[i-1]+suf_len) % s_len] };
            if(cur!=prev)
                rank_counter++;
            rank_new[p[i]]=rank_counter;
        }

        for(i=0; i<s_len; i++)
            rank[i]=rank_new[i];
    }

    // create suffix array
    for(int i=0; i<s_len; i++){
        string suff = s.substr(p[i],s_len-p[i]+1);
        sa[i]=suff;
    }
}

int main(){
    string txt = "banana"; // Sample Input text
    string suffix_array[txt.size()];
    generate_SA(txt, suffix_array);
    for(string suffix: suffix_array)
        cout << suffix << "\n";
    return 0;
}