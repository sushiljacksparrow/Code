

bool knows[N][N];
bool invited[N] = {true};
int knows_guest[N];

bool eliminated;
int invited = N;
do
{
	eliminated = true;
	for(int i=0;i<N;i++)
	{
		if(invited[i]==false)
			continue;
		if(knows_guest[i]<5 || know_gues[i] > invited - 5)
		{
			eliminated = true;
			invited--;
			invited[i]=false;
			for(int j=0;j<N;j++)
				if(knows[i][j])
					knows_gues[j]--;
		}
	}
} while(eliminated==true);