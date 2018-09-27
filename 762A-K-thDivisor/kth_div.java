import java.util.*; 
public class kth_div { 
   public static void main(String args[]) { 
       Scanner ob=new Scanner(System.in); 
       long n=ob.nextLong(),i,md=-1; 
       int k=ob.nextInt(),c=0; 
       
       //for(i=1;i<=n;i++) { // change condition to  i*i <= n 
       //   if(n%i==0) { c++; } 
       //   if(c==k) { md=i; break; } 
       //}
        for(i = 1; i * i <=n;++i) {  //  i*i <=n ---> i <= sqrt(n) <= sqrt(10^15) < 3.2*10^7
          if (n%i==0){c++;}
          if (c == k){md = i; break;}
        } 

        if ( md == -1 )
        {
               --i;
            if (i*i==n)c--;
           // reverse order
           for(  ;  i > 0; --i)
           {
                  if (n % i == 0 ){ c++; }
                  if (c == k){ md = n / i ; break;}
            }
         }

         System.out.println(md); 
   } 
}