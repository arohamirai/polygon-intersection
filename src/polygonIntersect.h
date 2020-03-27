#ifndef POLYGONINTERSECT_H
#define POLYGONINTERSECT_H

#include <cxcore.h>
#include <vector>

float distPoint( cv::Point2i p1, cv::Point2i p2 ) ;
float distPoint(cv::Point2f p1,cv::Point2f p2) ;
bool segementIntersection(cv::Point2i p0_seg0,cv::Point2i p1_seg0,cv::Point2i p0_seg1,cv::Point2i p1_seg1,cv::Point2i * intersection) ;
bool segementIntersection(cv::Point2f p0_seg0,cv::Point2f p1_seg0,cv::Point2f p0_seg1,cv::Point2f p1_seg1,cv::Point2f * intersection) ;

bool pointInPolygon(cv::Point2i p,const cv::Point2i * points,int n) ;
bool pointInPolygon(cv::Point2f p,const cv::Point2f * points,int n) ;


#define MAX_POINT_POLYGON 64
struct Polygon {
        //std::vector<cv::Point2i> pt;
        cv::Point2i pt[MAX_POINT_POLYGON];
	int     n;

        Polygon(int n_ = 0 ) { assert(n_>= 0 && n_ < MAX_POINT_POLYGON); n = n_;}
        virtual ~Polygon() {}

	void clear() { n = 0; }
        void add(const cv::Point2i &p) {if(n < MAX_POINT_POLYGON) pt[n++] = p;}
        void push_back(const cv::Point2i &p) {add(p);}
	int size() const { return n;}
        cv::Point2i getCenter() const ;
        const cv::Point2i & operator[] (int index) const { assert(index >= 0 && index < n); return pt[index];}
        cv::Point2i& operator[] (int index) { assert(index >= 0 && index < n); return pt[index]; }
	void pointsOrdered() ;
	float area() const ;
        bool pointIsInPolygon(cv::Point2i p) const ;
};


void intersectPolygon( const cv::Point2i * poly0, int n0,const cv::Point2i * poly1,int n1, Polygon & inter ) ;
void intersectPolygon( const Polygon & poly0, const Polygon & poly1, Polygon & inter ) ;
void intersectPolygonSHPC(const Polygon * sub,const Polygon* clip,Polygon* res) ;
void intersectPolygonSHPC(const Polygon & sub,const Polygon& clip,Polygon& res) ;

#endif //
