void merge(int*arr, int start, int end)
{
     int middle=(start+end)/2;
    int fc=start;
       int tc=0;
     int sc=middle+1;
    int* new_arr=new   int[end-start+1];
    while(fc<middle+1 and sc<end+1)
    {
        if(arr[fc]<=arr[sc])
        {
            new_arr[tc]=arr[fc];
            fc++;
            tc++;
        }
        else
        {
            new_arr[tc]=arr[sc];
            sc++;
            tc++;
        }


    }
    while(fc<middle+1)
    {
         new_arr[tc]=arr[fc];
            fc++;
            tc++;
    }
    while(sc<end+1)
    {
        new_arr[tc]=arr[sc];
            sc++;
            tc++;
    }

    for( int i=0;i<end-start+1;i++)
    {

        arr[start+i]=new_arr[i];
    }

    delete new_arr;



}


void insertion_sort(int*arr,int start,int end)
{
    int size=end-start+1;
    if(size==1)
     return;

    int already_sorted=start+1;
    for(;already_sorted<start+size;already_sorted++)
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



void merge_sort(int*arr,int start,int end)
{
    if(end-start<1)
        return;
    if(end-start<=3)
    {
        insertion_sort(arr,start,end);
        return;
    }
    int middle=(start+end)/2;
    merge_sort(arr,start,middle);
    merge_sort(arr,middle+1,end);
    merge(arr,start,end);



}
