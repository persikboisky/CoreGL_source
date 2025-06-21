#ifndef INCLUDE_GRAPHICS_COMMONS_TEXTURE_HPP_
#define INCLUDE_GRAPHICS_COMMONS_TEXTURE_HPP_

#include <vector>

namespace core
{
    struct texture
    {
    private:
        [[maybe_unused]] static std::vector<unsigned int> id;

    public:
        /// @brief �������� ��������
        /// @param id ���������� ��������
        /// @param Sample ������ �������� (���� ����������� ����� ��� �������(uniform Sample2D))
        static void bind(unsigned int id, unsigned int Sample = 0);

        /// @brief ��������� �������� �� ������� ������
        /// @param png_code ������
        /// @param width ������
        /// @param height ������
        /// @param channels ���-�� �������
        /// @return ���������� ���������� ��������
        static unsigned int load(unsigned char* png_code, int width, int height, int channels);

        /// @brief ��������� �������� �� ������� ������
        /// @param png_code ������
        /// @param width ������
        /// @param height ������
        /// @param channels ���-�� �������
        /// @return ���������� ���������� ��������
        static unsigned int load(std::vector<unsigned char>& png_code, int width, int height, int channels);

        /// @brief ��������� �������� �� png �����
        /// @param path ���� � �����
        /// @return ���������� ���������� ��������
        static unsigned int load(const char* path);

        /// @brief ������� �������� �� � �����������
        /// @param id ����������
        static void Delete(unsigned int id);

        /// @brief ������� ��� ��������
        static void DeleteALL();
    };

    class Texture : private texture
    {
    private:
        unsigned int id;

    public:
        /// @brief �����������, ������ �������� �� ������� ������
        /// @param png_code ������
        /// @param width ������
        /// @param height ������
        /// @param channels ���-�� �������
        Texture(unsigned char* png_code, int width, int height, int channels);

        /// @brief �����������, ������ �������� �� ������� ������
        /// @param png_code ������
        /// @param width ������
        /// @param height ������
        /// @param channels ���-�� �������
        Texture(std::vector<unsigned char>& png_code, int width, int height, int channels);

        /// @brief �����������, ��������� �������� �� png �����
        /// @param path ���� � �����
        Texture(const char* path);
        ~Texture();

        /// @brief �������� ��������
        /// @param Sample ������ �������� (���� ����������� ����� ��� �������(uniform Sample2D))
        void bind(unsigned int Sample = 0) const;

        unsigned int getID() const;
    };
}

#endif // !INCLUDE_GRAPHICS_COMMONS_TEXTURE_HPP_
