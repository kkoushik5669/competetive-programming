while(B - A > 4)
{
    int m1 = (A + B) / 2;
    int m2 = (A + B) / 2 + 1;

    if(f(m1) > f(m2))
       A = m1;
    else
       B = m2;
}

ans = inf;

for(int i = A; i <= B; i++)
    ans = min(ans , f(i));
