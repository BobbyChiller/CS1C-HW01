#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
using namespace std;

ifstream fin;
ofstream fout;


class RandomNumberProgram{
	public:
		int RandomNumber;
		void GenerateNumber(){
			RandomNumber = (rand() % 1000);
		}
		void PrintRandomNumber(){
			cout << RandomNumber << endl;
		}
		int SumDigits(){
			int n = RandomNumber;
			int sum = 0;
			int m;

			while(n>0){
				m = n%10;
				sum = sum + m;
				n = n/10;
		}

			return sum;
		}
		int TripleNumber(){
			return RandomNumber * 3;
		}
		int ReverseNumber(){
			int num = RandomNumber;
			int remainder;
			int reversedNumber = 0;

			while(num != 0){
				remainder = num % 10;
				reversedNumber = reversedNumber * 10 + remainder;
				num /= 10;
			}

			return reversedNumber;
		}		
};

int * ReadFile(){
	fin.open("Output.txt");

	static int Array[9];
	int element;

	if(fin.is_open()){
		int i = 0;
		while(fin >> element){
			Array[i++] = element;
		}
	}
	fin.close();
	return Array;
}
int main() {
	RandomNumberProgram RNP;
	RNP.GenerateNumber();
	RNP.PrintRandomNumber();
	cout << RNP.SumDigits() << endl;
	cout << RNP.TripleNumber() << endl;
	cout << RNP.ReverseNumber() << endl;

	enum Seasons {Spring, Summer, Fall, Winter};

	

	int Array[9];

	for(int r = 0; r <=9; r++)
	{
		Array[r] = rand()%10;
		cout << Array[r];
		cout << endl;
	}


	for(int i = 0; i<=9; i++)
	{
		for(int j = i+1; j<=9; j++)
		{
			if(Array[j] < Array[i])
			{
					int temp = Array[i];
					Array[i] = Array[j];
					Array[j] = temp;
			}
		}

	}

	cout << "Sort yourself out mate " << endl;
	for(int i = 0; i<=9; i++)
	{
		cout << Array[i] << endl;
	}

	fout.open("Output.txt");

	for(int i = 0; i<=9; i++)
	{
		fout << Array[i] << endl;
	}

	fout.close();

	int *Arr = ReadFile();

	cout << "Printing array from file: " << endl;
	for(int i = 0; i<=9; i++)
	{
		cout << Arr[i] << endl;
	}

	return 0;
}