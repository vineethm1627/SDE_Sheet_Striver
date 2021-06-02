#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public:
        int nextStep(int n) {
            // stop the process when cycle of gap 1 is completed.
            if(n <= 1)
                return 0;
             
            return ceil(n / 2.0);
        }
    
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) { 
            int gap_step = nextStep(n + m);
            
            while(gap_step > 0) {
                int i, j;
                // compare the elements in the first array
                for(i = 0; i + gap_step < n; i++) {
                    if(arr1[i] > arr1[i + gap_step])
                        swap(arr1[i], arr1[i + gap_step]);
                }
                // compare the elements in both the arrays: cross arrays
                j = gap_step > n ? gap_step - n : 0;
                for(; i < n && j < m; i++, j++) {
                    if(arr1[i] > arr2[j])
                        swap(arr1[i], arr2[j]);
                }
                // compare the elements in the second array
                if(j < m) {
                    for(int j = 0; j + gap_step < m; j++) {
                        if(arr2[j] > arr2[j + gap_step])
                            swap(arr2[j], arr2[j + gap_step]);
                    }
                }
                // get the gap step for next iteration
                gap_step = nextStep(gap_step);
            }
        } 
};

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 