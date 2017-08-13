#include <cstdio>
#include <iostream>
#define P 1000000007
using namespace std;
int T;
long long n,m; 
struct Matrix{
	long long v[2][2];
	void init(int a,int b,int c,int d){
		v[0][0]=a,v[0][1]=b,v[1][0]=c,v[1][1]=d;
	}
    Matrix operator *(Matrix &tmp){
    	Matrix res;
    	res.init(0,0,0,0);
    	for(int i=0;i<2;++i)
    	    for(int j=0;j<2;++j)
    	        for(int k=0;k<2;++k){
    	        	res.v[i][j]+=v[i][k]*tmp.v[k][j];
    	        	res.v[i][j]%=P;
    	        }
    	return res;
    }
    Matrix operator -(Matrix &tmp){
    	Matrix res;
    	for(int i=0;i<2;++i)
    	    for(int j=0;j<2;++j){
    	    	res.v[i][j]=v[i][j]-tmp.v[i][j]+P;
    	    	res.v[i][j]%=P;
    	    }
    	return res;
    }
};
Matrix pow(Matrix x,long long y){
	Matrix res;
	res.init(1,0,0,1);
	for(;y;y>>=1,x=x*x)
	    if(y&1)res=res*x;
	return res;
}
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>n>>m;
	    Matrix A,B,C;
	    A.init(0,2,1,1);
	    if(n&1)B.init(-1,2,1,0);
	    else B.init(1,0,0,1);
	    C=pow(pow(A,n)-B,m-1);
	    cout<<(C.v[0][0]+C.v[1][0])%P<<endl;
    }
}
