
## Concepts

1. *Modulo rules*

- `(a+b)%m = (a%m+b%m)%m.`
- `(a*b)%m = (a%m*b%m)%m.`

2. *10e9 + 7*
- it is caluclated as (10^10) + 7

3. *Use of &*
- It is used to take the reference of the argument passed while calling the function. It helps to `call by reference`.

4. *Whenver you are given to modulo the answer by (10e8 + 7)*
- So it basically wants you to modulo it at the time of performing the operation and also typecast them to a higher datatype which can store such big numbers and after performing your operation alongwith the modula as well, typecast it back again to the previous datatype

Eg: (int) (((long long)a * (long long)b) % (10e8 + 7))


# Bit Manipulation

1. *what is lowerBound* => a number `ahead of` the maximum element which is `less than` the number whose lowerbound we are finding
    *what is upperBound* => a number `before` the minimum element which is `greater than` the number whose upperbound we are finding

2. *Ceil* => Ceil of x is the smallest element which is ` greater than or equal to x`. Ceil of x doesn’t exist if x is greater than greatest element of arr[].
    *Floor* => Floor of x is the largest element which is `smaller than or equal to x`. Floor of x doesn’t exist if x is smaller than smallest element of arr[].

  


# LinkedList

1. *Hare Tortoise* 
- whenever you don't know about the size of something and you have to find a particular point then this can help you like if you want to be in the middle of LL then make your hare twice as faster as the tort so if the hare hits the NULL then the tort will be in the middle of the LL.

2. *Recursion*
- Whenever you want to start your operations from the last node and then follow back doing your operations to the head. 
- It helps to do so without reversing the entire list.  



# Recursion

1. *Take Not Take* : best way to return a subarray or substring but with T.C : O(2^N) which may lead to the TLE.
2. *When you have to return from recursion after first correct match and no need to search for other matches*: 
    - Make the return type bool
    - return true whenever you get the match.
    - and wrap each function call in an if statement so that if it returns true then you just return from there as well and won't call more function calls
3. *Unique subsequences*: Here you have to understand that if a character is repeating in further string then what could be the possible duplicate subsequence will it formed?
    - For example take "saa" here what will be the duplicate subsequence and the answer is 2 or (the number of subsequence possible before the first occurence of the repeated character because that is the only common subseqeuences which will be formed exactly same with the second occurence of the repeated character)
    - To prove my point let's delve futher the subsequence before first occurence of 'a' is only two ('', 's) now if you see the complete subsequences it will be like this {'', 's', 'a', 'a','sa', 'sa', 'aa', 'saa'} so the above two subsequence are repeating with both occurences (''-> 'a' , 'a' :::: 's'-> 'sa' , 'sa')


# Bit Manipulation

1. 1s complement - just replace all the 1s from the 0s and vice versa from the bit form of the number 
2. 2s complement - add one in the binary you got after 1s complement.
3. n >> k == n/(2^k) 
4. A negative number is stored in the form of 2s complement
5. working of a not oeprator (written at the back of the copy)
6. *check the ith bit* : num & (1 << i-1) or (num >> i-1) & 1


# Patters for coding

1. Just see the video by Sahil gaba of 8 patterns

2. 

### POTD solutions repo

1. [POTD_GFG](https://github.com/getlost01/gfg-potd)