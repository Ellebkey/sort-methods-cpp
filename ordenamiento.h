#include <sys/time.h>
#define _ordenamiento_h

using namespace std;

int v[100000];
int v2[100000];

int Guardar(int count)
{
	//---Se crea el vector aleatorio y se guarda en archivo---
	ofstream fichero("Datos", ios::app | ios::binary);
	
	for (int i = 0; i < count; ++i)
	{
		int numero = rand() % 99999+1;
		fichero.write((char *)&numero, sizeof(int));
	}
	cout<< "Creando vector con: "<< count<<" elementos" << endl;
	    
	//-------------------------------------------------------
	fichero.close();

	//---Guardo el tamaño del vector en archivo tambien------
	ofstream fichero2("num", ios::app | ios::binary);
	int numero2 = count;
	fichero2.write((char *)&numero2, sizeof(int));
	fichero2.close();
	//-------------------------------------------------------
	return 0;
}

int Tamanio()
{
	int l;
	ifstream fichero("num", ios::in | ios::binary);

	fichero.read((char *)&l,sizeof(int));
	fichero.close();
	
	return l;
}

void Cargar(int n, bool b)
{	
	ifstream fichero("Datos", ios::in | ios::binary);
	if(!fichero)
	{
		cout << "No se puede abrir el fichero.";
		exit(0);        
	}
	if (b == false)
	{	
		for (int i = 0; i < n; ++i)
		{
			fichero.read((char *)&v[i],sizeof(int));
			cout<< v[i]<<"-";
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			fichero.read((char *)&v[i],sizeof(int));			    
		}
		cout<< "El vector ha sido reiniciado" <<endl;
	}

	fichero.close();
}


void Mostrar(int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<"-";
	}
	cout<<"\n\n"<< n << " elementos en el vector" <<endl;
	    
}


int menu()
{
	int op;
	cout << "\n-----Metodos de ordenamiento-----" <<endl;
	cout << "| 1. Reiniciar Arreglo"<<endl;
	cout << "| 2. Mostrar" <<endl;
	cout << "| --------------------------------" <<endl;
	cout << "| 3. BubbleSort"<<endl;
	cout << "| 4. Min-Bubblesort"<<endl;
	cout << "| 5. SelectionSort"<<endl;
	cout << "| 6. ShakerSort"<<endl;
	cout << "| 7. InsertionSort"<<endl;
	cout << "| 8. BinaryInsertionSort"<<endl;
	cout << "| 9. ShellSort"<<endl;
	cout << "| 10.HeapSort"<<endl;
	cout << "| 11.QuickSort" <<endl;
	cout << "| 12.MergeSort" <<endl;
	    
	cout << "0.Salir" <<endl;
	cin >> op;
	return op;
}


long double getTime()
{
	timeval starter;
	gettimeofday(&starter,NULL);
	long double t1 = starter.tv_sec+(starter.tv_usec/1000000.0);
	return t1;
}


void BubbleSort(int n)
{
	int nM=0 ,nC=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			nC++;

			if(v[j] > v[j+1])
			{
				swap(v[j],v[j+1]);
				nM++;
			}
		}
	}

	cout <<"\nMovimientos: "<<nM<<endl;
	cout <<"\nComparaciones: "<<nC<<endl;
}

void ShakerSort(int n)
{
	int left = 0,right = n-1,last = n-1, nM = 0, nC = 0;
	while(right > left)
	{
		for (int i = right; i > left; --i)
		{
			if (v[i-1] > v[i])
			{
				swap(v[i],v[i-1]);
				last = i;
				nM++;
			}
			nC++;
		}
		left = last;

		for (int j = left; j < right; ++j)
		{
			if(v[j-1] > v[j])
			{
				swap(v[j],v[j-1]);
				last = j;
				nM++;
			}
			nC++;
		}
		right = last;
	}
	cout <<"\nMovimientos: "<<nM<<endl;
	cout <<"\nComparaciones: "<<nC<<endl;
}


void MinBubbleSort(int n)
{
	int nM=0 ,nC=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = n-1; j >i; j--)
		{
			nC++;
			if (v[i]>v[j])
			{
				swap(v[i],v[j]);
				nM++;
			}
		}
	}
	cout <<"\nMovimientos: "<<nM<<endl;
	cout <<"\nComparaciones: "<<nC<<endl;
}

void SelectionSort(int n)
{
	int min, nM=0 ,nC=0;
	for (int i = 0; i < n-1; ++i)
	{
		nM++;
		min=i;
		for (int j = i +1; j < n; ++j)
		{
			nC++;
			if (v[j] < v[min])
			{
				min = j;
			}
		}
		swap(v[i],v[min]);
	}
	cout <<"\nMovimientos: "<<nM<<endl;
	cout <<"\nComparaciones: "<<nC<<endl;
}

void InsertionSort(int n)
{
	long nC = 0, nM =0;
	for (int i = 0; i < n - 1; i++)
	{
		int j = i+1;
		int temp = v[j];
		nM++;
		while(j > 0 && temp < v[j-1])
		{
			nC++;
			v[j] = v[j-1];
			j--;
		}
		v[j]=temp;
	}

	cout <<"\nMovimientos: "<<nM<<endl;
	cout <<"\nComparaciones: "<<nC<<endl;    
}

void BinaryInsertionSort(int n)
{
	int nC = 0, nM =0;
	for (int i = 1; i < n ; ++i)
	{
		int left = 0, right = i;
		int temp = v[i];
		while(left < right)
		{
			nC++;
			int m = (left + right) / 2;
			if (temp >= v[m])
				left = m + 1;
			else 
				right = m;
		}

		for (int j = i; j > left; --j)
		{
			nM++;
			swap(v[j-1],v[j]);
		}
	}
	cout <<"\nMovimientos: "<<nM<<endl;
	cout <<"\nComparaciones: "<<nC<<endl;
}

void ShellSort(int n)
{
	int m = n/2, j = 0;
	bool fin;
	while(m > 0)
	{
		for (int i = m -1; i < n; ++i)
		{
			int aux = v[i];
			j = i-m;
			fin = false;
			while (j >= 0 && (fin == false))
			{
				if (v[j] > aux)
				{
					v[j+m] =v[j];
					j = j-m;
				}
				else
					fin = true;
			}
			v[j+m] = aux;
		}
		m = m / 2;
	}

}

void QuickSort(int arr[], int left, int right, int nM, int nC) 
{
	int i = left, j = right;
  	int pivot = v[(left + right) / 2];
  	while (i <= j) 
  	{
  		while (v[i] < pivot)
        	i++;
    	while (v[j] > pivot)
          	j--;
    	if (i <= j) 
    	{
    		nM++;
    		swap(v[i],v[j]);
        	i++;
        	j--;
    	}
    	nC++;
  	}
  	if (left < j)
    	QuickSort(v, left, j,nM,nC);
  	if (i < right)
        QuickSort(v, i, right,nM,nC);   
}

void merge(int v[], int v2[], int left, int right) {
    int middleIndex = (left + right)/2;
    int leftIndex = left; 
    int rightIndex = middleIndex + 1;
    int v2Index = left;
    while (leftIndex <= middleIndex && rightIndex <= right) {
        if (v[leftIndex] <= v[rightIndex]) 
        {
            v2[v2Index] = v[leftIndex++];
        } 
        else {
            v2[v2Index] = v[rightIndex++];
        }
        v2Index++;
    }
    while (leftIndex <= middleIndex) {
        v2[v2Index] = v[leftIndex++];
        v2Index++;
    }
    while (rightIndex <= right) {
        v2[v2Index] = v[rightIndex++];
        v2Index++;
    }
}    

void mergeSort(int v[], int v2[], int left, int right) {
    if (left == right) return; 
    int middleIndex = (left + right)/2;
    mergeSort(v, v2, left, middleIndex);
    mergeSort(v, v2, middleIndex + 1, right);
    merge(v, v2, left, right);
  
    for (int i = left; i <= right; i++) {
        v[i] = v2[i];
    }
}    

void buildHeap(int v[], int lastIndex, int topIndex) 
{
	// lastindex es el ultimo indice
	// topIndex es el indice a la cabezara del monticulo
    int tmp = v[topIndex];
    int hijoDer = topIndex*2 + 1;

    if (hijoDer < lastIndex && v[hijoDer] < v[hijoDer+1]) 
    	hijoDer++;
    
    while (hijoDer <= lastIndex && tmp < v[hijoDer]) 
    {
        v[topIndex] = v[hijoDer];
        topIndex = hijoDer;
        hijoDer = hijoDer*2 + 1;
        if (hijoDer < lastIndex && v[hijoDer] < v[hijoDer+1]) 
        	hijoDer++;
    }
    v[topIndex] = tmp; 
}


void heapsort(int v[], int size) 
{
	//se reacomoda el vector para encontrar el nuevo "tope"
    for (int i = size/2 - 1; i >= 0; i--) 
    {
        buildHeap(v, size - 1, i);
            
    }
    
    //cuando encontramos los nuevo "topes"
    //podemos cambiarlos ya ordenados
    for (int i = size - 1; i > 0; i--) 
    {
    	int t = v[i];
    	v[i] = v[0];
    	v[0] = t;
        buildHeap(v, i - 1, 0);
    }
}


void swap(int a, int b)
{
	int aux = 0;
	aux = a;
	a = b;
	b = aux;

}


