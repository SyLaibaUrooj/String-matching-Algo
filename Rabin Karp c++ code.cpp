/******************************************************************************

                             RABIN KARP

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string text = "3141592653589793";
    string pattern = "26";
    int n = text.size();
    int m = pattern.size();

    int d =10;
    int q =11;
    int h=10;
    //%q;
    /***
    float mf = pattern.size();
    float df =10;
    float res = pow(df, mf-1);
    ***/
    int p =0;
    int t[n-m+1]={0}; // for text , for every m alphabets 
    t[0]=0; ///


    // PRE-PROCESSING 
    for(int i=0; i<m; i++){ 
        
        int temp1 = pattern[i] - '0'; 
        int temp2 = text[i] - '0'; 

		p = (d*p + temp1)%q;
		t[0] = (d*t[0] + temp2) %q;

    }
   
    // MATCHING
    for(int s=0; s <= n-m; s++){

	    if( p == t[s] ){
		    int cnt =0;
		    for( int j=0; j<m; j++){
			    if( pattern[j] != text[s])
					    break;
			    else
				    cnt++;
			    if( cnt == m )
				    cout << "Pattern occurs with shift " << s << endl;
		    }
		    
	    }
	
	    if( s < n-m ){ // 3,8,4

	        int temp1 = text[s+m] - '0';
	        int temp2 = text[s] - '0';
	        int g = (d*(t[s]-(temp2*h)) + temp1); /// 
		    cout << g << endl;
		    t[s+1] = g%q;

		
	    }
    }

    return 0;
}
