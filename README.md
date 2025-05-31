# QuickSortProject

Given a list of the number of pages in all the books in the school library, and a maximum limit of
the number of pages you are willing to read, determine the maximum number of books you can
fully read!

This solution implements the Quick Sort algortihm to sort the list of book pages from smallest to highest
then return the number of books that can be read after adding up all the pages until it reaches the 
maximum number of pages or run out of books (whichever first).

Run this program with a C compiler.

The Input (to be read from standard input)

The first line will contain a single positive integer, c (c ≤ 25), representing the number of test cases
to process. The test cases follow.

The first line of each test case will contain a two space separated positive integers, n (n ≤ 100000),
representing the number of books in the school library, and L (L ≤ 1014), representing the maximum
number of pages you are willing to read.

The second line of each test case will contain n space separated integers, each of which represents
the number of pages in one of the n books in the school library. Each of these integers will be in
between 1 and 109, inclusive.

The Output (to be printed to standard out)

For each input case, output the maximum number of different books you can read without going
over your maximum page limit.

Sample Input
3
5 20
6 12 3 10 2
5 21
12 3 6 10 2
10 31
9 6 6 3 8 2 12 15 13 7

Sample Output
3
4
5

Note: The C file is what I recovered since I didn't have this file on my computer anymore, 
unfortunately the white space is not like how it used to be but should still be clear what is going on with the code.
