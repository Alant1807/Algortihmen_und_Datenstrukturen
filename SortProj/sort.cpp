#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace sorting {

	void SelectionSort(std::vector<int>& a) {
		int min_idx;
		for (int i = 0; i < a.size() - 1; i++) {
			min_idx = i;
			for (int j = i + 1; j < a.size(); j++) {
				if (a[j] < a[min_idx]) {
					min_idx = j;
				}
			}
			swap(a[min_idx], a[i]);
		}
	}

	void Shellsort(std::vector<int>& a) {
		int hibbard = 0;
		while (hibbard < (a.size() / 2)) {
			hibbard = 2 * hibbard + 1;
		}
		// schleife für abstandsfolge
		for (int gap = hibbard; gap > 0; gap /= 2) {
			// insertion sort von elementen mit abstand gap
			for (int i = gap; i < a.size(); i++) {
				int key = a[i];
				int j = i;
				for (; j >= gap && key < a[j - gap]; j -= gap) {
					a[j] = a[j - gap];
				}
				a[j] = key;
			}
			// elemente im abstand gap sortiert
		}
	}

	void InsertionSort(vector<int>& a) {
		int j, key;
		for (int i = 1; i < a.size(); i++) {
			key = a[i];
			j = i - 1;
			while (j >= 0 && a[j] > key) {
				a[j + 1] = a[j];
				j -= 1;
			}
			a[j + 1] = key;
		}
	}

	void BubbleSort(std::vector<int>& a) {
		for (int i = a.size() - 1; i >= 0; i--) {
			for (int j = a.size() - 1; j > 0; j--) {
				if (a[j] < a[j - 1]) {
					swap(a[j], a[j - 1]);
				}
			}
		}
	}

	int Partition(vector<int>& arr, int left, int right) {
		int x, i;
		x = arr[right];    // x soll das Pivot-Element sein
		i = left - 1;
		for (int j = left; j <= right - 1; j++) {   // schaue dir jedes Feldelement zwischen left und right
			if (arr[j] <= x) {
				i++;                                // unterteile die Teilfolgen
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i + 1], arr[right]);       // Pivot-Element an die richtige Position vertauschen
		return i + 1;                             // gebe die Position vom Pivot-Element zurück
	}

	void QuickSort(vector<int>& arr, int left, int right) {    // sortiere arr[left...right]
		//***************************
		// implement quicksort here *
		//************ **************
		if (left < right) {
			int pivot = Partition(arr, left, right);   // suche das Pivot-Element
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

	void percDown(vector<int>& a, int p, int n) {      // durchsickern für minheap a[0...n-1]
		int child = p;
		int tmp = a[p];
		int j = p;
		while ((2 * j) + 1 < n) {     // tausche solange, bis kein swap mehr gemacht werden muss 
			child = (2 * j) + 1;
			if (child != (n - 1) && a[child] < a[child + 1]) child++;
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

}

void TestSort() {
	//Test Sortieralgorithmen
	vector<int> folge1;
	folge1.assign(10, 0);
	for (int i = 0; i < 10; i++) {
		cout << "Zahl eingeben: ";
		cin >> folge1[i];
	}
	vector<int> folge2;
	folge2.assign(10, 0);

	cout << endl << "|";
	for (int i = 0; i < folge1.size(); i++) {
		cout << folge1[i] << "|";
	}
	cout << endl;
	//Aufruf Sortieralgorithmus
	sorting::HeapSort(folge1, folge1.size());
	//
	cout << endl << "|";
	for (int i = 0; i < folge1.size(); i++) {
		cout << folge1[i] << "|";
	}
	cout << endl << endl;
}

void moduloQuadrSond(int k, int i, int m) {
	cout << (k + (i * i)) % m << endl;
}

void moduloLinearSond(int k, int i, int m) {
	cout << (k + i) % m << endl;
}

void moduleHash(int k, int m) {
	cout << k % m << endl;
}

void babosort(vector<int>& a) {
	while (!is_sorted(a.begin(), a.end()))
		random_shuffle(a.begin(), a.end());
}

int main() {

	TestSort();
	

	
	std::cout << '\n';
	system("pause");
	return 0;
}