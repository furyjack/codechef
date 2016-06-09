void insertion_sort(int*arr,int size)
{
    if(size==1)
     return;

    int already_sorted=1;
    for(;already_sorted<size;already_sorted++)
    {
        int index=already_sorted-1;
        int key=arr[already_sorted];

        while(index>=0 and arr[index]>key)
        {
            arr[index+1]=arr[index];
            index--;


        }
        arr[index+1]=key;



    }

}

