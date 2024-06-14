# HW8

$$
\newcommand \dx{\mathrm{d}x}
\newcommand \dy{\mathrm{d}y}
$$

## 15

### 15.1

由题, $a + 0.2 + 0 + c = 0.4$, $\frac {a + 0 + 0.1 + b} {a + 0 + 0.1 + b + 0 + 0.2} = \frac{2}{3}$, $a + 0 + 0.2 + 0.1 + b + 0.1 + 0 + 0.2 + c = 1$. 解得 $a = 0.1, b = 0.2, c = 0.1$.

### 15.2

$\xi(-1) = a + 0.1 + 0 = 0.2$,
$\xi(0) = 0 + b + 0.2 = 0.4$,
$\xi(1) = 0.2 + 0.1 + c = 0.4$,

$\eta(-1) = a + 0 + 0.2 = 0.3$,
$\eta(0) = 0.1 + b + 0.1 = 0.4$,
$\eta(1) = 0 + 0.2 + c = 0.3$.

### 15.3

$(\xi+\eta)(-2) = a = 0.1$,
$(\xi+\eta)(-1) = 0 + 0.1 = 0.1$,
$(\xi+\eta)(0) = 0 + b + 0.2 = 0.4$,
$(\xi+\eta)(1) = 0.2 + 0.1 = 0.3$,
$(\xi+\eta)(2) = c = 0.1$.

## 16

### 16.1

归一化:

$$
\int_{0}^{+\infty}\int_{0}^{+\infty}A\exp(-2x-y)\dx\dy = 1
$$
可得 $A = 2$

### 16.2

$$
P\{\xi \lt 2, \eta \lt 1\} = \int_{0}^{2}\int_{0}^{1} A\exp(-2x-y)\dx\dy = (1-\exp(-4))(1 - \exp(-1))
$$

### 16.3

$$
\begin{aligned}
p(x) &= \int_{y=0}^{+\infty}p(x,y)dy \\
&= \begin{cases}
    0, &x \le 0 \\
    2\exp(-2x), &x\gt 0
    \end{cases}
\end{aligned}
$$

### 16.4

$$
\begin{aligned}
P\{\xi + \eta \lt 2 \}
&= \int_{x = 0}^{2}\int_{y=0}^{2-x}A\exp(-2x-y)\dx\dy \\
&= 1 - \exp(-4) - 2(\exp(-2) - \exp(-4)) \\
&= 1 - 2\exp(-2) + \exp(-4)\\
&= (1 - \exp(-2))^2
\end{aligned}
$$

### 16.5

$$
p(x|y) ~ p(y) = p(x,y)
$$

因此, 我们可以得出:
$$
p(x | y) = \begin{cases}
0, & x\le 0 \\
2\exp(-2x), & x \gt 0
\end{cases}
$$

### 16.6

$$
\begin{aligned}
P\{\xi \lt 2 | \eta \lt 1\}
& = \frac {P\{ \xi \lt 2, \eta \lt 1 \}}{P(\eta \lt 1)} \\
& = \frac {(1 - \exp(-4))(1 - \exp(-1))} {1 - \exp(-1)} \\
& = 1 - \exp(-4)
\end{aligned}
$$

## 17

先化简原式:
$$
\begin{aligned}
P\{\mu=m, \nu=\}
& = \frac{(\lambda p)^m (\lambda- \lambda p)^{n-m}}{m!(n-m)!} \exp(-\lambda)\\
& = \frac{\lambda^n p^m (1-p)^{n-m} {n \choose m} }{n!} \exp(-\lambda)
\end{aligned}
$$

### 17.1

$$
\begin{aligned}
P\{\nu=n\}
& = \sum_{n = n \wedge m \in [0,n]} \frac{\lambda^n p^m (1-p)^{n-m} {n \choose m} }{n!} \exp(-\lambda)\\
& = \sum_{n = n} \frac{\lambda^n}{n!}\exp(-\lambda) \\
& = \frac{\lambda^n}{n!}\exp(-\lambda)
\end{aligned}
$$

### 17.2

$$
\begin{aligned}
P\{\mu = m\}
& =\sum_{n \in [m, +\infty)} \frac{\lambda^n p^m (1-p)^{n-m} {n \choose m} }{n!} \exp(-\lambda)\\
& = \frac{\lambda^m p^m}{m!} \exp(-\lambda)
\sum_{n\in[m,\infty)} \frac{(\lambda(1-p))^{n-m}}{(n-m)!}\\
& = \frac{\lambda^m p^m}{m!} \exp(-\lambda) \exp(\lambda(1-p)) \\
& = \frac{(\lambda p)^m}{m!} \exp(-\lambda p)
\end{aligned}
$$

### 17.3

$$
P\{\mu=m | \nu=n\} = \frac { P(m,n) } {P\{\nu = n\}} = {n \choose m} p^m (1-p)^{n-m}
$$

### 17.4

$$
\begin{aligned}
P\{\nu - \mu = k\}
&= \sum_{n - m = k} \frac{(\lambda p)^m (\lambda- \lambda p)^{n-m}}{m!(n-m)!} \exp(-\lambda) \\
&= \frac{\lambda^k (1 - p)^k}{k!} \exp(-\lambda) \sum_{m \in [0, +\infty)} \frac{\lambda^m p^m}{m!} \\
&= \frac{\lambda^k (1 - p)^k}{k!} \exp(-\lambda) \exp(\lambda p) \\
&= \frac{\lambda^k (1 - p)^k}{k!} \exp(-\lambda (1-p))
\end{aligned}
$$

## 20

### 20.1

$$
f_{\xi}(x) = 2x (x \in [0,1]) \\
f_{\eta}(y) = 2y (y \in [0,1]) \\
f(x,y) = 4xy = f_{\xi}(x) \cdot f_{\eta}(y)
$$

独立。

### 20.2

$$
g_{\xi}(x) = 4x(1 - x^2) (x \in [0,1]) \\
g_{\eta}(y) = 4y^3 (y \in [0,1]) \\
g(x,y) = 8xy \ne g_{\xi}(x) \cdot g_{\eta}(y)
$$

不独立。

## 22

$$
p_{\xi}(x) = p_{\eta}(y)= \frac{1}{2} \\
p(x,y) = \frac{1 + xy}{4} \ne p_{\xi}(x) \cdot p_{\eta}(y) \\
$$

所以不独立，但是考虑 $x^2$ 和 $y^2$ 的概率。
$$
p\{x^2 \lt a\} = \frac 1 2 \sqrt{a} \\
p\{y^2 \lt b\} = \frac 1 2 \sqrt{b} \\
p\{x^2\lt a, y^2 \lt b\} = \frac 1 4 \sqrt{ab} = p\{x^2 \lt a\} \cdot p\{y^2 \lt b\}
$$
因此，独立。

## 23

### 23.1

$$
p(\mu_1 = k_1, \mu_2 = k_2) = \frac{n!}{k_1! k_2! k_3!}{p_1}^{k_1}{p_2}^{k_2}{p_3}^{k_3} \\
(\text{where} ~ k_3 = n - k_1 - k_2)
$$

### 23.2

$$
p(\mu_1 = k_1) = \frac{n!}{k_1! (n - k_1)!}{p_1}^{k_1}(1 - p_1)^{n - k_1}
$$

### 23.3

$$
\begin{aligned}
p(\mu_2 = k_2 | \mu_1 = k_1)
&= \frac {p(\mu_2 = k_2 , \mu_1 = k_1)}{p(\mu_1 = k_1)} \\
&= \frac {(k_2 + k_3)!}{k_2! k_3!} (\frac{p_2}{p_2 + p_3})^{k_2} (\frac{p_3}{p_2 + p_3})^{k_3} \\
(\text{where} ~ {k_3 = n - k_1 - k_2})
\end{aligned}
$$

## 24

> Remark: 过程太多了, 简单的题后面只敲答案了.......

### 24.1

$$
\frac{{N_1 \choose n_1}{N_2 \choose n_2}{N_3 \choose n_3}}{N \choose n}
$$

### 24.2

$$
\frac{{N_1 \choose n_1}{N-N_1 \choose n-n_1}}{N \choose n}
$$

### 24.3

$$
\frac{{N_2 \choose n_2}{N_3 \choose n_3}}{N_2 + N_3 \choose n_2 + n_3}
$$

## 25

### 25.1

$$
\begin{aligned}
P\{\xi_1 + \xi_2 = k\}
& = \sum_{n = 0}^{k}{n_1 \choose n}{n_2 \choose k - n}p^{n}(1-p)^{n_1 - n}p^{k-n}(1-p)^{n_2 - n + k} \\
& = p^k (1-p)^{n_1 + n_2 - k} \sum_{n=0}^k{n_1 \choose n}{n_2 \choose k-n} \\
& = p^k (1-p)^{n_1 + n_2 - k} {n_1 + n_2 \choose k}
\end{aligned}
$$

因此得证。

### 25.2

$$
P\{\xi_1=k | \xi_1 + \xi_2=n\} = \frac{P\{\xi_1=k\}}{P\{\xi_1 + \xi_2=n\}}
= \frac {{n_1 \choose k}{n_2 \choose n - k}}{n_1 + n_2 \choose n}
$$

## 26

### 26.1

$$
\begin{aligned}
P\{\xi_1 + \xi_2 = k\}
& = \exp(-\lambda_1 - \lambda_2) \sum_{n = 0}^{k}\frac{\lambda_1^n \lambda_2^{k-n} }{n!(k - n)!} \\
& = \exp(-\lambda_1 - \lambda_2) \frac{(\lambda_1 + \lambda_2)^k}{k!}
\end{aligned}
$$

### 26.2

$$
P\{\xi_1=k | \xi_1 + \xi_2=n\} = \frac{P\{\xi_1=k\}}{P\{\xi_1 + \xi_2=n\}}
= \frac{{\lambda_1}^k{\lambda_2}^{n-k}}{(\lambda_1 + \lambda_2)^n} \frac{n!}{(n-k)!k!}
$$

再化简后，该式即为所求。
