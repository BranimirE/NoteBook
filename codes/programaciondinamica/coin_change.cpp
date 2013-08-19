#define clr(a)  memset(a,0,sizeof(a))
using namespace std;
long long int dp[30001];
int money[]={1,5,10,25,50};
void coinchange(int sum){
	clr(dp);
	dp[0]=1;
	for(int i=0;i<5;i++){
		for(int j=money[i];j<=sum;j++){
			dp[j]+=dp[j-money[i]];
		}
	}
}
