bool isAnagram(char * s, char * t){

    int sarr[30]={};
    int tarr[30]={};
    if(strlen(s) != strlen(t)){
        return false;
    }

    for(int i = 0;i<strlen(s);i++){
        sarr[s[i]-97]++;
        tarr[t[i]-97]++;
    }
    for(int i = 0;i<30;i++){
        if(sarr[i]==tarr[i]){
            continue;
        }
        else{
            return false;
        }
    }
    
    return true;

}