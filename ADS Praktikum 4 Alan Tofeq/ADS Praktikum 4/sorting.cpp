#include "sorting.h"

/*
Bearbeitet von Alan Tofeq
*/

namespace sorting {

	//************
	// QuickSort *
	//************ 
	int partition(vector<int>& arr, int left, int right) {
		int x, i;
		x = arr[right];    // x soll das Pivot-Element sein
		i = left - 1;
		for (int j = left; j <= right - 1; j++) {   // schaue dir jedes Feldelement zwischen left und right
			if (arr[j] <= x) {                      
				i++;                                // unterteile die Teilfolgen
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[double(i) + 1], arr[right]);       // Pivot-Element an die richtige Position vertauschen
		return i + 1;                               // gebe die Position vom Pivot-Element zurück
	}

	
	void QuickSort(vector<int>& arr, int left, int right) {    // sortiere arr[left...right]
		//***************************
		// implement quicksort here *
		//************ **************
		if (left < right) {
			int pivot = partition(arr, left, right);   // suche das Pivot-Element
			QuickSort(arr, left, pivot - 1);           // sortiere Teilarray, sodass die Elemente kleiner als das Pivot-Element sind
			QuickSort(arr, pivot + 1, right);          // sortiere Teilarray, sodass die Elemente größer als das Pivot-Element sind
		}
	}

	//************
	// MergeSort *
	//************

	//***************************
	// implement mergesort here *
	//***************************

	void Merge(vector<int>& a, vector<int>& b, int low, int pivot, int high) {
		int rightpos = pivot;
		int leftEnd = rightpos - 1;
		int tmpPos = low;
		int n = high - low + 1;                          // n Elemente werden gemischt
		while (low <= leftEnd && rightpos <= high) {     // Mische die Elemente der Teilfolgen in den vector B 
			if (a.at(low) <= a.at(rightpos)) {
				b.at(tmpPos) = a.at(low);                // falls Element der linken Teilfolge kleiner ist, übernehme in vector B
				low++;
			}
			else {
				b.at(tmpPos) = a.at(rightpos);           // falls Element der rechten Teilfolge kleiner ist, übernehme in vector B
				rightpos++;
			}
			tmpPos++;                                    // erhöhe Index von vector B nach jedem übernehmen
		}
		while (low <= leftEnd) b.at(tmpPos++) = a.at(low++);            // Falls rechte Teilfolge fertig ist, übernehme Rest von der linken Teilfolge in vector B 
		while (rightpos <= high) b.at(tmpPos++) = a.at(rightpos++);     // Falls linke Teilfolge fertig ist, übernehme Rest von der rechten Teilfolge in vector B 
		for (int i = 0; i < n; i++) {                                   // kopiere gemischter sortierter vector B in vector A zurück  
			a.at(high) = b.at(high);
			high--;
		}
	}

	void MergeSort(vector<int>& a, vector<int>& b, int low, int high) {    // Sortiere a[low...high]
		if (low < high) {
			int middle = ((high + low) / 2);
			MergeSort(a, b, low, middle);
			MergeSort(a, b, middle + 1, high);
			Merge(a, b, low, middle + 1, high);
		}
	}

	//************
	// Heapsort  *
	//************

	int leftChild(int i) {
		return((2 * i) + 1);
	}

	void percDown(vector<int>& a, int p, int n) {      // durchsickern für minheap a[0...n-1]
		int child = p;
		int tmp = a[p];
		int j = p;
		while (leftChild(j) < n) {     // tausche solange, bis kein swap mehr gemacht werden muss 
			child = leftChild(j);
			if (child != (n - 1) && a[child] < a[double(child) + 1]) child++;
			if (tmp < a[child]) {
				swap(a[j], a[child]);
				j = child;
			}
			else break;
		}
	}

	void HeapSort(vector<int>& a, int n) {
		for (int i = n / 2; i >= 0; i--)
			percDown(a, i, n);              // percDown ab i bis runter zu n also gedanklich runter
		// gültiger Heap wurde erzeugt
		for (int j = n - 1; j > 0; j--) {  // sortiere sukzessiv
			swap(a[0], a[j]);              // vertausche Wurzel mit dem letzten Blatt
			percDown(a, 0, j);             // percDown von der Wurzel bis zur Position j
		}
	}

	//************
	// Shellsort *
	//************

	void ShellSort(vector<int>& a, int n) {
		//***************************
		// implement shellsort here *
		//***************************
		int hibbard = 0;
		while (hibbard < (n / 2)) {
			hibbard = 2 * hibbard + 1;
		}
		// schleife für abstandsfolge
		for (int gap = hibbard; gap > 0; gap /= 2) {
			// insertion sort von elementen mit abstand gap
			for (int i = gap; i < n; i++) {
				int tmp = a[i];
				int j = i;
				for (; j >= gap && tmp < a[double(j) - gap]; j -= gap)
					a[j] = a[double(j) - gap];
				a[j] = tmp;
			}
			// elemente im abstand gap sortiert
		}
	}

	void randomizeVector(vector<int>& array, int n) {
		array.resize(n);
		for (unsigned int i = 0; i < array.size(); i++)
			array[i] = rand() % 1000000;
	}
}
  






