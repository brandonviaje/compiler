
# SEMP Context-Free Grammar 

This grammar is designed to be **LL(1)** compatible, meaning it is specifically structured for a **Recursive Descent Parser** by eliminating left-recursion.

**Start Symbol**: Program

**Nonterminals**: Program, Stmt, StmtList, Block, Expr, E, E', T, T', F, Literal

**Terminals**:

$$
\begin{aligned}
\text{ret} &\rightarrow \_RETURN \\
\{,\} &\rightarrow \_LEFT\_BRACE, \_RIGHT\_BRACE \\
; &\rightarrow \_SEMICOLON \\
(,) &\rightarrow \_LEFT\_PAREN, \_RIGHT\_PAREN \\
+, * &\rightarrow \_PLUS, \_STAR \\
\text{id} &\rightarrow \_IDENTIFIER \\
\text{number} &\rightarrow \_INT\_LITERAL \\
\text{string} &\rightarrow \_STR\_LITERAL \\
\text{EOF} &\rightarrow \_EOF
\end{aligned}
$$

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
