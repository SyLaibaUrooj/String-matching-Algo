

//////////////////////////////////////////////////////////////////////////			COMPUTE PREFIX FUNCTION


/******************************************************************************

                            WORKING & TESTED 

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{

    string pattern = "aabaabcab"; // 0	1	0	1	2	3	0	1	0
    int plen = pattern.size();
    
    int pi[plen]={0};
    pi[0]=-1; // by default always 
    int k =-1;

    for ( int i =1; i< plen; i++){ // i = 1 , 2
	
	    while( k>=0 && pattern[k+1] != pattern[i] ){
	
		    k = pi[k];
	    }
	
	    if( pattern[k+1] == pattern[i] )
		    k =k +1; // k=0 , 
	
	    pi[i] = k;

    }

    // Display
    cout << "prefix function" << endl;
    for( int x =0; x < plen; x++){
    
    cout << pi[x]+1 << " ";
    }
    
    return 0;
}
