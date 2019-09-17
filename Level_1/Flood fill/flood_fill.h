//
// Created by Vasco Varas on 9/17/19.
//

#ifndef INC_42_EXAM_INTERMEDIATE_FLOOD_FILL_H
#define INC_42_EXAM_INTERMEDIATE_FLOOD_FILL_H

typedef struct  s_point
{
	int           x;
	int           y;
}               t_point;

void  flood_fill(char **tab, t_point size, t_point begin);

#endif //INC_42_EXAM_INTERMEDIATE_FLOOD_FILL_H
