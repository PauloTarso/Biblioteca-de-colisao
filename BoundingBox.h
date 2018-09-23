/*
 * BoundingBox.h
 *
 *  Created on: 9 de jul de 2017
 *      Author: paulo
 */

#ifndef BOUNDINGBOX_H_
#define BOUNDINGBOX_H_
#include "vector3.h"
#include <limits>

class BoundingBox {
public:
	vector3 bMin, bMax, bCenter;
	double height, width , depth;


	BoundingBox(vector3 _bMin,vector3 _bMax)
	{
		bMax = _bMax;
		bMin = _bMin;
		dimentions();
		bCenter = ((bMin+bMax)*.5);
	}
	BoundingBox()
	{
		// TODO resolver problema com a 1 inserção
		bMax = 0;
		bMin = 0;
		width = std::abs(bMax.x - bMin.x);
		height = std::abs(bMax.y - bMin.y);
		depth = std::abs(bMax.z - bMin.z);
	}
	void dimentions()
	{
		width = std::abs(bMax.x - bMin.x);
		height = std::abs(bMax.y - bMin.y);
		depth = std::abs(bMax.z - bMin.z);
	}
	void insertV3(vector3 _v)
	{

		if(_v.x > bMax.x) bMax.x =_v.x;
		if(_v.y > bMax.y) bMax.y =_v.y;
		if(_v.z > bMax.z) bMax.z =_v.z;
		if(_v.x < bMin.x) bMin.x =_v.x;
		if(_v.y < bMin.y) bMin.y =_v.y;
		if(_v.z < bMin.z) bMin.z =_v.z;

	};

	bool intercept(BoundingBox(_box))
	{
		vector3 currentMin = _box.bMin;
		//std::cout << bMin <<std::endl;
		vector3 currentMax = _box.bMax;
		//std::cout << bMax <<std::endl;
		if (currentMin==bMin)
		{
			//std::cout << "1" <<std::endl;
			return true;
		}

		if (currentMax==bMax)
		{
			//std::cout << "2" <<std::endl;
			return true;
		}
		if ((std::abs((bCenter.x + _box.bCenter.x)<=(width/2+_box.width/2)))&&
			(std::abs((bCenter.y + _box.bCenter.y)<=(height/2+_box.height/2)))&&
			(std::abs((bCenter.z + _box.bCenter.z)<=(depth/2+_box.depth/2))))
		{
			std::cout << "3" <<std::endl;
			return true;
		}
		return false;
	};

	//bool aabb = false;


	virtual ~BoundingBox(){};
};

#endif /* BOUNDINGBOX_H_ */
