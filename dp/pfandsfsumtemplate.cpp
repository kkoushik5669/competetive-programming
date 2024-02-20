vector<ll>findpre(vector<ll>a)
{
    int n=a.size();
    vector<ll>pf(n);
    pf[0]=a[0];
    for(int i=1;i<n;i++)pf[i]=pf[i-1]+a[i];
  return pf;
}
vector<ll>findsuf(vector<ll>a)
{
    int n=a.size();
    vector<ll>sf(n);
    sf[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){sf[i]=sf[i+1]+a[i];}
  return sf;
}
