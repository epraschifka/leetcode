// DONE

// given two strings s and t, return true if s is a subsequence of t, and false otherwise.
// how big can s be? 0 <= s.length <= 100
// how big can t be? 0 <= t.length <= 10^4
// what characters can s and t consist of? lowercase english chars

// t = aumriiopiz
// s = b (false)
// s = a (true)
// s = aumriiopiz (true)
// s = ai (true)
// s = ua (false)
// s = au (true)
// s = "" (true)

// if s is empty:
//      return true

// if t is empty:
//      return (s=="")

// have two iterators: one for s (s_itr) and one for t (t_itr).

// for char c in t: O(|t|)
//     if c == *s_itr:
//          s_itr++
//     if s_itr has gone past the end of s:
//          return true
//     t_itr++
//  return false

// suppose s has length |s| and t has length |t|,
// time complexity: O(|t|)
// space complexity: O(1)

#include <string>

class Solution
{
public:
    bool isSubsequence(std::string s, std::string t)
    {
        // if s is empty:
        //      return true
        if (s == "")
        {
            return true;
        }

        // if t is empty:
        //      return (s=="")
        if (t == "")
        {
            return (s == "");
        }

        // have two iterators: one for s (s_itr) and one for t (t_itr).
        std::string::iterator s_itr = s.begin();
        std::string::iterator t_itr = t.begin();

        // for char c in t: O(|t|)
        for (char c : t)
        {
            //     if c == *s_itr:
            if (c == *s_itr)
            {
                //  s_itr++
                ++s_itr;
            }
            //     if s_itr has gone past the end of s:
            if (s_itr == s.end())
            {
                // return true
                return true;
            }

            //     t_itr++
            ++t_itr;
        }

        //  return false
        return false;
    }
};