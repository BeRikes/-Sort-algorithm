//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
#include"All_in.h"

struct arr {
	arr():p(NULL) {}
	~arr() {
		if (p) {
			delete[]p;
			cout << "array was freed" << endl;
		}
	}
	int* p;
};

void exec_sort(int *p, int n, void sort(int*, int), string name) {
	clock_t start = clock();
	sort(p, n);
	clock_t end = clock();
	cout << "this is the result of "<< name << endl;
	/*for (int i = 0; i < n; i++) cout << p1[i] << ' ';
	cout << endl;*/
	if (check(p, n)) cout << "------> correct sort" << endl;
	else cout << "------ > wrong sort!!" << endl;
	cout << "the run time is " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl << endl;
}

void exec_sort(int* p, int n, void sort(int*, int, int), string name) {
	clock_t start = clock();
	sort(p, 0, n - 1);
	clock_t end = clock();
	cout << "this is the result of "<< name << endl;
	/*for (int i = 0; i < n; i++) cout << p1[i] << ' ';
	cout << endl;*/
	if (check(p, n)) cout << "------> correct sort" << endl;
	else cout << "------ > wrong sort!!" << endl;
	cout << "the run time is " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl << endl;
}

void exec_sort(int* p, int n, void sort(int*, int*), string name) {
	clock_t start = clock();
	sort(p, p+n);
	clock_t end = clock();
	cout << "this is the result of " << name << endl;
	/*for (int i = 0; i < n; i++) cout << p1[i] << ' ';
	cout << endl;*/
	if (check(p, n)) cout << "------> correct sort" << endl;
	else cout << "------ > wrong sort!!" << endl;
	cout << "the run time is " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl << endl;
}

int main() {
	//八种排序算法，输入n，排序以n为规模的随机数数组，并输出消耗时间
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	const int sort_num = 13;
	string sort_name[sort_num] = { "GnomeSort", "BubbleSort", "selectSort", "insertSort", "QuickSort",
		"QuickSort2", "the STL Sort", "MergeSort", "shellSort", "radixSort", "combSort", "heapSort", "bucketSort"};
	int n, i;
	cin >> n;
	srand((unsigned)time(0));
	time_t begin = clock();
	arr a[sort_num];
	for (i = 0; i < sort_num; ++i) {
		init(a[i].p, n);
	}
	cout << "numsArray is allocated, now start to calculate······" << endl;

	exec_sort(a[0].p, n, GnomeSort, sort_name[0]);
	exec_sort(a[1].p, n, bubbleSort, sort_name[1]);
	exec_sort(a[2].p, n, selectSort, sort_name[2]);
	exec_sort(a[3].p, n, insertSort, sort_name[3]);
	exec_sort(a[4].p, n, QuickSort, sort_name[4]);
	exec_sort(a[5].p, n, QuickSort2, sort_name[5]);
	exec_sort(a[6].p, n, std::sort, sort_name[6]);
	exec_sort(a[7].p, n, MergeSort, sort_name[7]);
	exec_sort(a[8].p, n, shellSort, sort_name[8]);
	exec_sort(a[9].p, n, radixSort, sort_name[9]);
	exec_sort(a[10].p, n, combSort, sort_name[10]);
	exec_sort(a[11].p, n, heapSort, sort_name[11]);
	exec_sort(a[12].p, n, bucketSort, sort_name[12]);
	//exec_sort(a[13].p, n, countSort, sort_name[13]);

	time_t end = clock();
	cout << "the sum of run time is "<<(double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
	system("pause");
	return 0;
}