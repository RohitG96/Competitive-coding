/*
problem link: https://www.codechef.com/MARCH18B/problems/XXOR/
You are given a sequence A1, A2, ..., AN and Q queries. In each query, you are given two parameters L and R; you have to find the smallest integer X such that 0 ≤ X < 231 and the value of (AL xor X) + (AL+1 xor X) + ... + (AR xor X) is maximum possible.

Note: xor denotes the bitwise xor operation.

Input
The first line of the input contains two space-separated integers N and Q denoting the number of elements in A and the number of queries respectively.
The second line contains N space-separated integers A1, A2, ..., AN.
Each of the next Q lines contains two space-separated integers L and R describing one query.
Output
For each query, print a single line containing one integer — the minimum value of X.

Constraints
1 ≤ N ≤ 105
1 ≤ Q ≤ 105
0 ≤ Ai < 231 for each valid i
Subtasks
Subtask #1 (18 points):

1 ≤ N ≤ 103
1 ≤ Q ≤ 103
0 ≤ Ai < 210 for each valid i
Subtask #2 (82 points): original constraints

Example
Input:

5 3
20 11 18 2 13
1 3
3 5
2 4

Output:

2147483629
2147483645
2147483645
*/
#include<stdio.h>
int a[32][100000];
int main(){
	int n,q,l,r,x,c,i,j,s;
	scanf("%d%d",&n,&q);
	int b[32];
	b[0]=1;
	for(i=1;i<31;i++)
		b[i]=2*b[i-1];
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		j=0;
		while(x!=0)
		{
			a[j++][i+1]=x%2;
			x=x/2;
		}
	}
	for(i=0;i<31;i++)
	{
		for(j=1;j<=n;j++)
			a[i][j]+=a[i][j-1];
	}
	
	for(i=0;i<q;i++)
	{
		scanf("%d%d",&l,&r);
		s=r-l+1;
		l--;
		x=0;
		for(j=0;j<31;j++)
		{
			c=a[j][r]-a[j][l];
			if(c<s-c)
				x+=b[j];
		}
		printf("%d\n",x);
	}
} 