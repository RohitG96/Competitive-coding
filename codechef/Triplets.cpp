/*
problem link:https://www.codechef.com/JUNE17/problems/SUMQ/
Given a triplet of integers (X , Y , Z), such that X ≤ Y and Y ≥ Z, we define f(X , Y , Z) to be (X + Y) * (Y + Z). If either X > Y or Y < Z, or both, then f(X , Y , Z) is defined to be 0.

You are provided three arrays A , B and C of any length (their lengths may or may not be equal).

Your task is to find the sum of f(X , Y , Z) over all triplets (X, Y , Z) where X, Y and Z belong to A, B and C respectively.

Output your sum for each test case modulo 1000000007.

Input
The first line contains a single integer, T, which is the number of test cases. The description of each testcase follows:
The first line of each testcase contains 3 integers: p, q and r. These denote the lengths of A,B and C respectively.
The second line contains p integers, which are the elements of A
The third line contains q integers, which are the elements of B
The fourth line contains r integers, which are the elements of C
Output
Output the required sum modulo 1000000007 for each test case in a new line.

Constraints
1 ≤ T ≤ 10
1 ≤ p, q, r ≤ 100000
1 ≤ every array element ≤ 1000000000
Subtasks
Subtask #1 (30 points): 1 ≤ p,q,r ≤ 100
Subtask #2 (70 points): 1 ≤ p,q,r ≤ 100000
Example :
Input:
1 
3 1 3
1 2 3
5
4 5 6

Output:
399
Explanation:
As there is only one choice for Y which equals to 5, to get a non-zero function value,we can choose any element for X from the set { 1 , 2 , 3 } and for Z from the set { 4 , 5 }

So triplets which give non-zero function values are:

{ 1 , 5 , 4 } : ( 1 + 5 ) * ( 5 + 4 ) = 54

{ 1 , 5 , 5 } : ( 1 + 5 ) * ( 5 + 5 ) = 60

{ 2 , 5 , 4 } : ( 2 + 5 ) * ( 5 + 4 ) = 63

{ 2 , 5 , 5 } : ( 2 + 5 ) * ( 5 + 5 ) = 70

{ 3 , 5 , 4 } : ( 3 + 5 ) * ( 5 + 4 ) = 72

{ 3 , 5 , 5 } : ( 3 + 5 ) * ( 5 + 5 ) = 80

Final answer : 54 + 60 + 63 + 70 + 72 + 80 = 399
*/
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int mod=1000000007;
	int i,j,k,p,q,r,t;
	long long int ans,g,h,x[100002],y[100002],z[100002],xs[100002],zs[100002];
	xs[0]=zs[0]=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&p,&q,&r);
		for(i=0;i<p;i++)
			scanf("%lld",&x[i]);
		for(i=0;i<q;i++)
			scanf("%lld",&y[i]);
		for(i=0;i<r;i++)
			scanf("%lld",&z[i]);
		sort(x,x+p);
		sort(y,y+q);
		sort(z,z+r);
		for(i=1;i<=p;i++)
			xs[i]=(xs[i-1]+x[i-1])%mod;
		for(i=1;i<=r;i++)
			zs[i]=(zs[i-1]+z[i-1])%mod;
		ans=g=h=0;j=0;k=0;
		for(i=0;i<q;i++)
		{
			if(j<p)
				while(y[i]>=x[j]&&j<p)
					j++;
				if(k<r)
					while(y[i]>=z[k]&&k<r)
						k++;
					g=(j*y[i]%mod+xs[j])%mod;
					h=(k*y[i]%mod+zs[k])%mod;
					ans=(ans + (g*h)%mod)%mod;	
				}
				printf("%lld\n",ans);	
			}
			
		}