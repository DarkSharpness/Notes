# T1

$w = 0$ 的情况已在课上证. 现在证明 $w \ne 0 $ 的情况. 已知 $T(n) = a T(n/b) + n^d \log^w n$. 不妨假设 $n = b^k$. 令 $c = \frac {a}{b^d}$ 则:

$$
\begin{aligned}
T(n) &= n^d \log^w n + a(n / b)^d \log^w (n / b) + a^2(n / b^2)^d \log^w (n / b^2) + \cdots + a^k(n / b^k)^d \log^w (n / b^k) \\
&= n^{d} (\log b) ^ w [ k^w + c \cdot (k-1)^w + \cdots + c^k \cdot 0^w ] \\
\end{aligned}
$$

## case 1

当 $a \lt b^d$ 即 $c \lt 1$ 时:

$$
\begin{aligned}
T(n) &\lt n^d (\log b)^w k^w \frac 1 {1-c} \\
&= \frac 1 {1 - c} n^d (\log n)^w \\
\end{aligned}
$$

因此, $T(n) = \mathcal{O}(n^d \log^w n)$.

## case 2

当 $a \gt b^d$ 即 $c \gt 1$ 时:

$$
T(n) = n^d (\log b)^w c^k [ 0^w + \frac 1 c \cdot 1^w + \cdots + \frac 1 {c^{k-1}} \cdot (k-1)^w + \frac 1 {c^k} \cdot k^w ] \\
$$

考虑数列 $x_n = \frac 1 {c^n} n^w > 0$. 注意到

$$
\lim_{n\rightarrow \infty} \frac {x_{n+1}}{x_n} = \frac{1}{c} \lt 1
$$

所以由 Abel 定理, $\sum {x_n}$ 收敛. 故存在常数 $C$ 使得:

$$
\lim_{n\rightarrow \infty} \sum_{i=0}^n {x_i} = C
$$

所以有:

$$
\begin{aligned}
T(n) &= n^d (\log b)^w c^k [ 0^w + \frac 1 c \cdot 1^w + \cdots + \frac 1 {c^{k-1}} \cdot (k-1)^w + \frac 1 {c^k} \cdot k^w ] \\
&= n^d (\log b)^w c^k ~\sum_{i=0}^k {x_i} \\
&\lt n^d (\log b)^w c^kC \\
&= C(\log b)^w n^d c^{\log_b n} \\
&= C(\log b)^w n^d n^{\log_b c} \\
&= C(\log b)^w n^d n^{\log_b a - d} \\
&= C(\log b)^w n^{\log_b a} \\
\end{aligned}
$$

前面的 $C(\log b)^w$ 是常数, 所以 $T(n) = \mathcal{O}(n^{\log_b a})$.

## case 3

当 $a = b^d$ 即 $c = 1$ 时, 有:

$$
\begin{aligned}
T(n) &= n^d (\log b)^w (k^w + (k-1)^w + \cdots + 1^w + 0^w) \\
&\lt n^d (\log b)^w (k^w + k^w + \cdots + k^w + k^w) \\
&= n^d (\log b)^w k^{w + 1} \\
&= \frac 1 {\log b} n^d (\log n)^{w + 1} \\  
\end{aligned}
$$

所以, 此时 $T(n) = \mathcal{O}(n^d \log^{w+1} n)$.

# T2

## a

## b

# T3

注: 求第二大和第二小本质一样, 下面只讨论第二小的情况.

首先执行 `find_min` 算法:

- 对于长度为 $1$ 的区间, 直接返回唯一元素.
- 对于长度为 $n$ 的区间, 分别对前一半和后一半的区间调用 `find_min` 算法, 得到两个值 $a,b$ , 然后比较一次, 返回较小的那个 $\min(a,b)$. 同时, 记录比较结果以及两个最小值.

然后执行 `find_sec` 算法:

- 对于长度为 $2$ 的区间, 直接返回较大的那个元素. (利用之前的 `find_min` 的比较结果)
- 对于长度为 $n$ 的区间, 根据之前的比较结果, 得到前一半的最小值 $a$ 和 后一半的最小值 $b$. 如果 $a \le b$, 则对前一半的区间调用 `find_sec` 算法, 得到 $c$, 然后比较一次, 返回 $\min(c, b)$. 否则, 对后一半的区间调用 `find_sec` 算法, 得到 $c$, 然后比较一次, 返回 $\min(c, a)$.

C++ 代码如下:

```C++
int N; // Number of elements.

// Compare
bool cmp(value_t __a, value_t __b) { return __a < __b; }

struct answer_type {
    value_t lmin;
    value_t rmin;
    bool result;
} data[N]; // Hold the result of each range.

// Return the unique index of a range, not important.
size_t get_num(size_t __l, size_t __len) {
    return (__l + N) / __len - 1;
}

// Find the min and keep track of the result.
value_t find_min(value_t *__arr, size_t __l, size_t __len) {
    if (__len == 1) return __arr[__l];
    auto __r = __l + __len / 2;
    auto __a = find_min(__arr, __l, __len / 2);
    auto __b = find_min(__arr, __r, __len / 2);
    bool __cmp = cmp(__a, __b);
    // Store the result.
    data[get_num(__l, __len)] = {__a, __b, __cmp};
    // Return the min.
    return __cmp ? __a : __b;   
}

// Find the second min after finding min.
value_t find_sec(value_t *__arr, size_t __l, size_t __len) {
    auto [__a, __b, __cmp] = data[get_num(__l, __len)];
    // Special judge.
    if (__len == 2) return __cmp ? __b : __a;
    if (__cmp) { // Left min < Right min
        auto __c = find_sec(__arr, __l, __len / 2);
        return cmp(__c, __b) ? __c : __b;
    } else { // Left min > Right min
        auto __r = __l + __len / 2;
        auto __c = find_sec(__arr, __r, __len / 2);
        return cmp(__c, __a) ? __c : __a;
    }
}

void my_algorithm(value_t *__arr) {
    auto __min = find_min(__arr, 0, N);
    auto __sec = find_sec(__arr, 0, N);
    std::cout << "Min: " << __min << " Second: " << __sec << std::endl;
    std::cout << "Counter: " << counter << std::endl;
}
```

当 $N = 2^k,~ k\ge 1$ 时 以上这个算法可以同时求出最小值和第二小的值.

[Check it out online!](https://godbolt.org/z/5vTKWEsE5)

## 复杂度 (Compare 次数)

### find_min

在程序中, 表现为 cmp 函数的调用次数. 在 `find_min` 函数中, 假设处理一个长度为 $n$ 的区间的最小值需要 $T(n)$ 次比较. 那么，首先, 当 $n = 1$ 时, 不需要比较, 所以 $T(1) = 0$. 当 $n \gt 1$ 时, 假设 $n = 2^k$, 则根据算法, 我们对前一半的区间和后一半的区间分别调用 `find_min` , 递归下去的 `find_min` 中 $n$ 减半, 所以有:

$$
T(n) = 2T(n/2) + 1 = 4T(n/4) + 2 + 1 = \cdots = 2^kT(1) + (2^k - 1) = n - 1
$$

一共需要 $n - 1$ 次比较.

### find_sec

然后分析 `find_sec` 函数. 在 `find_sec` 函数中, 假设处理一个长度为 $n$ 的区间的第二小的值需要 $S(n)$ 次比较. 那么, 首先, 当 $n = 2$ 时, 不需要比较, 所以 $S(2) = 0$. 当 $n \gt 2$ 时, 假设 $n = 2^k$, 则根据算法, 我们只会调用恰好一次 `find_sec` , 且递归下去的 `find_sec` 中 $n$ 减半, 所以有:

$$
S(n) = S(n/2) + 1 = S(n/4) + 1 + 1 = \cdots = S(2) + \log_2 n - 1 = \log_2 n - 1
$$

所以, 整个算法调用比较函数一共 $n - 1 + \log_2 n - 1 = n + \log_2 n - 2$ 次. 不超过 $n + \log_2 n$ 次.

## 正确性

### min

比较一次返回两者的最小值, 显然正确...

### find_min

首先分析 `find_min` 的正确性. 我们使用归纳法.

当 $n = 1$ 时, 仅一个元素, 显然正确.

当 $n = 2 ^ k,~ k \gt 0$ 时, 假设对于 $k - 1$ 已经正确. 设全集为 $S$. 设前 $\frac n 2$ 个元素的集合为 $A$, 由归纳假设, 求出最小值为 $a$ ; 设后 $\frac n 2$ 个元素的集合为 $B$, 由归纳假设, 求出最小值为 $b$ .

此时, 由定义, $\forall x \in A$, 有 $x \ge a$, $\forall y \in B$, 有 $y \ge b$. 且由定义, $A + B = S$. 因此, $\forall x \in A \cup B = S, \min(a, b) \le x$. 所以, 返回的 $\min(a, b)$ 是 $S$ 的最小值.

因此, 由归纳法, `find_min` 的正确性得证.

### find_sec

然后分析 `find_sec` 的正确性. 我们使用归纳法.

当 $n = 2$ 时, 仅两个元素, 我们直接使用之前比较的结果, 返回较大的那个, 显然正确.

当 $n = 2 ^k,~ k \gt 1$ 时, 假设对于 $k - 1$ 已经正确. 设全集为 $S$. 设前 $\frac n 2$ 个元素的序列为 $A$, 由归纳假设, 求出最小值为 $a$ ; 设后 $\frac n 2$ 个元素的的序列为 $B$, 由归纳假设, 求出最小值为 $b$.

简单起见, 不妨假设 $a \le b$. 由归纳假设, 我们可以求出 $A$ 中的次小值 $c$. 此时, 我们比较 $c$ 和 $b$.

- 如果 $c \le b$, 那么 $\forall x \in B, c \le b \le x$. 又因为 $c$ 是 $A$ 的次小值, 所以返回的 $c$ 也是 $A + B = S$ 的次小值. 正确性得证.
- 如果 $c \ge b$, 那么在 $A$ 除去 $a$ 之后 (如果有多个重复相同, 只去除一个), 记这个新的集合为 $C$ ,则 $\forall x \in C, b \le c \le x$. 而又因为 $b$ 为 $B$ 中最小值, 所以 $b$ 是 $C + B$ 中的最小值, 且 $a \le b$. 因此在 $C + B + \{a\}$ 中, 返回的 $b$ 是次小值. 正确性得证.

可以看出无论如何, 此时返回的 $\min(c,b)$ 是当前这个区间的次小值.

$a \gt b$ 的时候同理. 由归纳法, `find_sec` 的正确性得证.
