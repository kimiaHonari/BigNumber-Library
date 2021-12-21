#include "BigNumber.h"
#include <iostream>
int main()
{
	while(1)
	{

		string num1;
		string num2;
        char opera='+';
		cin>>num1;
		if(num1=="end")
			break;
		cin>>opera;
		cin>>num2;
		BigNumber a(num1);
		BigNumber b(num2);
	   
	    switch(opera)
		{
		    case '+':
			  cout<<a+b<<endl;
			  break;
			case '-':
				cout<<a-b<<endl;
				break;
			case '*':
				cout<<a*b<<endl;
				break;
			case '/':
				cout<<a/b<<endl;
				break;
			default:
				break;
	   }
		


	}
	
	
	return 0;
}