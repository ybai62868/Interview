char *my_inet_ntoa(unsigned long inaddr)
{
    int a[4],i;
    char str[233];
    char b[20],c[15],d[10],e[5];
    a[0]=((inaddr & 0xff000000)>>24);
    a[1]=((inaddr & 0x00ff0000)>>16);
    a[2]=((inaddr & 0x0000ff00)>>8);
    a[3]=((inaddr & 0x000000ff)>>0);
    
//    itoa(a[0],b,10);
    sprintf(b,"%d",a[0]);
    strcat(b,".");
//    itoa(a[1],c,10);
    sprintf(c,"%d",a[1]);
    strcat(c,".");
//    itoa(a[2],d,10);
    sprintf(d,"%d",a[2]);
    strcat(d,".");
//    itoa(a[3],e,10);
    sprintf(e,"%d",a[3]);
        
    strcat(str,strcat(b,strcat(c,strcat(d,e))));
    return str;
    
}
