
#ifndef WORLD_H
#define WORLD_H

#include <list>

#include "model.hpp"
#include "camera.hpp"
#include "light.hpp"
#include "mirror.hpp"
#include "listener.hpp"

#define WORLD_COLLISION_TYPES	16
#define WORLD_COLLISION_HITS	4

class World{
public:
	//collision methods
	enum{
		COLLISION_METHOD_SPHERE=1,
		COLLISION_METHOD_POLYGON=2,
		COLLISION_METHOD_BOX=3
	};

	//collision actions
	enum{
		COLLISION_RESPONSE_NONE=0,
		COLLISION_RESPONSE_STOP=1,
		COLLISION_RESPONSE_SLIDE=2,
		COLLISION_RESPONSE_SLIDEXZ=3,
	};

	void clearCollisions();
	void addCollision( int src_type,int dest_type,int method,int response );

	void update( float elapsed );
	void capture();
	void render( float tween );

	bool CheckLineOfSight( Object *src,Object *dest );
	bool hitTest( const Line &line,float radius,Object *obj,const Transform &tf,int method,Collision *curr_coll  );
	Object *traceRay( const Line &line,float radius,ObjCollision *curr_coll );

private:
	struct CollInfo{
		int dst_type,method,response;
	};

	vector<CollInfo> _collInfo[WORLD_COLLISION_TYPES];
	std::list<Object*> _objsByType[WORLD_COLLISION_TYPES];
	std::list<Object*> _objsByTypeSwappable[WORLD_COLLISION_TYPES];

	void collide( Object *src );
	void render( Camera *c,Mirror *m );
	void render( Model *m,const RenderContext &rc );
	void flushTransparent();

};

#endif