#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    float x;
    float y;
}

struct Direct {
	float a;
	float b;
	float c;
}

Point nextToTop(stack<Point> &S){
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

int swap(Point &p1, Point &p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
    return 1; //Успех
}

int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // коллинеарны
    return (val > 0)? 1: 2; // по часовой стрелке или против
}

int compare(const void *vp1, const void *vp2){
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    // Находим ориентацию
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1;

    return (o == 2)? -1: 1;
}

void GrahamScan(Point points[], int n, std::vector<Point> &result){
    // Находим самую нижнюю точку
    float ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++){
        int y = points[i].y;

        // Выбираем самую нижнюю или самую левую из них в случае совпадения
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // Помещаем самую левую точку в начало
    swap(points[0], points[min]);

    // Сортируем n-1 точек по отношению к первой точке.  Точка p1 становится
    // перед p2 в отсортированной последовательности, если p2 имеет больший полярный угол (в 
    // направлении по часовой стрелке), чем p1
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point), compare);

    // Создаем пустой стек и кладем в него первые три точки.
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // Обрабатываем оставшиеся n-3 точек
    for (int i = 3; i < n; i++){
        // Продолжаем удалять верхнюю точку, пока угол, сформированный точками next-to-top, 
        // top, and points[i] не образует левый поворот
        if  (S.size() >= 2){
            while  (orientation(nextToTop(S), S.top(), points[i]) != 2)
                S.pop();
            S.push(points[i]);
        }
    }

     // Теперь в стеке нужные точки
    while (!S.empty()){
        Point p = S.top();
        //cout << "(" << p.x << ", " << p.y <<")" << endl;
        result.push_back(p);
        S.pop();
    }
}


//Алгоритм генерации выпуклого многоугольника

void genLargeRectangle(int amount, std::vector<g::Point> &rect, int &generated){
    //Генерируем множество из amount точек
    g::Point *p = new g::Point[amount];
    genRandPointVariety(p, amount);
    //Строим для них выпуклую оболочку по Грэхему
    std::vector<g::Point> convex_hull;
    GrahamScan(p, amount, convex_hull);
    //Количество точек в оболочке (вершин многоугольника)
    generated = convex_hull.size();
    //Копируем точки из вектора в массив rect
    rect.assign(convex_hull.begin(), convex_hull.end());
    delete[] p;
}
    
 
//Функция генерации множества точек

void genRandPointVariety(g::Point points[], int amount){
    std::vector<g::Point> v;
    g::Point *p = NULL;

    //Генерируем множество произвольных точек в количестве amount
    srand(time(NULL));
    for(int i = 0; i < amount; i++){
        float x = std::rand() % 512;
        float y = std::rand() % 512;
        p = new g::Point();
        p->x = x;
        p->y = y;
        v.push_back(*p);
        delete p;
    }

    //Удаляем повторяющиеся точки, если такие есть
    std::vector<g::Point>::iterator it;
    it = std::unique(v.begin(), v.end(), pt_cmp);
    v.erase(it, v.end());

    //Если после удаления точек в векторе меньше, чем нужно,
    //Добавляем по одной, проверяя уникальность
    while(v.size() < amount){
        float x = std::rand() % 335;
        float y = std::rand() % 335;
        p = new g::Point();
        p->x = x;
        p->y = y;
        v.push_back(*p);
        it = std::unique(v.begin(), v.end(), pt_cmp);
        v.erase(it, v.end());
        delete p;
    }

    for(int i = 0; i < amount; i++)
        points[i] = v[i];
}
   
   
//Функция заполняющая массив структур, прилегащих к точке многоугольника (вершине)
//И уравнение биссектриссы угла (задается координатами направляющего вектора )

void PointDirection (Point p[], Direct s[][], Point bisec[]){
	int n = sizeof (p[]);
	for (int i=0, i<n, i++)
	{
		if i=0
		{	
			s[0][0].a = p[n].y-p[0].y;
			s[0][0].b = p[0].x-p[n].x;
			s[0][0].c = p[0].y*p[n].x-p[0].x*p[n].y;
			
			s[1][0].a = p[1].y-p[0].y;
			s[1][0].b = p[0].x-p[1].x;
			s[1][0].c = p[0].y*p[1].x-p[0].x*p[1].y;
			
			bisec[0].x = ((p[n].x-p[0].x)/sqrt((p[n].x-p[0].x)*(p[n].x-p[0].x)+(p[n].y-p[0].y)*(p[n].y-p[0].y)) + ((p[1].x-p[0].x)/sqrt((p[1].x-p[0].x)*(p[1].x-p[0].x)+(p[1].y-p[0].y)*(p[1].y-p[0].y));
			bisec[0].y = ((p[n].y-p[0].y)/sqrt((p[n].x-p[0].x)*(p[n].x-p[0].x)+(p[n].y-p[0].y)*(p[n].y-p[0].y)) + ((p[1].y-p[0].y)/sqrt((p[1].x-p[0].x)*(p[1].x-p[0].x)+(p[1].y-p[0].y)*(p[1].y-p[0].y));	
		}
		
		if (i=n)
		{	
			s[0][n].a = p[n-1].y-p[n].y;
			s[0][n].b = p[n].x-p[n-1].x;
			s[0][n].c = p[n].y*p[n-1].x-p[n].x*p[n-1].y;
			
			s[1][n].a = p[0].y-p[n].y;
			s[1][n].b = p[n].x-p[0].x;
			s[1][n].c = p[n].y*p[0].x-p[n].x*p[0].y;
			
			bisec[n].x = ((p[n-1].x-p[n].x)/sqrt((p[n-1].x-p[n].x)*(p[n-1].x-p[n].x)+(p[n-1].y-p[n].y)*(p[n-1].y-p[n].y)) + ((p[n+1].x-p[n].x)/sqrt((p[n+1].x-p[n].x)*(p[n+1].x-p[n].x)+(p[n+1].y-p[n].y)*(p[n+1].y-p[n].y));
			bisec[n].y = ((p[n-1].y-p[n].y)/sqrt((p[n-1].x-p[n].x)*(p[n-1].x-p[n].x)+(p[n-1].y-p[n].y)*(p[n-1].y-p[n].y)) + ((p[n+1].y-p[n].y)/sqrt((p[n+1].x-p[n].x)*(p[n+1].x-p[n].x)+(p[n+1].y-p[n].y)*(p[n+1].y-p[n].y));
			
		}
		
		if ((i != n) and (i != 0)){
			s[0][i].a = p[i-1].y-p[i].y;
			s[0][n].b = p[i].x-p[i-1].x;
			s[0][n].c = p[i].y*p[i-1].x-p[i].x*p[i-1].y;
			
			s[1][n].a = p[i+1].y-p[i].y;		
			s[1][n].b = p[i].x-p[i+1].x;
			s[1][n].c = p[i+1].y*p[i].x-p[I+1].x*p[i].y;
			
			bisec[i].x = ((p[i-1].x-p[i].x)/sqrt((p[i-1].x-p[i].x)*(p[i-1].x-p[i].x)+(p[i-1].y-p[i].y)*(p[i-1].y-p[i].y)) + ((p[i+1].x-p[i].x)/sqrt((p[i+1].x-p[i].x)*(p[i+1].x-p[i].x)+(p[i+1].y-p[i].y)*(p[i+1].y-p[i].y));
			bisec[i].y = ((p[i-1].y-p[i].y)/sqrt((p[i-1].x-p[i].x)*(p[i-1].x-p[i].x)+(p[i-1].y-p[i].y)*(p[i-1].y-p[i].y)) + ((p[i+1].y-p[i].y)/sqrt((p[i+1].x-p[i].x)*(p[i+1].x-p[i].x)+(p[i+1].y-p[i].y)*(p[i+1].y-p[i].y));
		}
		
	}
	
}

//Функция нахождения узлов скелета 

void Skelet (Point p[], Direct s[][], Point bisec[], Point uzel[]){
	int n = sizeof (p[]);
	float t;
	float r;
	int k=0;
	int schet = 0;
	
	while (k != n){
		for (int i=0, i<n, i++){
			if (i != k){
				t=((s[2][i].c+s[2][i].b*p[k].y+s[2][i].a*p[k].x)/sqrt(s[2][i].a*s[2][i].a+s[2][i].b*s[2][i].b) - (s[2][k].c+s[2][k].b*p[k].y+s[2][k].a*p[k].x)/sqrt(s[2][k].a*s[2][k].a+s[2][k].b*s[2][k].b))/((bisec[k].x*s[2][k].a-bisec[k].y*s[2][k].b)/sqrt(s[2][i].a*s[2][i].a+s[2][i].b*s[2][i].b)+(bisec[k].y*s[2][k].b-bisec[k].x*s[2][k].a)/sqrt(s[2][k].a*s[2][k].a+s[2][k].b*s[2][k].b));
				float x0 = bisec[k].x*t+p[k].x;
				float y0 = bisec[k].y*t+p[k].y;

				if (((s[1][k].a*x0+s[1][k].b*y0+s[1][k].c)<0)and((s[1][k].a*p[k+1].x+s[1][k].b*p[K+1].y+s[1][k].c)<0)) or (((s[1][k].a*x0+s[1][k].b*y0+s[1][k].c)>0)and((s[1][k].a*p[k+1].x+s[1][k].b*p[K+1].y+s[1][k].c)>0)){
					r = abs(s[2][k].a*x0+s[2][k].b*y0+s[2][k].c)/sqrt(s[2][k].a*s[2][k].a+s[2][k].b*s[2][k].b);
					for (int j=0, j<n, j++){
						if ((j != k) and (j != i)){
							if ((abs(s[2][j].a*x0+s[2][j].b*y0+s[2][j].c)/sqrt(s[2][j].a*s[2][j].a+s[2][j].b*s[2][j].b))<r){
								schet = schet+1;
							}
						}
					}
				}
				else{
					t=((s[2][i].c-s[2][i].b*p[k].y-s[2][i].a*p[k].x)/sqrt(s[2][i].a*s[2][i].a+s[2][i].b*s[2][i].b) - (s[2][k].c+s[2][k].b*p[k].y+s[2][k].a*p[k].x)/sqrt(s[2][k].a*s[2][k].a+s[2][k].b*s[2][k].b))/((bisec[k].x*s[2][k].a+bisec[k].y*s[2][i].b)/sqrt(s[2][i].a*s[2][i].a+s[2][i].b*s[2][i].b)+(bisec[k].y*s[2][k].b+bisec[k].x*s[2][i].a)/sqrt(s[2][k].a*s[2][k].a+s[2][k].b*s[2][k].b));
					r = abs(s[2][k].a*x0+s[2][k].b*y0+s[2][k].c)/sqrt(s[2][k].a*s[2][k].a+s[2][k].b*s[2][k].b);
					for (int j=0, j<n, j++){
						if ((j != k) and (j != i)){
							if ((abs(s[2][j].a*x0+s[2][j].b*y0+s[2][j].c)/sqrt(s[2][j].a*s[2][j].a+s[2][j].b*s[2][j].b))<r){
								schet = schet+1;
							}
						}
					}
				}
			}
			
			if (schet == 0){
				uzel[k].x=x0;
				uzel[k].y=y0;
				k = k + 1;
			}
		}
	}
}

//Рисовалка :)

void Drow (Point p[], Point uzel[]){
	for (int i=0, i<n, i++){
		if (i=n-1){
			Line (p[n].x, p[n].y, p[0].x, p[0].y);
			Line (p[n].x, p[n].y, uzel[n].x, uzel[n].y);
			Line (uzel[n].x, uzel[n].y, uzel[0].x, uzel[0].y);
		}
		else{
			Line (p[i].x, p[i].y, p[i+1].x, p[i+1].y);
			Line (p[i].x, p[i].y, uzel[i].x, uzel[i].y);
			Line (uzel[i].x, uzel[i].y, uzel[i+1].x, uzel[i+1].y);
		}
	}
}


int main{
   
   
	
	return 0;
}
