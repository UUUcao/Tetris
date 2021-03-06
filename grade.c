

void setLEVEL()
{
    if(GRADE<=250)
    {
        LEVEL=1;
        dropTIME=oneTIME;
    }
    else if(GRADE<=670)
    {
        LEVEL=2;
        dropTIME=twoTIME;
    }
        else if(GRADE<=1200)
    {
        LEVEL=3;
        dropTIME=threeTIME;
    }
        else if(GRADE<=2200)
    {
        LEVEL=4;
        dropTIME=fourTIME;
    }
        else if(GRADE<=5000)
    {
        LEVEL=5;
        dropTIME=fiveTIME;
    }
        else if(GRADE>500)
    {
        LEVEL=6;
        dropTIME=sixTIME;
    }
}


////Win Test Function
int WIN_TEST()
{
    int i,j,k;
    int LINE;
    queue_mark=0;
    for(i=4;i<=23;i++)
    {
        LINE=0;
        for(j=0;j<12;j++)
        {
            if(a[i][j]>STAY)
            {
                LINE++;
            }
        }
        if(LINE==12)
        {
            EnQueue(&Q,i);
            queue_mark++;
        }
    }
    k=QueueEmpty(Q);//Empty=1,Not Empty=0;
    if(k==1)
    {
        return 0;
    }
    else
    {
        printf_miss();
        while(k!=1)
        {
            DeQueue(&Q,&i);
            for(;i>4;i--)
            {
                for(j=0;j<12;j++)
                {
                    a[i][j]=a[i-1][j];
                }
            }
            GRADE+=(10+2*LEVEL);
            k=QueueEmpty(Q);
        }
    }
    if(queue_mark==2)
    {
        GRADE+=(3*LEVEL+20);
    }
    if(queue_mark==3)
    {
        GRADE+=(4*LEVEL+35);
    }
    if(queue_mark==4)
    {
        GRADE+=(5*LEVEL+50);
    }
    setLEVEL();
    drawLEFT();
}
