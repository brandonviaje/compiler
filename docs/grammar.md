
# SEMP Context-Free Grammar 

This grammar is designed to be **LL(1)** compatible, meaning it is specifically structured for a **Recursive Descent Parser** by eliminating left-recursion.

**Start Symbol**: `Program`

**Nonterminals**: `Program`, `Stmt`, `StmtList`, `Block`, `Expr`, `E,` `E'`, `T`, `T'`, `F`, `Literal`

**Terminals**:

| Token     | Maps to                      |
|-----------|------------------------------|
| ret       | _RETURN                      |
| { , }     | _LEFT_BRACE, _RIGHT_BRACE    |
| ;         | _SEMICOLON                   |
| ( , )     | _LEFT_PAREN, _RIGHT_PAREN    |
| + , *     | _PLUS, _STAR                 |
| id        | _IDENTIFIER                  |
| number    | _INT_LITERAL                 |
| string    | _STR_LITERAL                 |
| EOF       | _EOF                         |

# Program Structure
$$
Program \rightarrow StmtList\ \text{EOF}
$$

# Statements & Blocks
$$
\begin{aligned}
StmtList &\rightarrow Stmt\ StmtList \mid \varepsilon \\
Stmt &\rightarrow \text{ret Expr ;} \\
Stmt &\rightarrow Block \\
Block &\rightarrow \{ StmtList \}
\end{aligned}
$$


# Expressions
$$
\begin{aligned}
Expr &\rightarrow E \\
E  &\rightarrow T\ E' \\
E' &\rightarrow +\ T\ E' \mid \varepsilon \\
T  &\rightarrow F\ T' \\
T' &\rightarrow *\ F\ T' \mid \varepsilon \\
F  &\rightarrow (E) \mid \text{id} \mid \text{Literal}
\end{aligned}
$$

# Literals

$$
Literal \rightarrow \text{number} \mid \text{string}
$$
