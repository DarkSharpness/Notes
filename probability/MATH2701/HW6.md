# HW6

## 14

由定义, $P(A)P(B) = P(AB)$. 因此:

$$P(A~\varnothing) = 0 = P(A)P(\varnothing) $$

$$P(A\bar{B}) = P(A) - P(AB) = P(A) (1 - P(B)) = P(A)P(\bar(B))$$

$$P(A~\Omega) = P(A) = P(A) P(\Omega)$$

其他同理可得.

## 15

### 1

$P(A | B) = \frac{P(AB)}{P(B)} = \frac{P(A) - P(A \bar{B})}{1 - P(\bar{B})}$

当 $P(A | B) = P (A | \bar{B})$.

可得: $P(A | B) = P(A)$ 即 $P(AB) = P(A)P(B)$ 即独立.

同理, 当独立的时候有 $P(A|B) = P(A)$, 因此 $P(A|B) = \frac{P(A \bar{B})}{P(\bar{B})} = P(A | \bar{B})$$.

### 2

$$
\begin{aligned}
& P(A | B) + P(\bar{A} | \bar{B}) = 1 \\ \Leftrightarrow ~\
& P(A | B) = 1 - P(\bar{A} | \bar{B}) = P(A | \bar{B})
\end{aligned}
$$

等价于 $1$.

## 17

由于 $P(A) = P(B) = P(C)$ 且相互独立, 可得:

$$
\begin{aligned}
P(A)
&= \frac{1}{3}(P(A \cup B \cup C) + 3 P(A) ^ 2 - P(ABC)) \\
&= \frac{1}{3}(\frac {9}{16} + 3 P(A) ^ 2)
\end{aligned}
$$

解得: $P(A) = \frac 1 4$ (舍负).

## 18

### 1

$$
\begin{aligned}
P((A \cup B) C)
&= P(AC \cup BC) \\
&= P(AC) + P(BC) - P(ACBC) \\
&= P(C)(P(A) + P(B) - P(AB)) \\
&= P(C)P(A \cup B) \\
P((A - B)C)
&= P(AC - BC) \\
&= P(AC) - P(ACBC) \\
&= P(A)P(C)(1 - P(B)) \\
&= (P(A) - P(AB))P(C) \\
&= P(A - B)P(C) \\
P(ABC) &= P(A)P(B)P(C) = P(AB)P(C) \\
\end{aligned}
$$

### 2

两两独立由 $14$ 可知. 三者独立即:

$$
\begin{aligned}
P(\bar A \bar B \bar C)
&= 1 - P(A \cup B \cup C) \\
&= 1 - (P(A) + P(B) + P(C) - P(AB) - P(AC) - P(BC) + P(ABC)) \\
&= 1 - P(A) - P(B) - P(C) + P(A)P(B) + P(A)P(C) + P(B)P(C) - P(A)P(B)P(C) \\
&= (1 - P(A))(1 - P(B))(1 - P(C)) \\
&= P(\bar A)P(\bar B)P(\bar C) \\
\end{aligned}
$$

## 20

$$
1 - (1 - 0.4)(1 - 0.5)(1 - 0.7) = 0.91
$$

## 24

$$
(\frac{1}{3}) ^ 3 + (\frac{1}{3}) ^ 4 \cdot 3 = \frac {2}{27}
$$

## 25

$$ 1 - \frac{1}{2^{2n}}, \frac{2n \choose n}{2^{2n}} $$
