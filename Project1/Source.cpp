
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
#define INF INT_MAX 

// tested with .txt files
//
//double prec(double var)
//{
//	
//	double value = (int)(var * 100 + .5);
//	return (double)value / 100;
//}
bool compareFloatNum(double a, double b)
{

	// Correct method to compare 
	// floating-point numbers 
	if (abs(a - b) < 1e-9)
	{
		return true;
	}
	else {
		return false;
	}
}

class Point
{
public:
	//Default constructor
	Point();
	Point(double new_x, double new_y);
	void printpoint();
	void setpoint(double new_x, double new_y);
	//Accessors

	double GetX();
	bool compare(Point P1)
	{
		if (P1.xCOORD == this->xCOORD && P1.yCOORD == this->yCOORD)
			return true;
		else return false;
	}
	double GetY();
	//Mutators
	void SetX(double x);
	void SetY(double Y);
private:

	double xCOORD, yCOORD;
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
Point::Point(double new_x, double new_y)
{
	setprecision(2);
	xCOORD = new_x;
	yCOORD = new_y;
}
void Point::setpoint(double new_x, double new_y)
{

	xCOORD =new_x;
	yCOORD = new_y;
}

//MUTATOR FUNCTIONS
void Point::SetX(double x)
{

	xCOORD = x;
}
void Point::SetY(double y)
{

	yCOORD = y;
}

double Point::GetX()
{
	return xCOORD;
}
double Point::GetY()
{
	return yCOORD;
}



// LINE CLASS 
class Line
{
public:
	Line();

	double gradient()
	{
		double x1, x2, y1, y2;
		x1 = p1.GetX();
		x2 = p2.GetX();
		y1 = p1.GetY();
		y2 = p2.GetY();
		double m = (y2 - y1) / (x2 - x1); // gradient
		return m;
	}
	double intercept()
	{
		double x1, x2 = 0;
		double  y1, y2 = 0;
		x1 = p1.GetX();
		y1 = p1.GetY();
		double m = gradient();
		double c1 = y1 - (m)* x1;
		return c1;
	}
	double calculatearea_line()
	{
		// length 1 
		double a = p1.GetY();
		// length 2 
		double b = p2.GetY();
		// height
		double val = p2.GetX();
		double val2 = p1.GetX();
		double h;
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
	double calculatearea_middle(double x, double y)
	{
		double x1 = x;// Intersection x 
		double x2 = p2.GetX(); // p2 x
		double y1 = y; // intersection y
		double y2 = p2.GetY(); // p2 y
		double h;
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

	double calculatearea_middle2(double x, double y)
	{
		double x1 = x;// Intersection x 
		double x2 = p1.GetX(); // p2 x
		double y1 = y; // intersection y
		double y2 = p1.GetY(); // p2 y
		double h;
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
	double calculatearea_middle3(double x, double y, Point P)
	{
		double x1 = x;// Intersection x 
		double x2 = P.GetX(); // p2 x
		double y1 = y; // intersection y
		double y2 = P.GetY(); // p2 y
		double h;
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

	Point getpoint();
	Point getpoint2();
	Line(Point P1, Point P2);
	double GetA();
	void setpoint(Point P1, Point P2);
	double GetB();
	void printline();
private:
	Point p1, p2;
	double A, B;
};

Line::Line() :A(0), B(0)
{
	//left blank intentionally
}

Line::Line(Point P1, Point P2)
{
	p1 = P1;
	p2 = P2;
	double x1, x2, y1, y2;
	x1 = P1.GetX();
	x2 = P2.GetX();
	y1 = P1.GetY();
	y2 = P2.GetY();

	//derived from slope(m) intercept(b) form
	double m, b;
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
double Line::GetA()
{
	return A;
}
double Line::GetB()
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
	double x1, x2, y1, y2;
	x1 = P1.GetX();
	x2 = P2.GetX();
	y1 = P1.GetY();
	y2 = P2.GetY();

	//derived from slope(m) intercept(b) form
	double m, b;
	m = (y2 - y1) / (x2 - x1); // gradient
	b = y1 - ((y2 - y1)) / (x2 - x1) * x1; // y-intercept

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
	Line* Get_Graph_lines()
	{
		return GraphLines;
	}
	int Get_no_of_lines()
	{
		return no_of_lines;
	}
	Graph(Line* GraphLines, int no_of_lines)
	{
		this->GraphLines = GraphLines;
		this->no_of_lines = no_of_lines;
	}
	void setline(Line L)
	{
		GraphLines[no_of_lines++].setpoint(L.getpoint(),L.getpoint2());
	}
	void setnum()
	{
		no_of_lines++;
	}


};
void point_of_intersection(Intersection* I, Graph G1, Graph G2,double grad = 0)
{
	int bigger;

	if (G1.Get_no_of_lines() < G2.Get_no_of_lines())

		bigger = G2.Get_no_of_lines();
	else
		bigger = G1.Get_no_of_lines();
	I->point_of_intersection_1 = new Point[bigger +1];
	bool found = false;
	int n = G2.Get_no_of_lines() - 1;
	Point lastg2 = G2.Get_Graph_lines()[G2.Get_no_of_lines() - 1].getpoint2();
	for (int i = 0; i < G1.Get_no_of_lines(); i++) // for each coordinate 
	{
		int j = 0;
		

		for (; j < G2.Get_no_of_lines(); j++)
		{

			double m1 = G1.Get_Graph_lines()[i].gradient(); // returns gradient of the line 
			double m2 = G2.Get_Graph_lines()[j].gradient(); // returns gradient of the line 

			if (m1 - m2 != 0) // point of intersection exists
			{

				double c1 = G1.Get_Graph_lines()[i].intercept();
				double c2 = G2.Get_Graph_lines()[j].intercept();
				double intersection_X = (c2 - c1) / (m1 - m2); // x intercept
				if (intersection_X < 0)
					intersection_X = ceil(intersection_X);
				else
					intersection_X = floor(intersection_X);
				double intersection_Y = m1 * intersection_X + c1; // y intercept 
				double a, b, c, d, e, f, g, h = 0;
				b= floor(G1.Get_Graph_lines()[i].getpoint2().GetX());
				a= floor(G1.Get_Graph_lines()[i].getpoint().GetX());
				d = G1.Get_Graph_lines()[i].getpoint2().GetY();
				c = G1.Get_Graph_lines()[i].getpoint().GetY();
				f = floor(G2.Get_Graph_lines()[i].getpoint2().GetX());
				e = floor(G2.Get_Graph_lines()[i].getpoint().GetX());
				h = G2.Get_Graph_lines()[i].getpoint2().GetY();
				g = G2.Get_Graph_lines()[i].getpoint().GetY();
				
				//bool neg_grad = false;
				if (m2 < 0 && m1>0)
				{
					if ((((intersection_X < G1.Get_Graph_lines()[i].getpoint2().GetX() || compareFloatNum(intersection_X , G1.Get_Graph_lines()[i].getpoint2().GetX()))
						&& (intersection_X > G1.Get_Graph_lines()[i].getpoint().GetX())|| compareFloatNum(intersection_X , G1.Get_Graph_lines()[i].getpoint().GetX()))
						&& ((intersection_Y < G1.Get_Graph_lines()[i].getpoint2().GetY() || compareFloatNum(intersection_Y , G1.Get_Graph_lines()[i].getpoint2().GetY()))
							&& (intersection_Y >G1.Get_Graph_lines()[i].getpoint().GetY()))||compareFloatNum(intersection_Y , G1.Get_Graph_lines()[i].getpoint().GetY()))
						&& (
						((intersection_X < G2.Get_Graph_lines()[j].getpoint2().GetX()||compareFloatNum(intersection_X ,G2.Get_Graph_lines()[j].getpoint2().GetX()))
							&& (intersection_X > G2.Get_Graph_lines()[j].getpoint().GetX())||compareFloatNum(intersection_X , G2.Get_Graph_lines()[j].getpoint().GetX()))
							&& ((intersection_Y > G2.Get_Graph_lines()[j].getpoint2().GetY()||compareFloatNum(intersection_Y , G2.Get_Graph_lines()[j].getpoint2().GetY()))
								&& (intersection_Y < G2.Get_Graph_lines()[j].getpoint().GetY()||compareFloatNum(intersection_Y , G2.Get_Graph_lines()[j].getpoint().GetY())))
							))
					/*if (intersection_X <= f && intersection_X >= e)
					{
						if (intersection_X >= a && intersection_X <= b)
						{
							if (intersection_Y >= c && intersection_Y <= d)
							{
								if (intersection_Y <=g && intersection_Y >=h)
								
							}
						}
					}
					*/
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
					double val = intersection_X;

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
						
						if((val <= b && val >=a ))
						{
							if (intersection_Y <= G1.Get_Graph_lines()[i].getpoint2().GetY()
								&& intersection_Y >= G1.Get_Graph_lines()[i].getpoint().GetY())
							{


								if (
									((val <= f&& val >= e) )
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

				if (lastg2.GetX() >= G1.Get_Graph_lines()[i].getpoint().GetX() && lastg2.GetX() <= G1.Get_Graph_lines()[i].getpoint2().GetX())
				{
					double m1 = G1.Get_Graph_lines()[i].gradient();
					double c1 = G1.Get_Graph_lines()[i].intercept();
					double y_intercept = m1 * lastg2.GetX() + c1;
					Point p2(lastg2.GetX(), y_intercept);
					
					I->point_of_intersection_1[I->no_of_intersections].SetX(lastg2.GetX());
					I->point_of_intersection_1[I->no_of_intersections].SetY(y_intercept);

					I->no_of_intersections++;
					L.setpoint(lastg2, p2);
					G2.setline(L);
					G2.setnum();
				}
			}
		}
		else
		{
			//////
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
void calculatearea(Intersection* I, Graph G1, Graph G2, double* area)
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
	int n = I->no_of_intersections;
	bool* visitedintersection = new bool[n];
	for (int i = 0; i < bigger; i++)
	{
		visited1[i] = false;
		visitedintersection[i] = false;
	}
	double var = 0;
	
	double totalarea = 0;
	int k = 0;
	int n1 = G1.Get_no_of_lines();
	int n2 = G2.Get_no_of_lines();

	double lastg1 = G1.Get_Graph_lines()[n1 - 1].getpoint2().GetX();
	double lastg2 = G2.Get_Graph_lines()[n2 - 1].getpoint2().GetX();
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

				// point of intersection == point 1 of the line that it lies on
				if (I->point_of_intersection_1[i].compare(G1.Get_Graph_lines()[j].getpoint()) == true)
				{ // same point of intersection as a cordinate 
					//calculate area
					var = G1.Get_Graph_lines()[j].calculatearea_line();
					totalarea = var + totalarea;
					area[counter] = var + area[counter];
					visited1[j] = true;
					visitedintersection[i] = true;
				}
				// point of intersection == point 2 of the line that it lies on   || point 2 of the line is larger than second graph x
				else if (I->point_of_intersection_1[i].compare(G1.Get_Graph_lines()[j].getpoint2()) == true
					&& G1.Get_Graph_lines()[j].getpoint2().GetX() > lastg2)
				{ // same point of intersection as a cordinate 
					//calculate area


					var = G1.Get_Graph_lines()[j].calculatearea_middle(I->point_of_intersection_1[i].GetX(), I->point_of_intersection_1[i].GetY());
					totalarea = var + totalarea;
					area[counter] = var + area[counter];
					visitedintersection[i] = true;
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
									var = G1.Get_Graph_lines()[j].calculatearea_middle3(I->point_of_intersection_1[i].GetX(), I->point_of_intersection_1[i].GetY(), G1.Get_Graph_lines()[j].getpoint2());
								else

									var = G1.Get_Graph_lines()[j].calculatearea_middle3(I->point_of_intersection_1[i - 1].GetX(), I->point_of_intersection_1[i - 1].GetY(), I->point_of_intersection_1[i]);

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
							var = G1.Get_Graph_lines()[j].calculatearea_middle3(I->point_of_intersection_1[i].GetX(), I->point_of_intersection_1[i].GetY(), P);
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
	//fin.open("graph200.txt");
	//fin.open("sam.txt");
	fin.open("sampleg.txt");
	//fin.open("s.txt");
	int i = 0;
	double y = 0; double x = 0;
	int totalpoints = 0;
	while (!fin.eof())
	{
		fin >> x;
		fin.ignore();
		fin >> y;
		//points[i] = new Point;
		points[i].SetX(x);
		points[i].SetY(y);
		totalpoints++; // count the number of coordinates 
	//	points[i].printpoint();
		i++;

	}
	Line* lines = new Line[totalpoints - 1];

	for (int i = 1; i < totalpoints; i++)
	{
		//lines[i - 1] = new Line;
		lines[i - 1].setpoint(points[i - 1], points[i]);
		//lines[i - 1].printline();
	}



	Point* points2 = new Point[100];
	fstream fin2;
	//fin2.open("graph202.txt");
	fin2.open("samplet.txt");
	//fin2.open("sam2.txt");
	//fin2.open("sa2.txt");
	int i2 = 0;
	double y2 = 0; double x2 = 0;
	int totalpoints2 = 0;
	while (!fin2.eof())
	{
		fin2 >> x2;
		fin2.ignore();
		fin2 >> y2;
		setprecision(2);
		points2[i2].SetX(x2);
		points2[i2].SetY(y2);
		totalpoints2++; // count the number of coordinates 
	//	points2[i2].printpoint();
		i2++;

	}
	Line* lines2 = new Line[totalpoints2 - 1];

	for (int i = 1; i < totalpoints2; i++)
	{
		//lines[i - 1] = new Line;
		lines2[i - 1].setpoint(points2[i - 1], points2[i]);
		//lines2[i - 1].printline();
	}

	// 2 Graphs initialised

	Intersection* I = new Intersection;
	Graph Graph1(lines, totalpoints - 1);
	Graph Graph2(lines2, totalpoints2 - 1);
	point_of_intersection(I, Graph1, Graph2);
	if (I->no_of_intersections == 0)
		cout << "\n\nSorry! The graphs do not intersect\n\n";

	double reqarea = 0;


	int n = I->no_of_intersections;
	double* area1 = new double[n];
	double* area2 = new double[n];
	for (int m = 0; m < I->no_of_intersections - 1; m++)
	{
		area1[m] = 0;
		area2[m] = 0;
	}

	calculatearea(I, Graph1, Graph2, area1);
	calculatearea(I, Graph2, Graph1, area2);

	cout << endl;
	/*for (int i = 0; i < I->no_of_intersections - 1; i++)
		cout << area1[i] << " ";
	cout << endl;
	for (int i = 0; i < I->no_of_intersections - 1; i++)
		cout << area2[i] << " ";*/

	double req1 = 0;
	double req2 = 0;
	double finala = 0;

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

	cout << endl << "Area in the middle is: " << reqarea<<endl;
	//cout << reqarea;
}