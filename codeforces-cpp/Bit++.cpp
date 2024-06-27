#include <iostream>
#include <string>

int main()
{
	int x = 0;
	unsigned int n = 0, index = 0;;
	std::string operation;

	do
	{
		std::cin >> n;
	}
	while(n > 150);

	do
	{
		std::cin >> operation;
		if((operation[0] == 'X') && (operation.size() < 4))
		{
			if((operation[1] == '+') && (operation[2] == '+'))
			{
				x++;
				index++;
			}
			else if((operation[1] == '-') && (operation[2] == '-'))
			{
				x--;
				index++;
			}
		}
		else if((operation[0] == '+') && (operation.size() < 4))
		{
			if((operation[1] == '+') && (operation[2] == 'X'))
			{
				++x;
				index++;
			}
		}
		else if((operation[0] == '-') && (operation.size() < 4))
		{
			if((operation[1] == '-') && (operation[2] == 'X'))
			{
				--x;
				index++;
			}
		}
	}
	while(index < n);

	std::cout << x;

	return 0;
}

/*
Test 1: 3 opeartions
3
X+++
++X+
X---
-X--
X---
x---
---x
--x
--x
-x-
+xx
++x
+++
+++
+++
+++
----
---
--

---

---
--
--X
++X
++X
1
*/

/*
Test 2: 1 operation
1
X++
1
 */

/*
Test 3: 149 operations
149
X++
X++
X++
X--
X--
X--
X--
X--
X--

X--
X--
X--
X--
X--
X--
X--
X++
X++
X++
X++
X++
X++
X--
X++
X--
X++
X++
X--
X++
X++
X--
X--
X++
X++
X--
X--
X--
X--
X--
X++


X--
X--
X--
X--
X--
X++
X--
X--
X++
X--
X++
X--
X++
X++
X--
X--

X++
X++
X--
X--
X++
X++
X--
X--
X++
X++
X--
X--
X++
X++
X--
X--
X++
X--
X++
X--
X++
X--
X++
X--
X++
X--
X++
X--
X--
X--
X--
X--
X--
X--
X++
X++
X++
X++
X--
X--
X++
X++
X--
X++
X--
X++
X--
X++
X--
X--
X--
X--
X--
X--
X--
X--
X--
X++
X--
X++
X++
X--
X--

X++
X--
X++
X--
X++
X--
X--
X++
X++
X--
X--
X++
X++

X--
X--
X++
X++
X--
X--
X++
X++
X++
X--
X--
X++
X++
X--
X--
X++
X++
-21
 */
