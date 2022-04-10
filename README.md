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
