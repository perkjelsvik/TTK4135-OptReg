# [TTK4135 - Optimization and Control](http://www.ntnu.edu/studies/courses/TTK4135)

## Course Content

The course treats optimization. The candidates learn to formulate optimization problems and solve these through appropriate algorithms and software. Optimality conditions like the Karush-Kuhn-Tucker (KKT) conditions are discussed and conditions for global and local conditions are analyzed. Key optimization classes of problems including linear programming (LP), quadratic programming (QP) and nonlinear programming (NP) are studied and applied in different settings. The course includes advanced control of dynamic systems with emphasis on Model Predictive Control (MPC).

In this course, we had a term project, where i was in a group with two other students. The project counts 15% of the final grade. Here's a brief description of the project:

## Helicopter Lab
The project can be divided into four parts:

* **PART I:** Problem Description & Mathematical Model
* **PART II:** Optimal Control of Pitch/Travel without Feedback
* **PART III:** Optimal Control of Pitch/Travel with Feedback (LQ)
* **PART IV:** Optimal Control of Pitch/Travel and Elevation with and without Feedback

This project uses the same setup as [TTK4155](https://github.com/PerKjelsvik/TTK4115-LinSys/), namely a quanser helicopter with 3 degrees of freedom ([like this one](http://www.quanser.com/products/3dof_helicopter)). For a more detailed overview of the system and underlying mathematical modelling, head over to the [TTK4155](https://github.com/PerKjelsvik/TTK4115-LinSys/) repo.

Optimal trajectories and input was calculated through minimizing a quadratic optimization problem. It was applied to the system with pitch as input, both with and without feedback. The feedback was implemented using a linear quadratic controller. Then a nonlinear inequality elevation constraint was added to the optimization problem, and once again, optimal input and trajectories was calculated and applied to the system with both pitch and elevation as input, with and without feedback. Lastly it was attempted to modify the given constraints of the problem, to possibly increase the precision of the system. The system was implemented and run in SIMULINK.

Overall, we were pleased with the outcome of the term project, and feel that we gained a good understanding of optimization and control. The project was not as demanding and large as previous term projects, but it was great fun that did require some hard thinking. We achieved 94/100 points on the project.
