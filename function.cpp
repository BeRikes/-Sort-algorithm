#include"All_in.h"
//�������������Ǵ�С����

void init(int*& a, int n) {
	a = new int[n];
	for (int i = 0; i < n; i++) {
		if (i != 0 && a[i - 1] % 2 == 0) a[i] = rand() % INT_MAX;
		else a[i] = 2 * rand() % INT_MAX;
	}
}

void bubbleSort(int* a, int n) {//2 ð������
	int i, j, tmp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) tmp = a[j], a[j] = a[j + 1], a[j + 1] = tmp;
		}
	}
}

void selectSort(int* a, int n) {                   //1 ѡ������
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

int Quickdivide(int* a, int low, int high) {       //3 ��������
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

void mergearray(int a[], int first, int mid, int last, int temp[])	//��������������ϲ����� 
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
void mergesort(int a[], int first, int last, int temp[])	//��������������ϲ����� 
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);	//�������
		mergesort(a, mid + 1, last, temp);	//�ұ�����
		mergearray(a, first, mid, last, temp);	//�ٽ�������������ϲ�
	}
}
void MergeSort(int a[], int n)                      //4 �鲢����
{
	int* p = new int[n];  //����һ����n��int��Ԫ�ص�������ռ�ռ䣬����������ĵ�һ��Ԫ�صĵ�ַ����int *��ָ��p
	if (p == NULL) return;
	mergesort(a, 0, n - 1, p);
	delete[] p;
}

void shellSort(int a[], int n) {                   //5 ϣ������
	int gap = n;
	while (gap > 1) {
		//ÿ�ζ�gap�۰����
		gap = gap / 2;            //������������ֵΪ������һ
		//��������
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

void combSort(int* arr, int n) {               //��������
	double shrink_factor = 1.247330950103979;
	int gap = n, swapped = 1, tmp, i;
	while ((gap > 1) || swapped) {
		if (gap > 1) gap = gap / shrink_factor;
		swapped = 0;
		for (i = 0; (i + gap) < n; i++) {  //����ѭ��
			if (arr[i] > arr[i + gap]) {   //�ڲ�ð��
				tmp = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = tmp;
				swapped = 1;          //ȷ����αȽ�ʵ��ð��
			}
		}
	}
}

void GnomeSort(int array[], int n) {
	int i = 0;
	while (i < n) {
		//���i=0����i-1��i����ʱ��i++
		if (i == 0 || array[i - 1] <= array[i]) {
			i++;
		}
		else {
			//���i-1��i����ʱ��i--
			swap(array[i - 1], array[i]);
			i--;
		}
	}
}

int maxBit(int data[], int n)
{
	//����Щ��������n��Ԫ�ص����ֵ 
	int maxData = data[0];
	for (int i = 1; i < n; i++)
	{
		if (maxData < data[i])
			maxData = data[i];
	}

	//��Щ�����������ֵ��λ���Ƕ��� 
	int d = 1;    //d�����������ֵ��λ������Ϊ��Ȼ��һ�������϶�������1λ������d��ʼ��Ϊ1 
	while (maxData >= 10)  //�����ֵ����/10������λ�� 
	{
		maxData /= 10;
		d++;
	}
	return d;
}
void radixSort(int data[], int n) {  //�������� 
	int* temp = new int[n];
	int bucket[10];     //ʮ��Ͱ
	int d = maxBit(data, n);  //������λ��
	int i, j, k;
	int radix = 1;   //��ǰ�����λ��
	for (i = 1; i <= d; i++) {   //����d������
		for (j = 0; j < 10; j++) bucket[j] = 0;  //ÿ�η���ǰ��ռ�����		
		for (j = 0; j < n; j++) {    //ͳ��ÿ��Ͱ��Ԫ�ظ��� 
			k = (data[j] / radix) % 10;
			bucket[k]++;
		}
		//�ؼ�����1 
		for (j = 1; j < 10; j++) bucket[j] = bucket[j - 1] + bucket[j];    //����֮������λ��Ϊj��һȺ����temp���飨ȡ���󣩵�β���±�
		//�ؼ�����2 
		for (j = n - 1; j >= 0; j--) {
			k = (data[j] / radix) % 10;
			temp[bucket[k] - 1] = data[j];
			bucket[k]--;
		}
		for (j = 0; j < n; j++) data[j] = temp[j];     //����ʱ��������ݸ��Ƶ�data��
		radix = radix * 10;  //��λ  -> ʮλ  ->��λ ->���� 
	}
	delete[]temp;
}

void select_heap(int data[], int i, int n) {
	//������i�ڵ�Ϊ������Ϊ����
	if (i >= n / 2) return;   // iΪ��Ҷ�ӽڵ�
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
	//��������
	int i;
	for (i = n / 2 - 1; i >= 0; --i) {
		select_heap(data, i, n);
	}
	for (i = 0; i < n; ++i) {
		//�Ѷ�Ԫ�����βԪ�ؽ�������Ϊ�Ѷ�Ԫ���������������Ԫ���ں��棬��������Ǵ�С����
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
	const int bucketNum = sqrt(n);   // ƽ��һ��Ͱ����sqrt(n)����
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
		cout << "��������û�����ݣ�" << endl;
		return false;
	}
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}