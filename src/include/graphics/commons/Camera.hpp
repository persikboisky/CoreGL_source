#ifndef INCLUDE_GRAPHICS_COMMONS_CAMERA_HPP_
#define INCLUDE_GRAPHICS_COMMONS_CAMERA_HPP_

#include "../../math/Vectors.hpp"
#include "../../math/Matrix4.hpp"

namespace core
{
    enum Key_code;
    enum CAM_MODE;

    class Shader;

    struct cameraInfo
    {
        math::Vector3 up = math::Vector3(0, 1, 0);
        math::Vector3 position = math::Vector3(0, 0, 4);
        math::Vector3 target = math::Vector3(0, 0, -1);
        float fov = 70.0f;
        float far = 100.0f;
        float near = 0.1f;
        CAM_MODE mode;

        cameraInfo();
    };

    /// @brief ����� ��� ������ � �������
    class Camera
    {
    private:

        math::Vector3 startUP;
        math::Vector3 startTARGET;

        math::Vector3 up;
        math::Vector3 target;
        math::Vector3 pos;

        math::Matrix4 rot = math::Matrix4(1.0f);

        float fov;
        float far;
        float near;

        CAM_MODE mode;

        void update();

    public:
        /// @brief ����������� ������
        /// @param posX ������� ������ �� x
        /// @param posY ������� ������ �� y
        /// @param posZ ������� ������ �� z
        /// @param fov ���� ������ � ��������
        /// @param distance ��������� ������
        Camera(float posX, float posY, float posZ, float fov, float distance);

        /// @brief ����������� ������
        /// @param pos ������� ������
        /// @param fov ���� ������ � ��������
        /// @param distance ��������� ������
        Camera(math::Vector3 pos, float fov, float distance);

        //rf
        Camera(const cameraInfo& info);

        /// @brief ������������� ����� ������
        /// @param mode ����� (������: STATIC, DYNAMIC)
        void setMode(CAM_MODE mode);

        /// @brief ������������� ���� ������
        /// @param fov ���� ������ � ��������
        void setFov(float fov);

        /// @brief ������������� ��������� ������
        /// @param distance ��������� ������
        void setDistance(float distance);

        /// @brief ������������ ������ �� �������� ����
        /// @param x ���� �������� �� ��� x � ��������
        /// @param y ���� �������� �� ��� y � ��������
        /// @param z ���� �������� �� ��� z � ��������
        void rotate(float x, float y, float z);

        /// @brief ������������ ������ �� �������� ����
        /// @param axis ���� �������� �� ���� � �������� � ���� �������
        void rotate(const math::Vector3& axis);

        /// @brief �������� ������� ������(���������� � �������� ���������)
        void resetRotate();

        /// @brief ���������� ������ �� �������� ����
        /// @param x ����� ������ �� x
        /// @param y ����� ������ �� y
        /// @param z ����� ������ �� z
        void move(float x, float y, float z);

        void move(const math::Vector3 vec3);

        /// @brief ������������� ������ �� �������� ����������
        /// @param x ���������� x
        /// @param y ���������� y
        /// @param z ���������� z
        void setPos(float x, float y, float z);

        /// @brief ������������� ������ �� �������� ����������
        /// @param pos ������ � ������������
        void setPos(const math::Vector3& pos);

        /// @brief ������������� ����� � ������� ������� ������
        /// @param x ���������� x
        /// @param y ���������� y
        /// @param z ���������� z
        void setTarget(float x, float y, float z);

        /// @brief ������������� ����� � ������� ������� ������
        /// @param target ������ � ������������
        void setTarget(const math::Vector3& target);

        /// @brief �������� ������� ������
        /// @param x ���������� ��� �������� ���������� x
        /// @param y ���������� ��� �������� ���������� y
        /// @param z ���������� ��� �������� ���������� z
        void getPos(float& x, float& y, float& z) const;

        /// @brief �������� ������� ������
        /// @param pos ������ ��� �������� ���������
        void getPos(math::Vector3& pos) const;

        /// @brief �������� ���������� ���� ������� ������
        /// @param x ���������� ��� �������� ���������� x
        /// @param y ���������� ��� �������� ���������� y
        /// @param z ���������� ��� �������� ���������� z
        void getTarget(float& x, float& y, float& z) const;

        /// @brief �������� ���������� ���� ������� ������
        /// @param target ������ ��� �������� ���������
        void getTarget(math::Vector3& target) const;

        /// @brief ������ ������� �������� ������
        /// @param width ������ ����
        /// @param height ������ ����
        /// @return ���������� ������� ��������
        math::Matrix4 getProj(int width, int height) const;

        /// @brief ������ ������� ������� ������
        /// @return ���������� ������� �������
        math::Matrix4 getView();
    };
}

#endif // !INCLUDE_GRAPHICS_COMMONS_CAMERA_HPP_