/*
problem link:
Chef likes to play with big numbers. Today, he has a big positive integer N. He can select any two digits from this number (the digits can be same but their positions should be different) and orders them in any one of the two possible ways. For each of these ways, he creates a two digit number from it (might contain leading zeros). Then, he will pick a character corresponding to the ASCII value equal to this number, i.e. the number 65 corresponds to 'A', 66 to 'B' and so on till 90 for 'Z'. Chef is only interested in finding which of the characters in the range 'A' to 'Z' can possibly be picked this way.

Input
The first line of the input contains an integer T denoting the number of test cases.

The first line of the input contains an integer N.

Output
For each test case, output a string containing characters Chef can pick in sorted order If the resulting size of string is zero, you should output a new line.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 10100000
Subtasks
Subtask #1 (40 points) N ≤ 1010
Subtask #2 (60 points) Original Constraints
Example
Input:
4
65
566
11
1623455078

Output:
A
AB

ACDFGHIJKLNPQRSTUVW
Explanation
Example case 1. Chef can pick digits 6 and 5 and create integers 56 and 65. The integer 65 corresponds to 'A'.

Example case 2. Chef can pick digits 6 and 5 and create 'A' as it equals 65. He can pick 6 and 6 (they are picked from position 2 and position 3, respectively) to create 'B' too. Hence answer is "AB".

Example case 3. It's not possible to create any character from 'A' to 'Z'. Hence, we just print a new line.
*/
#include<stdio.h>
#include<string.h>
int main()
{
	int t,n,i,j;
	char a[100002],x;
	scanf("%d%c",&t,&x);
	while(t--)
	{
		scanf("%s",a);
		n=strlen(a);
		int p[26]={0},b[10]={0},j=0,u,h;
		for(i=0;i<n;i++)
		b[a[i]-'0']++;
		j=0;
		for(i=65;i<91;i++)
		{
			u=i%10;
			h=i/10;
			if(u==h&&b[u]==1)
			p[j]=0;
			else if(b[u]>0&&b[h]>0)
			p[j]=1;
			j++;
		}
		for(j=0;j<26;j++)
		{
			if(p[j])
			printf("%c",'A'+j);
		}
		printf("\n");
	}
}