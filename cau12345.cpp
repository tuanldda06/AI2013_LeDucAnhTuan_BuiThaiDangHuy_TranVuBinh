#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
vector<int> sang(int n) {
    vector<bool> nto(n + 1, true);
    nto[0] = nto[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (nto[p]) {
            for (int i = p * p; i <= n; i += p)
                nto[i] = false;
        }
    }
    vector<int> snt;
    for (int p = 2; p <= n; p++) {
        if (nto[p]) {
            snt.push_back(p);
        }
    }
    return snt;
}
bool ngto(long long n)
{
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++)
       {
           if(n%i==0)return false;
       }
    return true;
}
int main(){

   long long n,dem=0,a[10001],limit = 10000,m;
   cin>>n;
   cin>>m;
   for(int i=0;i<=n;i++)
   {
        if((i*i+2*i)%15==0) {dem++;a[dem]=i;}
   }
   //câu1
   cout<<n+1-dem<<endl;
   //câu2
   cout<<a[dem-99]<<endl;
   //câu 3
   dem=0;
   for(int i=1;i<=m;i++)
    for(int j=i+1;j<=m;j++)
   {
       if(i*j==m&&ngto(i)&&ngto(j)) dem=1;
   }
   cout<<dem<<endl;
    vector<int> snt = sang(sqrt(limit));
    set<int> kqua;

    for (size_t i = 0; i < snt.size(); i++) {
        for (size_t j = i + 1; j < snt.size(); j++) {
            long long c = (long long)snt[i] * snt[j];
            if (c <= limit) {
                kqua.insert(c);
            }
        }
    }
    //câu 4
    cout << kqua.size() << endl;
    return 0;
}
