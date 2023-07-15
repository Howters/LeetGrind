char * longestCommonPrefix(char ** strs, int strsSize){
int len = 200;
char *string = malloc(sizeof(char) * len +1 );
char *prefix = malloc(sizeof(char) * len +1 );

  for ( int i =0 ; i < strsSize; i++){
  int len = strlen(strs[i]);
  if(len == 0 ){
    prefix[0] = '\0';

  }
  strcpy(string,strs[i]);
  int index = 0;
  if (i==0){
    strcpy(prefix,strs[i]);
  }

  if(i>0){
      for(int j =0; j<len ; j ++){
        if(string[0]=='\0'){
          prefix[0] = '\0';
          return 0;
        }
        if(prefix[j] == string[j] && string[j+1]!='\0' && string[j]){
          index ++;
        }
        else if (prefix[j] == string[j] && string[j+1] == '\0'){
          prefix[j+1] = '\0';

        }
        else{
          prefix[j] = '\0';
        }
      }
  }
    // printf("%s %s",strings,prefix);

    }
    return prefix;
    return;
    }
