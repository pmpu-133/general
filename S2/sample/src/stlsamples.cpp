#include "stdafx.h"

#include "stlsamples.h"

#include <iostream>
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>

#include "point_utils.h"


std::vector<Point>  generate_points(size_t NumPoints = 10) {
  std::vector<Point> v = { {0,1} };

  std::random_device rng;
  std::uniform_real_distribution<double> rd(0.0, 1.0);


  v.reserve(NumPoints);
  for (size_t k = 0; k < NumPoints; ++k)
    v.push_back({ rd(rng),rd(rng) });
  return v;
}

typedef std::vector<Point>::const_iterator CIT;
typedef std::vector<Point>::iterator IT;
typedef std::vector<Point>::reverse_iterator RIT;

// Простая итерация по массиву
std::ostream & operator<<(std::ostream& ost, const std::vector<Point> &v) {
  for (CIT ci = v.begin(); ci != v.end(); ++ci)
    ost << *ci << std::endl;
  return ost;
}

void printvec(const std::vector<Point> &v) {
  std::for_each(v.begin(), v.end(), [](const Point& p) {
    std::cout << p << std::endl;
  }
  );
}

double distE(const Point& p1, const Point& p2) {
  return std::sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

void zerocollect(const std::vector<Point> &v) {
  double res = 0;
  std::for_each(v.begin(), v.end(), [&res](const Point& p) {
    res += distE(p, { 0,0 });
  }
  );
  std::cout << "Total distance " << res << std::endl;
}

// Или используем итератор для вывода в поток
/*
std::ostream & operator<<(std::ostream& ost, const std::vector<Point> &v){
    std::ostream_iterator<Point> out_it (ost,", ");
    std::copy( v.begin(), v.end(), out_it );
    return ost;
}
*/

// перемешиваем содержимое
void stlsample01() {
  std::cout << "random_suffle" << std::endl;
  std::vector<Point> v = generate_points();
  std::cout << v << std::endl << std::endl << std::endl;
  std::random_shuffle(v.begin(), v.end());
  std::cout << v << std::endl << std::endl << std::endl;
}
// переставляем содержимое
void stlsample02() {
  std::cout << "rotate + 3" << std::endl;
  std::vector<Point> v = generate_points();
  std::cout << v << std::endl << std::endl << std::endl;
  std::rotate(v.begin(), v.begin() + 3, v.end());
  std::cout << v << std::endl << std::endl << std::endl;
}

// переворачиваем содержимое
void stlsample03() {
  std::cout << "reverse" << std::endl;
  std::vector<Point> v = generate_points();
  std::cout << v << std::endl << std::endl << std::endl;
  std::reverse(v.begin(), v.end());
  std::cout << v << std::endl << std::endl << std::endl;
}

// Сравниваем
void stlsample04() {
  std::cout << "equal" << std::endl;
  std::vector<Point> v = generate_points();
  std::vector<Point> v1(v);
  std::cout << v << std::endl << std::endl << std::endl;
  std::random_shuffle(v.begin(), v.end());
  std::cout << equal(v.begin(), v.end(), v1.begin()) << std::endl;
}

// Заполняем
void stlsample05() {
  std::cout << "fill" << std::endl;
  std::vector<Point> v = generate_points();
  std::cout << v << std::endl << std::endl << std::endl;
  std::fill(v.begin() + 1, v.end(), *v.begin());
  std::cout << v << std::endl << std::endl << std::endl;
}

class point_mover {
public:
  point_mover(const Vec&v_) :v(v_) {}
  Point operator()(const Point& p) {
    return p + v;
  }
private:
  Vec v;
};

void stlsample06() {
  std::cout << "transform" << std::endl;
  std::vector<Point> v = generate_points();
  std::cout << v << std::endl << std::endl << std::endl;

  Vec displacement = { 0.5,0.5 };
  point_mover pmov(displacement);
  std::transform(v.begin(), v.end(), v.begin(), pmov);
  std::cout << v << std::endl << std::endl << std::endl;
}

bool xcomp(const Point& p1, const Point& p2) {
  return p1.x == p2.x;
}

void stlsample07() {
  std::cout << "equal on x" << std::endl;
  std::vector<Point> v = generate_points();
  std::vector<Point> v1(v);
  std::cout << v << std::endl << std::endl << std::endl;
  std::random_shuffle(v.begin(), v.end());
  std::cout << equal(v.begin(), v.end(), v1.begin(), xcomp) << std::endl;
}

class vicComp {
public:
  vicComp() : m_vicinity(0) {}
  vicComp(double  v_ = 1e-6) : m_vicinity(v_) {}
  bool operator()(const Point& p1, const Point& p2) {
    return std::sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)) < m_vicinity;
  }
private:
  double m_vicinity;
};


void stlsample08() {
  std::cout << "neighborhood" << std::endl;
  std::vector<Point> v = generate_points();
  std::vector<Point> v1(v);
  double vicinity = 1;
  vicComp comp(vicinity);
  std::cout << v << std::endl << std::endl << std::endl;
  std::random_shuffle(v.begin(), v.end());
  std::cout << equal(v.begin(), v.end(), v1.begin(), comp) << std::endl;
}

class inSquare {
public:
  inSquare(const Point& ll, const Point& ur) : m_ll(ll), m_ur(ur) {}
  bool operator()(const Point& p) {
    return (m_ll.x <= p.x && p.x < m_ur.x) && (m_ll.y <= p.y && p.y < m_ur.y);
  }
private:
  Point m_ll, m_ur;
};


void stlsample09() {
  std::cout << "count" << std::endl;
  std::vector<Point> v = generate_points();
  std::cout << v << std::endl << std::endl << std::endl;
  //std::fill(v.begin() + 1, v.end(), *v.begin());
  //std::cout << v << std::endl << std::endl << std::endl;
  Point p1 = { 0.8,0.8 };
  Point p2 = { 1,1 };
  inSquare pred(p1, p2);
  std::cout << std::count_if(v.begin(), v.end(), pred) << std::endl;
}


class closeToPoint {
public:
  closeToPoint(const Point& p1) : m_p(p1) {}
  bool operator()(const Point& p1, const Point& p2) { 
    return distE(p1, m_p) < distE(p2, m_p);
  }
private:
  Point m_p;
};

void stlsample10() {
  std::cout << "sort" << std::endl;
  std::vector<Point> v = generate_points();
  std::cout << v << std::endl << std::endl << std::endl;
  //std::fill(v.begin() + 1, v.end(), *v.begin());
  //std::cout << v << std::endl << std::endl << std::endl;
  std::sort(v.begin(), v.end(), closeToPoint({ 0.5,0.5 }));
  std::cout << v << std::endl;
}

class pointDistCollector {
public:
  pointDistCollector() : m_res(0) {}
  void operator()(const Point &p) {
    m_res += distE(p, {0, 0});
  }
  
private:
  double m_res;
};
double sumDists(const std::vector<Point>& v1, const Point& p1) {
  double sum = 0;
  for (CIT ci = v1.begin(); ci != v1.end(); ++ci)
    sum += distE(*ci, p1);
  return sum;
}

void stlsample11() {
  std::cout << "sum dists" << std::endl;
  std::vector<Point> v = generate_points();
  std::cout << v << std::endl << std::endl << std::endl;
  std::cout << sumDists(v, Point({ 0,0 })) << std::endl;
  zerocollect(v);
}



/*
    cout<<"------Sum of u elements------"<<endl;
int sum=0;
sum=accumulate(u.begin(),u.end(),sum);
cout<<sum<<endl;

cout<<"------Inner product of u and v------"<<endl;
int innp=0;
innp=inner_product(u.begin(),u.end(),v.begin(),innp);
cout<<innp<<endl;

cout<<"------w: partial sum of v------"<<endl;
vector<int> w(v.size());
partial_sum(v.begin(),v.end(),w.begin());
cout<<"------Forward: w------"<<endl;
for (IT it=w.begin();it!=w.end();it++)
    cout<<*it<<endl;
cout<<"------x: adjacent_difference of u------"<<endl;
vector<int> x(v.size());
adjacent_difference(u.begin(),u.end(),x.begin());
cout<<"------Forward: x------"<<endl;
for (IT it=x.begin();it!=x.end();it++)
    cout<<*it<<endl;





/*
cout<<"------Finding values between 2 and 5------"<<endl;
it=v.begin();
do
{
    it=find_if(it,v.end(),int_range(2,5));
    if (it!=v.end())
    {
        cout<<"Found in range "<<*it<<endl;
        it++;
    }
}
while (it!=v.end());

cout<<"------Removing values between 2 and 5------"<<endl;
it=remove_if(v.begin(),v.end(),int_range(2,5));
cout<<"------Viewing until remove_if result------"<<endl;
IT it1;
for (it1=v.begin();it1!=it;it1++)
    cout<<*it1<<endl;

cout<<"------Counting elements in range 5 to 50------"<<endl;
int sz=count_if(v.begin(),v.end(),int_range(5,50));
cout<<sz<<endl;

cout<<"------Find equal elements------"<<endl;
it=adjacent_find(v.begin(),b.end());
for (it1=it;it1!=v.end();it1++)
    cout<<*it1<<endl;

*/

