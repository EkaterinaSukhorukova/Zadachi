#include <iostream>
using namespace std;

int main() {
	for (int a=0; a<10; a++) 
		for (int b=0; b<10; b++)
			for (int c=0; c<10; c++)
				for (int g=0; g<10-b; g++)
					for (int r=0; r<10; r++)
					{
						cout <<" "<<a<<b<<c<<"5"<<"0"<<endl;
						cout <<" "<<"0"<<g<<"0"<<"0"<<r<<endl;
						cout <<" "<<a<<b+g<<c<<"5"<<r<<endl<<endl;
					}
	
	return 0;
}
