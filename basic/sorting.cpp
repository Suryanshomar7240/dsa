#include <iostream>
using namespace std;
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void selection(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr, i, j);
            }
        }
    }
}
void insertion(int arr[], int n)
{
    int current;
    for (int i = 0; i < n; i++)
    {
        current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}
void bubble(int arr[], int n)
{
    int count = 1;
    while (count < n)
    {
        for (int i = 0; i < n - count; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr, i, i + 1);
            }
        }
        count++;
    }
}
void merging(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1], b[n2];
    for (int i = 0, j = l; i < n1; i++, j++)
    {
        a[i] = arr[j];
    }
    for (int i = 0, j = mid; i < n2; i++, j++)
    {
        b[i] = arr[j];
    }
    int i = 0, j = 0;
    while (j < n2 && i < n1)
    {
        if (a[i] < b[j])
        {
            arr[l++] = a[i++];
        }
        else
        {
            arr[l++] = b[j++];
        }
    }
    while(i<n1)
        arr[l++] = a[i++];
    while(j<n2)
        arr[l++] = a[j++];
}
void merge(int arr[], int n, int l, int r)
{
    int mid = (l + r) / 2;
    if (l < r)
    {
        merge(arr, n, l, mid);
        merge(arr, n, mid + 1, r);
        merging(arr, l, mid, r);
    }
}
int pivot(int arr[], int l, int r)
{
    int i = l - 1;
    int piv = arr[r];
    for (int j = l; j < r - 1; j++)
    {
        if (arr[j] < piv)
        {
            i++;
            swap(arr, j,r);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}
void quick(int arr[], int n, int l, int r)
{
    if (l < r)
    {
        int pi = pivot(arr, l, r);
        quick(arr, n, l, pi);
        quick(arr, n, pi + 1, r);
    }
}
void count(int arr[], int n)
{
    int k = arr[0];
    for (int i = 1; i <= n; i++)
    {
        k = max(k, arr[i]);
    }
    int count[100] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i < k; i++)
    {
        count[i] += count[i - 1];
    }
    int output[n];
    for (int i = n - 1; i > 0; i++)
    {
        output[--count[arr[i]]] == arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
void dnf(int arr[], int n)
{
    int low = 0, high = n - 1, mid = 0;
    while (mid != high)
    {
        if (arr[mid] == 1)
        {
            mid++;
        }
        if (arr[mid] == 0)
        {
            swap(arr, low, mid);
            mid++;
            low++;
        }
        if (arr[mid] == 2)
        {
            swap(arr, high, mid);
            high--;
        }
    }
}
void wave(int arr[], int n)
{
    for (int i = 1; i < n; i = i + 2)
    {
        if (arr[i] > arr[i - 1])
        {
            swap(arr[i], arr[i - 1]);
        }
        if (arr[i] > arr[i + 1] && i <= n - 2)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}
int main()
{
    int a, n;
    char c;
    cout << "Enter no of elements in arrays=";
    cin >> n;
    int *arr = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "PLEASE ENTER YOUR FAV. SORTING METHOD\n HERE ARE SOME CHOICES FOR YOU\n PLEASE SELECT ONE OF THEM";
    cout << endl
         << "1.SELECTION SORT\n2.INSERTION SORT\n3.BUBBLE SORT\n4.MERGE SORT \n5.QUICK SORT\n6.COUNT SORT \n 7.DNF SORT \n8.WAVE SORT\n Enter your choice=";
    cin >> a;
    switch (a)
    {
    case 1:
        selection(arr, n);
        break;
    case 2:
        insertion(arr, n);
        break;
    case 3:
        bubble(arr, n);
        break;
    case 4:
        merge(arr, n, 0, n);
        break;
    case 5:
        quick(arr, n, 0, n);
        break;
    case 6:
        count(arr, n);
        break;
    case 7:
        dnf(arr, n);
        break;
    case 8:
        wave(arr, n);
        break;
    default:
        cout << "None of the above shorting techinque";
        break;
    }
    cout << endl;
    if (a > 0 && a < 9)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    return 0;
}