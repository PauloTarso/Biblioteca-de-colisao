/*
 * BoundingSphere.h
 *
 *  Created on: 9 de jul de 2017
 *      Author: paulo
 */

#ifndef BOUNDINGSPHERE_H_
#define BOUNDINGSPHERE_H_
#include "vector3.h"
#include "BoundingBox.h"
class BoundingSphere {
public:
	double radius;
	vector3 bMin,bMax,sCenter,cPoint,relCenter,dist;

	BoundingSphere(vector3 _center,double _radius)
	{
		sCenter = _center;
		radius = _radius;
	}
	BoundingSphere();



	void dimentions()
	{
		//no caso de multiplo pontos
		//diameter = std::abs( bMax.length(bMin));
		//radius = std::abs(diameter/2);
	}
	bool intercept(BoundingBox _b)
	{
	relCenter = sCenter -_b.bCenter;
	//Verifica o X
	if(relCenter.x > _b.width/2)
	{
		cPoint.x = _b.width/2;
	}else if (relCenter.x < _b.width/2)
	{
		cPoint.x = -_b.width/2;
	}
	else
	{
		cPoint.x = relCenter.x;
	}

	//Verifica o Y
	if(relCenter.y > _b.height/2)
	{
		cPoint.y = _b.height/2;
	}else if (relCenter.y < _b.height/2)
	{
		cPoint.y = -_b.height/2;
	}
	else
	{
		cPoint.y = relCenter.y;
	}

	//Verifica o Z
	if(relCenter.z > _b.bCenter.length(sCenter)/2)
	{
		cPoint.z = _b.bCenter.length(sCenter)/2;
	}else if (relCenter.z < _b.bCenter.length(sCenter)/2)
	{
		cPoint.z = -_b.bCenter.length(sCenter)/2;
	}
	else
	{
		cPoint.z = relCenter.z;
	}
	std::cout << cPoint << std::endl;

	dist = relCenter - cPoint;

	if (dist.x*dist.x + dist.y*dist.y + dist.z*dist.z < radius*radius)
	    return true;
	else
	    return false;

	}

	bool intercept(BoundingSphere _b)
	{
	if(std::abs(_b.radius + radius) >= std::abs(sCenter.length(_b.sCenter)))
		{
			std::cout << radius << std::endl;
			std::cout << _b.radius + radius << std::endl;
			std::cout << sCenter.length(_b.sCenter) << std::endl;
			return true;
		}

	return false;

	}
	virtual ~BoundingSphere();
};

#endif /* BOUNDINGSPHERE_H_ */
