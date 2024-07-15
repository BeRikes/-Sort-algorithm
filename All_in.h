#pragma once

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string.h>
#include<algorithm>
using namespace std;

void init(int*& a, int n);
void bubbleSort(int* a, int n);
void selectSort(int* a, int n);
void insertSort(int* a, int n);
int Quickdivide(int* a, int low, int high);
void QuickSort(int* a, int low, int high);
int partition(int* a, int low, int high);
void QuickSort2(int* a, int low, int high);
void mergearray(int a[], int first, int mid, int last, int temp[]);
void mergesort(int a[], int first, int last, int temp[]);
void MergeSort(int a[], int n);
void shellSort(int a[], int n);
void combSort(int* arr, int size);
void GnomeSort(int array[], int n);
int maxBit(int data[], int n);
void radixSort(int data[], int n);
void select_heap(int data[], int i, int n);
void heapSort(int data[], int n);
int array_max(int data[], int n);
int array_min(int data[], int n);
//void countSort(int data[], int n);
void bucketSort(int a[], int n);
bool check(int a[], int n);

struct node {
	int val = 0;
	node* next = NULL;
	node* prior = NULL;
};

class array_of_list {
public:
	array_of_list():arr(NULL), num(0) {}
	array_of_list(int n) :num(n) {
		arr = new node * [n];
		for (int i = 0; i < n; ++i) {
			arr[i] = new node;
		}
	}

	void insert(int idx, int val) {
		node* add = new node;
		add->val = val;
		add->next = arr[idx]->next;
		add->prior = arr[idx];
		if(arr[idx]->next) arr[idx]->next->prior = add;
		arr[idx]->next = add;
	}

	node* operator[](int idx) {
		return arr[idx];
	}

	void sort_list(int idx) {
		node* p = arr[idx]->next, *p2;
		if (p == NULL) return;
		else {
			for (p = p->next; p != NULL;p=p->next) {
				int tmp = p->val;
				for (p2 = p->prior; p2 != arr[idx] && p2->val > tmp; p2 = p2->prior) p2->next->val = p2->val;
				p2->next->val = tmp;
			}
		}
	}

	~array_of_list() {
		for (int i = 0; i < num; ++i) {
			node* p = arr[i], * p2;
			while (p) {
				p2 = p->next;
				delete p;
				p = p2;
			}
		}
		delete[]arr;
	}
private:
	node** arr;
	int num;
};