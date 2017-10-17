#include <iostream>
#include <cassert>

using namespace std;

template <class T>
void copy_array(T dst[], T src[], int count) {
	for(int i = 0; i < count; i++) {
		dst[i] = src[i];
	}
}

// s = start of range to sort
// e = end of range to sort

template <class T>
void msort(T  a[], T x[], int s, int e) {
	if ((e - s) < 1) {
		return;
	}

	int mid = (s + e) / 2;
	int i = s;
	int j = mid + 1;
	int k = s;

	msort(a,x,s,mid);
	msort(a,x,mid + 1, e);

	copy_array(&x[s],&a[s],e-s+1);

	while (i <= mid && j <= e) {
		if(x[i] <= x[j] && k <= e) {

			a[k] = x[i];
			i++;
			k++;
		} else if (x[j] < x[i] && k <= e) {

			a[k] = x[j];
			j++;
			k++;
		}
	}

	if(i <= mid) {
		while (i <= mid) {
			a[k] = x[i];
			i++;
			k++;
		}
	}

	if(j <= e) {
		while (j <= e) {
			a[k] = x[j];
			j++;
			k++;
		}
	}
}

template <class T>
void mergesort( T a[], int size) {

	T * x = new T[size];

	msort(a,x,0,size-1);

	delete [] x;
}

template <class T>
bool sorted(T a[], T size) {
	for(int i = 0; i < size - 1; i++) {
		if(a[i] > a[i+1]) { return false;}
	} return true;
}

int main(int argc, char * args[]) {
	int a[1000];
	for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;	// This line not needed for anything beside ints
	mergesort<int>(a,1000);
	assert(sorted<int>(a,1000));

	int s[10];
	for (int i = 0; i < 10; ++i) s[i] = -50 + rand() % 100;		// This line not needed for anything beside ints
	mergesort<int>(s,10);
	assert(sorted<int>(s,10));

	cout << "All tests passed." << endl;
}
