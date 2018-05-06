#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;
	prev_cte = 0;
	p_error = 0;
	d_error = 0;
	i_error = 0;
}

void PID::UpdateError(double cte) {
	p_error = -cte;
	d_error = p_error - prev_cte;
	i_error += p_error;
	prev_cte = p_error;

}

double PID::TotalError() {
	control_val = Kp * p_error + Ki * i_error + Kd * d_error;

	if (control_val > upper_limit)
		control_val = upper_limit;
	else if (control_val < lower_limit)
		control_val = lower_limit;

	return control_val;
}

