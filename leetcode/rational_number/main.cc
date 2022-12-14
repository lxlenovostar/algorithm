#include <stdio.h>
#include <iostream>
using namespace std;

//这个是求最大公因数咯 
int gcd(long long int p, long long int q)
{
	if (p%q == 0)
		return q;
	else
		return gcd(q, p%q);	
}
 
 
int main()
{
	long long int a, b,suma = 0, sumb = 1,m;
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lld/%lld", &a, &b);
        std::cout << "what1 suma:" << suma << " sumb: " << sumb << std::endl;
        //不仅要输入分子分母，还要让其与前面的一起另一个分数加和
        //suma为分子，通分乘以分母
		suma *= b;
        //下个分子乘以上一个分母，
		suma = (suma + a*sumb);
		//分母相乘通分
		sumb *= b;	
        //化简分子和分母，就是求出最大公因数后两者一起化简，相当于求最小公倍数
		m = gcd(suma, sumb);
        std::cout << "what2 suma:" << suma << " sumb: " << sumb << std::endl;
		suma /= m;
		sumb /= m;
        std::cout << "what2 suma:" << suma << " sumb: " << sumb << " m: " << m << std::endl;
	}
 
 
 
    //真分数情况  格式的输出注意
	if (suma&&(suma/sumb==0)){
		if(sumb>0) printf("%lld/%lld\n", suma, sumb);
		if(sumb<0) printf("%lld/%lld\n", -suma, -sumb);
	}
    //假分数  要输出整数和分数
	else if (suma%sumb==0)
		printf("%lld\n", suma / sumb);		//一个整数
	else					                //整数和分数
	{
	    if (suma/sumb<0){
	        if(sumb>0) printf("%lld %lld/%lld\n",suma/sumb,suma%sumb,sumb);
	        if(sumb<0) printf("%lld %lld/%lld\n",suma/sumb,-suma%sumb,-sumb);
	    }
		else printf("%lld %lld/%lld\n",suma/sumb,suma%sumb,sumb);
	}
	return 0;
}