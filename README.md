# tlas
tiny lemon assembler

## EBNF
```ebnf
(* atom *)
character   = ? ascii character ? ;
letter      = ? english alphabet ? ;
digit       = '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' ;
symbol      = '_' | '.' | '@' | '?' | '!' | ':' | '$' ;
identifier  = ( letter | symbol ) , { letter | digit | symbol } ;
(* low level *)
boolean     = 'true' | 'false' ;
address reg = 'a'    | 'd'   | 'k'   | 'p'    ;
register    = 'f'    | 'i'   | 'o'   | 's'    | address reg     ;
status flag = 'fz'   | 'fc'  | 'fn'  | 'fo'   | 'fi'   | 'fb'   | 'fs'   | 'fu'   ;
instruction = 'nop'  | 'mov' | 'swp' | 'setf' | 'jif'  | 'jmp'  | 'call' | 'loop' | 'psha' | 'popa' 
            | 'rti'  | 'brk' | 'in'  | 'out'  | 'halt' | 'push' | 'pop'  | 'peek' | 'cmp'  | 'test' 
            | 'add'  | 'adc' | 'sub' | 'sbc'  | 'and'  | 'or'   | 'nor'  | 'xor'  | 'inc'  | 'dec'  
            | 'not'  | 'neg' | 'shl' | 'shlc' | 'shr'  | 'shrc' | 'db'   | 'rb'   | 'asm'  | 'bin'  
            | 'inta' ;
string      = '"' , character , { character } , '"' ;
char        = "'" , character , "'" ;
integer     = [ '-' ] , digit , { digit } ;
label       = identifier ;
(* high level *)
byte value  = integer | char | label ;
double mem  = '**' , address reg ;
memory      = '*' , ( address reg | byte value ) ;
operand     = register | status flag | byte value | memory | double mem | string | boolean ;
operands    = operand , [ operand , [ operand ] ] ;
comment     = ';' , { character } ;
source line = [ label ] , [ instruction , [ operands ] ] , [ comment ] , '\n' ;
text        = { source line } ;
```
## instructions
f_ - fz, fc, fn, fo, fi, fb, fs or fu

boolean - true or false

reg - any register

address_reg - a, d, k or f

mem - value at address

imm - value at p and defined immediately
### nop (no operation)
instruction to do nothing
```
nop
```
### mov (move)
set value of register or memory
```
mov reg a
mov a reg
mov reg 0
mov a mem
mov mem a
mov a imm
```
### swp (swap)
swap a with register or memory
```
swp a reg
swp a mem
swp reg a
swp mem a
```
### setf (set flag)
set one bit of the status flag register to true or false
```
setf f_ boolean
```
### jif (jump if)
jump to immediate address if register f has required state
```
jif f_ boolean imm
```
### jmp (jump)
unconditional jump to address from address register or immediate address
```
jmp imm
jmp *address_reg
jmp **address_reg
```
### call
push p and do what jmp do
```
call imm
call *address_reg
call **address_reg
```
### loop
a - 1 and jump if a is not null
```
loop imm
loop *address_reg
loop **address_reg
```
### psha (push all)
push a, d, i, k, o, f
```
psha
```
### popa (pop all)
pop f, o, k, i, d, a
```
popa
```
### rti (return from interrupt)
popa and pop p in one instruction
```
rti
```
### brk (break)
do interrupt and set fb true
```
brk
```
### in (input)
get value from i-th input port and save it to a
```
in
```
### out (output)
sends value of a to o-th output port
```
out
```
### halt
jump to itself forever
```
halt
```
### push
push register or memory
```
push reg
push mem
push imm
```
### pop
pop register or memory
```
pop reg
pop mem
```
### peek
peek register or memory
```
peek reg
peek mem
```
### cmp (compare)
imaginary subtraction to set status flags (a - mem)
```
cmp imm
cmp mem
```
### test
imaginary bitwise AND to set status flags (a & mem)
```
test imm
test mem
```
### add (addition)
a = a + memory
```
add imm_address
add imm
```
### adc (addition with carry)
a = a + memory + fc
```
adc imm_address
adc imm
```
### sub (subtraction)
a = a - memory
```
sub imm_address
sub imm
```
### sbc (subtraction with carry)
a = a - memory - fc
```
sbc imm_address
sbc imm
```
### and (bitwise and)
a = a & mem
```
and imm_address
and imm
```
### or (bitwise or)
a = a | mem
```
or imm_address
or imm
```
### nor (bitwise nor)
a = ~(a | mem)
```
nor imm_address
nor imm
```
### xor (bitwise xor)
a = a ^ mem
```
xor imm_address
xor imm
```
### inc (increment)
+1 to memory or a or d or k
```
inc imm_address
inc a
inc d
inc k
```
### dec (decrement)
-1 to memory or a or d or k
```
dec imm_address
dec a
dec d
dec k
```
### not (bitwise not)
bitwise not a or memory
```
not a
not imm_address
```
### neg (negative)
change sign of a or memory
```
neg a
neg imm_address
```
### shl (shift left)
a = a << 1
```
shl
```
### shr (shift right)
a = a >> 1
```
shr
```
### shlc (shift left with carry)
a = a << 1

a = a | fc
```
shlc
```
### shrc (shift right with carry)
a = a >> 1

a = a | (fc << 7)
```
shrc
```
### db (define bytes)
pseudo-instruction to put values to memory
```
db imm imm ... imm ; any number of arguments
```
### rb (reserve bytes)
pseudo-instruction to put several null values
```
rb imm ; where imm is number of bytes
```
### asm (assembly file)
pseudo-instruction to include another tlas file
```
asm filename_string
```
### bin (binary file)
pseudo-instruction to include binary file
```
asm filename_string
```
