# bookPagePartitioner

Made this so that if you have a certain number of pages of a book that you want to read in a certain number of days,
you can partition up those number of pages into those set number of days.

Doesn't using any fancy math like division. Deals out the pages to the selected number of days like a deck of cards.

Comple this by doing:

```
mkdir build
cd build
cmake .. && make
```

Run this from the bookPagePartioner/build/src directory by doing:

```
./bookPagePartitioner startingPage endingPage numberOfDays
```

for Example, entering the following:

```
$ ./bookPagePartitioner 220 500 10
```
Will produce this output in the terminal:

```
 |-----------------------------------------|
 |          Book Partitioner Pro           |
 |-----------------------------------------|
 |  Day  | Start |   End | Number of Pages |
 |     1 |   220 |   248 |              29 | 
 |     2 |   249 |   276 |              28 | 
 |     3 |   277 |   304 |              28 | 
 |     4 |   305 |   332 |              28 | 
 |     5 |   333 |   360 |              28 | 
 |     6 |   361 |   388 |              28 | 
 |     7 |   389 |   416 |              28 | 
 |     8 |   417 |   444 |              28 | 
 |     9 |   445 |   472 |              28 | 
 |    10 |   473 |   500 |              28 | 
 |-----------------------------------------|
```
