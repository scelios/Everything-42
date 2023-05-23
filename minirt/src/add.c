/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:01:27 by beaudibe          #+#    #+#             */
/*   Updated: 2023/05/06 15:01:27 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


t_vec3d add_center(float x, float y, float z)
{
	t_vec3d vec;

	vec.x = x + g_minirt.world.coord_world.x;
	vec.y = y + g_minirt.world.coord_world.y;
	vec.z = z + g_minirt.world.coord_world.z;
	return (vec);
}

t_vec3d add_angle(float x, float y, float z)
{
	t_vec3d vec;

	vec.x = to_radian( x + g_minirt.world.angle_world.x);
	vec.y = to_radian( y + g_minirt.world.angle_world.y);
	vec.z = to_radian( z + g_minirt.world.angle_world.z);
	return (vec);
}

t_vec3d add_point(float x, float y, float z)
{
	t_vec3d vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_triangle add_triangle(t_vec3d pos)
{
	t_triangle triangle;

	triangle.p->x = pos.x;
	triangle.p->y = pos.y;
	triangle.p->z = pos.z;
	return (triangle);
}

t_plane add_plane(t_vec3d pos, t_vec3d angle, t_vec3d scale)
{
    // Initialisation des points du rectangle
    t_vec3d points[4] = {
        add_point(-scale.x / 2, -scale.y / 2, 0),
        add_point(scale.x / 2, -scale.y / 2, 0),
        add_point(scale.x / 2, scale.y / 2, 0),
        add_point(-scale.x / 2, scale.y / 2, 0)
    };

    // Rotation selon l'axe x
    for (int i = 0; i < 4; i++) {
        float y = points[i].y;
        float z = points[i].z;
        points[i].y = y * cos(angle.x) - z * sin(angle.x);
        points[i].z = y * sin(angle.x) + z * cos(angle.x);
    }

    // Rotation selon l'axe y
    for (int i = 0; i < 4; i++) {
        float x = points[i].x;
        float z = points[i].z;
        points[i].x = x * cos(angle.y) - z * sin(angle.y);
        points[i].z = x * sin(angle.y) + z * cos(angle.y);
    }

    // Rotation selon l'axe z
    for (int i = 0; i < 4; i++) {
        float x = points[i].x;
        float y = points[i].y;
        points[i].x = x * cos(angle.z) - y * sin(angle.z);
        points[i].y = x * sin(angle.z) + y * cos(angle.z);
    }

    // Translation des points pour avoir le rectangle centré en pos
    for (int i = 0; i < 4; i++) {
        points[i].x += pos.x;
        points[i].y += pos.y;
        points[i].z += pos.z;
    }

    // Création des triangles du rectangle
    t_triangle triangles[2];
    triangles[0].p[0] = points[0];
    triangles[0].p[1] = points[1];
    triangles[0].p[2] = points[2];
    triangles[1].p[0] = points[2];
    triangles[1].p[1] = points[3];
    triangles[1].p[2] = points[0];

    // Création du plan contenant les deux triangles
    t_plane plane;
    plane.triangle[0] = triangles[0];
    plane.triangle[1] = triangles[1];

    return plane;
}


