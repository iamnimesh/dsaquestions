/* Dynamic Programming implementation of LCS problem */
#include<bits/stdc++.h>

using namespace std;

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
string lcs(string  X, string Y, int m, int n )
{
int t[m+1][n+1];

for (int i=0; i<=m; i++)

	for (int j=0; j<=n; j++)
	
	if (i == 0 || j == 0)
		t[i][j] = 0;
/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
for (int i=1; i<=m; i++)
{
	for (int j=1; j<=n; j++)
	{
	
	 if (X[i-1] == Y[j-1])
		t[i][j] = t[i-1][j-1] + 1;
	else
		t[i][j] = max(t[i-1][j], t[i][j-1]);
	}
}

// Following code is used to print LCS
string s1=""; // Set the terminating character

// Start from the right-most-bottom-most corner and
// one by one store characters in lcs[]
int i = m, j = n;
while (i > 0 && j > 0)
{
	// If current character in X[] and Y are same, then
	// current character is part of LCS
	if (X[i-1] == Y[j-1])
	{
		s1.push_back(X[i-1]); // Put current character in result
		i--; j--; 	 // reduce values of i, j and index
	}

	// If not same, then find the larger of two and
	// go in the direction of larger value
   /* else
    {
      if (L[i][j-1] >L[i][j])
        j--;
      else
        i--;
    }*/
    
	else if (t[i-1][j] > t[i][j-1])
		i--;
	else
		j--;
}
reverse(s1.begin(),s1.end());
// Print the lcs
return s1;
}

/* Driver program to test above function */
int main()
{
string X ;
string Y ;
cin>>X>>Y;
int m = X.length();
int n = Y.length();
cout<<lcs(X, Y, m, n);
return 0;
}
