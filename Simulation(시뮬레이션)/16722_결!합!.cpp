#include <bits/stdc++.h>
using namespace std;

struct THING
{
   string shape,color,bColor;
};
THING arr[10];
int ans[10][10][10]={0,};

bool is_possible(int i,int j,int k)
{
    if((arr[i].shape==arr[j].shape && arr[j].shape==arr[k].shape && arr[k].shape==arr[i].shape) ||
       (arr[i].shape!=arr[j].shape && arr[j].shape!=arr[k].shape && arr[k].shape!=arr[i].shape) )
    if((arr[i].color==arr[j].color && arr[j].color==arr[k].color && arr[k].color==arr[i].color) ||
       (arr[i].color!=arr[j].color && arr[j].color!=arr[k].color && arr[k].color!=arr[i].color))
    if((arr[i].bColor==arr[j].bColor && arr[j].bColor==arr[k].bColor && arr[k].bColor==arr[i].bColor) ||
        (arr[i].bColor!=arr[j].bColor && arr[j].bColor!=arr[k].bColor && arr[k].bColor!=arr[i].bColor))
        return true;
    return false;
}

bool isG()
{
    for(int i=1;i<10;i++)
        for(int j=i+1;j<10;j++)
            for(int k=j+1;k<10;k++)
                if(ans[i][j][k]) return false;
    return true;
}

int main()
{
    for(int i=1;i<10;i++)
    {
        string s[3];
        for(int j=0;j<3;j++)
            cin>>s[j];
        arr[i]={s[0],s[1],s[2]};
    }
    for(int i=1;i<10;i++)
        for(int j=i+1;j<10;j++)
            for(int k=j+1;k<10;k++)
            if(is_possible(i,j,k)) ans[i][j][k]=true;
     /*for(int i=1;i<10;i++)
        for(int j=i+1;j<10;j++)
            for(int k=j+1;k<10;k++)
                if(ans[i][j][k]) cout<<i<<","<<j<<","<<k<<endl;*/

    int q,score=0;
    bool haveG=false;
    cin>>q;
    while(q--)
    {
        char c;
        int tmp[3];
        cin>>c;

        if(c=='H')
        {
            for(int i=0;i<3;i++)cin>>tmp[i];
            sort(tmp,tmp+3);
            if(ans[tmp[0]][tmp[1]][tmp[2]])
            {
                ans[tmp[0]][tmp[1]][tmp[2]]=0;
                score+=1;
            }
            else score-=1;
        }
        else
        {
            if(isG()&&!haveG) 
                {
                    score+=3;
                    haveG=true;
                }
            else score-=1;
        }
    }
    cout<<score;
}
