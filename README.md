# Extended L System Generator

This project implements in C++ an L System generator and renderer and a LSDL (L System Defining Language) interpreter. LSDL is a custom specific purpose language (see `Syntax and semantics`) that has been created ad-hoc for this project as a way of describing L Systems to the generator. The program reads LSDL `*.lsd` files, that define one or more L Systems with an easy and compact syntax. You can not only print the results of the L System but also create a SVG image from it (see `2D rendering`). Example:

```
lsys -a "A" -r "A->F(1.0)[+A][-A]; F(x)->F(x*1.6)" -H 90 -R 60 -C "#f00" -W 2 -i 11 --svg - -w 1000 | display
```

Shows:

![Penrose tiling](./images/tree1.svg)

An L system or Lindenmayer system is a parallel rewriting system and a type of formal grammar. An L-system consists of an alphabet of symbols that can be used to make strings, a collection of production rules that expand each symbol into some larger string of symbols, an initial "axiom" string from which to begin construction, and a mechanism for translating the generated strings into geometric structures.

L-systems were introduced and developed in 1968 by Aristid Lindenmayer, a Hungarian theoretical biologist and botanist at the University of Utrecht. Lindenmayer used L-systems to describe the behaviour of plant cells and to model the growth processes of plant development. L-systems have also been used to model the morphology of a variety of organisms and can be used to generate self-similar fractals.

To create an L System an axiom and a set of rules are needed (you can build an L System with just an axiom too, although it wouldn't change over iterations). An axiom is a string of characters such as letters, numbers and some symbols, e.g. "A", "F++F++F", etc. A rule has generally the shape "left -> right", where 'left' is the character the rule will select to be replaced by the 'right' string, e.g. "A -> AB", "B->A", etc.

Enjoy creating plants and fractals with this tool!

<!--The project is able to generate L-Systems after its axiom and rules, print the result or generate a 2D image SVG of it (see `2D rendering`).

An L-System has a set of rules and an axiom, that changes every character on each iteration if a rule is found for each of them. You should also specify the number of iterations (default is 0, prints axiom).-->

## Example L Systems (generated with the program)

Example `*.lsd` files are provided in `examples/`. You are free to use them in the program, even tweaking some parameters (see `lsys --help`).

```
lsystem DragonCurve {

    axiom FX

    set iterations = 10
    set initial_heading = 0
    set background = "#000"
    set line_color = "#3f3"
    set rotation = 90

    rules {

        X -> X+YF+
        Y -> -FX-Y

    }

}
```

Executing the program with this file (`lsys examples/DragonCurve.lsd --svg - | display`) generates:

![Dragon curve](./images/DragonCurve.svg)

### Other examples

Some parametric random plant (examples/B2.lsd):

![Some parametric random plant](./images/B2.svg)

Penrose tiling (examples/PenroseTiling.lsd):

![Penrose tiling](./images/PenroseTiling.svg)

Broccoli (examples/Broccoli.lsd):

![Broccoli](./images/Broccoli.svg)

Cantor set (examples/ParametricCantorSet.lsd):

![Cantor set](./images/ParametricCantorSet.svg)

## The program

### Compilation

#### Ubuntu/Debian

This program uses `ANTLR 4.11.1`, `CMake (>=3.15)` and other required libraries, like Java Runtime Environment to compile the grammar with the ANTLR jar file. ANTLR4 will later be installed and linked with the `make` command automatically. To install our dependencies:

```
sudo apt install cmake default-jre
```

Then, in our `LSysGen` folder, run:

```
mkdir build && cd build
cmake ..
make
```

For debug purposes, the cmake command should be something like:

```
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

If everything goes well, you will get the library `lsysgen.a` (that contains all the functionality of the project) and the executable `lsys`, the main program. Type `./lsys --help` for information about usage and arguments.

<!--
(*Optional*) If you wish to re-build the lexer and parser files from the grammars (`*.g4`), run (in the project root directory):

```
sudo apt install default-jre
```

```
java -jar <ANTLR4-JAR> -Dlanguage=Cpp -o antlr4-generated/ LSysDParser.g4 LSysDLexer.g4 -visitor -no-listener
```

where `<ANTLR4-JAR>` is a jar file that contains the ANTLR 4 parser generator. Or, if you have ANTLR 4 installed and accessible:

```
antlr4 -Dlanguage=Cpp -o antlr4-generated/ LSysDParser.g4 LSysDLexer.g4 -visitor -no-listener
```
-->

#### MacOS

MacOS target is expected to be tested in the future.

#### Windows

Windows target is still not available for this project.

### Execution

This project has two elements for processing L Systems: an executable and a library. The library (`lsysgen`) provides access to functions to manage out L Systems, Modules and read LSDL files. The executable (`lsys`) provides many options to create, customize and run your L Systems with command line arguments. The `--svg` option prints or writes to a file a SVG image of the run (the program just prints out the file, you can open it with a SVG compatible image viewer or a web browser, see `2D rendering`).

To execute the `lsys` program, go to `build/` and run either of:

```
./lsys INPUT_FILE [OUTPUT_FILE] [OPTIONS]
./lsys -a AXIOM [OPTIONS]
```

The main options are:

- `-i N`: sets or overrides the number of iterations
- `-a AXIOM`: sets or overrides the axiom. `AXIOM` should be quoted.
- `-r RULES`: adds rules to the L System. `RULES` must be quoted.
- `--svg [OUTPUT_SVG_FILE]`: outputs a SVG image after the L System result. If not set, the program outputs the result as is. If `OUTPUT_SVG_FILE` is set, that will be the file where the output will be writen, otherwise the output will be printed to the standard output. If `OUTPUT_SVG_FILE` set to a directory, a `FILE.svg` file will be created inside that directory, where `FILE` will be the name of the selected L System.

Run `./lsys --help` to see all options. 

Examples:

Inline L System (without LSDL file, defined by axiom (`-a`) and rules (`-r`) arguments):

```
./lsys -a "A" -r "A->B; B->AB;" -i 10
```

Output:

```
ABBABBABABBABBABABBABABBABBABABBABBABABBABABBABBABABBABABBABBABABBABBABABBABABBABBABABBAB
```

L System from LSDL file (ImageMagick's `display` opens a window that displays the SVG image output):

```
./lsys ../examples/Test1.lsd --svg - | display
```

Output:

![Test1 image](./images/Test1.svg)

Other examples:

```
./lsys ../examples/HilbertCurve.lsd --svg -i 4 | display
./lsys ../examples/B2.lsd -i 20 --svg B2.svg
```

There is also a small Python module, `lsys.py`, that uses the `lsysgen` library and serves as a Python wrapper for the library (through its class `LSystem` that is able to print the L system and also its 2D render). This python script is also runnable and prints the resulting L system string and the SVG image:

```
python lsys.py INPUT_FILE [N_ITERATIONS]
```

<!--

`INPUT_FILE` is a `*.lsd` file (or `-` for standard input) that defines an L-system. The next part of this file will show you how to edit a `*.lsd` file.

There are some useful options that you can see with the help:

$ python3 lsys\.py \-h

By default, the program will interpret the L-System and will draw it in a new window.-->

## LSDL Syntax and semantics

### Document structure

To define an L system with an axiom and the rules that transform it, I have created the LSDL (L System Defining Language) specific purpose language.

In the cases where we want to define just an axiom for the program to interpret it, we can just fill the document with the axiom. For example, to quickly draw a custom figure:

```
./build/lsys -a "F+F+PF+F+F+Fp+F+F" -F "#FF0000" -R 30 --svg images/test.svg
```

But this is not the main case. If we want to *generate* the L system, we create an LSDL document for it or tweak the program's parameters (`-r` to add rules, etc.).

The LSDL document consists on a series of definitions inside a name:

```
lsystem Name {

    # definitions...

}
```

or anonymous, without any name:

```
# definitions...
```

The three most important definitions in an L system are the **axiom**, the **rules** and the **number of iterations** (they are explained in further subsections).

For example, the sierpinski triangle in `examples/sierpinski.lsd`:

```
lsystem SierpinskiTriangle {

    axiom F-G-G

    set iterations = 6
    set initial_heading = 0
    set rotation = -120
    set background = "#ffbb00"

    rules {
        F -> F-G+F+G-F
        G -> GG

        G => F
    }

}
```

If we run:

```
./build/lsys examples/SierpinskiTriangle.lsd --svg - | display
```

This generates:

![Sierpinski](./images/SierpinskiTriangle.svg)

An example of an anonymous L system:

```
./build/lsys -a "A" -r "A->B; B->AB" -i 5
```

This gives us `BABABBAB`.

### Comments

Every text (in a line) followed by the character `#` is a comment and will be ignored by the interpreter:

```
# Hey I'm a comment
set notAComment = 3 #aComment
```

### Axiom

The axiom of an L system is the initial string and must be always defined once for each L system. This string is changed by the rules in the first iteration. The result of that is changed again by the rules in the second iteration... and so on.

We define an axiom:

```
axiom AB;
```

Semicolons at the end of each definition are only required if you wish to write several definitions in the same line.

### Number of iterations

This is the number of times that rules will be applied to generate the L system. We just have to define the `iterations` constant as a non-negative integer:

```
set iterations = 6
```

We can also use the option `-i` in the program to set it.

### Production rules

Production rules have the syntax:

```
[weight|] [left_context<] char [>right_context] [:condition] -> replacement
```

Production rules can be inside `table` blocks, `rules` blocks, `production rules` blocks or outside any block:

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

where the `char` occurrences are replaced by `replacement` in each iteration.
A DIL system (context-sensitive) would have rules with a left context:

```
left_context < char -> replacement
```

a right context:

```
char > right_context -> replacement
```

both:

```
left_context < char > right_context -> replacement
```

or none (like DOL's rules). A rule can't be chosen for some character if it doesn't meet the `condition`. For example, this rule:

```
9| A(x) : x < 5 -> A(x+1)
```

cannot match symbols `A`, `A(8)` or `A(6, 0.2)`.

A probabilistic l-system may have more than one rule available for the same character. Also, a weight can be specified for each rule (when the weight is not defined, a rule has a default weight of `1`). That weight will determine the probability of the rule to be chosen over other available rules. The syntax of a weighted rule just adds the parenthesized value at the beginning of the rule. For example:

```
9| a -> a
   a -> b
!| a < a -> ba
```

In this example, with an axiom `aaba`, the system would replace the first and last `a` characters by `a` (90% probability) or `b` (10% probability). The second 'a' would match the three rules, but only the third would be always applied (when matching an `a` followed by another `a`), because the special weight `!` means that it must be always chosen.

As you can see, any pair of ambiguous rules can bring non determinism to our l-system, even without explicit set of weights. Also, when two rules with `!` weight are available for some character, the first one will be always applied.

For parametric l-systems, you can just add parameters to any character in the left or right. The char to be replaced can define its parameters' names and a condition can be set for the rule to be executed (optional). The right side can specify arguments for its characters. For example:

```
a(x, y) -> b(x, y-1)
b(x, y): y >= 0 -> a(x+1, y)c(y)
```

Expressions in the right side or condition can use parameters of that rule, global constants and a special variable `i` that equals the number of the current iterations (`0` in axiom, `1` in first iteration, `2` in second, etc.)

Any character in the left and right contexts can also define their parameter names and their conditions. Char's condition can reference both context sides' params, but contexts' conditions can only reference char's params and params defined before them. The right side of the rule can reference all the params defined in the left side of the rule. For example:

```
c(x)d(y) < a(z, w) > d(y_)c(x_): x<=y and y<z and y_>z and y_=y -> a(max(y, y_), w)
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

A rule can have in the left hand side the special character `_` that represents any character. For example:

```
   a -> bd
   b -> ac
!| a < _ > a -> a
```

means that any character surrounded by `a`s will always be replaced by an `a`. This one:

```
b_c < a -> o
```

matches the `a` of `baca`, `b+ca`, `bbca`, etc.

### Tables

If you plan to use tables, you need to write the line:

```
set table_func(i) = <expr>
```

where `<expr>` is the expression of the function that decides which table will be used for the `i`-th iteration. For example:

```
set table_func(i) =  if i % 5 != 1 then "t1" else "t2"
```

Table names cannot be numbers. The code that defines a table is:

```
table <name> { <rules> }
```

Example:

```
set table_func(i) = 't' + str(i % 2)

table t0 {
    a -> b
    b -> ab
}
table t1 {
    a -> ba
    b -> a
}
```

<!--

Inside `table` blocks you can define rules or reference tags of already defined rules. For example:

```
set table_func(i) = 't' + str(i % 2)
rules {
    rep: {!} aa < a -> aFb
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

-->

### Coding rules

Coding rules can also be specified (better after production rules). These special rules are not applied as production rules. Instead, they apply at the end of an iteration for the string to be interpreted. For example, if you want the character `R` to be interpreted as a right branch (`[-F]`), you must not add a production rule for it, because it would not work with the `R`s generated in the same iteration and you would not be able to replace that `R` anymore (instead, you would end accumulating `[-F]`s everywhere). What you would need is:

```
R => [-F]
```

With this rule, the string `FFRFFR` would feed the next iteration but for the graphic representation it would be transformed into `FF[-F]FF[-F]`.

Coding rules can be included inside `rules` block, `coding rules` block or outside any block:

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
    
The syntax of the coding rules is the same than production rules', but using double arrow (`=>`). They also work similarly. Note that coding rules can't belong to tables, but they are global.

### Variables and constants

We have seen the `iterations` constant and the `table_func` function to choose which table to choose each iteration. We can define any function, variable or constant inside our L system.

Axioms and rules share a special variable: `i`, that equals the current iteration number. In the axiom, `i` = `0`, in the production rules, `i` = `1` in the first iteration, `i` = `2` in the second, etc. and in the coding rules, `i` always equals the total number of iterations. Example:

```
./lsys -a "A(i)" -r "A(x)->F(i)fA(x); f=>f(i)" -i 3
```

Output:

```
F(1)f(3)F(2)f(3)F(3)f(3)A(0)
```

Some examples of custom functions, variables and constants:

```
set double(x) = 2*x      # double is a function that takes 1 argument
set SQRT_2 = 1.414       # SQRT_2 is a constant
var x = double(SQRT_2)   # x is a variable
var y                    # y is also a variable
x = x + 1                # OK
y = "Hello"              # OK
SQRT_2 = 3.1             # ERROR: you can't change the value of a constant
```

These are special constant names used by the L system generator:

```
set iterations = 8          # (defaults 0) This line sets the number of iterations that the system will be executing
set ignore = "fF-+"         # (optional, defaults "") This constant sets the characters that must be ignored as context (see contexts in rules)
set seed = 6902             # (optional, defaults -1) You can specify a seed for a non-deterministic L-System. If a negative seed is defined, the program sets a random seed.
```

These other constant names are used by the 2D interpreter and do not have any meaning outside the 2D interpreter:

```
set initial_heading = 90      # (optional, defaults 0.0) This constant sets the initial heading in degrees that the turtle will have. 0 heads east. 90 heads north
set rotation = 30             # (optional, defaults 12.0) This constant sets the angle rotation in degrees that is used in rotations (- and + chars)
set line_width = 0.02         # (optional, defaults 0.1) This constant sets the line width of F and G draw characters, relative to the line length (0.02 is a line width of 0.02 per 1 pixel of line length, so if the line is 100px long, its width will be 2px)
set line_color = "#F33"       # (optional, defaults "#000" (black)) This constant sets the default line color of the line being drawn
set fill_color = "rgb(0,0,0)" # (optional, defaults "#000" (black)) This constant sets the default fill color when filling shapes
set background = "#FFBB00"    # (optional, defaults transparent) This constant sets the background color of the SVG
```

Every special constant has a special command-line argument in the program to quickly force a value for that constant.

You can also define any other variable or constant you want, and use them in the expressions of parametric rules.

## 2D rendering

The program `lsys` with the `--svg` argument renders the output of the L System generation in a 2D SVG image file.

The special characters that 2D rendering uses are:

- `F` draws a forward line.
- `G` draws a backward line.
- `f` moves forward without drawing.
- `g` moves backward without drawing.
- `h` moves horizontally without drawing.
- `v` moves vertically without drawing.

`F`, `G`, `f`, `g`, `h` and `v` can have one parameter that specifies the length of the line/move. Default is `1.0`.

- `+` rotates counterclockwise.
- `-` rotates clockwise.

`+` and `-` can accept one parameter that specifies the rotation angle (in degrees). Default angle is defined by the user in the `rotation` constant.

- `[` pushes a state / creates a branch.
- `]` pops a state / closes the branch.

The state is a position, heading, color and line width configuration. When closing a bracket, the turtle returns to the state when the bracket was opened.

- `c(r, g, b)` or `c(r, g, b, a)` changes the pen and fill color to the specified by the parameter(s) (`r` for red, `g` for green, `b` for blue and `a` for opacity; colors and opacity values range from 0 to 255 or from 0.0 to 1.0) until the end of the current branch or until it is changed again. For example, `c(255, 0, 0)` sets color to red (opaque by default), `c(80, 80, 80, 0.5)` sets color to semi-transparent dark grey and `c(1.0, 0.0, 1.0, 1.0)` sets color to opaque pink. Default fill and pen color is black.
- `n` works as `c` but only with pen color.
- `l` works as `c` but only with fill color.

- `w()` or `w(wid)` changes the line width of the following lines to `wid` or to the value of the `line_width` constant by default.
`w(wid)` works as the `line_width` constant but it affects anly the following lines instead of being global.

Color and line width changes won't be visible while filling, so they are not recommended under filling.

- `P` to start delimiting a figure to fill. `P(r, g, b)` and `P(r, g, b, a)` is also valid and works as l but just for the current fill.
- `p` to end delimiting the figure.

It is not possible to fill two figures if one contains another in the string. This is, every `P` must be followed by a `p` before branch end or another `P`, and there must not be a `p` without a `P` before. They work in the same branch, not in children nor in parent, and if you start a branch while filling, the new branch won't be filled.

- `Z` to close the current path.
Paths are continuous until a color or line width change or a `P`, `p` or `Z` is found.

- `c`, `c()` and `c(r)` draws a circle of centre the current position and of radius `r` or `1.0` by default. This command does not end the current path.

- `q` starts a quadratic bezier curve. It uses the next two points to define the curve, ending in the second one.
- `t` works as `q` but is always defined just after `q` and uses its last point for the first point, so `t` only requires to define one point.
- `z` starts a cubic bezier curve. It uses the next three points to define the curve, ending in the third one.
- `s` works as `z` but is always defined just after `z` and uses its last point for the first point, so `s` only requires to define two points.

The rest of the characters will be ignored when displaying.

## SVG

`lsys` with the option `--svg` converts the result of the L-system to SVG. If you want to see your image while creating it you can use ImageMagick's `display`:

```
lsys examples/B2.lsd --svg - | display
```

If you want to convert a SVG file into a PNG file, you can use inkscape:

```
inkscape -o test.png -w 1000 -b white test.svg
```

## Next steps

- Documentation
- Manage pointers (destructors and deletes)
- Capture all LSDL syntax errors and expression evaluation errors
- Debug, unit testing
- Parameters
- Action symbols
- Make it a deb package?
- Compile in windows?
- Threads?
- Run in a web page
- 3D representation and model export?
- Music representation?
- Optimize expressions (getting rid of strings and transforming trivial expressions into values)

