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

假设选中 pivot 使得左边和右边最多的一边不超过 $\frac 2 3$, 那么, 选中的元素的大小应该落在原数组大小的中间 $\frac 1 3$ 处 (即不能是前后 $\frac 1 3$). 由于是均等随机的选取, 所以每次选中的概率是 $\frac 1 3$. 因此, 期望下, 两次(即常数次) 即可使得左右两边的大小不超过 $\frac 2 3$. 

因此, $T(n) = 2T(\frac 2 3 n) + cn$. 根据主定理, $T(n) = \mathcal{O}(n^ d)$ 其中 $d = \log_{\frac 3 2} 2 \approx 1.7095$.

## b

首先, 对于第 $i$ 小和 第 $j$ 小的元素 $x_i$ 和 $x_j$ , 只有当 $x_i$ 或 $x_j$ 是 $x_i,x_{i+1},\cdots,x_j$ 中第一个被选中的 pivot 时, 才会贡献一次比较. 而由于是均等随机, 所以这个概率是 $\frac 2 {j - i + 1}$. 因此, 期望比较次数为:

$$
\begin{aligned}
&\sum_{i=1}^{n-1}\sum_{j=i+1}^n \frac 2 {j - i + 1} \\
= & \sum_{i=1}^{n-1}\sum_{k=2}^{n-i+1} \frac 2 k \\
\lt & \int_{0}^{n} \int_{1}^{n+1} \frac 2 k \, dk \, dx \\
= & ~2n \ln (n + 1) \\
= & ~\mathcal{O}(n \log n) \\
\end{aligned}
$$

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

# T4

## a

我们假设这个算法叫做 `divide(l,r)` 表示分治求出 $[l,r]$ 区间的局部最小值. 设原数组为 $a[1], a[2], \cdots, a[n]$.

执行步骤如下:

- 首先, 检查长度 $p$. 如果 $p \le 2 $ 直接枚举每个数比较即可.
- 否则, 先检测两端. 如果 $a[1] \lt a[2]$ , 则 $a[1]$ 是局部最小值. 如果 $a[p] \lt a[p-1]$ , 则 $a[p[$ 是局部最小值. 否则, 转入函数 `divide(1,p)`

函数 `divide(l,r)` 的执行步骤如下:

- 如果 $r - l = 2$ 则找到了 $a[l + 1]$ 是局部最小值.
- 否则, 令 $m = \lfloor \frac {l + r} 2 \rfloor$ , 检查 $a[m-1], a[m], a[m+1]$ 三个数的大小关系:
  + 如果 $a[m] \lt a[m-1]$ 且 $a[m] \lt a[m+1]$ , 则 $a[m]$ 是局部最小值.
  + 如果 $a[m -1] \lt a[m] \lt a[m+1]$ , 则转入 `divide(l,m)` .
  + 如果 $a[m-1] \gt a[m] \gt a[m+1]$ , 则转入 `divide(m,r)` .

时间复杂度: 在 `divide(l,r)` 的过程中, 我们至多执行常数 $c$ 次的额外操作, 再额外执行一次 `divide(l,m)` 或 `divide(m,r)`. 假设 $n = r - l$ , 递归下去的 `divide` 的长度不超过 $\frac n 2 + 1$. 所以有 $T(n) = T(\frac n 2 + 1) + c$ (特别地, 当 $n = 2$ 时, 终止 $T(2) = \mathcal{O}(1)$). 根据主定理, $T(n) = \mathcal{O}(\log n)$.

正确性: 在 `divide(l,r)` 函数执行时, 我们总是会保证 $a[l] \gt a[l + 1]$ 且 $a[r] \gt a[r - 1]$. 这是因为我们传入的时候, 其天然满足这个性质. 除此之外, 在递归调用的时候, 假设每次传入的参数都是符合这个性质的, 如果调用的是 `divide(l,m)` , 那么 $a[m-1] \lt a[m]$ (分支条件) 且 $a[l] \gt a[l + 1]$ (归纳假设) ; 如果调用的是 `divide(m,r)` 则同理.

因此, 在 `divide(l,r)` 函数执行时, 我们总是会保证 $a[l] \gt a[l + 1]$ 且 $a[r] \gt a[r - 1]$. 因此, 在递归终止条件 $r - l = 2$ 的时候, 有 $a[l] \gt a[l + 1] \lt a[l + 2] = a[r]$. 所以, $a[l + 1]$ 是局部最小值.

特别地, 我们需要额外证明递归不会递归到 $r - l = 2$ 以外的情况 (即死递归). 首先, 由于我们特判了长度 $p \le 2$ 的初始情况, 因此初始情况必然满足 $r - l = p - 1 \ge 2$. 注意到每次递归后新的 $r' - l' = \lfloor \frac {r - l} 2 \rfloor$ 或 $r' - l' = \lceil \frac {r - l} 2\rceil$ . 因此由数学知识易知, 在递归到 $r - l \lt 1$ 之前, 必须先递归到 $r - l = 1$ 或者 $r - l = 2$.

此时, 假设递归到了 $r - l = 1$ 且从未递归到 $r - l = 2$. 由数学知识容易知道, 其之前递归到了 $r - l = 3$, 且减少的时候, 只能是选择了前一半 (即 $r' - l' = 1$). 此时, 由归纳假设, $a[l] \gt a[l + 1]$ 且 $a[r] \gt a[r - 1]$. 且因为选择了前一半递归, 所以分支满足 $a[m-1] \lt a[m] \lt a[m+1]$. 注意到此时, $m = l + 1$. 因此 $a[l] \lt a[l + 1] \lt a[l + 2]$, 但这个共 $a[l] \lt a[l + 1]$ 矛盾.

综上, 必然会递归到 $r - l = 2$ 的情况. 而这种情况已经证明了正确性.

## b

我们直接来解决 $c$ 的情况. 对于一个 $m \times n$ 的矩阵, 我们采用新的算法 `divide(a,b)` 表示分治求出二维区域 $[a,b] \times [1,m]$ 的局部最小值. 我们不妨假设 $m \le n$

执行步骤如下:

- 首先找出第 $1$ 列和第 $n$ 列的最小值. 如果他们中的任意一个是局部最小值, 则返回
- 否则, 转入 `divide(1,n)` .

函数 `divide(l,r)` 的执行步骤如下:

- 当 $l - r = 2$ 时, 直接找出第 $l + 1$ 的最小值, 其必然是局部最小值.
- 令 $d = \lfloor \frac {l + r} 2 \rfloor$ , 找出第 $l$ 列的最小值. 如果他是局部最小值, 则返回. 
- 否则, 此时 $d - 1$ 列和 $d + 1$ 列中, 至少有一列存在比 $d$ 列的最小值小的值. 如果是 $d - 1$ 列. 转入 `divide(l,d)`. 否则, 转入 `divide(d,r)` .

观察容易得到, 该算法是 $a$ 的一般化情况, 只不过每次递归时, 需要多一次 $m$ 个数求最小值的操作. 因此, 时间复杂度为 $T(m,n) = \mathcal{O}(m) \times \mathcal{O}(\log n) = \mathcal{O}(m \log n)$. (其中, 我们前提假设了 $m \le n$. 如果 $m \gt n$, 则交换 $m$ 和 $n$ (即交换矩阵行列)即可).

正确性: 令 $f[x]$ 表示第 $x$ 列的最小值. 类似 $a$ , 我们可以归纳证明得到 $f[l] \gt f[l + 1]$ 且 $f[r] \gt f[r - 1]$. 因此, 在递归终止条件 $l - r = 2$ 的时候, 有 $f[l] \gt f[l + 1] \lt f[l + 2] = f[r]$. 所以, 任意的第 $l$ 和 $l + 1$ 的元素, 其一定大于第 $l + 1$ 列的最小值. 因此,由定义第 $l + 1$ 列的最小值是局部最小值. 算法的正确性得证.

同理 $a$, 递归不会递归到 $l - r = 2$ 以外的情况 (即死递归). 因此, 此算法的正确性得证.

当 $m = 1$ 时, 即为一维的情况: $T(n) = \mathcal{O}(\log n)$.

# T5

## a

注意到 $x + z = 2y$, 所以 $x + z$ 必须是偶数. 因此, $x$ 和 $z$ 的奇偶性必然相同.

## b

$[1,3,4,2]$

同奇偶的 $[1,3]$ 和 $[2,4]$ 直接没有其他数.

## c

$$
\begin{aligned}
&y - x = z - y  \\ \Leftrightarrow
&(y + 1) - (x + 1) = (z + 1) - (y + 1) \\ \Leftrightarrow
&\frac {y + 1} 2 - \frac {x + 1} 2 = \frac {z + 1} 2 - \frac {y + 1} 2
\end{aligned}
$$

## d

算法叫做 `sort(n)` 表示对 $\{1,2,\cdots,n\}$ 编号的点产生一个 out-of-order 的排列.

`sort(n)` 执行如下:

将 $1 \cdots n$ 分为奇数和偶数两堆. 分别分到两边. 由 $a$ 容易知道, 不存在一个 good order $\{x_i,x_j,x_k\}$ 使得 $x_i$ 在左边, $x_k$ 在右边 (奇偶性问题).

因此, 我们只需要单独解决左右两边的问题即可. 不妨设左边这一堆为 $\{1,3,\cdots 2t-1\}$, 记为 $\{y_i\}$ . 由 $c$ , $\{y_i\}$ out-of-order 等价于 $\{\frac{y_i + 1}2\}$ out-of-order. 即 $\{1,2,\cdots,t\}$ out-of-order. 我们为这些点重新编号, 我们可以递归调用 `sort(t)` 即可.

对于右边偶数的一堆, 同理. 记为 $\{y_i\}$ , 易知 $\{y_i\}$ out-of-order 等价于 $\{\frac{y_i}2\}$ out-of-order. 因此, 同理类似地重新编号并调用 `sort(t)` 即可.

最终, 递归终止条件是 $n = 1$ 或 $n = 2$ 时, 直接返回.

所以最终每一层花 $c \times n$  ($c$ 为常数) 的时间重命名并且分组, 然后向下递归, 有 $T(n) = T(\lfloor \frac n 2 \rfloor) + T(\lceil \frac n 2 \rceil) + c \times n$. 特别地, $T(1) = T(2) = \mathcal{O}(1)$.

因此, $T(n) \le 2T(\frac {n + 1} 2) + cn$. 且边界条件 $T(1) = T(2) = \mathcal{O}(1)$.

根据主定理, $T(n) = \mathcal{O}(n \log n)$.

# T6

List: Thinking time + writing time.

- T1: $0\text{min} + 15\text{min}$
- T2: $5\text{min} + 10\text{min}$
- T3: $5\text{min} + 25\text{min}$
- T4: $20\text{min} + 20\text{min}$
- T5: $5\text{min} + 15\text{min}$

Summary: too fucking hard. Difficulty = 5.
