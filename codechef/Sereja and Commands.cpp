/*
problem link: https://www.codechef.com/SEPT17/problems/SEACO/

Sereja has an array A consisting of n integers. Initially, all the elements of array are zero.

Sereja writes down m commands on a piece of a paper. The commands are enumerated from 1 to m. These commands can be of the following two types of commands:

l r (1 ≤ l ≤ r ≤ n) — Increase all elements of the array by one, whose indices belongs to the range [l, r]
l r (1 ≤ l ≤ r ≤ m) — Execute all the commands whose indices are in the range [l, r]. It's guaranteed that r is strictly less than the enumeration/number of the current command.
Can you please help Sereja in executing all the commands written on this piece of paper.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line contains integers n and m. Next m lines contain Sereja's commands in the format, described in statement: t, l, r, where t - number of type (1 or 2).

Output
For each test case on different lines print an array a, after executing all the commands. The numbers have to be separated by spaces. As the numbers can be quite large, print them modulo 109 + 7.

Constraints
1 ≤ T ≤ 3
1 ≤ n, m ≤ 105
Subtasks
Subtask #1 (20 points): 1 ≤ n, m ≤ 10
Subtask #2 (30 points): 1 ≤ n, m ≤ 1000
Subtask #3 (50 points): original constraints
Example
Input:
3
5 5
1 1 2
1 4 5
2 1 2
2 1 3
2 3 4
1 2
1 1 1
1 1 1
10 10
1 1 10
2 1 1
2 1 2
2 1 3
2 1 4
2 1 5
2 1 6
2 1 7
2 1 8
2 1 9

Output:
7 7 0 7 7
2
512 512 512 512 512 512 512 512 512 512
Explanation:
Example case 1..

After the first command, the resulting array is [1 1 0 0 0], after second [1 1 0 1 1].

On third command, we repeat the 1'st and the 2'nd command, so that resulting array is [2 2 0 2 2].

After fourth command, the array will looks like [4 4 0 4 4].

Last command will apply 3'rd and 4'th commands, which by themselves will apply 1'st, 2'nd, 1'st, 2'nd, 3'rd(1'st, 2'nd), so resulting arrays is [7 7 0 7 7].
*/
#include<stdio.h>
long long int mod=1e9+7;
typedef struct com{
	int ty,li,ri;
}co;
long long int a[100006],p[100006];
co b[100006];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int l=1,i,n,m,in=0,sum;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&(b[i].ty),&(b[i].li),&(b[i].ri));
		p[i]=0;
	}
	for(i=1;i<=n;i++)
	a[i]=0;
	sum=0;
	p[m+1]=0;
	for(i=m;i>=1;i--)
	{
		sum=(sum+p[i+1]+mod)%mod;
		if(b[i].ty==1)
		{
			a[b[i].li]=(a[b[i].li]+p[i]+sum+1+mod)%mod;
			a[b[i].ri+1]=(a[b[i].ri+1]-sum-p[i]-1+mod)%mod;
		}
		else
		{
			p[b[i].li-1]=(p[b[i].li-1]-p[i]-1-sum+mod)%mod;
			p[b[i].ri]=(p[b[i].ri]+p[i]+1+sum+mod)%mod;
		}
	}
	for(i=1;i<=n;i++)
	{
	a[i]=(a[i]+a[i-1]+mod)%mod;
	printf("%lld ",a[i]);}
	printf("\n");
	}
}