#include <iostream>
#include <map>
#include <string>
using namespace std;
using mpsss = map<pair<string, string>, string>;
using mpssi = map<pair<string, string>, int>;
using ss = pair<string, string>;

mpsss dp;

// For keep track of visited subproblem or not (0 = not
// visited, 1 = visited)
mpssi vs;

// utility function to reverse a string, we need it because
// our top-down approach return a reversed solution
string reverse(string str)
{
	string ans = str;
	int u = 0;
	int v = ans.length() - 1;
	while (u < v) {
		swap(ans[u], ans[v]);
		u++;
		v--;
	}
	return ans;
}

// utility function that compares two strings and return the
// longer in size.
string max_str(string a, string b)
{
	if (a.length() > b.length())
		return a;
	else
		return b;
}

string LCS_core(string a, string b)
{

	// size of string a
	int n_a = a.length();

	// size of string b
	int n_b = b.length();

	// Base case
	if (n_a == 0 || n_b == 0)
		return "";

	// dp index to access the dp structure
	ss dp_i = make_pair(a, b);

	// ans points to the memory location in the dp
	// structure in which the solution string will be stored
	string& ans = dp[dp_i];

	// if visited return solution from memory.
	if (vs[dp_i] == 1)
		return dp[dp_i];

	// if not visited, set the visit value to be one
	// (meaning its now visited)
	else
		vs[dp_i] = 1;

	// if the last two character match
	if (a[n_a - 1] == b[n_b - 1]) {

		// Add this character to the solution string
		ans += a[n_a - 1];

		// Erase last character from a
		a.erase(n_a - 1, 1);

		// Erase last character from b
		b.erase(n_b - 1, 1);

		// add to the solution string the value of
		// LCS_core(a, b) (the remaining strings after
		// deleting last characters)
		ans += LCS_core(a, b);
		return ans;
	}

	// Return longest string
	ans += max_str(LCS_core(a.substr(0, n_a - 1), b),
				LCS_core(a, b.substr(0, n_b - 1)));
	return ans;
}

string LCS(string a, string b)
{
	;

	// Reverse obtained result
	return reverse(LCS_core(a, b));
}

int main()
{
	string a = "AGGTAB";
	string b = "GXTXAYB";
	cout << LCS(a, b);
	return 0;
}
