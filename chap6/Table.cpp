/*
    Rearrange a[1:n] to correspond to the sequence a[t[1]], ... , a[t[n]], n >= 1.
    */
template <class T>
void Table(T *a, const int n, int *t)
{
    for (int i = 1; i < n; i++)
        if (t[i] != i) {
            // there is a non-trival cycle starting at i
            T p = a[i];
            int j = i;
            do {
                int k = t[j];
                a[j] = a[k];
                t[j] = j;
                j = k;
            } while (t[j] != i);
            a[j] = p;   // j is position for record p
            t[j] = j;
        }
}
