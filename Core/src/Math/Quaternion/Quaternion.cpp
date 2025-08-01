#include "Quaternion.h"

Quaternion::Quaternion(float x_, float y_, float z_, float w_)
{
	x = x_;
	y = y_;
	z = z_;
	w = w_;
}

Quaternion Quaternion::FromEuler(float pitch, float yaw, float roll)
{
    float cx = cos(pitch * 0.5f);
    float sx = sin(pitch * 0.5f);
    float cy = cos(yaw * 0.5f);
    float sy = sin(yaw * 0.5f);
    float cz = cos(roll * 0.5f);
    float sz = sin(roll * 0.5f);

    float w = cx * cy * cz + sx * sy * sz;
    float x = sx * cy * cz - cx * sy * sz;
    float y = cx * sy * cz + sx * cy * sz;
    float z = cx * cy * sz - sx * sy * cz;

    return Quaternion(x, y, z, w);
}

Quaternion operator*(const Quaternion& q1, const Quaternion& q2)
{
    return Quaternion(
        q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
        q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
        q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w,
        q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z
    );
}

Vector3 Quaternion::RotateVectorByQuaternion(const Vector3& v, const Quaternion& q)
{
    Quaternion qv(v.x, v.y, v.z, 0);

    Quaternion q_conj(-q.x, -q.y, -q.z, q.w); // inverse if unit quaternion

    Quaternion result = q * qv * q_conj;
    return Vector3(result.x, result.y, result.z);
}

Quaternion Quaternion::Slerp(Quaternion a, Quaternion b, float t)
{
    float dot = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;

    if (dot < 0.0f) {
        b = Quaternion(-b.x, -b.y, -b.z, -b.w);
        dot = -dot;
    }

    const float DOT_THRESHOLD = 0.9995f;
    if (dot > DOT_THRESHOLD) {
        // Linear interpolation for small angles
        Quaternion result(
            a.x + t * (b.x - a.x),
            a.y + t * (b.y - a.y),
            a.z + t * (b.z - a.z),
            a.w + t * (b.w - a.w)
        );
        // Normalize
        float mag = sqrt(result.x * result.x + result.y * result.y + result.z * result.z + result.w * result.w);
        return Quaternion(result.x / mag, result.y / mag, result.z / mag, result.w / mag);
    }

    float theta_0 = acos(dot);      // angle between input
    float theta = theta_0 * t;      // angle at t
    float sin_theta = sin(theta);
    float sin_theta_0 = sin(theta_0);

    float s0 = cos(theta) - dot * sin_theta / sin_theta_0;
    float s1 = sin_theta / sin_theta_0;

    return Quaternion(
        s0 * a.x + s1 * b.x,
        s0 * a.y + s1 * b.y,
        s0 * a.z + s1 * b.z,
        s0 * a.w + s1 * b.w
    );
}

