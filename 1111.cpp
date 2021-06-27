#include<stdio.h>
int arr1[10000];
int arr2[1000];
int arr3[1000];
int arr4[1000];
int l,u,r;
  	int q;
int select(int,int,int,int);
int main (){

	int f=0;
    printf("input number of test cases: ");
    printf("\n");
    int t;
    scanf("%d",&t); //input number of test cases
    int k;   
    for(k=1;k<=t;k++){
        int numOfShelves; 
        printf("input number of shelves\n");
        scanf("%d",&numOfShelves);
        				//creat an array to input books
        int l;
        printf("input books in each self\n");
        for(l=1;l<=numOfShelves;l++){
            scanf("%d",&arr1[l]);        //input books in to array
        }
        
    printf("input number of queries\n");    
       
    scanf("%d",&q); //number of queries
    int m=1;
    while(m<=q){
        int w,x,y,z;    //for commands
//        printf("0=>select query\n");
//        printf("1=>update query\n");
       // printf("choose 0 or 1\n");
        scanf("%d",&w);
        printf("\n");
		
		 if(w==0)        //select query
        {  
           // printf("...............select..................\n");
            scanf("%d",&l);		//startIndex
            scanf("%d",&u);		//endIndex
            scanf("%d",&r);
					//rank
         arr4[f++]=select(l,u,r,q);
         
        }
     
		 if(w==1)    //update query
      	{ 
	//	printf(".................update......................");
		printf("\n");
		int a,b;
		scanf("%d",&a); 	//position of the array
        scanf("%d",&b);	//update number of books
        arr1[a]=b;
        
                         
        }

        ++m;     
        }
        
            
               
    }        
           int h=0;
           printf("output\n");
    while(arr4[h]!=0)
    {
    	printf("%d\n",arr4[h]);
    	h++;
	}  
	  
  
  } 
    
   
    

int select(int l,int u,int r,int q)
{
	int c,i,j,temp;
	for(c=l;c<=u;c++)
	{
		for(i=c+1;i<=u;i++)
		{
			if(arr1[c]>arr1[i])
			{
				temp=arr1[c];
				arr1[c]=arr1[i];
				arr1[i]=temp;
			}
		}
	}

	int p=0;
	for(p=0;p<q-1;p++)
	{
		arr3[p]=arr1[r];
	return(arr3[p]);	
	}
//	arr3[p]=arr1[r];
//	return(arr3[p]);	
	
//	arr3[p]=arr1[r];
//return(arr3[p]);
	
	
}
    
   
    


