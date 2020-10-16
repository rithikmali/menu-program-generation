#include<stdio.h>

int main()
{
//changed
int a[4];
for(int k=0; k < 4; k++)
	a[k] = 1;
int ch1;
	a[0] = 1;
	while(a[0])
	{
		scanf("%d",&ch1);
		switch(ch1)
		{
		case 0:
			a[0]=0;
			break;
		case 1:
			printf("one\n");
		a[1] = 1;
		while(a[1])
		{
			scanf("%d",&ch1);
			switch(ch1)
			{
			case 0:
				a[1]=0;
				break;
		case 1:
			printf("oneone\n");
			break;
			case 2:
				printf("onetwo\n");
			a[2] = 1;
			while(a[2])
			{
				scanf("%d",&ch1);
				switch(ch1)
				{
				case 0:
					a[2]=0;
					break;
			case 1:
				printf("onetwothree\n");
				break;
				default:
					break;
				}
			}
			break;
		case 3:
			printf("onethree\n");
			break;
			default:
				break;
			}
		}
		break;
		case 2:
			printf("two\n");
		a[1] = 1;
		while(a[1])
		{
			scanf("%d",&ch1);
			switch(ch1)
			{
			case 0:
				a[1]=0;
				break;
			case 1:
				printf("aaa\n");
			a[2] = 1;
			while(a[2])
			{
				scanf("%d",&ch1);
				switch(ch1)
				{
				case 0:
					a[2]=0;
					break;
				case 1:
					printf("xxx\n");
				a[3] = 1;
				while(a[3])
				{
					scanf("%d",&ch1);
					switch(ch1)
					{
					case 0:
						a[3]=0;
						break;
				case 1:
					printf("zzz\n");
					break;
					default:
						break;
					}
				}
				break;
			case 2:
				printf("yyy\n");
				break;
				default:
					break;
				}
			}
			break;
		case 2:
			printf("bbb\n");
			break;
		case 3:
			printf("ccc\n");
			break;
			default:
				break;
			}
		}
		break;
		case 3:
			printf("three\n");
		a[1] = 1;
		while(a[1])
		{
			scanf("%d",&ch1);
			switch(ch1)
			{
			case 0:
				a[1]=0;
				break;
		case 1:
			printf("abc\n");
			break;
			case 2:
				printf("pqr\n");
			a[2] = 1;
			while(a[2])
			{
				scanf("%d",&ch1);
				switch(ch1)
				{
				case 0:
					a[2]=0;
					break;
				case 1:
					printf("ppp\n");
				a[3] = 1;
				while(a[3])
				{
					scanf("%d",&ch1);
					switch(ch1)
					{
					case 0:
						a[3]=0;
						break;
				case 1:
					printf("qqq\n");
					break;
					default:
						break;
					}
				}
				break;
				default:
					break;
				}
			}
			break;
		case 3:
			printf("rrr\n");
			break;
			default:
				break;
			}
		}
		break;
	case 4:
		printf("four\n");
		break;
	case 5:
		printf("five\n");
		break;
		default:
			break;
		}
	}

return 0;
}
