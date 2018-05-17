/*
problem link: https://www.codechef.com/SEPT17/problems/FILLMTR/

A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.

You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.

Input
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains two space separated integers N, Q.

Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.

Output
For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.

Constraints
1 ≤ T ≤ 106
2 ≤ N ≤ 105
1 ≤ Q ≤ 106
1 ≤ i, j ≤ N
0 ≤ val ≤ 1
Sum of each of N, Q over all test cases doesn't exceed 106
Subtasks
Subtask #1 (40 points) 2 ≤ N ≤ 103, 1 ≤ Q ≤ 103, Sum of each of N, Q over all test cases doesn't exceed 104
Subtask #2 (60 points) Original Constraints
Example
Input
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1

Output
yes
no
yes
no
Explanation
Example 1. You can fill the entries of matrix B as follows.

0 1
1 0
This matrix corresponds to the array A = [1, 2].
Example 2. It is impossible to fill the remaining entries of matrix B such that the resulting matrix is good, as B[1][2] = 1 and B[2][1] = 0, which is impossible.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct nod{
	int val,c;
	struct nod *next;
}node;
int abs(int i)
{
	if(i<0)
		return -1*i;
	return i;
}
int main()
{
	int a[100005],n,qu,i,no,u,v,ab,b[100001],q[100005];
	node *nd[100005],*e[100005],*temp;
	int rear,t,end;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&qu);
		for(i=1;i<=n;i++)
		{
			a[i]=b[i]=0;nd[i]=NULL;e[i]=NULL;
		}
			no=0;
			for(i=1;i<=qu;i++)
			{
				scanf("%d%d%d",&u,&v,&ab);
				if(!no){
					if(u==v&&ab==1)
						no=1;
					else if(u!=v)
					{
						temp =(node*)malloc(sizeof(node));
						temp->next=NULL;
						temp->val=ab;
						temp->c=v;
						if(nd[u]==NULL)
							nd[u]=temp;
						else
							e[u]->next=temp;
						e[u]=temp;
						temp =(node*)malloc(sizeof(node));
						temp->next=NULL;
						temp->c=u;
						temp->val=ab;
						if(nd[v]==NULL)
							nd[v]=temp;
						else
							e[v]->next=temp;
						e[v]=temp;
					}
				}
			}
				for(i=1;i<=n;i++)
				{
					if(no==1)
						break;
					rear=-1;
					end=0;
					if(!b[i])
					{
						q[end]=i;
						b[i]=1;
						while(rear<end&&no==0)
						{

							temp=nd[q[++rear]];
							while(temp!=NULL&&no==0)
							{
								if(!b[temp->c])
								{
									b[temp->c]=1;
									a[temp->c]=abs(temp->val-a[q[rear]]);
									q[++end]=temp->c;
								}
								else if(abs(a[temp->c]-a[q[rear]])!=temp->val)
								{
									no=1;
								}

								temp=temp->next;				
							}

						}
					}
				}
		if(no==1)
		printf("no\n");
		else
		printf("yes\n");
	}
} 