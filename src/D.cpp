#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define log1(a) for(auto x:a)cout << x <<" ";cout <<endl;
#define log2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<a[i][j]<<" ";cout << endl;}
#define file_io freopen("process/input.txt", "r", stdin); freopen("process/output.txt", "w", stdout); freopen("process/err.log", "w", stderr);

using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int test_case() {
	int n, a, b; cin >> n >> a >> b;
	string s; cin >> s;
	
	// default common (horizontals for road and unity height for pillars):
	int ans = n*a + (n+1)*b;
	
	// left end:
	int firstOne = n;
	for(int i=0; i<n; i++) {
		if(s[i] == '1') {
			firstOne = i;
			break;
		}
	}
	if(firstOne != n) {
		int opt1 = 0*a + firstOne*b;
		int opt2 = 1*a + 0*b;
		ans += min(opt1, opt2);
	}
	
	// middle section:
	int z = 0;
	for(int i=firstOne; i<n; i++) {
		if(s[i] == '0') z++;
		else {
			ans += (1*b);
			if(z >= 1) {
				ans += (1*b);
				if(z >= 2) {
					int opt1 = 0*a + (z-1)*b;
					int opt2 = 2*a + 0*b;
					ans += min(opt1, opt2);
				}
				z = 0;
			}
			
		}
	}
	
	// right end:
	if(firstOne != n) {
		ans += (1*b);
	
		int opt1 = 0*a + z*b;
		int opt2 = 1*a + 0*b;
		ans += min(opt1, opt2);
	}
	
	return ans;
}

int32_t main()
{
    file_io
	fastio
	
	int T; cin >> T;
	for(int t=1; t<=T; t++)
	{
		cout << test_case() << "\n";
	}
	
	return 0;
}