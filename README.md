# talc
A simple CLI single-operation calculator tool

# Usage
## talc
`talc` doesn't work on its own - you need to append the equation to the end of the command, with spaces around the operation. For example:
`talc 1 + 1`

As of now, this will not work:
```
talc 1+1
```

# Operation Support
### + Add
### - Subtract
### * Multiply
### / Divide
### ^ Power

# Install (Linux)
You'll need to have the C language, clang, and git installed already, and then you can run this code:
```
git clone https://github.com/dotclb/talc.git talc

cd talc

clang -o talc main.c -lm

sudo cp talc /usr/local/bin

cd ..

rm -rf talc
```

Alternatively, you could use gcc in place of clang:
```
git clone https://github.com/dotclb/talc.git talc

cd talc

gcc -o talc main.c -lm

cd ..

rm -rf talc
```
