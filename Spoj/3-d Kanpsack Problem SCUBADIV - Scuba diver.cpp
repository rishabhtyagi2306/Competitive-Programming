//https://www.spoj.com/problems/SCUBADIV/



#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll              long long
#define vii             vector<int>
#define vll             vector<ll>
#define mii             map<int, int>
#define mll             map<ll, ll>
#define si              set<int> 
#define sl              set<ll>
#define umi             unordered_map<int, int>
#define uml             unordered_map<ll, ll>
#define usi             unordered_set<int>
#define usl             unordered_set<ll>
#define maxpq           priority_queue<int>
#define minpq           priority_queue<int,vii,greater<int>()>
#define pii             pair<int, int>
#define pll             pair<ll, ll> 
#define pb              push_back
#define pf              push_front
#define mp              make_pair
#define endl            "\n"
#define desc            greater<int>()
#define F               first
#define S               second
#define mod             1000000007
#define pi              3.141592653589793238
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
using namespace __gnu_pbds;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, 
             tree_order_statistics_node_update> PBDS;



const int INF_WEIGHT = 100000000;
int main() {
    FASTIO
	int t;  // Nb of test cases
	int oxygenRequired, nitrogenRequired;
	int oxygen[1000];
	int nitrogen[1000];
	int weight[1000];
	int dp[1000][22][80];
	int nbCylinders;
    cin>>t;
    while(t--)
    {
		cin >> oxygenRequired >> nitrogenRequired >> nbCylinders;
		for (int i = 0; i < nbCylinders; i++)
			cin >> oxygen[i] >> nitrogen[i] >> weight[i];

		// Dynamic Programming
		for (int i = 0; i < nbCylinders; i++)
			for (int j = 0; j <= oxygenRequired; j++)
				for (int k = 0; k <= nitrogenRequired; k++) {
					dp[i][j][k] = INF_WEIGHT;
						if (j == 0 && k == 0)
							dp[i][j][k] = 0;
				}

		for (int j = 0; j <= oxygenRequired; j++)
			for (int k = 0; k <= nitrogenRequired; k++)
				if (j <= oxygen[0] && k <= nitrogen[0] && (j > 0 || k > 0)) {
					dp[0][j][k] = weight[0];
			}

		for (int i = 1; i < nbCylinders; i++)
			for (int j = 0; j <= oxygenRequired; j++)
				for (int k = 0; k <= nitrogenRequired; k++) {
					dp[i][j][k] = dp[i-1][j][k];
					if (j <= oxygen[i] && k <= nitrogen[i])
						dp[i][j][k] = min(dp[i][j][k], weight[i]);
					else
						dp[i][j][k] = min(dp[i][j][k], weight[i] + dp[i-1][max(0,j-oxygen[i])][max(0,k-nitrogen[i])]);
				}

		cout << dp[nbCylinders-1][oxygenRequired][nitrogenRequired] << "\n";
    }
    return 0; 
}
