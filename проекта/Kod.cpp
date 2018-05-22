#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <stack>
#include <ctime>
#include <algorithm>
#include <set>

using namespace std;

const double EPS(1e-5);

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
} p0;

bool operator <(const Point &a, const Point &b) {
   	return a.y < b.y || (abs(a.y - b.y) < EPS && a.x < b.x);
}

struct Direct {
	double a, b, c;
};

double dist(const Point &p1, const Point &p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

Point nextToTop(stack <Point> &S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}



//Проверка на левую тройку векторов
bool orientation(const Point &p0, const Point &p1, const Point &p2) {
    return (p0.x * p1.y + p1.x * p2.y + p2.x * p0.y - p0.y * p1.x - p1.y * p2.x - p2.y * p0.x) / 2 > EPS;
}

bool compare(const Point &p1, const Point &p2) {
	if (dist(p0, p1) < EPS)
		return true;
	if (dist(p0, p2) < EPS)
		return false;

	if (orientation(p0, p1, p2))
		return true;
	if (orientation(p0, p2, p1))
		return false;

	return dist(p0, p1) > dist(p0, p2);
}



void GrahamScan(vector <Point> &points) {
	// Находим самую нижнюю точку
	size_t min = 0;
	for (size_t i = 1; i < points.size(); i++)
	    // Выбираем самую нижнюю или самую левую из них в случае совпадения
	    if (points[i] < points[min])
	        min = i;

	p0 = points[min];

	// Сортируем точки по отношению к нижней. Точка p1 становится
	// перед p2 в отсортированной последовательности, если p2 имеет больший полярный угол
	// (в направлении против часовой стрелке), чем p1
	sort(points.begin(), points.end(), &compare);

	// Создаем пустой стек и кладем в него первые три точки.
	stack <Point> S;
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);

	// Обрабатываем оставшиеся точки
	for (size_t i = 3; i < points.size(); i++) {
		// Продолжаем удалять верхнюю точку, пока угол, сформированный точками next-to-top, 
		// top, and points[i] не образует левый поворот
		while (S.size() > 1 && !orientation(nextToTop(S), S.top(), points[i]))
			S.pop();
		S.push(points[i]);
	}
	// Теперь в стеке нужные точки
	points.resize(S.size());
	for (size_t i = 0; !S.empty(); i++, S.pop())
		points[i] = S.top();
}
	
//Функция генерации множества точек
void genRandPointVariety(const size_t amount, vector <Point> &points) {
    set <Point> s;
    //Генерируем множество произвольных точек в количестве amount
    srand(time(NULL));
    while (s.size() < amount)
    	s.insert(Point(rand() % 512, rand() % 512));

	size_t i = 0;
    points.resize(amount);
    for(auto it: s)
        points[i++] = it;
}

//Алгоритм генерации выпуклого многоугольника
size_t genLargeRectangle(const size_t amount, vector <Point> &rect) {
    //Генерируем множество из amount точек
    genRandPointVariety(amount, rect);
    //Строим для них выпуклую оболочку по Грэхему
    GrahamScan(rect);
    return rect.size();
}



//Функция заполняющая массив структур, прилегащих к точке многоугольника (вершине)
//И уравнение биссектриссы угла (задается координатами направляющего вектора )

void PointDirection(vector <Point> &p, vector <Direct> s[], vector <Point> &bisec) {
	size_t n = p.size() - 1;
	for (size_t i = 0; i <= n; i++) {
		if (i == 0) {
			s[0][0].a = p[n-1].y - p[0].y;
			s[0][0].b = p[0].x - p[n-1].x;
			s[0][0].c = p[0].y * p[n-1].x - p[0].x * p[n-1].y;

			s[1][0].a = p[1].y - p[0].y;
			s[1][0].b = p[0].x - p[1].x;
			s[1][0].c = p[0].y * p[1].x - p[0].x * p[1].y;

			bisec[0].x = (p[n-1].x - p[0].x) / sqrt(dist(p[0], p[n-1])) + (p[1].x - p[0].x) / sqrt(dist(p[0], p[1]));
			bisec[0].y = (p[n-1].y - p[0].y) / sqrt(dist(p[0], p[n-1])) + (p[1].y - p[0].y) / sqrt(dist(p[0], p[1]));	
		}
		
		if (i == n-1)	{	
			s[0][n-1].a = p[n - 2].y - p[n-1].y;
			s[0][n-1].b = p[n-1].x - p[n - 2].x;
			s[0][n-1].c = p[n-1].y * p[n - 2].x - p[n-1].x * p[n - 2].y;

			s[1][n-1].a = p[0].y - p[n-1].y;
			s[1][n-1].b = p[n-1].x - p[0].x;
			s[1][n-1].c = p[n-1].y * p[0].x - p[n-1].x * p[0].y;

			bisec[n-1].x = (p[n - 2].x - p[n-1].x) / sqrt(dist(p[n - 2], p[n-1])) + (p[0].x - p[n-1].x) / sqrt(dist(p[n-1], p[0]));
			bisec[n-1].y = (p[n - 2].y - p[n-1].y) / sqrt(dist(p[n - 2], p[n-1])) + (p[0].y - p[n-1].y) / sqrt(dist(p[n-1], p[0]));
		}

		if (i != n && i != 0) {
			s[0][i].a = p[i - 1].y - p[i].y;
			s[0][i].b = p[i].x - p[i - 1].x;
			s[0][i].c = p[i].y * p[i - 1].x - p[i].x * p[i - 1].y;

			s[1][i].a = p[i + 1].y - p[i].y;
			s[1][i].b = p[i].x - p[i + 1].x;
			s[1][i].c = p[i + 1].y * p[i].x - p[i + 1].x * p[i].y;

			bisec[i].x = (p[i - 1].x - p[i].x) / sqrt(dist(p[i - 1], p[i])) + (p[i + 1].x - p[i].x) / sqrt(dist(p[i], p[i + 1]));
			bisec[i].y = (p[i - 1].y - p[i].y) / sqrt(dist(p[i - 1], p[i])) + (p[i + 1].y - p[i].y) / sqrt(dist(p[i], p[i + 1]));
		}
	}
}



//Функция нахождения узлов скелета 

void Skelet(vector <Point> &p, vector <Direct> s[], vector <Point> bisec, vector <Point> uzel) {
	double t, r, x0, y0;
	size_t k = 0, n = p.size();
	int schet = 0;
	while (k != n-1) {
		for (size_t i = 0; i < n; i++) {
			if (i != k) {
				t = ((s[0][i].c + s[0][i].b * p[k].y + s[1][i].a * p[k].x) / sqrt(s[1][i].a * s[1][i].a + s[1][i].b * s[1][i].b)
					-(s[1][k].c + s[1][k].b * p[k].y + s[1][k].a * p[k].x) / sqrt(s[1][k].a * s[1][k].a + s[1][k].b * s[1][k].b))
					/((bisec[k].x * s[1][k].a - bisec[k].y * s[1][k].b) / sqrt(s[1][i].a * s[1][i].a + s[1][i].b * s[1][i].b)
					+ (bisec[k].y * s[1][k].b - bisec[k].x * s[1][k].a) / sqrt(s[1][k].a * s[1][k].a + s[1][k].b * s[1][k].b));
				x0 = bisec[k].x * t + p[k].x;
				y0 = bisec[k].y * t + p[k].y;

				if ((s[0][k].a * x0 + s[0][k].b * y0 + s[0][k].c < 0 && s[0][k].a * p[k + 1].x + s[0][k].b * p[k + 1].y + s[0][k].c < 0)
				 || (s[0][k].a * x0 + s[0][k].b * y0 + s[0][k].c > 0 && s[0][k].a * p[k + 1].x + s[0][k].b * p[k + 1].y + s[0][k].c > 0)) {
					r = abs(s[1][k].a * x0 + s[1][k].b * y0 + s[1][k].c) / sqrt(s[1][k].a * s[1][k].a + s[1][k].b * s[1][k].b);
					for (size_t j = 0; j < n; j++)
						if (j != k && j != i)
							if (abs(s[1][j].a * x0 + s[1][j].b * y0 + s[1][j].c) / sqrt(s[1][j].a * s[1][j].a + s[1][j].b * s[1][j].b) < r)
								schet++;
				} else {
					t = ((s[1][i].c - s[1][i].b * p[k].y - s[1][i].a * p[k].x) / sqrt(s[1][i].a * s[1][i].a + s[1][i].b * s[1][i].b)
						-(s[1][k].c + s[1][k].b * p[k].y + s[1][k].a * p[k].x) / sqrt(s[1][k].a * s[1][k].a + s[1][k].b * s[1][k].b))
						/((bisec[k].x * s[1][k].a + bisec[k].y * s[1][i].b) / sqrt(s[1][i].a * s[1][i].a + s[1][i].b * s[1][i].b)
						+ (bisec[k].y * s[1][k].b + bisec[k].x * s[2][i].a) / sqrt(s[1][k].a * s[1][k].a + s[1][k].b * s[1][k].b));
					r = abs(s[1][k].a * x0 + s[1][k].b * y0 + s[1][k].c) / sqrt(s[1][k].a*s[1][k].a + s[1][k].b * s[1][k].b);
					for (size_t j = 0; j < n; j++)
						if (j != k && j != i)
							if (abs(s[1][j].a * x0 + s[1][j].b * y0 + s[1][j].c) / sqrt(s[1][j].a * s[1][j].a + s[1][j].b * s[1][j].b) < r)
								schet++;
				}
			}

			if (schet == 0) {
				uzel[k].x = x0;
				uzel[k].y = y0;
				k++;
			}
		}
	}
}





int main() {
	size_t n;
	cin >> n;
	vector <Point> rect;
	n = genLargeRectangle(n, rect);
	vector <Direct> s[2];
	s[0].resize(n), s[1].resize(n);
	vector <Point> bisec, uzel;
	bisec.resize(n), uzel.resize(n);
	PointDirection(rect, s, bisec);
	Skelet(rect, s, bisec, uzel);
	cout << "Rectangle:" << endl;
	for (size_t i = 0; i < n; ++i)
		cout << '(' << rect[i].x << ", " << rect[i].y << ')' << endl;
	cout << endl << "Skelet:" << endl;
	for (size_t i = 0; i < n; ++i)
		cout << '(' << uzel[i].x << ", " << uzel[i].y << ')' << endl;
	return 0;
}
