#include <bits/stdc++.h>

using namespace std;


void Extended(long long a, long long b, long long &k1, long long &k2)
{
    if (b==0){
        k1 = 1;
        k2 = 0;
        return;
    }
    long long x1, y1;
    Extended(b, a%b, x1, y1);

    k1 = y1;
    k2 = x1-(y1*(a/b));
}

void minComb(long long int &k1, long long int &k2, long long int res1, long long int res2, long long int vx, long long int vy, long long int fact){

    k1*=vx;
    k2*=-vy;
    while(k1*vx*(fact/abs(fact))<0 || k2*vy*(fact/abs(fact))<0){
        k1+=vx*(fact/abs(fact))*res1;
        k2+=vy*(fact/abs(fact))*res2;
    }
    k1*=fact;
    k2*=fact;

    long long int mini=min(abs(k1)/res1, abs(k2)/res2);
    k1+=mini*(-vx)*res1;
    k2+=mini*(-vy)*res2;
}

int main(void){

    long long n, m, x, y, vx, vy;
    cin >> n >> m >> x >> y >> vx >> vy;
    if(vy==0){
        if(y==0){
            if(vx>0) cout << n << " " << 0 << "\n";
            else cout << 0 << " "  << 0 << "\n";
        }
        else{
            if(y==m){
                if(vx>0) cout << n << " " << m << "\n";
                else cout << 0 << " "  << m << "\n";
            }
            else cout << -1 << "\n";
        }
    }
    else{
        if(vx==0){
            if(x==0){
                if(vy>0) cout << 0 << " " << m << "\n";
                else cout << 0 << " "  <<  0 << "\n";
            }
            else{
                if(x==n){
                    if(vy>0) cout << n << " " << m << "\n";
                    else cout << n << " "  <<  0 << "\n";
                }
                else cout << -1 << "\n";
            }
        }
        else{
            if(vx>0) vx=1;
            else vx=-1;
            if(vy>0) vy=1;
            else vy=-1;
            int mcd=__gcd(n,m);

            if((vx*x-vy*y)%mcd!=0) cout << -1 << "\n";
            else{
                long long int aux=vx*x-vy*y;
                long long int k1, k2;
                Extended(n, m, k1, k2);
                if(aux==0){
                    if(vx<0 && vy<0){
                        k1=0;
                        k2=0;
                    }
                    else{
                        k1=m/mcd;
                        k2=n/mcd;
                    }
                }
                else{
                    long long int res1=m/mcd, res2=n/mcd;
                    minComb(k1, k2, res1, res2, vx, vy, aux/mcd);

                }
                int ansx, ansy;
                if(k1&1) ansx=n;
                else ansx=0;
                if(k2&1) ansy=m;
                else ansy=0;
                cout << ansx << " "  << ansy << "\n";

            }
        }
    }


    return 0;
}
