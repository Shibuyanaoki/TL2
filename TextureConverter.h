#pragma once
#include <string>
class TextureConverter
{
private:

	void LoadWICTextureFromFIle(const std::string& filePath);


	std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	/// <summary>
	/// �e�N�X�`����WIC����DDS�ɕϊ�
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void ConvertTextureWICToDDS(const std::string& filePath);

public:

};

