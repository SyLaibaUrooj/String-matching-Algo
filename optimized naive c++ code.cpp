/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
string text = "abcxabcd";
string pattern = "abcd";
int tlen = text.size();
int plen = pattern.size();

int limit = tlen - plen;
int cond = 0;

for( int i =0; i <= limit; i++){
    
    
	for( int j=0; j<plen; j++){
	    
	    cond = j+1; // +1 bcuz last j inc to break the loop not adds.
		if ( text[i+j] != pattern[j])
		{
		    cond = j;
			break;
		}
		
	}
	//cout << "cond" << cond << endl;
	if( cond == plen )
	{
		cout << "pattern found at position " << i << endl;
		i = i+plen;
		i -= 1;
	}
	else if (cond != 0){
		i = i+cond;
		i=i-1; // bcuz in next iteration outer for loop also increments.
		//cout << i;
	}


}

    return 0;
}
