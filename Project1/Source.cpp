
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
#define INF INT_MAX 

// tested with sample files only in .txt -- 
// doesnt deal with negative values yet -- donneeee 
// doesnt deal with line intersecting another line multiple times --------------- 

float prec(float var)
{
	float value = (int)(var * 100 + .5);
	return (float)value / 100;
}

class Point
{
public:
	//Default constructor
	Point();
	Point(float new_x, float new_y);
	void printpoint();
	void setpoint(float new_x, float new_y);
	//Accessors
	/*Point(Point& obj)
	{
		xCOORD = obj.xCOORD;
		yCOORD = obj.yCOORD;
	}*/
	float GetX();
	bool compare(Point& P1)
	{
		if (P1.xCOORD == this->xCOORD && P1.yCOORD == this->yCOORD)
			return true;
		else return false;
	}
	void operator=(const Point& P)
	{

		this->xCOORD = P.xCOORD;
		this->yCOORD = P.yCOORD;

	}
	float GetY();
	//Mutators
	void SetX(float x);
	void SetY(float Y);

	Point(Point& P)
	{
		xCOORD = P.xCOORD;
		yCOORD = P.yCOORD;
	}
private:

	float xCOORD, yCOORD;
};


//INITIALIZES
Point::Point() :xCOORD(INF), yCOORD(INF)
{
	//default constructor
	//does nothing
}
void Point::printpoint()
{
	cout << "(" << xCOORD << ", " << yCOORD << ")";

}

Point::Point(float new_x, float new_y)
{
	//	setprecision(2);
	xCOORD = new_x;
	yCOORD = new_y;
}
void Point::setpoint(float new_x, float new_y)
{

	xCOORD = new_x;
	yCOORD = new_y;
}

//MUTATOR FUNCTIONS
void Point::SetX(float x)
{

	xCOORD = x;
}
void Point::SetY(float y)
{

	yCOORD = y;
}

float Point::GetX()
{
	return xCOORD;
}
float Point::GetY()
{
	return yCOORD;
}



// LINE CLASS 
class Line
{
public:
	Line();
	/*Line(Line& obj)
	{
		p1 = obj.p1;
		p2 =obj.p2;
	}*/
	float gradient()
	{
		float x1, x2, y1, y2;
		x1 = p1.GetX();
		x2 = p2.GetX();
		y1 = p1.GetY();
		y2 = p2.GetY();
		float m = (y2 - y1) / (x2 - x1); // gradient
		return m;
	}
	float intercept()
	{
		float x1, x2 = 0;
		float  y1, y2 = 0;
		x1 = p1.GetX();
		y1 = p1.GetY();
		float m = gradient();
		float c1 = y1 - (m)* x1;
		return c1;
	}
	float calculatearea_line()
	{
		// length 1 
		float a = p1.GetY();
		// length 2 
		float b = p2.GetY();
		// height
		float val = p2.GetX();
		float val2 = p1.GetX();
		float h;
		if (p2.GetX() > 0 && p1.GetX() < 0)
		{
			val2 = val2 * -1;
			h = val2 + val;
		}
		else
		{
			if (p2.GetX() < 0)
			{
				val = p2.GetX() * -1;
			}
			if (p1.GetX() < 0)
			{
				val2 = p1.GetX() * -1;
			}

			if (val2 > val)
				h = val2 - val;
			else
				h = val - val2;

		}

		return  ((a + b) * h) / 2;
	}
	float calculatearea_middle(float x, float y)
	{
		float x1 = x;// Intersection x 
		float x2 = p2.GetX(); // p2 x
		float y1 = y; // intersection y
		float y2 = p2.GetY(); // p2 y
		float h;
		if (x2 > 0 && x1 < 0)
		{
			x1 = x1 * -1;
			h = x2 + x1;
		}
		else
		{
			if (x2 < 0)
			{
				x2 = x2 * -1;

			}
			if (x1 < 0)
			{
				x1 = x1 * -1;
			}

			if (x1 > x2)
				h = x1 - x2;
			else
				h = x2 - x1;
		}



		return ((y2 + y) * h) / 2
			;
	}

	float calculatearea_middle2(float x, float y)
	{
		float x1 = x;// Intersection x 
		float x2 = p1.GetX(); // p2 x
		float y1 = y; // intersection y
		float y2 = p1.GetY(); // p2 y
		float h;
		if (x2 > 0 && x1 < 0)
		{
			x1 = x1 * -1;
			h = x1 + x2;
		}
		else
		{
			if (x2 < 0)
			{
				x2 = x2 * -1;

			}
			if (x1 < 0)
			{
				x1 = x1 * -1;
			}

			if (x1 > x2)
				h = x1 - x2;
			else
				h = x2 - x1;
		}


		return ((y2 + y) * h) / 2
			;
	}
	float calculatearea_middle3(float x, float y, float xx, float yy)
	{
		float x1 = x;// Intersection x 
		float x2 = xx; // p2 x
		float y1 = y; // intersection y
		float y2 = yy; // p2 y
		float h;
		if (x2 > 0 && x1 < 0)
		{
			x1 = x1 * -1;
			h = x2 + x1;
		}
		else
		{
			if (x2 < 0)
			{
				x2 = x2 * -1;

			}
			if (x1 < 0)
			{
				x1 = x1 * -1;
			}

			if (x1 > x2)
				h = x1 - x2;
			else
				h = x2 - x1;
		}



		return ((y2 + y) * h) / 2
			;
	}
	void operator=(Line& L)
	{

		//Point p1; Point p2;
		this->p1.SetX(L.p1.GetX());
		this->p1.SetY(L.getpoint().GetY());
		this->p2.SetX(L.getpoint2().GetX());
		this->p2.SetY(L.getpoint2().GetY());
	}

	Point getpoint();
	Point getpoint2();
	Line(Point P1, Point P2);
	float GetA();
	void setpoint(Point P1, Point P2);
	float GetB();
	void printline();
private:
	Point p1, p2;
	float A, B;
};

Line::Line() :A(0), B(0)
{
	//left blank intentionally
}

Line::Line(Point P1, Point P2)
{
	p1 = P1;
	p2 = P2;
	float x1, x2, y1, y2;
	x1 = P1.GetX();
	x2 = P2.GetX();
	y1 = P1.GetY();
	y2 = P2.GetY();

	//derived from slope(m) intercept(b) form
	float m, b;
	m = (y2 - y1) / (x2 - x1); // gradient
	b = y1 - ((y2 - y1)) / (x2 - x1) * x1; // y-intercept

	B = -1 / b; // y=Ax+B
	A = -B * m;
}


void Line::printline()
{
	cout << endl << "Line: ";
	p1.printpoint();
	cout << "	";
	p2.printpoint();
}
float Line::GetA()
{
	return A;
}
float Line::GetB()
{
	return B;
}
Point Line::getpoint()
{
	return p1;
}
Point Line::getpoint2()
{
	return p2;
}

void Line::setpoint(Point P1, Point P2)
{
	p1 = P1;
	p2 = P2;
	float x1, x2, y1, y2;
	x1 = P1.GetX();
	x2 = P2.GetX();
	y1 = P1.GetY();
	y2 = P2.GetY();

	//derived from slope(m) intercept(b) form
	float m, b;
	float xx = x2 - x1;
	if (xx == 0)
	{
		xx = 1;
		m = 0;
	}
	else
		m = (y2 - y1) / xx; // gradient

	b = y1 - ((y2 - y1)) / xx * x1; // y-intercept

	B = -1 / b; // y=Ax+B
	A = -B * m;
}
struct Intersection
{
	Point* point_of_intersection_1;
	int no_of_intersections;
	Intersection()
	{
		point_of_intersection_1 = nullptr;
		no_of_intersections = 0;
	}
	Intersection(Intersection& obj)
	{
		no_of_intersections = obj.no_of_intersections;
		point_of_intersection_1 = new Point[no_of_intersections];
		for (int i = 0; i < no_of_intersections; i++)
		{
			point_of_intersection_1[i] = obj.point_of_intersection_1[i];
		}
	}
	void setintnum()

	{
		no_of_intersections++;
	}
};
class Graph
{
private:
	Line* GraphLines;
	int no_of_lines;
public:
	Graph()
	{
		GraphLines = nullptr;
		no_of_lines = 0;

	}
	~Graph()
	{
		delete[] GraphLines;
	}
	Graph(const Graph& obj)
	{
		no_of_lines = obj.no_of_lines;
		for (int i = 0; i < obj.no_of_lines; i++)
		{
			GraphLines[i] = obj.GraphLines[i];
		}
	}
	Line* Get_Graph_lines()
	{
		return GraphLines;
	}
	void setlines(int n)
	{
		no_of_lines = n;
	}
	int Get_no_of_lines()
	{
		return no_of_lines;
	}
	Graph(Line* GraphLines, int no_of_lines)
	{
		this->GraphLines = new Line[no_of_lines];
		for (int i = 0; i < no_of_lines; i++)
		{

			this->GraphLines[i] = GraphLines[i];
		}
		this->no_of_lines = no_of_lines;
	}
	void AddLine(Line& L)
	{
		int n = no_of_lines - 1;
		/*Line* NewGraph = new Line[n];

		for (int i = 0; i < n; i++)
		{
			NewGraph[i].setpoint(GraphLines[i].getpoint(), GraphLines[i].getpoint2());
		}*/
		GraphLines[n].getpoint().SetX(L.getpoint().GetX());
		GraphLines[n].getpoint().SetY(L.getpoint().GetY());
		GraphLines[n].getpoint2().SetX(L.getpoint2().GetX());
		GraphLines[n].getpoint2().SetY(L.getpoint2().GetY());

	}

};
void point_of_intersection(Intersection* I, Graph& G1, Graph& G2, float grad = 0)
{
	bool found = false;
	int n = G2.Get_no_of_lines() - 1;
	/*G2.Get_Graph_lines()[n].getpoint2();
	Point lastg2;*/
	float  v1 = G2.Get_Graph_lines()[n].getpoint2().GetX();
	float v2 = G2.Get_Graph_lines()[n].getpoint2().GetY();
	//lastg2.setpoint(G2.Get_Graph_lines()[n].getpoint2().GetX(), G2.Get_Graph_lines()[n].getpoint2().GetY());
	I->point_of_intersection_1 = new Point[G1.Get_no_of_lines() + 1];
	//bool found = false;
	for (int i = 0; i < G1.Get_no_of_lines(); i++) // for each coordinate 
	{
		int j = 0;


		for (; j < G2.Get_no_of_lines(); j++)
		{

			float m1 = G1.Get_Graph_lines()[i].gradient(); // returns gradient of the line 
			float m2 = G2.Get_Graph_lines()[j].gradient(); // returns gradient of the line 

			if (m1 - m2 != 0) // point of intersection exists
			{

				float c1 = G1.Get_Graph_lines()[i].intercept();
				float c2 = G2.Get_Graph_lines()[j].intercept();
				float intersection_X = prec((c2 - c1) / (m1 - m2));
				float intersection_Y = prec(m1 * intersection_X + c1);

				/*if (
					((intersection_X <= G1.Get_Graph_lines()[i].getpoint2().GetX()
					&& intersection_X >= G1.Get_Graph_lines()[i].getpoint().GetX())
					&& (intersection_Y <= G1.Get_Graph_lines()[i].getpoint2().GetY()
					&& intersection_Y >= G1.Get_Graph_lines()[i].getpoint().GetY()))
					&& (
					(intersection_X <= G2.Get_Graph_lines()[j].getpoint2().GetX()
					&& intersection_X >= G2.Get_Graph_lines()[j].getpoint().GetX())
					&& (intersection_Y <= G2.Get_Graph_lines()[j].getpoint2().GetY()
					&& intersection_Y >= G2.Get_Graph_lines()[j].getpoint().GetY())
					))*/
					/*	if (intersection_X <= G1.Get_Graph_lines()[i].getpoint2().GetX()
							&& intersection_X >= G1.Get_Graph_lines()[i].getpoint().GetX()
							&& (intersection_Y <= G1.Get_Graph_lines()[i].getpoint2().GetY()
								&& intersection_Y >= G1.Get_Graph_lines()[i].getpoint().GetY()))
						{
							if (intersection_X <= G2.Get_Graph_lines()[j].getpoint2().GetX()
								&& intersection_X >= G2.Get_Graph_lines()[j].getpoint().GetX()
								&& (intersection_Y <= G2.Get_Graph_lines()[j].getpoint2().GetY()
									&& intersection_Y >= G2.Get_Graph_lines()[j].getpoint().GetY()))
								{*/
				bool neg_grad = false;
				if (G1.Get_Graph_lines()[i].getpoint().GetX() == G2.Get_Graph_lines()[j].getpoint().GetX())
				{
					if (j == n)
						found = true;
					I->point_of_intersection_1[I->no_of_intersections].SetX(intersection_X);
					I->point_of_intersection_1[I->no_of_intersections].SetY(intersection_Y);

					I->no_of_intersections++;
				}
				else if (m2 < 0 && m1>0)
				{
					if (((intersection_X <= G1.Get_Graph_lines()[i].getpoint2().GetX()
						&& intersection_X >= G1.Get_Graph_lines()[i].getpoint().GetX())
						&& (intersection_Y <= G1.Get_Graph_lines()[i].getpoint2().GetY()
							&& intersection_Y >= G1.Get_Graph_lines()[i].getpoint().GetY()))
						&& (
						(intersection_X <= G2.Get_Graph_lines()[j].getpoint2().GetX()
							&& intersection_X >= G2.Get_Graph_lines()[j].getpoint().GetX())
							&& (intersection_Y >= G2.Get_Graph_lines()[j].getpoint2().GetY()
								&& intersection_Y <= G2.Get_Graph_lines()[j].getpoint().GetY())
							))
					{
						if (j == n)
							found = true;
						I->point_of_intersection_1[I->no_of_intersections].SetX(intersection_X);
						I->point_of_intersection_1[I->no_of_intersections].SetY(intersection_Y);

						I->no_of_intersections++;
					}
				}
				else if (m1 < 0 && m2>0)

				{
					if (((intersection_X <= G1.Get_Graph_lines()[i].getpoint2().GetX()
						&& intersection_X >= G1.Get_Graph_lines()[i].getpoint().GetX())
						&& (intersection_Y >= G1.Get_Graph_lines()[i].getpoint2().GetY()
							&& intersection_Y <= G1.Get_Graph_lines()[i].getpoint().GetY()))
						&& (
						(intersection_X <= G2.Get_Graph_lines()[j].getpoint2().GetX()
							&& intersection_X >= G2.Get_Graph_lines()[j].getpoint().GetX())
							&& (intersection_Y <= G2.Get_Graph_lines()[j].getpoint2().GetY()
								&& intersection_Y >= G2.Get_Graph_lines()[j].getpoint().GetY())
							))
					{
						if (j == n)
							found = true;
						I->point_of_intersection_1[I->no_of_intersections].SetX(intersection_X);
						I->point_of_intersection_1[I->no_of_intersections].SetY(intersection_Y);

						I->no_of_intersections++;
					}

				}
				else if (m1 < 0 && m2 < 0)
				{
					if (
						((intersection_X <= G1.Get_Graph_lines()[i].getpoint2().GetX()
							&& intersection_X >= G1.Get_Graph_lines()[i].getpoint().GetX())
							&& (intersection_Y >= G1.Get_Graph_lines()[i].getpoint2().GetY()
								&& intersection_Y <= G1.Get_Graph_lines()[i].getpoint().GetY()))
						&& (
						(intersection_X <= G2.Get_Graph_lines()[j].getpoint2().GetX()
							&& intersection_X >= G2.Get_Graph_lines()[j].getpoint().GetX())
							&& (intersection_Y >= G2.Get_Graph_lines()[j].getpoint2().GetY()
								&& intersection_Y <= G2.Get_Graph_lines()[j].getpoint().GetY())
							))
					{
						if (j == n)
							found = true;
						I->point_of_intersection_1[I->no_of_intersections].SetX(intersection_X);
						I->point_of_intersection_1[I->no_of_intersections].SetY(intersection_Y);

						I->no_of_intersections++;
					}
				}
				else


				{
					float val = intersection_X;

					if (val == G1.Get_Graph_lines()[i].getpoint().GetX())
					{

						if (j == n)
							found = true;
						I->point_of_intersection_1[I->no_of_intersections].SetX(val);
						I->point_of_intersection_1[I->no_of_intersections].SetY(intersection_Y);

						I->no_of_intersections++;
					}
					else
					{
						if
							(val <= G1.Get_Graph_lines()[i].getpoint2().GetX()
								&& val >= G1.Get_Graph_lines()[i].getpoint().GetX())
						{
							if (intersection_Y <= G1.Get_Graph_lines()[i].getpoint2().GetY()
								&& intersection_Y >= G1.Get_Graph_lines()[i].getpoint().GetY())
							{


								if (
									(val <= G2.Get_Graph_lines()[j].getpoint2().GetX()
										&& val >= G2.Get_Graph_lines()[j].getpoint().GetX())
									&& (intersection_Y <= G2.Get_Graph_lines()[j].getpoint2().GetY()
										&& intersection_Y >= G2.Get_Graph_lines()[j].getpoint().GetY())
									)
								{
									if (j == n)
										found = true;
									I->point_of_intersection_1[I->no_of_intersections].SetX(val);
									I->point_of_intersection_1[I->no_of_intersections].SetY(intersection_Y);

									I->no_of_intersections++;
								}
							}
						}
					}

				}






			}
		}
		//}
	}
	if (found == false)
	{
		Line L;

		if (grad == 0)
		{


			for (int i = 0; i < G1.Get_no_of_lines(); i++)
			{

				if (v1 >= G1.Get_Graph_lines()[i].getpoint().GetX() && v1 <= G1.Get_Graph_lines()[i].getpoint2().GetX())
				{
					float m1 = G1.Get_Graph_lines()[i].gradient();
					float c1 = G1.Get_Graph_lines()[i].intercept();
					float y_intercept = m1 * v1 + c1;


					I->point_of_intersection_1[I->no_of_intersections].SetX(v1);
					I->point_of_intersection_1[I->no_of_intersections].SetY(y_intercept);
					I->no_of_intersections++;
					//I->setintnum();
					//L.setpoint(lastg2,p2);
					G2.AddLine(L);
				}
			}
		}
		else
		{
			G2.setlines(G2.Get_no_of_lines() + 1);

		}
	}

}

int checkintersections(Intersection* I, Line l)
{
	int n = 0;
	for (int i = 0; i < I->no_of_intersections - 1; i++)
	{
		if (I->point_of_intersection_1[i].GetX() < l.getpoint2().GetX() &&
			I->point_of_intersection_1[i].GetX() > l.getpoint().GetX())
			n++;
	}
	return n;
}
void calculatearea(Intersection*& I, Graph& G1, Graph& G2, float*& area)
{

	int counter = 0;

	// case 1: No point of intersections 
	// case 2: only 1 point of intersection
	// case 3: two points of intersection
	bool found = false;
	int bigger;

	if (G1.Get_no_of_lines() < G2.Get_no_of_lines())

		bigger = G2.Get_no_of_lines();
	else
		bigger = G1.Get_no_of_lines();
	bool* visited1 = new bool[bigger];
	bool* visitedintersection = new bool[I->no_of_intersections - 1];
	for (int i = 0; i < bigger; i++)
	{
		visited1[i] = false;
		visitedintersection[i] = false;
	}
	float var = 0;
	//setprecision(2);
	float totalarea = 0;
	int k = 0;
	int n1 = G1.Get_no_of_lines();
	int n2 = G2.Get_no_of_lines();

	float lastg1 = G1.Get_Graph_lines()[n1 - 1].getpoint2().GetX();
	float lastg2 = G2.Get_Graph_lines()[n2 - 1].getpoint2().GetX();
	// visited array 
	int num = 0;
	for (int j = 0; j < G1.Get_no_of_lines(); j++)
	{
		found = false;
		var = 0;
		for (int i = 0; i < I->no_of_intersections; i++)
			//{
			//	num = checkintersections(I, G1.Get_Graph_lines()[j]);
			//	if (num > 1)
			//	{
			//	// calculate area with multiple intersections 	
			//		for (int n = 0; n < num + 1; n++)
			//		{

			//		}
			//	}
				//else 
				//if (num == 1)
				//{


					// check if for any line , how many intersections cut it. 
					// if more than one 
					// ----------------code ----------------
					// else if only one intersection cuts it then {} 
			if (visitedintersection[i] == false)
			{


				/*if (I->point_of_intersection_1[i + 1].compare(G1.Get_Graph_lines()[k].getpoint() )==true || (I->point_of_intersection_1[i+1].GetX() < G1.Get_Graph_lines()[k].getpoint2().GetX() &&
					I->point_of_intersection_1[i+1].GetX() > G1.Get_Graph_lines()[k].getpoint().GetX()))
				{
					found = true;
					k = j-1;
				}*/



				// point of intersection == point 1 of the line that it lies on
				if (I->point_of_intersection_1[i].GetX() == G1.Get_Graph_lines()[j].getpoint().GetX())
				{ // same point of intersection as a cordinate 
					//calculate area
					var = G1.Get_Graph_lines()[j].calculatearea_line();
					totalarea = var + totalarea;
					area[counter] = var + area[counter];
					visited1[j] = true;
				}
				// point of intersection == point 2 of the line that it lies on   || point 2 of the line is larger than second graph x
				else if (I->point_of_intersection_1[i].GetX() == G1.Get_Graph_lines()[j].getpoint2().GetX()
					&& G1.Get_Graph_lines()[j].getpoint2().GetX() > lastg2)
				{ // same point of intersection as a cordinate 
					//calculate area


					var = G1.Get_Graph_lines()[j].calculatearea_middle(I->point_of_intersection_1[i].GetX(), I->point_of_intersection_1[i].GetY());
					totalarea = var + totalarea;
					area[counter] = var + area[counter];

					visited1[j] = true;

				}
				// point of intersection is somewhere on 1 line 
				else if (I->point_of_intersection_1[i].GetX() < G1.Get_Graph_lines()[j].getpoint2().GetX() &&
					I->point_of_intersection_1[i].GetX() > G1.Get_Graph_lines()[j].getpoint().GetX()
					)
				{
					visited1[j] = true;
					Point P;

					visitedintersection[i] = true;
					bool foo = false;
					for (int x = 0; x < I->no_of_intersections - 1 && foo == false; x++)
					{
						if (I->point_of_intersection_1[i + 1].GetX() < G1.Get_Graph_lines()[j].getpoint2().GetX() &&
							I->point_of_intersection_1[i + 1].GetX() < lastg2)
						{
							P.setpoint(I->point_of_intersection_1[i + 1].GetX(), I->point_of_intersection_1[i + 1].GetY());
							foo = true;
						}
						else
							foo = false;
					}
					if (foo == false)
					{
						if (found == true)
							counter++;
						if (i == 0) // if first area 
						{
							var = G1.Get_Graph_lines()[j].calculatearea_middle(I->point_of_intersection_1[i].GetX(), I->point_of_intersection_1[i].GetY());
							totalarea = var + totalarea;
							area[counter] = var + area[counter];
						}
						else // for all other areas 
						{
							if (found == true)
							{
								if (i == 1)
									var = G1.Get_Graph_lines()[j].calculatearea_middle3(I->point_of_intersection_1[i].GetX(), I->point_of_intersection_1[i].GetY(), G1.Get_Graph_lines()[j].getpoint2().GetX(), G1.Get_Graph_lines()[j].getpoint2().GetY());
								else

									var = G1.Get_Graph_lines()[j].calculatearea_middle3(I->point_of_intersection_1[i - 1].GetX(), I->point_of_intersection_1[i - 1].GetY(), I->point_of_intersection_1[i].GetX(), I->point_of_intersection_1[i].GetY());

							}
							else
								var = G1.Get_Graph_lines()[j].calculatearea_middle2(I->point_of_intersection_1[i].GetX(), I->point_of_intersection_1[i].GetY());
							totalarea = var + totalarea;
							area[counter] = var + area[counter];
							if (I->no_of_intersections > 2 && I->point_of_intersection_1[i].GetX() < lastg2 && found == false)
							{

								var = G1.Get_Graph_lines()[j].calculatearea_middle(I->point_of_intersection_1[i].GetX(), I->point_of_intersection_1[i].GetY());
								totalarea = var + totalarea;
								counter++;
								area[counter] = var + area[counter];

							}

						}
					}
					else if (foo == true)
					{
						found = true;
						if (i == 0) // if first area 
						{
							var = G1.Get_Graph_lines()[j].calculatearea_middle3(I->point_of_intersection_1[i].GetX(), I->point_of_intersection_1[i].GetY(), P.GetX(), P.GetY());
							totalarea = var + totalarea;
							//	counter++;
							area[counter] = var + area[counter];
							/*if (I->no_of_intersections > 2 && I->point_of_intersection_1[i].GetX() < lastg2)
							{
								var = G1.Get_Graph_lines()[j].calculatearea_middle(P.GetX(), P.GetY());
								totalarea = var + totalarea;
								counter++;
								area[counter] = var + area[counter];

							}*/

						}
						else // for all other areas 
						{

							var = G1.Get_Graph_lines()[j].calculatearea_middle2(I->point_of_intersection_1[i].GetX(), I->point_of_intersection_1[i].GetY());
							totalarea = var + totalarea;
							//counter++; 
							area[counter] = var + area[counter];
							//visitedintersection[i + 1] = true;
							/*if (I->no_of_intersections > 2 && I->point_of_intersection_1[i].GetX() < lastg2)
							{
								var = G1.Get_Graph_lines()[j].calculatearea_middle3(I->point_of_intersection_1[i].GetX(), I->point_of_intersection_1[i].GetY(), P);
								totalarea = var + totalarea;
								counter++;
								area[counter] = var + area[counter];

							}*/
						}
					}

					// if more than one point of intersection lies on 1 line 

				}
				//  for all other areas in between with ""NO POINT OF INTERSECTION""
				else if (I->point_of_intersection_1[0].GetX() < G1.Get_Graph_lines()[j].getpoint2().GetX())
				{

					if (visited1[j] == false)
					{
						var = G1.Get_Graph_lines()[j].calculatearea_line();
						totalarea = var + totalarea;
						area[counter] = var + area[counter];
						visited1[j] = true;
					}
				}



				//	}
			//	}
			}
	}



}

int main()
{
	Point* points = new Point[100];
	fstream fin;
	fin.open("graph200.txt");
	//fin.open("sam.txt");
	//fin.open("sampleg.txt");
	//fin.open("s.txt");
	int i = 0;
	float y = 0; float x = 0;
	int totalpoints = 0;
	while (!fin.eof())
	{
		fin >> x;
		fin.ignore();
		fin >> y;
		//points[i] = new Point;
	//	x = ceil(x);
		points[i].SetX(x);
		points[i].SetY(y);
		totalpoints++; // count the number of coordinates 
		points[i].printpoint();
		i++;

	}
	Line* lines = new Line[totalpoints - 1];

	for (int i = 1; i < totalpoints; i++)
	{
		//lines[i - 1] = new Line;
		lines[i - 1].setpoint(points[i - 1], points[i]);
		lines[i - 1].printline();
	}



	Point* points2 = new Point[100];
	fstream fin2;
	fin2.open("graph202.txt");
	//fin2.open("samplet.txt");
	//fin2.open("sam2.txt");
	//fin2.open("sa2.txt");
	int i2 = 0;
	float y2 = 0; float x2 = 0;
	int totalpoints2 = 0;
	while (!fin2.eof())
	{
		fin2 >> x2;
		fin2.ignore();
		fin2 >> y2;
		//x2 = ceil(x2);
		setprecision(2);
		points2[i2].SetX(x2);
		points2[i2].SetY(y2);
		totalpoints2++; // count the number of coordinates 
		points2[i2].printpoint();
		i2++;

	}
	Line* lines2 = new Line[totalpoints2 - 1];

	for (int i = 1; i < totalpoints2; i++)
	{
		//lines[i - 1] = new Line;
		lines2[i - 1].setpoint(points2[i - 1], points2[i]);
		lines2[i - 1].printline();
	}

	// 2 Graphs initialised

	Intersection* I = new Intersection;
	Graph Graph1(lines, totalpoints - 1);
	Graph Graph2(lines2, totalpoints2);
	Graph2.setlines(totalpoints2 - 1);

	point_of_intersection(I, Graph1, Graph2);

	if (I->no_of_intersections == 0)
		cout << "\n\nSorry! The graphs do not intersect\n\n";

	I->point_of_intersection_1[0];
	I->point_of_intersection_1[1];
	I->point_of_intersection_1[2];
	float reqarea = 0;


	int n = I->no_of_intersections;
	float* area1 = new float[n];
	float* area2 = new float[n];
	for (int m = 0; m < I->no_of_intersections - 1; m++)
	{
		area1[m] = 0;
		area2[m] = 0;
	}
	//	cout << 123456;
	calculatearea(I, Graph1, Graph2, area1);
	calculatearea(I, Graph2, Graph1, area2);

	cout << endl;
	for (int i = 0; i < I->no_of_intersections - 1; i++)
		cout << area1[i] << " ";
	cout << endl;
	for (int i = 0; i < I->no_of_intersections - 1; i++)
		cout << area2[i] << " ";

	float req1 = 0;
	float req2 = 0;
	float finala = 0;
	cout << endl << "Area in the middle is: " << reqarea;
	for (int k = 0; k < I->no_of_intersections - 1; k++)
	{
		//addd always but sign of the greater area 
		if (area1[k] > area2[k])
		{
			if (reqarea < 0)
			{
				reqarea = reqarea * -1; // becomes positive 
				req1 = area1[k] - area2[k];
				req2 = req1 + reqarea;
				reqarea = req2;
				// check sign
				if (req1 < reqarea)
				{

					reqarea = reqarea * -1;
				}


			}
			else
				reqarea = (area1[k] - area2[k]) + reqarea;
			// positive 
		}
		else
		{
			req1 = area2[k] - area1[k];
			req2 = req1 + reqarea;

			if (req1 > reqarea)
			{
				reqarea = req2;
				reqarea = reqarea * -1;
			}
			//negative 

		}
		// 2

	}


	cout << reqarea;
}