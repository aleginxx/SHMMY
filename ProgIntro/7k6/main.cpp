#include "pzhelp"
PROGRAM {
    int n, counter = 0, s[5000000], j=0, temp;
    for (int y=0; y<5000000; y++) 
    s[y]=0;
    n=READ_INT();
    temp=n;
    for (int i=2; i<=n; i++) {
        if (n%i==0)
        {
            s[j]=i;
            while (n%i==0)
            {
                n=n/i;
            }
            j++;
        }
    }
    for (int k=1; k<=temp; k++) {
        for (int l=0; l<=j; l++)
        {
            if (s[l]==0) break;
            if (k%s[l]==0)
            {
                counter ++;
                break;
            }
        }
    }
    cout<<counter<<endl;
    // count = 0;
    // for (i=2; i <= N; i++) {
    //     for (int j = 2; j <= i; j++) {
    //         if ((i % j == 0) AND (N % j ==0)) {
    //             count = count + 1;
    //             break;
    //             }
    //         else continue;
    //         }
    //     }
    //     WRITELN (count);
    // }

    


