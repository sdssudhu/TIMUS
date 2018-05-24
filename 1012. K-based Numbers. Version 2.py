n=(int)(input())
k=(int)(input())
dp = []
dp2= []
dp.append(k-1);
dp2.append(0);

for i in range (1,n):
	dp.append((k-1)*(dp[i-1]+dp2[i-1]))
	dp2.append(dp[i-1])
ans=dp[n-1]+dp2[n-1]
print(ans)