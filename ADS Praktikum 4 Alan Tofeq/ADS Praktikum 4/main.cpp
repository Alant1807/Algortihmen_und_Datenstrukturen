#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <iostream>
#include <omp.h>

#include "sorting.h"
#include "hashtable.h"
#include <time.h>

/*
Bearbeitet von Alan Tofeq
*/

using namespace std;

//benchmark functions
void benchmark_quicksort();
void benchmark_mergesort();
void benchmark_heapsort();
void benchmark_shellsort();

int main(int argc, char** argv) {

  Catch::Session().run();
  
  std::cout << "\nPress Enter to run measurement" << std::endl;
  std::cin.get();

  benchmark_quicksort();
  benchmark_mergesort();
  benchmark_heapsort();
  benchmark_shellsort();

  //srand(time(NULL));
  //vector<int> randomnum;
  //constexpr int anz = 200;
  //randomnum.resize(anz);
  //for (int i = 0; i < randomnum.size(); i++)
	 // randomnum[i] = rand() % 501 + 1000;
  //HashTable* hash = new HashTable(1000);
  ///*for (int i = 0; i < anz; i++) {
	 // hash->insert(randomnum.at(i));
	 // hash->search(i);
  //}*/
  //hash->insert(4);
  //hash->insert(10);
  //hash->insert(9);
  //hash->insert(3);
  //hash->insert(7);
  //hash->search(11);
  //cout << "Anzahl an Kollisionen: " << hash->getCollisionCount() << endl << endl;
  //***************************
  // run all benchmarks *
  //***************************
  system("pause");
  return 0;
}

//executes benchmark for quicksort
void benchmark_quicksort() {

  //file stream
  ofstream quicksort_measurement;
  quicksort_measurement.open("quicksort.txt", ios::out | ios::app);

  //benchmark parameters / variables
  double dtime;
  int n_start = 1000;
  int n_step = 1000;
  int n_end = 1000000;

  vector<int> V;

  //actual benchmark loop
  for (int n = n_start; n<=n_end; n += n_step) {
	
	//"progress bar"
    std::cout << "Running Quicksort with n: " << n << std::endl;

	//generate n random integers
	sorting::randomizeVector(V, n);

	//start measurement
    dtime = omp_get_wtime();
    
	//execzute sorting algorithm
    sorting::QuickSort(V,0,V.size()-1);

	//stop time
    dtime = omp_get_wtime() - dtime;

	//write to file
    quicksort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
  }

  //close file handle
  quicksort_measurement.close();
}

void benchmark_mergesort() {
	ofstream mergesort_measurement;
	mergesort_measurement.open("mergesort.txt", ios::out | ios::app);

	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> a;
	vector<int> b;

	for (int n = n_start; n <= n_end; n += n_step) {
		std::cout << "Running Mergesort with n: " << n << std::endl;
		sorting::randomizeVector(a, n);
		sorting::randomizeVector(b, n);
		dtime = omp_get_wtime();
		sorting::MergeSort(a, b, 0, a.size() - 1);
		dtime = omp_get_wtime() - dtime;
		mergesort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
	}
	mergesort_measurement.close();
}

void benchmark_heapsort() {
	ofstream heapsort_measurement;
	heapsort_measurement.open("heapsort.txt", ios::out | ios::app);

	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> v;

	for (int n = n_start; n <= n_end; n += n_step) {
		std::cout << "Running Heapsort with n: " << n << std::endl;
		sorting::randomizeVector(v, n);
		dtime = omp_get_wtime();
		sorting::HeapSort(v, v.size());
		dtime = omp_get_wtime() - dtime;
		heapsort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
	}
	heapsort_measurement.close();
}

void benchmark_shellsort() {
	ofstream shellsort_measurement;
	shellsort_measurement.open("shellsort.txt", ios::out | ios::app);

	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> v;

	for (int n = n_start; n <= n_end; n += n_step) {
		std::cout << "Running Shellsort with n: " << n << std::endl;
		sorting::randomizeVector(v, n);
		dtime = omp_get_wtime();
		sorting::ShellSort(v, v.size());
		dtime = omp_get_wtime() - dtime;
		shellsort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
	}
	shellsort_measurement.close();
}

