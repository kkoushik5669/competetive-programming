int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<N;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<=N;k++)
				dp[i][j][k] = INF;
	if(A[0] == 0)
		dp[0][0][1] = 0;
	else
		dp[0][0][1] = 1;
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<=i;j++)
			for(int k=1;k<=i+1;k++)
			{
        //extending the last segment.
				if(j < i) 
					dp[i][j][k] = dp[i-1][j][k];
				else
					for(int j1=0;j1<i;j1++)
						dp[i][j][k] = min(dp[i][j][k], dp[i-1][j1][k-1]);
        //putting a new door in the current index.
				if(A[i] != i-j) 
					dp[i][j][k]++;
			}
	}
	for(int k=1;k<=N;k++)
	{
		int low = INF;
		for(int j=0;j<N;j++)
			low = min(low, dp[N-1][j][k]);
		cout << low << '\n';
	}
}
