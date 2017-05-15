int binary_search (int a[], int low, int high, int key) {
        int mid;
        if (low == high)
                return low;
        mid = low + ((high-low)/2);
        if (key > a[mid])
                return binary_search(a, mid+1, high, key);
        else if (key < a [mid])
                return binary_search(a, low, mid, key);
        return mid;
}

void binary_insertion_sort(int C[], int tam) {
        int i, j, chave;
        int ins;
        for (j=1; j<tam; j++) {
                ins = binary_search(C, 0, j, C[j]);
                chave = C[j];
                for (int k=j-1; k>=ins; k--) {
                        C[k+1] = C[k];
                }
                C[ins]=chave;
        }
}

void insertion_sort(int C[], int tam) {
        int i, j, chave;
        for (j=1; j<tam; j++) {
                chave = C[j];
                i = j-1;
                while ((i>=0) && C[i]>chave) {
                        C[i+1] = C[i];
                        i--;
                }
                C[i+1]=chave;
        }
}
