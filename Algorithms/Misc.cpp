// Longest Increasing Subsequence

vector<int> LIS;

LIS.clear(); cnt=0;
for(int i=0; i<n; i++) {
    p = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();
    if(p == (int)LIS.size()) {LIS.push_back(arr[i]); cnt++;}
    else LIS[p] = arr[i];
    inc[i] = cnt;
}

LIS.clear(); cnt=0;
for(int i=n-1; i>=0; i--) {
    p = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();
    if(p == (int)LIS.size()) {LIS.push_back(arr[i]); cnt++;}
    else LIS[p] = arr[i];
    dec[i] = cnt;
}

//###############################################################################//

// Printing DP solution: "repeat the function"
//example:
void print(int x, int i) {
	if(x > t || i == n) return;

	int &ret = dp[x][i];
	int a = go(x+arr[i], i+1);
	int b = go(x, i+1);

	if(ret == a) {
		cout << arr[i] << " ";
		print(x+arr[i], i+1);
	} else {
		print(x, i+1);
	}
}

//###############################################################################//

// function to find the longest subarray 
// with sum divisible by k

int longSubarrWthSumDivByK(int arr[], int n, int k) { 
	// hash table 
	unordered_map<int, int> um; 
	
	// 'mod_arr[i]' stores (sum[0..i] % k) 
	int mod_arr[n], max = 0; 
	int curr_sum = 0;
	
	for (int i = 0; i < n; i++) { 
		curr_sum += arr[i]; 
		mod_arr[i] = ((curr_sum % k) + k) % k;	// as sum can be negative	 
	}	 
	
	for (int i = 0; i < n; i++)  {
		// if true then sum(0..i) is divisible by k 
		if (mod_arr[i] == 0) max = i + 1;
		
		// if value 'mod_arr[i]' not present in 'um' then store it with its first occurrence		 
		else if (um.find(mod_arr[i]) == um.end()) 
			um[mod_arr[i]] = i; 
			
		// if mod_arr[i] == mod_arr[j] then subarr between them is divisible by k
		else {
			if (max < (i - um[mod_arr[i]])) 
				max = i - um[mod_arr[i]];			 
		}
	} 
	
	return max; 
}						 

//###############################################################################//
//###############################################################################//

// merge sort

void merge(int arr[], int start, int mid, int end) {
	int temp[end-start+1];
	int p=start, q=mid+1, k=0;

	for(int i=start; i<=end; i++) {
		if(p > mid)		// checks if first part comes to an end or not
			temp[k++] = arr[q++];
		else if(q > end)	// checks if second part comes to an end or not
			temp[k++] = arr[p++];
		else if(arr[p] < arr[q])	// checks which part has smaller element
			temp[k++] = arr[p++];
		else
			temp[k++] = arr[q++];
			//inv += mid-p+1	(num of inversions "i < j && a[i] > a[j]")
	}

	for(int i=0; i<k; i++)
		arr[start++] = temp[i];
}

void merge_sort(int arr[], int start, int end) {
	if(start < end) {
		int mid = (start+end)/2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

//###############################################################################//
//###############################################################################//

Game Theory:

Nim:

xor of all piles == 0 ? "lose" : "win"

//###############################################################################//

Grundy:

int dp[MAX_N];

int calcMex(unordered_set<int> s) {
	int val=0;
	while(s.find(val) != s.end()) val++;
	return val;
}

int calcGrundy(int n) {
	if(n == 0) return 0;    //no more moves
   
    int &ret = dp[n];
    if(ret != -1) return ret;

	unordered_set<int> sub_nimbers;
    for(x : valid_moves)
        sub_nimbers.insert(calcGrundy(move));

	return ret = calcMex(sub_nimbers);
}

//###############################################################################//
