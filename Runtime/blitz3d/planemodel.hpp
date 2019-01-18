
#ifndef PLANEMODEL_H
#define PLANEMODEL_H

#include "brush.hpp"
#include "model.hpp"

class PlaneModel : public Model {
	public:
	PlaneModel(int sub_divs);
	PlaneModel(const PlaneModel& t);
	~PlaneModel();
	Entity* clone()
	{
		return new PlaneModel(*this);
	}

	//model interface
	bool render(const RenderContext& rc);

	//object interface
	bool collide(const Line& line, float radius, Collision* curr_coll, const Transform& tf);

	Plane getRenderPlane() const;

	private:
	struct Rep;

	Rep* rep;

	virtual PlaneModel* getPlaneModel()
	{
		return this;
	}
};

#endif