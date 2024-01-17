
➜  javac -d jv *.java

Quine.java jv

➜   diff Quine.java <(java -cp jv Quine)

gcc ex1.c -o ex1 && ./ex1 > ex1.txt && diff ex1.c ex1.txt

gcc ex2.c -o ex2 && ./ex2 > ex2.txt && diff ex2.c ex2.txt

gcc Colleen.c -o Colleen && ./Colleen > Colleen.txt && diff Colleen.c Colleen.txt

diff test.js <(node test.js)

gcc Grace.c -o Grace && ./Grace && diff Grace.c Grace_kid.c
