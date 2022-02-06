//header file
class VecThreeD
{

public:
    VecThreeD();
    ~VecThreeD() {};
    float getVec1();
    float getVec2();
    float getVec3();
    float getVec4();
    float getVec5();
    float getVec6();
    void setVec1(float);
    void setVec2(float);
    void setVec3(float);
    void setVec4(float);
    void setVec5(float);
    void setVec6(float);
    void displayVec();
    void calVec();
    double exp(double base, long power);  //the function for computing the exponential
    double arctan(double a, double b, int term);  //the fucntion for computing the acrtan(x)
private:
    float o, p, q, r, s, t;

};
