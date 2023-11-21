// for time and space complexity purposes,
// let m = coins.size() and n = amount

#include <vector>

class Solution
{
public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        // create an array 'amounts' of size
        // amount+1 where amounts[i] is the
        // minimum number of coins required to
        // reach amount=i. Assume that
        // each amount cannot be reached initially.
        std::vector<int> amounts(amount + 1, -1); // O(n) space
        bool notMinusOne;

        // Since it takes 0 coins to reach amount 0
        // set amounts[0] = 0
        amounts[0] = 0;

        // for i in [1,amount], fill
        // amounts[i].
        for (int i = 1; i <= amount; i++) // O(n) time
        {
            // to do this, basically
            // try using each coin and
            // then adding the difference
            // (i.e. amount-coin),
            // which we should have already
            // calculated in our amounts array
            // since amount-coin < amount
            // take the minimum of these.

            // this line is explained below
            notMinusOne = false;

            for (int coin : coins) // O(m) time
            {
                // a slight issue: it might be
                // the case that i-coin < 0.
                // In this case we can move on
                // since the coin cannot possibly
                // be used to reach i

                // another slight issue: our array
                // is initialized to -1's, so
                // we'll need to have a variable (notMinusOne)
                // that looks for the first "valid" answer
                // (i.e. where i-coin >= 0) and
                // amounts[i-coin] = -1

                if (i - coin >= 0 && amounts[i - coin] != -1)
                {
                    if (!notMinusOne)
                    {
                        amounts[i] = 1 + amounts[i - coin];
                        notMinusOne = true;
                    }
                    else
                    {
                        amounts[i] = std::min(amounts[i], 1 + amounts[i - coin]);
                    }
                }
            }
        }
        return amounts[amount];
    }
};

// total time complexity: O(m*n)
// total space complexity: O(n)