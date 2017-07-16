// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>

using namespace std;

static vector<int> vecRule;
static vector<int> vecValue;

int getCost(int& nTmpMin,int nPersonNum,int nPrice,int nLeftCost)
{
	static int nFreight = 5;
	int nTotalCost = nPersonNum*nPrice;
	int nSize = vecRule.size();
	int nRealCost =nTotalCost;
	int nTag =0;

	for(int i =0;i< nSize;i++)
	{
		if(nTotalCost>=vecRule[i])
			nRealCost = nTotalCost - vecValue[i];
	}

	nRealCost+=(nLeftCost+nFreight);
	
	if(nTmpMin > nRealCost)
	{
		nTag = 1;
		nTmpMin = nRealCost;
	}

	return nTag;
}
int getMinCost(int nPerson,int nPrice)
{
	int		nMin = 0,nTmp = 0,iRet;
	vector<int>pCost(nPerson+1);
	vector<int>pMethod(nPerson+1);

	for(int i=1;i<=nPerson;i++)
	{
		nTmp = 99999;
		for(int j=1;j<=i;j++)
		{
			iRet = getCost(nTmp,j,nPrice,pCost[i-j]);
			if(iRet == 1)
				pMethod[i] = j;
		}
		pCost[i] = nTmp;
	}
	nMin = pCost[nPerson];

	while(nPerson)
	{
		printf("%d ",pMethod[nPerson]);
		nPerson -=pMethod[nPerson];
	}
	return nMin;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vecRule.push_back(20);
	vecValue.push_back(10);

	vecRule.push_back(30);
	vecValue.push_back(12);

	vecRule.push_back(40);
	vecValue.push_back(12);

	vecRule.push_back(50);
	vecValue.push_back(15);

	int iRet = getMinCost(40,15);
	printf("\n%d",iRet);

	getchar();
	return 0;
}

