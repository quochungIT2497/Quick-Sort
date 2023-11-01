#include <iostream>
using namespace std;

void swap(int& a, int& b)//hàm swap
{
	int t = a;
	a = b;
	b = t;
}
void quicksort(int a[], int l, int r)
{
	int x = a[r];//tìm 1 số bất kì ở vị trí (đầu = l, giữa = (l+r)/2, cuối = r)
	int i = l;
	int j = r;
	while (1) //while điều kiện = true tương đương l < r
	{
		while (a[i] < x)//Nếu i ở vị trí bên trái bé hơn số x 
		{
			i++;//tăng i
		}
		while (a[j] > x)//Nếu j ở vị trí bên phải bé hơn số x
		{
			j--;//giảm j
		}
		if (i > j) break;//nếu i lớn hơn j thì bỏ, hoặc nếu i <= j thì tiếp tục swap
		swap(a[i], a[j]);//đổi vị trí của i và j trong mảng
		i++;//tiếp tục tăng i
		j--;//tiếp tục tăng j
	}
	if (i < r)//nếu l < r tương đương true
		quicksort(a, i, r);//đệ quy quick sort thay l = i
	if(l<r)
		quicksort(a, l, j);//đệ quy quick sort thay r = j
}
/*void nhapmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap so thu " << i + 1 << " vao mang: " << endl;
		cin >> a[i];
	}
}
*/
void xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << " " << a[i] << " ";
		cout << endl;
}

void main()
{
	int a[] = { 60, 55, 6, 41, 10, 51, 56, 23, 20, 25 };
	int n = sizeof(a)/sizeof(a[0]);
	//nhapmang(a, n);
	cout << "Mang truoc khi nhap: "<<endl;
	xuatmang(a, n);
	cout << "Mang sau khi nhap: "<<endl;
	quicksort(a, 0, n - 1);
	xuatmang(a, n);
}