#include <stdio.h>

/*
 * 有 N 件物品和一个容量为 V 的背包. 第 i 件物品的重量是
 * c[i], 价值是 w[i]. 求解将哪些物品装入背包可使这些物品
 * 的重量总和不超过背包容量, 且价值总和最大.
 *
 * 用子问题定义状态: 即 f[i][v] 表示前 i 件物品恰放入一个
 * 容量为v的背包可以获得的最大价值. 则其状态转移方程便是:
 * f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}.
 *
 * 这个方程非常重要, 基本上所有跟背包相关的问题的方程都是
 * 由它衍生出来的. 所以有必要将它详细解释一下: "将前 i 件
 * 物品放入容量为 v 的背包中" 这个子问题, 可以转化为一个只
 * 牵扯前 i-1 件物品的问题. 如果不放第 i 件物品, 那么问题
 * 就转化为 "前 i-1 件物品放入容量为 v 的背包中", 价值为
 * f[i-1][v]; 如果放第 i 件物品, 那么问题就转化为"前 i-1
 * 件物品放入剩下的容量为 v-c[i] 的背包中", 此时能获得的
 * 最大价值就是 f[i-1][v-c[i]] 再加上通过放入第 i 件物品
 * 获得的价值 w[i].
 */

/*
 * 从背包容量为 0 开始, 1 号物品先试, 0, 1, 2 的容量都不能
 * 放. 所以置0, 背包容量为 3 则里面放 4. 这样, 这一排背包
 * 容量为 4, 5, 6 ... 10 的时候，最佳方案都是放 4. 假如 1
 * 号物品放入背包. 则再看2号物品. 背包容量为5的时候，最佳
 * 方案为自己的重量 5. 背包容量为 7 的时候, 很显然是5加上
 * 一个值了. 加谁? 很显然是 7 - 4 = 3 的时候. 上一排 c3 的
 * 最佳方案是4. 一排一排推下去, 最右下的数据是最大的价值
 */

int main(void)
{
	int n, m, v, w, i, j;
	int f[100] = {0};

	scanf("%d%d", &n, &m);

	/* n 件物品, 背包容量为 m, 物件体积 w, 价值 v */
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &v, &w);

		for (j = m; j >= w; j--)
			if (f[j] < f[j - w] + v)
				f[j] = f[j - w] + v;
	}
	printf("%d\n", f[m]);
	return 0;
}


/*
 * 给你一个数字三角形, 形式如下:
 *    1
 *   2 3
 *  4 5 6
 * 7 8 9 10
 * 找出从第一层到最后一层的一条路, 使得所经过的权值之和
 * 最小或者最大.
 *
 * f(i, j)=a[i, j] + min{f(i-1, j), f(i, j - 1)}
 *
 * 第一步：
 *    7
 *   3 8
 *  8 1 0
 * 7 12 10 10
 *
 * 第二步：
 *    7
 *   3 8
 * 20 13 10
 *
 * 第三步：
 *   7
 * 23 21
 *
 * 最后一步：
 * 30
 */


























