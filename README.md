# Extended L System Generator

This project implements an interpreter in C++ of L-Systems descriptor files (`*.lsd`) writen in a custom specific purpose language LSysDescriptor or LSD (see `Syntax and semantics`).

The project is able to generate L-Systems after its axiom and rules and print the result. Very soon, it will be able to show 2D and 3D representations of the resulting string (see `2D Display interpretation`).

An L-System has a set of rules and an axiom, that changes every character on each iteration if a rule is found for each of them. You should also specify the number of iterations (default is 0, prints axiom).

## The program

### Compilation

To compile the program you will need to put the ANTLR 4 (I am using 4.8) libraries in libs/. You can build them from source, in their C++ runtime repo, running:

```
cd <antlr4-dir>/runtime/Cpp
mkdir build && mkdir run && cd build
cmake ..
make
DESTDIR=<antlr4-dir>/runtime/Cpp/run make install
```

Then, run:

```
mkdir build; cd build
cmake ..
make
```

(Optional) If you wish to re-build the lexer and parser files from the grammars (\*.g4), run (in the project root directory):

```
java -jar <ANTLR4-JAR> -Dlanguage=Cpp -o antlr4-runtime/ LSysDParser.g4 LSysDLexer.g4 -visitor
```

where <ANTLR4-JAR> is a jar file that contains the ANTLR 4 parser generator. Or, if you have ANTLR 4 installed and accessible:

```
antlr4 -Dlanguage=Cpp -o antlr4-runtime/ LSysDParser.g4 LSysDLexer.g4 -visitor
```

### Execution

To execute the compiled program to generate l-systems, go to build/ and run:

```
./lsysgen FILE [N_ITERATIONS]
```

Where FILE is a file \*.lsd that describes an L-system. The next part of this file will show you how to edit a \*.lsd file.

<!--There are some useful options that you can see with the help:

$ python3 lsys\.py \-h-->

By default, the program will interpret the L-System and it will draw it in a new window\.

## Syntax and semantics

### Production rules

Production rules have the syntax:

```
[tag:] [(weight)] [left_context<] char [>right_context] -> replacement
```

Production rules can be inside `table` blocks, `rules` blocks, inside `production rules` blocks or outside any block:

```
rules {
    v -> avd  # Valid
    r -> rr   # Valid
}
a -> aFa      # Valid
production rules {
    k -> F-F  # Valid
}
```

A DOL system (the most basic one) has rules of type:

```
char -> replacement
```

where the char occurrences are replaced by replacement.
A DIL system (context-sensitive) would have rules of type:

```
left_context < char -> replacement
```

or:

```
char > right_context -> replacement
```

or both:

```
left_context < char > right_context -> replacement
```

or none like DOL's rules.
A probabilistic l-system can include a weight for each rule (it is not necessary, every rule has a default weight of 1). The syntax is just adding the parenthesized value at the beginning of the rule. For example:

```
(9) a -> a
    a -> b
(!) a < a -> ba
```

In this example, with an axiom `aaba`, the system would replace the first and last `a` characters by `a` (90% probability) or `b` (10% probability). The second 'a' would match the three rules, but only the third would be always applied, because the special weight ! means that it must be always chosen.
As you can see, any pair of ambiguous rules can bring non determinism to our l system, even without explicit set of weights. Also, when two rules with ! weight are available for some character, the first will be always applied.

For parametric l-systems, you can just add parameters to any character in the left or right. The char to be replaced can define its parameters' names and even define a condition (optional). The right side can specify arguments for its characters, referencing (or not) the left side parameters. For example:

```
a(x, y) -> b(x, y-1)
b(x, y | y >= 0) -> a(x+1, y)c(y)
```

Any character in the left and right contexts can also define their parameter names and their conditions. Char's condition can reference both context sides' params, but contexts' conditions can only reference char's params and params defined before them. The right side of the rule can reference all the params defined in the left side of the rule. For example:

```
c(x)d(y|x==y and y<z) < a(z, w) > d(y_|y_>z)c(x_|y_==x_) -> a(max(y, y_), w)
```

Bracketed IL-systems (context-sensitive l-systems with branches) have a special treatment for brackets. They are not treated as characters in the left side, so they cannot be replaced. When asking for a character in a left context:

```
a < b -> bb
```

The `b` of `abc` would be accepted, and also the one of `a[cc]b`, `a[bcd]` and `a[[b]c]`, but not `[a]b`.
For right context:

```
b > a -> c
```

The `b` of `cba` would be accepted, and also the one of `cb[cd]a`, `b[add]c` and `b[[a]d]`, but not `[b]a`.
When asking for a branch in the left or right context, it is matched if and only if a branch is found starting by the specified elements (at the beginning, on the left). For example:

```
[ab] < c > [ad] -> [cab]
```

matches with the `c` in `[abddd]c[adrst]`, `[ab]c[ad]`, `[ab][c[[ad]s]]`, but not `[ba]c[ad]` or `[dab]c[ssad]`.

A rule can have in the left hand side the special character '\_' that represents any character. For example:

```
    a -> bd
    b -> ac
(!) a < _ > a -> a
```

This means that any character surrounded by `a`s will always be replaced by an `a`.

```
b_c < a -> o
```

This matches with the `a` of `baca`, `b+ca`, `bbca`, etc.

### Tables

If you plan to use tables, you first write the line:

```
set table_func(i) = <expr>
```

where `<expr>` is the expression of the function that decides which table will be used for the i-th iteration. For example:

```
set table_func(i) =  if i % 5 != 1 then "t1" else "t2"
```

Table names cannot be numbers. The code that defines a table is:

```
table <name> { <rules> }
```

Inside table blocks you can define rules or reference tags of already defined rules. For example:

```
set table_func(i) = 't' + str(i % 2)
rules {
    rep: (!) aa < a -> aFb
}
table t0 {
    a -> b
    b -> ab
    rep
}
table t1 {
    a -> ba
    b -> a
    rep
}
```

### Coding rules

Coding rules can also be specified (better after production rules). These special rules are not applied as production rules. Instead, they apply at the end of an iteration for the string to be interpreted. For example, if you want the character `R` to be interpreted as a right branch (`[-F]`), you must not add a production rule for it, because it would not work with the `R`s generated in the same iteration and you would not be able to replace that `R` anymore (instead, you would end accumulating `[-F]`s everywhere). What you would need is:

```
R => [-F]
```

With this rule, the string `FFRFFR` would feed the next iteration but for the graphic representation it would be transformed into `FF[-F]FF[-F]`.

Coding rules can be included in `rules` block, in `coding rules` block or outside any block:

```
a => FFF      # Valid
a -> aFa      # Valid
rules {
    v -> avd  # Valid
    v =>      # Valid
}
coding rules {
    r -> rr   # Invalid
    r => k    # Valid
}
production rules {
    k => F-F  # Invalid
    k -> F-F  # Valid
}
u => [+F]     # Valid
```
    
The syntax of the coding rules is the same than production rules'. They also work similarly. Though they don't belong to tables, they are global.

### Comments

Every line followed by the character `#` is a comment:

```
# Hey I'm a comment
set notAComment = 3 #aComment
```

### Properties

We have seen the `table_func` function to choose which table to choose each time. We can also define properties. The ones that the system understand (and require) are:

```
set axiom = "aabb"          # This line sets the axiom string of the L-System
set iterations = 8          # This line sets the number of iterations that the system will be executing
set ignore = ""             # (optional) This property sets the characters that must be ignored as context (see contexts in rules)
set initial_heading = 90    # (optional, defaults 90) This property sets the initial heading in degrees that the turtle will have. 0 heads east. 90 heads north
set rotation = 30           # (optional, defaults 30) This property sets the angle rotation in degrees that is used in rotations (- and + chars)
```

This was the last line to be read. The file may contain more text after this last line but it will be ignored. That's why the example file has so many lines: it has the description of some examples, separated by blank lines, but only the first one will be read.

There are example files called `*.lsd` you just have to execute the program with the name of the file as its parameter.

## 2D Display interpretation

- `F` draws a forward line.
- `G` draws a backward line.
- `f` moves forward without drawing.
`F`, `G` and `f` can have one parameter that specifies the length of the line/move. Default is `5`.

- `+` rotates counterclockwise.
- `-` rotates clockwise.
`+` and `-` can accept one parameter that specifies the rotation angle (in degrees). Default angle is defined by the user.

- `[` pushes a state.
- `]` pops a state.
The state is a position, heading and color configuration. When closing a bracket, the turtle returns to the state when the bracket was opened.

- `w` for white.
- `k` for black.
- `r` for red.
- `g` for green.
- `b` for blue.
These fixed color characters stablish the pen and fill color until the end of the current branch or until it is changed again.

- `c("#RRGGBB")` or `c(r, g, b)` changes the pen and fill color to the specified by the parameter(s) until the end of the current branch or until it is changed again.
- `n` works as `c` but only with pen color.
- `l` works as `c` but only with fill color.

- `P` to start delimiting a figure to fill.
- `p` to end delimiting the figure.
It is not possible to fill two figures if one contains another in the string. This is, a `P` must be followed by a `p` before another `P`.

The rest of the characters will be ignored when displaying.

## Next steps

- Manage pointers (destructors and deletes)
- Capture all LSD semantic errors and expression evaluation errors
- Catch bugs
- 2D representation
- 3D representation
- Music representation?

