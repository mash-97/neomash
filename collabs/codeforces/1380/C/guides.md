# Brute Force-> codeforces:contests:1380:C



## Description

Simulate problem codeforces:contests:1380:C by using Brute Force method. It's like an
helper program to help simulate the problem into solution. It'll give us the all possible
solutions for the problem.

NOTICE: Through out the document we'll use just the example input below.
NOTICE: We are going to refer `the elements` as the skills input `[7, 11, 2, 9, 5]`.

## Example

```bash
1
5 10
7 11 2 9 5
```


## The Method

As brute-force we'll first produce the power-set of the elements.
Actually, the power-set we're talking about here is like all the possible teams can be formed from the input.
With the power-set elements we'll form all the possible combinations of teams. <- it's kinda extreme level brute-force,
like bursting a water-bottle with a tank-missile :D.
Then we'll only chose the teams that satisfy the problem.
This is the abstract idea of the brute-force method that we're going to use here.


## The Solutional Segments

Now we're going to segmentify the method, with the associated functions and the header
file name where the functions should be placed inside:

  1. Make a vector of vectors as power-set of the elements.
        ```cpp
        [utils.h]

        vector<vector<int>> get_power_set(vector<int>)
        ```

  2. Get possible combinations of teams from the power-vector.
        ```cpp
        [utils.h]

        vector<vector<vector<int>>> get_possible_teams(vector<vector<int>>)
        ```

  3. Choose only the teams that satisfy the problem.
        ```cpp
        [utils.h]

        /* this is the function that checks if the collected teams abide the rules of the problem */
        /* it just a simple function that checks if minimum_skill from the team multiplied by the size of the team is  greater of equal to the x */
        bool does_satisfy(vector<vector<int>>)

        vector<vector<vector<int>>> get_satisfied_teams(vector<vector<vector<int>>>)
        ```

  4. Some helper functions.
        ```cpp
        [helper.h]

        vector<int> merge_vector(vector<int>, vector<int>)  // which merges two vectors
        bool is_uniq(vector<int>)   // check if the elements inside the vector are uniq
        ```

  4. Write the main simulation function using all the above utils functions.
        ```cpp
        [main.cpp]

        int main() // which just simulates the program the way we want
        ```

We're allowed to have other helper functions as our needs.


## Words

As it just the primary guide, if possible suggest us corrections!
