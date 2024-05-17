# HW5

## T1

This problem is easy. We keep track of the overall money the someone owes others as $\text{sum}$. It's clear that

$$\text{sum}(u) = \sum_{(u,v)\in E} w(u,v) -  \sum_{(v,u)\in E} w(v,u)$$

It's trivial that $\sum \text{sum(u)} = 0$, and $\text{sum}$ is the money that someone should pay others/get from others. 

So, we may arrange a new debt network to transfer the money:

- Initial $\text{rest}(u) = \text{sum}(u)$
- In each time, we choose $u,v$ where $\text{rest}(u)\lt 0$ and $\text{rest}(v)>0$. we just add one new edge $(u,v)$ where the money is $w = \min (\text{rest}(v),-\text{rest}(u))$, so we have $\text{rest}(u) = \text{rest}(u) + w$ and $\text{rest}(v) = \text{rest}(v) - w$
- End when $\forall u, \text{rest}(u)=0$ 

The iteration will be run at most $n - 1$ times. First of all, we may prove by induction that $\sum \text{rest}(u) = 0$ before and after each iteration.  This can be simply proved by induction.

Then if $\exist u, \text{rest}(u) \ne 0$, then there must exist satisfying $u,v$ . This is guaranteed by $\sum \text{rest}(u) = 0$​.

Also, after each iteration, since the weight is $(\text{rest}(v),-\text{rest}(u))$, at least one in $\text{rest}(u),\text{rest}(v)$ should be zero, and we still have the fact that $\text{rest}(u) \le 0, \text{rest}(v) \ge 0$ .

Based on these facts, after one iteration, exactly one edge is added and one or two $\text{rest}$ should be updated to zero. Since there is at most $n$ non-zero $\text{rest}$, which is eliminated to $0$ after the program , there is at most $n$ iteration. Moreover, consider the last iteration, if just one $\text{rest}$ is updated to zero, then before the last iteration, there exists only one non-zero $\text{rest}$. However, we have $\sum\text{rest}(u) = 0$. This is impossible. So in the last iteration, two $\text{rest}$ are updates to zero. So, there is at most $n - 1$ iterations.

That means that in our new debt network, we add at most $n - 1$ edges. And, the new network still satisfy the fact that $\text{sum}'(u) = \text{sum}(u)$. This means our network settle all the payment, containing no more than $n - 1$ p2p payment.

## T2

### 2.a

For each $i \in U$, we create a virtual node $x_i$ . For each $A_j \in \mathcal{A}$, similarly, we create a virtual node $y_i$. An edge $(x_i,y_j)$ if and only if $i \in A_j$.

In addition, we add a virtual source node $s$ and terminal node $t$, where $s$ connects each $x_i$, and $t$ connects each $y_j$. We assign each edge with capacity of $1$.

Then, we claim that the primal problem exists a solution if and only if this network flow's maximal flow equals to $k$. 

$\Rightarrow$  If there exists a representative $a_1,\cdots,a_k$, then there exists  $k$ flows from $s \rightarrow x_{a_i} \rightarrow y_i \rightarrow t $ . Since the maximal flow is restricted by $t$ (contains at most $k$ sources), the maximal flow is exactly $k$.

$\Leftarrow$ Similarly, if the maximal flow is exactly $k$, due to the nature of our graph, a flow must be like this $s \rightarrow x_i \rightarrow y_j \rightarrow t$ . What's more, since each $x_i$ has exactly one in-edge and $y_j$ has exactly one out-edge, so assume those $k$ flows are $s \rightarrow x_{c_i} \rightarrow y_{d_i} \rightarrow t$. Then there exists no $i,j, i\ne j, c_i = c_j \bigvee d_i = d_j$ , otherwise some node might have more than one in/out-flow-edge, which impossible. However, there is exactly $k$ nodes $y$-typed. So, we may rearrange these flows to $s \rightarrow x_{a_i} \rightarrow y_i \rightarrow t$. If we choose $a_i$ as the representative of $A_i$, then it's easy to check that it's a valid solution by our network's definition.

So, we successfully transform the primal problem into a bipartite graph maximal flow problem, where the capacity of each edge is exactly $1$​.

We have prove in class, $\text{Dinic}$ algorithm runs in $\mathcal{O}(E\sqrt{V})$  time, where $E \le nk + n + k$, and $V \le n + k + 2$. So, we have the time complexity $\mathcal{O}(nk\sqrt{n + k})$ 

### 2.b

This problem is similar to 2.a.

We just add virtual node $x_i,y_j$ to each $A_i, B_j$. We add two additional intermediate layer of $z_i,w_i$ corresponding to each $i \in [n]$. Then we connects $s$ to all $x_i$, $x_i$ to $z_j$ if and only if $j \in A_i$, $z_j$ to $w_j$ , $w_j$ to $y_i$ if and only if $j \in B_i$ , and all $y_i$ to $t$.

Similar to the proof in 2.a, we may easily prove that primal problem exists a solution if and only if this network flow's maximal flow equals to $k$, since for different flow $s \rightarrow x_i \rightarrow z_j \rightarrow w_j \rightarrow y_l \rightarrow t$ , since for each non $s,t$ node, either its in/out edge capacity is $1$, so each node can appear at most once in the overall flow (otherwise, some node may be "overflowed"). Similar to the proof in 2.a,  we may derive that the solution where the representative where $a_i = j$, $b_l = j$ valid since all those flow are disjoint(a.k.a, each node can appear at most once in the overall flow). Also, if there's a valid representation where $a_i = j = b_l$, we may build such a network as above.

So, the correctness is guaranteed. Proof similar to 2.a. (keen observation: each node can appear no more than once in a valid flow).

As proved in class, $\text{Dinic}$ in this case has worst time complexity $\mathcal{O}(EV^2)$ where $E \le n + 2k + 2nk$ and $V \le 2n + 2k + 2$. So, the time complexity is $\mathcal{O}((n + k)^2nk)$





