#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    int frame,req,i,j,k,hit=0;
    cout << "Numero de frames: "; cin >> frame;
    cout << "Numero de requerimientos: "; cin >> req;
    vector<char> p(req);
    vector<char> hi(req);
    cout << "Ingresar requerimientos: ";

    for(i=0; i<req; i++){
        cin>>p[i];
    }    
    vector<vector<char>> a(frame);
    for(i=0; i<frame; i++){
        a[i]=vector<char>(req,-1);
    }
    map <char, char> mp;    
    for(i=0; i<req; i++){
        vector<pair<char,char>> c;
        for(auto q:mp){
            c.push_back({q.second,q.first});
        }
        sort(c.begin(),c.end());
        bool hasrun=false;
        for(j=0; j<frame; j++){
            if(a[j][i] == p[i]){
                hit++;
                hi[i]=1;
                mp[p[i]]=1;
                hasrun=true;
                break;
            }
            if(a[j][i]==-1){
                for(k=i;k<req;k++)
                    a[j][k]=p[i];
                mp[p[i]]++;
                hasrun=true;
                break;
            }
        }
        if(j==frame || hasrun==false){
            for(j=0; j<frame; j++){
                if(a[j][i] == c[c.size()-1].second){
                    mp.erase(a[j][i]);
                    for(k=i; k<req; k++)
                        a[j][k]=p[i];
                    mp[p[i]]++;
                    break;
                }
            }
        }
        for(auto q:mp){
            if(q.first!=p[i]){
                mp[q.first]++;
            }
        }
    }
    cout << "Procedimiento ";
    for(i=0; i<req; i++){
        cout << p[i] << " ";
    }
    cout << '\n';
    for(i=0; i<frame; i++){
        cout << "Frame " << i+1 << " ";
        for(j=0; j<req; j++){
            if(a[i][j] == -1)
                cout << "- ";
            else 
                cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    for(i=0; i<req; i++){
        if(hi[i] == 0) cout << "  ";
        else cout << hi[i] << " ";
    }
    cout << "\n";
    cout << "Hits= " << hit << '\n' << "Page Fault= " << req-hit << '\n';
    return 0;
}//A B D D E A E C A B C A E