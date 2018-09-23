//============================================================================
// Name        : Colisões.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "vector3.h"
#include <stdio.h>
#include "BoundingBox.h"
#include "BoundingSphere.h"

int main() {
	int nPontos,nOpcao;
	double x,y,z,radius1,radius2;
	vector3 sCenter,vTransicao;
	vector3 bMax(0,0,0);
	vector3 bMin(1000,1000,1000);

	vector3 a(-1,-1,-1);
	vector3 b(1,1,1);


	BoundingBox boxA(a,b);
	BoundingBox boxB(a,b);
	BoundingSphere sphereA(b,1);
	BoundingSphere sphereB(b,1);

	std::cout << "Escolha a colisão: \n1)AABB X AABB \n2)SPHERE X AABB  \n3)SPHERE X SPHERE" << std::endl;
	scanf("%d", &nOpcao);
	//---------------------------------------AABB X AABB----------------------------------------------------------------------
	if(nOpcao == 1)
	{
	std::cout << "Digite a quantidade de pontos desejados" << std::endl;
	scanf("%d", &nPontos);
	for(int l = 0;l < 2;l++)
		{
		for(int i = 1; i < nPontos+1 ;i++)
		{
			std::cout << "insira o "<<i<<"º ponto" << std::endl;
			for(int j = 0;j < 3;j++){
				if(j==0)
				{
				std::cout << "insira X" << std::endl;
				scanf("%lf", &x);
				vTransicao.x = x;
				if(vTransicao.x >= bMax.x) bMax.x =vTransicao.x;
				if(vTransicao.x <= bMin.x) bMin.x =vTransicao.x;
				}
				if(j==1)
				{
				std::cout << "insira Y" << std::endl;
				scanf("%lf", &y);
				vTransicao.y = y;
				if(vTransicao.y >= bMax.y) bMax.y =vTransicao.y;
				if(vTransicao.y <= bMin.y) bMin.y =vTransicao.y;
				}
				if(j==2)
				{
				std::cout << "insira Z" << std::endl;
				scanf("%lf", &z);
				vTransicao.z = z;
				if(vTransicao.z >= bMax.z) bMax.z =vTransicao.z;
				if(vTransicao.z <= bMin.z) bMin.z =vTransicao.z;
				}
			}

			std::cout << "("<<x<<","<<y<<","<<z<<")foi inserido " << std::endl;
			std::cout << "Max = " << bMax <<  std::endl;
			std::cout << "Min = " << bMin <<  std::endl;
		}
		if(l == 0)
		{
			BoundingBox boxA(bMin,bMax);
			std::cout << "L = 0" << std::endl;
			bMax = 0;
			bMin = 1000;
		}else
		{
			BoundingBox boxB(bMin,bMax);
			if (boxA.intercept(boxB)){
			std::cout << "Colide" << std::endl;
			}else
			{
			std::cout << "Não Colide" << std::endl;
			}
		}
		}
	}
	//---------------------------------------SPHERE X AABB----------------------------------------------------------------------
	else if(nOpcao == 2)
	{

		std::cout << "Digite a quantidade de pontos desejados." << std::endl;
			scanf("%d", &nPontos);
			for(int l = 0;l < 2;l++)
					{

					for(int i = 1; i < nPontos+1 ;i++)
					{
						std::cout << "insira o "<<i<<"º ponto" << std::endl;
						for(int j = 0;j < 3;j++){
							if(j==0)
							{
							std::cout << "insira X" << std::endl;
							scanf("%lf", &x);
							vTransicao.x = x;
							if(vTransicao.x >= bMax.x) bMax.x =vTransicao.x;
							if(vTransicao.x <= bMin.x) bMin.x =vTransicao.x;
							}
							if(j==1)
							{
							std::cout << "insira Y" << std::endl;
							scanf("%lf", &y);
							vTransicao.y = y;
							if(vTransicao.y >= bMax.y) bMax.y =vTransicao.y;
							if(vTransicao.y <= bMin.y) bMin.y =vTransicao.y;
							}
							if(j==2)
							{
							std::cout << "insira Z" << std::endl;
							scanf("%lf", &z);
							vTransicao.z = z;
							if(vTransicao.z >= bMax.z) bMax.z =vTransicao.z;
							if(vTransicao.z <= bMin.z) bMin.z =vTransicao.z;
							}
						}

					std::cout << "("<<x<<","<<y<<","<<z<<")foi inserido " << std::endl;
					std::cout << "Max = " << bMax <<  std::endl;
					std::cout << "Min = " << bMin <<  std::endl;

					}
					if(l == 0)
					{
						BoundingBox boxA(bMin,bMax);
						std::cout << "L = 0" << std::endl;
						bMax = 0;
						bMin = 1000;
					}else
					{
						radius1 = (bMax.length(bMin))/2;
						sCenter.x =(bMax.x + bMin.x)/2;
						sCenter.y =(bMax.y + bMin.y)/2;
						sCenter.z =(bMax.z + bMin.z)/2;
						BoundingSphere sphereA(sCenter,radius1);
						if (sphereA.intercept(boxB)){
						std::cout << "Colide" << std::endl;
						}else
						{
						std::cout << "Não Colide" << std::endl;
						}
					}
					}
	//---------------------------------------SPHERE X SPHERE----------------------------------------------------------------------
	}else if(nOpcao == 3)
	{
		std::cout << "Digite a quantidade de pontos desejados" << std::endl;
					scanf("%d", &nPontos);
					for(int l = 0;l < 2;l++)
							{
							for(int i = 1; i < nPontos+1 ;i++)
							{
								std::cout << "insira o "<<i<<"º ponto" << std::endl;
								for(int j = 0;j < 3;j++){
									if(j==0)
									{
									std::cout << "insira X" << std::endl;
									scanf("%lf", &x);
									vTransicao.x = x;
									if(vTransicao.x >= bMax.x) bMax.x =vTransicao.x;
									if(vTransicao.x <= bMin.x) bMin.x =vTransicao.x;
									}
									if(j==1)
									{
									std::cout << "insira Y" << std::endl;
									scanf("%lf", &y);
									vTransicao.y = y;
									if(vTransicao.y >= bMax.y) bMax.y =vTransicao.y;
									if(vTransicao.y <= bMin.y) bMin.y =vTransicao.y;
									}
									if(j==2)
									{
									std::cout << "insira Z" << std::endl;
									scanf("%lf", &z);
									vTransicao.z = z;
									if(vTransicao.z >= bMax.z) bMax.z =vTransicao.z;
									if(vTransicao.z <= bMin.z) bMin.z =vTransicao.z;
									}
								}

								std::cout << "("<<x<<","<<y<<","<<z<<")foi inserido " << std::endl;
								std::cout << "Max = " << bMax <<  std::endl;
								std::cout << "Min = " << bMin <<  std::endl;
							}
							if(l == 0)
							{
								radius1 = (bMax.length(bMin))/2;
								sCenter.x =(bMax.x + bMin.x)/2;
								sCenter.y =(bMax.y + bMin.y)/2;
								sCenter.z =(bMax.z + bMin.z)/2;
								BoundingSphere spherebB(sCenter,radius1);
								std::cout << "L = 0" << std::endl;
								bMax = 0;
								bMin = 1000;

							}else
							{
								radius2 = (bMax.length(bMin))/2;
								sCenter.x =(bMax.x + bMin.x)/2;
								sCenter.y =(bMax.y + bMin.y)/2;
								sCenter.z =(bMax.z + bMin.z)/2;
								BoundingSphere sphereA(sCenter,radius2);
								if (sphereA.intercept(sphereB)){
								std::cout << "Colide" << std::endl;
								}else
								{
								std::cout << "Não Colide" << std::endl;
								}
							}
							}
	}else
	{
		std::cout << "Porfavor entre com um numero de 1 --> 3" << std::endl;
	}

	return 0;
}
