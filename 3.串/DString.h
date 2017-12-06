   using namespace std;
   #include <string.h>
   typedef struct
   {
    char *str;
    int maxLength;
    int length;
    }DString;

void Initiate(DString *S,int max,char *string)
  {
    int i;
    S->str=(char*)malloc(sizeof(char)*max);
    S->maxLength=max;
    S->length=strlen(string);
    for(i=0;i<S->length;i++)
      S->str[i]=string[i];
  }

int Insert(DString *S,int pos,DString T)
 {
   int i;
   char *p;

   if(pos<0||pos>S->length)
   {
     printf("pos error!\n");
     return 0;
    }
    else
    {
      if(S->length+T.length>S->maxLength)
       {
        p=(char *)realloc(S->str,(S->length+T.length)*sizeof(char));
        if(p==NULL)
         {
          printf("The memory is not enough!\n");
          return 0;
          }
        }

       for(i=S->length-1;i>=pos;i--)
        S->str[i+T.length]=S->str[i];

      for(i=0;i<T.length;i++)
        S->str[pos+i]=T.str[i];

      S->length=S->length+T.length;
      return 1;
    }
   }

int Delete(DString *S,int pos,int len)
 {
   int i;
   if(S->length<=0)
   {
     printf("String is empty!\n");
     return 0;
    }
    else  if(pos<0||len<0||pos+len>S->length)
    {
      printf("pos or len error!\n");
      return 0;
    }
    else
    {
      for(i=pos+len;i<=S->length-1;i++)
        S->str[i-len]=S->str[i];

      S->length=S->length-len;
      return 1;
    }
   }

 int SubString(DString S, int pos,int len, DString *T)
  {
   int i, n;
    n=S.length;
    if(pos<0||len<0||pos+len>n)
    {
       printf("pos or len error!\n");
       return   0;
     }
     else
     {
       for(i=0;i<len;i++)
         T->str[i]=S.str[pos+i];
       T->length=len;
       return 1;
    }
   }

   void Destrory(DString *S)
    {
     free(S->str);
     S->maxLength=0;
     S->length=0;
    }



