
char * breakPalindrome(char * palindrome)
{
    
    int first = 0, last ,i=0;
    for(;palindrome[i] != '\0' ; i++);
    last = i-1;
    if(first==last)
        return "";
    //printf("%c %c",palindrome[first],palindrome[last]);
    while(palindrome[first]=='a' && first<last)
    {
        first++;
        last--;
    }
    if(first>=last)
        palindrome[i-1]++;
    else
        palindrome[first]='a';
    return palindrome;
}