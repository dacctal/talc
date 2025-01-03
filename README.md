# talc
A simple CLI calculator tool

# Usage
## talc
`talc` launches the calculator prompt
## That's it
No more annoying syntax to remember. Just type "talc" and be on your way!

# Operation Support
### + Add
### - Subtract
### * Multiply
### / Divide
### ^ Power

# Install (Linux)
You'll need to have the C language, clang, and git installed already, and then you can run this code:
```
git clone https://github.com/DOTADER/talc.git talc

cd talc

clang -o talc main.c -lm

sudo cp talc /usr/local/bin

cd ..

rm -rf talc
```
