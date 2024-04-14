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

## 1

没看懂题目, 假定 $p + q = 1$ 并且要么向左要么向右:

$$
\mathbb{P(S_n = 2x - n)} = \begin{cases}
    {n \choose x } p^x q^{n-x}   & x \in [0, n], x \in \mathbb{Z} \\
    0 & \text{otherwise}
\end{cases}
$$

如果是 $p$ 向左和 $q$ 向右无关. 那么向左 $x$ 即为 $x+y$ 向左, 向右$y$. 所以:

$$
\mathbb{P}(S_n = x) = \begin{cases}
    \sum_{y = 0}^{n - x} {n \choose y + x} p^{y + x} (1 - p)^{n - x - y} {n \choose y}  q ^ y (1 - q)^{n - y} & x \in [0, n] \\
    \sum_{y = 0}^{n + x} {n \choose y - x} q^{y - x} (1 - q)^{n + x - y} {n \choose y}  p ^ y (1 - p)^{n - y} & x \in [-n, 0] \\
    0 & \text{otherwise}
\end{cases}
$$

这个函数看起来不能再化简了, 但是在 $p + q = 1$ 的时候, 借助卷积公式, 可得:

$$
\mathbb{P}(S_n = x) \begin{cases}
    {2n \choose n - x} p^{n + x} q^{n - x} & x \in [-n, n] \\
    0 & \text{otherwise}
\end{cases}
$$

## 2

$$
\mathbb{P}(\xi = x) = p^x q + q^x p
$$

## 3

$$
1, \frac 1 {e ^{\lambda x} - 1}
$$

## 12

$$
F(x,y) = \begin{cases}
    1 & x + y \gt 0 \\
    0 & x + y \leq 0
\end{cases}
$$

令 $F_y(x) = F(x, y)$, 则:

$$
F_y(x) = \begin{cases}
    1 & x \gt -y \\
    0 & x \leq -y
\end{cases}
$$

显然单调不减, 且在 $x = -y$ 处显然左连续. 对于 $F_x(y)$ 同理.

但是, 考虑 $[-1,3] \times [-1,3]$. 式 $(3.2.5)$:

$$
F(3,3) - F(3,-1) - F(-1,3) + F(-1,-1) = 1 - 1 - 1 + 0 = -1
$$

## 13

由分布密度的充要条件:

$$
\begin{aligned}
f(x,y) = f_1(x)f_2(y) + h(x,y) \ge 0
&\Leftrightarrow h(x,y) \ge -f_1(x)f_2(y) \\
\int\int f(x,y) \, \mathrm{d}x \, \mathrm{d}y = 1
&\Leftrightarrow \int\int h(x,y) \, \mathrm{d}x \, \mathrm{d}y = 0
\end{aligned}
$$

## 14

$$
\begin{aligned}
f_{\alpha}(x_1,x_2,x_3)
& = \prod_{i=1}^3 f_i(x_i) \cdot \bigg(1 + \alpha \prod_{i=1}^3 (2F_i(x_i) - 1)\bigg) \\
&\ge (1 - |\alpha|) \prod_{i=1}^3 f_i(x_i) \\
&\ge 0
\end{aligned}
$$

$$
\begin{aligned}
\int\int\int f_{\alpha}(x_1,x_2,x_3) \, \mathrm{d}x_1 \, \mathrm{d}x_2 \, \mathrm{d}x_3
& = \int\int\int \prod_{i=1}^3 f_i(x_i) \, \mathrm{d}x_1 \, \mathrm{d}x_2 \, \mathrm{d}x_3 \\
& + \alpha \int\int\int \prod_{i=1}^3 f_i(x_i) \cdot \prod_{i=1}^3 (2F_i(x_i) - 1) \, \mathrm{d}x_1 \, \mathrm{d}x_2 \, \mathrm{d}x_3 \\
& = 1 + \alpha \prod_{i=1}^3 \int f_i(x) (2F_i(x) - 1) \, \mathrm{d}x \\
& = 1 + \alpha \prod_{i=1}^3 (F(x)^2 - F(x)) \bigg|_{-\infty}^{\infty} \\
& = 1 + 0 = 1
\end{aligned}
$$

$$
\begin{aligned}
\int\int f_{\alpha}(x_1,x_2,x_3) \, \mathrm{d}x_2 \, \mathrm{d}x_3
& = \int\int \prod_{i=1}^3 f_i(x_i) \, \mathrm{d}x_2 \, \mathrm{d}x_3 \\
& + \alpha \int\int \prod_{i=1}^3 f_i(x_i) \cdot \prod_{i=1}^3 (2F_i(x_i) - 1) \, \mathrm{d}x_2 \, \mathrm{d}x_3 \\
&= f_1(x_1) + \alpha f_1(x_1) (2F_1(x) - 1) \int f_2(x) (2F_2(x) - 1) \, \mathrm{d}x_2 \, \int f_3(x) (2F_3(x) - 1) \, \mathrm{d}x_3 \\
&= f_1(x_1) + 0 ~~~\ (\text{过程类似前一个证明,两个定积分为 0}) \\
&= f_1(x_1)
\end{aligned}
$$
