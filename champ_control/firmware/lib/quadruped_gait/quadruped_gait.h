#ifndef _QUADRUPED_GAIT_H_
#define _QUADRUPED_GAIT_H_

#include<Arduino.h>
#include<Geometry.h>
#include<quadruped_base.h>
#include<trajectory_planner.h>
#include<phase_generator.h>

class QuadrupedGait
{
        QuadrupedBase *base_;

        TrajectoryPlanner *trajectory_planners_[4];

        PhaseGenerator phase_gen_;

        float step_length_;
        float transversal_step_length_;
        float lateral_step_length_;
        float rotational_step_length_;
        float optimal_rotational_angle_;

        void transformTrajectory(QuadrupedLeg *leg, float linear_velocity_x, float linear_velocity_y, float angular_velocity_z, float &step_length, float &rotation);
        float getOptimalRotationalAngle(QuadrupedLeg *leg, float step_length);
        float getOptimalTurningAngle(QuadrupedLeg *leg, float step_length);
        float getStepLength(float linear_velocity_x, float linear_velocity_y, float angular_velocity_z);

    public:
        QuadrupedGait(QuadrupedBase &quadruped_base, float max_velocity, float swing_height, float step_length, float stance_depth);

        TrajectoryPlanner lf;
        TrajectoryPlanner rf;
        TrajectoryPlanner lh;
        TrajectoryPlanner rh;

        void generate(Transformation (&foot_positions)[4], float linear_velocity_x, float linear_velocity_y, float angular_velocity_z);
};

#endif