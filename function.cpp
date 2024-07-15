#include"All_in.h"
//所有排序结果都是从小到大

void init(int*& a, int n) {
	a = new int[n];
	for (int i = 0; i < n; i++) {
		if (i != 0 && a[i - 1] % 2 == 0) a[i] = rand() % INT_MAX;
		else a[i] = 2 * rand() % INT_MAX;
	}
}

void bubbleSort(int* a, int n) {//2 冒泡排序
	int i, j, tmp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) tmp = a[j], a[j] = a[j + 1], a[j + 1] = tmp;
		}
	}
}

void selectSort(int* a, int n) {                   //1 选择排序
	int i, k, j, tmp;
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (a[k] > a[j]) k = j;
		}
		tmp = a[k], a[k] = a[i], a[i] = tmp;
	}
}

void insertSort(int* a, int n) {
	int i, j,tmp;
	for (i = 1; i < n; i++) {
		tmp = a[i];
		for (j = i - 1; j >= 0 && a[j] > tmp; j--) a[j + 1] = a[j];
		a[j + 1] = tmp;
	}
}

int Quickdivide(int* a, int low, int high) {       //3 快速排序
	int x = a[low];
	while (low < high) {
		while (low < high && a[high] >= x) --high;
		if (low == high) break;
		a[low++] = a[high];
		while (low < high && a[low] <= x) ++low;
		if (low == high) break;
		a[high--] = a[low];
	}
	a[low] = x;
	return low;
}

void QuickSort(int* a, int low, int high) {
	if (low >= high) return;
	int middle = Quickdivide(a, low, high);
	QuickSort(a, low, middle - 1);
	QuickSort(a, middle + 1, high);
}

int partition(int* a, int low, int high) {
	int x = a[high], i = low - 1, j, temp;
	for (j = low; j < high; ++j) {
		if (a[j] < x) {
			temp = a[j];
			a[j] = a[i + 1];
			a[i + 1] = temp;
			++i;
		}
	}
	a[high] = a[i + 1];
	a[i + 1] = x;
	//for (j = 0; j <= high; j++) cout << a[j] << ' ';
	//cout << endl;
	return i + 1;
}

void QuickSort2(int* a, int low, int high) {
	if (low >= high) return;
	int middle = partition(a, low, high);
	QuickSort2(a, low, middle - 1);
	QuickSort2(a, middle + 1, high);
}

void mergearray(int a[], int first, int mid, int last, int temp[])	//将两个有序数组合并排序 
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;
	while (i <= m && j <= n)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= m)
		temp[k++] = a[i++];
	while (j <= n)
		temp[k++] = a[j++];
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])	//将两个任意数组合并排序 
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);	//左边有序
		mergesort(a, mid + 1, last, temp);	//右边有序
		mergearray(a, first, mid, last, temp);	//再将两个有序数组合并
	}
}
void MergeSort(int a[], int n)                      //4 归并排序
{
	int* p = new int[n];  //分配一个有n个int型元素的数组所占空间，并将该数组的第一个元素的地址赋给int *型指针p
	if (p == NULL) return;
	mergesort(a, 0, n - 1, p);
	delete[] p;
}

void shellSort(int a[], int n) {                   //5 希尔排序
	int gap = n;
	while (gap > 1) {
		//每次对gap折半操作
		gap = gap / 2;            //或者设置增量值为除三减一
		//单趟排序
		for (int i = 0; i < n - gap; ++i) {
			int end = i;
			int tem = a[end + gap];
			while (end >= 0&&tem < a[end]) {
					a[end + gap] = a[end];
					end -= gap;
			}
			a[end + gap] = tem;
		}
	}
}

void combSort(int* arr, int n) {               //梳子排序
	double shrink_factor = 1.247330950103979;
	int gap = n, swapped = 1, tmp, i;
	while ((gap > 1) || swapped) {
		if (gap > 1) gap = gap / shrink_factor;
		swapped = 0;
		for (i = 0; (i + gap) < n; i++) {  //单次循环
			if (arr[i] > arr[i + gap]) {   //内层冒泡
				tmp = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = tmp;
				swapped = 1;          //确保多次比较实现冒泡
			}
		}
	}
}

void GnomeSort(int array[], int n) {
	int i = 0;
	while (i < n) {
		//如果i=0或者i-1与i正序时，i++
		if (i == 0 || array[i - 1] <= array[i]) {
			i++;
		}
		else {
			//如果i-1与i逆序时，i--
			swap(array[i - 1], array[i]);
			i--;
		}
	}
}

int maxBit(int data[], int n)
{
	//行这些代码在求n个元素的最大值 
	int maxData = data[0];
	for (int i = 1; i < n; i++)
	{
		if (maxData < data[i])
			maxData = data[i];
	}

	//这些代码在求最大值的位数是多少 
	int d = 1;    //d用来计数最大值的位数，因为既然是一个数，肯定至少有1位，所以d初始化为1 
	while (maxData >= 10)  //将最大值不断/10，计算位数 
	{
		maxData /= 10;
		d++;
	}
	return d;
}
void radixSort(int data[], int n) {  //基数排序 
	int* temp = new int[n];
	int bucket[10];     //十个桶
	int d = maxBit(data, n);  //求出最大位数
	int i, j, k;
	int radix = 1;   //当前处理的位数
	for (i = 1; i <= d; i++) {   //进行d次排序
		for (j = 0; j < 10; j++) bucket[j] = 0;  //每次分配前清空计数器		
		for (j = 0; j < n; j++) {    //统计每个桶的元素个数 
			k = (data[j] / radix) % 10;
			bucket[k]++;
		}
		//关键代码1 
		for (j = 1; j < 10; j++) bucket[j] = bucket[j - 1] + bucket[j];    //更新之后变成了位数为j的一群数在temp数组（取出后）的尾部下标
		//关键代码2 
		for (j = n - 1; j >= 0; j--) {
			k = (data[j] / radix) % 10;
			temp[bucket[k] - 1] = data[j];
			bucket[k]--;
		}
		for (j = 0; j < n; j++) data[j] = temp[j];     //将临时数组的内容复制到data中
		radix = radix * 10;  //个位  -> 十位  ->百位 ->…… 
	}
	delete[]temp;
}

void select_heap(int data[], int i, int n) {
	//调整以i节点为根的数为最大堆
	if (i >= n / 2) return;   // i为非叶子节点
	int tmp = i, leftchild = 2 * i + 1, rightchild = 2 * i + 2;
	if (leftchild < n && data[tmp] < data[leftchild]) tmp = leftchild;
	if (rightchild < n && data[tmp] < data[rightchild]) tmp = rightchild;
	if (tmp != i) {
		int t = data[tmp];
		data[tmp] = data[i];
		data[i] = t;
		select_heap(data, tmp, n);
	}
}

void heapSort(int data[], int n) {
	//建立最大堆
	int i;
	for (i = n / 2 - 1; i >= 0; --i) {
		select_heap(data, i, n);
	}
	for (i = 0; i < n; ++i) {
		//堆顶元素与堆尾元素交换，因为堆顶元素逆向输出，最大的元素在后面，所以最后是从小到大
		int tmp = data[0];
		data[0] = data[n - i - 1];
		data[n - i - 1] = tmp;
		select_heap(data, 0, n - i - 1);
	}
}

int array_max(int data[], int n) {
	int m = data[0];
	for (int i = 1; i < n; ++i) {
		if (data[i] > m) m = data[i];
	}
	return m;
}

int array_min(int data[], int n) {
	int m = data[0];
	for (int i = 1; i < n; ++i) {
		if (data[i] < m) m = data[i];
	}
	return m;
}

//void countSort(int data[], int n) {
//	int max = array_max(data, n);
//	int min = array_min(data, n);
//	int* cnt = new int[max - min + 1], *sorted = new int[n], i;
//	memset(cnt, 0, sizeof(cnt));
//	for (i = 0; i < n; ++i) {
//		++cnt[data[i]-min];
//	}
//	for (i = 1; i < max - min + 1; ++i) {
//		cnt[i] += cnt[i - 1];
//	}
//	for (i = n - 1; i >= 0; --i) {
//		sorted[cnt[data[i]]] = data[i] + min;
//		--cnt[data[i]];
//	}
//	delete[]cnt;
//	delete[]data;
//	data = sorted;
//}

void bucketSort(int a[], int n) {
	const int bucketNum = sqrt(n);   // 平均一个桶含有sqrt(n)个数
	int min = array_min(a, n), max = array_max(a, n), i, j;
	int step = (max - min) / bucketNum + 1;
	array_of_list buckets(bucketNum);
	for (i = 0; i < n; ++i) {
		buckets.insert((a[i] - min) / step, a[i]);
	}
	for (i = 0; i < bucketNum; ++i) {
		buckets.sort_list(i);
	}
	j = 1;
	node* p = buckets[0]->next;
	for (i = 0; i < n; ++i) {
		while (p == NULL) p = buckets[j++]->next;
		a[i] = p->val;
		p = p->next;
	}
}

bool check(int a[], int n) {
	if (a == NULL) {
		cout << "此数组中没有数据！" << endl;
		return false;
	}
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}