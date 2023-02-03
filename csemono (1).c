#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Returns true if str[curr] does not matches with any of
// the characters after str[start]
bool shouldSwap(char str[], int start, int curr)
{
	for (int i = start; i < curr; i++)
		if (str[i] == str[curr])
			return 0;
	return 1;
}

// Prints all distinct permutations in str[0..n-1]
void findPermutations(char str[], int index, int n)
{
	if (index >= n) {
		printf("%s\n", str);
		return;
	}

	for (int i = index; i < n; i++) {

		// Proceed further for str[i] only if it
		// doesn't match with any of the characters
		// after str[index]
		bool check = shouldSwap(str, index, i);
		if (check) {
			// Swapping the str[index] with str[i]
			char temp = str[index];
			str[index] = str[i];
			str[i] = temp;
			findPermutations(str, index + 1, n);
			// Swapping the str[index] with str[i]
			temp = str[index];
			str[index] = str[i];
			str[i] = temp;
		}
	}
}

// Driver code
int main()
{
	char str[] = "ABCD";
	int n = strlen(str);
	findPermutations(str, 0, n);
	return 0;
}
