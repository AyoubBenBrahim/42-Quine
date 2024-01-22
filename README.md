## self-replicating programs

##### Making a spoon using only a [spoon](https://youtu.be/OSfUUqNkrOQ)

![alt text](./spoon.png "spoon")

#### Requirements:

This project invites you to confront the principle of self-reproduction and the problems that derive from it. It is a perfect introduction to more complex projects, particularly malware projects.

The goal of this project is to write three quines.

A quine is a program whose output is equal to its source code.

This project is done using C.

#### Testing quines

javac -d jv *.java

Quine.java jv

diff Quine.java <(java -cp jv Quine)

gcc ex1.c -o ex1 && ./ex1 > ex1.txt && diff ex1.c ex1.txt

gcc ex2.c -o ex2 && ./ex2 > ex2.txt && diff ex2.c ex2.txt

gcc Colleen.c -o Colleen && ./Colleen > Colleen.txt && diff Colleen.c Colleen.txt

diff test.js <(node test.js)

gcc Grace.c -o Grace && ./Grace && diff Grace.c Grace_kid.c

#### to read:

https://en.wikipedia.org/wiki/Quine_(computing)

https://en.wikipedia.org/wiki/Fixed_point_(mathematics)

check f(x) = x here  https://www.desmos.com/calculator/rih3fgne7h

https://en.wikipedia.org/wiki/Kleene%27s_recursion_theorem

https://en.wikipedia.org/wiki/Indirect_self-reference

https://en.wikipedia.org/wiki/Quine%27s_paradox

https://en.wikipedia.org/wiki/Autopoiesis

https://newmaterialism.eu/almanac/a/autopoietic-system.html
