#include "main.cpp"

int myWORD[10][8][8] =
{
	{
		{ 0,0,0,0,1,1,1,1 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,1,1,1 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
	},
	{
		{ 0,0,0,0,1,1,1,1 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,1,1,1 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
	},
	{
		{ 0,0,0,0,1,1,1,1 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,1,1,1 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,1,1,1 },
	},
	{
		{ 1,1,1,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
	},
	{
		{ 1,1,1,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
	},
	{
		{ 1,1,1,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
	},
	{
		{ 1,1,1,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 1,1,0,1,0,0,0,0 },
		{ 1,0,0,1,0,0,0,0 },
		{ 1,0,0,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
	},
	{
		{ 0,0,0,0,1,1,1,1 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,1,1 },
		{ 0,0,0,0,1,0,0,1 },
		{ 0,0,0,0,1,0,0,1 },
		{ 0,0,0,0,1,1,1,1 },
	},
	{
		{ 0,0,0,0,0,1,0,0 },
		{ 0,0,0,0,0,1,0,0 },
		{ 0,0,0,0,0,1,0,0 },
		{ 0,0,0,0,0,1,0,0 },
		{ 0,0,1,1,1,1,0,0 },
		{ 0,0,1,0,0,1,0,0 },
		{ 0,0,1,0,0,1,0,0 },
		{ 0,0,1,1,1,1,0,0 },
	},
	{
		{ 0,0,1,0,0,0,0,0 },
		{ 0,0,1,0,0,0,0,0 },
		{ 0,0,1,0,0,0,0,0 },
		{ 0,0,1,0,0,0,0,0 },
		{ 0,0,1,1,1,1,0,0 },
		{ 0,0,1,0,0,1,0,0 },
		{ 0,0,1,0,0,1,0,0 },
		{ 0,0,1,1,1,1,0,0 },
	}
};

int getSeed(int data[16][64])
{
	return 0;
}