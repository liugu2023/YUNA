//运维部第一次授课课后作业
#include <stdio.h>
#include <math.h>
#include <time.h>

// 判断是否为质数
int is_prime(int n) {
	if (n <= 1) return 0;  // 1和负数不是质数
	if (n == 2) return 1;   // 2是质数
	if (n % 2 == 0) return 0; // 偶数不是质数
	
	// 判断从3到sqrt(n)的奇数
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	clock_t start, end;
	double cpu_time_used;
	
	// 设置输出缓冲区，增大缓冲区提高输出性能
	setvbuf(stdout, NULL, _IOFBF, 1024 * 1024);  // 设置1MB缓冲区
	
	start = clock();  // 记录程序开始时间
	
	// 输出1到1000000之间的质数，每个质数后换行
	for (int i = 2; i <= 1000000; i++) {
		if (is_prime(i)) {
			printf("%d\n", i);  // 每输出一个质数都换行
		}
	}
	
	end = clock();  // 记录程序结束时间
	
	// 计算程序运行时间，单位为毫秒
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;  // 转换为毫秒
	
	// 输出运行时间，保留整数部分
	printf("\n程序运行时间: %d毫秒\n", (int)cpu_time_used);
	return 0;
}

