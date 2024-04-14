# HW 7

## Extra-1

### 1

设 $X$ 是随机变量, 则对于任意 $x \in \mathbb{R}$, 有

$$
\{X \leq x\} \in \mathcal{F} \\
\{|X| \leq x\} = \{X \leq x\} \cup \{X \geq -x\}
$$

由 $\sigma$ 代数的性质, 因为 $\forall x \in \mathbb{R}$, $\{X \leq x\} \in \mathcal{F}$, 所以 $\{|X| \geq x\} \in \mathcal{F}$, 所以可推得 $|X|$ 是随机变量.

### 2

反例:

$$
\Omega = \{0, 1\}, \mathcal{F} = \{\Omega, \varnothing\}, X(0) = 1, X(1) = -1
$$

定义随机变量 $X$ 如下:

$$
{|X| \leq x} = \begin{cases}
    \varnothing &   x \lt 1 \\
    \Omega      &   x \ge 1 \\
\end{cases}
$$

但是, $\{X \leq 0\} = \{0\} \notin \mathcal{F}$, 所以 $|X|$ 不是随机变量.

## Extra-2

$$
\begin{aligned}
G(x-)
& = \lim_{y \to x} \mathbb{P}(X \lt y) \\
& = \cup_{n=1}^{\infty} \{X \lt x - \frac{1}{n}\} \\
& = \{\omega | X(\omega) \lt  \cup_{n=1}^{\infty} (-\infty, x - \frac{1}{n})\} \\
& = \{\omega | X(\omega) \lt x\} \\
& = \mathbb{P}(X \lt x) \\
& = G(x)
\end{aligned}
$$

右极限为:

$$
\begin{aligned}
G(x+)
& = \lim_{y \to x} \mathbb{P}(X \leq y) \\
& = \cup_{n=1}^{\infty} \{X \leq x - \frac{1}{n}\} \\
& = \{\omega | X(\omega) \leq  \cup_{n=1}^{\infty} (-\infty, x - \frac{1}{n})\} \\
& = \{\omega | X(\omega) \leq x\} \\
& = \mathbb{P}(X \leq x) \\
\end{aligned}
$$

其意义是即为小于等于 $x$ 的概率.
